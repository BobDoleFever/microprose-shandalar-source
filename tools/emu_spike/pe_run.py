#!/usr/bin/env python3
"""
Feasibility spike: can the original MAGIC.EXE run inside a CPU emulator on this machine, with its
imported Win32 / C-runtime functions supplied by us?

Loads the PE at its preferred base (0x00400000), points every import at a trap address, runs the
entry point under Unicorn (x86-32 user mode), and logs each import the program calls. Imports are
answered by a small table (stdcall argument counts, return values); when the program calls one that
is not in the table the run stops and says which, so the table can be grown one import at a time.

    python3 pe_run.py [path-to-MAGIC.EXE] [max_calls]

Needs `pip install unicorn pefile`. The game files are your own (see docs/ORACLE_VM.md); nothing here
ships them.
"""
import itertools
import json
import os
import re
import struct
import sys

import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, UcError
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_FS,
                               UC_X86_REG_GDTR, UC_X86_REG_DS, UC_X86_REG_ES, UC_X86_REG_SS,
                               UC_X86_REG_CS)

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_EXE = os.path.join(HERE, "..", "..", "sources", "installed", "Magic", "Program", "MAGIC.EXE")
STUB_BASE = 0x70000000
STACK_TOP = 0x00200000
STACK_SIZE = 0x00100000
TEB = 0x7FFDE000
PEB = 0x7FFDF000
HEAP = 0x10000000

# name -> (stdcall argument count, return value). CRT (msvcrtd.dll) imports are cdecl: nothing popped.
STDCALL = {
    "GetVersion": (0, 0x0A280105),                     # Windows 98 SE: 4.10.2222
    "GetCommandLineA": (0, None),                      # filled in below
    "GetModuleHandleA": (1, 0x00400000),
    "GetStartupInfoA": (1, 0),
    "GetCurrentThreadId": (0, 1),
    "GetLastError": (0, 0),
    "SetLastError": (1, 0),
}


GDT = 0x7FFD0000


def gdt_entry(base, limit, access, flags):
    return struct.pack("<HHBBBB", limit & 0xFFFF, base & 0xFFFF, (base >> 16) & 0xFF, access,
                       ((flags & 0xF) << 4) | ((limit >> 16) & 0xF), (base >> 24) & 0xFF)


def set_fs(uc, teb):
    """Point FS at the thread block. Unicorn 2 has no usable FS_BASE register, so build a tiny GDT."""
    uc.mem_map(GDT, 0x1000)
    uc.mem_write(GDT, gdt_entry(0, 0, 0, 0)                                  # 0x00 null
                 + gdt_entry(0, 0xFFFFF, 0x9B, 0xC)                          # 0x08 code
                 + gdt_entry(0, 0xFFFFF, 0x93, 0xC)                          # 0x10 data
                 + gdt_entry(teb, 0xFFF, 0x93, 0x4))                         # 0x18 FS: base = TEB
    uc.reg_write(UC_X86_REG_GDTR, (0, GDT, 0x1F, 0))
    uc.reg_write(UC_X86_REG_CS, 0x08)
    for r in (UC_X86_REG_DS, UC_X86_REG_ES, UC_X86_REG_SS):
        uc.reg_write(r, 0x10)
    uc.reg_write(UC_X86_REG_FS, 0x18)


class Heap:
    """Bump allocator inside the mapped HEAP block; enough for a spike (free is a no-op)."""
    def __init__(self, uc, start):
        self.uc, self.next = uc, start

    def alloc(self, n, fill=0):
        a = (self.next + 15) & ~15
        self.next = a + max(n, 4)
        return a

    def cstr(self, b):
        a = self.alloc(len(b) + 1)
        self.uc.mem_write(a, b + b"\0")
        return a


