#!/usr/bin/env python3
"""
Run MAGIC.EXE (or another PE) in the emulated Win32 host.

    python3 -m winemu.run [--exe PATH] [--seconds N] [--trace] [--trace-only REGEX] [--log-files]
                          [--shots DIR] [--quiet]

Run from tools/emu_spike. Game files come from sources/installed/Magic (your own copy); writes go to
sources/emu_overlay so the installed copy is never modified. The screen is composed from the windows the
game creates and saved as PNG in --shots (default sources/emu_shots) when the run ends.
"""
import argparse
import json
import os
import re
import sys
import time

import numpy as np
from PIL import Image

from . import crt, gdi, kernel32, user32                                     # noqa: F401  (register handlers)
from .machine import Machine

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, "..", "..", ".."))


def compose(m):
    st = m.state.get("u32", {})
    desk = np.zeros((gdi.SCREEN_H, gdi.SCREEN_W, 3), np.uint8)
    for hwnd, win in st.get("windows", {}).items():
        if not win["visible"] or win["surface"] is None or win["style"] & user32.WS_CHILD:
            continue
        s, x, y = win["surface"], win["x"], win["y"]
        x0, y0 = max(x, 0), max(y, 0)
        x1, y1 = min(x + s.w, desk.shape[1]), min(y + s.h, desk.shape[0])
        if x1 > x0 and y1 > y0:
            desk[y0:y1, x0:x1] = gdi.surface_rgb(m, s, x0 - x, y0 - y, x1 - x, y1 - y)
    return desk


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--exe", default=os.path.join(ROOT, "sources", "installed", "Magic", "Program", "MAGIC.EXE"))
    ap.add_argument("--seconds", type=float, default=30)
    ap.add_argument("--trace", action="store_true")
    ap.add_argument("--trace-only", default=None)
    ap.add_argument("--log-files", action="store_true")
    ap.add_argument("--shots", default=os.path.join(ROOT, "sources", "emu_shots"))
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--all-counts", action="store_true", help="list more of the most-called imports")
    ap.add_argument("--script", default="", help='timed actions, e.g. "20:click 230 308;25:shot a;30:key 13"')
    ap.add_argument("--shot-every", type=float, default=0, help="also save screen_NNN.png every N seconds")
    args = ap.parse_args(argv)

    game_root = os.path.join(ROOT, "sources", "installed", "Magic")
    overlay = os.path.join(ROOT, "sources", "emu_overlay")
    os.makedirs(overlay, exist_ok=True)
    os.makedirs(args.shots, exist_ok=True)
    m = Machine(args.exe, game_root, overlay, log=(lambda *_: None) if args.quiet else print)
    argc = json.load(open(os.path.join(HERE, "..", "argc_magic.json")))
    m.state["argc_table"] = argc
    m.state["log_files"] = args.log_files
    m.trace = args.trace or bool(args.trace_only)
    if args.trace_only:
        rx = re.compile(args.trace_only)
        m.trace_filter = lambda n: bool(rx.search(n))
    crt.init_argv(m, m.exe_guest_path)
    t0 = time.time()
    tick = {"n": 0, "next": time.time() + args.shot_every}
    actions = []
    for part in filter(None, (p.strip() for p in args.script.split(";"))):
        at, cmd = part.split(":", 1)
        actions.append((float(at), cmd.split()))
    actions.sort(key=lambda a: a[0])
    pending = {"clicks": []}                                   # (due_time, kind, x, y) follow-ups of a click

    def run_action(mm, cmd, now):
        op = cmd[0]
        if op == "click":                                      # move, press, then release 0.3 s later
            x, y = int(cmd[1]), int(cmd[2])
            user32.inject_mouse(mm, "move", x, y)
            user32.inject_mouse(mm, "down", x, y)
            pending["clicks"].append((now + 0.3, "up", x, y))
        elif op == "move":
            user32.inject_mouse(mm, "move", int(cmd[1]), int(cmd[2]))
        elif op == "key":
            user32.inject_key(mm, int(cmd[1]), int(cmd[2]) if len(cmd) > 2 else None)
        elif op == "shot":
            Image.fromarray(compose(mm)).save(os.path.join(args.shots, f"{cmd[1]}.png"))
            print(f"   [script] shot {cmd[1]}")

    def schedule(mm):
        kernel32.on_schedule(mm)
        now = time.time()
        while actions and now - t0 >= actions[0][0]:
            run_action(mm, actions.pop(0)[1], now)
        for c in [c for c in pending["clicks"] if c[0] <= now]:
            pending["clicks"].remove(c)
            user32.inject_mouse(mm, c[1], c[2], c[3])
        if args.shot_every and time.time() >= tick["next"]:
            tick["next"] = time.time() + args.shot_every
            tick["n"] += 1
            Image.fromarray(compose(mm)).save(os.path.join(args.shots, f"screen_{tick['n']:03d}.png"))
    m.state["on_schedule"] = schedule
    m.state["should_stop"] = lambda mm: time.time() - t0 > args.seconds
    code = m.run()
    print(f"\nfinished: exit code {code}, {m.calls} import calls, {time.time() - t0:.1f}s")
    shot = os.path.join(args.shots, "screen.png")
    Image.fromarray(compose(m)).save(shot)
    print(f"screen: {shot}")
    print("most-called imports:")
    for (dll, name), n in sorted(m.counts.items(), key=lambda kv: -kv[1])[:(60 if args.all_counts else 12)]:
        print(f"  {n:8d}  {dll}!{name}")
    if m.unimplemented:
        top = sorted(m.unimplemented.items(), key=lambda kv: -kv[1])
        print("unimplemented imports called (stubbed to 0):")
        for (dll, name), n in top[:40]:
            print(f"  {n:6d}  {dll}!{name}")
    if m.state.get("messageboxes"):
        print("message boxes:", m.state["messageboxes"])
    return 0


if __name__ == "__main__":
    sys.exit(main())
