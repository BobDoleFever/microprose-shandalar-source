"""USER32: window classes, windows, messages and the message pump, timers, dialogs and menus (minimal)."""
import struct
import time as _time

from .crt import va
from .cformat import format_c
from .gdi import (Surface, SCREEN_W, SCREEN_H, Bitmap, DC, dc_of, fill_rect, get_stock, new_dc, new_obj, obj,
                  colorref, text_size, draw_text, _st as gdi_st)
from .machine import Block, Cont, api, u32
from . import kernel32

u = lambda name, argc: api("user32.dll", name, argc)
S32 = lambda v: v - 0x100000000 if v & 0x80000000 else v

WM_NULL, WM_CREATE, WM_DESTROY, WM_MOVE, WM_SIZE, WM_ACTIVATE, WM_SETFOCUS, WM_KILLFOCUS = 0, 1, 2, 3, 5, 6, 7, 8
WM_PAINT, WM_CLOSE, WM_QUIT, WM_ERASEBKGND, WM_SHOWWINDOW, WM_ACTIVATEAPP, WM_SETCURSOR = 0xF, 0x10, 0x12, 0x14, 0x18, 0x1C, 0x20
WM_GETMINMAXINFO, WM_NCCREATE, WM_NCDESTROY, WM_NCCALCSIZE, WM_NCACTIVATE, WM_NCHITTEST = 0x24, 0x81, 0x82, 0x83, 0x86, 0x84
WM_INITDIALOG, WM_COMMAND, WM_TIMER = 0x110, 0x111, 0x113
WM_WINDOWPOSCHANGING, WM_WINDOWPOSCHANGED = 0x46, 0x47
WS_CHILD, WS_VISIBLE, WS_POPUP, WS_CAPTION = 0x40000000, 0x10000000, 0x80000000, 0x00C00000


def _st(m):
    st = m.state.setdefault("u32", {})
    if not st:
        st.update(classes={}, windows={}, next_hwnd=0x10010, queue=[], quit=None, timers={}, focus=0, active=0,
                  capture=0, cursor=(320, 240), dirty=False, keys={}, last_idle=_time.time(), depth=0,
                  menus={}, next_menu=0x9001, dialogs=[])
    return st


def window(m, h):
    return _st(m)["windows"].get(h)


def mark_dirty(m):
    _st(m)["dirty"] = True


# ---- classes -------------------------------------------------------------------------------------------------
@u("RegisterClassA", 1)
def register_class(m, a):
    style, proc, cbcls, cbwnd, hinst, icon, cursor, bg, menu, name = struct.unpack("<10I", m.rd(a[0], 40))
    key = m.cstr(name).decode("latin-1").lower() if name > 0xFFFF else f"#{name}"
    st = _st(m)
    st["classes"][key] = dict(style=style, proc=proc, cbwnd=cbwnd, hinst=hinst, cursor=cursor, bg=bg,
                              name=key, extra=cbcls)
    return 0xC000 + len(st["classes"])


@u("SetClassLongA", 3)
def set_class_long(m, a):
    return 0


# ---- window creation ----------------------------------------------------------------------------------------
def new_window(m, cls, parent, style, exstyle, x, y, w, h, title, menu, param):
    st = _st(m)
    hwnd = st["next_hwnd"]
    st["next_hwnd"] += 4
    c = st["classes"].get(cls.lower() if isinstance(cls, str) else cls)
    win = dict(hwnd=hwnd, cls=cls, proc=c["proc"] if c else 0, parent=parent, style=style, exstyle=exstyle,
               x=x, y=y, w=w, h=h, title=title, visible=False, enabled=True, id=menu if style & WS_CHILD else 0,
               long={}, extra={}, invalid=True, surface=None, children=[], param=param, userdata=0,
               builtin=c is None, hinst=c["hinst"] if c else 0)
    st["windows"][hwnd] = win
    if parent and parent in st["windows"]:
        st["windows"][parent]["children"].append(hwnd)
    _resize_surface(win)
    return win


def _resize_surface(win):
    cw, ch = client_size(win)
    if win["surface"] is None or (win["surface"].w, win["surface"].h) != (cw, ch):
        win["surface"] = Surface(max(cw, 1), max(ch, 1))


