"""Tests for find_twins.py. Run with: python3 -m pytest tools/twins

The end-to-end tests run the matcher on the real magic/ and duel/ decompilations (about 20 s).
"""

import csv
import os
import sys

import pytest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import find_twins as ft  # noqa: E402


# --------------------------------------------------------------------------------------------------
# Normalisation


def tokens_of(body, own=(), local=(), glob=()):
    lines, strings, consts, apis, callees = ft.tokenize_body(body, set(own), set(local), set(glob))
    return [t for line in lines for t in line], strings, consts, apis, callees


def test_masks_names_and_addresses():
    toks, strings, consts, apis, callees = tokens_of(
        "local_c = Magic_Foo(player, DAT_006a3f78 + 0x4ff590, 0x120);\n"
        "g_EventSourcePlayer = FUN_00401000(s_Draw_a_card_Phase_00525af8);\n"
        "SendMessageA(hwnd, 0x403, 0, 0);",
        own={"Magic_Foo"}, local={"local_c", "player", "hwnd"})
    assert toks == [
        "V", "=", "FN", "(", "V", ",", "G", "+", "ADDR", ",", "288", ")", ";",
        "G", "=", "FN", "(", "STR", ")", ";",
        "SendMessageA", "(", "V", ",", "1027", ",", "0", ",", "0", ")", ";",
    ]
    assert strings == {"draw_a_card_phase": 1}
    assert consts == {0x120: 1, 0x403: 1}
    assert apis == {"SendMessageA": 1}
    assert callees == ["Magic_Foo", "FUN_00401000"]


def test_renamed_twin_normalises_identically():
    magic = "iVar1 = Magic_QueryCardAttribute(player, slot, 0x32, -1);\nDAT_006ff4c0 = iVar1 + 0xff;"
    duel = "local_8 = Duel_TapCardForMana(param_1, param_2, 0x32, -1);\ng_DuelTurn = local_8 + 255;"
    a = tokens_of(magic, own={"Magic_QueryCardAttribute"}, local={"iVar1", "player", "slot"})[0]
    b = tokens_of(duel, own={"Duel_TapCardForMana"}, local={"local_8", "param_1", "param_2"})[0]
    assert a == b


def test_c_runtime_call_reads_like_an_internal_call():
    # MAGIC.EXE imports the C runtime; DUEL.EXE links it statically.
    a = tokens_of("_itoa(x, buf, 10);", local={"x", "buf"})
    b = tokens_of("Str_IntToAscii(x, buf, 10);", own={"Str_IntToAscii"}, local={"x", "buf"})
    assert a[0] == b[0]
    assert a[3] == {} and a[4] == ["_itoa"]


def test_split_functions_pairs_bodies_with_the_index():
    text = (
        "int DAT_00500000;\n\n\n"
        "int FUN_00401000(int a)\n\n{\n  int local_8;\n  \n  local_8 = a + DAT_00500000;\n"
        "  return local_8;\n}\n\n\n\n"
        "void Named_Thing(void)\n\n{\n  FUN_00401000(3);\n  return;\n}\n"
    )
    funcs = ft.build_program(text, [(0x401000, "FUN_00401000", 20), (0x401020, "Old_Name", 10)], "t")
    assert [f.addr for f in funcs] == [0x401000, 0x401020]
    assert funcs[0].tokens == ["V", "=", "V", "+", "G", ";", "return", "V", ";"]
    assert funcs[1].aliases == {"Old_Name", "Named_Thing"}
    assert funcs[1].callees == [0x401000] and funcs[0].callers == {0x401020}


# --------------------------------------------------------------------------------------------------
# Matching on small synthetic programs


def program(bodies, base):
    text = "".join(f"int FUN_{base + i * 0x100:08x}(int p)\n\n{{\n{body}\n}}\n\n\n"
                   for i, body in enumerate(bodies))
    index = [(base + i * 0x100, f"FUN_{base + i * 0x100:08x}", 40 + len(body))
             for i, body in enumerate(bodies)]
    return ft.build_program(text, index, "t")


