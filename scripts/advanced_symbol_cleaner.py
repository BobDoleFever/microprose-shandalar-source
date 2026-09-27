#!/usr/bin/env python3
"""
advanced_symbol_cleaner.py - Advanced Symbol & Variable Cleaner for Shandalar Decompilation
Cleans remaining DAT globals, FUN_ / hex-named functions, parameters, and local variables.
"""

import os
import re
import csv
import glob
import subprocess

BASE_DIR = "/Users/ben/decomp"
GHIDRA_HEADLESS = "/opt/homebrew/Cellar/ghidra/12.1.3/libexec/support/analyzeHeadless"
JAVA_HOME = "/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home"

# ------------------------------------------------------------------------------
# 1. Additional Global DAT Symbol Definitions
# ------------------------------------------------------------------------------
EXTRA_DAT_MAP = {
    "0052245c": "g_DisplayScreenHeight",
    "00522458": "g_DisplayScreenWidth",
    "006189a0": "g_DuelAssetDirectory",
    "00618990": "g_DuelMainHwnd",
    "00664680": "g_DuelInstanceHandle",
    "006679f0": "g_DuelCardNameBuffer",
    "005f6810": "g_DuelCardChoicePrompt",
    "004ff597": "g_DuelMasterCardSubType",
    "004ff594": "g_DuelMasterCardTable",
    "0068efa0": "g_DuelCombatBlockerSlot",
    "00690af0": "g_DuelCombatAttackerPlayer",
    "0068f2d4": "g_DuelDamageAccumulator",
    "0068f104": "g_DuelTargetCardId",
    "0068f230": "g_DuelCurrentEventCode",
    "0068f2c4": "g_DuelCombatPhaseState",
    "0066aaf4": "g_DuelDebugModeFlag",
    "00676504": "g_DuelTargetCardSlot",
    "00676510": "g_DuelTargetPlayer",
    "00666458": "g_TurnPlayer",
    "0066642c": "g_CardEventResult",
    "00666408": "g_DuelPlayerCreatureCount",
    "00681ea0": "g_DuelTurnCounter",
    "00681eb0": "g_DuelModeFlags",
    "00681ea8": "g_DuelPlayerLifeTotals",
    "00681ea4": "g_DuelHumanPlayerIndex",
    "00690c48": "g_EventSourceSlot",
    "0068ecb0": "g_EventSourcePlayer",
    "006827b9": "g_DuelCardSlot_SpecialState",
    "006827b8": "g_DuelCardSlot_TapState",
    "006827b4": "g_DuelCardSlot_AttachedAuraSlot",
    "006827b0": "g_DuelCardSlot_AttachedAuraPlayer",
    "0068271c": "g_DuelCardSlot_CombatTargetSlot",
    "00682718": "g_DuelCardSlot_TargetPlayer",
    "006826fc": "g_DuelCardSlot_Abilities2",
    "006826f8": "g_DuelCardSlot_Abilities1",
    "006826f0": "g_DuelCardSlot_DisplayIndex",
    "006826e8": "g_DuelCardSlot_TargetSlot",
    "006826e4": "g_DuelCardSlot_Counters",
    "006826d8": "g_DuelCardSlot_Power",
    "006826d3": "g_DuelCardSlot_Controller",
    "006826d2": "g_DuelCardSlot_ColorMask",
    "006826ce": "g_DuelCardSlot_Subtypes",
    "006826cc": "g_DuelCardSlot_Flags",
    "006826c4": "g_DuelCardSlot_CardId",
    # Audio Subsystem & Channel State
    "00519c24": "g_ActiveSoundTrackId",
    "00519ff4": "g_MidiSequenceState",
    "00530d9c": "g_CurrentMidiTrackId",
    "0067f780": "g_SoundChannelActiveCount",
    "0067f7d0": "g_SoundChannelDescriptors",
    "00538750": "g_SoundSampleBufferTable",

    # Overworld Campaign & Town Coordinates
    "0052eff0": "g_OverworldPlayerPixelX",
    "0052eff4": "g_OverworldPlayerPixelY",
    "0052effc": "g_OverworldPlayerDirection",
    "0067f374": "g_OverworldMovementFlags",
    "0067bda4": "g_MouseCursorScreenX",
    "0067bda8": "g_MouseCursorScreenY",
    "007039c4": "g_MouseCursorButtonState",
    "00680770": "g_MouseCursorCapturedFlag",
    "0067f380": "g_CampaignDifficultyLevel",
    "0067f3bc": "g_CampaignCompassHeading",
    "0067bdf4": "g_DungeonMapTileX",
    "0067bdf8": "g_DungeonMapTileY",
    "0067f014": "g_TownBuildingFlags",
    "0067f2d0": "g_TownBuildingCoordinates",
    "006a28b0": "g_PlayerGoldCoins",
    "006b2e30": "g_PlayerAmuletGems",
    "005659f8": "g_OverworldPopupMenu",

    # Graphics, Palettes, Decoders & Framebuffers
    "006261d8": "g_PcxDecoderWidth",
    "006261dc": "g_PcxDecoderHeight",
    "00520cc8": "g_KimpicExtensionStr",
    "00520cd0": "g_KimpicReadModeStr",
    "00520cd4": "g_KimpicErrorStr",
    "00520cb8": "g_KimpicSurfacePtr",
    "00520cec": "g_KimpicSourceFileId",
    "00520d44": "g_KimpicDecoderInitialized",
    "00539e88": "g_WaveletBitmaskTable",
    "00539e8c": "g_WaveletBitAccumulator",
    "00527b44": "g_WaveletBitsRemaining",
    "0053aa90": "g_WaveletDecompressCursor",
    "00649c20": "g_PaletteColorMatchBuffer",
    "0054be3c": "g_ActivePaletteColorData",
    "00536d94": "g_DialogPromptTemplate",

    # MTG Rules, Card Slots & Turn Variables
    "0069e730": "g_PlayerDeckCardList",
    "006ff710": "g_PlayerGraveyardList",
    "006b2d2c": "g_SelectedTargetSlot",
    "006b2d3c": "g_SelectedTargetPlayer",
    "006a4b5c": "g_CurrentCardColorTarget",
    "00695ec4": "g_ActiveCardTargetSlot",
    "0063edc0": "g_CurrentTurnTargetPlayer",
    "006a2828": "g_PlayerPoisonCounters",
    "006a2854": "g_PlayerSelectionPriority",
    "00695f0c": "g_TurnPhaseStateFlags",
    "006a4a04": "g_PlayerDeckCardCount",
    "00696740": "g_PlayerAvailableManaMask",
    "0063ee4c": "g_PlayerManaBurnAccumulator",
    "006b3008": "g_ActivePlayerSpellPriority",
    "00627a14": "g_PendingSpellResolutionFlag",
    "0063ee20": "g_TemporaryToughnessBuffer",
    "0067bda0": "g_CombatAttackerSlotIndex",
    "0067bda4": "g_CombatBlockerSlotIndex",
    "0067f2b0": "g_SpellStackResolutionCursor",
    "0067f2b4": "g_SpellStackItemCount",
}

