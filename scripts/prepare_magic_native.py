#!/usr/bin/env python3
"""Prepare the recovered MAGIC.EXE source for the native build."""

from __future__ import annotations

import argparse
import csv
import re
from pathlib import Path


GLOBAL_MARKER = "\n/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */"
CRT_MARKER = "\nsize_t __cdecl strlen(char *str_1)"
DECOMPRESSOR_MARKER = "\nvoid __fastcall FUN_0070d000"
ADDRESS_PATTERN = re.compile(r"(?:^|_)([0-9a-fA-F]{8})$")
FUNCTION_PROTOTYPE = re.compile(
    r"^.*?\b([A-Za-z_][A-Za-z0-9_]*)\([^;\n]*\);$"
)
GLOBAL_DECLARATION = re.compile(r"^(.*?\b)([^\s;]+);\s*$")
SHADOWED_PARAMETERS = {
    "Ai_PenalizeCounterattack": {"x"},
    "FUN_00492cb1": {"y"},
    "Pic_Subsystem_0044e2e7": {"y"},
    "Prompts_Load_004fe67f": {"flags"},
}
PREFERRED_GLOBAL_TYPES = {
    "DAT_00625178": "int ",
    "DAT_0062517c": "int *",
}
HOST_REPLACED_FUNCTIONS = {
    "GetSaveFileNameA",
    "MCIWndCreateA",
}


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--source", required=True, type=Path)
    parser.add_argument("--header", required=True, type=Path)
    parser.add_argument("--symbols", required=True, type=Path)
    parser.add_argument("--output-source", required=True, type=Path)
    parser.add_argument("--output-header", required=True, type=Path)
    return parser.parse_args()


def safe_name(name: str) -> str:
    result = re.sub(r"[^A-Za-z0-9_]", "_", name)
    if not result or result[0].isdigit():
        result = "MAGIC_DATA_" + result
    return result


def load_symbols(path: Path) -> tuple[dict[str, int], int, int]:
    lines = path.read_text(encoding="utf-8").splitlines()
    if len(lines) < 4:
        raise ValueError(f"The symbol file is incomplete: {path}")

    metadata = next(csv.reader([lines[1]]))
    image_base = int(metadata[0], 16)
    image_size = int(metadata[2], 10)
    symbols: dict[str, int] = {}
    for row in csv.DictReader(lines[2:]):
        if row["Primary"].lower() != "true":
            continue
        name = safe_name(row["Name"])
        symbols.setdefault(name, int(row["Address"], 16))
    return symbols, image_base, image_size


def function_names(header: str) -> set[str]:
    names: set[str] = set()
    for line in header.splitlines():
        match = FUNCTION_PROTOTYPE.match(line)
        if match:
            names.add(match.group(1))
    return names


def normalize_parameters(parameters: str) -> str:
    if not parameters.strip():
        return parameters

    seen: dict[str, int] = {}
    result: list[str] = []
    for parameter in parameters.split(","):
        match = re.search(r"([A-Za-z_][A-Za-z0-9_]*)\s*$", parameter)
        if not match or not parameter[: match.start()].strip():
            result.append(parameter)
            continue
        name = match.group(1)
        type_text = parameter[: match.start()]
        if "*" not in type_text:
            type_text = re.sub(
                r"\b(?:bool|byte|char|sbyte|short|undefined1|undefined2|ushort)\b",
                "int",
                type_text,
            )
            parameter = type_text + parameter[match.start() :]
            match = re.search(r"([A-Za-z_][A-Za-z0-9_]*)\s*$", parameter)
            assert match is not None
            name = match.group(1)
        seen[name] = seen.get(name, 0) + 1
        if seen[name] > 1:
            parameter = (
                parameter[: match.start()]
                + f"{name}_{seen[name]}"
                + parameter[match.end() :]
            )
        result.append(parameter)
    return ",".join(result)


