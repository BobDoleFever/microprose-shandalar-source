#!/usr/bin/env python3
"""
refactor_ai_engine.py - Full Automated Renaming, Variable Cleanup, DAT De-obfuscation & STE Documentation for Ai.c
MicroProse Magic: The Gathering (Shandalar 1997) Reconstructed ANSI C Engine
"""

import os
import re
import json
import glob

BASE_DIR = "/Users/ben/decomp"
FUNCS_DIR = os.path.join(BASE_DIR, "magic/functions")
METADATA_PATH = "/Users/ben/.gemini/antigravity/brain/669cec31-26e1-4589-bb85-e02a80bda342/scratch/ai_metadata_full.json"

DAT_REPLACEMENTS = {
    "DAT_00559a94": "g_AiCreaturePowerEval",
    "DAT_00559a20": "g_AiCreatureToughnessEval",
    "DAT_00559b1c": "g_AiCombatScoreBuffer",
    "DAT_006b2d40": "g_AiSelectedTargetCard",
    "DAT_0063ee90": "g_AiLookaheadDepth",
    "DAT_005574b0": "g_AiPlayerScoreTable",
    "DAT_0051aec8": "g_MasterCardManaCostTable",
    "DAT_005596b8": "g_AiAttackerList",
    "DAT_00522450": "g_AiManaColorCost_White",
    "DAT_00522454": "g_AiManaColorCost_Blue",
    "DAT_00522458": "g_AiManaColorCost_Red",
    "DAT_0052245c": "g_AiManaColorCost_Green",
    "DAT_005595f8": "g_AiBlockerList",
    "DAT_0054be44": "g_AiBestScoreTable",
    "DAT_00627a20": "g_AiTempTargetBuffer",
    "DAT_006b2e90": "g_AiCurrentChoiceIndex",
    "DAT_0055a050": "g_AiCombatDamageTable",
    "DAT_0067f2c0": "g_AiHandEvaluationBuffer",
    "DAT_0067bdf0": "g_CardSlot_CreatureType",
    "DAT_006410f0": "g_AiBestScore",
    "DAT_006410f4": "g_AiBestCardIndex",
    "DAT_006410f8": "g_AiBestTargetPlayer",
    "DAT_00559848": "g_AiCandidateCardList",
    "DAT_0051aed0": "g_MasterCardSubtypeTable",
    "DAT_00556ae8": "g_AiHeuristicWeight_CreaturePower",
    "DAT_00633430": "g_AiGameStateBackupBuffer",
    "DAT_0052d5cc": "g_AiHeuristicWeight_LifeAdvantage",
    "DAT_00559808": "g_AiCandidateScoreList",
    "DAT_006b2d58": "g_AiSelectedTargetPlayer",
    "DAT_006b3064": "g_AiDecisionMatrix_Row",
    "DAT_0052d77c": "g_AiHeuristicWeight_CardAdvantage",
    "DAT_00559f88": "g_AiCombatSimulationState",
    "DAT_00641870": "g_AiDecisionTreeDepth",
    "DAT_00559638": "g_AiBlockerAssignmentList",
    "DAT_006fe444": "g_DuelArenaStatusFlags",
    "DAT_00556a90": "g_AiHeuristicWeight_DirectDamage",
    "DAT_006a5f4c": "g_CardSlot_CountersBonus",
    "DAT_006498d0": "g_AiLookaheadScore_Player0",
    "DAT_006498d4": "g_AiLookaheadScore_Player1",
    "DAT_006498d8": "g_AiLookaheadDelta",
    "DAT_006498dc": "g_AiLookaheadBestMove",
    "DAT_0069f744": "g_MainAppWindow",
    "DAT_0055a008": "g_AiDamageAssignmentBuffer",
    "DAT_0063ee30": "g_AiCombatScore_Attacker",
    "DAT_0063ee18": "g_AiCombatScore_Blocker",
    "DAT_0063edd0": "g_AiCombatScore_Total",
    "DAT_006a4924": "g_TurnPriorityState",
    "DAT_006b2e2c": "g_AiSelectedActionCode",
    "DAT_00556b18": "g_AiHeuristicWeight_BoardThreat",
    "DAT_00556c60": "g_AiHeuristicWeight_Regeneration",
    "DAT_0055699c": "g_AiHeuristicWeight_ManaEfficiency",
    "DAT_006ff2f0": "g_ActiveCombatRoundCounter",
    "DAT_005569d8": "g_AiHeuristicWeight_Evasion",
    "DAT_006ff4ac": "g_AiManaPoolReserve",
    "DAT_0052d770": "g_AiHeuristicWeight_HandAdvantage",
    "DAT_0067be00": "g_CardSlot_StatusFlags",
    "DAT_006ff1ac": "g_AiAttackingCreatureCount",
    "DAT_006ff19c": "g_AiBlockingCreatureCount",
    "DAT_0055a010": "g_AiLethalDamageFlag",
    "DAT_006a5f20": "g_ActiveBattlefieldFlag",
    "DAT_006a3f78": "g_AiEvaluatedMoveCount",
    "DAT_006fefa8": "g_AiCurrentSearchPath",
    "DAT_0067bdb0": "g_CardSlot_PowerBonus",
    "DAT_006fe400": "g_AiDuelTurnState",
    "DAT_00556938": "g_AiHeuristicWeight_Aggression",
    "DAT_006b2e28": "g_AiCandidateActionCount",
    "DAT_006b2d60": "g_AiSelectedCardTargetSlot",
    "DAT_006fedc0": "g_AiTurnDecisionFlag",
    "DAT_00695ec8": "g_AiCombatDamageAssigned",
    "DAT_006776a0": "g_AiBackupBoardRegister",
    "DAT_00559890": "g_AiCandidatePriorityList",
    "DAT_00559b80": "g_AiCombatRoundResult",
    "DAT_005520c8": "g_AiCardScore_BasicLand",
    "DAT_0067b9a4": "g_CardSlot_ToughnessBonus",
    "DAT_00695e88": "g_AiPlayerLifeDifferential",
    "DAT_0069e720": "g_AiLookaheadTreeRoot",
    "DAT_0068a73c": "g_AiEvaluationTimeout",
    "DAT_00695ea0": "g_AiPlayerHandDifferential",
    "DAT_00556b20": "g_AiHeuristicWeight_Removal",
    "DAT_00627864": "g_AiTemporaryCardState",
    "DAT_0055747c": "g_AiHeuristicWeight_Tempo",
    "DAT_0067f2d4": "g_AiCardEvaluationScore",
    "DAT_0067f2d8": "g_AiCardSynergyScore",
    "DAT_00627a7c": "g_AiCombatLookaheadTarget",
    "DAT_006a5f3d": "g_CardSlot_StateByte",
    "DAT_00559800": "g_AiEvaluationCandidateCount",
    "DAT_00559fc8": "g_AiCombatSimulationBuffer_End",
    "DAT_0069e730": "g_AiLookaheadTreeCurrentNode",
    "DAT_006ff710": "g_AiEvaluationPassCounter",
    "DAT_006b1590": "g_AiTemporaryBuffer_006b1590",
    "DAT_006b2d90": "g_AiSelectedAbilityIndex",
    "DAT_006b3070": "g_AiDecisionMatrix_Col",
    "DAT_00556acc": "g_AiHeuristicWeight_Flyers",
    "DAT_006a284c": "g_AiEvaluationLock",
    "DAT_00556ad4": "g_AiHeuristicWeight_FirstStrike",
    "DAT_0052ce98": "g_AiHeuristicWeight_Trample",
    "DAT_00556b28": "g_AiHeuristicWeight_Protection",
    "DAT_0067f35c": "g_AiCardScoringThreshold",
    "DAT_00556c58": "g_AiHeuristicWeight_Lifelink"
}

