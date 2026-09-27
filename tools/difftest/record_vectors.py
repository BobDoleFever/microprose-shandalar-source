#!/usr/bin/env python3
"""
record_vectors.py - record difftest vectors from the original game running in tools/emu_spike's
emulator (this is the recorder docs/difftest's SPEC.md describes under "Recording vectors from the
original" and was previously "not implemented here").

For each sampled call of a native-implemented function it logs: the stack arguments, every byte the
function (or a callee) reads before writing it (memory_in), every byte it writes (memory_out,
exhaustive), the non-native calls it makes with their return value and writes (calls, replayed
verbatim by the harness), and its return value - one JSON file per call, in the format SPEC.md
defines. Calls are de-duplicated by a rough situation key (see `situation_key`) so a run yields a
few examples of each interesting case rather than thousands of near-identical ones.

Needs the user's own copy of the game (tools/emu_spike/README's sources/installed/...); nothing
recorded here is redistributed, only the numbers this script prints.

Usage:
    python3 record_vectors.py OUTDIR MAX_PER_SITUATION [emulator args...]

Example:
    python3 record_vectors.py tools/difftest/vectors/session1 2 \\
        --exe sources/installed/Magic/Program/DUEL.EXE --seconds 240 --script "..."

(--exe, --seconds and --script are tools/emu_spike/winemu/run.py's own options; see its --help and
docs/PORT_STRATEGY.md for a working script.)
"""
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))

S32 = lambda v: v - (1 << 32) if v & 0x80000000 else v  # noqa: E731


def load_layout(program):
    """Parse src/native/layout.c's LAYOUT_MAGIC/LAYOUT_DUEL, and engine.h's FN_*/CALLEE_* enum order,
    into {entry point address -> (native name, nargs)} and {callee address -> label}, so the
    recorder's tables cannot drift from what the native code actually calls (checked by
    test_difftest.py's test_record_vectors_tables_match_layout, which needs no emulator)."""
    layout_c = open(os.path.join(ROOT, "src", "native", "layout.c")).read()
    engine_h = open(os.path.join(ROOT, "src", "native", "engine.h")).read()
    m = re.search(r"const Layout LAYOUT_%s = \{(.*?)\n\};" % program, layout_c, re.S)
    block = m.group(1)

    def enum_order(typedef_name):
        # `[^{}]*` (not `.*?`) so this cannot skip past an earlier enum's own closing brace and swallow
        # two blocks into one match (there is more than one `typedef enum {` in this file).
        m = re.search(r"\{([^{}]*)\}\s*" + typedef_name + r";", engine_h, re.S)
        names = [ln.split(",")[0].split("/*")[0].strip() for ln in m.group(1).splitlines()
                 if ln.strip().startswith(("FN_", "CALLEE_"))]
        return [n for n in names if not n.endswith("_COUNT")]  # drop the FN_COUNT/CALLEE_COUNT sentinel

    entries = dict(re.findall(r"\[(FN_\w+)\]\s*=\s*(0x[0-9a-fA-F]+)", block))
    callees = dict(re.findall(r"\[(CALLEE_\w+)\]\s*=\s*(0x[0-9a-fA-F]+)", block))
    return entries, callees, enum_order("NativeFn"), enum_order("Callee")


# Native function name and argument count, in FN_* enum order (src/native/engine.h NATIVE_FUNCTIONS).
NATIVE_FUNCTIONS = [
    ("FN_QUERY_CARD_ATTRIBUTE", "Magic_QueryCardAttribute", 4),
    ("FN_IS_MANA_SOURCE", "Magic_IsManaSource", 2),
    ("FN_DROP_TOP_SPELL", "Magic_DropTopSpell", 0),
    ("FN_PUSH_SPELL_STACK", "Magic_PushSpellStack", 5),
    ("FN_CLEAR_SPELL_STACK", "Magic_ClearSpellStack", 0),
    ("FN_GET_COLOR_AND_TYPE_FLAGS", "Card_GetColorAndTypeFlags", 2),
]
# Callee label and argument count, in CALLEE_* enum order (src/native/card_query.c, spell_stack.c).
CALLEES_INFO = [
    ("CALLEE_SCAN_CARDS", "Magic_ScanCards", 1),
    ("CALLEE_IS_TAPPED", "Card_IsTapped", 2),
    ("CALLEE_COLOR_OVERRIDE_FF", "colour_override_FF", 3),
    ("CALLEE_COLOR_OVERRIDE_F9", "colour_override_F9", 3),
    ("CALLEE_COLOR_MASK_TO_INDEX", "Card_ColorMaskToColorIndex", 1),
    ("CALLEE_MARK_CARD", "mark_card", 3),
    ("CALLEE_AFTER_MARK", "after_mark", 0),
    ("CALLEE_FIND_FREE_SLOT", "find_free_slot", 2),
    ("CALLEE_PUSH_EVENT_CONTEXT", "Magic_PushEventContext", 0),
    ("CALLEE_POP_EVENT_CONTEXT", "Magic_PopEventContext", 0),
]
# Slot table base for the recorded program is read from layout.c at runtime (slot_base); the mode-flags
# dword the query function's caller reads a byte of (see PAD_DWORDS) is duel_mode_flags.
SLOT_PLAYER_STRIDE, SLOT_STRIDE = 0x5B20, 0x120


