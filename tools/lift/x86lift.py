#!/usr/bin/env python3
"""
x86lift.py - turn one function of a 32-bit x86 PE into C that does exactly what its machine code does.

This is static recompilation of a single function, not decompilation: every instruction becomes a statement over the
same registers and the same memory (src/native/lift_rt.h), so there are no types to recover, no names to trust and no
call targets to guess. The result is not meant to be read; it is meant to be checked (tools/difftest) and then kept or
replaced by hand-written code where understanding matters.

Scope: the 32-bit integer subset a compiler like MSVC 5 emits for ordinary game logic: mov/movzx/movsx/lea,
push/pop/leave, add/sub/adc/sbb/and/or/xor/neg/not/inc/dec/imul/idiv/cdq, cmp/test, shifts, setcc, jcc/jmp inside the
function, direct calls and ret. Anything else (FPU, string instructions, indirect calls and jumps, segment overrides,
a jump out of the function) raises Unsupported and the function is reported, never mistranslated.

    lift_function(getbytes, addr, name, entries) -> (C source, set of call targets, instruction count, (lo, hi))
"""
import capstone
from capstone import x86 as X

CC = {  # condition-code suffix -> C expression over the flag variables
    "e": "ZF", "z": "ZF", "ne": "!ZF", "nz": "!ZF",
    "l": "(SF != OF)", "nge": "(SF != OF)", "le": "(ZF || SF != OF)", "ng": "(ZF || SF != OF)",
    "g": "(!ZF && SF == OF)", "nle": "(!ZF && SF == OF)", "ge": "(SF == OF)", "nl": "(SF == OF)",
    "b": "CF", "c": "CF", "nae": "CF", "be": "(CF || ZF)", "na": "(CF || ZF)",
    "a": "(!CF && !ZF)", "nbe": "(!CF && !ZF)", "ae": "!CF", "nb": "!CF", "nc": "!CF",
    "s": "SF", "ns": "!SF", "o": "OF", "no": "!OF",
}
REG32 = ["eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"]
REG16 = {"ax": "eax", "cx": "ecx", "dx": "edx", "bx": "ebx", "sp": "esp", "bp": "ebp", "si": "esi", "di": "edi"}
REG8LO = {"al": "eax", "cl": "ecx", "dl": "edx", "bl": "ebx"}
REG8HI = {"ah": "eax", "ch": "ecx", "dh": "edx", "bh": "ebx"}


class Unsupported(Exception):
    pass


