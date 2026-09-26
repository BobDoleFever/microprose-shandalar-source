#!/usr/bin/env python3
"""
Second oracle experiment: what runs when a duel starts?

With the game sitting on the "Duel a <wizard>" screen and the pointer over the Duel choice
(see oracle_ctl.py), attach the debugger, click, and record which of these fire:

  * Magic_DrawCardPhase   MAGIC.EXE 0x00474c7f  (decomp label: the draw step)
  * DUEL.EXE entry point  0x004dea30            (proves duels run in a separate process)

Every program loads at 0x00400000, so a hit only counts if the code bytes at the address are
the ones from the matching file in sources/installed (`code_matches`).

    python3 probe_duel_start.py <qmp.sock> [seconds]
"""
import json
import os
import socket
import struct
import sys
import time

from oracle_qemu import QMP, GDBRemote

PROGRAM = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..",
                       "sources", "installed", "Magic", "Program")


def code_bytes(exe, va, n=8):
    """Bytes at virtual address `va` as stored in the PE file on disk."""
    d = open(os.path.join(PROGRAM, exe), "rb").read()
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    nsec, optsz = struct.unpack_from("<H", d, pe + 6)[0], struct.unpack_from("<H", d, pe + 20)[0]
    base = struct.unpack_from("<I", d, pe + 24 + 28)[0]
    for i in range(nsec):
        o = pe + 24 + optsz + i * 40
        vsz, rva, rsz, roff = struct.unpack_from("<IIII", d, o + 8)
        if base + rva <= va < base + rva + max(vsz, rsz):
            return d[roff + (va - base - rva):][:n]
    raise ValueError(hex(va))


TARGETS = {
    0x00474C7F: ("MAGIC.EXE", "Magic_DrawCardPhase"),
    0x004DEA30: ("DUEL.EXE", "DUEL.EXE entry point"),
}


def main():
    budget = float(sys.argv[2]) if len(sys.argv) > 2 else 120
    qmp = QMP(sys.argv[1])
    gdb = GDBRemote()
    expected = {va: code_bytes(exe, va) for va, (exe, _) in TARGETS.items()}
    for va in TARGETS:
        gdb.set_breakpoint(va)
    gdb.cont()
    qmp.click()                     # pointer is already over "Duel a ..."
    t0 = time.time()
    events = []
    while time.time() - t0 < budget:
        try:
            gdb.wait_stop(timeout=2)
        except socket.timeout:
            continue
        regs = gdb.read_registers()
        va = regs["eip"]
        if va in TARGETS:
            exe, label = TARGETS[va]
            try:
                matches = gdb.read_memory(va, 8) == expected[va]
            except IOError:                # page not resident yet (demand paging); the retry
                matches = None             # after resume() will hit again with readable code
            ev = {"t": round(time.time() - t0, 1), "label": label, "eip": f"0x{va:08x}",
                  "code_matches": matches, "matches_exe": exe}
            events.append(ev)
            print(json.dumps(ev), flush=True)
        gdb.resume(set(TARGETS))
        if len(events) >= 20:
            break
    with open("probe_duel_start.json", "w") as f:
        json.dump(events, f, indent=2)
    qmp.screendump(os.path.abspath("probe_duel_start.png"))
    print("done:", len(events), "events", flush=True)


if __name__ == "__main__":
    main()
