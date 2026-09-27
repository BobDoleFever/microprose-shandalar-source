#!/usr/bin/env python3
"""Pair every MAGIC.EXE function with its likely twin in DUEL.EXE.

Both programs carry the same duel engine at different addresses, and the Ghidra names in the two
decompilations are unreliable (the bulk rename pass copied names by resemblance, and in DUEL.EXE two
different functions once shared one name). So names are never compared. Each function body is
normalised instead:

- comments and local declarations are dropped;
- parameters and locals become ``V``;
- calls to the program's own functions become ``FN`` (the call graph keeps the target address);
- globals (``DAT_``, ``PTR_``, ``g_``, anything declared at file scope) become ``G``;
- hex constants in the image range (0x400000 to 0x7fffff) become ``ADDR``;
- string labels (``s_Draw_a_card_Phase_00525af8``) become ``STR``, their text kept as evidence;
- keywords, types, Win32/C runtime imports, Ghidra macros and ordinary constants stay as they are.

Candidates come from an inverted index over token 5-grams (weighted by rarity) plus the nearest
functions by size. Each candidate is then scored on the edit-distance ratio of its normalised statement
lines, the 5-gram overlap, the body size, the call-graph shape (call sites and distinct callees), imported calls,
string literals and constants. A second pass adds call-graph agreement: how many of the function's
callees and callers already have a confident twin among the candidate's callees and callers.

Output: ``twins.csv`` with one row per MAGIC.EXE function, ranked by confidence. The evidence column
starts with a verdict, and the rows are grouped by it in this order:

- ``twin``: score at least ``TWIN_SCORE`` and a clear margin over the runner-up;
- ``weak``: a clear best, but scoring between ``NO_TWIN_SCORE`` and ``TWIN_SCORE``;
- ``ambiguous``: the runner-up is within ``AMBIGUOUS_MARGIN`` (listed as ``close=``), or the DUEL
  function matches another MAGIC function at least as well (``contested-by=``). The duel_addr is only
  the nominal best; do not take it as the twin;
- ``no-twin``: best score below ``NO_TWIN_SCORE``, probably MAGIC.EXE-only code (the overworld).

Standard library only. Run from anywhere:

    python3 tools/twins/find_twins.py            # writes tools/twins/twins.csv
    python3 tools/twins/find_twins.py --out x.csv
"""

import argparse
import bisect
import csv
import difflib
import math
import os
import re
import sys
import zlib
from collections import Counter, defaultdict

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
HERE = os.path.dirname(os.path.abspath(__file__))

# Pairs confirmed on the running game or the emulator (docs/SYMBOL_VERIFICATION.md). MAGIC -> DUEL.
KNOWN_PAIRS = [
    (0x004751D7, 0x0048D878),  # Magic_PushSpellStack
    (0x0047624F, 0x0048E8F2),  # Magic_RunTurnStep
    (0x00474D1E, 0x0048D3BF),  # Magic_ClearSpellStack
    (0x00473179, 0x0048B81A),  # Magic_QueryCardAttribute
    (0x00474389, 0x0048CA2A),  # Magic_IsManaSource
    (0x004AB28B, 0x0043064A),  # Ai_RecordChoice
    (0x004AB552, 0x00430911),  # Ai_EvaluateBoard
    (0x004CDB4F, 0x0049FC0F),  # SpellChain_WndProc (DUEL 0x00493e30 once shared the name; not a twin)
]
KNOWN_NON_TWINS = [(0x004CDB4F, 0x00493E30)]

NGRAM = 5
MAX_DF = 250            # 5-grams in more DUEL functions than this are too common to find candidates with
TOP_K = 12              # candidates rescored in detail per MAGIC function
SIZE_NEIGHBOURS = 12    # candidates added purely by nearest body size
SEQ_LINE_CAP = 1500     # longer pairs let difflib skip very common lines (faster, slightly lower)
SEQ_TOKEN_CAP = 800     # pairs up to this many tokens are also compared token by token
AMBIGUOUS_MARGIN = 0.02
NO_TWIN_SCORE = 0.55
TWIN_SCORE = 0.70
ANCHOR_SCORE = 0.85

WEIGHTS = {
    "seq": 0.35,
    "ngram": 0.20,
    "size": 0.15,
    "calls": 0.10,
    "api": 0.05,
    "str": 0.05,
    "const": 0.05,
    "graph": 0.20,
}

IMAGE_LO, IMAGE_HI = 0x400000, 0x800000

