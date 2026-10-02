#!/usr/bin/env python3
"""
make_inject_script.py - build the emulator script that runs card handlers on demand, so tools/difftest/record_vectors.py
can record what each one does (tools/lift/README.md).

For every chosen handler it picks the event codes the handler tests (the constants its decompiled body compares its third
parameter with, plus a few common ones), and emits `inject HANDLER EVENT NTH K` operations (winemu/run.py) for the first
card in play, once for each K: the value every function the handler calls is made to return. The operations are spaced
0.1 virtual seconds apart, so each injected call has finished (and the game has been put back) before the next starts.

    python3 make_inject_script.py SPEC.json --count 24 --start 46 [--all] > script.txt
"""
import argparse
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
COMMON = (0x15, 0x74, 0x71, 0x21)


def events_for(source, name, addr):
    """Event codes a handler's decompiled body tests its third parameter against."""
    m = re.search(r"Function: \S+ @ " + addr[2:] + r"\n \* =+ \*/\n\n[^\n]*\((.*?)\)\n\n\{(.*?)\n\}\n", source, re.S)
    if not m:
        return []
    params = [p.strip().split()[-1].lstrip("*") for p in m.group(1).split(",")]
    if len(params) < 3:
        return []
    ev, body = params[2], m.group(2)
    found = {int(x, 0) for x in re.findall(r"\b" + re.escape(ev) + r"\s*==\s*(0x[0-9a-fA-F]+|\d+)", body)}
    found |= {int(x, 0) for x in re.findall(r"\bcase\s+(0x[0-9a-fA-F]+|\d+)\s*:", body)}
    return sorted(found)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("spec")
    ap.add_argument("--count", type=int, default=24)
    ap.add_argument("--all", action="store_true", help="every lifted handler instead of an evenly spaced sample")
    ap.add_argument("--start", type=float, default=46.0)
    ap.add_argument("--step", type=float, default=0.1)
    ap.add_argument("--ks", default="0,1,2", help="values the called functions return, one injection each")
    ap.add_argument("--max-events", type=int, default=10)
    ap.add_argument("--base", default="", help="script operations to run before the injections")
    ap.add_argument("--shard", default="0/1", help="I/N: only every Nth handler starting at I, to record in N parallel runs")
    ap.add_argument("--only", help="a JSON list of handler addresses (\"0x00402cc1\"): leave the others out")
    ap.add_argument("--list", help="write the chosen handler addresses to this file")
    args = ap.parse_args()

    spec = [e for e in json.load(open(args.spec)) if e["lifted"]]
    if args.only:
        keep = {int(a, 16) for a in json.load(open(args.only))}
        spec = [e for e in spec if int(e["addr"], 16) in keep]
    spec.sort(key=lambda e: e["instructions"])
    if not args.all and len(spec) > args.count:
        step = len(spec) / args.count
        spec = [spec[int(i * step)] for i in range(args.count)]
    i, n = (int(x) for x in args.shard.split("/"))
    spec = spec[i::n]
    source = open(os.path.join(ROOT, "duel", "duel_all.c"), errors="replace").read()

    ks = [int(k, 0) for k in args.ks.split(",")]
    ops, t, chosen = [], args.start, []
    for e in spec:
        events = events_for(source, e["name"], e["addr"])
        events = (events + [c for c in COMMON if c not in events])[: args.max_events]
        chosen.append((e["addr"], events))
        for ev in events:
            for k in ks:
                ops.append(f"{t:.2f}:inject {int(e['addr'], 16):#x} {ev:#x} 0 {k:#x}")
                t += args.step
    if args.list:
        json.dump(chosen, open(args.list, "w"))
    print(";".join(([args.base] if args.base else []) + ops))
    print(f"{len(chosen)} handlers, {len(ops)} injections, ends at {t:.1f} virtual s", file=sys.stderr)


if __name__ == "__main__":
    main()
