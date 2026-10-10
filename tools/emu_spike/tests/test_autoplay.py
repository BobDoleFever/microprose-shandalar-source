"""The duel autopilot's decisions, on fake card data (no emulator)."""
import os
import sys

import pytest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
import autoplay  # noqa: E402


def card(name, ctype="Summon", cost="000000", p=1, t=1, flying=False):
    digits = cost.rjust(6, "0")
    c = {col: int(digits[i]) for i, col in enumerate(autoplay.COLOURS)}
    c["any"] = int(digits[5])
    return dict(name=name, type=ctype, cost=c, power=p, toughness=t, cmc=sum(c.values()), flying=flying, text="")


def land(name):
    return dict(name=name, fact=dict(type="Land"), tapped=False, slot=0, player=0, parent="Player Territory", rect=(0, 0, 80, 80), cid=1, flags=0)


@pytest.fixture
def ap():
    a = autoplay.Autoplay.__new__(autoplay.Autoplay)
    a.facts = None
    a.log = lambda *x: None
    return a


def test_cost_digits_of_info_csv_are_five_colours_then_generic():
    if not os.path.exists(autoplay.INFO):
        pytest.skip("no game data")
    f = autoplay.Facts()
    falcon = f.find("Zephyr Falcon")                                                   # 000011: one blue, one generic
    assert falcon["cost"]["U"] == 1 and falcon["cost"]["any"] == 1 and falcon["cmc"] == 2
    assert falcon["type"] == "Summon" and (falcon["power"], falcon["toughness"]) == (1, 1)
    assert f.by_id[841]["name"] == "Wall of Dust"                                      # the master card table keeps this number
    assert f.find("Zephyr Falcon")["flying"] and not f.find("Craw Wurm")["flying"]


def test_pay_plan_taps_the_colours_first_then_any_land(ap):
    lands = [land("Island"), land("Mountain"), land("Forest")]
    plan = ap.pay_plan(card("Falcon", cost="000011"), lands)                           # U + 1
    assert [l["name"] for l in plan][0] == "Island" and len(plan) == 2
    assert ap.pay_plan(card("Fire", cost="000300"), lands) is None                     # RRR: only one Mountain
    assert ap.pay_plan(card("Big", cost="000005"), lands) is None                      # 5 generic with 3 lands
    assert ap.pay_plan(card("Free"), lands) == []                                      # costs nothing


def test_names_are_matched_loosely():
    assert autoplay.norm("Tawnos's Wand") == "tawnosswand"
    assert autoplay.norm("Fire Elem.") == "fireelem"