def prepare_header(raw_header: str, names: set[str]) -> str:
    text = raw_header.replace("#define code   void", "typedef uintptr_t code();")
    text = text.replace("typedef ulong DWORD;", "typedef uint32_t DWORD;")
    text = text.replace("typedef long LONG;", "typedef int32_t LONG;")
    text = text.replace("typedef long LONG_PTR;", "typedef intptr_t LONG_PTR;")
    text = text.replace("typedef uint size_t;", "typedef uintptr_t size_t;")
    text = text.replace("typedef long clock_t;", "typedef intptr_t clock_t;")

    output: list[str] = [
        "#ifndef SHANDALAR_GENERATED_MAGIC_NATIVE_H\n",
        "#define SHANDALAR_GENERATED_MAGIC_NATIVE_H\n\n",
        "#include <stdbool.h>\n",
        "#include <stdint.h>\n\n",
        "typedef uint32_t pointer32;\n",
        "typedef int32_t int3;\n",
        "typedef uint32_t uint3;\n",
        "typedef signed char sbyte;\n",
        "typedef unsigned long long ulonglong;\n",
        "typedef char *string;\n",
        "typedef void *pointer;\n",
        "typedef int _func_4879(void);\n\n",
    ]

    for line in text.splitlines(keepends=True):
        match = FUNCTION_PROTOTYPE.match(line.rstrip("\n"))
        if match and match.group(1) in names:
            output.append(f"uintptr_t {match.group(1)}();\n")
            continue
        output.append(line)

    output.extend(
        [
            "\nint magic_native_load_image(const char *path);\n",
            "void magic_native_set_arguments(int argc, char **argv);\n",
            "int magic_native_run(void);\n",
            "\n#endif\n",
        ]
    )
    return "".join(output)


def address_from_name(name: str, symbols: dict[str, int]) -> int | None:
    if name in symbols:
        return symbols[name]
    match = ADDRESS_PATTERN.search(name)
    if match:
        return int(match.group(1), 16)
    return None


def macro_for_global(prefix: str, name: str, address: int) -> str:
    lowered = prefix.lower()
    if name.startswith("s_"):
        return f"#define {name} ((char *)MAGIC_HOST_ADDRESS(0x{address:08x}u))\n"
    if name.startswith("PTR_") or "*" in prefix or any(
        token in prefix
        for token in (
            "HANDLE",
            "HWND",
            "HDC",
            "HGDIOBJ",
            "HINSTANCE",
            "HPALETTE",
            "HBITMAP",
            "HFONT",
            "HBRUSH",
            "HMODULE",
            "FARPROC",
            "pointer",
            "string",
            "code",
        )
    ):
        native_type = prefix.strip()
        if native_type == "pointer":
            native_type = "void *"
        elif native_type == "string":
            native_type = "char *"
        if native_type == "code *":
            return f"#define {name} MAGIC_CODE_SLOT(0x{address:08x}u)\n"
        return (
            f"#define {name} "
            f"MAGIC_POINTER({native_type}, 0x{address:08x}u)\n"
        )
    elif "undefined8" in lowered or "longlong" in lowered:
        accessor = "MAGIC_U64"
    elif "undefined2" in lowered or "ushort" in lowered or "word" in lowered:
        accessor = "MAGIC_U16"
    elif re.search(r"\b(short)\b", lowered):
        accessor = "MAGIC_I16"
    elif any(token in lowered for token in ("undefined1", "byte", "uchar")):
        accessor = "MAGIC_U8"
    elif re.search(r"\b(char|sbyte|undefined)\b", lowered):
        accessor = "MAGIC_I8"
    elif re.search(r"\b(int|long)\b", lowered) and not any(
        token in lowered for token in ("uint", "ulong", "undefined4", "dword", "dword")
    ):
        accessor = "MAGIC_I32"
    else:
        accessor = "MAGIC_U32"
    return f"#define {name} {accessor}(0x{address:08x}u)\n"


def pointer_type(prefix: str, name: str) -> str | None:
    if not (
        name.startswith("PTR_")
        or "*" in prefix
        or any(
            token in prefix
            for token in (
                "HANDLE",
                "HWND",
                "HDC",
                "HGDIOBJ",
                "HINSTANCE",
                "HPALETTE",
                "HBITMAP",
                "HFONT",
                "HBRUSH",
                "HMODULE",
                "FARPROC",
                "pointer",
                "string",
                "code",
            )
        )
    ):
        return None
    result = prefix.strip()
    if result == "pointer":
        return "void *"
    if result == "string":
        return "char *"
    return result