C_WORDS = {
    "if", "else", "while", "do", "for", "switch", "case", "default", "break", "continue", "return",
    "goto", "sizeof", "struct", "union", "enum", "typedef", "const", "volatile", "unsigned", "signed",
    "static", "extern", "void", "char", "short", "int", "long", "float", "double", "bool", "true", "false",
}

TOKEN_RE = re.compile(
    r'"(?:\\.|[^"\\])*"'                 # string literal
    r"|'(?:\\.|[^'\\])*'"                # char literal
    r"|[A-Za-z_][A-Za-z0-9_]*"           # identifier
    r"|0[xX][0-9a-fA-F]+[uUlL]*"         # hex number
    r"|\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[uUlLfF]*"  # decimal number
    r"|->|<<=|>>=|<<|>>|==|!=|<=|>=|&&|\|\||\+\+|--|[-+*/%&|^]="
    r"|\S"
)
COMMENT_RE = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
HEX8_RE = re.compile(r"_?[0-9a-fA-F]{8}$")
STRING_LABEL_RE = re.compile(r"^(?:s|u)_(.*?)_?([0-9a-fA-F]{8})$")
GLOBAL_PREFIX_RE = re.compile(
    r"^(?:_?DAT|PTR|LAB|UNK|switchD|caseD|joined_r0x|code_r0x|g|off|exref|BYTE|WORD|DWORD)_"
)
FUN_RE = re.compile(r"^(?:thunk_)?FUN_[0-9a-fA-F]{8}$")
EMBEDDED_ADDR_RE = re.compile(r"(?:^|_)00[4-7][0-9a-fA-F]{5}(?:_|$)")
MACRO_RE = re.compile(r"^(?:CONCAT|SUB|ZEXT|SEXT|CARRY|SCARRY|SBORROW|POPCOUNT)\d*$|^swi$")
DECL_NAME_RE = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[[^\]]*\]\s*)*;\s*$")


class Func:
    __slots__ = (
        "addr", "name", "aliases", "size", "lines", "line_bag", "tokens", "token_bag", "shingles", "strings", "consts", "apis",
        "callee_names", "callees", "callers", "n_calls",
    )

    def __init__(self, addr, name, size):
        self.addr = addr
        self.name = name
        self.size = size
        self.callees = []
        self.callers = set()


# --------------------------------------------------------------------------------------------------
# Parsing


def read_index(path):
    rows = []
    with open(path, newline="", encoding="utf-8", errors="replace") as f:
        for row in csv.DictReader(f):
            rows.append((int(row["Address"], 16), row["FunctionName"], int(row["BodySize"] or 0)))
    return rows


def split_functions(text):
    """Yield (signature, body_lines) for each top-level function, in file order."""
    lines = text.split("\n")
    globals_ = set()
    seen_function = False
    i = 0
    n = len(lines)
    while i < n:
        if lines[i] == "{":
            j = i - 1
            while j >= 0 and not lines[j].strip():   # Ghidra leaves a blank line before the brace
                j -= 1
            sig = []
            while j >= 0 and lines[j].strip():
                sig.insert(0, lines[j])
                j -= 1
            k = i + 1
            while k < n and lines[k] != "}":
                k += 1
            seen_function = True
            yield " ".join(sig), lines[i + 1:k], globals_
            i = k + 1
            continue
        if not seen_function:
            m = DECL_NAME_RE.search(lines[i])
            if m and "(" not in lines[i]:
                globals_.add(m.group(1))
        i += 1


def signature_name_and_params(sig):
    sig = COMMENT_RE.sub(" ", sig)
    head, _, rest = sig.partition("(")
    names = re.findall(r"[A-Za-z_][A-Za-z0-9_]*", head)
    name = names[-1] if names else ""
    params = set()
    for part in rest.rsplit(")", 1)[0].split(","):
        ids = re.findall(r"[A-Za-z_][A-Za-z0-9_]*", part)
        if len(ids) >= 2:
            params.add(ids[-1])
    return name, params


def split_declarations(body_lines):
    """Ghidra puts the local declarations first, then a blank line."""
    locals_ = set()
    for idx, line in enumerate(body_lines):
        s = line.strip()
        if not s:
            return locals_, body_lines[idx + 1:]
        m = DECL_NAME_RE.search(COMMENT_RE.sub("", s))
        if not m or "(" in s and "(*" not in s or "=" in s:
            return locals_, body_lines[idx:]
        locals_.add(m.group(1))
    return locals_, []


