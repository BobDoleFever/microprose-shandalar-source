#!/usr/bin/env python3
"""
refactor_top_symbols.py - Comprehensive Refactoring for Top Default Named Symbols
Refactors the most frequently occurring FUN_* functions, DAT_* global variables,
and argument/parameter names across all subsystems and updates CSV symbol maps.
"""

import os
import re
import csv
import glob

BASE_DIR = "/Users/ben/decomp"

# ==============================================================================
# 1. Top DAT Global Variables Mapping
# ==============================================================================
TOP_DAT_MAP = {
    # DUEL.EXE CardSlot Structure (Base 0x006826c4, Stride 0x120, Player Stride 0x5b20)
    "006826c4": "g_DuelCardSlot_CardId",
    "006826cc": "g_DuelCardSlot_Flags",
    "006826ce": "g_DuelCardSlot_Subtypes",
    "006826d2": "g_DuelCardSlot_ColorMask",
    "006826d3": "g_DuelCardSlot_Controller",
    "006826d8": "g_DuelCardSlot_Power",
    "006826e4": "g_DuelCardSlot_Counters",
    "006826e8": "g_DuelCardSlot_TargetSlot",
    "006826f0": "g_DuelCardSlot_DisplayIndex",
    "006826f8": "g_DuelCardSlot_Abilities1",
    "006826fc": "g_DuelCardSlot_Abilities2",
    "00682718": "g_DuelCardSlot_TargetPlayer",
    "0068271c": "g_DuelCardSlot_CombatTargetSlot",
    "006827b0": "g_DuelCardSlot_AttachedAuraPlayer",
    "006827b4": "g_DuelCardSlot_AttachedAuraSlot",
    "006827b8": "g_DuelCardSlot_TapState",
    "006827b9": "g_DuelCardSlot_SpecialState",

    # DUEL.EXE Game State & Progression Globals
    "0068ecb0": "g_DuelActivePlayer",
    "00690c48": "g_DuelActiveCardSlot",
    "00681ea4": "g_DuelHumanPlayerIndex",
    "00681ea8": "g_DuelPlayerLifeTotals",
    "00681eb0": "g_DuelPlayerManaPool",
    "00681ea0": "g_DuelTurnCounter",
    "00666408": "g_DuelPlayerCreatureCount",
    "0066642c": "g_DuelCurrentTurnPhase",
    "00666458": "g_DuelDefendingPlayer",
    "00676510": "g_DuelTargetPlayer",
    "00676504": "g_DuelTargetCardSlot",
    "0066aaf4": "g_DuelDebugModeFlag",
    "0068f2c4": "g_DuelCombatPhaseState",
    "0068f230": "g_DuelCurrentEventCode",
    "0068f104": "g_DuelTargetCardId",
    "0068f2d4": "g_DuelDamageAccumulator",
    "00690af0": "g_DuelCombatAttackerPlayer",
    "0068efa0": "g_DuelCombatBlockerSlot",
    "004ff594": "g_DuelMasterCardTable",
    "004ff597": "g_DuelMasterCardSubType",
    "005f6810": "g_DuelCardChoicePrompt",
    "006679f0": "g_DuelCardNameBuffer",
    "00664680": "g_DuelInstanceHandle",
    "00618990": "g_DuelMainHwnd",
    "006189a0": "g_DuelAssetDirectory",
    "00522458": "g_DisplayScreenWidth",
    "0052245c": "g_DisplayScreenHeight",
}

