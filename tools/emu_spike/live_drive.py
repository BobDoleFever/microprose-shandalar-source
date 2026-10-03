#!/usr/bin/env python3
"""
Drive the live window without a screen: the game runs with SDL's dummy video driver and a script of real pygame events (clicks, keys)
is posted to it, so what the window would show can be saved as PNG and the run repeated.

    cd tools/emu_spike
    SEQ="w:10 c:330,390 w:40 s:menu" python3 live_drive.py                # Resume Game, wait, save the frame as live_menu.png
    OUT=/tmp/shot SEQ="..." SESSION=/tmp/cmds.txt python3 live_drive.py   # then append tokens to /tmp/cmds.txt while it runs; `quit` ends

Tokens (space separated, run in order):
    w:SECS         wait
    c:X,Y          click (mouse move, 0.3 s, button down 0.12 s, up)
    k:NAME         press a key (pygame name; enter, esc, space, tab, a..z, 1..0; shift+b for a capital)
    s:NAME         save the frame the window shows as $OUT_NAME.png
    sent:          pending cross-thread SendMessage calls
    top:SECS       the imports called during SECS
    n:             print the counters of a few imports        win:   list the windows         rec:  the last imports called
    pal:           system palette and index statistics         thr:   thread states            r:A,B  read guest dwords (hex)
    p:SECS         histogram of where the guest is (needs LIVE_SAMPLE=1)
Other arguments are passed to winemu.run (for example --dump-windows, --break ...). Environment: EMU_SRAND=N fixes the game's random
seed, LIVE_TICK_MS / LIVE_STATS / GDI_DEBUG as in winemu/live.py.

Everything here reads Python-side state only: reading the guest's registers from another thread while it runs corrupts it.
"""
import os
import sys
import threading
import time

os.environ.setdefault("SDL_VIDEODRIVER", "dummy")
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import pygame  # noqa: E402
from PIL import Image  # noqa: E402

from winemu import live, run  # noqa: E402

OUT = os.environ.get("OUT", "live")
KEYS = {"enter": "return", "esc": "escape"}


def post(*a, **k):
    pygame.event.post(pygame.event.Event(*a, **k))


def press(arg):
    *mods, key = arg.split("+")
    key = KEYS.get(key, key)
    code = pygame.key.key_code
    for mod in mods:
        post(pygame.KEYDOWN, key=code("left " + mod), unicode="", mod=0, scancode=0)
        time.sleep(0.05)
    ch = {"return": "\r", "space": " "}.get(key, key if len(key) == 1 else "")
    if "shift" in mods and len(key) == 1:
        ch = key.upper()
    post(pygame.KEYDOWN, key=code(key), unicode=ch, mod=0, scancode=0)
    time.sleep(0.08)
    post(pygame.KEYUP, key=code(key), mod=0, scancode=0)
    time.sleep(0.05)
    for mod in reversed(mods):
        post(pygame.KEYUP, key=code("left " + mod), mod=0, scancode=0)
        time.sleep(0.05)


def tokens():
    for tok in os.environ.get("SEQ", "").split():
        yield tok
    sess = os.environ.get("SESSION")
    if sess:
        pos = 0
        open(sess, "a").close()
        while True:
            with open(sess) as fh:
                fh.seek(pos)
                data = fh.read()
                pos = fh.tell()
            for tok in data.split():
                if tok == "quit":
                    return
                yield tok
            time.sleep(0.3)


