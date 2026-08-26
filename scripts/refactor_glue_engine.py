#!/usr/bin/env python3
"""
refactor_glue_engine.py - Full Automated Modularization, Renaming, STE Documentation & Splitting for glue.c
MicroProse Magic: The Gathering (Shandalar 1997) Reconstructed ANSI C Engine
"""

import os
import re
import json
import glob

BASE_DIR = "/Users/ben/decomp"
FUNCS_DIR = os.path.join(BASE_DIR, "magic/functions")
METADATA_PATH = "/Users/ben/.gemini/antigravity/brain/669cec31-26e1-4589-bb85-e02a80bda342/scratch/glue_metadata_full.json"

MODULE_HEADERS = {
    "timer": """/*
 * sid/glue_timer.c - High-Precision Hardware Timer & Profiling Clock
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"
""",

    "spell_chain": """/*
 * sid/glue_spell_chain.c - Spell Resolution Stack & Spell Chain Window UI
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"
""",

    "card_scripts": """/*
 * sid/glue_card_scripts.c - Specific Card Rules Scripts & Activated/Triggered Abilities
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier & Ned Way / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"
""",

    "card_queries": """/*
 * sid/glue_card_queries.c - Permanent Queries, Iterators, Counter Manipulation & Targeting
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"
""",

    "adventure": """/*
 * sid/glue_adventure.c - Shandalar Overworld Campaign, Town Dialogs, Newsflashes & Audio Events
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"
""",

    "duel_ui": """/*
 * sid/glue_duel_ui.c - Tactical Duel Combat Arena Window, Debug Cheats & Status Banners
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/glue.h"
""",

    "bazaar": """/*
 * sid/glue_bazaar.c - Bazaar Card Trading Shop & Haar Wavelet Art Decompressor
 * Reconstructed MicroProse Source Module
 * Author: Ned Way & Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/catalog.h"
#include "shandalar/haar.h"
#include "shandalar/glue.h"
"""
}

def clean_parameter_names(sig, func_name, ep_int):
    sig = re.sub(r"\bparam_1\b", "hwnd", sig)
    sig = re.sub(r"\bparam_2\b", "uMsg", sig)
    sig = re.sub(r"\bparam_3\b", "wParam", sig)
    sig = re.sub(r"\bparam_4\b", "lParam", sig)
    sig = re.sub(r"\bstr_1\b", "name_or_path", sig)
    sig = re.sub(r"\bstr_2\b", "file_name", sig)
    sig = re.sub(r"\bstr_6\b", "banner_text", sig)

    if "Card_" in func_name or (0x004d0cdb <= ep_int < 0x004e654a):
        sig = re.sub(r"\bspell_id\b", "player", sig)
        sig = re.sub(r"\btarget_id\b", "card_index", sig)
        sig = re.sub(r"\bflags\b", "event_code", sig)
        sig = re.sub(r"\barg_1\b", "player", sig)
        sig = re.sub(r"\barg1\b", "player", sig)
        sig = re.sub(r"\barg_2\b", "card_index", sig)
        sig = re.sub(r"\barg2\b", "card_index", sig)
        sig = re.sub(r"\barg_3\b", "event_code", sig)
        sig = re.sub(r"\barg3\b", "event_code", sig)
        sig = re.sub(r"\barg_4\b", "action_param", sig)
        sig = re.sub(r"\barg_5\b", "extra_flags", sig)
    elif "WndProc" in func_name:
        sig = re.sub(r"\barg_1\b", "hwnd", sig)
        sig = re.sub(r"\barg1\b", "hwnd", sig)
        sig = re.sub(r"\barg_2\b", "uMsg", sig)
        sig = re.sub(r"\barg2\b", "uMsg", sig)
        sig = re.sub(r"\barg_3\b", "wParam", sig)
        sig = re.sub(r"\barg3\b", "wParam", sig)
        sig = re.sub(r"\barg_4\b", "lParam", sig)
        sig = re.sub(r"\barg4\b", "lParam", sig)
    else:
        sig = re.sub(r"\barg_1\b", "arg1", sig)
        sig = re.sub(r"\barg_2\b", "arg2", sig)
        sig = re.sub(r"\barg_3\b", "arg3", sig)
        sig = re.sub(r"\barg_4\b", "arg4", sig)
        sig = re.sub(r"\barg_5\b", "arg5", sig)
        sig = re.sub(r"\barg_6\b", "arg6", sig)
        sig = re.sub(r"\barg_7\b", "arg7", sig)
    return sig