AI_HEADER = """/*
 * sid/Ai.c - MicroProse Sid Meier Tactical AI & Decision Heuristics Engine
 * Reconstructed MicroProse Source Module
 * Author: Sid Meier / MicroProse (1997)
 *
 * Comments follow Simplified Technical English (ASD-STE100) rules.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/ai.h"
#include "shandalar/glue.h"
"""

def clean_parameter_names(sig, func_name, ep_int):
    if not sig.strip() or sig.strip() == "void":
        return sig

    params = [p.strip() for p in sig.split(",") if p.strip()]
    cleaned_params = []
    
    is_wndproc = "wndproc" in func_name.lower() or "dialogproc" in func_name.lower()
    is_scoring = "scorecardplay" in func_name.lower() or "evalability" in func_name.lower()
    is_mana = "calcmanarequirement" in func_name.lower() or "calcmana" in func_name.lower()
    is_combat = "evalattack" in func_name.lower() or "evalblock" in func_name.lower() or "choose" in func_name.lower()
    
    used_names = set()
    for idx, p in enumerate(params):
        m = re.match(r"^(.*?)\b([a-zA-Z0-9_]+)$", p)
        if not m:
            cleaned_params.append(p)
            continue
        ptype = m.group(1).strip()
        pname = m.group(2).strip()
        
        new_pname = pname
        if is_wndproc:
            if idx == 0:
                new_pname = "hwnd" if "RECT" not in ptype else "lprect"
            elif idx == 1:
                new_pname = "uMsg" if "HWND" not in ptype else "hwnd_target"
            elif idx == 2:
                new_pname = "wParam"
            elif idx == 3:
                new_pname = "lParam"
            else:
                new_pname = f"arg{idx+1}"
        elif is_scoring:
            if idx == 0: new_pname = "player"
            elif idx == 1: new_pname = "card_index"
            elif idx == 2: new_pname = "target_player"
            elif idx == 3: new_pname = "action_flags"
            else: new_pname = f"arg{idx+1}"
        elif is_mana:
            if idx == 0: new_pname = "player"
            elif idx == 1: new_pname = "color_index"
            elif idx == 2: new_pname = "required_amount"
            else: new_pname = f"arg{idx+1}"
        elif is_combat:
            if idx == 0: new_pname = "player"
            elif idx == 1: new_pname = "attacker_idx"
            elif idx == 2: new_pname = "blocker_idx"
            else: new_pname = f"arg{idx+1}"
        else:
            if pname.startswith("param_") or pname.startswith("arg_") or pname.startswith("arg"):
                new_pname = f"arg{idx+1}"
            elif pname == "str_1":
                new_pname = "prompt_text"
            elif pname == "str_2":
                new_pname = "output_str"
            else:
                new_pname = pname
        
        if new_pname in used_names:
            new_pname = f"{new_pname}_{idx+1}"
        used_names.add(new_pname)
        
        cleaned_params.append(f"{ptype} {new_pname}" if ptype else new_pname)
    
    return ", ".join(cleaned_params)

