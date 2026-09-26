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

from . import crt, gdi, kernel32, kernel32_rt, user32                                     # noqa: F401  (register handlers)
from .machine import Machine

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, "..", "..", ".."))


def draw_dialogs(m, desk):
    """A plain rendering of open dialogs (grey panel, control text) so a script can see what is on screen."""
    from PIL import ImageDraw, ImageFont
    st = m.state.get("u32", {})
    img = Image.fromarray(desk)
    d = ImageDraw.Draw(img)
    try:
        font = ImageFont.truetype("/System/Library/Fonts/Supplemental/Arial.ttf", 11)
    except OSError:
        font = ImageFont.load_default()
    for h in st.get("dialogs", []):
        win = st["windows"].get(h)
        if not win:
            continue
        x0, y0 = win["x"], win["y"]
        d.rectangle([x0, y0, x0 + win["w"], y0 + win["h"]], fill=(212, 208, 200), outline=(0, 0, 0))
        d.text((x0 + 6, y0 + 3), win["title"] or "Dialog", fill=(0, 0, 128), font=font)
        for c in win["children"]:
            cw = st["windows"].get(c)
            if not cw or not cw["visible"]:
                continue
            cx0, cy0, cx1, cy1 = x0 + cw["x"], y0 + cw["y"], x0 + cw["x"] + cw["w"], y0 + cw["y"] + cw["h"]
            cls = str(cw["cls"]).upper()
            text = cw["title"]
            if cls == "BUTTON":
                style = cw["style"] & 0xF
                if style in (2, 3, 4, 5, 6, 9):                                       # radio / check boxes
                    d.ellipse([cx0, cy0 + 1, cx0 + 9, cy0 + 10], outline=(0, 0, 0), fill=(255, 255, 255))
                    if cw.get("checked"):
                        d.ellipse([cx0 + 3, cy0 + 4, cx0 + 6, cy0 + 7], fill=(0, 0, 0))
                    d.text((cx0 + 14, cy0), text.replace("&", ""), fill=(0, 0, 0), font=font)
                elif style == 7:                                                      # group box
                    d.rectangle([cx0, cy0 + 5, cx1, cy1], outline=(128, 128, 128))
                    d.text((cx0 + 8, cy0), text.replace("&", ""), fill=(0, 0, 0), font=font)
                else:
                    d.rectangle([cx0, cy0, cx1, cy1], fill=(224, 224, 224), outline=(0, 0, 0))
                    d.text((cx0 + 4, cy0 + 2), text.replace("&", ""), fill=(0, 0, 0), font=font)
            elif cls == "COMBOBOX":
                d.rectangle([cx0, cy0, cx1, cy0 + 16], fill=(255, 255, 255), outline=(0, 0, 0))
                sel = cw.get("sel", -1)
                items = cw.get("items", [])
                d.text((cx0 + 3, cy0 + 2), items[sel][0] if 0 <= sel < len(items) else "", fill=(0, 0, 0), font=font)
            else:
                d.text((cx0, cy0), text.replace("&", ""), fill=(0, 0, 0), font=font)
    return np.asarray(img)


def compose(m):
    """Paint every visible window, parents before children, children offset by their parent's position."""
    st = m.state.get("u32", {})
    desk = np.zeros((gdi.SCREEN_H, gdi.SCREEN_W, 3), np.uint8)
    wins = st.get("windows", {})

    def paint(win, ox, oy):
        s = win["surface"]
        x, y = ox + win["x"], oy + win["y"]
        if s is not None and win["proc"]:
            x0, y0 = max(x, 0), max(y, 0)
            x1, y1 = min(x + s.w, desk.shape[1]), min(y + s.h, desk.shape[0])
            if x1 > x0 and y1 > y0:
                desk[y0:y1, x0:x1] = gdi.surface_rgb(m, s, x0 - x, y0 - y, x1 - x, y1 - y)
        for c in win["children"]:
            cw = wins.get(c)
            if cw and cw["visible"]:
                paint(cw, x, y)

    for hwnd, win in wins.items():
        if win["visible"] and not win["style"] & user32.WS_CHILD and hwnd != st.get("desktop_hwnd") \
                and not win.get("dialog"):
            paint(win, 0, 0)
    return draw_dialogs(m, desk)


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
    ap.add_argument("--dump-windows", action="store_true")
    ap.add_argument("--dump-palette", action="store_true")
    ap.add_argument("--dump-bitmaps", action="store_true", help="save the game's large off-screen bitmaps as PNG")
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
    m.state["gdi_debug"] = os.environ.get("GDI_DEBUG") == "1"
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
        elif op == "dlg":                                      # dlg ID: press a button in the open dialog
            print(f"   [script] dlg {cmd[1]} -> {user32.press_dialog_button(mm, int(cmd[1]))}")
        elif op == "dlgsel":                                   # dlgsel ID INDEX
            user32.select_dialog_item(mm, int(cmd[1]), int(cmd[2]))
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
    m.state["hard_stop"] = t0 + args.seconds + 10
    m.state["should_stop"] = lambda mm: time.time() - t0 > args.seconds
    code = m.run()
    print(f"\nfinished: exit code {code}, {m.calls} import calls, {time.time() - t0:.1f}s")
    shot = os.path.join(args.shots, "screen.png")
    Image.fromarray(compose(m)).save(shot)
    print(f"screen: {shot}")
    print("most-called imports:")
    for (dll, name), n in sorted(m.counts.items(), key=lambda kv: -kv[1])[:(60 if args.all_counts else 12)]:
        print(f"  {n:8d}  {dll}!{name}")
    if args.dump_palette:
        pal = m.state.get("gdi", {}).get("system_palette", [])
        uniq = len(set(map(tuple, pal)))
        print(f"system palette: {len(pal)} entries, {uniq} distinct; first 8 {pal[:8]}; 100..104 {pal[100:104]}")
        for h, o in m.state.get("gdi", {}).get("objs", {}).items():
            if isinstance(o, tuple) and o[0] == "palette":
                print(f"  palette obj 0x{h:x}: {len(o[1])} entries, {len(set(map(tuple, o[1])))} distinct, shared_with_system={o[1] is pal}")
    if args.dump_bitmaps:
        st = m.state.get("gdi", {})
        n = 0
        for h, o in sorted(st.get("objs", {}).items()):
            if isinstance(o, gdi.Bitmap) and o.w * o.h >= 4000:
                if o.kind == "dib":
                    px = gdi.read_dib_rgb(m, o, 0, 0, o.w, o.h)
                else:
                    px = gdi.system_lut(m)[o.idx]
                if px.size and px.any():
                    Image.fromarray(px).save(os.path.join(args.shots, f"bmp_{h:x}_{o.kind}{o.bpp}_{o.w}x{o.h}.png"))
                    n += 1
        print(f"dumped {n} non-empty bitmaps to {args.shots}")
    if args.dump_windows:
        print("windows (hwnd class title visible x,y w x h parent style):")
        for h, w in m.state.get("u32", {}).get("windows", {}).items():
            print(f"  0x{h:x} {w['cls']!r} {w['title']!r} vis={int(w['visible'])} {w['x']},{w['y']} {w['w']}x{w['h']} "
                  f"parent=0x{w['parent']:x} style=0x{w['style']:08x} tid={w.get('tid')} "
                  f"invalid={int(w['invalid'])} painted={int((w['surface'].idx != 0).sum()) if w['surface'] is not None else 0}px")
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