def normalise_string(s):
    return re.sub(r"[^0-9A-Za-z]+", "_", s).strip("_").lower()


def to_int(tok):
    try:
        if tok[:2] in ("0x", "0X"):
            return int(tok.rstrip("uUlL"), 16)
        return int(tok.rstrip("uUlL"))
    except ValueError:
        return None


def tokenize_body(body, own_names, local_names, global_names):
    """Return (normalised statement lines, strings, constants, api calls, callee names).

    Each line is a tuple of normalised tokens. A call to a lower-case or ``_`` name that is not one of the
    program's own functions is a C runtime import in MAGIC.EXE (``malloc``, ``_itoa``); DUEL.EXE links the
    runtime statically, so there the same call is to one of its own functions. Both become ``FN`` so the
    twins still read alike, and only capitalised imports (Win32) count as API calls.
    """
    body = COMMENT_RE.sub(" ", body)
    lines = []
    strings = Counter()
    consts = Counter()
    apis = Counter()
    callees = []
    for text in body.split("\n"):
        raw = TOKEN_RE.findall(text)
        if not raw:
            continue
        out = []
        for i, tok in enumerate(raw):
            c = tok[0]
            nxt = raw[i + 1] if i + 1 < len(raw) else ""
            if c == '"':
                out.append("STR")
                strings[normalise_string(tok[1:-1])] += 1
            elif c == "'":
                out.append(tok)
            elif c.isdigit():
                v = to_int(tok)
                if v is not None and tok[:2] in ("0x", "0X") and IMAGE_LO <= v < IMAGE_HI:
                    out.append("ADDR")
                else:
                    out.append(str(v) if v is not None else tok)
                    if v is not None and v > 1:
                        consts[v] += 1
            elif c.isalpha() or c == "_":
                if tok in local_names:
                    out.append("V")
                elif tok in own_names or FUN_RE.match(tok):
                    out.append("FN")
                    if nxt == "(":
                        callees.append(tok)
                else:
                    m = STRING_LABEL_RE.match(tok)
                    if m:
                        out.append("STR")
                        strings[normalise_string(m.group(1))] += 1
                    elif (tok in global_names or GLOBAL_PREFIX_RE.match(tok)
                          or EMBEDDED_ADDR_RE.search(tok)):
                        out.append("G")
                    elif nxt == "(" and tok not in C_WORDS and not MACRO_RE.match(tok):
                        if c.isupper():
                            out.append(tok)
                            apis[tok] += 1
                        else:
                            out.append("FN")
                            callees.append(tok)
                    else:
                        out.append(tok)
            else:
                out.append(tok)
        lines.append(tuple(out))
    return lines, strings, consts, apis, callees


def load_program(unified_c, index_csv, label):
    with open(unified_c, encoding="utf-8", errors="replace") as f:
        text = f.read()
    return build_program(text, read_index(index_csv), label)


def build_program(text, index, label):
    """Functions of one program from its unified C text and its index rows (address, name, size)."""
    parts = list(split_functions(text))
    if len(parts) != len(index):
        raise SystemExit(f"{label}: {len(parts)} function bodies but {len(index)} index rows")
    # The index lags behind renames applied to the C file, so a function is known by both names.
    sigs = [signature_name_and_params(sig) for sig, _, _ in parts]
    own_names = {name for _, name, _ in index} | {name for name, _ in sigs}
    funcs = []
    for (addr, name, size), (_, body_lines, globals_), (sig_name, params) in zip(index, parts, sigs):
        locals_, stmts = split_declarations(body_lines)
        f = Func(addr, name, size)
        f.aliases = {name, sig_name}
        (f.lines, f.strings, f.consts, f.apis, f.callee_names) = tokenize_body(
            "\n".join(stmts), own_names, params | locals_, globals_)
        f.tokens = [t for line in f.lines for t in line]
        f.line_bag = Counter(f.lines)
        f.token_bag = Counter(f.tokens)
        f.n_calls = len(f.callee_names) + sum(f.apis.values())
        funcs.append(f)
    # Bodies and index rows are paired by order; names like Foo_0049fc0f must carry their own address.
    for f in funcs:
        for nm in f.aliases:
            m = HEX8_RE.search(nm)
            if m and nm.startswith("FUN_") and int(m.group(0).lstrip("_"), 16) != f.addr:
                raise SystemExit(f"{label}: body order disagrees with the index at {nm}")
    # Resolve callee names to addresses; a name carried by two functions resolves to neither.
    by_name = defaultdict(list)
    for f in funcs:
        for nm in f.aliases:
            by_name[nm].append(f.addr)
    by_addr = {f.addr: f for f in funcs}
    for f in funcs:
        for nm in f.callee_names:
            targets = by_name.get(nm)
            if not targets and FUN_RE.match(nm):
                a = int(nm[-8:], 16)
                targets = [a] if a in by_addr else None
            if targets and len(targets) == 1:
                f.callees.append(targets[0])
                by_addr[targets[0]].callers.add(f.addr)
        f.shingles = shingles(f.tokens)
    return funcs


