"""Tests for the verified-name registry. Run with: python3 -m pytest tools/registry"""

import os
import subprocess
import sys

import pytest

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

import audit_names  # noqa: E402
import build_registry  # noqa: E402
import check_registry  # noqa: E402
import registry as reg  # noqa: E402

# Mismatches the checker finds in the repository today. They are real drift, recorded here rather than
# fixed because this change only adds tools. Fix the repository, then delete the entry: the test fails
# while this set and the checker disagree, in either direction, so new drift cannot slip in and a fixed
# entry cannot linger.
KNOWN_DRIFT = {
    # duel/function_index.csv (and duel/symbols.csv) still say FUN_0048d00c; the C file and the rename
    # maps already use Sound_PlayTrackById.
    ("DUEL", 0x0048D00C, "Sound_PlayTrackById", "duel/function_index.csv", ("FUN_0048d00c",)),
    # engine_globals_map.csv still has the old guess; magic/symbols.csv has the verified name.
    ("MAGIC", 0x006A3F78, "g_SpellStackCount", "engine_globals_map.csv", ("g_AiEvaluatedMoveCount",)),
}


@pytest.fixture(scope="module")
def registry_rows():
    return reg.read_registry()


def by_key(rows):
    return {(r["program"], r["address"]): r for r in rows}


# --------------------------------------------------------------------------------------------------
# The checker, on the real repository


def test_checker_finds_exactly_the_known_drift(registry_rows):
    failures, _ = check_registry.check(registry_rows)
    got = {(p, a, n, s, tuple(f)) for p, a, n, s, f in failures}
    assert got == KNOWN_DRIFT, "\n".join(check_registry.describe(f) for f in failures)


def test_checker_exit_code():
    proc = subprocess.run([sys.executable, os.path.join(HERE, "check_registry.py")],
                          capture_output=True, text=True)
    assert proc.returncode == (1 if KNOWN_DRIFT else 0), proc.stdout + proc.stderr
    for _, addr, name, _, _ in KNOWN_DRIFT:
        assert f"{reg.fmt_addr(addr)}: registry says `{name}`" in proc.stdout


def test_checker_catches_a_changed_name(registry_rows):
    rows = [dict(r) for r in registry_rows]
    target = next(r for r in rows if r["program"] == "MAGIC" and r["address"] == 0x004751D7)
    target["name"] = "Magic_CombatPhase"
    failures, _ = check_registry.check(rows)
    assert ("MAGIC", 0x004751D7, "Magic_CombatPhase", "magic/function_index.csv",
            ["Magic_PushSpellStack"]) in failures


# --------------------------------------------------------------------------------------------------
# The registry against the doc


def test_registry_csv_and_parse_report_are_up_to_date():
    assert build_registry.main(["--check"]) == 0, "run tools/registry/build_registry.py"


def test_registry_shape(registry_rows):
    with open(reg.REGISTRY_CSV) as f:
        assert f.readline().strip() == ",".join(reg.FIELDS)
    keys = [(r["program"], r["address"]) for r in registry_rows]
    assert len(keys) == len(set(keys))
    for r in registry_rows:
        assert r["program"] in ("MAGIC", "DUEL")
        assert r["kind"] in ("function", "global")
        assert r["evidence"] in ("natural", "synthetic", "static", "qemu")
        assert r["section"] and r["name"]


def test_rows_with_both_addresses_give_one_row_per_program(registry_rows):
    rows = by_key(registry_rows)
    for magic, duel, name in [(0x004CF8B6, 0x004A197E, "SpellChain_FindEntryIndex"),
                              (0x004AB28B, 0x0043064A, "Ai_RecordChoice"),
                              (0x00494310, 0x0043504D, "Color_RGBToOctreePath")]:
        assert rows[("MAGIC", magic)]["name"] == name
        assert rows[("DUEL", duel)]["name"] == name
    # "none" in the DUEL column: MAGIC only.
    assert ("MAGIC", 0x0050DA40) in rows
    # DUEL address first, MAGIC address in brackets.
    assert rows[("DUEL", 0x00681EB0)]["name"] == rows[("MAGIC", 0x006A4A08)]["name"] == "g_DuelModeFlags"


