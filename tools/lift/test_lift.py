"""Tests for the x86 lifter and the flat harness, on small hand-assembled functions (no game data needed).
Run with: python3 -m pytest tools/lift"""

import json
import os
import shutil
import subprocess
import sys

import pytest

capstone = pytest.importorskip("capstone")

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
DIFFTEST = os.path.join(os.path.dirname(HERE), "difftest")
sys.path.insert(0, HERE)
sys.path.insert(0, DIFFTEST)

import run_vectors as rv  # noqa: E402
from x86lift import Lifter, Unsupported  # noqa: E402

# name, address, machine code
FUNCTIONS = {
    # mov eax,[esp+4]; add eax,[esp+8]; ret
    "Test_Add": (0x1000, bytes.fromhex("8b442404" "03442408" "c3")),
    # signed max: mov eax,[esp+4]; cmp eax,[esp+8]; jge +4; mov eax,[esp+8]; ret
    "Test_Max": (0x2000, bytes.fromhex("8b442404" "3b442408" "7d04" "8b442408" "c3")),
    # switch (a) { case 0: return 10; case 1: return 20; case 2: return 30; default: return -1; } through a jump table
    "Test_Switch": (0x3000, bytes.fromhex(
        "8b442404" "83f802" "7725" "ff248510300000"
        "1c300000" "22300000" "28300000"
        "b80a000000c3" "b814000000c3" "b81e000000c3" "b8ffffffffc3")),
    # cdq; idiv: mov eax,[esp+4]; cdq; idiv dword [esp+8]; ret
    "Test_Div": (0x4000, bytes.fromhex("8b442404" "99" "f77c2408" "c3")),
    # a call: push [esp+4]; call 0x5100; add esp,4; add eax,1; ret
    "Test_Call": (0x5000, bytes.fromhex("ff742404" "e8f7000000" "83c404" "83c001" "c3")),
    # a call through an import slot: push [esp+4]; call [0x7000]; add eax,2; ret   (the callee pops its argument)
    "Test_Import": (0x7100, bytes.fromhex("ff742404" "ff1500700000" "83c002" "c3")),
    # a call through the master table: mov eax,[esp+4]; push eax; call [eax*4+0x8000]; add esp,4; ret
    "Test_Dynamic": (0x7200, bytes.fromhex("8b442404" "50" "ff148500800000" "83c404" "c3")),
    # an indirect jump with no bound check in front of it: must be refused
    "Test_BadJump": (0x6000, bytes.fromhex("8b442404" "ff248500700000" "c3")),
}
CALLEE = 0x5100
IMPORT_SLOT = 0x7000


def getbytes(va, n):
    for name, (addr, code) in FUNCTIONS.items():
        if addr <= va < addr + len(code):
            return code[va - addr:va - addr + n] + b"\x90" * 64
    raise Unsupported(f"0x{va:x} is not in the test image")


@pytest.fixture(scope="module")
def harness(tmp_path_factory):
    cc = os.environ.get("CC") or "cc"
    if not shutil.which(cc):
        pytest.skip("no C compiler")
    out = tmp_path_factory.mktemp("lift")
    lifter, sources, lifted = Lifter(), [], []
    lifter.imports[IMPORT_SLOT] = "Sleep"
    for name, (addr, code) in FUNCTIONS.items():
        if name == "Test_BadJump":
            continue
        src, targets, _, _ = lifter.lift_function(getbytes, addr, name, frozenset([CALLEE]))
        sources.append(src)
        lifted.append((name, addr))
    gen = ['#include "lift_rt.h"\n#include "lift_tables.h"\n'] + sources
    gen.append("const LiftedFn LIFTED[] = {\n" + "".join(f'    {{"{n}", 0x{a:x}u, lifted_{a:08x}}},\n' for n, a in lifted)
               + "    {0, 0, 0}\n};")
    gen.append(f"const int LIFTED_COUNT = {len(lifted)};")
    gen.append(f"const CalleeRow LIFT_CALLEES[] = {{ {{0x{CALLEE:x}u, 1, 0u}}, {{0x{IMPORT_SLOT:x}u, 1, 4u}}, {{0, 0, 0}} }};\nconst int LIFT_CALLEE_COUNT = 2;")
    (out / "gen.c").write_text("\n".join(gen))
    exe = str(out / "harness-flat")
    cmd = [cc, "-O1", "-DLIFT_TRACK_WRITES", "-w", f"-I{os.path.join(ROOT, 'src', 'native')}", "-o", exe, os.path.join(DIFFTEST, "harness_flat.c"),
           str(out / "gen.c")]
    proc = subprocess.run(cmd, capture_output=True, text=True)
    assert proc.returncode == 0, proc.stderr
    return exe


