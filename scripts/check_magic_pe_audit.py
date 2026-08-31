#!/usr/bin/env python3
"""Fail the PE32 build when the generated ABI audit has fatal gaps."""

from __future__ import annotations

import json
import sys
from pathlib import Path


def main() -> int:
    if len(sys.argv) < 2:
        print("Usage: check_magic_pe_audit.py <report.json>...", file=sys.stderr)
        return 2
    failed = False
    for argument in sys.argv[1:]:
        path = Path(argument)
        audit = json.loads(path.read_text(encoding="utf-8"))
        fatal_errors = audit.get("fatal_errors", [])
        for error in fatal_errors:
            print(f"PE32 ABI error: {error}", file=sys.stderr)
        counts = audit.get("counts", {})
        if counts:
            print(
                "PE32 audit: "
                + ", ".join(
                    f"{name}={value}" for name, value in sorted(counts.items())
                )
            )
        else:
            module_count = len(audit.get("modules", []))
            export_count = sum(
                len(module.get("exports", []))
                for module in audit.get("modules", [])
            )
            print(
                f"PE32 ordinal audit: modules={module_count}, exports={export_count}"
            )
        failed = failed or bool(fatal_errors)
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