def client_size(win):
    """Client area size. Windows created with a caption/frame lose the frame; kept simple: 0 frame."""
    return max(win["w"], 0), max(win["h"], 0)


def send(m, hwnd, msg, wp, lp):
    """Generator: deliver a message synchronously to a window procedure and return its result."""
    win = window(m, hwnd)
    if win is None:
        return 0
    if win["proc"]:
        r = yield Cont(win["proc"], [hwnd, msg, wp, lp])
        return r
    return default_proc(m, win, msg, wp, lp)


def default_proc(m, win, msg, wp, lp):
    if msg == WM_NCCREATE or msg == WM_ERASEBKGND:
        return 1
    if msg == WM_NCHITTEST:
        return 1
    if msg == WM_CLOSE:
        destroy(m, win["hwnd"])
        return 0
    return 0


@u("DefWindowProcA", 4)
def def_window_proc(m, a):
    win = window(m, a[0])
    return default_proc(m, win, a[1], a[2], a[3]) if win else 0


@u("CallWindowProcA", 5)
def call_window_proc(m, a):
    if a[0] in m.stubs:
        win = window(m, a[1])
        return default_proc(m, win, a[2], a[3], a[4]) if win else 0
    return Cont(a[0], [a[1], a[2], a[3], a[4]])


@u("CreateWindowExA", 12)
def create_window_ex(m, a):
    exstyle, cls, title, style, x, y, w, h, parent, menu, hinst, param = a
    cname = m.cstr(cls).decode("latin-1") if cls > 0xFFFF else f"#{cls}"
    ttl = m.cstr(title).decode("latin-1") if title > 0xFFFF else ""
    x, y, w, h = map(S32, (x, y, w, h))
    if x == S32(0x80000000):
        x = 0
    if y == S32(0x80000000):
        y = 0
    win = new_window(m, cname, parent, style, exstyle, x, y, w if w != S32(0x80000000) else 640,
                     h if h != S32(0x80000000) else 480, ttl, menu, param)
    hwnd = win["hwnd"]
    m.log(f"   CreateWindowEx(class={cname!r}, title={ttl!r}, style=0x{style:08x}, {w}x{h} at {x},{y}) -> hwnd 0x{hwnd:x}"
          + ("" if win["proc"] else "  [builtin control]"))
    if not win["proc"]:
        return hwnd
    cs = m.alloc(48)
    m.wr(cs, struct.pack("<12I", param, hinst, menu, parent, u32(h), u32(w), u32(y), u32(x), style, title, cls, exstyle))
    r = yield from send(m, hwnd, WM_NCCREATE, 0, cs)
    if not r:
        destroy(m, hwnd)
        return 0
    yield from send(m, hwnd, WM_NCCALCSIZE, 0, 0)
    r = yield from send(m, hwnd, WM_CREATE, 0, cs)
    if S32(r) == -1:
        destroy(m, hwnd)
        return 0
    if style & WS_VISIBLE:
        yield from show(m, hwnd, 1)
    return hwnd


def destroy(m, hwnd):
    st = _st(m)
    win = st["windows"].pop(hwnd, None)
    if win:
        for c in list(win["children"]):
            destroy(m, c)
    return 1


@u("DestroyWindow", 1)
def destroy_window(m, a):
    win = window(m, a[0])
    if not win:
        return 0
    if win["proc"]:
        yield Cont(win["proc"], [a[0], WM_DESTROY, 0, 0])
    destroy(m, a[0])
    return 1


def show(m, hwnd, cmd):
    win = window(m, hwnd)
    if win is None:
        return 0
    was = win["visible"]
    win["visible"] = cmd != 0
    if cmd and not was:
        _st(m)["dirty"] = True
        win["invalid"] = True
        yield from send(m, hwnd, WM_SHOWWINDOW, 1, 0)
        if not win["style"] & WS_CHILD:
            st = _st(m)
            st["active"] = st["focus"] = hwnd
            yield from send(m, hwnd, WM_ACTIVATEAPP, 1, 1)
            yield from send(m, hwnd, WM_ACTIVATE, 1, 0)
            yield from send(m, hwnd, WM_SETFOCUS, 0, 0)
            cw, ch = client_size(win)
            yield from send(m, hwnd, WM_SIZE, 0, (cw & 0xFFFF) | (ch << 16))
            yield from send(m, hwnd, WM_MOVE, 0, (win["x"] & 0xFFFF) | (win["y"] << 16))
    return int(was)


