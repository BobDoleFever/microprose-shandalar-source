"""
native_host.py - host the native layer (src/native, built as a shared library by `make -C tools/difftest host`) inside the
emulator, so that the original program runs with some of its functions replaced by native C.

For every native function and, when the library was built with the generated handlers (tools/lift), every lifted card
handler, an intercept is put on the original's entry address (Machine.add_intercept). When the guest reaches it, the
function runs natively instead: its arguments are read off the guest's stack, it reads and writes the guest's memory
through callbacks (the native code addresses memory by the original's own addresses), and its result goes back in EAX.

Native code is plain C that calls the guest's functions that are not native yet by calling a callback. A callback cannot run
guest code from inside the emulator's hook, so a native call runs on its own thread and hands control back and forth
(NativeCall): when the C code calls out, the thread waits and the machine runs the guest function (a Cont, as an import
handler does), then wakes the thread with the result. Only one of the two runs at any moment, so nothing needs locking.
"""
import ctypes
import os
import queue
import sys
import threading
import time

from unicorn import UcError
from unicorn.x86_const import UC_X86_REG_EAX

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(HERE)))
DEFAULT_LIB = os.path.join(ROOT, "tools", "difftest", "build", "libnative_host.dylib")

RD = ctypes.CFUNCTYPE(ctypes.c_uint32, ctypes.c_void_p, ctypes.c_uint32, ctypes.c_int)
WR = ctypes.CFUNCTYPE(None, ctypes.c_void_p, ctypes.c_uint32, ctypes.c_int, ctypes.c_uint32)
CALL = ctypes.CFUNCTYPE(ctypes.c_uint32, ctypes.c_uint32, ctypes.c_int, ctypes.POINTER(ctypes.c_uint32), ctypes.c_uint32)

_current = threading.local()


class Worker(threading.Thread):
    """A thread that runs native calls one at a time. A call that is waiting for the guest keeps its worker, so a call made
    meanwhile (the guest function ran a native one) gets another."""

    def __init__(self, pool):
        super().__init__(daemon=True)
        self.pool, self.jobs = pool, queue.SimpleQueue()
        self.start()

    def run(self):
        while True:
            call, run = self.jobs.get()
            _current.call = call
            try:
                call.req.put(("done", run()))
            except BaseException as e:  # noqa: BLE001 - handed to the machine's thread
                call.req.put(("error", e))
            self.pool.append(self)


class NativeCall:
    """A native function running on a worker thread, which stops whenever it calls out to the guest."""
    pool = []

    def __init__(self, run):
        self.req, self.resp = queue.SimpleQueue(), queue.SimpleQueue()
        self.run = run

    def start(self):
        worker = self.pool.pop() if self.pool else Worker(self.pool)
        worker.jobs.put((self, self.run))
        return self.req.get()

    def resume(self, value):
        self.resp.put(value)
        return self.req.get()


