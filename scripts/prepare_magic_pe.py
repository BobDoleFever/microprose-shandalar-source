#!/usr/bin/env python3
"""Generate the recovered MAGIC source for a 32-bit Windows PE build."""

from __future__ import annotations

import argparse
import json
import re
import zlib
from pathlib import Path

import prepare_magic_native as native


CALLBACK_ARGUMENTS = {
    "DialogBoxParamA": (3, "dialog"),
    "CreateThread": (2, "thread"),
    "timeSetEvent": (2, "time"),
    "EnumChildWindows": (1, "enum"),
    "EnumWindows": (0, "enum"),
    "EnumFontFamiliesA": (2, "enum"),
    "SetTimer": (3, "timer"),
    "SetWindowsHookExA": (1, "hook"),
}

CRT_IMPORTS = {
    "__p___mb_cur_max", "__p__pctype", "_atexit", "_chdir", "_close",
    "_controlfp", "_errno", "_expand", "_filelength", "_fileno", "_getcwd",
    "_isctype", "_itoa", "_lseek", "_mkdir", "_msize", "_open", "_read",
    "_splitpath", "_strcmpi", "_stricmp", "_strlwr", "_strnicmp", "_tell",
    "_vsnprintf", "_write", "abs", "atoi", "bsearch", "clock", "ctime", "exit", "fclose",
    "feof", "fgetc", "fgets", "fopen", "fprintf", "fread", "free", "fscanf", "fseek",
    "ftell", "fwrite", "malloc", "memchr", "memcmp", "memcpy", "memmove",
    "memset", "qsort", "rand", "realloc", "snprintf", "sprintf", "srand", "sscanf", "strcat",
    "strchr", "strcmp", "strcpy", "strcspn", "strlen", "strncat", "strncmp",
    "strncpy", "strrchr", "strspn", "strtok", "strtol", "strtoul", "time", "tolower",
}

RUNTIME_IMPORTS = {
    "MagicPe_Address", "MagicPe_Assert", "MagicPe_GetProcAddress",
    "MagicPe_LoadLibraryA", "MagicPe_RegisterCallable", "MagicPe_ResolveCallable",
    "MagicPe_LookupSymbolName", "MagicPe_StackProbe", "MagicPe_AllShl",
    "MagicRecovered_WinMain", "assert", "__allshl", "Mem_AllocOrFree_00513bd0",
}

HOST_REPLACED_FUNCTIONS = {
    "GetSaveFileNameA",
    "MCIWndCreateA",
    "DeckBuilderMain",
    "__dllonexit",
    "initterm",
}


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--source", required=True, type=Path)
    parser.add_argument("--header", required=True, type=Path)
    parser.add_argument("--symbols", required=True, type=Path)
    parser.add_argument("--output-dir", required=True, type=Path)
    parser.add_argument(
        "--compat-header",
        type=Path,
        default=Path("include/shandalar/win32_compat.h"),
    )
    parser.add_argument(
        "--ordinals",
        type=Path,
        default=Path("build/generated/pe32/magic_module_ordinals.json"),
    )
    parser.add_argument(
        "--image",
        type=Path,
        default=Path("build/generated/magic_image.bin"),
    )
    return parser.parse_args()


def load_companion_prototypes(ordinals_path: Path) -> dict[str, str]:
    if not ordinals_path.exists():
        return {
            "DeckBuilderMain": "WPARAM __cdecl DeckBuilderMain(HWND hwnd, uint32_t arg_2, int32_t arg_3);",
            "status_show": "void __cdecl status_show(int arg1, int arg2);",
            "status_init": "int __cdecl status_init(undefined4 *ptr_1);",
            "play_video": "int __cdecl play_video(undefined4 arg_1, undefined2 arg_2, undefined2 arg_3, byte arg_4);",
        }
    data = json.loads(ordinals_path.read_text(encoding="utf-8"))
    prototypes: dict[str, str] = {}
    for module in data.get("modules", []):
        for export in module.get("exports", []):
            name = export.get("function")
            proto = export.get("prototype")
            if name and proto and not export.get("is_data", False):
                prototypes[name] = proto
    prototypes.setdefault(
        "DeckBuilderMain",
        "WPARAM __cdecl DeckBuilderMain(HWND hwnd, uint32_t arg_2, int32_t arg_3);",
    )
    return prototypes


