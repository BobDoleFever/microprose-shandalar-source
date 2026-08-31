#!/usr/bin/env python3
"""Generate recovered source and ABI audit for companion PE modules (DLLs and EXEs)."""

from __future__ import annotations

import argparse
import csv
import json
import re
from pathlib import Path

import prepare_magic_native as native
import prepare_magic_pe as magic_pe


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--module", required=True, help="Module name, e.g. statwin, magsnd, magvid, deckdll, duel, deck")
    parser.add_argument("--source", required=True, type=Path)
    parser.add_argument("--header", required=True, type=Path)
    parser.add_argument("--symbols", required=True, type=Path)
    parser.add_argument("--output-dir", required=True, type=Path)
    parser.add_argument(
        "--compat-header",
        type=Path,
        default=Path("include/shandalar/win32_compat.h"),
    )
    parser.add_argument("--is-dll", action="store_true")
    return parser.parse_args()


def load_module_symbols(path: Path) -> tuple[dict[str, int], int, int]:
    if not path.exists():
        return {}, 0x10000000, 0
    lines = path.read_text(encoding="utf-8").splitlines()
    if not lines:
        return {}, 0x10000000, 0

    # If format has ImageBase header (from ExportPeImage)
    if lines[0].startswith("ImageBase,"):
        metadata = next(csv.reader([lines[1]]))
        image_base = int(metadata[0], 16)
        image_size = int(metadata[2], 10)
        symbols: dict[str, int] = {}
        for row in csv.DictReader(lines[2:]):
            if row.get("Primary", "").lower() != "true":
                continue
            name = native.safe_name(row["Name"])
            symbols.setdefault(name, int(row["Address"], 16))
        return symbols, image_base, image_size

    # Standard symbols.csv from decompiler
    symbols: dict[str, int] = {}
    min_address = None
    max_address = None
    for row in csv.DictReader(lines):
        raw_address = row["Address"]
        if raw_address.startswith("EXTERNAL:") or not re.match(r"^[0-9a-fA-F]+$", raw_address):
            continue
        address = int(raw_address, 16)
        name = row["SymbolName"]
        if min_address is None or address < min_address:
            min_address = address
        if max_address is None or address > max_address:
            max_address = address
        clean_name = native.safe_name(name)
        symbols.setdefault(clean_name, address)

    image_base = min_address if min_address is not None else 0x10000000
    image_size = (max_address - min_address + 1) if (min_address and max_address) else 0
    return symbols, image_base, image_size


EXTRA_CRT_IMPORTS = {
    "realloc", "strncpy", "_vsnprintf", "_onexit", "qsort", "strtok", "strtol", "strtoul",
}

EXTRA_MACROS = """
#define free_dbg(p, t) free(p)
#define malloc_dbg(s, t, f, l) malloc(s)
#define _CrtDbgReport(...) 0
#define _CrtCheckMemory() 1
#define _CrtIsValidHeapPointer(p) 1
#define _BLOCK_TYPE(t) (t)
#define _BLOCK_TYPE_IS_VALID(t) 1
#define _I10_OUTPUT(...) 0
#define _T(x) x
#define swi(x) ((void)0)
#define CONCAT13(high, low) ((((uint32_t)(uint8_t)(high)) << 24) | ((uint32_t)(low) & 0xffffffu))
#define CONCAT14(high, low) ((((uint64_t)(uint8_t)(high)) << 32) | ((uint64_t)(uint32_t)(low)))
#define CARRY4(a, b) (((uint32_t)(a) + (uint32_t)(b)) < (uint32_t)(a))
#define SUB41(a, b) ((uint8_t)((uint32_t)(a) >> ((b) * 8)))
#define __CRT_INIT_12() 1
"""


