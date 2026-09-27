"""Tests for propagate.py. Run with: python3 -m pytest tools/twins/test_propagate.py"""

import os
import re
import sys

import pytest

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

import propagate as pp  # noqa: E402


def index_csv(rows):
    lines = ["Address,FunctionName,ReturnType,ParameterCount,BodySize,Status,Filename"]
    lines += [f'{a:08x},"{n}","undefined",0,16,SUCCESS,"{n}_{a:08x}.c"' for a, n in rows]
    return "\n".join(lines) + "\n"


MAGIC = [
    (0x401000, "Magic_Verified"),          # 1: semantic and verified, DUEL generic
    (0x401100, "Magic_Unverified"),        # 1: semantic, unverified here (verified elsewhere), DUEL copied label
    (0x401200, "FUN_00401200"),            # 2: DUEL semantic
    (0x401300, "Magic_Conflict"),          # 3: both semantic, different
    (0x401400, "Pic_Subsystem_00401400"),  # 2 and 4: DUEL name shared by two addresses
    (0x401500, "Card_Same"),               # both semantic, same
    (0x401600, "FUN_00401600"),            # both generic
    (0x401700, "Ai_Util_00401700"),        # weak twin: left out
    (0x401800, "Magic_Ambiguous"),         # ambiguous: left out
]
DUEL = [
    (0x481000, "FUN_00481000"),
    (0x481100, "Pic_Load_00401100"),
    (0x481200, "Duel_Named"),
    (0x481300, "Duel_OtherName"),
    (0x481400, "Shared_Name"),
    (0x481500, "Card_Same"),
    (0x481600, "FUN_00481600"),
    (0x481700, "Glue_Subsystem_00401700"),
    (0x481800, "FUN_00481800"),
    (0x481900, "Shared_Name"),
]
TWINS = [
    (0x401000, 0x481000, 1.0, "twin"), (0x401100, 0x481100, 0.95, "twin"),
    (0x401200, 0x481200, 0.9, "twin"), (0x401300, 0x481300, 0.85, "twin"),
    (0x401400, 0x481400, 0.8, "twin"), (0x401500, 0x481500, 1.0, "twin"),
    (0x401600, 0x481600, 1.0, "twin"), (0x401700, 0x481700, 0.6, "weak"),
    (0x401800, 0x481800, 1.0, "ambiguous"),
]
REGISTRY = [
    ("MAGIC", 0x401000, "Magic_Verified"),
    ("MAGIC", 0x409999, "Magic_Unverified"),   # the name is verified, but at another address
    ("DUEL", 0x481300, "Duel_OtherName"),
]
DUPLICATES_MD = """# Duplicate function names

## MAGIC.EXE: 0 shared names

None.

## DUEL.EXE: 1 shared names

| Name | Addresses (body size) | Registry |
|---|---|---|
| `Shared_Name` | `0x00481400` (16), `0x00481900` (16) |  |
"""
# A DUEL C file in which 0x481000 already has a name the index lacks.
DUEL_C = "".join(
    f"int {('Duel_CName' if a == 0x481000 else n)}(void)\n\n{{\n  return 0;\n}}\n\n\n" for a, n in DUEL)


@pytest.fixture
def repo(tmp_path):
    (tmp_path / "magic").mkdir()
    (tmp_path / "duel").mkdir()
    (tmp_path / "tools" / "twins").mkdir(parents=True)
    (tmp_path / "tools" / "registry").mkdir(parents=True)
    (tmp_path / "magic" / "function_index.csv").write_text(index_csv(MAGIC))
    (tmp_path / "duel" / "function_index.csv").write_text(index_csv(DUEL))
    (tmp_path / "duel" / "duel_unified.c").write_text(DUEL_C)
    rows = ["magic_addr,duel_addr,score,second_best_score,evidence"]
    rows += [f"0x{m:08x},0x{d:08x},{s:.4f},0.1000,{v}; mutual; seq=1.00" for m, d, s, v in TWINS]
    (tmp_path / "tools" / "twins" / "twins.csv").write_text("\n".join(rows) + "\n")
    reg = ["program,address,name,kind,evidence,section,notes"]
    reg += [f"{p},0x{a:08x},{n},function,natural,Test," for p, a, n in REGISTRY]
    (tmp_path / "tools" / "registry" / "verified_names.csv").write_text("\n".join(reg) + "\n")
    (tmp_path / "tools" / "registry" / "duplicates.md").write_text(DUPLICATES_MD)
    return tmp_path


def report(repo):
    assert pp.main(["--repo", str(repo)]) == 0
    return (repo / "tools" / "twins" / "propagation.md").read_text()


