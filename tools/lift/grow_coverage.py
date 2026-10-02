#!/usr/bin/env python3
"""
grow_coverage.py - record more situations for the lifted card handlers until the vectors run (nearly) all their code.

Each round it looks at which lifted instructions no vector has executed yet, picks injections aimed at the handlers
with the most left (random event, random result for each function the handler calls, the handler's own card put in
play, the slot's fields and other cards' zones filled with arbitrary values: winemu/run.py `inject`), records them from
the original in several emulator runs at once, runs every recorded vector through the lifted code with coverage on, and
keeps the vectors that executed something new. A vector the lifted code does not match is a finding: it is kept in
OUT/fail with the harness's message.

    python3 tools/lift/grow_coverage.py --out DIR --hours 6

Needs sources/generated/lift (gen_handlers.py) and a harness built with -DLIFT_TRACK_WRITES -DLIFT_COVERAGE (the command
is in tools/lift/README.md). It can be stopped and started again: the state is in OUT.
"""
import argparse
import glob
import json
import multiprocessing
import os
import random
import re
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(ROOT, "tools", "difftest"))

import make_inject_script as mis  # noqa: E402
import run_vectors as rv  # noqa: E402

BASE = "2:dlgsel 1122 59;2.1:dlgsel 1123 59;3:dlg 1;5:dlg 1158;6:dlg 1;43:cast land"
START = 46.0
STEP = 0.05


def log(out, msg):
    line = time.strftime("%H:%M:%S ") + msg
    print(line, flush=True)
    with open(os.path.join(out, "log.txt"), "a") as f:
        f.write(line + "\n")


def instructions_by_handler(gen_c):
    funcs, cur = {}, None
    for line in open(gen_c):
        m = re.match(r"uint32_t lifted_([0-9a-f]{8})\(", line)
        if m:
            cur = funcs.setdefault(int(m.group(1), 16), [])
        m = re.search(r"LIFT_COV\(0x([0-9a-f]+)u\)", line)
        if m and cur is not None:
            cur.append(int(m.group(1), 16))
    return funcs


GATE = re.compile(r"/\* (?:cmp|test) (dword|word|byte) ptr \[0x([0-9a-f]+)\], (-?(?:0x[0-9a-f]+|\d+)|\w+) \*/")
SIZES = {"dword": 4, "word": 2, "byte": 1}


def gates_by_handler(gen_c):
    """Per handler, the globals its code compares or tests: {address: (size, values it is compared with)}. A handler is
    usually gated on one of these (the step code, say) before it does anything, so injections set them to what it wants."""
    gates, cur = {}, None
    for line in open(gen_c):
        m = re.match(r"uint32_t lifted_([0-9a-f]{8})\(", line)
        if m:
            cur = gates.setdefault(int(m.group(1), 16), {})
        m = GATE.search(line)
        if m and cur is not None and 0x4F2000 <= int(m.group(2), 16) < 0x6C3000:
            size, addr, operand = SIZES[m.group(1)], int(m.group(2), 16), m.group(3)
            values = cur.setdefault(addr, (size, set()))[1]
            try:
                values.add(int(operand, 0) & 0xFFFFFFFF)
            except ValueError:    # compared with a register: some small values are what it can be equal to
                values.update((0, 1, 2))
    return gates


def plan_round(rng, spec, insns, covered, events, gates, n):
    """n injection operations, aimed at the handlers with the most uncovered instructions."""
    left = {a: sum(1 for i in ins if i not in covered) for a, ins in insns.items()}
    todo = [a for a, c in left.items() if c > 0]
    if not todo:
        return []
    weights = [left[a] ** 0.7 for a in todo]
    ops = []
    for h in rng.choices(todo, weights, k=n):
        evs = events.get(h) or []
        event = rng.choice(evs) if evs and rng.random() < 0.6 else rng.randrange(0, 0x90)
        card = "own" if rng.random() < 0.8 else "-"
        pokes = []
        g = gates.get(h) or {}
        if g and rng.random() < 0.85:
            for addr in rng.sample(sorted(g), min(len(g), rng.randrange(1, 4))):
                size, values = g[addr]
                v = rng.choice(sorted(values)) if rng.random() < 0.8 else rng.randrange(0, 4)
                pokes.append(f"{addr:x}:{size}:{v:x}")
        ops.append((h, event, rng.randrange(0, 4), card, rng.randrange(1, 1 << 31), ",".join(pokes) or "-"))
    return ops


