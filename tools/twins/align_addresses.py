#!/usr/bin/env python3
"""
align_addresses.py - the addresses a function uses in one program and the ones its twin uses in the other.

DUEL.EXE and MAGIC.EXE carry the same engine at different addresses (tools/twins/twins.csv). A function and its twin are
compiled from the same source, so their instructions line up one for one and differ only in the absolute addresses (globals,
callees, tables). This disassembles both and prints, for each absolute operand, the address in each program, so a native
function can be given both programs' layouts without reading two decompilations side by side. It stops at the first place the
two instruction streams stop agreeing.

    python3 tools/twins/align_addresses.py 0x0042fea9 0x004aaaea       # DUEL address, MAGIC address
"""
import argparse
import os
import sys

import capstone
import pefile
from capstone import x86 as X

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
EXES = {"DUEL": "DUEL.EXE", "MAGIC": "MAGIC.EXE"}


class Image:
    def __init__(self, name):
        path = os.path.join(ROOT, "sources", "installed", "Magic", "Program", EXES[name])
        self.pe = pefile.PE(path)
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self.md.detail = True

    def code(self, va, n):
        return self.pe.get_data(va - self.base, n)

    def function(self, va, limit=0x2000):
        """Instructions from va to the first `ret` that is not followed by more of the function (a linear sweep that follows
        forward jumps: enough for the straight-line and loop code of these functions)."""
        out, farthest = [], va
        for i in self.md.disasm(self.code(va, limit), va):
            out.append(i)
            if i.mnemonic in ("jmp",) or i.mnemonic.startswith("j"):
                if i.operands and i.operands[0].type == X.X86_OP_IMM:
                    farthest = max(farthest, i.operands[0].imm)
            if i.mnemonic == "ret" and i.address >= farthest:
                break
        return out


def operands(i):
    """The absolute addresses an instruction mentions: immediates and displacements that look like addresses, calls, jumps."""
    found = []
    for k, op in enumerate(i.operands):
        if op.type == X.X86_OP_IMM and op.imm >= 0x400000:
            found.append((k, "imm", op.imm & 0xffffffff))
        elif op.type == X.X86_OP_MEM and (op.mem.disp & 0xffffffff) >= 0x400000 and not (op.mem.base and i.reg_name(op.mem.base) in ("ebp", "esp")):
            found.append((k, "mem", op.mem.disp & 0xffffffff))
    return found


def align(a_va, b_va):
    ia, ib = Image("DUEL").function(a_va), Image("MAGIC").function(b_va)
    pairs, calls, where = {}, {}, None
    for n, (x, y) in enumerate(zip(ia, ib)):
        if x.mnemonic != y.mnemonic or len(x.operands) != len(y.operands):
            where = (n, x, y)
            break
        for (k, kind, va), (_, _, vb) in zip(operands(x), operands(y)):
            if x.mnemonic == "call":
                calls.setdefault(va, set()).add(vb)
            elif x.mnemonic == "jmp" or x.mnemonic.startswith("j"):
                continue   # code addresses inside the function are not what is wanted
            else:
                pairs.setdefault(va, set()).add(vb)
        # `call imm` is not an "absolute operand" above (operands() skips immediates of calls through the address filter only for
        # data); a direct call's target is an immediate too
        if x.mnemonic == "call" and x.operands and x.operands[0].type == X.X86_OP_IMM and y.operands[0].type == X.X86_OP_IMM:
            calls.setdefault(x.operands[0].imm & 0xffffffff, set()).add(y.operands[0].imm & 0xffffffff)
    return ia, ib, pairs, calls, where


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("duel", type=lambda s: int(s, 0))
    ap.add_argument("magic", type=lambda s: int(s, 0))
    args = ap.parse_args()
    ia, ib, pairs, calls, where = align(args.duel, args.magic)
    print(f"{len(ia)} and {len(ib)} instructions")
    if where:
        print(f"the streams part at instruction {where[0]}: DUEL {where[1].address:x} {where[1].mnemonic} {where[1].op_str} / MAGIC {where[2].address:x} {where[2].mnemonic} {where[2].op_str}")
    for va in sorted(pairs):
        print(f"0x{va:08x} -> " + ", ".join(f"0x{v:08x}" for v in sorted(pairs[va])))
    print("calls:")
    for va in sorted(calls):
        print(f"0x{va:08x} -> " + ", ".join(f"0x{v:08x}" for v in sorted(calls[va])))


if __name__ == "__main__":
    sys.exit(main())
