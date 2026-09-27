"""Tests for the difftest pipeline. Run with: python3 -m pytest tools/difftest"""

import copy
import csv
import filecmp
import json
import os
import re
import shutil
import subprocess
import sys

import pytest

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

import make_doc_vectors  # noqa: E402
import run_vectors as rv  # noqa: E402

VECTORS = os.path.join(HERE, "vectors")


@pytest.fixture(scope="module")
def harness():
    return rv.build_harness()


def load(name):
    with open(os.path.join(VECTORS, name), encoding="utf-8") as f:
        return json.load(f)


def run(tmp_path, harness, vector, name="v.json"):
    path = tmp_path / name
    path.write_text(json.dumps(vector))
    return rv.run_vector(str(path), harness)


# --------------------------------------------------------------------------------------------------
# The seed vectors


def test_every_vector_passes_or_is_unimplemented(harness):
    for path in sorted(os.listdir(VECTORS)):
        status, messages, _ = rv.run_vector(os.path.join(VECTORS, path), harness)
        expected = "UNIMPLEMENTED" if "unimplemented" in path else "PASS"
        assert status == expected, (path, messages)


def test_runner_exit_codes(harness):
    assert rv.main(["--harness", harness]) == 0
    assert rv.main(["--harness", harness, "--strict"]) == 1


def test_doc_vectors_are_up_to_date(tmp_path):
    make_doc_vectors.main(str(tmp_path))
    try:
        generated = sorted(os.listdir(tmp_path))
        committed = sorted(f for f in os.listdir(VECTORS) if f.startswith("doc_"))
        assert generated == committed
        match, mismatch, errors = filecmp.cmpfiles(str(tmp_path), VECTORS, generated, shallow=False)
        assert not mismatch and not errors, "run tools/difftest/make_doc_vectors.py"
    finally:
        make_doc_vectors.OUT = make_doc_vectors.os.path.join(make_doc_vectors.HERE, "vectors")


def test_doc_numbers_are_in_the_vectors():
    # Llanowar Elves 1/1, Durkwood Boars 4, Killer Bees ability 0x20, Forest index 2 and a mana source.
    assert load("doc_query_power_elves_recompute.json")["expected_return"] == 1
    assert load("doc_query_toughness_elves_recompute.json")["expected_return"] == 1
    assert load("doc_query_power_boars_recompute.json")["expected_return"] == 4
    assert load("doc_query_abilities_bees_recompute.json")["expected_return"] == 0x20
    assert load("doc_query_index_forest.json")["expected_return"] == 2
    assert load("doc_is_mana_source_forest_duel.json")["expected_return"] == 1
    assert load("doc_color_type_flags_forest.json")["expected_return"] == 0
    assert load("doc_color_type_flags_green_creature_elves.json")["expected_return"] == 0x2000


# --------------------------------------------------------------------------------------------------
# The runner notices what is wrong


def test_wrong_return_fails(tmp_path, harness):
    v = load("doc_query_power_elves_recompute.json")
    v["expected_return"] = 2
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "FAIL" and "return 0x1, expected 0x2" in messages[0]


def test_bool_return_compares_the_low_byte_only(tmp_path, harness):
    v = load("doc_is_mana_source_forest_duel.json")
    v["expected_return"] = "0x7c3a0001"   # garbage above AL, as a trace of a bool function can show
    assert run(tmp_path, harness, v)[0] == "PASS"


def test_missing_input_memory_is_reported(tmp_path, harness):
    v = load("doc_is_mana_source_forest_duel.json")
    v["memory_in"] = v["memory_in"][:1]  # drop the master record
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "FAIL" and any("undefined byte" in m for m in messages)


def test_wrong_memory_out_fails(tmp_path, harness):
    v = load("doc_clear_duel.json")
    v["memory_out_expected"][0]["dwords"][0] = "0x00000001"
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "FAIL" and any("memory at" in m for m in messages)


def test_unlisted_write_fails_when_exhaustive(tmp_path, harness):
    v = load("doc_clear_duel.json")
    v["memory_out_expected"] = v["memory_out_expected"][:1]
    v["memory_out_expected"][0]["dwords"] = v["memory_out_expected"][0]["dwords"][:1]
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "FAIL" and any("changed but not in memory_out_expected" in m for m in messages)
    v["memory_out_exhaustive"] = False
    assert run(tmp_path, harness, v)[0] == "PASS"