# ==============================================================================
# 2. Top FUN Function Symbols Mapping
# ==============================================================================
TOP_FUN_MAP = {
    "004d9640": "Str_CopyFast",
    "004d9630": "Str_CopyFastAligned",
    "004521e2": "Mana_GetCardColorRequirement",
    "0046e571": "Duel_DrawCardSprite",
    "0040d949": "Font_DrawString",
    "0049b309": "Duel_DrawString",
    "00434660": "Catalog_ParseCsvLine",
    "0048e01d": "FileIo_ReadStream",
    "0040a1d2": "Math_RandomRange",
    "00433bb6": "FileIo_ReadDataBlock",
    "0041bcf0": "UI_SelectTargetCardDialog",
    "00403250": "UI_PaintBigCardInfo",
    "0043071d": "Card_DispatchRulesEvent",
    "0046f172": "Sprite_ResolveAssetPath",
    "00471395": "GDI_DestroyDIBSection",
    "00410cc0": "Card_ApplyTriggerEffect",
    "004707a4": "GDI_RealizeAndFlushPalette",
    "00473179": "Card_TapForMana",
    "00439892": "Duel_RandomRange",
    "004a2b00": "Duel_TriggerCardEvent",
    "0048b81a": "Duel_TapCardForMana",
    "004f3955": "GDI_RealizeAndFlushPalette_Magic",
    "0041d9d2": "Card_SetTapState",
    "00473cc5": "Card_ColorMaskToColorIndex",
    "0040a3e1": "App_ProcessPendingMessages",
    "0050dce0": "Surface_BlitToDevice",
    "004f4548": "GDI_DestroyDIBSection_Magic",
    "0048c367": "Duel_ColorMaskToIndex",
    "004af7bb": "Duel_GetCardColorOverride",
    "00451482": "Duel_UpdateBoardState",
    "00471c32": "Card_IsTapped",
    "0048d00c": "Sound_PlayTrackById",
    "0040a305": "Math_Clamp",
    "0048a33f": "Duel_CardIsTapped",
    "0040d4d1": "Font_DrawTextInRect",
    "0041d963": "Card_UntapCard",
    "00472b60": "GDI_RealizePaletteTree",
    "004af74c": "Duel_GetCardModifiedPower",
    "004f5d1a": "GDI_RealizePaletteTree_Magic",
    "00468130": "Mana_CanAffordCost",
    "0048c907": "Duel_PlayCardSoundEffect",
    "00447184": "Deck_ValidateCardLimit",
    "005112b0": "Surface_TransformPoint",
    "004709ae": "GDI_DrawBitmapToHDC",
    "004d7d5e": "Card_IsValidCardId",
    "0047a090": "Sound_PlaySpatialSound",
    "0040cc7e": "Font_DrawFormattedText",
    "004af950": "Duel_ApplyCombatDamage",
    "0040c761": "Surface_GetPixelColor",
    "0041db67": "Card_ApplyCombatDamage",
}