def prepare_header(raw_header: str, recovered_names: set[str]) -> str:
    text = raw_header.replace("#define code   void", "typedef uintptr_t code();")
    text = text.replace("typedef ulong DWORD;", "typedef uint32_t DWORD;")
    text = text.replace("typedef long LONG;", "typedef int32_t LONG;")
    text = text.replace("typedef long LONG_PTR;", "typedef intptr_t LONG_PTR;")
    text = text.replace("typedef uint size_t;", "")
    text = text.replace("typedef long clock_t;", "")

    # Strip CRT struct/typedef conflicts
    text = re.sub(r"struct\s+_iobuf\s*\{[\s\S]*?\};", "", text)
    text = re.sub(r"typedef\s+struct\s+_iobuf\s+FILE\s*;", "", text)
    text = re.sub(r"typedef\s+struct\s+_iobuf\s+_iobuf\s*;", "", text)
    text = re.sub(r"typedef\s+intptr_t\s+clock_t\s*;", "", text)
    text = re.sub(r"typedef\s+uintptr_t\s+size_t\s*;", "", text)

    output: list[str] = [
        "#ifndef SHANDALAR_GENERATED_MAGIC_PE_H\n",
        "#define SHANDALAR_GENERATED_MAGIC_PE_H\n\n",
        "#include <stdbool.h>\n",
        "#include <stdint.h>\n",
        "#include <stdio.h>\n",
        "#include <stdlib.h>\n",
        "#include <string.h>\n",
        "#include <ctype.h>\n",
        "#include <direct.h>\n",
        "#include <io.h>\n",
        "#include <time.h>\n",
        "#include <math.h>\n",
        "#include <malloc.h>\n",
        "#include <float.h>\n",
        "#include <errno.h>\n\n",
        "#ifndef WINAPI\n",
        "#define WINAPI __attribute__((stdcall))\n",
        "#endif\n",
        "#ifndef CALLBACK\n",
        "#define CALLBACK WINAPI\n",
        "#endif\n",
        "#ifndef WINAPIV\n",
        "#define WINAPIV __cdecl\n",
        "#endif\n\n",
        "typedef uint32_t pointer32;\n",
        "typedef int32_t int3;\n",
        "typedef uint32_t uint3;\n",
        "typedef signed char sbyte;\n",
        "typedef unsigned long long ulonglong;\n",
        "typedef char *string;\n",
        "typedef void *pointer;\n",
        "typedef int _func_4879(void);\n",
        "typedef uintptr_t code();\n\n",
    ]

    callback_typedefs = {
        r"typedef DWORD \(\*PTHREAD_START_ROUTINE\)\(LPVOID\);":
            "typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID);",
        r"typedef LRESULT \(\*WNDPROC\)\(HWND, UINT, WPARAM, LPARAM\);":
            "typedef LRESULT (CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);",
        r"typedef BOOL \(\*WNDENUMPROC\)\(HWND, LPARAM\);":
            "typedef BOOL (CALLBACK *WNDENUMPROC)(HWND, LPARAM);",
        r"typedef void \(\*TIMERPROC\)\(HWND, UINT, UINT_PTR, DWORD\);":
            "typedef void (CALLBACK *TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);",
        r"typedef INT_PTR \(\*DLGPROC\)\(HWND, UINT, WPARAM, LPARAM\);":
            "typedef INT_PTR (CALLBACK *DLGPROC)(HWND, UINT, WPARAM, LPARAM);",
        r"typedef void \(TIMECALLBACK\)\(UINT, UINT, DWORD_PTR, DWORD_PTR, DWORD_PTR\);":
            "typedef void (CALLBACK TIMECALLBACK)(UINT, UINT, DWORD_PTR, DWORD_PTR, DWORD_PTR);",
        r"typedef LRESULT \(\*HOOKPROC\)\(int, WPARAM, LPARAM\);":
            "typedef LRESULT (CALLBACK *HOOKPROC)(int, WPARAM, LPARAM);",
    }

    for line in text.splitlines(keepends=True):
        clean_line = line.rstrip("\n")
        match = native.FUNCTION_PROTOTYPE.match(clean_line)
        if match:
            fn_name = match.group(1)
            # Only emit prototype in header if it is an actual recovered function definition
            if fn_name in recovered_names and fn_name not in HOST_REPLACED_FUNCTIONS:
                output.append(f"uintptr_t __cdecl {fn_name}();\n")
            continue

        for pattern, replacement in callback_typedefs.items():
            if re.search(pattern, line):
                line = re.sub(pattern, replacement, line)
                break
        output.append(line)

    output.extend(
        [
            "\nint __cdecl MagicRecovered_WinMain(HINSTANCE, HINSTANCE, LPSTR, int);\n",
            "const char *MagicPe_LookupSymbolName(uint32_t address);\n",
            "\n#endif\n",
        ]
    )
    return "".join(output)


