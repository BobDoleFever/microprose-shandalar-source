"""
A live window for the emulated game: `python3 -m winemu.run --live`.

The emulator runs on a worker thread and the window (pygame / SDL) on the main thread, as SDL requires. The two meet at
two places only (and the window thread never calls into Unicorn):
  - input: the window's thread puts events in a queue; the emulator's thread turns them into the game's messages
    (user32.inject_mouse / inject_key) between scheduling slices, so the guest's state is only ever touched by one thread;
  - output: the emulator's thread composes the screen (run.compose) up to 30 times a second and hands over the latest frame.
A slice is short (SLICE instructions), so input is served and the frame refreshed many times a second even while the game thread spins.

Time. The guest sees only the virtual clock (machine.py). Live, that clock is the real one (`Pacer`): it never runs behind
what the host's clock says, and when every thread is waiting the jump to the next deadline is slept out in real time, so
animations and timers run at the speed the game was made for however fast or slow the host is.
"""
import os
import queue
import threading
import time

# Keys as the game's keyboard code sees them: name (pygame.key.name) -> (virtual-key code, scan code). The game turns a
# WM_KEYDOWN's scan code into a character itself and reads Shift, Ctrl, Alt and Caps Lock from GetAsyncKeyState, so those
# are real key events too.
KEYS = {"escape": (27, 0x01), "backspace": (8, 0x0E), "tab": (9, 0x0F), "return": (13, 0x1C), "enter": (13, 0x1C),
        "left ctrl": (0x11, 0x1D), "right ctrl": (0x11, 0x1D), "left shift": (0x10, 0x2A), "right shift": (0x10, 0x36),
        "left alt": (0x12, 0x38), "right alt": (0x12, 0x38), "space": (32, 0x39), "caps lock": (0x14, 0x3A),
        "home": (0x24, 0x47), "up": (38, 0x48), "page up": (0x21, 0x49), "left": (37, 0x4B), "right": (39, 0x4D),
        "end": (0x23, 0x4F), "down": (40, 0x50), "page down": (0x22, 0x51), "insert": (0x2D, 0x52), "delete": (46, 0x53),
        "-": (0xBD, 0x0C), "=": (0xBB, 0x0D), "[": (0xDB, 0x1A), "]": (0xDD, 0x1B), ";": (0xBA, 0x27), "'": (0xDE, 0x28),
        "`": (0xC0, 0x29), "\\": (0xDC, 0x2B), ",": (0xBC, 0x33), ".": (0xBE, 0x34), "/": (0xBF, 0x35)}
for _i, _c in enumerate("1234567890"):
    KEYS[_c] = (ord(_c), 0x02 + _i)
for _i, _c in enumerate("qwertyuiop"):
    KEYS[_c] = (ord(_c.upper()), 0x10 + _i)
for _i, _c in enumerate("asdfghjkl"):
    KEYS[_c] = (ord(_c.upper()), 0x1E + _i)
for _i, _c in enumerate("zxcvbnm"):
    KEYS[_c] = (ord(_c.upper()), 0x2C + _i)
for _i in range(1, 11):
    KEYS[f"f{_i}"] = (0x6F + _i, 0x3A + _i)
KEYS["f11"], KEYS["f12"] = (0x7A, 0x57), (0x7B, 0x58)


def key_info(name, unicode_char=""):
    """(vk, scan code, char) for a pygame key name and the character it typed; None for a key the game does not get.
    `char` is what WM_CHAR carries, None for a key that types nothing."""
    k = KEYS.get(name)
    if k is None:
        return None
    ch = {"return": 13, "enter": 13, "backspace": 8, "tab": 9, "escape": 27}.get(name)
    if ch is None and unicode_char and len(unicode_char) == 1 and 32 <= ord(unicode_char) < 127:
        ch = ord(unicode_char)
    return k[0], k[1], ch


class Pacer:
    """Maps virtual time to real time. `wait(target)` returns the virtual time to continue from: `target` once the real
    clock has reached it, sooner if `interrupt()` says something happened meanwhile."""

    def __init__(self, speed=1.0, clock=time.monotonic, sleep=time.sleep, step=0.004):
        self.speed, self.clock, self.sleep, self.step = speed, clock, sleep, step
        self.real0 = None
        self.vt0 = 0.0

    def now_vt(self):
        now = self.clock()
        if self.real0 is None:
            self.real0, self.vt0 = now, 0.0
        return self.real_to_vt(now)

    def real_to_vt(self, now):
        return self.vt0 + (now - self.real0) * self.speed

    def wait(self, vt_now, target, interrupt=lambda: False):
        now = self.clock()
        if self.real0 is None:
            self.real0, self.vt0 = now, vt_now
        behind = self.real_to_vt(now) - vt_now
        if behind > 0.05:                                        # slower than real time: forget the lag, do not race ahead
            self.real0, self.vt0 = now, vt_now
        while True:
            now = self.clock()
            reach = self.real_to_vt(now)
            if reach >= target:
                return target
            if interrupt():
                return max(vt_now, min(target, reach))
            self.sleep(max(0.0001, min(self.step, (target - reach) / self.speed)))


