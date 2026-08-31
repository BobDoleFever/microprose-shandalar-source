#!/usr/bin/env python3
"""Generate typed ordinal metadata for retail companion DLL calls."""

from __future__ import annotations

import argparse
import csv
import json
import re
from pathlib import Path


MODULES = {
    "STATWIN.DLL": (Path("statwin"), 3),
    "MAGSND.DLL": (Path("magsnd"), 27),
    "MAGVID.DLL": (Path("magvid"), 20),
    "DECKDLL.DLL": (Path("deckdll"), 4),
}


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", type=Path, default=Path("."))
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--def-dir", type=Path, default=None)
    return parser.parse_args()


def read_functions(path: Path) -> dict[int, str]:
    result: dict[int, str] = {}
    if not path.exists():
        return result
    with path.open(newline="", encoding="utf-8") as source:
        for row in csv.DictReader(source):
            result[int(row["Address"], 16)] = row["FunctionName"]
    return result


def read_symbols(path: Path) -> tuple[dict[int, int], dict[int, str], set[int]]:
    ordinals: dict[int, int] = {}
    names: dict[int, str] = {}
    data_addresses: set[int] = set()
    if not path.exists():
        return ordinals, names, data_addresses
    with path.open(newline="", encoding="utf-8") as source:
        for row in csv.DictReader(source):
            raw_address = row["Address"]
            if raw_address.startswith("EXTERNAL:") or not re.match(r"^[0-9a-fA-F]+$", raw_address):
                continue
            address = int(raw_address, 16)
            name = row["SymbolName"]
            match = re.fullmatch(r"Ordinal_(\d+)", name)
            if match is not None:
                ordinals[int(match.group(1))] = address
            elif not name.startswith("DAT_") and not name.startswith("PTR_"):
                names[address] = name
            if row.get("SymbolType") == "Label" or row.get("IsFunction") == "false":
                data_addresses.add(address)
    return ordinals, names, data_addresses


def read_prototypes(path: Path) -> dict[str, str]:
    result: dict[str, str] = {}
    if not path.exists():
        return result
    pending = ""
    for raw_line in path.read_text(encoding="utf-8").splitlines():
        pending = (pending + " " + raw_line.strip()).strip()
        if ";" not in raw_line:
            continue
        statement = pending.split(";", 1)[0].strip() + ";"
        match = re.search(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(", statement)
        if match is not None and not statement.startswith("typedef"):
            result[match.group(1)] = statement
        pending = pending.split(";", 1)[1].strip()
    return result


def normalize_prototype(prototype: str) -> tuple[str, str, bool]:
    if "__stdcall" in prototype:
        return prototype, "__stdcall", False
    if "__cdecl" in prototype:
        return prototype, "__cdecl", False
    name = re.search(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(", prototype)
    if name is None:
        raise ValueError(f"The prototype is not valid: {prototype}")
    typed = prototype[:name.start()] + "__cdecl " + prototype[name.start():]
    return typed, "__cdecl", True


def generate_def_file(module_name: str, exports: list[dict[str, object]]) -> str:
    lines = [f"LIBRARY {module_name}", "EXPORTS"]
    for export in exports:
        name = export["function"]
        ordinal = export["ordinal"]
        is_data = export.get("is_data", False)
        if is_data:
            lines.append(f"    {name} @{ordinal} DATA")
        else:
            lines.append(f"    {name} @{ordinal}")
    lines.append("")
    return "\n".join(lines)


def main() -> None:
    arguments = parse_arguments()
    modules = []
    errors: list[str] = []
    def_dir = arguments.def_dir or arguments.output.parent

    for module_name, (relative_directory, required_count) in MODULES.items():
        directory = arguments.root / relative_directory
        functions = read_functions(directory / "function_index.csv")
        ordinals, symbol_names, data_addresses = read_symbols(directory / "symbols.csv")
        prototypes = read_prototypes(directory / f"{relative_directory.name}_unified.h")
        exports = []
        for ordinal in range(1, required_count + 1):
            address = ordinals.get(ordinal)
            function_name = functions.get(address) if address is not None else None
            if function_name is None and address is not None:
                function_name = symbol_names.get(address)
            if address is None or function_name is None:
                errors.append(f"{module_name} ordinal {ordinal} has no resolved symbol.")
                continue

            is_data = (address in data_addresses and address not in functions)
            if is_data:
                exports.append({
                    "ordinal": ordinal,
                    "address": f"0x{address:08x}",
                    "function": function_name,
                    "prototype": f"extern void *{function_name};",
                    "calling_convention": "DATA",
                    "calling_convention_inferred": False,
                    "is_data": True,
                })
            else:
                prototype = prototypes.get(function_name or "")
                if prototype is None:
                    errors.append(f"{module_name} ordinal {ordinal} ({function_name}) has no typed export prototype.")
                    continue
                typed, convention, inferred = normalize_prototype(prototype)
                exports.append({
                    "ordinal": ordinal,
                    "address": f"0x{address:08x}",
                    "function": function_name,
                    "prototype": typed,
                    "calling_convention": convention,
                    "calling_convention_inferred": inferred,
                    "is_data": False,
                })

        modules.append({
            "module": module_name,
            "required_ordinals": required_count,
            "exports": exports,
        })

        if def_dir is not None:
            def_dir.mkdir(parents=True, exist_ok=True)
            stem = Path(module_name).stem.lower()
            def_path = def_dir / f"{stem}.def"
            def_path.write_text(generate_def_file(module_name, exports), encoding="utf-8")

    manifest = {
        "schema_version": 1,
        "modules": modules,
        "fatal_errors": errors,
    }
    arguments.output.parent.mkdir(parents=True, exist_ok=True)
    arguments.output.write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    if errors:
        raise SystemExit("\n".join(errors))


if __name__ == "__main__":
    main()