def section(text, number):
    return text.split(f"## {number}.", 1)[1].split("\n## ", 1)[0]


def table_rows(text):
    return [line for line in text.splitlines() if line.startswith("| `0x")]


def test_kind():
    assert pp.kind("FUN_00401000", 0x401000)[0] == "generic"
    assert pp.kind("thunk_FUN_00401000", 0x401000)[0] == "generic"
    assert pp.kind("Palette_Subsystem_0049608e", 0x4a1bf7)[0] == "generic"
    assert pp.kind("Ai_Util_004ab510", 0x4ab510) == ("generic", "ends in its own address")
    assert pp.kind("Pic_Clip_00443b63", 0x4b4efc) == ("generic", "ends in another address")
    assert pp.kind("Magic_QueryCardAttribute", 0x473179)[0] == "semantic"
    assert pp.kind("FID_conflict:_memcpy", 0x4d99b0)[0] == "semantic"
    assert pp.kind("Card_Sinbad_Draw", 0x4d1cc4)[0] == "semantic"


def test_sections(repo):
    text = report(repo)
    one = table_rows(section(text, 1))
    assert [r.split(" | ")[0] for r in one] == ["| `0x00401000`", "| `0x00401100`"]  # verified first
    two = table_rows(section(text, 2))
    assert {r.split(" | ")[0] for r in two} == {"| `0x00401200`", "| `0x00401400`"}
    three = table_rows(section(text, 3))
    assert len(three) == 1 and "`Magic_Conflict`" in three[0] and "`Duel_OtherName` (verified)" in three[0]
    # Same names, both generic, and the weak and ambiguous pairs appear in no section.
    for addr in ("0x00401500", "0x00401600", "0x00401700", "0x00401800"):
        assert f"`{addr}`" not in text
    assert "| 1. MAGIC semantic, DUEL generic | 2 (1 of the MAGIC names verified) |" in text
    assert "| Both semantic, the same | 1 |" in text
    assert "| Both generic | 1 |" in text
    assert "(7 pairs)" in text


def test_every_unverified_semantic_name_is_labelled(repo):
    text = report(repo)
    verified = {("MAGIC", "Magic_Verified"), ("DUEL", "Duel_OtherName")}
    semantic = [n for _, n in MAGIC + DUEL if pp.kind(n, 0)[0] == "semantic"]
    body = text.split("## 1.", 1)[1]
    checked = 0
    for name in semantic:
        for m in re.finditer(rf"`{re.escape(name)}` \(([^)]*)", body):
            checked += 1
            status = m.group(1)
            if any(name == v for _, v in verified):
                assert status in ("verified",) or status.startswith("**UNVERIFIED**"), (name, status)
            else:
                assert status.startswith("**UNVERIFIED**"), (name, status)
    assert checked >= 7


def test_verified_elsewhere_is_still_unverified_here(repo):
    row = table_rows(section(report(repo), 1))[1]
    assert "`Magic_Unverified` (**UNVERIFIED** here (verified at MAGIC 0x00409999)" in row
    assert "DUEL name ends in the MAGIC address (copied auto-label)" in row


def test_shared_duel_names(repo):
    text = report(repo)
    four = section(text, 4)
    assert "`Shared_Name` (**UNVERIFIED**) | listed |" in four
    assert "`0x00481400` (twin of `0x00401400`" in four and "`0x00481900` (no `twin` row)" in four
    two = [r for r in table_rows(section(text, 2)) if "0x00401400" in r][0]
    assert "is carried by 2 DUEL addresses" in two
    # Not listed in duplicates.md: flagged.
    (repo / "tools" / "registry" / "duplicates.md").write_text("# empty\n")
    assert "`Shared_Name` (**UNVERIFIED**) | **not listed** |" in section(report(repo), 4)


def test_c_file_names_are_noted(repo):
    row = table_rows(section(report(repo), 1))[0]
    assert "DUEL C file already says `Duel_CName` (**UNVERIFIED**; the index lags)" in row
    assert pp.main(["--repo", str(repo), "--no-c"]) == 0
    assert "Duel_CName" not in (repo / "tools" / "twins" / "propagation.md").read_text()


def test_committed_report_is_current(tmp_path):
    repo_root = pp.REPO
    if not os.path.exists(os.path.join(repo_root, "duel", "duel_unified.c")):
        pytest.skip("decompiled sources not present")
    out = tmp_path / "p.md"
    assert pp.main(["--out", str(out)]) == 0
    with open(os.path.join(HERE, "propagation.md"), encoding="utf-8") as f:
        assert out.read_text() == f.read(), "run tools/twins/propagate.py"