@u("ShowWindow", 2)
def show_window(m, a):
    r = yield from show(m, a[0], a[1])
    return r


@u("UpdateWindow", 1)
def update_window(m, a):
    win = window(m, a[0])
    if win and win["invalid"] and win["visible"]:
        yield from send(m, a[0], WM_PAINT, 0, 0)
    return 1


@u("InvalidateRect", 3)
def invalidate_rect(m, a):
    win = window(m, a[0])
    if win:
        win["invalid"] = True
        _st(m)["dirty"] = True
    return 1


@u("ScrollWindow", 5)
def scroll_window(m, a):
    return 1


# ---- window geometry ---------------------------------------------------------------------------------------
def _put_rect(m, p, l, t, r, b):
    m.wr(p, struct.pack("<4i", l, t, r, b))


@u("GetClientRect", 2)
def get_client_rect(m, a):
    win = window(m, a[0])
    if not win:
        return 0
    cw, ch = client_size(win)
    _put_rect(m, a[1], 0, 0, cw, ch)
    return 1


@u("GetWindowRect", 2)
def get_window_rect(m, a):
    win = window(m, a[0])
    if not win:
        return 0
    _put_rect(m, a[1], win["x"], win["y"], win["x"] + win["w"], win["y"] + win["h"])
    return 1


@u("MoveWindow", 6)
def move_window(m, a):
    win = window(m, a[0])
    if win:
        win["x"], win["y"], win["w"], win["h"] = S32(a[1]), S32(a[2]), S32(a[3]), S32(a[4])
        _resize_surface(win)
        win["invalid"] = True
        mark_dirty(m)
    return 1


@u("SetWindowPos", 7)
def set_window_pos(m, a):
    win = window(m, a[0])
    hwnd, after, x, y, cx, cy, flags = a
    if win:
        if not flags & 2:
            win["x"], win["y"] = S32(x), S32(y)
        if not flags & 1:
            win["w"], win["h"] = S32(cx), S32(cy)
            _resize_surface(win)
        if flags & 0x40:
            yield from show(m, hwnd, 1)
        elif flags & 0x80:
            yield from show(m, hwnd, 0)
        win["invalid"] = True
        mark_dirty(m)
    return 1


@u("AdjustWindowRect", 3)
def adjust_window_rect(m, a):
    return 1


@u("ClientToScreen", 2)
def client_to_screen(m, a):
    return 1


@u("ScreenToClient", 2)
def screen_to_client(m, a):
    return 1


@u("MapWindowPoints", 4)
def map_window_points(m, a):
    return 0


@u("GetSystemMetrics", 1)
def get_system_metrics(m, a):
    return {0: SCREEN_W, 1: SCREEN_H, 4: 19, 5: 1, 6: 1, 7: 3, 8: 3, 15: 19, 32: 4, 33: 4, 3: 32, 2: 16, 28: 4, 29: 4,
            16: SCREEN_W, 17: SCREEN_H - 40, 75: 0}.get(a[0], 0)


# ---- rectangles (pure functions) -----------------------------------------------------------------------------
u("SetRect", 5)(lambda m, a: (_put_rect(m, a[0], *map(S32, a[1:5])), 1)[1])
u("CopyRect", 2)(lambda m, a: (m.wr(a[0], m.rd(a[1], 16)), 1)[1])


@u("OffsetRect", 3)
def offset_rect(m, a):
    l, t, r, b = struct.unpack("<4i", m.rd(a[0], 16))
    dx, dy = S32(a[1]), S32(a[2])
    _put_rect(m, a[0], l + dx, t + dy, r + dx, b + dy)
    return 1


@u("InflateRect", 3)
def inflate_rect(m, a):
    l, t, r, b = struct.unpack("<4i", m.rd(a[0], 16))
    dx, dy = S32(a[1]), S32(a[2])
    _put_rect(m, a[0], l - dx, t - dy, r + dx, b + dy)
    return 1


@u("IsRectEmpty", 1)
def is_rect_empty(m, a):
    l, t, r, b = struct.unpack("<4i", m.rd(a[0], 16))
    return int(r <= l or b <= t)