def main() -> None:
    args = parse_arguments()
    mod_name = args.module.lower()
    mod_prefix = args.module.capitalize()

    raw_header = args.header.read_text(encoding="utf-8")
    raw_source = args.source.read_text(encoding="utf-8")

    # Normalize decompiler name quirks
    raw_header = raw_header.replace("FID_conflict:_$E31", "FUN_100027ff")
    raw_source = raw_source.replace("FID_conflict:_$E31", "FUN_100027ff")
    raw_source = raw_source.replace("FID_conflict___E31", "FUN_100027ff")
    raw_source = raw_source.replace("FID_conflict__E31", "FUN_100027ff")
    raw_source = raw_source.replace("FID_conflict_E31", "FUN_100027ff")

    names = native.function_names(raw_header)
    symbols, image_base, image_size = load_module_symbols(args.symbols)

    if native.GLOBAL_MARKER in raw_source:
        raw_globals, body = raw_source.split(native.GLOBAL_MARKER, 1)
        body = native.GLOBAL_MARKER + body
    else:
        raw_globals, body = "", raw_source

    if native.CRT_MARKER in body:
        body = body.split(native.CRT_MARKER, 1)[0]
    if native.DECOMPRESSOR_MARKER in raw_source:
        body += raw_source[raw_source.index(native.DECOMPRESSOR_MARKER):]

    # Resolve FID conflicts in source
    body = re.sub(r"\bFID_conflict___", "__", body)
    body = re.sub(r"\bFID_conflict__", "_", body)
    body = re.sub(r"\bFID_conflict_", "", body)
    body = re.sub(r"\bFUN_101cdebc\s*\(", "MAGIC_NATIVE_CALL(FUN_101cdebc)(", body)

    header = magic_pe.prepare_header(raw_header, names)
    header = header.replace("SHANDALAR_GENERATED_MAGIC_PE_H", f"SHANDALAR_GENERATED_{mod_name.upper()}_PE_H")
    header = header.replace("MagicRecovered_WinMain", f"{mod_prefix}Recovered_WinMain")
    header = header.replace("MagicPe_LookupSymbolName", f"{mod_prefix}Pe_LookupSymbolName")

    globals_text, body = native.prepare_globals(raw_globals, body, names, symbols)
    body = native.prepare_body(body, names)
    body = native.remove_host_replaced_functions(body)
    body = re.sub(rf'#include\s+"{mod_name}_unified\.h"\n', "", body)
    resolver = native.recovered_callable_resolver(body, symbols)

    body = re.sub(r"(?m)^uintptr_t ([A-Za-z_][A-Za-z0-9_]*)\(", r"uintptr_t __cdecl \1(", body)
    body = body.replace("MagicNative_", f"{mod_prefix}Pe_")
    resolver = resolver.replace("MagicNative_", f"{mod_prefix}Pe_")
    body, resolved_indirect_calls = magic_pe.replace_data_indirect_calls(body)
    body, callbacks = magic_pe.replace_callbacks(body, names)
    body = magic_pe.add_fallthrough_returns(body)

    prototypes = magic_pe.function_statements(args.compat_header)
    prototypes.setdefault("LoadBitmapA", "HBITMAP LoadBitmapA(HINSTANCE instance, LPCSTR name);")
    prototypes.setdefault("InitCommonControls", "void InitCommonControls(void);")

    all_crt = magic_pe.CRT_IMPORTS | EXTRA_CRT_IMPORTS
    calls = magic_pe.called_names(body) - names
    win32_names = calls & prototypes.keys()
    crt_names = calls & all_crt
    excluded = magic_pe.RUNTIME_IMPORTS | {
        "CONCAT11", "CONCAT12", "CONCAT13", "CONCAT14", "CONCAT22", "CONCAT31", "CONCAT44",
        "CARRY4", "SUB41", "_T", "swi", "free_dbg", "malloc_dbg", "_CrtDbgReport",
        "_CrtCheckMemory", "_CrtIsValidHeapPointer", "_BLOCK_TYPE", "_BLOCK_TYPE_IS_VALID",
        "_I10_OUTPUT", "__CRT_INIT_12",
        "LOCK", "MAGIC_CALL", "MAGIC_NATIVE_CALL", "MAGIC_CODE_SLOT",
        "MAGIC_HOST_ADDRESS", "MAGIC_PART",
        "MAGIC_POINTER", "MAGIC_POINTER_AT", "MAGIC_POINT_FROM_LPARAM",
        "MAGIC_U8", "MAGIC_I8", "MAGIC_U16", "MAGIC_I16", "MAGIC_U32",
        "MAGIC_I32", "MAGIC_U64", "UNLOCK",
        f"{mod_prefix}Pe_RegisterCallable", f"{mod_prefix}Pe_ResolveCallable",
        f"{mod_prefix}Pe_GlobalAddress", f"{mod_prefix}Pe_LookupSymbolName",
        "for", "if", "return", "sizeof", "switch", "while", "case", "hs", "n", "s", "block",
    }
    unresolved = calls - win32_names - crt_names - excluded

    import_lines = [
        f"#ifndef SHANDALAR_GENERATED_{mod_name.upper()}_PE_IMPORTS_H\n",
        f"#define SHANDALAR_GENERATED_{mod_name.upper()}_PE_IMPORTS_H\n\n",
    ]
    for name in sorted(win32_names):
        import_lines.append(magic_pe.add_calling_convention(prototypes[name], name) + "\n")
    import_lines.extend(
        [
            f"uintptr_t __cdecl {mod_prefix}Pe_GlobalAddress(uint32_t address);\n",
            f"uintptr_t __cdecl {mod_prefix}Pe_ResolveCallable(uint32_t address);\n",
            f"uintptr_t __cdecl {mod_prefix}Pe_RegisterCallable(uintptr_t function_address);\n",
            f"const char *{mod_prefix}Pe_LookupSymbolName(uint32_t address);\n",
            "HMODULE WINAPI MagicPe_LoadLibraryA(LPCSTR name);\n",
            "FARPROC WINAPI MagicPe_GetProcAddress(HMODULE module, LPCSTR name);\n",
        ]
    )
    for kind, name in sorted(callbacks):
        import_lines.append(magic_pe.trampoline_declaration(kind, name) + "\n")
    import_lines.append("\n#endif\n")
    import_header = "".join(import_lines)

    source_preamble = f"""/* This file is generated. Do not edit it. */
#include "{mod_name}_pe.h"
#include "{mod_name}_pe_imports.h"

_Static_assert(sizeof(void *) == 4, "{mod_name.upper()} requires 32-bit pointers.");
_Static_assert(sizeof(uintptr_t) == 4, "{mod_name.upper()} requires 32-bit uintptr_t.");

#define {mod_name.upper()}_IMAGE_BASE 0x{image_base:08x}u
#define {mod_name.upper()}_IMAGE_SIZE {image_size}u
#define MAGIC_HOST_ADDRESS(address) {mod_prefix}Pe_GlobalAddress((uint32_t)(address))
#define MAGIC_POINTER(type, address) ((type)(uintptr_t)MAGIC_U32(address))
#define MAGIC_POINTER_AT(type, address, index) ((type)(uintptr_t)MAGIC_U32((address) + ((uint32_t)(index) * 4u)))
#define MAGIC_CODE_SLOT(address) ((code *)(uintptr_t){mod_prefix}Pe_ResolveCallable(MAGIC_U32(address)))
#define MAGIC_CALL(address) ((uintptr_t (__cdecl *)())(uintptr_t){mod_prefix}Pe_ResolveCallable(MAGIC_U32(address)))
#define MAGIC_NATIVE_CALL(pointer) ((uintptr_t (__cdecl *)())(uintptr_t){mod_prefix}Pe_ResolveCallable((uint32_t)(uintptr_t)(pointer)))
#define MAGIC_PART_1(value, offset) (*(uint8_t *)((uint8_t *)&(value) + (offset)))
#define MAGIC_PART_2(value, offset) (*(uint16_t *)((uint8_t *)&(value) + (offset)))
#define MAGIC_PART_3(value, offset) (*(uint3 *)((uint8_t *)&(value) + (offset)))
#define MAGIC_PART_4(value, offset) (*(uint32_t *)((uint8_t *)&(value) + (offset)))
#define MAGIC_PART(value, offset, size) MAGIC_PART_##size(value, offset)
#define MAGIC_POINT_FROM_LPARAM(value) ((POINT){{(LONG)((uintptr_t)(value) & 0xffff), (LONG)(((uintptr_t)(value) >> 16) & 0xffff)}})
#define CONCAT11(high, low) ((((uint16_t)(uint8_t)(high)) << 8) | (uint8_t)(low))
#define CONCAT12(high, low) ((((uint32_t)(uint8_t)(high)) << 16) | (uint16_t)(low))
#define CONCAT22(high, low) ((((uint32_t)(uint16_t)(high)) << 16) | (uint16_t)(low))
#define CONCAT31(high, low) ((((uint32_t)(high)) << 8) | (uint8_t)(low))
#define CONCAT44(high, low) ((((uint64_t)(uint32_t)(high)) << 32) | (uint32_t)(low))
#define LOCK() ((void)0)
#define UNLOCK() ((void)0)
{EXTRA_MACROS}
"""

    host_calls = magic_pe.called_names(body) - names - win32_names - magic_pe.RUNTIME_IMPORTS
    host_declarations = "".join(
        f"uintptr_t {name}();\n"
        for name in sorted(host_calls)
        if name in crt_names
    )

    trampoline_source = [
        "/* This file is generated. Do not edit it. */\n",
        f'#include "{mod_name}_pe.h"\n',
        f'#include "{mod_name}_pe_imports.h"\n\n',
    ]
    for kind, name in sorted(callbacks):
        trampoline_source.append(magic_pe.trampoline_definition(kind, name) + "\n")

    callable_source = (
        "/* This file is generated. Do not edit it. */\n"
        f'#include "{mod_name}_pe.h"\n'
        + resolver
        + "\n"
        + magic_pe.generate_symbol_table(symbols).replace("MagicPe_", f"{mod_prefix}Pe_").replace("g_MagicPe_", f"g_{mod_prefix}Pe_")
    )

    audit = {
        "schema_version": 1,
        "module": args.module,
        "target": "i686-w64-mingw32",
        "image_base": f"0x{image_base:08x}",
        "image_size": image_size,
        "is_dll": args.is_dll,
        "counts": {
            "callbacks": len(callbacks),
            "crt_imports": len(crt_names),
            "recovered_functions": len(names),
            "resolved_indirect_calls": resolved_indirect_calls,
            "unresolved_imports": len(unresolved),
            "win32_imports": len(win32_names),
        },
        "fatal_errors": [f"Unresolved imports: {', '.join(sorted(unresolved))}"] if unresolved else [],
        "unresolved_imports": sorted(unresolved),
    }

    out = args.output_dir
    out.mkdir(parents=True, exist_ok=True)
    (out / f"{mod_name}_pe.h").write_text(header, encoding="utf-8")
    (out / f"{mod_name}_pe_imports.h").write_text(import_header, encoding="utf-8")
    (out / f"{mod_name}_pe.c").write_text(
        source_preamble + host_declarations + "\n" + globals_text + "\n" + body,
        encoding="utf-8",
    )
    (out / f"{mod_name}_callable_map.c").write_text(callable_source, encoding="utf-8")
    (out / f"{mod_name}_callback_trampolines.c").write_text(
        "".join(trampoline_source), encoding="utf-8"
    )
    (out / f"{mod_name}_pe_audit.json").write_text(
        json.dumps(audit, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    (out / f"{mod_name}_pe_audit.md").write_text(magic_pe.audit_markdown(audit), encoding="utf-8")


if __name__ == "__main__":
    main()