def shingles(tokens):
    """Token 5-grams as CRC-32s (not hash(), which changes per run and would make the output unstable)."""
    if len(tokens) < NGRAM:
        return {zlib.crc32("\x00".join(tokens).encode())} if tokens else set()
    return {zlib.crc32("\x00".join(tokens[i:i + NGRAM]).encode())
            for i in range(len(tokens) - NGRAM + 1)}


# --------------------------------------------------------------------------------------------------
# Scoring


def multiset_jaccard(a, b):
    if not a and not b:
        return None
    inter = sum((a & b).values())
    union = sum((a | b).values())
    return inter / union if union else None


def ratio(x, y):
    if x == y:
        return 1.0
    return min(x, y) / max(x, y)


def seq_ratio(m, d):
    """Edit-distance ratio (difflib's 2 * matches / total) over normalised statement lines.

    Small bodies are also compared token by token and the better ratio kept: two builds of a short
    function often split the same expression over different statements.
    """
    if m.lines == d.lines:
        return 1.0
    a, b = m.lines, d.lines
    r = difflib.SequenceMatcher(None, a, b, autojunk=len(a) + len(b) > SEQ_LINE_CAP).ratio()
    if len(m.tokens) + len(d.tokens) <= SEQ_TOKEN_CAP:
        r = max(r, difflib.SequenceMatcher(None, m.tokens, d.tokens, autojunk=False).ratio())
    return r


def seq_bound(m, d):
    """An upper bound for seq_ratio: the same ratios with order ignored (cheap)."""
    r = bag_ratio(m.line_bag, d.line_bag)
    if len(m.tokens) + len(d.tokens) <= SEQ_TOKEN_CAP:
        r = max(r, bag_ratio(m.token_bag, d.token_bag))
    return r


def bag_ratio(a, b):
    """The same ratio with order ignored: an upper bound for seq_ratio, and cheap."""
    total = sum(a.values()) + sum(b.values())
    return 2 * sum((a & b).values()) / total if total else 1.0