@u("PtInRect", 3)
def pt_in_rect(m, a):
    l, t, r, b = struct.unpack("<4i", m.rd(a[0], 16))
    x, y = S32(a[1]), S32(a[2])
    return int(l <= x < r and t <= y < b)


@u("UnionRect", 3)
def union_rect(m, a):
    r1, r2 = struct.unpack("<4i", m.rd(a[1], 16)), struct.unpack("<4i", m.rd(a[2], 16))
    _put_rect(m, a[0], min(r1[0], r2[0]), min(r1[1], r2[1]), max(r1[2], r2[2]), max(r1[3], r2[3]))
    return 1


# ---- window state ------------------------------------------------------------------------------------------
GWL = {-4: "proc", -16: "style", -20: "exstyle", -21: "userdata", -12: "id", -6: "hinst", -8: "parent"}


@u("GetWindowLongA", 2)
def get_window_long(m, a):
    win = window(m, a[0])
    if not win:
        return 0
    idx = S32(a[1])
    if idx in GWL:
        return u32(win[GWL[idx]])
    return win["extra"].get(idx, 0)


@u("SetWindowLongA", 3)
def set_window_long(m, a):
    win = window(m, a[0])
    if not win:
        return 0
    idx = S32(a[1])
    if idx in GWL:
        old = win[GWL[idx]]
        win[GWL[idx]] = a[2]
        if idx == -4:
            win["builtin"] = False
        return u32(old)
    old = win["extra"].get(idx, 0)
    win["extra"][idx] = a[2]
    return old


u("GetParent", 1)(lambda m, a: (window(m, a[0]) or {}).get("parent", 0))
u("GetWindow", 2)(lambda m, a: 0)
u("GetDlgCtrlID", 1)(lambda m, a: (window(m, a[0]) or {}).get("id", 0))
u("IsWindowVisible", 1)(lambda m, a: int(bool((window(m, a[0]) or {}).get("visible"))))
u("IsIconic", 1)(lambda m, a: 0)
u("EnableWindow", 2)(lambda m, a: 0)
u("SetWindowRgn", 3)(lambda m, a: 1)
u("LockWindowUpdate", 1)(lambda m, a: 1)
u("BringWindowToTop", 1)(lambda m, a: 1)
u("SetForegroundWindow", 1)(lambda m, a: 1)
u("GetWindowThreadProcessId", 2)(lambda m, a: (m.w32(a[1], 1) if a[1] else None, 1)[1])
u("EnumChildWindows", 3)(lambda m, a: 0)
u("GetClassNameA", 3)(lambda m, a: len((window(m, a[0]) or {"cls": ""})["cls"]))
u("WinHelpA", 4)(lambda m, a: 1)
u("MessageBeep", 1)(lambda m, a: 1)


@u("FindWindowA", 2)
def find_window(m, a):
    return 0


@u("FindWindowExA", 4)
def find_window_ex(m, a):
    return 0


@u("SetFocus", 1)
def set_focus(m, a):
    st = _st(m)
    old, st["focus"] = st["focus"], a[0]
    return old


u("GetFocus", 0)(lambda m, a: _st(m)["focus"])
u("SetActiveWindow", 1)(lambda m, a: _st(m).__setitem__("active", a[0]) or 0)
u("SetCapture", 1)(lambda m, a: (_st(m).__setitem__("capture", a[0]), 0)[1])
u("GetCapture", 0)(lambda m, a: _st(m)["capture"])
u("ReleaseCapture", 0)(lambda m, a: (_st(m).__setitem__("capture", 0), 1)[1])


@u("SetWindowTextA", 2)
def set_window_text(m, a):
    win = window(m, a[0])
    if win:
        win["title"] = m.cstr(a[1]).decode("latin-1")
    return 1


@u("GetWindowTextA", 3)
def get_window_text(m, a):
    win = window(m, a[0])
    b = (win["title"] if win else "").encode("latin-1")[:max(a[2] - 1, 0)]
    m.put_cstr(a[1], b)
    return len(b)