BODY_A = "  if (p < 0x20) {\n    DAT_006a3f78 = DAT_006a3f78 + 1;\n  }\n  return p * 0x120;"
BODY_B = "  SendMessageA(DAT_0069f744, 0x403, p, 0);\n  return 0;"
BODY_C = "  while (p != 0) {\n    p = p >> 1;\n    DAT_00701234 = DAT_00701234 ^ 0x5b20;\n  }\n  return p;"


def rows_for(magic_bodies, duel_bodies):
    matcher = ft.Matcher(program(magic_bodies, 0x401000), program(duel_bodies, 0x481000))
    results = matcher.match()
    return {r["magic_addr"]: r for r in ft.build_rows(matcher, results)}


def test_twin_found_despite_different_addresses():
    rows = rows_for([BODY_A, BODY_B], [BODY_B.replace("0069f744", "00666458"), BODY_A])
    assert rows[0x401000]["duel_addr"] == 0x481100
    assert rows[0x401000]["verdict"] == "twin"
    assert rows[0x401100]["duel_addr"] == 0x481000


def test_identical_candidates_are_ambiguous():
    rows = rows_for([BODY_A], [BODY_A, BODY_C, BODY_A])
    assert rows[0x401000]["verdict"] == "ambiguous"
    assert "close=0x00481200" in rows[0x401000]["evidence"]
    assert rows[0x401000]["second"] == rows[0x401000]["score"]


# --------------------------------------------------------------------------------------------------
# The real programs


@pytest.fixture(scope="module")
def real():
    if not os.path.exists(os.path.join(ft.REPO, "magic", "magic_unified.c")):
        pytest.skip("decompiled sources not present")
    matcher, results = ft.find_twins()
    return matcher, results, ft.build_rows(matcher, results)


@pytest.mark.parametrize("magic_addr,duel_addr", ft.KNOWN_PAIRS,
                         ids=[f"{m:08x}-{d:08x}" for m, d in ft.KNOWN_PAIRS])
def test_verified_pair_is_rank_one(real, magic_addr, duel_addr):
    matcher, results, rows = real
    ranked = results[magic_addr]
    assert ranked, "no candidates"
    assert ranked[0][2] == duel_addr, [(round(s, 3), hex(a)) for s, _, a in ranked[:3]]
    row = next(r for r in rows if r["magic_addr"] == magic_addr)
    assert row["verdict"] == "twin", row["evidence"]


def test_known_pairs_rank_one_fraction(real):
    _, results, _ = real
    hit, total, _ = ft.known_pair_report(results)
    print(f"verified pairs found at rank 1: {hit}/{total} ({hit / total:.0%})")
    assert hit == total


def test_spellchain_wndproc_is_not_the_other_function_that_shared_its_name(real):
    _, results, _ = real
    for magic_addr, wrong in ft.KNOWN_NON_TWINS:
        ranked = results[magic_addr]
        assert ranked[0][2] != wrong
        others = [s for s, _, a in ranked if a == wrong]
        if others:   # scored as a candidate: must be well below the real twin
            assert others[0] < ranked[0][0] - ft.AMBIGUOUS_MARGIN


def test_csv_has_one_ranked_row_per_magic_function(real, tmp_path):
    matcher, _, rows = real
    out = tmp_path / "twins.csv"
    ft.write_csv(rows, out)
    with open(out, newline="") as f:
        reader = csv.DictReader(f)
        assert reader.fieldnames == ["magic_addr", "duel_addr", "score", "second_best_score", "evidence"]
        got = list(reader)
    assert len(got) == len(matcher.magic)
    assert len({r["magic_addr"] for r in got}) == len(got)
    order = ["twin", "weak", "ambiguous", "no-twin"]
    verdicts = [order.index(r["evidence"].split(";")[0]) for r in got]
    assert verdicts == sorted(verdicts)
    for r in got:
        assert float(r["score"]) >= float(r["second_best_score"])
        if r["evidence"].startswith("twin"):
            assert float(r["score"]) - float(r["second_best_score"]) >= ft.AMBIGUOUS_MARGIN
    # A DUEL function is the confident twin of at most one MAGIC function.
    twins = [r["duel_addr"] for r in got if r["evidence"].startswith("twin")]
    assert len(twins) == len(set(twins))