# Specific parameter improvements for named functions
FUNCTION_PARAM_MAP = {
    "Math_Clamp": ["value", "min_val", "max_val"],
    "Math_RandomRange": ["max_val"],
    "Duel_RandomRange": ["max_val"],
    "Card_IsTapped": ["player", "card_slot"],
    "Duel_CardIsTapped": ["player", "card_slot"],
    "Card_UntapCard": ["player", "card_slot"],
    "Card_SetTapState": ["player", "card_slot", "tap_state"],
    "Card_ColorMaskToColorIndex": ["color_mask"],
    "Duel_ColorMaskToIndex": ["color_mask"],
    "Card_IsValidCardId": ["card_id"],
    "GDI_DestroyDIBSection": ["hDIBSection"],
    "GDI_DestroyDIBSection_Magic": ["hDIBSection"],
    "GDI_RealizeAndFlushPalette": ["hdc"],
    "GDI_RealizeAndFlushPalette_Magic": ["hdc"],
    "GDI_DrawBitmapToHDC": ["hdc", "point", "hBitmap"],
    "Font_DrawString": ["x", "y", "text"],
    "Duel_DrawString": ["x", "y", "text"],
    "Font_DrawTextInRect": ["x", "y", "width", "height"],
    "Surface_GetPixelColor": ["x", "y"],
    "FileIo_ReadStream": ["buffer", "size"],
    "FileIo_ReadDataBlock": ["buffer", "size"],
    "Sprite_ResolveAssetPath": ["asset_name"],
    "Card_TapForMana": ["player", "card_slot", "color_index", "flags"],
    "Duel_TapCardForMana": ["player", "card_slot", "color_index", "flags"],
    "Mana_GetCardColorRequirement": ["player", "card_slot"],
    "Card_ApplyTriggerEffect": ["player", "card_slot", "target_player", "target_slot", "flags"],
    "Card_ApplyCombatDamage": ["attacker_player", "attacker_slot", "defender_player", "defender_slot", "damage"],
    "Duel_ApplyCombatDamage": ["attacker_player", "attacker_slot", "defender_player", "defender_slot", "damage"],
    "Duel_GetCardModifiedPower": ["player", "card_slot", "base_power"],
    "Duel_GetCardColorOverride": ["player", "card_slot", "base_color"],
    "Mana_CanAffordCost": ["player", "cost_mask", "available_pool"],
    "Sound_PlayTrackById": ["track_id"],
    "Sound_PlaySpatialSound": ["sound_id", "x", "y", "flags"],
    "Deck_ValidateCardLimit": ["deck_id", "card_id"],
    "Str_CopyFast": ["dest", "src"],
    "Str_CopyFastAligned": ["dest", "src"],
    "Catalog_ParseCsvLine": ["csv_buffer", "out_record"],
}