class Live:
    def __init__(self, fps=30, speed=1.0, title="Magic: The Gathering"):
        self.events = queue.SimpleQueue()
        self.frame = None                                        # latest composed frame (numpy RGB), set by the emulator thread
        self.frame_n = 0
        self.lock = threading.Lock()
        self.closed = False
        self.fps, self.title = fps, title
        self.pacer = Pacer(speed)
        self.compose = None
        self.next_frame = 0.0
        self.machine = None

    # ---- emulator thread ---------------------------------------------------------------------------
    def attach(self, m, compose):
        """Hook into the machine: service input and output each time it schedules, pace its idle clock jumps."""
        from . import user32  # noqa: PLC0415
        self.machine, self.compose, self.user32 = m, compose, user32
        m.state["pace"] = lambda mm, target: self.pacer.wait(mm.vt, target, lambda: self._service(mm))
        # The guest's clock is the real one (never less than what its instructions cost, never backwards): the game
        # thread busy-waits through whole 200M-instruction slices, and its timers must still run at the right rate.
        m.state["clock"] = lambda mm, before: max(before, self.pacer.now_vt())
        m.state["should_stop"] = lambda mm: self.closed
        m.slice = self.SLICE
        m.state["hard_stop"] = None
        m.state["virtual_limit"] = None

    def on_schedule(self, m):
        self._service(m)

    def _service(self, m):
        """Deliver queued input to the game and publish a new frame if one is due. True if input was delivered."""
        got = False
        while True:
            try:
                ev = self.events.get_nowait()
            except queue.Empty:
                break
            got = True
            if ev[0] == "mouse":
                self.user32.inject_mouse(m, ev[1], ev[2], ev[3])
            elif ev[0] == "key":
                self.user32.inject_key_event(m, *ev[1:])
        now = time.monotonic()
        if now >= self.next_frame:
            self.next_frame = now + 1.0 / self.fps
            frame = self.compose(m)
            with self.lock:
                self.frame, self.frame_n = frame, self.frame_n + 1
        return got

    # ---- window thread -----------------------------------------------------------------------------
    def run(self, m):
        """Run the machine on a worker thread and the window here until either ends. Returns the machine's exit code."""
        import pygame  # noqa: PLC0415
        result = {}

        def work():
            try:
                result["code"] = m.run()
            except BaseException as e:                           # noqa: BLE001  (shown after the window closes)
                result["error"] = e
            finally:
                result["done"] = True

        pygame.init()
        pygame.key.set_repeat(400, 40)
        screen = pygame.display.set_mode((640, 480), pygame.SCALED | pygame.RESIZABLE)
        pygame.display.set_caption(self.title)
        clock = pygame.time.Clock()
        worker = threading.Thread(target=work, name="emulator", daemon=True)
        worker.start()
        shown = 0
        held, repeating = {}, set()                               # keys down: what each sent, and which have already repeated
        while not self.closed and not result.get("done"):
            for ev in pygame.event.get():
                if ev.type == pygame.QUIT:
                    self._close(m)
                elif ev.type == pygame.MOUSEMOTION:
                    self.events.put(("mouse", "move", ev.pos[0], ev.pos[1]))
                elif ev.type in (pygame.MOUSEBUTTONDOWN, pygame.MOUSEBUTTONUP) and ev.button in (1, 3):
                    kind = ("down" if ev.button == 1 else "rdown") if ev.type == pygame.MOUSEBUTTONDOWN \
                        else ("up" if ev.button == 1 else "rup")
                    self.events.put(("mouse", kind, ev.pos[0], ev.pos[1]))
                elif ev.type == pygame.WINDOWFOCUSLOST:                  # keys let go while elsewhere would stay down
                    for key, (vk, sc, _) in held.items():
                        self.events.put(("key", vk, sc, False, None, False))
                    held.clear()
                    repeating.clear()
                elif ev.type in (pygame.KEYDOWN, pygame.KEYUP):
                    info = key_info(pygame.key.name(ev.key), getattr(ev, "unicode", ""))
                    if ev.type == pygame.KEYDOWN and info:
                        held[ev.key] = info
                    elif ev.type == pygame.KEYUP:
                        info = held.pop(ev.key, info)
                    if info:
                        vk, sc, ch = info
                        self.events.put(("key", vk, sc, ev.type == pygame.KEYDOWN, ch if ev.type == pygame.KEYDOWN else None,
                                         ev.type == pygame.KEYDOWN and ev.key in repeating))
                        repeating.add(ev.key) if ev.type == pygame.KEYDOWN else repeating.discard(ev.key)
            with self.lock:
                frame, n = self.frame, self.frame_n
            if frame is not None and n != shown:
                shown = n
                surf = pygame.image.frombuffer(frame.tobytes(), (frame.shape[1], frame.shape[0]), "RGB")
                screen.blit(surf, (0, 0))
                pygame.display.flip()
            clock.tick(120)
        if not result.get("done"):
            self._close(m)
            worker.join(5)
        pygame.quit()
        if "error" in result:
            raise result["error"]
        return result.get("code", 0)

    # Instructions a thread runs before the others (and the window) get their turn. The game's own thread busy-waits, so
    # without this the window would wait for the 200M-instruction slice of the exact runs (some twenty seconds of host time).
    # The emulator is only ever stopped by running out of instructions: Unicorn's stop-from-another-thread is not atomic.
    SLICE = int(os.environ.get("LIVE_SLICE", "200000"))

    def _close(self, m):
        """The window was closed: the game's next GetMessage sees WM_QUIT; a slice in progress is cut short."""
        self.closed = True
        m.stop = True