def clean_body_variables(body, func_name, ep_int):
    body = re.sub(r"\bparam_1\b", "hwnd", body)
    body = re.sub(r"\bparam_2\b", "uMsg", body)
    body = re.sub(r"\bparam_3\b", "wParam", body)
    body = re.sub(r"\bparam_4\b", "lParam", body)

    body = re.sub(r"\barg_1\b", "arg1", body)
    body = re.sub(r"\barg_2\b", "arg2", body)
    body = re.sub(r"\barg_3\b", "arg3", body)
    body = re.sub(r"\barg_4\b", "arg4", body)
    body = re.sub(r"\barg_5\b", "arg5", body)
    body = re.sub(r"\barg_6\b", "arg6", body)
    body = re.sub(r"\barg_7\b", "arg7", body)

    body = re.sub(r"\bstr_1\b", "prompt_text", body)
    body = re.sub(r"\bstr_2\b", "output_str", body)

    body = re.sub(r"\biVar1\b", "status", body)
    body = re.sub(r"\biVar2\b", "val_result", body)
    body = re.sub(r"\biVar3\b", "temp_idx", body)
    body = re.sub(r"\biVar4\b", "card_idx", body)
    body = re.sub(r"\buVar1\b", "u_res", body)
    body = re.sub(r"\buVar2\b", "u_temp", body)
    body = re.sub(r"\buVar3\b", "u_score", body)
    body = re.sub(r"\buVar4\b", "u_val", body)
    body = re.sub(r"\buVar5\b", "u_extra", body)
    body = re.sub(r"\bbVar1\b", "is_valid", body)
    body = re.sub(r"\bbVar2\b", "is_match", body)
    body = re.sub(r"\bcVar1\b", "c_res", body)
    body = re.sub(r"\bsVar1\b", "s_res", body)
    body = re.sub(r"\bAVar1\b", "atom_res", body)
    body = re.sub(r"\bpuVar1\b", "p_ures", body)
    body = re.sub(r"\bpiVar1\b", "p_ires", body)
    body = re.sub(r"\bpHVar1\b", "h_wnd", body)

    for dat_old, dat_new in DAT_REPLACEMENTS.items():
        body = re.sub(r"\b" + dat_old + r"\b", dat_new, body)
        body = re.sub(r"\b_" + dat_old + r"\b", dat_new, body)

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

        m_head = re.search(r"/\*\s*\*\s*Decompiled function:\s*(\w+)\s*\*\s*Entry Point:\s*([0-9a-fA-F]+)\s*\*\s*Size:\s*(\d+)\s*bytes\s*\*/", ftext)
        old_name = m_head.group(1) if m_head else f"FUN_{addr}"
        sz = m_head.group(3) if m_head else "0"

        old_to_new[old_name] = new_name
        old_to_new[f"FUN_{addr}"] = new_name
        old_to_new[f"Ai_{addr}"] = new_name
        old_to_new[f"Ai_Subsystem_{addr}"] = new_name
        old_to_new[f"Ai_Util_{addr}"] = new_name
        old_to_new[f"Mem_AllocOrFree_{addr}"] = new_name
        old_to_new[f"Pic_Load_{addr}"] = new_name
        old_to_new[f"UI_DialogProc_{addr}"] = new_name
        old_to_new[f"UI_WndProc_{addr}"] = new_name
        old_to_new[f"UI_CreateWindow_{addr}"] = new_name

        ep_int = int(addr, 16)

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
            "body": body
        })

    prototypes = []
    formatted_funcs = []

    for item in parsed_funcs:
        ep_int = item["ep_int"]
        old_name = item["old_name"]
        new_name = item["new_name"]
        purpose = item["purpose"]
        steps = item["steps"]
        body = item["body"]

        for o_n, n_n in old_to_new.items():
            body = re.sub(r"\b" + re.escape(o_n) + r"\b", n_n, body)

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
        formatted_funcs.append(full_func)

    # 1. Update include/shandalar/ai.h
    ai_h_lines = [
        "/*",
        " * shandalar/ai.h - MicroProse Sid Meier Tactical AI & Decision Engine",
        " * Original Source Path: G:\\NewMagic\\sources\\sid\\Ai.h / Ai.c",
        " * Comments follow Simplified Technical English (STE) rules.",
        " */",
        "#ifndef SHANDALAR_AI_H",
        "#define SHANDALAR_AI_H",
        "",
        '#include "types.h"',
        '#include "sound.h"',
        '#include "win32_compat.h"',
        "",
        "#ifdef __cplusplus",
        'extern "C" {',
        "#endif",
        "",
        "/*",
        " * AI Difficulty Levels.",
        " * Use these values to set the opponent skill level.",
        " */",
        "typedef enum AiDifficulty {",
        "    AI_DIFFICULTY_APPRENTICE = 0, /* Lowest difficulty level. */",
        "    AI_DIFFICULTY_MAGE       = 1, /* Medium difficulty level. */",
        "    AI_DIFFICULTY_ARCHMAGE   = 2, /* Hard difficulty level. */",
        "    AI_DIFFICULTY_WIZARD     = 3  /* Expert difficulty level. */",
        "} AiDifficulty;",
        "",
        "/*",
        " * Board Evaluation Score Metrics.",
        " * This structure holds numeric score values for board analysis.",
        " */",
        "typedef struct BoardScore {",
        "    int32_t life_score;          /* Score for player life total advantage. */",
        "    int32_t card_advantage;      /* Score for count of cards in hand. */",
        "    int32_t creature_power;      /* Total attack and defense power of creatures. */",
        "    int32_t mana_available;      /* Count of untapped mana sources. */",
        "    int32_t board_threat;        /* Threat value of opponent cards (ScWilly metric). */",
        "    int32_t total_score;         /* Sum of all calculated score values. */",
        "} BoardScore;",
        "",
        "/*",
        " * Combat Decision Matrix.",
        " * This structure stores combat assignments for creatures.",
        " */",
        "typedef struct CombatDecision {",
        "    int32_t attacker_card_id;    /* Identification number of attacking card. */",
        "    int32_t blocker_card_id;     /* Identification number of blocking card (-1 = none). */",
        "    int32_t damage_assigned;     /* Amount of damage to apply. */",
        "    bool    should_attack;       /* True if the creature must attack. */",
        "    bool    should_block;        /* True if the creature must block. */",
        "} CombatDecision;",
        "",
        "/* ========================================================================= */",
        "/* Modernized Function Prototypes (260 Tactical AI Functions)               */",
        "/* ========================================================================= */",
        ""
    ]

    ai_h_lines.extend(prototypes)

    ai_h_lines.extend([
        "",
        "/* ========================================================================= */",
        "/* Backward Compatibility Aliases for Legacy Decompiled Symbols             */",
        "/* ========================================================================= */",
        ""
    ])

    for o_n, n_n in sorted(old_to_new.items()):
        if o_n != n_n:
            ai_h_lines.append(f"#define {o_n} {n_n}")

    ai_h_lines.extend([
        "",
        "#ifdef __cplusplus",
        "}",
        "#endif",
        "",
        "#endif /* SHANDALAR_AI_H */",
        ""
    ])

    ai_h_path = os.path.join(BASE_DIR, "include/shandalar/ai.h")
    with open(ai_h_path, "w", encoding="utf-8") as f:
        f.write("\n".join(ai_h_lines))
    print(f"Generated {ai_h_path} ({len(prototypes)} prototypes).")

    # 2. Write src/magic/sid/Ai.c and mirror to magic/sid/Ai.c
    ai_content = AI_HEADER + "\n" + "".join(formatted_funcs)
    p1 = os.path.join(BASE_DIR, "src/magic/sid/Ai.c")
    p2 = os.path.join(BASE_DIR, "magic/sid/Ai.c")
    with open(p1, "w", encoding="utf-8") as f:
        f.write(ai_content)
    with open(p2, "w", encoding="utf-8") as f:
        f.write(ai_content)
    print(f"Updated {p1} and {p2} ({len(formatted_funcs)} functions).")

if __name__ == "__main__":
    refactor()