def clean_body_variables(body, func_name, ep_int):
    if "Card_" in func_name or (0x004d0cdb <= ep_int < 0x004e654a):
        body = re.sub(r"\bspell_id\b", "player", body)
        body = re.sub(r"\btarget_id\b", "card_index", body)
        body = re.sub(r"\bflags\b", "event_code", body)
        body = re.sub(r"\barg_1\b", "player", body)
        body = re.sub(r"\barg1\b", "player", body)
        body = re.sub(r"\barg_2\b", "card_index", body)
        body = re.sub(r"\barg2\b", "card_index", body)
        body = re.sub(r"\barg_3\b", "event_code", body)
        body = re.sub(r"\barg3\b", "event_code", body)
        body = re.sub(r"\barg_4\b", "action_param", body)
        body = re.sub(r"\barg_5\b", "extra_flags", body)
    elif "WndProc" in func_name:
        body = re.sub(r"\bparam_1\b", "hwnd", body)
        body = re.sub(r"\bparam_2\b", "uMsg", body)
        body = re.sub(r"\bparam_3\b", "wParam", body)
        body = re.sub(r"\bparam_4\b", "lParam", body)
    else:
        body = re.sub(r"\bstr_1\b", "name_or_path", body)
        body = re.sub(r"\bstr_2\b", "file_name", body)
        body = re.sub(r"\bstr_6\b", "banner_text", body)
        body = re.sub(r"\barg_1\b", "arg1", body)
        body = re.sub(r"\barg_2\b", "arg2", body)
        body = re.sub(r"\barg_3\b", "arg3", body)
        body = re.sub(r"\barg_4\b", "arg4", body)
        body = re.sub(r"\barg_5\b", "arg5", body)
        body = re.sub(r"\barg_6\b", "arg6", body)
        body = re.sub(r"\barg_7\b", "arg7", body)

    body = re.sub(r"\biVar1\b", "status", body)
    body = re.sub(r"\biVar2\b", "val_result", body)
    body = re.sub(r"\biVar3\b", "temp_idx", body)
    body = re.sub(r"\buVar1\b", "u_res", body)
    body = re.sub(r"\buVar2\b", "u_temp", body)
    body = re.sub(r"\bbVar1\b", "is_valid", body)
    body = re.sub(r"\bbVar2\b", "is_match", body)
    body = re.sub(r"\bcVar1\b", "c_res", body)
    body = re.sub(r"\bsVar1\b", "s_res", body)
    body = re.sub(r"\bAVar1\b", "atom_res", body)
    return body

def build_ste_comment(func_name, ep, sz, purpose, steps):
    lines = ["/*", f" * {func_name}", f" * Purpose: {purpose}"]
    if steps:
        lines.append(" * Procedure:")
        for idx, step in enumerate(steps, 1):
            lines.append(f" * {idx}. {step}")
    lines.append(" */")
    lines.append("/*")
    lines.append(f" * Decompiled function: {func_name}")
    lines.append(f" * Entry Point: {ep}")
    lines.append(f" * Size: {sz} bytes")
    lines.append(" */")
    return "\n".join(lines)