class Matcher:
    def __init__(self, magic, duel):
        self.magic = magic
        self.duel = duel
        self.duel_by_addr = {f.addr: f for f in duel}
        n = len(duel)
        df = Counter()
        for f in duel:
            df.update(f.shingles)
        self.idf = {h: math.log(1 + n / c) for h, c in df.items()}
        self.postings = defaultdict(list)
        for f in duel:
            for h in f.shingles:
                if df[h] <= MAX_DF:
                    self.postings[h].append(f.addr)
        self.duel_weight = {f.addr: self.weight(f.shingles) for f in duel}
        self.magic_weight = {f.addr: self.weight(f.shingles) for f in magic}
        self.by_size = sorted(duel, key=lambda f: f.size)
        self.sizes = [f.size for f in self.by_size]
        self.detail_cache = {}
        self.seq_cache = {}
        self.anchors = {}      # magic addr -> duel addr

    def weight(self, hs):
        # Shingles DUEL.EXE never has get the weight of a DUEL singleton.
        default = math.log(1 + len(self.duel))
        return sum(self.idf.get(h, default) for h in hs)

    def ngram_sim(self, m, d, shared=None):
        if shared is None:
            common = m.shingles & d.shingles
            shared = sum(self.idf[h] for h in common)
        union = self.magic_weight[m.addr] + self.duel_weight[d.addr] - shared
        return shared / union if union > 0 else 1.0

    def candidates(self, m):
        acc = defaultdict(float)
        for h in m.shingles:
            posting = self.postings.get(h)
            if posting:
                w = self.idf[h]
                for a in posting:
                    acc[a] += w
        wm = self.magic_weight[m.addr]
        coarse = {}
        for a, shared in acc.items():
            union = wm + self.duel_weight[a] - shared
            coarse[a] = shared / union if union > 0 else 1.0
        chosen = set(sorted(coarse, key=lambda a: (-round(coarse[a], 9), a))[:TOP_K])
        # Nearest by size, so tiny functions whose 5-grams are all common still get candidates.
        pos = bisect.bisect_left(self.sizes, m.size)
        lo, hi = pos - 1, pos
        added = 0
        while added < SIZE_NEIGHBOURS and (lo >= 0 or hi < len(self.sizes)):
            dl = m.size - self.sizes[lo] if lo >= 0 else float("inf")
            dh = self.sizes[hi] - m.size if hi < len(self.sizes) else float("inf")
            if dl <= dh:
                chosen.add(self.by_size[lo].addr)
                lo -= 1
            else:
                chosen.add(self.by_size[hi].addr)
                hi += 1
            added += 1
        return chosen

    def details(self, m, d):
        """Every feature except the sequence ratio and the call graph (cached)."""
        key = (m.addr, d.addr)
        det = self.detail_cache.get(key)
        if det is None:
            det = {
                "seq_bound": seq_bound(m, d),
                "ngram": self.ngram_sim(m, d),
                "size": ratio(m.size, d.size),
                "calls": (ratio(m.n_calls, d.n_calls)
                          + ratio(len(set(m.callee_names)), len(set(d.callee_names)))) / 2,
                "api": multiset_jaccard(m.apis, d.apis),
                "str": multiset_jaccard(m.strings, d.strings),
                "const": multiset_jaccard(m.consts, d.consts),
            }
            self.detail_cache[key] = det
        return det

    def seq(self, m, d):
        key = (m.addr, d.addr)
        v = self.seq_cache.get(key)
        if v is None:
            v = self.seq_cache[key] = seq_ratio(m, d)
        return v

    def graph_sim(self, m, d):
        """Share of m's anchored callees and callers whose twins are d's callees and callers."""
        hits = total = 0
        d_callees = set(d.callees)
        for c in set(m.callees):
            t = self.anchors.get(c)
            if t is not None:
                total += 1
                hits += t in d_callees
        for c in m.callers:
            t = self.anchors.get(c)
            if t is not None:
                total += 1
                hits += t in d.callers
        return hits / total if total else None

    @staticmethod
    def combine(det):
        num = den = 0.0
        for k, w in WEIGHTS.items():
            v = det.get(k)
            if v is not None:
                num += w * v
                den += w
        return num / den

    def rank(self, m):
        """Candidates for m, best first, as (score, features, duel_addr).

        The sequence ratio is the expensive part, so candidates are taken in order of an upper bound
        (the order-free ratio in its place) and the exact score is only computed while a candidate could
        still reach the top two or come within AMBIGUOUS_MARGIN of the best.
        """
        bounded = []
        for a in self.candidates(m):
            d = self.duel_by_addr[a]
            det = dict(self.details(m, d))
            det["graph"] = self.graph_sim(m, d) if self.anchors else None
            det["seq"] = det["seq_bound"]
            bounded.append((self.combine(det), a, det))
        bounded.sort(key=lambda t: (-t[0], t[1]))
        exact = []
        for bound, a, det in bounded:
            if len(exact) >= 2:
                best, second = exact[0][0], exact[1][0]
                if bound < min(second, best - AMBIGUOUS_MARGIN):
                    break
            det["seq"] = self.seq(m, self.duel_by_addr[a])
            del det["seq_bound"]
            exact.append((self.combine(det), det, a))
            exact.sort(key=lambda t: (-t[0], t[2]))
        return exact

    def run_pass(self):
        return {m.addr: self.rank(m) for m in self.magic}

    def match(self):
        first = self.run_pass()
        best_rev = self.best_reverse(first)
        for ma, ranked in first.items():
            if not ranked:
                continue
            s, _, da = ranked[0]
            second = ranked[1][0] if len(ranked) > 1 else 0.0
            if s >= ANCHOR_SCORE and s - second >= AMBIGUOUS_MARGIN and best_rev.get(da) == ma:
                self.anchors[ma] = da
        return self.run_pass()

    @staticmethod
    def best_reverse(results, with_score=False):
        """For each DUEL function, the MAGIC function that scored it highest (lowest address on ties)."""
        best = {}
        for ma, ranked in sorted(results.items()):
            for s, _, da in ranked:
                if da not in best or s > best[da][0]:
                    best[da] = (s, ma)
        if with_score:
            return best
        return {da: ma for da, (s, ma) in best.items()}


# --------------------------------------------------------------------------------------------------
# Output


def fmt(v):
    return "-" if v is None else f"{v:.2f}"