def prepare_globals(
    raw_globals: str,
    body: str,
    names: set[str],
    symbols: dict[str, int],
) -> tuple[str, str]:
    declarations: dict[str, tuple[str, int]] = {}
    called_globals = set(
        re.findall(r"\(\*\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)\s*\(", body)
    )
    for line in raw_globals.splitlines():
        match = GLOBAL_DECLARATION.match(line)
        if not match or line.lstrip().startswith(("#", "/*", "*")):
            continue
        prefix, original_name = match.groups()
        name = safe_name(original_name)
        if name in names or name in declarations:
            continue
        address = address_from_name(name, symbols)
        if address is not None:
            if name in called_globals:
                prefix = "code *"
            declarations[name] = (prefix, address)

    # Ghidra uses these operator characters in three recovered string names.
    body = body.replace("s___nScan<10_00525d00", "s___nScan_10_00525d00")
    body = body.replace("s_ScWilly>_0_0052ce44", "s_ScWilly__0_0052ce44")
    body = body.replace("s_File_>__s__Line_>__d_00530ff0", "s_File____s__Line____d_00530ff0")
    body = body.replace("s_File_>__s__Line_>__d_00531068", "s_File____s__Line____d_00531068")

    referenced = set(re.findall(r"\b(?:_?DAT|iRam)[_0-9a-fA-F]*\b", body))
    referenced.update(re.findall(r"\b(_[A-Za-z_][A-Za-z0-9_]*)\b", body))
    for reference in sorted(referenced):
        candidate = reference
        if candidate in declarations:
            continue
        if candidate.startswith("iRam") and len(candidate) == 12:
            address = int(candidate[4:], 16)
            declarations[candidate] = ("int ", address)
            continue
        if candidate.startswith("_") and candidate[1:] in declarations:
            declarations[candidate] = declarations[candidate[1:]]
            continue
        if candidate.startswith("_"):
            continue
        address = address_from_name(candidate, symbols)
        if address is not None:
            declarations[candidate] = ("undefined4 ", address)

    for name, prefix in PREFERRED_GLOBAL_TYPES.items():
        if name in declarations:
            declarations[name] = (prefix, declarations[name][1])

    pointer_info = {
        name: (native_type, address)
        for name, (prefix, address) in declarations.items()
        if (native_type := pointer_type(prefix, name)) is not None
    }
    if pointer_info:
        pointer_names = "|".join(
            re.escape(name) for name in sorted(pointer_info, key=len, reverse=True)
        )
        table_index = r"((?:[^\[\]\n]|\[[^\[\]\n]*\])+)"
        table_assignment = re.compile(
            rf"\(&({pointer_names})\)\[{table_index}\](\s*)=(?!=)"
        )

        def replace_table_assignment(match: re.Match[str]) -> str:
            _, address = pointer_info[match.group(1)]
            return (
                f"MAGIC_U32(0x{address:08x}u + "
                f"((uint32_t)({match.group(2)}) * 4u)){match.group(3)}="
            )

        body = table_assignment.sub(replace_table_assignment, body)
        table_read = re.compile(rf"\(&({pointer_names})\)\[{table_index}\]")

        def replace_table_read(match: re.Match[str]) -> str:
            native_type, address = pointer_info[match.group(1)]
            if native_type == "code *":
                return (
                    f"MAGIC_CODE_SLOT(0x{address:08x}u + "
                    f"((uint32_t)({match.group(2)}) * 4u))"
                )
            return (
                f"MAGIC_POINTER_AT({native_type}, 0x{address:08x}u, "
                f"({match.group(2)}))"
            )

        body = table_read.sub(replace_table_read, body)
        direct_assignment = re.compile(
            rf"(?<!\*)\b({pointer_names})(\s*)=(?!=)"
        )

        def replace_direct_assignment(match: re.Match[str]) -> str:
            _, address = pointer_info[match.group(1)]
            return f"MAGIC_U32(0x{address:08x}u){match.group(2)}="

        body = direct_assignment.sub(replace_direct_assignment, body)
        address_of = re.compile(rf"&({pointer_names})\b(?!\s*\[)")

        def replace_address_of(match: re.Match[str]) -> str:
            native_type, address = pointer_info[match.group(1)]
            return f"(({native_type} *)MAGIC_HOST_ADDRESS(0x{address:08x}u))"

        body = address_of.sub(replace_address_of, body)

    output = [
        "#define MAGIC_U8(address) (*(uint8_t *)MAGIC_HOST_ADDRESS(address))\n",
        "#define MAGIC_I8(address) (*(int8_t *)MAGIC_HOST_ADDRESS(address))\n",
        "#define MAGIC_U16(address) (*(uint16_t *)MAGIC_HOST_ADDRESS(address))\n",
        "#define MAGIC_I16(address) (*(int16_t *)MAGIC_HOST_ADDRESS(address))\n",
        "#define MAGIC_U32(address) (*(uint32_t *)MAGIC_HOST_ADDRESS(address))\n",
        "#define MAGIC_I32(address) (*(int32_t *)MAGIC_HOST_ADDRESS(address))\n",
        "#define MAGIC_U64(address) (*(uint64_t *)MAGIC_HOST_ADDRESS(address))\n",
    ]
    for name, (prefix, address) in sorted(declarations.items()):
        output.append(macro_for_global(prefix, name, address))
    return "".join(output), body