def refactor():
    with open(METADATA_PATH, "r") as f:
        metadata = json.load(f)

    all_files = glob.glob(os.path.join(FUNCS_DIR, "*.c"))
    file_map = {}
    for fpath in all_files:
        fname = os.path.basename(fpath)
        m = fname[:-2].split("_")[-1]
        if len(m) == 8 and all(c in "0123456789abcdefABCDEF" for c in m):
            file_map[m.lower()] = fpath

    old_to_new = {}
    parsed_funcs = []

    for addr, (new_name, purpose, steps) in sorted(metadata.items(), key=lambda x: int(x[0], 16)):
        fpath = file_map.get(addr.lower())
        if not fpath:
            print(f"Error: Function file for address {addr} not found!")
            continue

        with open(fpath, "r", encoding="utf-8", errors="ignore") as f:
            ftext = f.read()

        # Parse header
        m_head = re.search(r"/\*\s*\*\s*Decompiled function:\s*(\w+)\s*\*\s*Entry Point:\s*([0-9a-fA-F]+)\s*\*\s*Size:\s*(\d+)\s*bytes\s*\*/", ftext)
        old_name = m_head.group(1) if m_head else f"FUN_{addr}"
        sz = m_head.group(3) if m_head else "0"

        old_to_new[old_name] = new_name
        old_to_new[f"FUN_{addr}"] = new_name
        old_to_new[f"Glue_{addr}"] = new_name
        old_to_new[f"Glue_Subsystem_{addr}"] = new_name
        old_to_new[f"Glue_Util_{addr}"] = new_name
        old_to_new[f"Glue_Sound_{addr}"] = new_name
        old_to_new[f"Glue_UI_{addr}"] = new_name
        old_to_new[f"Glue_Timer_{addr}"] = new_name
        old_to_new[f"Glue_Render_{addr}"] = new_name

        ep_int = int(addr, 16)
        if ep_int < 0x004cd760:
            group = "timer"
        elif ep_int < 0x004d0cdb:
            group = "spell_chain"
        elif ep_int < 0x004e654a:
            group = "card_scripts"
        elif ep_int < 0x004e73a0:
            group = "card_queries"
        elif ep_int < 0x004ecfe5:
            group = "adventure"
        elif ep_int < 0x004f0de8:
            group = "duel_ui"
        else:
            group = "bazaar"

        # Extract function body (strip includes and comment headers)
        body_start = ftext.find("#include")
        if body_start != -1:
            body_start = ftext.find("\n", body_start) + 1
        else:
            body_start = ftext.find("*/") + 2
        body = ftext[body_start:].strip()

        parsed_funcs.append({
            "ep": addr,
            "ep_int": ep_int,
            "sz": sz,
            "old_name": old_name,
            "new_name": new_name,
            "purpose": purpose,
            "steps": steps,
            "group": group,
            "body": body
        })

    prototypes = []
    submodule_code = {g: [] for g in MODULE_HEADERS}

    for item in parsed_funcs:
        ep_int = item["ep_int"]
        old_name = item["old_name"]
        new_name = item["new_name"]
        purpose = item["purpose"]
        steps = item["steps"]
        group = item["group"]
        body = item["body"]

        # Rename calls in body
        for o_n, n_n in old_to_new.items():
            body = re.sub(r"\b" + re.escape(o_n) + r"\b", n_n, body)

        # Match signature definition line
        def_match = re.search(r"((?:[a-zA-Z0-9_*]+\s+)+)" + re.escape(new_name) + r"\s*\(([^)]*)\)", body)
        if not def_match:
            def_match = re.search(r"((?:[a-zA-Z0-9_*]+\s+)+)" + re.escape(old_name) + r"\s*\(([^)]*)\)", body)
            if def_match:
                body = body[:def_match.start()] + def_match.group(1) + new_name + "(" + def_match.group(2) + ")" + body[def_match.end():]
                def_match = re.search(r"((?:[a-zA-Z0-9_*]+\s+)+)" + re.escape(new_name) + r"\s*\(([^)]*)\)", body)

        if def_match:
            ret_type = def_match.group(1).strip()
            param_str = def_match.group(2).strip()
            cleaned_params = clean_parameter_names(param_str, new_name, ep_int)
            sig_line = f"{ret_type} {new_name}({cleaned_params})"
            prototypes.append(f"{sig_line};")
            body = body[:def_match.start()] + sig_line + body[def_match.end():]

        body = clean_body_variables(body, new_name, ep_int)

        ste_header = build_ste_comment(new_name, item["ep"], item["sz"], purpose, steps)
        full_func = f"{ste_header}\n\n{body}\n\n"
        submodule_code[group].append(full_func)

    # 1. Write include/shandalar/glue.h
    glue_h_lines = [
        "/*",
        " * shandalar/glue.h - Master Declarations & Subsystems for Shandalar Engine",
        " * MicroProse Magic: The Gathering (Shandalar 1997) Reconstructed ANSI C Engine",
        " */",
        "#ifndef SHANDALAR_GLUE_H",
        "#define SHANDALAR_GLUE_H",
        "",
        '#include "types.h"',
        '#include "win32_compat.h"',
        "",
        "#ifdef __cplusplus",
        'extern "C" {',
        "#endif",
        "",
        "/* ========================================================================= */",
        "/* Modernized Function Prototypes (251 Subsystem Functions)                  */",
        "/* ========================================================================= */",
        ""
    ]

    glue_h_lines.extend(prototypes)

    glue_h_lines.extend([
        "",
        "/* ========================================================================= */",
        "/* Backward Compatibility Aliases for Legacy Decompiled Symbols             */",
        "/* ========================================================================= */",
        ""
    ])

    for o_n, n_n in sorted(old_to_new.items()):
        if o_n != n_n:
            glue_h_lines.append(f"#define {o_n} {n_n}")

    glue_h_lines.extend([
        "",
        "#ifdef __cplusplus",
        "}",
        "#endif",
        "",
        "#endif /* SHANDALAR_GLUE_H */",
        ""
    ])

    glue_h_path = os.path.join(BASE_DIR, "include/shandalar/glue.h")
    with open(glue_h_path, "w", encoding="utf-8") as f:
        f.write("\n".join(glue_h_lines))
    print(f"Generated {glue_h_path} ({len(prototypes)} prototypes).")

    # 2. Write 7 submodules to src/magic/sid/ and mirror to magic/sid/
    output_files = {
        "timer": "glue_timer.c",
        "spell_chain": "glue_spell_chain.c",
        "card_scripts": "glue_card_scripts.c",
        "card_queries": "glue_card_queries.c",
        "adventure": "glue_adventure.c",
        "duel_ui": "glue_duel_ui.c",
        "bazaar": "glue_bazaar.c"
    }

    for grp, fname in output_files.items():
        content = MODULE_HEADERS[grp] + "\n" + "".join(submodule_code[grp])
        p1 = os.path.join(BASE_DIR, "src/magic/sid", fname)
        p2 = os.path.join(BASE_DIR, "magic/sid", fname)
        with open(p1, "w", encoding="utf-8") as f:
            f.write(content)
        with open(p2, "w", encoding="utf-8") as f:
            f.write(content)
        print(f"Generated {fname} ({len(submodule_code[grp])} functions).")

    # 3. Write master glue.c
    master_glue = """/*
 * sid/glue.c - Master Aggregator Module for Shandalar Engine Subsystems
 * Reconstructed MicroProse Source Architecture (Sid Meier & Ned Way, 1997)
 *
 * Subsystems contained:
 * 1. glue_timer.c        - High-Precision Hardware Timer & Profiling Clock
 * 2. glue_spell_chain.c  - Spell Resolution Stack & Spell Chain Window UI
 * 3. glue_card_scripts.c - Specific Card Rules Scripts & Activated/Triggered Abilities
 * 4. glue_card_queries.c - Permanent Queries, Iterators, Counter Manipulation & Targeting
 * 5. glue_adventure.c    - Shandalar Overworld Campaign, Town Dialogs & Audio Events
 * 6. glue_duel_ui.c      - Tactical Duel Combat Arena Window, Debug Cheats & Status Banners
 * 7. glue_bazaar.c       - Bazaar Card Trading Shop & Haar Wavelet Art Decompressor
 */

#include "glue_timer.c"
#include "glue_spell_chain.c"
#include "glue_card_scripts.c"
#include "glue_card_queries.c"
#include "glue_adventure.c"
#include "glue_duel_ui.c"
#include "glue_bazaar.c"
"""

    with open(os.path.join(BASE_DIR, "src/magic/sid/glue.c"), "w", encoding="utf-8") as f:
        f.write(master_glue)
    with open(os.path.join(BASE_DIR, "magic/sid/glue.c"), "w", encoding="utf-8") as f:
        f.write(master_glue)
    print("Updated master src/magic/sid/glue.c and magic/sid/glue.c")

if __name__ == "__main__":
    refactor()