# ---- cursor, keyboard state ----------------------------------------------------------------------------------
u("ShowCursor", 1)(lambda m, a: 0)
u("SetCursor", 1)(lambda m, a: 0)
u("LoadCursorA", 2)(lambda m, a: new_obj(m, ("cursor", a[1])))
u("LoadIconA", 2)(lambda m, a: new_obj(m, ("icon", a[1])))
u("DestroyIcon", 1)(lambda m, a: 1)
u("DestroyCursor", 1)(lambda m, a: 1)
u("LoadAcceleratorsA", 2)(lambda m, a: new_obj(m, ("accel", a[1])))
u("TranslateAcceleratorA", 3)(lambda m, a: 0)
u("GetDoubleClickTime", 0)(lambda m, a: 500)


@u("GetCursorPos", 1)
def get_cursor_pos(m, a):
    x, y = _st(m)["cursor"]
    m.w32(a[0], x)
    m.w32(a[0] + 4, y)
    return 1


@u("SetCursorPos", 2)
def set_cursor_pos(m, a):
    _st(m)["cursor"] = (S32(a[0]), S32(a[1]))
    return 1


u("WindowFromPoint", 2)(lambda m, a: next((h for h, w in reversed(list(_st(m)["windows"].items()))
                                            if w["visible"] and not w["style"] & WS_CHILD), 0))
u("GetKeyState", 1)(lambda m, a: 0x8000 if _st(m)["keys"].get(a[0]) else 0)
u("GetAsyncKeyState", 1)(lambda m, a: 0x8000 if _st(m)["keys"].get(a[0]) else 0)


# ---- messages ------------------------------------------------------------------------------------------------
@u("SendMessageA", 4)
def send_message(m, a):
    r = yield from send(m, a[0], a[1], a[2], a[3])
    return r


@u("SendDlgItemMessageA", 5)
def send_dlg_item_message(m, a):
    return 0


@u("PostMessageA", 4)
def post_message(m, a):
    _st(m)["queue"].append((a[0], a[1], a[2], a[3]))
    return 1


@u("PostQuitMessage", 1)
def post_quit(m, a):
    _st(m)["quit"] = a[0]
    return 0


u("GetMessageTime", 0)(lambda m, a: kernel32.now_ms(m))
u("TranslateMessage", 1)(lambda m, a: 0)


@u("DispatchMessageA", 1)
def dispatch_message(m, a):
    hwnd, msg, wp, lp = struct.unpack("<4I", m.rd(a[0], 16))
    if msg == WM_TIMER and lp:
        yield Cont(lp, [hwnd, WM_TIMER, wp, kernel32.now_ms(m)])
        return 0
    r = yield from send(m, hwnd, msg, wp, lp)
    return r


def _next_message(m, remove, hwnd_filter=0):
    """A pending message tuple, or None. Synthesizes WM_PAINT for invalid visible windows, and due timers."""
    st = _st(m)
    for i, msg in enumerate(st["queue"]):
        if not hwnd_filter or msg[0] == hwnd_filter:
            if remove:
                st["queue"].pop(i)
            return msg
    t = kernel32.now_ms(m)
    for (hwnd, tid), tm in list(st["timers"].items()):
        if tm["next"] <= t and hwnd in st["windows"] or (hwnd == 0 and tm["next"] <= t):
            tm["next"] = t + max(tm["delay"], 1)
            return (hwnd, WM_TIMER, tid, tm["proc"])
    for hwnd, win in st["windows"].items():
        if win["invalid"] and win["visible"] and win["proc"]:
            if remove:
                win["invalid"] = False
            return (hwnd, WM_PAINT, 0, 0)
    return None


def _write_msg(m, p, msg):
    m.wr(p, struct.pack("<7I", msg[0], msg[1], msg[2], msg[3], kernel32.now_ms(m), _st(m)["cursor"][0],
                        _st(m)["cursor"][1]))


@u("PeekMessageA", 5)
def peek_message(m, a):
    hook = m.state.get("on_pump")
    if hook:
        hook(m)
    st = _st(m)
    if st["quit"] is not None:
        _write_msg(m, a[0], (0, WM_QUIT, st["quit"], 0))
        if a[4] & 1:
            st["quit"] = None
        return 1
    msg = _next_message(m, bool(a[4] & 1), a[1])
    if msg is None:
        return 0
    _write_msg(m, a[0], msg)
    return 1


