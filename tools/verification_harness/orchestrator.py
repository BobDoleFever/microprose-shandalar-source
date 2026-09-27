#!/usr/bin/env python3
"""
Drives a run of one side (port or original) against an input script and produces
a tick-indexed trace of StateSnapshots. Two runs' traces are then compared with
state_snapshot.diff_snapshots, and divergence_bisect.bisect_divergence localizes any mismatch.

STATUS: skeleton. Neither side is wired up to a live process yet:

- Port side needs the build/shandalar test binary to accept an input script and
  emit state snapshots -- it currently only has a fixed 120-frame procedural test
  mode (see src/main.c). Adding a real "--harness-replay <script.json>" mode plus a
  snapshot dump is Phase 0/1 engineering work in the C code, not blocked on discs
  or Wine, and should happen before this file can do anything real.
- Original-binary side needs Wine, the clock-override shim DLL (see
  docs/VERIFICATION_HARNESS_PLAN.md, Layer 1), and a legally obtained copy of the
  game -- Phase 1/2.

This file defines the interface both sides need to satisfy, and a CLI that will
become useful once at least the port side is real.
"""

import json
import subprocess
import sys

from state_snapshot import StateSnapshot


class HarnessSide:
    """Interface a runnable side (port or original) must implement."""

    def run(self, input_script, max_tick):
        """Replay input_script up to max_tick and return a dict {tick: StateSnapshot}
        at whatever checkpoint ticks the implementation supports. Must be
        deterministic: the same input_script and max_tick must always produce the
        same trace."""
        raise NotImplementedError


class PortSide(HarnessSide):
    """Drives build/shandalar (this repo's own test binary)."""

    def __init__(self, binary_path="build/shandalar"):
        self.binary_path = binary_path

    def run(self, input_script, max_tick):
        # TODO(phase 0/1, C side): build/shandalar needs a real harness mode:
        #   ./build/shandalar --harness-replay script.json --max-tick N --dump-json
        # emitting one JSON snapshot per checkpoint tick to stdout. Until that
        # exists, this raises rather than pretending to produce real data.
        raise NotImplementedError(
            "PortSide.run: build/shandalar does not yet have a --harness-replay "
            "mode. See TODO in this method. Do not stub this out with fake data -- "
            "a silently-fake trace is worse than an explicit NotImplementedError."
        )


class OriginalBinarySide(HarnessSide):
    """Drives the real MAGIC.EXE/DUEL.EXE under Wine, via the clock-override shim."""

    def __init__(self, exe_path, wine_prefix):
        self.exe_path = exe_path
        self.wine_prefix = wine_prefix

    def run(self, input_script, max_tick):
        # TODO(phase 2): needs Wine installed, the clock-override shim DLL built
        # and injected via WINEDLLOVERRIDES, and a legally obtained copy of the
        # game providing exe_path. See docs/VERIFICATION_HARNESS_PLAN.md.
        raise NotImplementedError(
            "OriginalBinarySide.run: Wine/toolchain/original binary not available yet."
        )


def compare_traces(trace_a, trace_b, diff_fn):
    """Given two {tick: StateSnapshot} dicts covering the same ticks, return the
    sorted list of ticks with a non-empty diff, plus the diffs themselves."""
    common_ticks = sorted(set(trace_a) & set(trace_b))
    mismatches = []
    for tick in common_ticks:
        d = diff_fn(trace_a[tick], trace_b[tick])
        if d:
            mismatches.append((tick, d))
    return mismatches


if __name__ == "__main__":
    print(
        "orchestrator.py is a skeleton -- see the module docstring for what's "
        "implemented vs. pending. Nothing runnable yet without Phase 0/1/2 work.",
        file=sys.stderr,
    )
    sys.exit(1)