def prepare_body(body: str, names: set[str]) -> str:
    body = re.sub(
        r"\b([A-Za-z_][A-Za-z0-9_]*)\._([0-9]+)_([0-9]+)_",
        r"MAGIC_PART(\1, \2, \3)",
        body,
    )

    signature_pattern = re.compile(
        r"(?m)^(?:[A-Za-z_][A-Za-z0-9_ *]*(?: __cdecl| __fastcall| __thiscall)?)"
        r"(?:\n| )([A-Za-z_][A-Za-z0-9_]*)\s*\(([^;]*?)\)(?=\n\n\{)"
    )

    def replace_signature(match: re.Match[str]) -> str:
        name = match.group(1)
        if name not in names:
            return match.group(0)
        parameters = normalize_parameters(match.group(2))
        if parameters.strip() == "void":
            parameters = ""
        for parameter in SHADOWED_PARAMETERS.get(name, set()):
            parameters = re.sub(
                rf"\b{re.escape(parameter)}\b(?=\s*(?:,|$))",
                parameter + "_arg",
                parameters,
            )
        return f"uintptr_t {name}({parameters})"

    body = signature_pattern.sub(replace_signature, body)
    body = body.replace(
        "puVar4 = (undefined4 *)__p___argv();\n    strcpy(local_150,*(char **)*puVar4);",
        "MagicNative_CopyProgramPath(local_150,sizeof(local_150));",
    )
    body = body.replace(
        "pcVar5 = strrchr(local_150,0x5c);\n    *pcVar5 = '\\0';",
        "pcVar5 = strrchr(local_150,0x5c);\n"
        "    if (pcVar5 == (char *)0x0) pcVar5 = strrchr(local_150,0x2f);\n"
        "    if (pcVar5 != (char *)0x0) *pcVar5 = '\\0';",
    )
    callable_names = "|".join(
        re.escape(name) for name in sorted(names, key=len, reverse=True)
    )
    body = re.sub(
        rf"(MAGIC_U32\([^\n;]+\)\s*=\s*)(&?(?:{callable_names}))(\s*;)",
        lambda match: (
            match.group(1)
            + "(uint32_t)MagicNative_RegisterCallable((uintptr_t)("
            + match.group(2)
            + "))"
            + match.group(3)
        ),
        body,
    )
    body = re.sub(
        r"\(POINT\)\(CONCAT44\([^,]+,\s*(lParam)\)\s*&\s*0xffffffff0000ffff\)",
        r"MAGIC_POINT_FROM_LPARAM(\1)",
        body,
    )
    body = re.sub(
        r"\bDAT_00532804\[([^\]\n]+)\]",
        r"MAGIC_U8(0x00532804u + (uint32_t)(\1))",
        body,
    )

    pseudo_names = set(re.findall(r"\b(?:stack0x[0-9a-fA-F]+|register0x[0-9a-fA-F]+|_uStack[0-9a-fA-F]+)\b", body))
    pseudo_declarations = "".join(
        f"static uintptr_t {name};\n" for name in sorted(pseudo_names)
    )
    return pseudo_declarations + body


