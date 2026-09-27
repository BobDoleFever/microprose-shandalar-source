#!/usr/bin/env python3
"""Check that the repository still carries every verified name at its address.

For each row of tools/registry/verified_names.csv:

- a function must have exactly the registry name at that address in <program>/function_index.csv;
- a global must have the registry name at that address in engine_globals_map.csv, or, where that map
  has no entry for the address, in <program>/symbols.csv.

Any difference, or an address missing from the file checked, is a failure (exit 1). A global whose
program symbols.csv still has another name is only a warning: engine_globals_map.csv is the source
checked, and symbols.csv files are regenerated from Ghidra.

    python3 tools/registry/check_registry.py
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import registry as reg  # noqa: E402


def check(rows=None):
    """Return (failures, warnings); each failure is (program, address, name, source, found)."""
    rows = reg.read_registry() if rows is None else rows
    index = {p: reg.read_function_index(p) for p in reg.PROGRAMS}
    symbols = {p: reg.read_symbols(p) for p in reg.PROGRAMS}
    globals_map = reg.read_globals_map()
    failures, warnings = [], []
    for r in rows:
        prog, addr, name = r["program"], r["address"], r["name"]
        if r["kind"] == "function":
            source = f"{prog.lower()}/function_index.csv"
            found = index[prog].get(addr, [])
        elif addr in globals_map:
            source = "engine_globals_map.csv"
            found = [globals_map[addr]]
            sym = symbols[prog].get(addr, [])
            if sym and name not in sym:
                warnings.append((prog, addr, name, f"{prog.lower()}/symbols.csv", sym))
        else:
            source = f"{prog.lower()}/symbols.csv"
            found = symbols[prog].get(addr, [])
        if found != [name]:
            failures.append((prog, addr, name, source, found))
    return failures, warnings


def describe(item):
    prog, addr, name, source, found = item
    have = " / ".join(f"`{f}`" for f in found) if found else "nothing"
    return f"{prog} {reg.fmt_addr(addr)}: registry says `{name}`, {source} has {have}"


def main():
    rows = reg.read_registry()
    failures, warnings = check(rows)
    for w in warnings:
        print("warning:", describe(w))
    for f in failures:
        print("MISMATCH:", describe(f))
    print(f"{len(rows)} registry rows checked: {len(failures)} mismatches, {len(warnings)} warnings")
    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())