def regions(byte_map):
    """{addr: byte} -> [{'addr': '0x..', 'bytes': 'hex'}], merging contiguous runs."""
    out, cur = [], None
    for a in sorted(byte_map):
        if cur and a == cur[0] + len(cur[1]):
            cur[1].append(byte_map[a])
        else:
            cur = [a, bytearray([byte_map[a]])]
            out.append(cur)
    return [{"addr": "0x%08x" % a, "bytes": bytes(b).hex()} for a, b in out]


class Recorder:
    """Hooks every native function's entry in a running Machine and, for a sampled call, records its
    inputs/outputs as a vector. One Recorder per Machine; at most one call is being recorded at a
    time (a nested entry, through a callee, is not itself recorded)."""

    def __init__(self, m, outdir, max_per_situation, program, mode_flags_addr):
        self.m, self.uc, self.out, self.cap, self.program = m, m.uc, outdir, max_per_situation, program
        self.mode_flags_addr = mode_flags_addr
        self.count, self.rec, self.n = {}, None, 0
        entries, callees, _, _ = load_layout(program)
        self.funcs = {int(entries[fn], 16): (name, nargs) for fn, name, nargs in NATIVE_FUNCTIONS if fn in entries}
        self.callees = {int(callees[c], 16): (label, nargs) for c, label, nargs in CALLEES_INFO if c in callees}
        # A no-op memory hook spanning the whole address space makes Unicorn translate every block with
        # memory-hook support, so the per-call hooks added at function entry see reads already inside a
        # block that started translating before the call began.
        self.uc.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, lambda *a: None, begin=0, end=0xFFFFFFFF)
        for addr in self.funcs:
            self.uc.hook_add(UC_HOOK_CODE, self.on_entry, begin=addr, end=addr)

    def situation_key(self, name, args):
        """A rough bucket so a run yields a few examples of each interesting case (a slot's flags, its
        card's colour and type, and whether the AI is thinking) rather than every one of a function's
        hundreds of thousands of calls. Not meant to be exhaustive, only to keep vector counts sane."""
        m = self.m
        if name in ("Magic_QueryCardAttribute", "Magic_IsManaSource", "Card_GetColorAndTypeFlags"):
            pl, sl = args[0], args[1]
            a = m.L_slot_base + pl * SLOT_PLAYER_STRIDE + sl * SLOT_STRIDE
            try:
                return (name, args[2] if name.startswith("Magic_Query") else 0, m.r32(a + 4),
                        m.r32(a + 0xC) & 2, m.r32(a + 0x3C) >> 24,
                        m.r32(m.L_event_depth) != 0, m.r32(m.L_is_ai_thinking))
            except Exception:
                return (name, "unreadable-slot")
        if name == "Magic_PushSpellStack":
            return (name, args[2], m.r32(m.L_is_ai_thinking), m.r32(m.L_spell_stack_count))
        if name == "Magic_DropTopSpell":
            return (name, m.r32(m.L_spell_stack_count))
        return (name,)

    def on_entry(self, uc, address, size, user):
        if self.rec is not None:
            return
        m = self.m
        esp = uc.reg_read(UC_X86_REG_ESP)
        name, nargs = self.funcs[address]
        args = [m.r32(esp + 4 + 4 * i) for i in range(nargs)]
        key = self.situation_key(name, args)
        if self.count.get(key, 0) >= self.cap:
            return
        self.count[key] = self.count.get(key, 0) + 1
        r = {"addr": address, "name": name, "args": args, "esp": esp, "ret": m.r32(esp),
             "reads": {}, "writes": {}, "touched": set(), "calls": [], "depth": 0, "cur": None,
             "t": m.vt, "handles": [], "lo": esp - 0x200000, "hi": esp + 4 + 4 * nargs}
        if self.mode_flags_addr is not None:
            # Superset padding: the query function's caller may re-check the mode-flags dword after a
            # recompute; the native code reads all 4 bytes where a given original call might read fewer.
            base = self.mode_flags_addr
            r["pad"] = {base + i: m.r32(base) >> (8 * i) & 0xFF for i in range(4)}
        else:
            r["pad"] = {}
        self.rec = r
        r["handles"].append(uc.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, self.on_mem))
        for ca in self.callees:
            r["handles"].append(uc.hook_add(UC_HOOK_CODE, self.on_callee, begin=ca, end=ca))
        r["handles"].append(uc.hook_add(UC_HOOK_CODE, self.on_return, begin=r["ret"], end=r["ret"]))

    def on_mem(self, uc, access, address, size, value, user):
        r = self.rec
        if r is None or r["lo"] <= address < r["hi"]:
            return  # the caller's stack frame: native code keeps locals in C variables, not memory
        if access == UC_MEM_WRITE:
            data = (value & ((1 << (8 * size)) - 1)).to_bytes(size, "little")
            for i in range(size):
                a = address + i
                (r["cur"]["writes"] if r["depth"] else r["writes"])[a] = data[i]
                r["touched"].add(a)
        elif r["depth"] == 0:
            for i in range(size):
                a = address + i
                if a not in r["touched"] and a not in r["reads"]:
                    r["reads"][a] = self.uc.mem_read(a, 1)[0]

    def on_callee(self, uc, address, size, user):
        r = self.rec
        if r is None or r["depth"] != 0:
            return
        esp = uc.reg_read(UC_X86_REG_ESP)
        name, nargs = self.callees[address]
        c = {"callee": address, "name": name, "args": [self.m.r32(esp + 4 + 4 * i) for i in range(nargs)],
             "writes": {}, "ret": self.m.r32(esp), "esp": esp}
        r["cur"], r["depth"] = c, 1
        r["handles"].append(uc.hook_add(UC_HOOK_CODE, self.on_callee_return, begin=c["ret"], end=c["ret"]))

    def on_callee_return(self, uc, address, size, user):
        r = self.rec
        if r is None or r["depth"] != 1 or r["cur"] is None or uc.reg_read(UC_X86_REG_ESP) != r["cur"]["esp"] + 4:
            return
        c = r["cur"]
        c["return"] = S32(uc.reg_read(UC_X86_REG_EAX))
        r["calls"].append(c)
        r["cur"], r["depth"] = None, 0

    def on_return(self, uc, address, size, user):
        r = self.rec
        if r is None or r["depth"] != 0 or uc.reg_read(UC_X86_REG_ESP) != r["esp"] + 4:
            return
        for h in r["handles"]:
            try:
                uc.hook_del(h)
            except Exception:
                pass
        self.rec = None
        eax = uc.reg_read(UC_X86_REG_EAX)
        out = {a: self.uc.mem_read(a, 1)[0] for a in r["writes"]}
        calls = [{"callee": "0x%08x" % c["callee"], "name": c["name"], "args": [S32(x) for x in c["args"]],
                  "return": c["return"], "memory_writes": regions({a: self.uc.mem_read(a, 1)[0] for a in c["writes"]})}
                 for c in r["calls"]]
        v = {"function": r["name"], "program": self.program, "address": "0x%08x" % r["addr"],
             "description": "recorded from %s at virtual %.3fs" % (self.program, r["t"]),
             "source": "tools/difftest/record_vectors.py (emulator recording)",
             "args": [S32(x) for x in r["args"]], "expected_return": S32(eax),
             "memory_in": regions({**r["pad"], **r["reads"]}), "calls": calls,
             "memory_out_expected": regions(out), "memory_out_exhaustive": True}
        self.n += 1
        json.dump(v, open(os.path.join(self.out, "%s_%04d.json" % (r["name"], self.n)), "w"), indent=1)