def script_for(ops):
    t, parts = START, [BASE]
    for h, event, nth, card, seed, pokes in ops:
        parts.append(f"{t:.2f}:inject {h:#x} {event:#x} {nth} r {card} {seed} {pokes}")
        t += STEP
    return ";".join(parts), t + 2.0


def start_chunk(args, out, tag, ops):
    script, seconds = script_for(ops)
    d = os.path.join(out, "work", tag)
    shutil.rmtree(d, ignore_errors=True)
    os.makedirs(d)
    spec = os.path.join(args.gen, "handler_spec.json")
    env = dict(os.environ, LIFT_SPEC=spec, RECORD_HANDLER_SPEC=spec, RECORD_ONLY_HANDLERS="1", INJECT_RESTORE="0.03",
               EMU_HARD_STOP=str(args.timeout))
    cmd = [args.python, "-u", os.path.join(ROOT, "tools", "difftest", "record_vectors.py"), d, "100000", "--exe", args.exe,
           "--seconds", f"{seconds:.1f}", "--script", script]
    logf = open(os.path.join(d, "..", tag + ".log"), "w")
    return subprocess.Popen(cmd, cwd=os.path.join(ROOT, "tools", "emu_spike"), env=env, stdout=logf, stderr=subprocess.STDOUT), d


def run_chunks(args, chunks, rnd, deadline):
    """Run the chunks, `workers` emulators at a time. An emulator that stops producing vectors (the game wedged on some
    arbitrary state) is killed after a while, and only its own chunk is lost."""
    pending = list(enumerate(chunks))
    running = []   # [process, directory, tag, started, vectors so far, when that last grew]
    while pending or running:
        while pending and len(running) < args.workers and time.time() < deadline:
            i, c = pending.pop(0)
            p, d = start_chunk(args, args.out, f"r{rnd}_{i}", c)
            running.append([p, d, f"r{rnd}_{i}", time.time(), 0, time.time()])
        if not running:
            break
        now = time.time()
        for r in list(running):
            p, d, tag, started, seen, changed = r
            if p.poll() is not None:
                running.remove(r)
                continue
            n = len(glob.glob(os.path.join(d, "Handler_*.json")))
            if n > seen:
                r[4], r[5] = n, now
            # (before the first vector the emulator is still playing the game up to the point where injections start)
            stalled = n > 0 and now - r[5] > args.stall
            if stalled or now - started > args.timeout or now > deadline + 600:
                p.kill()
                running.remove(r)
                log(args.out, f"{tag} cut off after {int(now - started)} s with {n} vectors" + (" (stalled)" if stalled else ""))
        time.sleep(10)