def test_call_mismatches(tmp_path, harness):
    base = load("doc_color_type_flags_green_creature_elves.json")
    v = copy.deepcopy(base)
    v["calls"][1]["args"][2] = 4
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "FAIL" and "args" in messages[0]
    v = copy.deepcopy(base)
    v["calls"] = v["calls"][:1]
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "FAIL" and "unexpected call" in messages[0]
    v = copy.deepcopy(base)
    v["calls"].append(dict(v["calls"][0]))
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "FAIL" and "not made" in messages[-1]
    v = copy.deepcopy(base)
    v["calls"][0]["callee"] = "0x00401000"
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "FAIL" and "expects 0x00401000" in messages[0]


def test_callee_side_effects_are_replayed(tmp_path, harness):
    # The finder's own writes (here: the player's card count) land before the push goes on.
    v = load("doc_push_stand_in_object.json")
    count_addr = "0x00666408"
    v["calls"][0]["memory_writes"] = [{"addr": count_addr, "dwords": [8]}]
    v["memory_out_expected"].append({"addr": count_addr, "dwords": [8]})
    assert run(tmp_path, harness, v)[0] == "PASS"


def test_bad_vectors_are_errors(tmp_path, harness):
    v = load("doc_clear_duel.json")
    del v["args"]
    assert run(tmp_path, harness, v)[0] == "ERROR"
    v = load("doc_clear_duel.json")
    v["address"] = "0x00401000"
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "ERROR" and "entry address mismatch" in messages[0]
    v = load("doc_clear_duel.json")
    v["function"] = "Magic_NotNativeYet"
    assert run(tmp_path, harness, v)[0] == "ERROR"
    v = load("doc_clear_duel.json")
    v["memory_in"] = [{"addr": "0x1000", "bytes": [300]}]
    assert run(tmp_path, harness, v)[0] == "ERROR"


# --------------------------------------------------------------------------------------------------
# The C side


def test_native_code_compiles_without_warnings(tmp_path):
    cc = os.environ.get("CC") or "cc"
    if not shutil.which(cc):
        pytest.skip("no C compiler")
    out = tmp_path / "h"
    proc = subprocess.run([cc, "-std=c99", "-O2", "-Wall", "-Wextra", "-Wpedantic", "-Werror", "-o", str(out)]
                          + rv.SOURCES, capture_output=True, text=True)
    assert proc.returncode == 0, proc.stderr


def layout_addresses():
    with open(os.path.join(rv.NATIVE, "layout.c"), encoding="utf-8") as f:
        text = f.read()
    out = {}
    for program in ("MAGIC", "DUEL"):
        block = text.split(f"const Layout LAYOUT_{program} = {{", 1)[1].split("\n};", 1)[0]
        out[program] = {m.group(1): int(m.group(2), 16)
                        for m in re.finditer(r"\[((?:FN|CALLEE)_[A-Z_0-9]+)\] = 0x([0-9a-fA-F]+)", block)}
    return out


def test_layout_code_addresses_are_function_starts():
    """Every entry and callee address in layout.c starts a function in that program's index."""
    for program, addrs in layout_addresses().items():
        with open(os.path.join(rv.REPO, program.lower(), "function_index.csv"), newline="") as f:
            starts = {int(r["Address"], 16) for r in csv.DictReader(f)}
        assert len(addrs) == 16
        missing = {k: hex(a) for k, a in addrs.items() if a not in starts}
        assert not missing, (program, missing)


def test_record_vectors_tables_match_native_code():
    """record_vectors.py's NATIVE_FUNCTIONS/CALLEES_INFO must name exactly the FN_*/CALLEE_* members
    src/native/engine.h declares, in both programs' layout.c, so the recorder's hardcoded tables cannot
    quietly drift from what the native code actually calls when a function is added or removed. This
    needs neither unicorn nor the game."""
    import record_vectors as rec  # noqa: PLC0415 (imported here: needs no unicorn to run this test)

    fn_names = {n for n, _, _ in rec.NATIVE_FUNCTIONS}
    callee_names = {n for n, _, _ in rec.CALLEES_INFO}
    for program in ("MAGIC", "DUEL"):
        entries, callees, fn_order, callee_order = rec.load_layout(program)
        assert set(fn_order) == fn_names, (program, "FN_* mismatch", set(fn_order) ^ fn_names)
        assert set(callee_order) == callee_names, (program, "CALLEE_* mismatch", set(callee_order) ^ callee_names)
        assert set(entries) == set(fn_order), (program, "layout.c .entry vs engine.h NativeFn")
        assert set(callees) == set(callee_order), (program, "layout.c .callee vs engine.h Callee")