def crt_handlers(uc, heap):
    """msvcrtd.dll functions (cdecl). Each gets (args) and returns eax. Anything else returns 0."""
    w32 = lambda a, v: uc.mem_write(a, struct.pack("<I", v & 0xFFFFFFFF))
    cell = {n: heap.alloc(4) for n in ("fmode", "commode", "argc", "argv", "environ", "acmdln")}
    argv0 = heap.cstr(b"C:\\Magic\\Program\\MAGIC.EXE")
    argv = heap.alloc(8)
    w32(argv, argv0)
    w32(cell["argv"], argv)
    w32(cell["argc"], 1)
    w32(cell["acmdln"], argv0)
    w32(cell["environ"], heap.alloc(8))

    def getmainargs(a):
        w32(a[0], 1)
        w32(a[1], argv)
        w32(a[2], cell["environ"])
        return 0

    def rd(a, limit=4096):
        out = bytearray()
        while len(out) < limit:
            c = uc.mem_read(a + len(out), 1)[0]
            if c == 0:
                break
            out.append(c)
        return bytes(out)

    def wr(a, b):
        uc.mem_write(a, bytes(b) + b"\0")

    def strrchr(a):
        i = rd(a[0]).rfind(bytes([a[1] & 0xFF]))
        return 0 if i < 0 else a[0] + i

    def strchr(a):
        i = rd(a[0]).find(bytes([a[1] & 0xFF]))
        return 0 if i < 0 else a[0] + i

    def cmp(x, y):
        return (x > y) - (x < y)

    def fmt(a):                                     # sprintf(dst, fmt, ...): %d %u %x %s %c only
        f, args, out, i = rd(a[1]), a[2:], b"", 0
        j = 0
        while j < len(f):
            if f[j:j + 1] == b"%" and j + 1 < len(f):
                j += 1
                while chr(f[j]) in "0123456789.-+ l":
                    j += 1
                c = chr(f[j])
                v = args[i] if i < len(args) else 0
                i += 1
                out += {"d": str(struct.unpack("<i", struct.pack("<I", v))[0]).encode(), "u": str(v).encode(),
                        "x": b"%x" % v, "s": rd(v), "c": bytes([v & 0xFF]), "%": b"%"}.get(c, b"?")
                if c == "%":
                    i -= 1
            else:
                out += f[j:j + 1]
            j += 1
        wr(a[0], out)
        return len(out)

    rng = {"seed": 1}

    def rand(a):
        rng["seed"] = (rng["seed"] * 214013 + 2531011) & 0xFFFFFFFF   # the MSVC generator
        return (rng["seed"] >> 16) & 0x7FFF

    def srand(a):
        rng["seed"] = a[0]
        return 0

    return {
        "strcpy": lambda a: (wr(a[0], rd(a[1])), a[0])[1],
        "strcat": lambda a: (wr(a[0] + len(rd(a[0])), rd(a[1])), a[0])[1],
        "strlen": lambda a: len(rd(a[0])), "strrchr": strrchr, "strchr": strchr,
        "strcmp": lambda a: cmp(rd(a[0]), rd(a[1])) & 0xFFFFFFFF,
        "_stricmp": lambda a: cmp(rd(a[0]).lower(), rd(a[1]).lower()) & 0xFFFFFFFF,
        "strncpy": lambda a: (wr(a[0], rd(a[1])[:a[2]]), a[0])[1],
        "memcpy": lambda a: (uc.mem_write(a[0], bytes(uc.mem_read(a[1], a[2]))), a[0])[1],
        "memset": lambda a: (uc.mem_write(a[0], bytes([a[1] & 0xFF]) * a[2]), a[0])[1],
        "sprintf": fmt, "rand": rand, "srand": srand, "free": lambda a: 0,
        "atoi": lambda a: int(rd(a[0]).split()[0] or 0) & 0xFFFFFFFF if rd(a[0]).split() else 0,
        "__p__fmode": lambda a: cell["fmode"], "__p__commode": lambda a: cell["commode"],
        "__p___argc": lambda a: cell["argc"], "__p___argv": lambda a: cell["argv"],
        "__p__environ": lambda a: cell["environ"], "__p__acmdln": lambda a: cell["acmdln"],
        "__getmainargs": getmainargs,
        "malloc": lambda a: heap.alloc(a[0]), "calloc": lambda a: heap.alloc(a[0] * a[1]),
        "_malloc_dbg": lambda a: heap.alloc(a[0]),
    }


def load_argc():
    """Argument counts derived from the decompiled call sites (derive_argc.py), plus three with none."""
    table = json.load(open(os.path.join(HERE, "argc_magic.json")))
    table.update({"GetPrivateProfileStringA": 6, "SetWindowRgn": 3, "CreatePolygonRgn": 3})
    return table


def load(path):
    pe = pefile.PE(path)
    image = pe.get_memory_mapped_image()
    return pe, image