def check_one(job):
    """(path, status, messages, covered addresses) for one vector."""
    path, harness = job
    cov = path + ".cov"
    os.environ["FLAT_COV"] = cov
    try:
        status, messages, _ = rv.run_vector(path, harness)
    except Exception as e:  # noqa: BLE001 - one odd vector must not stop a night's run
        return path, "ERROR", [f"driver: {e}"], set()
    hit = set()
    if os.path.exists(cov):
        hit = {int(l, 16) for l in open(cov) if l.strip()}
        os.remove(cov)
    return path, status, messages, hit


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", required=True)
    ap.add_argument("--exe", default=os.path.join(ROOT, "sources", "installed", "Magic", "Program", "DUEL.EXE"))
    ap.add_argument("--gen", default=os.path.join(ROOT, "sources", "generated", "lift"))
    ap.add_argument("--harness", default=os.path.join(ROOT, "tools", "difftest", "build", "harness-flat-cov"))
    ap.add_argument("--python", default=sys.executable)
    ap.add_argument("--hours", type=float, default=6.0)
    ap.add_argument("--workers", type=int, default=8, help="emulator runs at once")
    ap.add_argument("--chunk", type=int, default=400, help="injections per emulator run")
    ap.add_argument("--round-ops", type=int, default=12000, help="injections per round")
    ap.add_argument("--stall", type=float, default=420, help="seconds without a new vector before an emulator run is cut off")
    ap.add_argument("--timeout", type=float, default=50 * 60, help="seconds before an emulator run is cut off")
    ap.add_argument("--min-gain", type=float, default=0.05, help="stop after two rounds that each add less than this percent")
    args = ap.parse_args()
    os.makedirs(os.path.join(args.out, "keep"), exist_ok=True)
    os.makedirs(os.path.join(args.out, "fail"), exist_ok=True)
    os.makedirs(os.path.join(args.out, "work"), exist_ok=True)
    deadline = time.time() + args.hours * 3600

    insns = instructions_by_handler(os.path.join(args.gen, "handlers_gen.c"))
    total = sum(len(v) for v in insns.values())
    spec = json.load(open(os.path.join(args.gen, "handler_spec.json")))
    source = open(os.path.join(ROOT, "duel", "duel_all.c"), errors="replace").read()
    gates = gates_by_handler(os.path.join(args.gen, "handlers_gen.c"))
    events = {}
    for e in spec:
        if e["lifted"]:
            ev = mis.events_for(source, e["name"], e["addr"])
            events[int(e["addr"], 16)] = sorted(set(ev) | set(mis.COMMON))

    cov_file = os.path.join(args.out, "cov_all.txt")
    covered = {int(l, 16) for l in open(cov_file) if l.strip()} if os.path.exists(cov_file) else set()

    def percent():
        return 100.0 * sum(1 for ins in insns.values() for i in ins if i in covered) / total

    rnd = len(glob.glob(os.path.join(args.out, "round_*.done")))
    log(args.out, f"start: {len(insns)} handlers, {total} instructions, {percent():.2f}% covered, round {rnd}")
    quiet = 0
    pool = multiprocessing.Pool(args.workers)
    while time.time() < deadline and quiet < 2:
        rnd += 1
        rng = random.Random(time.time_ns())
        before = percent()
        ops = plan_round(rng, spec, insns, covered, events, gates, args.round_ops)
        if not ops:
            log(args.out, "everything is covered")
            break
        chunks = [ops[i:i + args.chunk] for i in range(0, len(ops), args.chunk)]
        run_chunks(args, chunks, rnd, deadline)
        paths = sorted(glob.glob(os.path.join(args.out, "work", f"r{rnd}_*", "Handler_*.json")))
        results = pool.map(check_one, [(p, args.harness) for p in paths], chunksize=16)
        kept = failed = errors = 0
        status_count = {}
        for path, status, messages, hit in results:
            status_count[status] = status_count.get(status, 0) + 1
            name = os.path.basename(os.path.dirname(path)) + "_" + os.path.basename(path)
            if status == "PASS":
                if hit - covered:
                    covered |= hit
                    shutil.move(path, os.path.join(args.out, "keep", name))
                    kept += 1
            elif status == "FAIL" or (status == "ERROR" and "depends on memory" in " ".join(messages)):
                failed += 1
                shutil.move(path, os.path.join(args.out, "fail", name))
                with open(os.path.join(args.out, "fail", name + ".txt"), "w") as f:
                    f.write(status + "\n" + "\n".join(messages) + "\n")
            else:
                errors += 1
        with open(cov_file, "w") as f:
            f.writelines(f"{a:x}\n" for a in sorted(covered))
        shutil.rmtree(os.path.join(args.out, "work"), ignore_errors=True)
        os.makedirs(os.path.join(args.out, "work"))
        open(os.path.join(args.out, f"round_{rnd}.done"), "w").close()
        after = percent()
        full = sum(1 for ins in insns.values() if all(i in covered for i in ins))
        log(args.out, f"round {rnd}: {len(paths)} vectors {status_count}; kept {kept}, differing {failed}, other errors {errors}; "
                      f"coverage {before:.2f}% -> {after:.2f}%, {full} handlers fully covered, "
                      f"{len(os.listdir(os.path.join(args.out, 'fail'))) // 2} differing vectors so far")
        quiet = quiet + 1 if after - before < args.min_gain else 0
    log(args.out, f"done: {percent():.2f}% covered")


if __name__ == "__main__":
    main()