def update_csv_maps():
    print(">>> Updating CSV symbol maps...")
    
    # 1. Update engine_globals_map.csv
    globals_csv = os.path.join(BASE_DIR, "engine_globals_map.csv")
    existing_globals = {}
    if os.path.exists(globals_csv):
        with open(globals_csv, 'r', encoding='utf-8') as f:
            reader = csv.reader(f)
            next(reader, None)
            for row in reader:
                if len(row) >= 2:
                    existing_globals[row[0].strip().lower()] = row[1].strip()
    
    for addr, name in TOP_DAT_MAP.items():
        existing_globals[addr.lower()] = name
        
    with open(globals_csv, 'w', newline='', encoding='utf-8') as f:
        writer = csv.writer(f)
        writer.writerow(["Address", "NewName"])
        for addr, name in sorted(existing_globals.items()):
            writer.writerow([addr, name])
    print(f"  -> engine_globals_map.csv has {len(existing_globals)} entries.")

    # 2. Update unified_engine_symbol_map.csv, magic_symbol_renames.csv, duel_symbol_renames.csv
    for csv_name in ["unified_engine_symbol_map.csv", "magic_symbol_renames.csv", "duel_symbol_renames.csv"]:
        cpath = os.path.join(BASE_DIR, csv_name)
        existing_funcs = {}
        if os.path.exists(cpath):
            with open(cpath, 'r', encoding='utf-8') as f:
                reader = csv.reader(f)
                next(reader, None)
                for row in reader:
                    if len(row) >= 3:
                        existing_funcs[row[0].strip().lower()] = (row[1].strip(), row[2].strip())
        
        for addr, name in TOP_FUN_MAP.items():
            addr_l = addr.lower()
            old_name = existing_funcs.get(addr_l, (f"FUN_{addr_l}", ""))[0]
            existing_funcs[addr_l] = (old_name, name)
            
        with open(cpath, 'w', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow(["Address", "OldName", "NewName"])
            for addr, (old_name, new_name) in sorted(existing_funcs.items()):
                writer.writerow([addr, old_name, new_name])
        print(f"  -> {csv_name} has {len(existing_funcs)} entries.")

def refactor_source_code():
    print(">>> Refactoring C source and header files across codebase...")
    
    # Build replacement dictionary
    replacements = {}
    
    # 1. Functions
    for addr, name in TOP_FUN_MAP.items():
        replacements[f"FUN_{addr}"] = name
        replacements[f"FUN_{addr.lower()}"] = name
        replacements[f"sub_{addr}"] = name
        replacements[f"sub_{addr.lower()}"] = name

    # 2. DATs
    for addr, name in TOP_DAT_MAP.items():
        replacements[f"DAT_{addr}"] = name
        replacements[f"DAT_{addr.lower()}"] = name
        replacements[f"_DAT_{addr}"] = name
        replacements[f"_DAT_{addr.lower()}"] = name

    # Collect all source files
    target_dirs = ["src", "include", "magic", "duel", "deck", "deckdll", "statwin", "magsnd", "magvid"]
    all_files = []
    for td in target_dirs:
        all_files.extend(glob.glob(os.path.join(BASE_DIR, td, "**/*.c"), recursive=True))
        all_files.extend(glob.glob(os.path.join(BASE_DIR, td, "**/*.h"), recursive=True))

    total_modified = 0

    for fpath in all_files:
        with open(fpath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()

        orig = content

        # Apply symbol replacements with word boundaries
        for old_sym, new_sym in replacements.items():
            if old_sym in content:
                content = re.sub(r'\b' + re.escape(old_sym) + r'\b', new_sym, content)

        # Refactor function parameters if this file contains a function definition
        fname_base = os.path.basename(fpath)
        for fn_name, new_params in FUNCTION_PARAM_MAP.items():
            if fn_name in content:
                # Check for function definition header comments or signatures
                sig_match = re.search(r'(\b' + re.escape(fn_name) + r'\s*\()([^)]+)(\))', content)
                if sig_match:
                    old_sig_params = sig_match.group(2)
                    param_parts = [p.strip() for p in old_sig_params.split(',')]
                    new_param_parts = []
                    for idx, part in enumerate(param_parts):
                        if idx < len(new_params):
                            sub_part = re.sub(r'\b(arg_?[0-9]+|param_[0-9]+|a[0-9]+)\b', new_params[idx], part)
                            new_param_parts.append(sub_part)
                            # Also rename uses inside body
                            old_pname_m = re.search(r'\b(arg_?[0-9]+|param_[0-9]+|a[0-9]+)\b', part)
                            if old_pname_m:
                                old_pname = old_pname_m.group(1)
                                content = re.sub(r'\b' + re.escape(old_pname) + r'\b', new_params[idx], content)
                        else:
                            new_param_parts.append(part)
                    new_sig_params = ', '.join(new_param_parts)
                    content = content.replace(sig_match.group(0), f"{fn_name}({new_sig_params})")

        if content != orig:
            with open(fpath, 'w', encoding='utf-8') as f:
                f.write(content)
            total_modified += 1

    print(f"  -> Successfully refactored and modernized {total_modified} source and header files!")

def update_python_scripts():
    print(">>> Updating refactoring scripts...")
    for script_name in ["scripts/advanced_symbol_cleaner.py", "scripts/full_codebase_refactor.py"]:
        spath = os.path.join(BASE_DIR, script_name)
        if os.path.exists(spath):
            with open(spath, 'r', encoding='utf-8') as f:
                content = f.read()
            orig = content
            for addr, name in TOP_DAT_MAP.items():
                if f'"{addr}"' not in content:
                    content = re.sub(r'(EXTRA_DAT_MAP\s*=\s*\{|GLOBAL_DAT_MAP\s*=\s*\{)', r'\1\n    "' + addr + '": "' + name + '",', content)
            if content != orig:
                with open(spath, 'w', encoding='utf-8') as f:
                    f.write(content)
                print(f"  -> Updated {script_name}")

def main():
    print("==========================================================")
    print(" Refactoring Top Default Functions, DATs and Arguments")
    print("==========================================================")
    update_csv_maps()
    refactor_source_code()
    update_python_scripts()
    print("==========================================================")
    print(" Refactoring Pipeline Complete!")
    print("==========================================================")

if __name__ == "__main__":
    main()