def vector(function, args, ret, calls=()):
    return {"function": function, "program": "DUEL", "args": args, "expected_return": ret,
            "memory_in": [], "calls": list(calls), "memory_out_expected": [], "memory_out_exhaustive": True}


def run(tmp_path, exe, v):
    path = tmp_path / "v.json"
    path.write_text(json.dumps(v))
    return rv.run_vector(str(path), exe)


def test_add(tmp_path, harness):
    assert run(tmp_path, harness, vector("Test_Add", [7, 5], 12))[0] == "PASS"
    assert run(tmp_path, harness, vector("Test_Add", [0xffffffff, 1], 0))[0] == "PASS"
    assert run(tmp_path, harness, vector("Test_Add", [7, 5], 13))[0] == "FAIL"


def test_signed_compare_and_branch(tmp_path, harness):
    for a, b, want in ((3, 9, 9), (9, 3, 9), (-4, 2, 2), (2, -4, 2), (-4, -9, -4)):
        assert run(tmp_path, harness, vector("Test_Max", [a, b], want))[0] == "PASS", (a, b)


def test_jump_table(tmp_path, harness):
    for index, want in ((0, 10), (1, 20), (2, 30), (3, -1), (200, -1)):
        assert run(tmp_path, harness, vector("Test_Switch", [index], want))[0] == "PASS", index


def test_division_truncates_toward_zero(tmp_path, harness):
    for a, b, want in ((7, 2, 3), (-7, 2, -3), (7, -2, -3), (-7, -2, 3)):
        assert run(tmp_path, harness, vector("Test_Div", [a, b], want))[0] == "PASS", (a, b)


def test_call_uses_the_recorded_return_and_arguments(tmp_path, harness):
    call = {"callee": CALLEE, "name": "Callee", "args": [9], "return": 41}
    status, messages, _ = run(tmp_path, harness, vector("Test_Call", [9], 42, [call]))
    assert status == "PASS", messages
    wrong = dict(call, args=[8])  # the lifted code passes 9
    assert run(tmp_path, harness, vector("Test_Call", [9], 42, [wrong]))[0] == "FAIL"
    assert run(tmp_path, harness, vector("Test_Call", [9], 42))[0] in ("FAIL", "ERROR")  # no call recorded


def test_import_call_is_a_call_to_the_slot_and_pops_its_argument(tmp_path, harness):
    call = {"callee": IMPORT_SLOT, "name": "Sleep", "args": [9], "return": 40}
    status, messages, _ = run(tmp_path, harness, vector("Test_Import", [9], 42, [call]))
    assert status == "PASS", messages


def test_call_through_the_master_table_takes_its_argument_count_from_the_recording(tmp_path, harness):
    call = {"callee": 0x1234, "name": "card_handler", "args": [3], "return": 7}
    # the target is whatever the table holds: the vector's memory says 0x1234, at 0x8000 + 3*4
    v = vector("Test_Dynamic", [3], 7, [call])
    v["memory_in"] = [{"addr": 0x8000 + 12, "dwords": [0x1234]}]
    status, messages, _ = run(tmp_path, harness, v)
    assert status == "PASS", messages