# ------------------------------------------------------------------------------
# 2. Automated Function Context Extraction
# ------------------------------------------------------------------------------
def discover_functions_from_context():
    discovered = {}

    tsv_files = [
        os.path.join(BASE_DIR, "scratch_magic_exe_context.tsv"),
        os.path.join(BASE_DIR, "scratch_duel_exe_context.tsv")
    ]

    for tsv in tsv_files:
        if not os.path.exists(tsv):
            continue
        with open(tsv, 'r', encoding='utf-8', errors='ignore') as f:
            r = csv.DictReader(f, delimiter='\t')
            for row in r:
                addr = (row.get('Address') or '').strip().lower()
                cname = (row.get('CurrentName') or '').strip()
                strs = (row.get('StringsReferenced') or '').strip()
                apis = (row.get('CalledAPIs') or '').strip()

                if not addr or len(addr) < 6:
                    continue

                # 1. Card Scripts
                card_prompts = re.findall(r'([A-Z_]{4,})\s*\|\s*prompts\.txt', strs)
                if card_prompts:
                    name_clean = ''.join(w.capitalize() for w in card_prompts[0].split('_'))
                    discovered[addr] = f"CardScript_{name_clean}"
                    continue

                # 2. Dialog & Window Procs
                if "wndproc" in cname.lower() or "dialogproc" in cname.lower():
                    continue

                if "dialog" in strs.lower() or "dlg" in strs.lower() or "enddialog" in apis.lower():
                    if "deck" in strs.lower():
                        discovered[addr] = f"UI_DeckDialogProc_{addr}"
                    elif "card" in strs.lower():
                        discovered[addr] = f"UI_CardDialogProc_{addr}"
                    else:
                        discovered[addr] = f"UI_DialogProc_{addr}"
                    continue

                if "registerclass" in apis.lower():
                    classes = re.findall(r'MAGICGAME_(\w+)|([A-Za-z]+Class)', strs)
                    if classes:
                        cname_c = classes[0][0] or classes[0][1]
                        discovered[addr] = f"UI_RegisterClass_{cname_c}"
                    else:
                        discovered[addr] = f"UI_RegisterClass_{addr}"
                    continue

                if "defwindowproc" in apis.lower() or "beginpaint" in apis.lower():
                    discovered[addr] = f"UI_WndProc_{addr}"
                    continue

                # 3. Audio & Sound
                if ".wav" in strs.lower():
                    wavs = re.findall(r'([a-zA-Z0-9_]+)\.wav', strs.lower())
                    if wavs:
                        wname = ''.join(w.capitalize() for w in wavs[0].split('_'))
                        discovered[addr] = f"Sound_Play_{wname}"
                        continue

                # 4. Sprites & Pics
                if ".spr" in strs.lower():
                    sprs = re.findall(r'([a-zA-Z0-9_]+)\.spr', strs.lower())
                    if sprs:
                        sname = ''.join(w.capitalize() for w in sprs[0].split('_'))
                        discovered[addr] = f"Sprite_Load_{sname}"
                        continue

                if ".pic" in strs.lower():
                    pics = re.findall(r'([a-zA-Z0-9_]+)\.pic', strs.lower())
                    if pics:
                        pname = ''.join(w.capitalize() for w in pics[0].split('_'))
                        discovered[addr] = f"Pic_Load_{pname}"
                        continue

                # 5. CSV and text files
                if ".csv" in strs.lower() or ".txt" in strs.lower():
                    files = re.findall(r'([a-zA-Z0-9_]+)\.(csv|txt)', strs.lower())
                    if files:
                        fname = ''.join(w.capitalize() for w in files[0][0].split('_'))
                        discovered[addr] = f"File_Load_{fname}"
                        continue

    return discovered