def host_import_declarations(body: str, names: set[str]) -> str:
    excluded = names | {
        "CONCAT11",
        "CONCAT12",
        "CONCAT22",
        "CONCAT31",
        "CONCAT44",
        "LOCK",
        "UNLOCK",
        "for",
        "if",
        "return",
        "sizeof",
        "switch",
        "while",
    }
    called_names = set(
        re.findall(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(", body)
    )
    imports = sorted(
        name
        for name in called_names - excluded
        if not name.startswith(("DAT_", "MAGIC_", "PTR_", "g_"))
    )
    return "".join(f"uintptr_t {name}();\n" for name in imports)


def remove_host_replaced_functions(body: str) -> str:
    function_pattern = re.compile(
        r"(?ms)^uintptr_t ([A-Za-z_][A-Za-z0-9_]*)\([^;]*?\)\n\n\{.*?^\}\n"
    )
    return function_pattern.sub(
        lambda match: "" if match.group(1) in HOST_REPLACED_FUNCTIONS else match.group(0),
        body,
    )


def recovered_callable_resolver(body: str, symbols: dict[str, int]) -> str:
    definitions = set(
        re.findall(r"(?m)^uintptr_t ([A-Za-z_][A-Za-z0-9_]*)\([^;]*\)\n\n\{", body)
    )
    entries: list[tuple[int, str]] = []
    for name in definitions:
        address = address_from_name(name, symbols)
        if address is not None:
            entries.append((address, name))
    lines = [
        "\nuintptr_t MagicNative_ResolveRecoveredCallable(uint32_t address)\n",
        "{\n",
        "    switch (address) {\n",
    ]
    for address, name in sorted(entries):
        lines.append(f"    case 0x{address:08x}u: return (uintptr_t)&{name};\n")
    lines.extend(["    default: return 0;\n", "    }\n", "}\n"])
    return "".join(lines)


def main() -> None:
    arguments = parse_arguments()
    raw_header = arguments.header.read_text(encoding="utf-8")
    raw_source = arguments.source.read_text(encoding="utf-8")
    names = function_names(raw_header)
    symbols, image_base, image_size = load_symbols(arguments.symbols)

    raw_globals, body = raw_source.split(GLOBAL_MARKER, 1)
    body = GLOBAL_MARKER + body
    if CRT_MARKER in body:
        body = body.split(CRT_MARKER, 1)[0]
    if DECOMPRESSOR_MARKER in raw_source:
        body += raw_source[raw_source.index(DECOMPRESSOR_MARKER) :]

    generated_header = prepare_header(raw_header, names)
    globals_text, body = prepare_globals(raw_globals, body, names, symbols)
    body = prepare_body(body, names)
    body = remove_host_replaced_functions(body)
    body = body.replace('#include "magic_unified.h"\n', "")
    imports_text = host_import_declarations(body, names)
    resolver_text = recovered_callable_resolver(body, symbols)

    source_preamble = f"""/* This file is generated. Do not edit it. */
#include "magic_native.h"

#define MAGIC_IMAGE_BASE 0x{image_base:08x}u
#define MAGIC_IMAGE_SIZE {image_size}u
#define MAGIC_HOST_ADDRESS(address) MagicNative_GlobalAddress((uint32_t)(address))
#define MAGIC_POINTER(type, address) ((type)MagicNative_HostPointer(MAGIC_U32(address)))
#define MAGIC_POINTER_AT(type, address, index) ((type)MagicNative_HostPointer(MAGIC_U32((address) + ((uint32_t)(index) * 4u))))
#define MAGIC_CODE_SLOT(address) ((code *)(uintptr_t)MagicNative_ResolveCallable(MAGIC_U32(address)))
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
#define malloc MagicNative_Malloc
#define free MagicNative_Free
#define _expand MagicNative_Realloc
#define _msize MagicNative_AllocationSize
#define fopen MagicNative_Fopen
#define fclose MagicNative_Fclose
#define fread MagicNative_Fread
#define fwrite MagicNative_Fwrite
#define fseek MagicNative_Fseek
#define ftell MagicNative_Ftell
#define fgets MagicNative_Fgets
#define fgetc MagicNative_Fgetc
#define fprintf MagicNative_Fprintf
#define fscanf MagicNative_Fscanf
#define GetProcAddress MagicNative_GetProcAddress
#define LoadBitmapA MagicNative_LoadBitmapA
#define __p___argv MagicNative_ArgvSlot
#define __p___mb_cur_max MagicNative_MbCurMax
#define __p__pctype MagicNative_Pctype
#define _atexit MagicNative_AtExit
#define _errno MagicNative_Errno
#define _isctype MagicNative_Isctype
#define _itoa MagicNative_Itoa
#define _strlwr MagicNative_Strlwr
#define _splitpath MagicNative_SplitPath
#define _vsnprintf MagicNative_Vsnprintf
#define assert MagicNative_Assert
#define _open MagicNative_Open
#define _close close
#define _read read
#define _write write
#define _lseek lseek
#define _tell MagicNative_Tell
#define _filelength MagicNative_FileLength
#define _fileno MagicNative_Fileno
#define _getcwd getcwd
#define _chdir chdir
#define _mkdir MagicNative_Mkdir
#define _stricmp strcasecmp
#define _strcmpi strcasecmp
#define _strnicmp strncasecmp

uintptr_t MagicNative_ResolveCallable();
uintptr_t MagicNative_RegisterCallable();
uintptr_t MagicNative_HostPointer();
uintptr_t MagicNative_GlobalAddress();
uintptr_t MagicNative_CopyProgramPath();
uintptr_t MagicNative_Malloc();
uintptr_t MagicNative_Free();
uintptr_t MagicNative_Realloc();
uintptr_t MagicNative_AllocationSize();

"""

    arguments.output_header.parent.mkdir(parents=True, exist_ok=True)
    arguments.output_source.parent.mkdir(parents=True, exist_ok=True)
    arguments.output_header.write_text(generated_header, encoding="utf-8")
    arguments.output_source.write_text(
        source_preamble + imports_text + "\n" + globals_text + "\n" + body + resolver_text,
        encoding="utf-8",
    )


if __name__ == "__main__":
    main()