@u("GetMessageA", 4)
def get_message(m, a):
    st = _st(m)
    hook = m.state.get("on_pump")
    if hook:
        hook(m)
    if st["quit"] is None and m.state.get("should_stop") and m.state["should_stop"](m):
        st["quit"] = 0
    if st["quit"] is not None:
        _write_msg(m, a[0], (0, WM_QUIT, st["quit"], 0))
        return 0
    msg = _next_message(m, True, a[1])
    if msg is not None:
        _write_msg(m, a[0], msg)
        return 1
    return Block(until=_time.time() + 0.003)                     # idle: let other threads run, then look again


@u("SetTimer", 4)
def set_timer(m, a):
    st = _st(m)
    tid = a[1] or (len(st["timers"]) + 1)
    st["timers"][(a[0], tid)] = {"delay": max(a[2], 1), "proc": a[3], "next": kernel32.now_ms(m) + max(a[2], 1)}
    return tid


@u("KillTimer", 2)
def kill_timer(m, a):
    _st(m)["timers"].pop((a[0], a[1]), None)
    return 1


# ---- painting and DCs ------------------------------------------------------------------------------------------
@u("GetDC", 1)
def get_dc(m, a):
    h, d = new_dc(m, "window", a[0])
    if not a[0] or not window(m, a[0]):
        d.hwnd = _desktop_window(m)
    return h


@u("GetWindowDC", 1)
def get_window_dc(m, a):
    return get_dc(m, a)


def _desktop_window(m):
    st = _st(m)
    if "desktop_hwnd" not in st:
        w = new_window(m, "#desktop", 0, 0, 0, 0, 0, SCREEN_W, SCREEN_H, "", 0, 0)
        w["visible"] = True
        st["desktop_hwnd"] = w["hwnd"]
    return st["desktop_hwnd"]


u("ReleaseDC", 2)(lambda m, a: 1)


@u("BeginPaint", 2)
def begin_paint(m, a):
    win = window(m, a[0])
    h, d = new_dc(m, "window", a[0])
    cw, ch = client_size(win) if win else (0, 0)
    m.wr(a[1], struct.pack("<IIiiiiII", h, 1, 0, 0, cw, ch, 0, 0) + b"\0" * 32)
    if win:
        win["invalid"] = False
    return h


u("EndPaint", 2)(lambda m, a: 1)


@u("FillRect", 3)
def fill_rect_api(m, a):
    dc = dc_of(m, a[0])
    l, t, r, b = struct.unpack("<4i", m.rd(a[1], 16))
    br = obj(m, a[2])
    if a[2] < 32 and not br:                                # COLOR_xxx + 1 system brush indices
        color = (192, 192, 192)
    else:
        color = br[1] if br and br[0] == "brush" and br[1] else None
    if dc and color is not None:
        fill_rect(m, dc, l, t, r, b, color)
    return 1


@u("FrameRect", 3)
def frame_rect(m, a):
    dc = dc_of(m, a[0])
    l, t, r, b = struct.unpack("<4i", m.rd(a[1], 16))
    br = obj(m, a[2])
    color = br[1] if br and br[0] == "brush" and br[1] else (0, 0, 0)
    for x0, y0, x1, y1 in ((l, t, r, t + 1), (l, b - 1, r, b), (l, t, l + 1, b), (r - 1, t, r, b)):
        fill_rect(m, dc, x0, y0, x1, y1, color)
    return 1


u("DrawFocusRect", 2)(lambda m, a: 1)