def helper(lv):
    t0 = time.time()
    for tok in tokens():
        op, _, arg = tok.partition(":")
        m = lv.machine
        if op == "w":
            time.sleep(float(arg))
        elif op == "s":
            with lv.lock:
                f = lv.frame
            Image.fromarray(f).save(f"{OUT}_{arg}.png")
            print(f"[{time.time() - t0:6.1f}s real, vt {m.vt:6.1f}] saved {arg}", flush=True)
        elif op == "c":
            x, y = map(int, arg.split(","))
            post(pygame.MOUSEMOTION, pos=(x, y), rel=(0, 0), buttons=(0, 0, 0))
            time.sleep(0.3)
            post(pygame.MOUSEBUTTONDOWN, pos=(x, y), button=1)
            time.sleep(0.12)
            post(pygame.MOUSEBUTTONUP, pos=(x, y), button=1)
        elif op == "k":
            press(arg)
        elif op == "n":
            c = {k[1]: v for k, v in m.counts.items()}
            print("COUNTS", {k: c.get(k) for k in ("SetPixelV", "BitBlt", "TextOutA", "GetMessageA", "SetDIBitsToDevice")},
                  "calls", m.calls, "vt", round(m.vt, 1), flush=True)
        elif op == "win":
            for h, w in list(m.state.get("u32", {}).get("windows", {}).items()):
                print(f"WIN 0x{h:x} {w['cls']!r} {w['title']!r} vis={int(w['visible'])} en={int(w.get('enabled', 1))} {w['x']},{w['y']} "
                      f"{w['w']}x{w['h']} parent=0x{w['parent']:x} tid={w.get('tid')}", flush=True)
        elif op == "top":                                      # top:SECS  the imports called during SECS, most first
            before = dict(m.counts)
            n0, v0 = m.calls, m.vt
            time.sleep(float(arg or 5))
            diff = sorted(((v - before.get(k, 0), k) for k, v in dict(m.counts).items() if v > before.get(k, 0)), reverse=True)[:8]
            print("TOP", m.calls - n0, "calls,", round(m.vt - v0, 2), "virtual s:", [(k[1], n) for n, k in diff], flush=True)
        elif op == "sent":
            st = m.state.get("u32", {})
            for r in list(st.get("sent", [])):
                w = st["windows"].get(r["hwnd"], {})
                owner = next((t for t in m.threads if t.tid == r["tid"]), None)
                print(f"SENT to t{r['tid']} ({owner.name + ' ' + owner.state if owner else 'gone'}): window 0x{r['hwnd']:x} {w.get('cls')!r} {w.get('title')!r} "
                      f"msg=0x{r['msg']:x} wp=0x{r['wp']:x} lp=0x{r['lp']:x} done={r['done']} running={r.get('running')}", flush=True)
        elif op == "rec":
            print("REC", [(t, n, hex(r)) for t, n, r in list(m.recent)[-30:]], flush=True)
        elif op == "thr":
            for t in list(m.threads):
                what = ""
                if t.state == "blocked":
                    w = t.wait
                    call = m.stubs.get(t.retry[0]) if t.retry else None
                    g = t.gen[0] if t.gen else None
                    gname = g.gi_code.co_name if g is not None else ""
                    gline = (g.gi_frame.f_lineno if g.gi_frame else 0) if g is not None else 0
                    what = f"in {call[1] if call else (('handler ' + gname + ':' + str(gline) + ' conts=' + str(len(t.conts))) if g is not None else 'a handler')} until={getattr(w, 'until', None)} ready={'yes' if getattr(w, 'ready', None) else 'no'}"
                print("THR", t.tid, t.name, t.state, what, flush=True)
        elif op == "pal":
            import numpy as np
            from winemu import gdi, user32
            sf = m.state["u32"]["windows"][user32.main_hwnd(m)]["surface"]
            lut = np.array(gdi.system_lut(m))
            print("PAL nonblack entries", int((lut.sum(1) > 0).sum()), "indices used", len(np.unique(sf.idx)),
                  "direct fraction", float(sf.direct.mean()), flush=True)
        elif op == "r":
            print("MEM", {a: hex(m.r32(int(a, 16))) for a in arg.split(",")}, flush=True)
        elif op == "p":
            lv.samples.clear()
            time.sleep(float(arg or 3))
            print("SAMPLE", sum(lv.samples.values()), [(hex(a), n) for a, n in lv.samples.most_common(14)], flush=True)
        else:
            print("unknown token", tok, flush=True)
    post(pygame.QUIT)


_run = live.Live.run


def patched(self, m):
    def go():
        try:
            helper(self)
        except BaseException:                                   # noqa: BLE001  (shown, then the window is closed)
            import traceback
            traceback.print_exc()
            post(pygame.QUIT)
    threading.Thread(target=go, daemon=True).start()
    return _run(self, m)


live.Live.run = patched
sys.exit(run.main(["--live"] + sys.argv[1:]))