class Lifter:
    def __init__(self):
        self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self.md.detail = True
        self.tables = {}   # address of an indirect jmp -> its jump table (guest addresses), found while exploring
        self.imports = {}  # address of an import slot (a `call [slot]` target) -> name; set by the caller
        self.strict_tables = True   # False: keep only the plausible entries of a jump table instead of refusing the function
        self.dynamic_sites = []   # addresses of `call [index*4 + table]` instructions in the function just lifted

    # ---- operands ---------------------------------------------------------------------------------------------
    def reg(self, insn, op):
        name = insn.reg_name(op.reg)
        if name in REG32:
            return ("r", name, 32)
        if name in REG16:
            return ("r16", REG16[name], 16)
        if name in REG8LO:
            return ("r8l", REG8LO[name], 8)
        if name in REG8HI:
            return ("r8h", REG8HI[name], 8)
        raise Unsupported(f"register {name}")

    def addr(self, insn, op):
        m = op.mem
        if m.segment not in (0, X.X86_REG_INVALID):
            raise Unsupported("segment override")
        parts = []
        if m.base:
            parts.append("R_" + insn.reg_name(m.base))
        if m.index:
            idx = "R_" + insn.reg_name(m.index)
            parts.append(idx if m.scale == 1 else f"({idx} * {m.scale}u)")
        if m.disp or not parts:
            parts.append(f"0x{m.disp & 0xffffffff:x}u")
        return "(uint32_t)(" + " + ".join(parts) + ")"

    def read(self, insn, op, size=None):
        """C expression for an operand's value, zero-extended to uint32_t."""
        if op.type == X.X86_OP_IMM:
            return f"0x{op.imm & 0xffffffff:x}u"
        if op.type == X.X86_OP_REG:
            kind, r, bits = self.reg(insn, op)
            return {"r": f"R_{r}", "r16": f"LO16(R_{r})", "r8l": f"LO8(R_{r})", "r8h": f"HI8(R_{r})"}[kind]
        if op.type == X.X86_OP_MEM:
            bits = (size or op.size) * 8
            return f"RD{bits}({self.addr(insn, op)})"
        raise Unsupported("operand type")

    def write(self, insn, op, value, size=None):
        if op.type == X.X86_OP_REG:
            kind, r, bits = self.reg(insn, op)
            return {"r": f"R_{r} = {value};", "r16": f"SET_LO16(R_{r}, {value});",
                    "r8l": f"SET_LO8(R_{r}, {value});", "r8h": f"SET_HI8(R_{r}, {value});"}[kind]
        if op.type == X.X86_OP_MEM:
            bits = (size or op.size) * 8
            return f"WR{bits}({self.addr(insn, op)}, {value});"
        raise Unsupported("write to a non-lvalue")

    def bits(self, insn, op):
        if op.type == X.X86_OP_REG:
            return self.reg(insn, op)[2]
        return op.size * 8

    # ---- one instruction --------------------------------------------------------------------------------------
    def insn(self, i, insns, targets):
        """C statements for instruction i. `insns` is the explored function (jump targets must be in it); `targets`
        collects direct call targets."""
        mn, ops = i.mnemonic, i.operands
        n = len(ops)

        def need(k):
            if n != k:
                raise Unsupported(f"{mn} with {n} operands")

        if mn == "nop":
            return []
        if mn == "mov":
            need(2)
            return [self.write(i, ops[0], self.read(i, ops[1], ops[0].size if ops[0].type == X.X86_OP_MEM else None))]
        if mn in ("movzx", "movsx"):
            need(2)
            src_bits = self.bits(i, ops[1])
            v = self.read(i, ops[1])
            if mn == "movsx":
                v = f"(uint32_t)(int32_t)(int{src_bits}_t){v}"
            return [self.write(i, ops[0], v)]
        if mn == "lea":
            need(2)
            return [self.write(i, ops[0], self.addr(i, ops[1]))]
        if mn == "push":
            need(1)
            # the operand is read before ESP moves (`push [esp+4]` and `push esp` see the old ESP)
            return [f"{{ uint32_t t_ = {self.read(i, ops[0], 4)}; R_esp -= 4; WR32(R_esp, t_); }}"]
        if mn == "pop":
            need(1)
            return [f"{{ uint32_t t_ = RD32(R_esp); R_esp += 4; {self.write(i, ops[0], 't_')} }}"]
        if mn == "leave":
            return ["R_esp = R_ebp;", "R_ebp = RD32(R_esp);", "R_esp += 4;"]
        if mn == "ret":
            return ["return R_eax;"]
        if mn in ("add", "sub", "cmp", "and", "or", "xor", "test", "adc", "sbb"):
            need(2)
            bits = self.bits(i, ops[0])
            a, b = self.read(i, ops[0]), self.read(i, ops[1])
            if ops[1].type == X.X86_OP_IMM and bits < 32:
                b = f"(0x{ops[1].imm & ((1 << bits) - 1):x}u)"
            elif ops[1].type == X.X86_OP_IMM and bits == 32:
                b = f"0x{ops[1].imm & 0xffffffff:x}u"
            out = [f"{{ uint32_t a_ = {a}, b_ = {b}, r_;"]
            if mn in ("add", "adc"):
                out.append(f"r_ = a_ + b_{' + CF' if mn == 'adc' else ''};")
                out.append(f"FLAGS_ADD(a_, b_, r_, {bits});")
            elif mn in ("sub", "cmp", "sbb"):
                out.append(f"r_ = a_ - b_{' - CF' if mn == 'sbb' else ''};")
                out.append(f"FLAGS_SUB(a_, b_, r_, {bits});")
            else:
                sym = {"and": "&", "test": "&", "or": "|", "xor": "^"}[mn]
                out.append(f"r_ = a_ {sym} b_;")
                out.append(f"FLAGS_LOGIC(r_, {bits});")
            if mn not in ("cmp", "test"):
                out.append(self.write(i, ops[0], "r_"))
            out.append("}")
            return out
        if mn in ("inc", "dec"):
            need(1)
            bits = self.bits(i, ops[0])
            a = self.read(i, ops[0])
            d = "+" if mn == "inc" else "-"
            of = f"(r_ & MASK({bits})) == (1u << ({bits} - 1))" if mn == "inc" else f"(a_ & MASK({bits})) == (1u << ({bits} - 1))"
            return [f"{{ uint32_t a_ = {a}, r_ = a_ {d} 1u; FLAGS_ZS(r_, {bits}); OF = {of};",
                    self.write(i, ops[0], "r_"), "}"]
        if mn == "neg":
            need(1)
            bits = self.bits(i, ops[0])
            return [f"{{ uint32_t a_ = {self.read(i, ops[0])}, r_ = 0u - a_; FLAGS_SUB(0u, a_, r_, {bits});",
                    self.write(i, ops[0], "r_"), "}"]
        if mn == "not":
            need(1)
            return [self.write(i, ops[0], f"~{self.read(i, ops[0])}")]
        if mn in ("shl", "sal", "shr", "sar"):
            bits = self.bits(i, ops[0])
            cnt = "1u" if n == 1 else (f"{ops[1].imm & 0x1f}u" if ops[1].type == X.X86_OP_IMM else "(LO8(R_ecx) & 0x1fu)")
            a = self.read(i, ops[0])
            if mn in ("shl", "sal"):
                body = f"r_ = a_ << c_; CF = c_ ? ((a_ >> ({bits} - c_)) & 1u) : CF;"
            elif mn == "shr":
                body = "r_ = (a_ & MASK(%d)) >> c_; CF = c_ ? ((a_ >> (c_ - 1u)) & 1u) : CF;" % bits
            else:
                sh = f"(int32_t)(a_ << (32 - {bits})) >> (32 - {bits})"
                body = f"r_ = (uint32_t)(({sh}) >> c_); CF = c_ ? (((uint32_t)(({sh}) >> (c_ - 1u))) & 1u) : CF;"
            return [f"{{ uint32_t a_ = {a}, c_ = {cnt}, r_; {body}",
                    "if (c_) { FLAGS_ZS(r_, %d); OF = 0; }" % bits, self.write(i, ops[0], "r_"), "}"]
        if mn == "imul":
            if n == 2:
                dst, a, b = ops[0], self.read(i, ops[0]), self.read(i, ops[1])
            elif n == 3:
                dst, a, b = ops[0], self.read(i, ops[1]), f"0x{ops[2].imm & 0xffffffff:x}u"
            else:
                raise Unsupported("one-operand imul")
            bits = self.bits(i, dst)
            if bits != 32:
                raise Unsupported("imul on a partial register")
            return [f"{{ int64_t p_ = (int64_t)(int32_t){a} * (int64_t)(int32_t){b}; uint32_t r_ = (uint32_t)p_;",
                    "CF = OF = (p_ != (int64_t)(int32_t)r_); FLAGS_ZS(r_, 32);", self.write(i, dst, "r_"), "}"]
        if mn == "cdq":
            return ["R_edx = (int32_t)R_eax < 0 ? 0xffffffffu : 0u;"]
        if mn == "idiv":
            need(1)
            if self.bits(i, ops[0]) != 32:
                raise Unsupported("idiv on a partial register")
            return [f"lift_idiv32(&R_eax, &R_edx, {self.read(i, ops[0])});"]
        if mn.startswith("set"):
            need(1)
            cc = mn[3:]
            if cc not in CC:
                raise Unsupported(mn)
            return [self.write(i, ops[0], f"({CC[cc]}) ? 1u : 0u")]
        if mn == "jmp":
            need(1)
            if ops[0].type != X.X86_OP_IMM:
                table = self.tables.get(i.address)
                if table is None:
                    raise Unsupported("indirect jmp")
                cases = "".join(f" case {k}: goto L_{t:08x};" for k, t in enumerate(table))
                return [f"switch (R_{i.reg_name(ops[0].mem.index)}) {{{cases} default: lift_bad_jump(0x{i.address:x}u); }}"]
            t = ops[0].imm
            if t not in insns:
                raise Unsupported("jmp to an address the function does not contain")
            return [f"goto L_{t:08x};"]
        if mn.startswith("j") and mn[1:] in CC:
            need(1)
            t = ops[0].imm
            if t not in insns:
                raise Unsupported("conditional jump to an address the function does not contain")
            return [f"if ({CC[mn[1:]]}) goto L_{t:08x};"]
        if mn == "call":
            need(1)
            nxt = i.address + i.size
            push = ["R_esp -= 4;", f"WR32(R_esp, 0x{nxt:x}u);", "LIFT_CALL_REGS();"]
            after = ["R_ecx = R_edx = 0xcdcdcdcdu;"]
            if ops[0].type == X.X86_OP_IMM:
                t = ops[0].imm
                targets.add(t)
                return push + [f"{{ uint32_t cl_ = 0; R_eax = lift_call(0x{t:x}u, R_esp + 4u, &cl_); R_esp += 4u + cl_; }}"] + after
            m = ops[0].mem if ops[0].type == X.X86_OP_MEM else None
            if m is not None and not m.base and not m.index and (m.disp & 0xffffffff) in self.imports and m.segment in (0, X.X86_REG_INVALID):
                t = m.disp & 0xffffffff   # a call through the import table: the slot's address stands for the function
                targets.add(t)
                return push + [f"{{ uint32_t cl_ = 0; R_eax = lift_call(0x{t:x}u, R_esp + 4u, &cl_); R_esp += 4u + cl_; }}"] + after
            if m is not None and not m.base and m.index and m.scale == 4 and m.segment in (0, X.X86_REG_INVALID):
                # `call [index*4 + table]`: a card's handler reached through the master table. The target is only known
                # when it runs; the harness takes its argument count from the recorded call.
                self.dynamic_sites.append(i.address)
                return push + [f"{{ uint32_t cl_ = 0; R_eax = lift_call(RD32({self.addr(i, ops[0])}), R_esp + 4u, &cl_); R_esp += 4u + cl_; }}"] + after
            raise Unsupported("indirect call")
        raise Unsupported(f"instruction {mn}")

    # ---- a whole function -------------------------------------------------------------------------------------
    def explore(self, getbytes, addr, entries, window=0x6000):
        """Recursive descent from `addr`: every instruction reachable by falling through or jumping, so the function's
        extent comes from its control flow (a size in an index can be short for code placed after other code).
        Returns {address: instruction} and the set of jumps that are tail calls (a jmp to another function's entry)."""
        code = getbytes(addr, window)
        insns, tails, work = {}, {}, [addr]
        while work:
            a = work.pop()
            run = []   # the instructions decoded since this path started: where a jump table's bound check is looked for
            while a not in insns:
                off = a - addr
                if not 0 <= off < len(code):
                    raise Unsupported(f"control flow leaves the readable code (0x{a:x}, entry 0x{addr:x})")
                dec = list(self.md.disasm(code[off:off + 16], a, count=1))
                if not dec:
                    raise Unsupported(f"undecodable bytes at 0x{a:x}")
                i = dec[0]
                insns[a] = i
                run.append(i)
                mn = i.mnemonic
                if mn == "ret":
                    break
                if mn == "jmp" or (mn.startswith("j") and mn[1:] in CC):
                    op = i.operands[0]
                    if op.type != X.X86_OP_IMM:
                        table = self.jump_table(getbytes, i, run, addr)
                        self.tables[a] = table
                        work.extend(table)
                        break
                    t = op.imm
                    if mn == "jmp" and t in entries and t != addr:
                        tails[a] = t
                        break
                    work.append(t)
                    if mn == "jmp":
                        break
                a += i.size
        return insns, tails

    def jump_table(self, getbytes, i, run, func):
        """The targets of `jmp [index*4 + table]`, from the bound check the compiler put in front of it:
        `cmp index, N` and an unsigned `ja`/`jae`/`jb`-style branch past the table."""
        if i.mnemonic != "jmp" or i.operands[0].type != X.X86_OP_MEM:
            raise Unsupported("indirect jmp")
        m = i.operands[0].mem
        if m.base or not m.index or m.scale != 4 or m.segment not in (0, X.X86_REG_INVALID):
            raise Unsupported("indirect jmp that is not through an index*4 table")
        # The compiler's bound check: `cmp X, N` then `ja default` (index <= N falls through), where X is the index
        # register or the variable it was loaded from. Nothing between the check and the jump but the load of the index.
        bound = None
        for k in range(len(run) - 2, 0, -1):
            j, branch = run[k - 1], run[k]
            if j.mnemonic == "cmp" and len(j.operands) == 2 and j.operands[1].type == X.X86_OP_IMM \
                    and branch.mnemonic in ("ja", "jae"):
                bound = j.operands[1].imm + (1 if branch.mnemonic == "ja" else 0)
                break
            if j.mnemonic in ("jmp", "ret", "call"):
                break
        if bound is None or not 1 <= bound <= 256:
            raise Unsupported("jump table with no bound check in front of it")
        raw = getbytes(m.disp & 0xffffffff, 4 * bound)
        if len(raw) < 4 * bound:
            raise Unsupported("jump table runs off the image")
        table = [int.from_bytes(raw[4 * k:4 * k + 4], "little") for k in range(bound)]
        if any(not func - 0x1000 <= t < func + 0x6000 for t in table):
            if self.strict_tables:
                raise Unsupported("jump table entry outside the function (the bound was misjudged)")
            table = [t for t in table if func - 0x1000 <= t < func + 0x6000]   # only the extent is wanted (native_host.py)
        return table

    def entry_register_reads(self, insns, tails, addr):
        """Registers the function may read before it has written them: its inputs in registers (a __fastcall or hand-written
        function). Lifted code starts them at zero, so such a function would be mistranslated; it is refused instead. A push of
        a register is a callee-save, not a use, a call is taken to define the scratch registers (the return value), and a
        write to part of a register counts as defining it (the compiler does not read the rest)."""
        fam = {n: n for n in REG32}
        fam.update(REG16)
        fam.update(REG8LO)
        fam.update(REG8HI)
        index = {n: k for k, n in enumerate(REG32)}
        skip = {"esp", "eip", "eflags"}

        def regs(lst, insn):
            out = 0
            for r in lst:
                n = fam.get(insn.reg_name(r))
                if n and n not in skip:
                    out |= 1 << index[n]
            return out
        scratch = sum(1 << index[n] for n in ("eax", "ecx", "edx"))
        state, work, bad = {addr: 0}, [addr], 0
        self.defined_at_returns = (1 << len(REG32)) - 1   # registers written on every path to a ret (read after the loop)
        while work:
            a = work.pop()
            i = insns.get(a)
            if i is None or a in tails:
                continue
            defined = state[a]
            rd, wr = i.regs_access()[:2]
            reads, writes = regs(rd, i), regs(wr, i)
            if i.mnemonic == "push":
                reads = 0
            if i.mnemonic in ("xor", "sub", "sbb") and len(i.operands) == 2 and i.operands[0].type == X.X86_OP_REG \
                    and i.operands[1].type == X.X86_OP_REG and i.operands[0].reg == i.operands[1].reg:
                reads = 0
            if i.mnemonic == "call":
                writes |= scratch
            bad |= reads & ~defined
            after = defined | writes
            succ = []
            mn = i.mnemonic
            if mn == "ret":
                self.defined_at_returns &= after
                continue
            if mn == "jmp" or (mn.startswith("j") and mn[1:] in CC):
                if i.operands[0].type == X.X86_OP_IMM:
                    succ.append(i.operands[0].imm)
                else:
                    succ.extend(self.tables.get(a, []))
                if mn != "jmp":
                    succ.append(a + i.size)
            else:
                succ.append(a + i.size)
            for t in succ:
                old = state.get(t)
                new = after if old is None else old & after
                if old is None or new != old:
                    state[t] = new
                    work.append(t)
        return [n for n in REG32 if bad & (1 << index[n])]

    def lift_function(self, getbytes, addr, name, entries=frozenset()):
        insns, tails = self.explore(getbytes, addr, entries)
        stray = [r for r in self.entry_register_reads(insns, tails, addr) if r not in ("ebx", "esi", "edi", "ebp")]
        if stray:
            raise Unsupported("reads " + ", ".join(stray) + " on entry (a register argument)")
        self.dynamic_sites = []
        order = sorted(insns)
        lo, hi = order[0], order[-1] + insns[order[-1]].size
        body, targets = [], set()
        for a in order:
            i = insns[a]
            body.append(f"L_{a:08x}:; LIFT_COV(0x{a:x}u);  /* {i.mnemonic} {i.op_str} */")
            if a in tails:
                t = tails[a]
                targets.add(t)
                body.append(f"    LIFT_CALL_REGS(); {{ uint32_t cl_ = 0; return lift_call(0x{t:x}u, R_esp + 4u, &cl_); }}")
            else:
                body.extend("    " + st for st in self.insn(i, insns, targets))
        # the registers the function starts with are its caller's (lift_rt.h LiftRegs): what it pushes to save them is real
        decl = ["    uint32_t R_eax = lift_in.eax, R_ecx = lift_in.ecx, R_edx = lift_in.edx, R_ebx = lift_in.ebx, R_esp = esp,",
                "             R_ebp = lift_in.ebp, R_esi = lift_in.esi, R_edi = lift_in.edi;",
                "    uint32_t ZF = 0, SF = 0, CF = 0, OF = 0;"]
        src = (f"/* {name} @ 0x{addr:08x}, 0x{lo:x}-0x{hi:x}, {len(order)} instructions */\n"
               f"uint32_t lifted_{addr:08x}(uint32_t esp)\n{{\n" + "\n".join(decl) + "\n" + "\n".join(body) + "\n}\n")
        self.last_stack_arguments = self.stack_arguments(insns)
        self.last_returns_value = bool(self.defined_at_returns & (1 << REG32.index("eax")))   # else EAX is whatever the caller left
        return src, targets, len(order), (lo, hi)

    def stack_arguments(self, insns):
        """How many dword arguments a function with a frame pointer reads at [ebp+8], [ebp+12], ... (0 when it uses none, or does
        not keep a frame: the function index's count is then all there is)."""
        top = 0
        for i in insns.values():
            for op in i.operands:
                if op.type == X.X86_OP_MEM and op.mem.base and i.reg_name(op.mem.base) == "ebp" and not op.mem.index \
                        and 8 <= op.mem.disp < 8 + 4 * 32:
                    top = max(top, (op.mem.disp - 8) // 4 + 1)
        return top

    def register_inputs(self, getbytes, addr, entries=frozenset()):
        """The scratch registers (eax, ecx, edx) a function reads on entry. Used on the functions a lifted function calls,
        whether or not they lift themselves: lift_call passes stack arguments only."""
        try:
            insns, tails = self.explore(getbytes, addr, entries)
        except Unsupported:   # not liftable: look at the bytes up to its last `ret` instead
            sweep = {i.address: i for i in self.md.disasm(getbytes(addr, 0x2000), addr)}
            ends = [a for a, i in sweep.items() if i.mnemonic == "ret"]
            insns, tails = {a: i for a, i in sweep.items() if not ends or a <= max(ends)}, {}
        return [r for r in self.entry_register_reads(insns, tails, addr) if r in ("eax", "ecx", "edx")]

    def callee_arguments(self, getbytes, addr, entries=frozenset(), size=0x2000):
        """The stack arguments a callee takes: the most of what its frame reads and what its `ret imm16` pops (more than the
        function index's count says when the decompiler missed one; extra arguments passed are harmless, missing ones are not)."""
        try:
            insns, _ = self.explore(getbytes, addr, entries)
        except Unsupported:   # not liftable: the bytes the function index gives it
            insns = {i.address: i for i in self.md.disasm(getbytes(addr, size), addr)}
        pops = max((i.operands[0].imm for i in insns.values() if i.mnemonic == "ret" and i.operands), default=0)
        return max(self.stack_arguments(insns), pops // 4)

    def ret_cleanup(self, getbytes, addr, entries=frozenset()):
        """Bytes a function pops off the stack itself: the largest `ret imm16` it contains."""
        try:
            insns, _ = self.explore(getbytes, addr, entries)
        except Unsupported:   # a callee is not lifted, only its `ret imm16` is wanted: sweep its bytes instead
            insns = {i.address: i for i in self.md.disasm(getbytes(addr, 0x2000), addr)}
            ends = [a for a, i in insns.items() if i.mnemonic == "ret"]
            insns = {a: i for a, i in insns.items() if not ends or a <= max(ends)}
        return max((i.operands[0].imm for i in insns.values() if i.mnemonic == "ret" and i.operands), default=0)