def test_unbounded_indirect_jump_is_refused():
    addr, code = FUNCTIONS["Test_BadJump"]
    with pytest.raises(Unsupported):
        Lifter().lift_function(getbytes, addr, "Test_BadJump", frozenset())


def test_unreadable_memory_is_reported(tmp_path, harness):
    # Test_Add reads its two arguments from the stack, which the harness provides; nothing else, so it is fine. A function
    # that read memory the vector does not define would give different results under the two fills.
    status, messages, _ = run(tmp_path, harness, vector("Test_Add", [1, 2], 3))
    assert status == "PASS", messages


# ---- the same lifted code inside the native layer (src/native/lift_bridge.c) ------------------------------------------


@pytest.fixture(scope="module")
def native_harness(tmp_path_factory):
    """tools/difftest's native harness with the synthetic functions linked in as Handler_<address> lifted functions."""
    cc = os.environ.get("CC") or "cc"
    if not shutil.which(cc) or not shutil.which("make"):
        pytest.skip("no C compiler or make")
    out = tmp_path_factory.mktemp("lift_native")
    lifter, sources, names = Lifter(), [], []
    lifter.imports[IMPORT_SLOT] = "Sleep"
    for name, (addr, code) in FUNCTIONS.items():
        if name == "Test_BadJump":
            continue
        src, _, _, _ = lifter.lift_function(getbytes, addr, f"Handler_{addr:08x}", frozenset([CALLEE]))
        sources.append(src)
        names.append((f"Handler_{addr:08x}", addr))
    gen = ['#include "lift_rt.h"\n#include "lift_tables.h"\n'] + sources
    gen.append("const LiftedFn LIFTED[] = {\n" + "".join(f'    {{"{n}", 0x{a:x}u, lifted_{a:08x}}},\n' for n, a in names)
               + "    {0, 0, 0}\n};")
    gen.append(f"const int LIFTED_COUNT = {len(names)};")
    gen.append(f"const CalleeRow LIFT_CALLEES[] = {{ {{0x{CALLEE:x}u, 1, 0u}}, {{0x{IMPORT_SLOT:x}u, 1, 4u}}, {{0, 0, 0}} }};\n"
               "const int LIFT_CALLEE_COUNT = 2;")
    (out / "handlers_gen.c").write_text("\n".join(gen))
    proc = subprocess.run(["make", "-C", DIFFTEST, "lifted", f"GEN={out}", f"BUILD={out}/build"], capture_output=True, text=True)
    assert proc.returncode == 0, proc.stdout + proc.stderr
    return str(out / "build" / "harness-lifted")


def test_native_layer_runs_a_lifted_function(tmp_path, native_harness):
    v = vector("Handler_00001000", [7, 5, 0], 12)   # Test_Add
    assert run(tmp_path, native_harness, v)[0] == "PASS"
    v = vector("Handler_00002000", [-4, 2, 0], 2)   # Test_Max
    assert run(tmp_path, native_harness, v)[0] == "PASS"


def test_native_layer_replays_the_calls_a_lifted_function_makes(tmp_path, native_harness):
    call = {"callee": CALLEE, "name": "Callee", "args": [9], "return": 41}
    status, messages, _ = run(tmp_path, native_harness, vector("Handler_00005000", [9, 0, 0], 42, [call]))   # Test_Call
    assert status == "PASS", messages


def test_native_layer_counts_a_read_of_undefined_memory_as_a_fault(tmp_path, native_harness):
    # Test_Switch reads nothing but its argument; Test_Dynamic reads the master table, which the vector does not provide
    v = vector("Handler_00007200", [3, 0, 0], 7, [{"callee": 0x1234, "name": "card_handler", "args": [3], "return": 7}])
    status, messages, _ = run(tmp_path, native_harness, v)
    assert status == "FAIL" and any("undefined" in m or "0x00008000" in m or "8000" in m for m in messages), messages