# ------------------------------------------------------------------------------
# 3. CSV File Updates
# ------------------------------------------------------------------------------
def update_all_csvs(func_map):
    print(">>> Updating all CSV symbol maps with extended symbols...")

    # 1. Update engine_globals_map.csv
    globals_csv = os.path.join(BASE_DIR, "engine_globals_map.csv")
    existing_globals = {}
    if os.path.exists(globals_csv):
        with open(globals_csv, 'r', encoding='utf-8') as f:
            r = csv.reader(f)
            next(r, None)
            for row in r:
                if len(row) >= 2:
                    existing_globals[row[0].strip().lower()] = row[1].strip()

    for addr, name in EXTRA_DAT_MAP.items():
        existing_globals[addr.lower()] = name

    with open(globals_csv, 'w', newline='', encoding='utf-8') as f:
        w = csv.writer(f)
        w.writerow(["Address", "NewName"])
        for addr, name in sorted(existing_globals.items()):
            w.writerow([addr, name])

    print(f"  -> engine_globals_map.csv total: {len(existing_globals)}")

    # 2. Update unified_engine_symbol_map.csv
    unified_csv = os.path.join(BASE_DIR, "unified_engine_symbol_map.csv")
    unified_map = {}
    if os.path.exists(unified_csv):
        with open(unified_csv, 'r', encoding='utf-8') as f:
            r = csv.reader(f)
            next(r, None)
            for row in r:
                if len(row) >= 3:
                    unified_map[row[0].strip().lower()] = (row[1].strip(), row[2].strip())

    for addr, new_name in func_map.items():
        addr_lower = addr.lower()
        old_name = unified_map.get(addr_lower, (f"FUN_{addr_lower}", f"FUN_{addr_lower}"))[0]
        unified_map[addr_lower] = (old_name, new_name)

    with open(unified_csv, 'w', newline='', encoding='utf-8') as f:
        w = csv.writer(f)
        w.writerow(["Address", "OldName", "NewName"])
        for addr, (old_name, new_name) in sorted(unified_map.items()):
            w.writerow([addr, old_name, new_name])

    print(f"  -> unified_engine_symbol_map.csv total: {len(unified_map)}")