def main():
    # Imported here, not at module level, so load_layout() and the vector-format helpers above can be
    # unit-tested (test_difftest.py) without unicorn or the game files installed.
    global UC_HOOK_CODE, UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE, UC_MEM_WRITE, UC_X86_REG_EAX, UC_X86_REG_ESP
    sys.path.insert(0, os.path.join(ROOT, "tools", "emu_spike"))
    from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE, UC_MEM_WRITE
    from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP
    from winemu import run as runmod

    outdir, cap = sys.argv[1], int(sys.argv[2])
    os.makedirs(outdir, exist_ok=True)
    program = "MAGIC" if "MAGIC.EXE" in " ".join(sys.argv) else "DUEL"

    orig_machine = runmod.Machine

    class RecordingMachine(orig_machine):
        def __init__(self, *a, **k):
            super().__init__(*a, **k)
            layout_c = open(os.path.join(ROOT, "src", "native", "layout.c")).read()
            block = re.search(r"const Layout LAYOUT_%s = \{(.*?)\n\};" % program, layout_c, re.S).group(1)

            def addr(field):
                m = re.search(r"\.%s\s*=\s*(0x[0-9a-fA-F]+)" % field, block)
                return int(m.group(1), 16) if m else None

            self.L_slot_base = addr("slot_base")
            self.L_event_depth = addr("event_depth")
            self.L_is_ai_thinking = addr("is_ai_thinking")
            self.L_spell_stack_count = addr("spell_stack_count")
            self.recorder = Recorder(self, outdir, cap, program, addr("duel_mode_flags"))

    runmod.Machine = RecordingMachine
    sys.argv = [sys.argv[0]] + sys.argv[3:]
    runmod.main()


if __name__ == "__main__":
    main()
