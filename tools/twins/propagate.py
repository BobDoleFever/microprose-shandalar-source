#!/usr/bin/env python3
"""Compare the names of MAGIC.EXE / DUEL.EXE twin functions and report what could carry over.

Reads the `twin` rows of tools/twins/twins.csv, looks both functions up in magic/function_index.csv and
duel/function_index.csv, and writes tools/twins/propagation.md:

1. MAGIC.EXE has a semantic name and DUEL.EXE a generic one (a name could be carried to DUEL.EXE);
2. the reverse;
3. both semantic and different (conflicts);
4. DUEL.EXE names carried by more than one address where a twin is involved (cross-referenced with
   tools/registry/duplicates.md).

A name is **generic** when it is a Ghidra default (`FUN_...`, `thunk_FUN_...`), an auto-label
(`..._Subsystem_<hex>`), or ends in an 8-digit address: its own, or another one (the rename scripts
copied auto-labels between the programs, so many DUEL.EXE names end in their MAGIC.EXE twin's
address). Everything else is **semantic**, which only means it claims a meaning: about one in five
semantic names in this repository was found wrong, so every semantic name in the report says whether
tools/registry/verified_names.csv verifies it at that address. Nothing is renamed.

    python3 tools/twins/propagate.py
    python3 tools/twins/propagate.py --repo /path/to/checkout --out report.md

Standard library only.
"""

import argparse
import csv
import os
import re
import sys
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", ".."))

GENERIC_PREFIXES = ("FUN_", "thunk_FUN_", "LAB_", "SUB_")
SUBSYSTEM_RE = re.compile(r"_Subsystem_[0-9a-fA-F]+$")
TRAILING_ADDR_RE = re.compile(r"_([0-9a-fA-F]{8})$")


# --------------------------------------------------------------------------------------------------
# Inputs


def read_index(path):
    """{address: name} from a function_index.csv."""
    with open(path, newline="", encoding="utf-8", errors="replace") as f:
        return {int(r["Address"], 16): r["FunctionName"] for r in csv.DictReader(f)}