# ------------------------------------------------------------------------------
# 4. Source Refactoring Engine
# ------------------------------------------------------------------------------
def refactor_codebase(func_map):
    print(">>> Refactoring source code files with advanced cleanups...")

    # Symbol replacement dictionary
    rep_dict = {}

    for addr, name in EXTRA_DAT_MAP.items():
        rep_dict[f"DAT_{addr}"] = name
        rep_dict[f"_DAT_{addr}"] = name

    for addr, name in func_map.items():
        rep_dict[f"FUN_{addr}"] = name
        for prefix in ["Ai_Subsystem_", "Ai_ScoreCardPlay_", "Ai_Util_", "Pic_Load_", "Minit_Subsystem_", "Minit_Util_", "Mem_AllocOrFree_", "Pic_Subsystem_", "Pic_Util_", "UI_WndProc_", "UI_DialogProc_", "UI_CreateWindow_", "Assert_Handler_"]:
            rep_dict[f"{prefix}{addr}"] = name

    # Standard parameter and local variable replacements
    var_patterns = [
        (r'\bint\s+arg_1\b', 'int player_id'),
        (r'\bint\s+arg_2\b', 'int card_slot'),
        (r'\bint\s+arg_3\b', 'int event_type'),
        (r'\bvoid\s+arg_1\b', 'void player_id'),
        (r'\bchar\s+\*str_1\b', 'char *filepath'),
        (r'\bchar\s+\*str_2\b', 'char *mode_str'),
        (r'\blocal_8\b', 'slot_idx'),
        (r'\blocal_10\b', 'card_idx'),
        (r'\blocal_14\b', 'player_idx'),
        (r'\blocal_18\b', 'target_idx'),
        (r'\blocal_1c\b', 'color_idx'),
        (r'\blocal_20\b', 'loop_idx'),
        (r'\blocal_c\b', 'match_count'),
    ]

    files = glob.glob(os.path.join(BASE_DIR, "src/**/*.c"), recursive=True) + \
            glob.glob(os.path.join(BASE_DIR, "include/**/*.h"), recursive=True)

    updated_count = 0
    for fpath in files:
        # Don't touch hand-written headers/shims with regex heuristics
        is_shim = "platform" in fpath or fpath.endswith("sprite.c") or fpath.endswith("Catalog.c") or fpath.endswith("shandalar.h")

        with open(fpath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()

        orig = content

        # Replace DATs and Function names
        for old_sym, new_sym in rep_dict.items():
            if old_sym in content:
                content = re.sub(r'\b' + old_sym + r'\b', new_sym, content)

        if not is_shim and fpath.endswith('.c'):
            for pat, repl in var_patterns:
                content = re.sub(pat, repl, content)

        if content != orig:
            with open(fpath, 'w', encoding='utf-8') as f:
                f.write(content)
            updated_count += 1
            print(f"  -> Cleaned: {os.path.relpath(fpath, BASE_DIR)}")

    print(f"Cleaned and updated {updated_count} files.")

# ------------------------------------------------------------------------------
# 5. Ghidra Headless Sync
# ------------------------------------------------------------------------------
def sync_ghidra():
    print(">>> Synchronizing with Ghidra database...")
    env = os.environ.copy()
    env["JAVA_HOME"] = JAVA_HOME
    env["PATH"] = f"{JAVA_HOME}/bin:" + env.get("PATH", "")

    for prog in ["MAGIC.EXE", "DUEL.EXE"]:
        for script in ["RenameGlobalSymbols.java", "ApplyUnifiedSymbols.java", "RenameFunctionParameters.java"]:
            cmd = [
                GHIDRA_HEADLESS,
                "/Users/ben",
                "ShandalarDecomp",
                "-process", prog,
                "-noanalysis",
                "-scriptPath", os.path.join(BASE_DIR, "scripts"),
                "-postScript", script
            ]
            res = subprocess.run(cmd, env=env, capture_output=True, text=True)
            if res.returncode == 0:
                print(f"     [OK] {script} -> {prog}")
            else:
                print(f"     [WARN] {script} -> {prog}: {res.stderr[:100]}")

def main():
    print("==========================================================")
    print(" Starting Advanced Symbol & Variable Cleaning Pipeline")
    print("==========================================================")

    func_map = discover_functions_from_context()
    print(f"Total discovered functions from context: {len(func_map)}")

    update_all_csvs(func_map)
    refactor_codebase(func_map)
    sync_ghidra()

    print("==========================================================")
    print(" Advanced Cleaning Pipeline Completed!")
    print("==========================================================")

if __name__ == "__main__":
    main()