def function_statements(path: Path) -> dict[str, str]:
    text = re.sub(r"/\*[\s\S]*?\*/", "", path.read_text(encoding="utf-8"))
    text = re.sub(r"//[^\n]*", "", text)
    statements: dict[str, str] = {}
    pending = ""
    for raw_line in text.splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#") or line in {"extern \"C\" {", "}"}:
            continue
        pending = (pending + " " + line).strip()
        if ";" not in line:
            continue
        for statement in pending.split(";")[:-1]:
            match = re.search(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(", statement)
            if match and not statement.lstrip().startswith("typedef"):
                statements[match.group(1)] = statement.strip() + ";"
        pending = pending.split(";")[-1].strip()
    return statements


def add_calling_convention(prototype: str, name: str) -> str:
    convention = "WINAPIV" if name in {"wsprintfA", "wvsprintfA", "MCIWndCreateA"} else "WINAPI"
    return re.sub(rf"\b{re.escape(name)}\s*\(", f"{convention} {name}(", prototype, count=1)


def find_call_end(text: str, opening: int) -> int:
    depth = 0
    quote: str | None = None
    escaped = False
    for index in range(opening, len(text)):
        character = text[index]
        if quote is not None:
            if escaped:
                escaped = False
            elif character == "\\":
                escaped = True
            elif character == quote:
                quote = None
            continue
        if character in {'"', "'"}:
            quote = character
        elif character == "(":
            depth += 1
        elif character == ")":
            depth -= 1
            if depth == 0:
                return index
    return -1


def find_block_end(text: str, opening: int) -> int:
    """Return the closing brace for one C block."""
    depth = 0
    quote: str | None = None
    escaped = False
    line_comment = False
    block_comment = False
    index = opening
    while index < len(text):
        character = text[index]
        following = text[index + 1] if index + 1 < len(text) else ""
        if line_comment:
            if character == "\n":
                line_comment = False
        elif block_comment:
            if character == "*" and following == "/":
                block_comment = False
                index += 1
        elif quote is not None:
            if escaped:
                escaped = False
            elif character == "\\":
                escaped = True
            elif character == quote:
                quote = None
        elif character == "/" and following == "/":
            line_comment = True
            index += 1
        elif character == "/" and following == "*":
            block_comment = True
            index += 1
        elif character in {'"', "'"}:
            quote = character
        elif character == "{":
            depth += 1
        elif character == "}":
            depth -= 1
            if depth == 0:
                return index
        index += 1
    return -1


def add_fallthrough_returns(body: str) -> str:
    """Add a defined result when recovered control flow reaches a function end."""
    definition = re.compile(
        r"(?m)^(?:uintptr_t|int)(?:\s+__cdecl)?\s+"
        r"(?:MagicRecovered_WinMain|[A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*?\)\s*\n\s*\{"
    )
    closing_braces: list[int] = []
    for match in definition.finditer(body):
        opening = body.find("{", match.start(), match.end())
        closing = find_block_end(body, opening)
        if closing < 0:
            raise ValueError(f"A recovered function at offset {match.start()} is incomplete.")
        closing_braces.append(closing)
    for closing in reversed(closing_braces):
        body = body[:closing] + "  return 0;\n" + body[closing:]
    return body


def split_arguments(arguments: str) -> list[str]:
    result: list[str] = []
    start = 0
    depth = 0
    for index, character in enumerate(arguments):
        if character in "([{":
            depth += 1
        elif character in ")]}":
            depth -= 1
        elif character == "," and depth == 0:
            result.append(arguments[start:index])
            start = index + 1
    result.append(arguments[start:])
    return result


def callback_name(argument: str, names: set[str]) -> str | None:
    identifiers = re.findall(r"\b[A-Za-z_][A-Za-z0-9_]*\b", argument)
    candidates = [identifier for identifier in identifiers if identifier in names]
    return candidates[-1] if candidates else None


def replace_call_callbacks(
    body: str, call_name: str, argument_index: int, kind: str, names: set[str]
) -> tuple[str, set[tuple[str, str]]]:
    callbacks: set[tuple[str, str]] = set()
    cursor = 0
    output: list[str] = []
    pattern = re.compile(rf"\b{re.escape(call_name)}\s*\(")
    while True:
        match = pattern.search(body, cursor)
        if match is None:
            output.append(body[cursor:])
            break
        opening = body.find("(", match.start())
        closing = find_call_end(body, opening)
        if closing < 0:
            output.append(body[cursor:])
            break
        output.append(body[cursor:opening + 1])
        arguments = split_arguments(body[opening + 1:closing])
        if argument_index < len(arguments):
            name = callback_name(arguments[argument_index], names)
            if name is not None:
                wrapper = f"MagicPe_{kind}_{name}"
                arguments[argument_index] = re.sub(
                    rf"\b{re.escape(name)}\b", wrapper, arguments[argument_index]
                )
                callbacks.add((kind, name))
        output.append(",".join(arguments))
        output.append(")")
        cursor = closing + 1
    return "".join(output), callbacks


def replace_callbacks(body: str, names: set[str]) -> tuple[str, set[tuple[str, str]]]:
    callbacks: set[tuple[str, str]] = set()

    def replace_window_proc(match: re.Match[str]) -> str:
        name = match.group(2)
        callbacks.add(("window", name))
        return match.group(1) + f"MagicPe_window_{name}" + match.group(3)

    body = re.sub(
        r"(\.lpfnWndProc\s*=\s*)([A-Za-z_][A-Za-z0-9_]*)(\s*;)",
        replace_window_proc,
        body,
    )
    for call_name, (argument_index, kind) in CALLBACK_ARGUMENTS.items():
        body, found = replace_call_callbacks(body, call_name, argument_index, kind, names)
        callbacks.update(found)
    return body, callbacks


def trampoline_declaration(kind: str, name: str) -> str:
    wrapper = f"MagicPe_{kind}_{name}"
    declarations = {
        "window": f"LRESULT CALLBACK {wrapper}(HWND, UINT, WPARAM, LPARAM);",
        "dialog": f"INT_PTR CALLBACK {wrapper}(HWND, UINT, WPARAM, LPARAM);",
        "thread": f"DWORD WINAPI {wrapper}(LPVOID);",
        "time": f"void CALLBACK {wrapper}(UINT, UINT, DWORD_PTR, DWORD_PTR, DWORD_PTR);",
        "enum": f"BOOL CALLBACK {wrapper}(HWND, LPARAM);",
        "timer": f"void CALLBACK {wrapper}(HWND, UINT, UINT_PTR, DWORD);",
        "hook": f"LRESULT CALLBACK {wrapper}(int, WPARAM, LPARAM);",
    }
    return declarations[kind]


def trampoline_definition(kind: str, name: str) -> str:
    wrapper = f"MagicPe_{kind}_{name}"
    definitions = {
        "window": (
            f"LRESULT CALLBACK {wrapper}(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)\n"
            f"{{ return (LRESULT){name}(hwnd, message, wparam, lparam); }}\n"
        ),
        "dialog": (
            f"INT_PTR CALLBACK {wrapper}(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)\n"
            f"{{ return (INT_PTR){name}(hwnd, message, wparam, lparam); }}\n"
        ),
        "thread": (
            f"DWORD WINAPI {wrapper}(LPVOID parameter)\n"
            f"{{ return (DWORD){name}(parameter); }}\n"
        ),
        "time": (
            f"void CALLBACK {wrapper}(UINT id, UINT message, DWORD_PTR user, DWORD_PTR first, DWORD_PTR second)\n"
            f"{{ (void){name}(id, message, user, first, second); }}\n"
        ),
        "enum": (
            f"BOOL CALLBACK {wrapper}(HWND hwnd, LPARAM lparam)\n"
            f"{{ return (BOOL){name}(hwnd, lparam); }}\n"
        ),
        "timer": (
            f"void CALLBACK {wrapper}(HWND hwnd, UINT message, UINT_PTR id, DWORD time)\n"
            f"{{ (void){name}(hwnd, message, id, time); }}\n"
        ),
        "hook": (
            f"LRESULT CALLBACK {wrapper}(int code, WPARAM wparam, LPARAM lparam)\n"
            f"{{ return (LRESULT){name}(code, wparam, lparam); }}\n"
        ),
    }
    return definitions[kind]


def generate_symbol_table(symbols: dict[str, int]) -> str:
    sorted_symbols = sorted(
        ((addr, name) for name, addr in symbols.items() if addr >= 0x00400000),
        key=lambda x: x[0],
    )
    dedup: list[tuple[int, str]] = []
    seen: set[int] = set()
    for addr, name in sorted_symbols:
        if addr not in seen:
            seen.add(addr)
            dedup.append((addr, name))

    lines = [
        "\nstruct MagicPe_SymbolEntry {\n",
        "    uint32_t address;\n",
        "    const char *name;\n",
        "};\n\n",
        f"static const struct MagicPe_SymbolEntry g_MagicPe_SymbolTable[{len(dedup)}] = {{\n",
    ]
    for addr, name in dedup:
        clean_name = name.replace('"', '\\"')
        lines.append(f'    {{ 0x{addr:08x}u, "{clean_name}" }},\n')
    lines.append("};\n\n")
    lines.extend([
        "const char *MagicPe_LookupSymbolName(uint32_t address)\n",
        "{\n",
        "    size_t left = 0;\n",
        f"    size_t right = {len(dedup)};\n",
        "    while (left < right) {\n",
        "        size_t mid = left + (right - left) / 2;\n",
        "        if (g_MagicPe_SymbolTable[mid].address == address) {\n",
        "            return g_MagicPe_SymbolTable[mid].name;\n",
        "        }\n",
        "        if (g_MagicPe_SymbolTable[mid].address < address) {\n",
        "            left = mid + 1;\n",
        "        } else {\n",
        "            right = mid;\n",
        "        }\n",
        "    }\n",
        "    return NULL;\n",
        "}\n",
    ])
    return "".join(lines)


def called_names(body: str) -> set[str]:
    without_comments = re.sub(r"/\*[\s\S]*?\*/", "", body)
    without_comments = re.sub(r"//[^\n]*", "", without_comments)
    return set(re.findall(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(", without_comments))


def replace_data_indirect_calls(body: str) -> tuple[str, int]:
    """Resolve a function pointer that is stored in recovered image data."""
    pattern = re.compile(r"\(\*DAT_([0-9A-Fa-f]{8})\)\s*\(")
    body, count = pattern.subn(
        lambda match: f"MAGIC_CALL(0x{match.group(1).lower()}u)(", body
    )
    variable_pattern = re.compile(
        r"\(\*\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)\s*\("
    )
    body, variable_count = variable_pattern.subn(
        lambda match: f"MAGIC_NATIVE_CALL({match.group(1)})(", body
    )
    return body, count + variable_count


def remove_host_replaced_and_recursive_functions(body: str) -> tuple[str, list[str]]:
    removed = []
    pattern = re.compile(
        r"(?ms)^(?:uintptr_t|void|int|int32_t|uint32_t)(?:\s+__cdecl)?\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*?\)\s*\n\s*\{([\s\S]*?^\}\n)"
    )

    def replace_func(match: re.Match[str]) -> str:
        name = match.group(1)
        inner = match.group(2)
        if name in HOST_REPLACED_FUNCTIONS:
            removed.append(name)
            return ""
        clean = re.sub(r"/\*[\s\S]*?\*/", "", inner)
        clean = re.sub(r"//[^\n]*", "", clean).strip()
        clean = re.sub(r"\breturn(?:\s+[^;]+)?\s*;", "", clean).strip()
        if re.fullmatch(rf"{re.escape(name)}\s*\([^;]*\)\s*;", clean):
            removed.append(name)
            return ""
        return match.group(0)

    body = pattern.sub(replace_func, body)
    return body, removed


def defined_function_names(body: str) -> set[str]:
    pattern = re.compile(
        r"(?m)^(?:uintptr_t|int|void|int32_t|uint32_t)(?:\s+__cdecl)?\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*?\)\s*\n\s*\{"
    )
    names = set(pattern.findall(body))
    names.discard("MagicRecovered_WinMain")
    return names


def check_self_recursion(body: str) -> list[str]:
    recursive = []
    pattern = re.compile(
        r"(?ms)^(?:uintptr_t|int|void|int32_t|uint32_t)(?:\s+__cdecl)?\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*?\)\s*\n\s*\{([\s\S]*?^\}\n)"
    )
    for m in pattern.finditer(body):
        name = m.group(1)
        inner = m.group(2)
        clean = re.sub(r"/\*[\s\S]*?\*/", "", inner)
        clean = re.sub(r"//[^\n]*", "", clean).strip()
        clean = re.sub(r"\breturn(?:\s+[^;]+)?\s*;", "", clean).strip()
        if re.fullmatch(rf"{re.escape(name)}\s*\([^;]*\)\s*;", clean):
            recursive.append(name)
    return recursive


def make_import_header(
    body: str,
    recovered_names: set[str],
    win32_prototypes: dict[str, str],
    companion_prototypes: dict[str, str],
    callbacks: set[tuple[str, str]],
) -> tuple[str, set[str], set[str], set[str], set[str]]:
    calls = called_names(body) - recovered_names
    calls.discard("MagicRecovered_WinMain")
    companion_names = calls & companion_prototypes.keys()
    win32_names = (calls - companion_names) & win32_prototypes.keys()
    crt_names = calls & CRT_IMPORTS
    excluded = RUNTIME_IMPORTS | CRT_IMPORTS | {
        "CONCAT11", "CONCAT12", "CONCAT22", "CONCAT31", "CONCAT44",
        "LOCK", "MAGIC_CALL", "MAGIC_NATIVE_CALL", "MAGIC_CODE_SLOT",
        "MAGIC_HOST_ADDRESS", "MAGIC_PART",
        "MAGIC_POINTER", "MAGIC_POINTER_AT", "MAGIC_POINT_FROM_LPARAM",
        "MAGIC_U8", "MAGIC_I8", "MAGIC_U16", "MAGIC_I16", "MAGIC_U32",
        "MAGIC_I32", "MAGIC_U64", "UNLOCK",
        "for", "if", "return", "sizeof", "switch", "while",
    }
    unresolved = calls - win32_names - companion_names - crt_names - excluded
    unresolved.discard("block")

    lines = [
        "#ifndef SHANDALAR_GENERATED_MAGIC_PE_IMPORTS_H\n",
        "#define SHANDALAR_GENERATED_MAGIC_PE_IMPORTS_H\n\n",
    ]
    # Win32 API imports
    for name in sorted(win32_names):
        lines.append(add_calling_convention(win32_prototypes[name], name) + "\n")
    if "InitCommonControls" not in win32_names:
        lines.append("void WINAPI InitCommonControls(void);\n")

    # Companion DLL imports
    for name in sorted(companion_names):
        lines.append(companion_prototypes[name] + "\n")

    # Legacy CRT adapters & declarations
    lines.extend([
        "int *__p___mb_cur_max(void);\n",
        "const unsigned short **__p__pctype(void);\n",
        "int __cdecl _atexit(void (*func)(void));\n",
    ])

    # Runtime imports
    lines.extend(
        [
            "uintptr_t __cdecl MagicPe_GlobalAddress(uint32_t address);\n",
            "uintptr_t __cdecl MagicPe_ResolveCallable(uint32_t address);\n",
            "uintptr_t __cdecl MagicPe_RegisterCallable(uintptr_t function_address);\n",
            "HMODULE WINAPI MagicPe_LoadLibraryA(LPCSTR name);\n",
            "FARPROC WINAPI MagicPe_GetProcAddress(HMODULE module, LPCSTR name);\n",
            "uint64_t __cdecl MagicPe_AllShl(unsigned int shift, uint32_t value);\n",
            "uintptr_t __cdecl MagicPe_Assert(const char *expression, const char *file, unsigned int line);\n",
            "uintptr_t __cdecl MagicPe_StackProbe(void);\n",
        ]
    )
    for kind, name in sorted(callbacks):
        lines.append(trampoline_declaration(kind, name) + "\n")
    lines.append("\n#endif\n")
    return "".join(lines), win32_names, companion_names, crt_names, unresolved


def audit_markdown(audit: dict[str, object]) -> str:
    lines = ["# MAGIC PE32 ABI Audit\n\n"]
    lines.append(f"Ready: **{'yes' if not audit['fatal_errors'] else 'no'}**\n\n")
    lines.append("## Counts\n\n")
    for name, value in sorted(audit["counts"].items()):
        lines.append(f"- `{name}`: {value}\n")
    lines.append("\n## Fatal errors\n\n")
    errors = audit["fatal_errors"]
    if errors:
        for error in errors:
            lines.append(f"- {error}\n")
    else:
        lines.append("- None.\n")
    return "".join(lines)


def main() -> None:
    arguments = parse_arguments()
    raw_header = arguments.header.read_text(encoding="utf-8")
    raw_source = arguments.source.read_text(encoding="utf-8")
    initial_names = native.function_names(raw_header)
    symbols, image_base, image_size = native.load_symbols(arguments.symbols)

    raw_globals, body = raw_source.split(native.GLOBAL_MARKER, 1)
    body = native.GLOBAL_MARKER + body
    if native.CRT_MARKER in body:
        body = body.split(native.CRT_MARKER, 1)[0]
    if native.DECOMPRESSOR_MARKER in raw_source:
        body += raw_source[raw_source.index(native.DECOMPRESSOR_MARKER):]

    globals_text, body = native.prepare_globals(raw_globals, body, initial_names, symbols)
    body = native.prepare_body(body, initial_names)
    body, removed_stubs = remove_host_replaced_and_recursive_functions(body)
    body = body.replace('#include "magic_unified.h"\n', "")

    body = re.sub(r"(?m)^uintptr_t ([A-Za-z_][A-Za-z0-9_]*)\(", r"uintptr_t __cdecl \1(", body)
    body = body.replace("uintptr_t __cdecl WinMain(", "int __cdecl MagicRecovered_WinMain(")
    body = body.replace("uintptr_t WinMain(", "int __cdecl MagicRecovered_WinMain(")
    body = body.replace("return;", "return 0;")
    body = body.replace("MagicNative_", "MagicPe_")
    body = body.replace("Ordinal_17()", "InitCommonControls()")
    body = re.sub(r"([A-Za-z_][A-Za-z0-9_]*)\->_flag", r"(feof(\1) ? 0x10 : 0)", body)
    body = re.sub(
        r"MagicPe_CopyProgramPath\(local_150,sizeof\(local_150\)\);\s*"
        r"pcVar5 = strrchr\(local_150,0x5c\);\s*"
        r"if \(pcVar5 == \(char \*\)0x0\) pcVar5 = strrchr\(local_150,0x2f\);\s*"
        r"if \(pcVar5 != \(char \*\)0x0\) \*pcVar5 = '\\0';\s*"
        r"_chdir\(local_150\);",
        "strcpy(local_150, \".\");\n    pcVar5 = local_150;",
        body,
    )
    body, resolved_indirect_calls = replace_data_indirect_calls(body)

    # Compute actual recovered function names from definitions that remain in body
    recovered_names = defined_function_names(body)
    recovered_names.add("MagicRecovered_WinMain")

    header = prepare_header(raw_header, recovered_names)

    resolver = native.recovered_callable_resolver(body, symbols)
    resolver = resolver.replace("MagicNative_", "MagicPe_")
    resolver = resolver.replace("&WinMain", "&MagicRecovered_WinMain")

    body, callbacks = replace_callbacks(body, recovered_names)
    body = add_fallthrough_returns(body)

    win32_prototypes = function_statements(arguments.compat_header)
    win32_prototypes.setdefault("InitCommonControls", "void InitCommonControls(void);")
    win32_prototypes.setdefault(
        "LoadBitmapA", "HBITMAP LoadBitmapA(HINSTANCE instance, LPCSTR name);"
    )
    win32_prototypes.setdefault(
        "GetSaveFileNameA", "BOOL WINAPI GetSaveFileNameA(LPOPENFILENAMEA lpofn);"
    )
    win32_prototypes.setdefault(
        "MCIWndCreateA", "HWND WINAPI MCIWndCreateA(HWND hwndParent, HINSTANCE hInstance, DWORD dwStyle, LPCSTR szFile);"
    )

    companion_prototypes = load_companion_prototypes(arguments.ordinals)

    import_header, win32_imports, companion_imports, crt_imports, unresolved = make_import_header(
        body, recovered_names, win32_prototypes, companion_prototypes, callbacks
    )

    source_preamble = f"""/* This file is generated. Do not edit it. */
#include "magic_pe.h"
#include "magic_pe_imports.h"

_Static_assert(sizeof(void *) == 4, "MAGIC.EXE requires 32-bit pointers.");
_Static_assert(sizeof(uintptr_t) == 4, "MAGIC.EXE requires 32-bit uintptr_t.");
_Static_assert(sizeof(RECT) == 16, "RECT must be 16 bytes.");
_Static_assert(sizeof(POINT) == 8, "POINT must be 8 bytes.");
_Static_assert(sizeof(MSG) == 28, "MSG must be 28 bytes.");
_Static_assert(sizeof(WNDCLASSA) == 40, "WNDCLASSA must be 40 bytes.");
_Static_assert(sizeof(BITMAPINFOHEADER) == 40, "BITMAPINFOHEADER must be 40 bytes.");
_Static_assert(sizeof(PALETTEENTRY) == 4, "PALETTEENTRY must be 4 bytes.");

#define MAGIC_IMAGE_BASE 0x{image_base:08x}u
#define MAGIC_IMAGE_SIZE {image_size}u
#define MAGIC_HOST_ADDRESS(address) MagicPe_GlobalAddress((uint32_t)(address))
#define MAGIC_POINTER(type, address) ((type)(uintptr_t)MAGIC_U32(address))
#define MAGIC_POINTER_AT(type, address, index) ((type)(uintptr_t)MAGIC_U32((address) + ((uint32_t)(index) * 4u)))
#define MAGIC_CODE_SLOT(address) ((code *)(uintptr_t)MagicPe_ResolveCallable(MAGIC_U32(address)))
#define MAGIC_CALL(address) ((uintptr_t (__cdecl *)())(uintptr_t)MagicPe_ResolveCallable(MAGIC_U32(address)))
#define MAGIC_NATIVE_CALL(pointer) ((uintptr_t (__cdecl *)())(uintptr_t)MagicPe_ResolveCallable((uint32_t)(uintptr_t)(pointer)))
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
#define LoadLibraryA MagicPe_LoadLibraryA
#define GetProcAddress MagicPe_GetProcAddress
#define __allshl MagicPe_AllShl
#define assert MagicPe_Assert
#define Mem_AllocOrFree_00513bd0 MagicPe_StackProbe

"""

    trampoline_source = [
        "/* This file is generated. Do not edit it. */\n",
        '#include "magic_pe.h"\n',
        '#include "magic_pe_imports.h"\n\n',
    ]
    for kind, name in sorted(callbacks):
        trampoline_source.append(trampoline_definition(kind, name) + "\n")

    callable_source = (
        "/* This file is generated. Do not edit it. */\n"
        '#include "magic_pe.h"\n'
        + resolver
        + "\n"
        + generate_symbol_table(symbols)
    )

    image = arguments.image.read_bytes()
    if len(image) != image_size:
        raise ValueError(
            f"The image size is {len(image)}, but the symbol manifest requires {image_size}."
        )
    pe_offset = int.from_bytes(image[0x3c:0x40], "little")
    optional_header = pe_offset + 24
    virtual_size = int.from_bytes(image[optional_header + 56:optional_header + 60], "little")
    if virtual_size < image_size:
        raise ValueError("The PE virtual size is smaller than the exported image.")
    image_header = f"""#ifndef SHANDALAR_GENERATED_MAGIC_PE_IMAGE_H
#define SHANDALAR_GENERATED_MAGIC_PE_IMAGE_H
#define MAGIC_PE_IMAGE_BASE 0x{image_base:08x}u
#define MAGIC_PE_IMAGE_SIZE {image_size}u
#define MAGIC_PE_VIRTUAL_SIZE {virtual_size}u
#define MAGIC_PE_IMAGE_CRC32 0x{zlib.crc32(image) & 0xffffffff:08x}u
#endif
"""

    raw_indirect_calls = len(re.findall(
        r"\(\*\s*[A-Za-z_][A-Za-z0-9_]*\s*\)\s*\(", body
    ))
    direct_callback_assignments = len(re.findall(
        r"\.lpfnWndProc\s*=\s*(?!MagicPe_)[A-Za-z_][A-Za-z0-9_]*", body
    ))
    recursive_functions = check_self_recursion(body)

    fatal_errors: list[str] = []
    if unresolved:
        fatal_errors.append("Unresolved imports: " + ", ".join(sorted(unresolved)))
    if direct_callback_assignments:
        fatal_errors.append(
            f"{direct_callback_assignments} window callbacks do not use ABI trampolines."
        )
    if raw_indirect_calls:
        fatal_errors.append(
            f"{raw_indirect_calls} indirect calls do not use checked resolution."
        )
    if recursive_functions:
        fatal_errors.append(
            "Direct self-recursive thunks detected: " + ", ".join(sorted(recursive_functions))
        )

    audit: dict[str, object] = {
        "schema_version": 1,
        "target": "i686-w64-mingw32",
        "image_base": f"0x{image_base:08x}",
        "image_size": image_size,
        "image_crc32": f"0x{zlib.crc32(image) & 0xffffffff:08x}",
        "counts": {
            "callbacks": len(callbacks),
            "crt_imports": len(crt_imports),
            "companion_imports": len(companion_imports),
            "recovered_functions": len(recovered_names),
            "raw_indirect_calls": raw_indirect_calls,
            "resolved_indirect_calls": resolved_indirect_calls,
            "unresolved_imports": len(unresolved),
            "win32_imports": len(win32_imports),
        },
        "fatal_errors": fatal_errors,
        "unresolved_imports": sorted(unresolved),
    }

    output = arguments.output_dir
    output.mkdir(parents=True, exist_ok=True)
    (output / "magic_pe.h").write_text(header, encoding="utf-8")
    (output / "magic_pe_imports.h").write_text(import_header, encoding="utf-8")
    (output / "magic_pe_image.h").write_text(image_header, encoding="utf-8")
    (output / "magic_pe.c").write_text(
        source_preamble + "\n" + globals_text + "\n" + body,
        encoding="utf-8",
    )
    (output / "magic_callable_map.c").write_text(callable_source, encoding="utf-8")
    (output / "magic_callback_trampolines.c").write_text(
        "".join(trampoline_source), encoding="utf-8"
    )
    (output / "magic_pe_audit.json").write_text(
        json.dumps(audit, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    (output / "magic_pe_audit.md").write_text(audit_markdown(audit), encoding="utf-8")


if __name__ == "__main__":
    main()
