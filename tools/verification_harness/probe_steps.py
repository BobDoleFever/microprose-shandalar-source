#!/usr/bin/env python3
"""
Live check of Magic_RunTurnStep (MAGIC.EXE 0x0047624f) and g_CurrentStepCode (0x006ff4c0).

Static analysis says: Magic_RunTurnStep(player, step_code, step_name, wait_for_pass) sets
g_CurrentStepCode to step_code, runs the step, and sets it back to -1. This probe records, on
the live game,
  * every entry of Magic_RunTurnStep: its four stack arguments, and the step name string;
  * every write to g_CurrentStepCode: the value now in memory and the function that wrote it.

Attach once a duel is on screen (watchpoints on hot pages can make the guest stop taking clicks
if they are armed earlier), then click Done to step through turns.

    python3 probe_steps.py [seconds] [max_events]      -> probe_steps.json
"""
import csv
import json
import os
import socket
import struct
import sys
import time

from oracle_qemu import GDBRemote

HERE = os.path.dirname(os.path.abspath(__file__))
RUN_STEP = 0x0047624F
STEP_CODE = 0x006FF4C0
PROGRAM = os.path.join(HERE, "..", "..", "sources", "installed", "Magic", "Program", "MAGIC.EXE")


def file_bytes(va, n=8):
    d = open(PROGRAM, "rb").read()
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    nsec, optsz = struct.unpack_from("<H", d, pe + 6)[0], struct.unpack_from("<H", d, pe + 20)[0]
    base = struct.unpack_from("<I", d, pe + 24 + 28)[0]
    for i in range(nsec):
        o = pe + 24 + optsz + i * 40
        vsz, rva, rsz, roff = struct.unpack_from("<IIII", d, o + 8)
        if base + rva <= va < base + rva + max(vsz, rsz):
            return d[roff + (va - base - rva):][:n]
    raise ValueError(hex(va))


def functions():
    fns = []
    for r in csv.reader(open(os.path.join(HERE, "..", "..", "magic", "function_index.csv"))):
        try:
            fns.append((int(r[0], 16), r[1]))
        except ValueError:
            pass
    return sorted(fns)


def owner(fns, va):
    best = None
    for a, n in fns:
        if a <= va:
            best = (a, n)
        else:
            break
    return best


def u32(gdb, addr):
    return struct.unpack("<I", gdb.read_memory(addr, 4))[0]


def main():
    budget = float(sys.argv[1]) if len(sys.argv) > 1 else 900
    max_events = int(sys.argv[2]) if len(sys.argv) > 2 else 60
    fns = functions()
    want = file_bytes(RUN_STEP)
    gdb = GDBRemote()
    gdb.set_breakpoint(RUN_STEP)
    gdb.set_watchpoint(STEP_CODE)
    print(f"[{time.strftime('%X')}] armed: breakpoint {RUN_STEP:#x}, write watchpoint {STEP_CODE:#x}", flush=True)
    gdb.cont()

    events, t0 = [], time.time()
    while time.time() - t0 < budget and len(events) < max_events:
        try:
            stop = gdb.wait_stop(timeout=2)
        except socket.timeout:
            continue
        regs = gdb.read_registers()
        t = round(time.time() - t0, 1)
        watched = GDBRemote.watch_address(stop)
        if watched == STEP_CODE:
            gdb.step()                                    # let the write complete
            ev = {"t": t, "kind": "write g_CurrentStepCode", "value": u32(gdb, STEP_CODE),
                  "written_by": (owner(fns, regs["eip"]) or ("?", "?"))[1],
                  "eip": f"0x{regs['eip']:08x}"}
        elif regs["eip"] == RUN_STEP:
            try:
                ok = gdb.read_memory(RUN_STEP, 8) == want
            except IOError:                               # code page not resident yet
                ok = None
            esp = regs["esp"]
            try:
                player, code, name_ptr, wait = [u32(gdb, esp + 4 + 4 * i) for i in range(4)]
                name = gdb.read_cstring(name_ptr).decode("latin-1") if name_ptr else None
            except IOError:
                player = code = wait = name = None
            ev = {"t": t, "kind": "enter Magic_RunTurnStep", "code_matches": ok,
                  "player": player, "step_code": None if code is None else f"0x{code:x}",
                  "step_name": name, "wait_for_pass": wait,
                  "step_code_before": u32(gdb, STEP_CODE) if ok is not None else None,
                  "called_from": f"0x{u32(gdb, esp):08x}"}
        else:
            ev = {"t": t, "kind": f"other stop {stop!r}"}
        events.append(ev)
        print(json.dumps(ev), flush=True)
        gdb.resume({RUN_STEP})

    for fn in (lambda: gdb.clear_breakpoint(RUN_STEP), lambda: gdb.clear_watchpoint(STEP_CODE), gdb.cont):
        try:
            fn()
        except Exception:
            pass
    json.dump(events, open("probe_steps.json", "w"), indent=2)
    print("done:", len(events), "events", flush=True)


if __name__ == "__main__":
    main()