def read_twins(path):
    """[(magic_addr, duel_addr, score)] for the rows whose verdict is `twin`."""
    out = []
    with open(path, newline="", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r["evidence"].split(";", 1)[0].strip() == "twin" and r["duel_addr"]:
                out.append((int(r["magic_addr"], 16), int(r["duel_addr"], 16), float(r["score"])))
    return out


def read_registry(path):
    """{(program, address): name} and {name: [(program, address)]} from verified_names.csv."""
    by_addr, by_name = {}, defaultdict(list)
    if not os.path.exists(path):
        return by_addr, by_name
    with open(path, newline="", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            key = (r["program"], int(r["address"], 16))
            by_addr[key] = r["name"]
            by_name[r["name"]].append(key)
    return by_addr, by_name


def read_duplicates_md(path):
    """The DUEL.EXE names listed in tools/registry/duplicates.md (current and split-at-export)."""
    names = set()
    if not os.path.exists(path):
        return names
    in_duel = False
    with open(path, encoding="utf-8") as f:
        for line in f:
            if line.startswith("#"):
                in_duel = "DUEL.EXE" in line
                continue
            m = re.match(r"\| `([^`]+)` \|", line)
            if in_duel and m:
                names.add(m.group(1))
    return names


# --------------------------------------------------------------------------------------------------
# Classification


def kind(name, addr):
    """'generic' or 'semantic', and why a generic name is generic."""
    if name.startswith(GENERIC_PREFIXES):
        return "generic", "Ghidra default"
    if SUBSYSTEM_RE.search(name):
        return "generic", "auto-label"
    m = TRAILING_ADDR_RE.search(name)
    if m:
        if int(m.group(1), 16) == addr:
            return "generic", "ends in its own address"
        return "generic", "ends in another address"
    return "semantic", ""


def read_c_names(c_path, index_path):
    """{address: name in the unified C file} where it differs from function_index.csv.

    The index lags behind renames applied to the C files (tools/registry found one such case). Bodies
    and index rows are paired by order, as tools/twins/find_twins.py does. Empty if the file is missing.
    """
    if not (os.path.exists(c_path) and os.path.exists(index_path)):
        return {}
    sys.path.insert(0, HERE)
    import find_twins
    with open(c_path, encoding="utf-8", errors="replace") as f:
        parts = list(find_twins.split_functions(f.read()))
    rows = find_twins.read_index(index_path)
    if len(parts) != len(rows):
        return {}
    out = {}
    for (addr, name, _), (sig, _, _) in zip(rows, parts):
        c_name = find_twins.signature_name_and_params(sig)[0]
        if c_name and c_name != name:
            out[addr] = c_name
    return out


class Names:
    def __init__(self, magic, duel, registry, registry_by_name, c_names=None):
        self.index = {"MAGIC": magic, "DUEL": duel}
        self.c_names = c_names or {"MAGIC": {}, "DUEL": {}}
        self.registry = registry
        self.registry_by_name = registry_by_name
        self.duel_by_name = defaultdict(list)
        for a, n in duel.items():
            self.duel_by_name[n].append(a)

    def status(self, program, addr, name):
        """How far a name can be trusted, as the text shown next to it in the report."""
        k, why = kind(name, addr)
        reg = self.registry.get((program, addr))
        if k == "generic":
            text = f"generic: {why}"
            if reg:
                text += f"; **the registry verifies `{reg}` here**"
            return text
        if reg == name:
            return "verified"
        if reg:
            return f"**UNVERIFIED**; the registry verifies `{reg}` at this address"
        elsewhere = [f"{p} 0x{a:08x}" for p, a in self.registry_by_name.get(name, []) if (p, a) != (program, addr)]
        if elsewhere:
            return f"**UNVERIFIED** here (verified at {', '.join(elsewhere)})"
        return "**UNVERIFIED**"

    def c_note(self, program, addr):
        c_name = self.c_names.get(program, {}).get(addr)
        if not c_name:
            return ""
        k = kind(c_name, addr)[0]
        return (f"{program} C file already says `{c_name}` ({self.status(program, addr, c_name)}; "
                f"the index lags)" if k == "semantic" else "")

    def verified(self, program, addr, name):
        return self.registry.get((program, addr)) == name


# --------------------------------------------------------------------------------------------------
# The report


def analyse(twins, names):
    sections = {"to_duel": [], "to_magic": [], "conflicts": [], "agree": [], "both_generic": [], "missing": []}
    for ma, da, score in twins:
        mn, dn = names.index["MAGIC"].get(ma), names.index["DUEL"].get(da)
        if mn is None or dn is None:
            sections["missing"].append((ma, da, score, mn, dn))
            continue
        mk, dk = kind(mn, ma)[0], kind(dn, da)[0]
        row = {"magic": ma, "duel": da, "score": score, "magic_name": mn, "duel_name": dn}
        if mk == "semantic" and dk == "generic":
            sections["to_duel"].append(row)
        elif mk == "generic" and dk == "semantic":
            sections["to_magic"].append(row)
        elif mk == "semantic" and dk == "semantic":
            sections["agree" if mn == dn else "conflicts"].append(row)
        else:
            sections["both_generic"].append(row)
    return sections


def duplicate_groups(twins, names):
    """DUEL.EXE names on more than one address, where at least one of those addresses is a twin."""
    twin_of = {da: (ma, score) for ma, da, score in twins}
    groups = {}
    for name, addrs in names.duel_by_name.items():
        if len(addrs) > 1 and any(a in twin_of for a in addrs):
            groups[name] = sorted(addrs)
    return groups, twin_of


def hidden_conflict(row, names):
    """A section 1 or 2 pair whose generic side already has another semantic name in its C file."""
    for program, other in (("DUEL", "magic_name"), ("MAGIC", "duel_name")):
        addr = row[program.lower()]
        c_name = names.c_names.get(program, {}).get(addr)
        if c_name and kind(c_name, addr)[0] == "semantic" and c_name != row[other]:
            return True
    return False


def cell(name, status):
    return f"`{name}` ({status})"


def sort_key(names, program):
    return lambda r: (not names.verified(program, r[program.lower()], r[f"{program.lower()}_name"]),
                      -r["score"], r["magic"])


def notes_for_duel_target(row, names):
    """Hazards of writing the MAGIC name onto the DUEL address."""
    notes = []
    shared = names.duel_by_name.get(row["duel_name"], [])
    if len(shared) > 1:
        notes.append(f"`{row['duel_name']}` is carried by {len(shared)} DUEL addresses: rename by address")
    already = [a for a in names.duel_by_name.get(row["magic_name"], []) if a != row["duel"]]
    if already:
        notes.append(f"`{row['magic_name']}` already names DUEL " + ", ".join(f"`0x{a:08x}`" for a in already))
    m = TRAILING_ADDR_RE.search(row["duel_name"])
    if m and int(m.group(1), 16) == row["magic"]:
        notes.append("DUEL name ends in the MAGIC address (copied auto-label)")
    notes += [n for n in (names.c_note("DUEL", row["duel"]), names.c_note("MAGIC", row["magic"])) if n]
    return "; ".join(notes)


def notes_for_magic_target(row, names):
    notes = []
    shared = names.duel_by_name.get(row["duel_name"], [])
    if len(shared) > 1:
        notes.append(f"**`{row['duel_name']}` is carried by {len(shared)} DUEL addresses** "
                     f"({', '.join(f'`0x{a:08x}`' for a in sorted(shared))}): probably a rename by name that hit "
                     "more than one function; do not carry it over (section 4)")
    already = [a for a, n in names.index["MAGIC"].items() if n == row["duel_name"] and a != row["magic"]]
    if already:
        notes.append(f"`{row['duel_name']}` already names MAGIC " + ", ".join(f"`0x{a:08x}`" for a in already))
    notes += [n for n in (names.c_note("MAGIC", row["magic"]), names.c_note("DUEL", row["duel"])) if n]
    return "; ".join(notes)


def render(twins, names, dup_md_names, inputs):
    s = analyse(twins, names)
    groups, twin_of = duplicate_groups(twins, names)
    out = []
    w = out.append
    w("# Twin name propagation")
    w("")
    w("Generated by `tools/twins/propagate.py`; do not edit by hand. Nothing here has been renamed.")
    w("")
    w(f"Inputs: {', '.join(f'`{p}`' for p in inputs)}. Only `twin` rows of `twins.csv` are used "
      f"({len(twins)} pairs); `weak` and `ambiguous` pairs are left out.")
    w("")
    w("**Read every name as a claim.** About one in five semantic names in this repository was found wrong "
      "(`docs/SYMBOL_SAMPLE.md`). Each semantic name below is marked **verified** only when "
      "`tools/registry/verified_names.csv` has that name at that address; every other semantic name is "
      "marked **UNVERIFIED** where it appears. Carrying an unverified name to the other program copies the "
      "claim, not evidence for it.")
    w("")
    w("A name is *generic* when it is a Ghidra default (`FUN_`, `thunk_FUN_`), an auto-label "
      "(`..._Subsystem_<hex>`) or ends in an 8-digit address: its own, or another one. The last case is an "
      "extension of \"ends in its own address\": many DUEL.EXE names end in their MAGIC.EXE twin's address "
      "because the rename scripts copied auto-labels between the programs, and they carry no meaning.")
    w("")
    w("| | Pairs |")
    w("|---|---|")
    w(f"| 1. MAGIC semantic, DUEL generic | {len(s['to_duel'])} "
      f"({sum(names.verified('MAGIC', r['magic'], r['magic_name']) for r in s['to_duel'])} of the MAGIC names verified) |")
    w(f"| 2. DUEL semantic, MAGIC generic | {len(s['to_magic'])} "
      f"({sum(names.verified('DUEL', r['duel'], r['duel_name']) for r in s['to_magic'])} of the DUEL names verified) |")
    hidden = [r for r in s["to_duel"] + s["to_magic"] if hidden_conflict(r, names)]
    w(f"| 3. Both semantic, different | {len(s['conflicts'])} |")
    w(f"| Sections 1 and 2 where the other side's C file already has a different semantic name "
      f"(conflicts once the index catches up) | {len(hidden)} |")
    w(f"| Both semantic, the same | {len(s['agree'])} |")
    w(f"| Both generic | {len(s['both_generic'])} |")
    w(f"| 4. DUEL names on several addresses, a twin among them | {len(groups)} |")
    if s["missing"]:
        w(f"| Twin rows whose address is missing from an index | {len(s['missing'])} |")
    w("")

    header = "| MAGIC | MAGIC name | DUEL | DUEL name | Twin score | Notes |"
    rule = "|---|---|---|---|---|---|"

    def row_line(r, notes):
        return (f"| `0x{r['magic']:08x}` | {cell(r['magic_name'], names.status('MAGIC', r['magic'], r['magic_name']))} "
                f"| `0x{r['duel']:08x}` | {cell(r['duel_name'], names.status('DUEL', r['duel'], r['duel_name']))} "
                f"| {r['score']:.4f} | {notes} |")

    w("## 1. MAGIC.EXE semantic, DUEL.EXE generic")
    w("")
    w("Candidates for carrying the MAGIC.EXE name to the DUEL.EXE twin. Verified MAGIC names first, then by twin "
      "score.")
    w("")
    if s["to_duel"]:
        w(header)
        w(rule)
        for r in sorted(s["to_duel"], key=sort_key(names, "MAGIC")):
            w(row_line(r, notes_for_duel_target(r, names)))
    else:
        w("None.")
    w("")

    w("## 2. DUEL.EXE semantic, MAGIC.EXE generic")
    w("")
    w("Candidates for carrying the DUEL.EXE name back to MAGIC.EXE. Verified DUEL names first, then by twin score.")
    w("")
    if s["to_magic"]:
        w(header)
        w(rule)
        for r in sorted(s["to_magic"], key=sort_key(names, "DUEL")):
            w(row_line(r, notes_for_magic_target(r, names)))
    else:
        w("None.")
    w("")

    w("## 3. Both semantic, different names (conflicts)")
    w("")
    w("The same code carries two different meaningful names; at most one can be right, and possibly neither. "
      "Pairs where one side is verified come first.")
    w("")
    if s["conflicts"]:
        w(header)
        w(rule)
        for r in sorted(s["conflicts"], key=lambda r: (
                not (names.verified("MAGIC", r["magic"], r["magic_name"])
                     or names.verified("DUEL", r["duel"], r["duel_name"])), -r["score"], r["magic"])):
            w(row_line(r, "; ".join(n for n in (names.c_note("MAGIC", r["magic"]), names.c_note("DUEL", r["duel"])) if n)))
    else:
        w("None.")
    w("")

    w("## 4. DUEL.EXE names carried by several addresses, with a twin among them")
    w("")
    w("A rename by name hits every address in the group (this happened with `Glue_Subsystem_004cdb4f`). "
      "`duplicates.md` says whether `tools/registry/duplicates.md` lists the group.")
    w("")
    if groups:
        w("| DUEL name | duplicates.md | Addresses (MAGIC twin, twin score, MAGIC name) |")
        w("|---|---|---|")
        for name in sorted(groups, key=lambda n: (-len(groups[n]), n)):
            parts = []
            for da in groups[name]:
                if da in twin_of:
                    ma, score = twin_of[da]
                    mn = names.index["MAGIC"].get(ma, "?")
                    parts.append(f"`0x{da:08x}` (twin of `0x{ma:08x}`, {score:.4f}, "
                                 f"{cell(mn, names.status('MAGIC', ma, mn))})")
                else:
                    parts.append(f"`0x{da:08x}` (no `twin` row)")
            listed = "listed" if name in dup_md_names else "**not listed**"
            w(f"| {cell(name, names.status('DUEL', groups[name][0], name))} | {listed} | {'<br>'.join(parts)} |")
    else:
        w("None.")
    w("")
    if s["missing"]:
        w("## Twin rows not found in a function index")
        w("")
        for ma, da, score, mn, dn in s["missing"]:
            w(f"- `0x{ma:08x}` ({mn or 'not in magic/function_index.csv'}) / `0x{da:08x}` "
              f"({dn or 'not in duel/function_index.csv'}), {score:.4f}")
        w("")
    return "\n".join(out), s, groups


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--repo", default=REPO, help="repository root (default: this checkout)")
    ap.add_argument("--twins", help="default: <repo>/tools/twins/twins.csv")
    ap.add_argument("--magic-index", help="default: <repo>/magic/function_index.csv")
    ap.add_argument("--duel-index", help="default: <repo>/duel/function_index.csv")
    ap.add_argument("--registry", help="default: <repo>/tools/registry/verified_names.csv")
    ap.add_argument("--duplicates", help="default: <repo>/tools/registry/duplicates.md")
    ap.add_argument("--out", help="default: <repo>/tools/twins/propagation.md")
    ap.add_argument("--no-c", action="store_true", help="do not read the unified C files for index-lag notes")
    args = ap.parse_args(argv)
    r = args.repo
    paths = {
        "twins": args.twins or os.path.join(r, "tools", "twins", "twins.csv"),
        "magic": args.magic_index or os.path.join(r, "magic", "function_index.csv"),
        "duel": args.duel_index or os.path.join(r, "duel", "function_index.csv"),
        "registry": args.registry or os.path.join(r, "tools", "registry", "verified_names.csv"),
        "duplicates": args.duplicates or os.path.join(r, "tools", "registry", "duplicates.md"),
    }
    out = args.out or os.path.join(r, "tools", "twins", "propagation.md")
    registry, registry_by_name = read_registry(paths["registry"])
    c_names = {} if args.no_c else {
        "MAGIC": read_c_names(os.path.join(r, "magic", "magic_unified.c"), paths["magic"]),
        "DUEL": read_c_names(os.path.join(r, "duel", "duel_unified.c"), paths["duel"]),
    }
    names = Names(read_index(paths["magic"]), read_index(paths["duel"]), registry, registry_by_name, c_names)
    twins = read_twins(paths["twins"])
    inputs = [os.path.relpath(p, r) if os.path.abspath(p).startswith(os.path.abspath(r)) else p
              for p in paths.values()]
    text, s, groups = render(twins, names, read_duplicates_md(paths["duplicates"]), inputs)
    with open(out, "w", encoding="utf-8") as f:
        f.write(text)
    print(f"{len(twins)} twin pairs: {len(s['to_duel'])} MAGIC->DUEL, {len(s['to_magic'])} DUEL->MAGIC, "
          f"{len(s['conflicts'])} conflicts, {len(s['agree'])} agree, {len(s['both_generic'])} both generic; "
          f"{len(groups)} shared DUEL names -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