def build_rows(matcher, results):
    best_rev = Matcher.best_reverse(results, with_score=True)
    rows = []
    for m in matcher.magic:
        ranked = results[m.addr]
        if not ranked:
            rows.append({"magic_addr": m.addr, "duel_addr": None, "score": 0.0, "second": 0.0,
                         "verdict": "no-twin", "evidence": "no-twin; no candidates"})
            continue
        s, det, da = ranked[0]
        second = ranked[1][0] if len(ranked) > 1 else 0.0
        d = matcher.duel_by_addr[da]
        close = [a for (sc, _, a) in ranked[1:] if s - sc < AMBIGUOUS_MARGIN]
        # Contested: the DUEL function is itself a better (or equal) match for another MAGIC function.
        rev_score, rev_magic = best_rev[da]
        mutual = rev_magic == m.addr
        contested = not mutual and rev_score > s - AMBIGUOUS_MARGIN
        if s < NO_TWIN_SCORE:
            verdict = "no-twin"
        elif close or contested:
            verdict = "ambiguous"
        elif s < TWIN_SCORE:
            verdict = "weak"
        else:
            verdict = "twin"
        parts = [verdict]
        if close:
            parts.append("close=" + "/".join(f"0x{a:08x}" for a in close[:4]))
        if contested:
            parts.append(f"contested-by=0x{rev_magic:08x}")
        parts.append("mutual" if mutual else "not-mutual")
        parts.append(f"seq={fmt(det['seq'])} ngram={fmt(det['ngram'])}")
        parts.append(f"size={m.size}/{d.size}")
        parts.append(f"calls={m.n_calls}/{d.n_calls}")
        if det["graph"] is not None:
            parts.append(f"graph={det['graph']:.2f}")
        for key, label in (("api", "api"), ("str", "str"), ("const", "const")):
            if det[key] is not None:
                parts.append(f"{label}={det[key]:.2f}")
        rows.append({"magic_addr": m.addr, "duel_addr": da, "score": s, "second": second,
                     "verdict": verdict, "evidence": "; ".join(parts)})
    order = {"twin": 0, "weak": 1, "ambiguous": 2, "no-twin": 3}
    rows.sort(key=lambda r: (order[r["verdict"]], -round(r["score"], 4),
                             -round(r["score"] - r["second"], 4), r["magic_addr"]))
    return rows


def write_csv(rows, path):
    with open(path, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["magic_addr", "duel_addr", "score", "second_best_score", "evidence"])
        for r in rows:
            w.writerow([f"0x{r['magic_addr']:08x}",
                        f"0x{r['duel_addr']:08x}" if r["duel_addr"] is not None else "",
                        f"{r['score']:.4f}", f"{r['second']:.4f}", r["evidence"]])


def known_pair_report(results, pairs=KNOWN_PAIRS):
    found = []
    for ma, da in pairs:
        ranked = results.get(ma, [])
        found.append(bool(ranked) and ranked[0][2] == da)
    return sum(found), len(pairs), found


def find_twins(repo=REPO):
    magic = load_program(os.path.join(repo, "magic", "magic_unified.c"),
                         os.path.join(repo, "magic", "function_index.csv"), "MAGIC.EXE")
    duel = load_program(os.path.join(repo, "duel", "duel_unified.c"),
                        os.path.join(repo, "duel", "function_index.csv"), "DUEL.EXE")
    matcher = Matcher(magic, duel)
    results = matcher.match()
    return matcher, results


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--repo", default=REPO)
    ap.add_argument("--out", default=os.path.join(HERE, "twins.csv"))
    args = ap.parse_args(argv)
    matcher, results = find_twins(args.repo)
    rows = build_rows(matcher, results)
    write_csv(rows, args.out)
    counts = Counter(r["verdict"] for r in rows)
    print(f"{len(rows)} MAGIC.EXE functions: {counts['twin']} twin, {counts['weak']} weak, "
          f"{counts['ambiguous']} ambiguous, {counts['no-twin']} no-twin; "
          f"{len(matcher.anchors)} call-graph anchors -> {os.path.relpath(args.out)}")
    hit, total, found = known_pair_report(results)
    for (ma, da), ok in zip(KNOWN_PAIRS, found):
        ranked = results.get(ma, [])
        got = f"0x{ranked[0][2]:08x}" if ranked else "none"
        print(f"  0x{ma:08x} -> 0x{da:08x}: {'rank 1' if ok else 'MISSED (got ' + got + ')'}")
    print(f"known pairs at rank 1: {hit}/{total} ({hit / total:.0%})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