def test_programs_evidence_and_names(registry_rows):
    rows = by_key(registry_rows)
    # Table introduced by "The same three functions in DUEL.EXE".
    assert rows[("DUEL", 0x00487CE1)]["name"] == "Magic_ExecuteDrawPhase"
    assert rows[("DUEL", 0x0048D00C)]["name"] == "Sound_PlayTrackById"   # "unchanged (name is fine)"
    # "Called" column written as `old` -> `new`.
    assert rows[("MAGIC", 0x00474428)]["name"] == "Magic_PushEventContext"
    # Parameter lists are not part of the name.
    assert rows[("MAGIC", 0x0047624F)]["name"] == "Magic_RunTurnStep"
    assert rows[("MAGIC", 0x0047624F)]["evidence"] == "qemu"
    assert rows[("MAGIC", 0x006A4F70)]["evidence"] == "static"      # "on static evidence only"
    assert rows[("MAGIC", 0x004CFD68)]["evidence"] == "synthetic"
    assert rows[("MAGIC", 0x004CF8B6)]["evidence"] == "natural"
    assert rows[("MAGIC", 0x0050DA40)]["evidence"] == "synthetic"   # "injected"
    assert rows[("DUEL", 0x00690C48)]["evidence"] == "static"       # "(static)" in an emulator table
    assert rows[("MAGIC", 0x006B2534)]["kind"] == "global"
    assert rows[("MAGIC", 0x00473179)]["kind"] == "function"


def test_only_the_known_rows_fail_to_parse():
    rows, problems, skipped = build_registry.build()
    assert len(problems) == 2 and all("twin shares a name" in p for p in problems), problems
    assert [t.line for t in skipped] == [230, 259, 311, 363, 389, 404, 431]


def test_parser_on_a_small_doc(tmp_path):
    doc = tmp_path / "doc.md"
    doc.write_text(
        "# Log\n\n## Renames (MAGIC.EXE)\n\n"
        "| Address | Was | Now | Status |\n|---|---|---|---|\n"
        "| `0x00401000` | `FUN_00401000` | `A_New(x)` | verified, live |\n\n"
        "The same function in `DUEL.EXE`:\n\n"
        "| Address | Was | Now | Status |\n|---|---|---|---|\n"
        "| `0x00402000` | `B_Old` | unchanged (name is fine) | verified, live |\n\n"
        "## Twins (emulator)\n\n"
        "| MAGIC.EXE / DUEL.EXE | Old name | New name | Evidence |\n|---|---|---|---|\n"
        "| `0x403000` / `0x404000` | `C_Old` | `C_New` | synthetic: injected |\n"
        "| `0x405000` / none | `D_Old` | `D_New` | natural |\n"
        "| `0x406000` / (twin shares a name) | `E_Old` | `E_New` | natural |\n\n"
        "| Step | Seen |\n|---|---|\n| `0xc9` | once |\n")
    rows, problems, skipped = reg.parse_doc(str(doc))
    got = {(r["program"], r["address"], r["name"], r["evidence"]) for r in rows}
    assert got == {("MAGIC", 0x401000, "A_New", "qemu"), ("DUEL", 0x402000, "B_Old", "qemu"),
                   ("MAGIC", 0x403000, "C_New", "synthetic"), ("DUEL", 0x404000, "C_New", "synthetic"),
                   ("MAGIC", 0x405000, "D_New", "natural"), ("MAGIC", 0x406000, "E_New", "natural")}
    assert len(problems) == 1 and "E_New" in problems[0]
    assert len(skipped) == 1


# --------------------------------------------------------------------------------------------------
# Audit reports


def test_duplicates_report_is_current_and_has_the_known_case(registry_rows):
    rows = audit_names.attach_old_names([dict(r) for r in registry_rows])
    text, total = audit_names.render_duplicates(rows)
    with open(audit_names.DUPLICATES_MD) as f:
        assert f.read() == text, "run tools/registry/audit_names.py"
    assert total == len(audit_names.duplicate_groups("MAGIC")) + len(audit_names.duplicate_groups("DUEL"))
    assert "| `Glue_Subsystem_004cdb4f` | `0x00493e30` `Glue_Subsystem_004cdb4f`, `0x0049fc0f`" in text


def test_generator_report_is_current(registry_rows):
    rows = audit_names.attach_old_names([dict(r) for r in registry_rows])
    text, script_hits, _, _ = audit_names.render_generators(rows)
    with open(audit_names.GENERATORS_MD) as f:
        assert f.read() == text, "run tools/registry/audit_names.py"
    assert any(h["file"] == "scripts/full_codebase_refactor.py" and "g_AiEvaluatedMoveCount" in h["stale"]
               for h in script_hits)