@u("DrawTextA", 5)
def draw_text_a(m, a):
    dc = dc_of(m, a[0])
    s = m.cstr(a[1]) if S32(a[2]) < 0 else m.rd(a[1], a[2])
    l, t, r, b = struct.unpack("<4i", m.rd(a[3], 16))
    fmt = a[4]
    tw, th = text_size(m, dc, s)
    x = l
    if fmt & 1:
        x = l + (r - l - tw) // 2
    elif fmt & 2:
        x = r - tw
    y = t + ((b - t - th) // 2 if fmt & 4 else 0)
    if not fmt & 0x400:                                         # DT_CALCRECT
        draw_text(m, dc, x, y, s)
    else:
        m.wr(a[3], struct.pack("<4i", l, t, l + tw, t + th))
    return th


# ---- strings ---------------------------------------------------------------------------------------------------
@api("user32.dll", "wsprintfA", None)
def wsprintf(m, a):
    out = format_c(m, m.cstr(a[1]), va(m, 2))
    m.put_cstr(a[0], out)
    return len(out)


# ---- dialogs, controls, menus ------------------------------------------------------------------------------------
@u("MessageBoxA", 4)
def message_box(m, a):
    m.log(f"   MessageBox: {m.cstr(a[2]).decode('latin-1')!r}: {m.cstr(a[1]).decode('latin-1')!r} -> IDOK")
    m.state.setdefault("messageboxes", []).append((m.cstr(a[2]).decode("latin-1"), m.cstr(a[1]).decode("latin-1")))
    return 1


@u("DialogBoxParamA", 5)
def dialog_box(m, a):
    m.log(f"   DialogBoxParam(template={a[1] if a[1] < 0x10000 else m.cstr(a[1])!r}, proc=0x{a[3]:08x}): "
          f"not shown, returns 0")
    return 0


u("EndDialog", 2)(lambda m, a: 1)
u("GetDlgItem", 2)(lambda m, a: 0)
u("SetDlgItemTextA", 3)(lambda m, a: 1)
u("GetDlgItemTextA", 4)(lambda m, a: 0)
u("GetDlgItemInt", 4)(lambda m, a: 0)
u("SetDlgItemInt", 4)(lambda m, a: 1)
u("CheckDlgButton", 3)(lambda m, a: 1)
u("IsDlgButtonChecked", 2)(lambda m, a: 0)
u("CheckRadioButton", 4)(lambda m, a: 1)
u("SetScrollRange", 5)(lambda m, a: 1)
u("SetScrollPos", 4)(lambda m, a: 0)
u("GetScrollPos", 2)(lambda m, a: 0)
u("GetScrollRange", 4)(lambda m, a: 1)
u("LoadBitmapA", 2)(lambda m, a: 0)
u("CreatePopupMenu", 0)(lambda m, a: new_obj(m, ("menu", [])))
u("AppendMenuA", 4)(lambda m, a: 1)
u("ModifyMenuA", 5)(lambda m, a: 1)
u("DeleteMenu", 3)(lambda m, a: 1)
u("RemoveMenu", 3)(lambda m, a: 1)
u("DestroyMenu", 1)(lambda m, a: 1)
u("GetMenuItemCount", 1)(lambda m, a: 0)
u("CheckMenuItem", 3)(lambda m, a: 0)
u("EnableMenuItem", 3)(lambda m, a: 0)
u("TrackPopupMenu", 7)(lambda m, a: 0)


# ---- host input injection ---------------------------------------------------------------------------------
WM_MOUSEMOVE, WM_LBUTTONDOWN, WM_LBUTTONUP, WM_RBUTTONDOWN, WM_RBUTTONUP = 0x200, 0x201, 0x202, 0x204, 0x205
WM_KEYDOWN, WM_KEYUP, WM_CHAR = 0x100, 0x101, 0x102


def main_hwnd(m):
    st = _st(m)
    for h, w in st["windows"].items():
        if w["visible"] and not w["style"] & WS_CHILD and w["proc"] and h != st.get("desktop_hwnd"):
            return h
    return 0


def inject_mouse(m, kind, x, y):
    """kind: move | down | up | rdown | rup. Coordinates are client pixels of the main window."""
    st = _st(m)
    h = main_hwnd(m)
    if not h:
        return False
    st["cursor"] = (x, y)
    msg = {"move": WM_MOUSEMOVE, "down": WM_LBUTTONDOWN, "up": WM_LBUTTONUP, "rdown": WM_RBUTTONDOWN,
           "rup": WM_RBUTTONUP}[kind]
    keys = 1 if kind in ("down",) else 0
    st["keys"][1] = kind == "down" or (kind == "move" and st["keys"].get(1, False))
    st["queue"].append((h, msg, keys, (y << 16) | (x & 0xFFFF)))
    return True


def inject_key(m, vk, char=None):
    st = _st(m)
    h = main_hwnd(m)
    if not h:
        return False
    st["queue"].append((h, WM_KEYDOWN, vk, 1))
    if char is not None:
        st["queue"].append((h, WM_CHAR, char, 1))
    st["queue"].append((h, WM_KEYUP, vk, 0xC0000001))
    return True