class NativeHost:
    def __init__(self, machine, lib_path=None):
        self.m = machine
        path = lib_path or os.environ.get("NATIVE_LIB") or DEFAULT_LIB
        if not os.path.exists(path):
            sys.exit(f"native library not found: {path} (make -C tools/difftest host)")
        self.lib = ctypes.CDLL(path)
        lib = self.lib
        lib.host_init.argtypes = [ctypes.c_char_p, RD, WR, CALL]
        lib.host_native_count.restype = ctypes.c_int
        lib.host_native_name.restype = ctypes.c_char_p
        lib.host_native_name.argtypes = [ctypes.c_int]
        lib.host_native_entry.restype = ctypes.c_uint32
        lib.host_native_entry.argtypes = [ctypes.c_int]
        lib.host_native_nargs.argtypes = [ctypes.c_int]
        lib.host_native_ret_bits.argtypes = [ctypes.c_int]
        lib.host_native_run.restype = ctypes.c_uint32
        lib.host_native_run.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_uint32), ctypes.c_uint32]
        lib.host_lifted_count.restype = ctypes.c_int
        lib.host_lifted_entry.restype = ctypes.c_uint32
        lib.host_lifted_entry.argtypes = [ctypes.c_int]
        lib.host_lifted_name.restype = ctypes.c_char_p
        lib.host_lifted_name.argtypes = [ctypes.c_int]
        lib.host_lifted_run.restype = ctypes.c_uint32
        lib.host_lifted_run.argtypes = [ctypes.c_uint32, ctypes.c_uint32]
        lib.host_native_try.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_uint32), ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32)]
        lib.host_lifted_try.argtypes = [ctypes.c_uint32, ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32)]
        self.escalated = {}   # name -> calls that had to be run again with a thread
        self.seconds = {"try": 0.0, "thread": 0.0}   # host time spent in each way of running a call (for tuning)
        self.faults = 0
        self.runs = {}   # name -> times run natively

        def read(ctx, addr, size):
            try:
                return int.from_bytes(self.m.uc.mem_read(addr, size), "little")
            except UcError:
                self.faults += 1
                return 0

        def write(ctx, addr, size, value):
            try:
                self.m.uc.mem_write(addr, (value & ((1 << (8 * size)) - 1)).to_bytes(size, "little"))
            except UcError:
                self.faults += 1

        def call(addr, nargs, args, sp):
            c = _current.call
            c.req.put(("call", addr, [args[i] for i in range(nargs)], sp))
            return c.resp.get()

        self._cb = (RD(read), WR(write), CALL(call))   # keep the callbacks alive
        if lib.host_init(b"DUEL", *self._cb) != 0:
            sys.exit("native_host: host_init failed")
        lib.host_add_region.argtypes = [ctypes.c_uint32, ctypes.c_uint32, ctypes.c_void_p]
        for base, size, host, _buf in self.m.regions:   # the guest's memory is host memory: no callback per access
            lib.host_add_region(base, size, host)

    # ---- what the original functions look like -----------------------------------------------------------------
    def _cleanup(self, entry):
        """Bytes the original function pops when it returns (`ret imm16`): 0 for a cdecl function."""
        sys.path.insert(0, os.path.join(ROOT, "tools", "lift"))
        from x86lift import Lifter, Unsupported  # noqa: PLC0415

        def getbytes(va, n):
            return bytes(self.m.uc.mem_read(va, min(n, 0x2000)))
        try:
            return Lifter().ret_cleanup(getbytes, entry, frozenset())
        except Unsupported:
            return 0

    def _run_in_thread(self, run):
        """A generator for Machine.add_intercept: run `run()` (a call into the library) with guest calls serviced."""
        call = NativeCall(run)
        msg = call.start()
        while msg[0] == "call":
            r = yield self.m.call_guest(msg[1], msg[2], sp=msg[3])
            msg = call.resume(r)
        if msg[0] == "error":
            raise msg[1]
        return msg[1]

    def _native(self, fid, name, nargs, bits):
        lib = self.lib

        def handler(m, esp):
            args = [m.r32(esp + 4 + 4 * i) for i in range(nargs)]
            arr = (ctypes.c_uint32 * max(nargs, 1))(*args)
            self.runs[name] = self.runs.get(name, 0) + 1
            out = ctypes.c_uint32()
            t0 = time.perf_counter()
            done = lib.host_native_try(fid, arr, esp, ctypes.byref(out)) == 0
            self.seconds["try"] += time.perf_counter() - t0
            if done:
                ret = out.value
            else:   # it needs the guest: put back what it wrote and run it again where it can wait for it
                self.escalated[name] = self.escalated.get(name, 0) + 1
                t0 = time.perf_counter()
                ret = yield from self._run_in_thread(lambda: lib.host_native_run(fid, arr, esp))
                self.seconds["thread"] += time.perf_counter() - t0
            if bits == 0:
                return m.uc.reg_read(UC_X86_REG_EAX)   # a void function: EAX is whatever it was
            return ret & 0xFF if bits == 8 else ret
        return handler

    def _lifted(self, entry, name):
        lib = self.lib

        def handler(m, esp):
            self.runs[name] = self.runs.get(name, 0) + 1
            out = ctypes.c_uint32()
            if lib.host_lifted_try(entry, esp, ctypes.byref(out)) == 0:
                return out.value
            self.escalated[name] = self.escalated.get(name, 0) + 1
            return (yield from self._run_in_thread(lambda: lib.host_lifted_run(entry, esp)))
        return handler

    def install(self, only=None, skip=(), handlers=True):
        """Intercept the original's native functions (and lifted handlers). `only` (a set of names) restricts it."""
        count = 0
        for fid in range(self.lib.host_native_count()):
            name = self.lib.host_native_name(fid).decode()
            if (only is not None and name not in only) or name in skip:
                continue
            entry = self.lib.host_native_entry(fid)
            self.m.add_intercept(entry, self._native(fid, name, self.lib.host_native_nargs(fid),
                                                    self.lib.host_native_ret_bits(fid)), self._cleanup(entry))
            count += 1
        if handlers:
            for i in range(self.lib.host_lifted_count()):
                name = self.lib.host_lifted_name(i).decode()
                if (only is not None and name not in only) or name in skip:
                    continue
                entry = self.lib.host_lifted_entry(i)
                self.m.add_intercept(entry, self._lifted(entry, name), self._cleanup(entry))
                count += 1
        return count
