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
            desk[y0:y1, x0:x1] = s.rgb[y0 - y:y1 - y, x0 - x:x1 - x]
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
    m.state["on_schedule"] = kernel32.on_schedule
    m.state["should_stop"] = lambda mm: time.time() - t0 > args.seconds
    code = m.run()
    print(f"\nfinished: exit code {code}, {m.calls} import calls, {time.time() - t0:.1f}s")
    shot = os.path.join(args.shots, "screen.png")
    Image.fromarray(compose(m)).save(shot)
    print(f"screen: {shot}")
    print("most-called imports:")
    for (dll, name), n in sorted(m.counts.items(), key=lambda kv: -kv[1])[:12]:
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