def main():
    path = sys.argv[1] if len(sys.argv) > 1 and not sys.argv[1].isdigit() else DEFAULT_EXE
    max_calls = int(sys.argv[-1]) if sys.argv[-1].isdigit() else 200
    pe, image = load(path)
    base = pe.OPTIONAL_HEADER.ImageBase
    size = (pe.OPTIONAL_HEADER.SizeOfImage + 0xFFF) & ~0xFFF
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(base, size)
    uc.mem_write(base, image)
    uc.mem_map(STACK_TOP - STACK_SIZE, STACK_SIZE)
    uc.mem_map(TEB, 0x2000)
    uc.mem_map(HEAP, 0x1000000)
    uc.mem_map(STUB_BASE, 0x10000)
    uc.mem_write(TEB + 0x18, struct.pack("<I", TEB))               # NT_TIB.Self
    uc.mem_write(TEB + 0x30, struct.pack("<I", PEB))               # PEB pointer
    set_fs(uc, TEB)
    cmdline = HEAP
    uc.mem_write(cmdline, b"MAGIC.EXE\0")
    STDCALL["GetCommandLineA"] = (0, cmdline)

    ARGC = load_argc()
    handles = itertools.count(0xC001)
    heap = Heap(uc, HEAP + 0x100)
    crt = crt_handlers(uc, heap)
    stubs = {}
    n = 0
    for entry in pe.DIRECTORY_ENTRY_IMPORT:
        dll = entry.dll.decode().lower()
        for imp in entry.imports:
            name = imp.name.decode() if imp.name else f"#{imp.ordinal}"
            addr = STUB_BASE + n * 16
            n += 1
            stubs[addr] = (dll, name)
            uc.mem_write(imp.address, struct.pack("<I", addr))       # the IAT slot
    print(f"{n} imports from {len(pe.DIRECTORY_ENTRY_IMPORT)} DLLs; entry point "
          f"0x{base + pe.OPTIONAL_HEADER.AddressOfEntryPoint:08x}")

    calls = []
    state = {"stop": None}

    def on_code(uc, address, size, user):
        if address not in stubs:
            return
        dll, name = stubs[address]
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret = struct.unpack("<I", uc.mem_read(esp, 4))[0]
        args = struct.unpack("<8I", uc.mem_read(esp + 4, 32))
        calls.append((dll, name, ret))
        cdecl = dll.startswith("msvcrt")
        if cdecl:
            argc, val = 0, crt[name](args) if name in crt else 0
        elif name in STDCALL:
            argc, val = STDCALL[name]
        elif name in ARGC:
            argc = ARGC[name]
            # Anything that makes or fetches an object "succeeds" with a fresh fake handle; the rest returns 0.
            val = next(handles) if re.match(r"(Create|Load|Register|GetStockObject|GetDC|GetDlgItem|FindResource|"
                                            r"GetModuleHandle|SelectObject|GetWindowDC|BeginPaint)", name) else 0
        else:
            state["stop"] = f"unhandled stdcall import {dll}!{name} (args {[hex(a) for a in args]})"
            uc.emu_stop()
            return
        shown = args[:2] if name == "_initterm" else args[:argc or 0]
        print(f"{len(calls):4d} {dll}!{name}({', '.join(hex(a) for a in shown)}) "
              f"<- 0x{ret:08x}{'  [cdecl, returns 0]' if cdecl else ''}")
        uc.reg_write(UC_X86_REG_EAX, val or 0)
        if cdecl:
            uc.reg_write(UC_X86_REG_ESP, esp + 4)
        else:
            uc.reg_write(UC_X86_REG_ESP, esp + 4 + 4 * argc)
        uc.reg_write(UC_X86_REG_EIP, ret)
        if len(calls) >= max_calls:
            state["stop"] = "call budget reached"
            uc.emu_stop()

    uc.hook_add(UC_HOOK_CODE, on_code, begin=STUB_BASE, end=STUB_BASE + 0x10000)
    uc.reg_write(UC_X86_REG_ESP, STACK_TOP - 0x100)
    uc.mem_write(STACK_TOP - 0x100, struct.pack("<I", 0xFFFF0000))   # return address of the entry point
    try:
        uc.emu_start(base + pe.OPTIONAL_HEADER.AddressOfEntryPoint, 0xFFFF0000, count=50_000_000)
    except UcError as e:
        print("emulation error:", e, "at eip", hex(uc.reg_read(UC_X86_REG_EIP)))
    print("stopped:", state["stop"] or "returned or hit the instruction limit")


if __name__ == "__main__":
    main()
