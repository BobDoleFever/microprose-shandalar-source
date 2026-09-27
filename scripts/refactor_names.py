#!/usr/bin/env python3
"""
refactor_names.py - Comprehensive Renaming Engine for Shandalar Decompilation
Renames DAT globals, functions, variables, and parameters across the C codebase and Ghidra database.
"""

import os
import re
import csv
import glob

BASE_DIR = "/Users/ben/decomp"

# ==============================================================================
# 1. Global DAT Variable Mappings
# ==============================================================================
DAT_RENAMES = {
    # Card Slot Structure Fields (0x006a5f30 base, 0x120 stride, 0x5b20 player stride)
    "DAT_006a5f30": "g_ActiveCardsInPlay",
    "DAT_006a5f34": "g_CardSlot_CardId",
    "DAT_006a5f38": "g_CardSlot_Controller",
    "DAT_006a5f3c": "g_CardSlot_Flags",
    "DAT_006a5f3e": "g_CardSlot_Subtypes",
    "DAT_006a5f40": "g_CardSlot_Power",
    "DAT_006a5f42": "g_CardSlot_Toughness",
    "DAT_006a5f43": "g_CardSlot_DamageReceived",
    "DAT_006a5f44": "g_CardSlot_Counters",
    "DAT_006a5f48": "g_CardSlot_PowerCounters",
    "DAT_006a5f4a": "g_CardSlot_ToughnessCounters",
    "DAT_006a5f4c": "g_CardSlot_PlusOneCounters",
    "DAT_006a5f4d": "g_CardSlot_MinusOneCounters",
    "DAT_006a5f4e": "g_CardSlot_ColorMask",
    "DAT_006a5f54": "g_CardSlot_ConvertedManaCost",
    "DAT_006a5f58": "g_CardSlot_OriginalCardId",
    "DAT_006a5f5c": "g_CardSlot_TypeFlags",
    "DAT_006a5f60": "g_CardSlot_TargetSlot",
    "DAT_006a5f64": "g_CardSlot_DisplayIndex",
    "DAT_006a5f68": "g_CardSlot_Abilities1",
    "DAT_006a5f6c": "g_CardSlot_Abilities2",
    "DAT_006a5f88": "g_CardSlot_CombatTarget",
    "DAT_006a5f8c": "g_CardSlot_AttachedAura",
    "DAT_006a6020": "g_CardSlot_TapState",
    "DAT_006a6024": "g_CardSlot_SicknessState",
    "DAT_006a6028": "g_CardSlot_TurnPlayed",
    "DAT_006a6038": "g_CardSlot_ProtectionFlags",
    "DAT_006a6044": "g_CardSlot_SpecialState",
    "DAT_0067bdf0": "g_CardSlot_CreatureType",
    "DAT_0067be00": "g_CardSlot_StatusFlags",
    "DAT_0067bdb0": "g_CardSlot_PowerBonus",
    "DAT_0067b9a4": "g_CardSlot_ToughnessBonus",

    # Rules Engine, Turn Progression & Scan Logic
    "DAT_006fe3f8": "g_CardScanDepth",
    "DAT_0068a704": "g_CurrentScanningCardIndex",
    "DAT_007006e0": "g_CardDisplayOrder_Player",
    "DAT_006a5750": "g_CardDisplayOrder_Slot",
    "DAT_0051aec8": "g_CardScriptCallbackTable",
    "DAT_0051aec0": "g_MasterCardManaCostTable",
    "DAT_0051aebe": "g_MasterCardColorTable",
    "DAT_0051aeb8": "g_MasterCardTypeTable",
    "DAT_0051aea8": "g_MasterCardTable",
    "DAT_0051aed0": "g_MasterCardSubtypeTable",
    "DAT_0068a64c": "g_GlobalEnchantmentCardId",
    "DAT_006a49fc": "g_ActivePlayer",
    "DAT_0068a71c": "g_TurnPlayer",
    "DAT_006a49e0": "g_CurrentTurnPhase",
    "DAT_006a49f8": "g_TurnCounter",
    "DAT_006a492c": "g_ActivePlayerPriority",
    "DAT_006a4a00": "g_PlayerCreatureCount",
    "DAT_006a4a08": "g_DuelModeFlags",
    "DAT_00695e80": "g_PlayerLifeTotals",
    "DAT_006808b8": "g_PlayerActiveCardCount",
    "DAT_006ff558": "g_ScWillyScore",
    "DAT_006ff55c": "g_AiChoiceValue",
    "DAT_006ff680": "g_SpellStackDepth",
    "DAT_006ff4c0": "g_CurrentStepCode",
    "DAT_0067f440": "g_MasterCardCount",
    "DAT_006ff2d4": "g_PendingAttackersTargetSlot",
    "DAT_006ff2e0": "g_PendingSpellTargetSlot",
    "DAT_006a4920": "g_CombatPhaseFlags",
    "DAT_006a4924": "g_TurnPriorityState",
    "DAT_006ff2f0": "g_ActiveCombatRoundCounter",
    "DAT_006ff1ac": "g_AiAttackingCreatureCount",
    "DAT_006ff19c": "g_AiBlockingCreatureCount",
    "DAT_006a5f20": "g_ActiveBattlefieldFlag",
    "DAT_006a3f78": "g_SpellStackCount",
    "DAT_006fefa8": "g_AiCurrentSearchPath",
    "DAT_006fe400": "g_AiDuelTurnState",
    "DAT_006fedc0": "g_AiTurnDecisionFlag",
    "DAT_00695ec8": "g_AiCombatDamageAssigned",
    "DAT_00695e88": "g_AiPlayerLifeDifferential",
    "DAT_0069e720": "g_AiLookaheadTreeRoot",
    "DAT_0068a73c": "g_AiEvaluationTimeout",
    "DAT_00695ea0": "g_AiPlayerHandDifferential",
    "DAT_0067f2d4": "g_AiCardEvaluationScore",
    "DAT_0067f2d8": "g_AiCardSynergyScore",
    "DAT_00627a7c": "g_AiCombatLookaheadTarget",

    # AI Lookahead Backup Buffers (Ai_SaveGameState / Ai_RestoreGameState)
    "DAT_00627a90": "g_AiSavedCardsInPlay",
    "DAT_006330f0": "g_AiSavedMasterCardTable",
    "DAT_00554050": "g_AiSavedLookaheadTreeCurrentNode",
    "DAT_0054e818": "g_AiSavedEvaluationPassCounter",
    "DAT_0054c620": "g_AiSavedTemporaryBuffer",
    "DAT_0054e7d8": "g_AiSavedCombatScore_Total",
    "DAT_0054e790": "g_AiSavedLookaheadDepth",
    "DAT_00555900": "g_AiSavedCombatScore_Attacker",
    "DAT_005532a0": "g_AiSavedManaReserveBuffer",
    "DAT_00553438": "g_AiSavedPlayerCreatureCount",
    "DAT_00554048": "g_AiSavedActiveTurnState",
    "DAT_00555100": "g_AiSavedDuelTurnState",
    "DAT_005550f8": "g_AiSavedLifeTotals",
    "DAT_005501a0": "g_AiSavedAbilityScoreBuffer",
    "DAT_0054f7b8": "g_AiSavedSelectedAbilityIndex",
    "DAT_005529b8": "g_AiSavedCardDisplayOrder_Player",
    "DAT_005518f8": "g_AiSavedCardDisplayOrder_Slot",
    "DAT_00555980": "g_AiSavedPlayerHandCardCount",
    "DAT_00550480": "g_AiSavedScWillyScore",
    "DAT_006498f0": "g_AiSavedScWillyScoreAlt",
    "DAT_00554ff0": "g_AiSavedDefendingPlayer",
    "DAT_0055319c": "g_AiSavedActiveBattlefieldFlag",
    "DAT_0054be40": "g_AiSavedActivePlayer",
    "DAT_00552938": "g_AiSavedSpellStackEntries",
    "DAT_00554ff8": "g_AiSavedDuelArenaStatusFlags",
    "DAT_00550308": "g_AiSavedCombatEvaluationState",
    "DAT_005558f8": "g_AiSavedPlayerActiveCardCount",
    "DAT_0054e5e8": "g_AiSavedEvaluatedMoveCount",
    "DAT_00550178": "g_AiSavedPlayerLifeDifferential",
    "DAT_005528cc": "g_AiSavedCardDisplayOrderCount",
    "DAT_00550038": "g_AiSavedDialogPromptBuffer",
    "DAT_00550450": "g_AiSavedMasterCardCountBuffer",
    "DAT_00550180": "g_AiSavedSelectedTargetCard",
    "DAT_00556928": "g_AiSavedGameStateCounter",

    # AI Heuristic Weights & Decision Tables
    "DAT_00559a94": "g_AiCreaturePowerEval",
    "DAT_00559a20": "g_AiCreatureToughnessEval",
    "DAT_00559b1c": "g_AiCombatScoreBuffer",
    "DAT_006b2d40": "g_AiSelectedTargetCard",
    "DAT_0063ee90": "g_AiLookaheadDepth",
    "DAT_005574b0": "g_AiPlayerScoreTable",
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
    "DAT_006410f0": "g_AiBestScore",
    "DAT_006410f4": "g_AiBestCardIndex",
    "DAT_006410f8": "g_AiBestTargetPlayer",
    "DAT_00559848": "g_AiCandidateCardList",
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
    "DAT_006498d0": "g_AiLookaheadScore_Player0",
    "DAT_006498d4": "g_AiLookaheadScore_Player1",
    "DAT_006498d8": "g_AiLookaheadDelta",
    "DAT_006498dc": "g_AiLookaheadBestMove",
    "DAT_0055a008": "g_AiDamageAssignmentBuffer",
    "DAT_0063ee30": "g_AiCombatScore_Attacker",
    "DAT_0063ee18": "g_AiCombatScore_Blocker",
    "DAT_0063edd0": "g_AiCombatScore_Total",
    "DAT_006b2e2c": "g_AiSelectedActionCode",
    "DAT_00556b18": "g_AiHeuristicWeight_BoardThreat",
    "DAT_00556c60": "g_AiHeuristicWeight_Regeneration",
    "DAT_0055699c": "g_AiHeuristicWeight_ManaEfficiency",
    "DAT_005569d8": "g_AiHeuristicWeight_Evasion",
    "DAT_006ff4ac": "g_AiManaPoolReserve",
    "DAT_0052d770": "g_AiHeuristicWeight_HandAdvantage",
    "DAT_0055a010": "g_AiLethalDamageFlag",
    "DAT_00556938": "g_AiHeuristicWeight_Aggression",
    "DAT_006b2e28": "g_AiCandidateActionCount",
    "DAT_006b2d60": "g_AiSelectedCardTargetSlot",
    "DAT_006776a0": "g_AiBackupBoardRegister",
    "DAT_00559890": "g_AiCandidatePriorityList",
    "DAT_00559b80": "g_AiCombatRoundResult",
    "DAT_005520c8": "g_AiCardScore_BasicLand",
    "DAT_00556b20": "g_AiHeuristicWeight_Removal",
    "DAT_00627864": "g_AiTemporaryCardState",
    "DAT_0055747c": "g_AiHeuristicWeight_Tempo",

    # Directories, Paths & Campaign State
    "DAT_006807a0": "g_GameInstallDirectory",
    "DAT_006ff1b0": "g_PlayDeckDirectory",
    "DAT_006a4a50": "g_FacesDirectory",
    "DAT_006808d0": "g_CardArtDirectory",
    "DAT_00696910": "g_DuelSoundsDirectory",
    "DAT_006ff570": "g_DuelDatFilePath",
    "DAT_006a28c0": "g_SaveGameDirectory",
    "DAT_006a49f4": "g_CardsDatLoadedHandle",
    "DAT_0069f750": "g_OverworldGoldAmount",
    "DAT_00678830": "g_OverworldFoodAmount",
    "DAT_00626850": "g_OverworldWorldState",
    "DAT_0070100c": "g_EventSourceSlot",
    "DAT_006b2534": "g_EventSourcePlayer",
    "DAT_006b2d68": "g_OverworldPlayerCoordY",
    "DAT_0052eff0": "g_OverworldMapPixelX",
    "DAT_0052eff4": "g_OverworldMapPixelY",
    "DAT_006a28b0": "g_PlayerGoldCoins",
    "DAT_006b2e30": "g_PlayerAmuletGems",

    # Graphics, Palettes, KIM/PIC & Haar Wavelets
    "DAT_00517444": "g_DisplaySurfaceScreen",
    "DAT_0051746c": "g_DisplaySurfaceBackBuffer",
    "DAT_00517494": "g_DisplaySurfaceWork",
    "DAT_0070a850": "g_ScreenSurfaces",
    "DAT_0068a654": "g_HdcBackBuffer",
    "DAT_0068a660": "g_CardEventResult",
    "DAT_0068a630": "g_ScreenDC",
    "DAT_0054aefc": "g_OctreeColorTreeRoot",
    "DAT_0054b324": "g_PaletteDitherInitialized",
    "DAT_0052afc0": "g_ActiveDitherPaletteId",
    "DAT_00703930": "g_PicFileStream",
    "DAT_00536860": "g_PicSourceWidth",
    "DAT_00536864": "g_PicSourceHeight",
    "DAT_00538ad4": "g_PicAlignedRowPitch",
    "DAT_00538adc": "g_PicScanlineCounter",
    "DAT_007039cc": "g_MouseCursorX",
    "DAT_007039c8": "g_MouseCursorY",
    "DAT_0067f7d0": "g_SoundChannelTable",

    # Win32 Frontend Handles
    "DAT_006b2e34": "g_MainAppHwnd",
    "DAT_006fecb0": "g_AppHInstance",
    "DAT_006fe488": "g_DuelArenaHwnd",
    "DAT_00700eb0": "g_DialogPromptHwnd",
}

# ==============================================================================
# 2. Function Name Mappings (Context & Semantic Based)
# ==============================================================================
FUNCTION_RENAMES = {
    # UI & Dialog Procs
    "FUN_00401000": "UI_BigCardDialogProc",
    "FUN_00401c91": "UI_RegisterSmallCardClass",
    "FUN_00401e65": "UI_RegisterBigCardClass",
    "FUN_00401f70": "UI_CardListWndProc",
    "FUN_0040360b": "Rules_ParseCardQueryFilter",
    "FUN_00405370": "UI_FormatActionPrompt",
    "FUN_00405802": "UI_ReportIllegalTarget",
    "FUN_004060e0": "Catalog_LoadInfoCsv",
    "FUN_004063b8": "Catalog_LoadMasterCsv",
    "FUN_004064f8": "Catalog_SaveConciseCsv",
    "FUN_0040659f": "Catalog_LoadConciseCsv",
    "FUN_00406681": "Catalog_SearchMasterCsv",
    "FUN_00406b4c": "Catalog_ParseDeckProfile",
    "FUN_0040706f": "Story_LoadCampaignText",
    "FUN_0040710a": "Story_LoadTaleText",
    "FUN_004071ce": "Story_LoadHintsText",
    "FUN_0040741b": "Story_SearchHintByKeyword",
    "FUN_00407b34": "Bazaar_CardSellerDialogue",
    "FUN_004081b0": "UI_RegisterCueCardClass",
    "FUN_004082d1": "UI_UnregisterCueCardClass",
    "FUN_0040836a": "UI_CueCardWndProc",
    "FUN_004088d0": "UI_UpdateCueCardPosition",
    "FUN_00408e20": "UI_RegisterFaceClass",
    "FUN_00409052": "UI_UnregisterFaceClass",
    "FUN_004090f6": "UI_DuelArenaMenuProc",
    "FUN_004097e2": "UI_RenderDuelStatusBanner",
    "FUN_00409d10": "Subsystem_LoadStatWinDll",
    "FUN_00409db6": "Subsystem_FreeStatWinDll",
    "FUN_0040a1ff": "Ai_SyncLookaheadBuffers",
    "FUN_0040c3cc": "UI_DrawCombatString",

    # Image, Pic & Kimpic Decompression
    "Pic_Load_0042351b": "Pic_LoadImageFile",
    "FUN_004232f0": "Pic_AllocateImageBuffer",
    "FUN_00512500": "Pic_DecodeKimpicHeader",
    "FUN_005126b0": "Pic_DecodeKimpicScanline",
    "Pic_Subsystem_004238ba": "Pic_OpenArchiveStream",
    "Pic_Util_00423919": "Pic_SeekImageStream",
    "FUN_0070d000": "Pic_ReadCompressedChunk",

    # Minit & Engine Initialization
    "Minit_Subsystem_00452827": "Engine_CountActiveCreatures",
    "Minit_Subsystem_004528c0": "UI_DrawManaSymbolBox",
    "Minit_Util_0045280c": "Ai_TriggerTurnPhaseEvaluation",
    "Pic_Subsystem_0044b8da": "UI_PrepareCombatViewport",
    "Ai_Subsystem_004cc9c5": "Ai_EvaluateTacticalPosition",
    "Assert_Handler_005019a0": "AssertOrLog",

    # Rules Engine & Phase Helpers (Magic.c)
    "FUN_004728c3": "Rules_ValidateCardTargetSlot",
    "FUN_00473e69": "Magic_BroadcastCardEvent",
    "FUN_00472fae": "Rules_ProcessCombatDamageStep",
    "FUN_00473cc5": "Rules_CalculateManaCostReduction",
    "FUN_00473ce8": "Rules_CalculateColorCost",
    "FUN_00473d09": "Rules_GetCardConvertedManaCost",
    "FUN_00473060": "Rules_TriggerEndOfTurnPhase",
    "FUN_004738a0": "Rules_ResolveSpellEffect",

    # AI Tactical Decision Subsystems (Ai.c)
    "Ai_Subsystem_004ad77b": "Ai_InitCombatHeuristics",
    "Ai_Subsystem_004ae716": "Ai_EvaluateManaCurve",
    "Ai_Subsystem_004ae779": "Ai_ScoreBoardPermanents",
    "Ai_Subsystem_004ae8a3": "Ai_CalculateCombatOdds",
    "Ai_Subsystem_004af5e3": "Ai_FindOptimalSpellTarget",
    "Ai_Subsystem_004af640": "Ai_EvaluateInstantSpells",
    "Ai_Subsystem_004af765": "Ai_ScoreAttackerCombination",
    "Ai_GetPlanCursor": "Ai_ClearCandidateScoreList",
    "Ai_Util_004ab525": "Ai_SortCandidateScoreList",
    "Ai_Util_004afa46": "Ai_GetHighestPriorityMove",
    "Ai_ScoreCardPlay_004afa69": "Ai_EvaluateCreatureCast",
    "Ai_ScoreCardPlay_004afc26": "Ai_EvaluateSpellCast",
}

def refactor_file(filepath):
    with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    orig_content = content

    # 1. Replace DAT globals
    for dat, new_name in DAT_RENAMES.items():
        if dat in content:
            content = re.sub(r'\b' + dat + r'\b', new_name, content)
            content = re.sub(r'\b_' + dat + r'\b', new_name, content)

    # 2. Replace Function names
    for fun, new_name in FUNCTION_RENAMES.items():
        if fun in content:
            content = re.sub(r'\b' + fun + r'\b', new_name, content)

    if content != orig_content:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
        return True
    return False

def update_csv_maps():
    print("Updating CSV symbol maps...")

    # 1. Update engine_globals_map.csv
    globals_csv = os.path.join(BASE_DIR, "engine_globals_map.csv")
    existing_globals = {}
    if os.path.exists(globals_csv):
        with open(globals_csv, 'r', encoding='utf-8') as f:
            r = csv.reader(f)
            header = next(r, None)
            for row in r:
                if len(row) >= 2:
                    existing_globals[row[0].strip()] = row[1].strip()

    for dat, new_name in DAT_RENAMES.items():
        addr = dat.replace("DAT_", "").lower()
        existing_globals[addr] = new_name

    with open(globals_csv, 'w', newline='', encoding='utf-8') as f:
        w = csv.writer(f)
        w.writerow(["Address", "NewName"])
        for addr, name in sorted(existing_globals.items()):
            w.writerow([addr, name])

    print(f"Updated engine_globals_map.csv with {len(existing_globals)} global symbols.")

    # 2. Update unified_engine_symbol_map.csv
    unified_csv = os.path.join(BASE_DIR, "unified_engine_symbol_map.csv")
    unified_map = {}
    if os.path.exists(unified_csv):
        with open(unified_csv, 'r', encoding='utf-8') as f:
            r = csv.reader(f)
            header = next(r, None)
            for row in r:
                if len(row) >= 3:
                    unified_map[row[0].strip()] = (row[1].strip(), row[2].strip())

    for fun, new_name in FUNCTION_RENAMES.items():
        addr_match = re.search(r'00[0-9a-fA-F]{6}', fun)
        if addr_match:
            addr = addr_match.group(0).lower()
            old_name = unified_map.get(addr, (fun, fun))[0]
            unified_map[addr] = (old_name, new_name)

    with open(unified_csv, 'w', newline='', encoding='utf-8') as f:
        w = csv.writer(f)
        w.writerow(["Address", "OldName", "NewName"])
        for addr, (old_name, new_name) in sorted(unified_map.items()):
            w.writerow([addr, old_name, new_name])

    print(f"Updated unified_engine_symbol_map.csv with {len(unified_map)} function symbols.")

def main():
    print("==========================================================")
    print(" Starting Comprehensive Codebase Renaming & Refactoring")
    print("==========================================================")

    # 1. Update CSV symbol maps
    update_csv_maps()

    # 2. Refactor C files in src/
    refactored_count = 0
    c_files = glob.glob(os.path.join(BASE_DIR, "src/**/*.c"), recursive=True)
    h_files = glob.glob(os.path.join(BASE_DIR, "include/**/*.h"), recursive=True)

    all_files = c_files + h_files
    for f in all_files:
        if refactor_file(f):
            refactored_count += 1
            print(f"  -> Refactored: {os.path.relpath(f, BASE_DIR)}")

    print(f"Successfully refactored {refactored_count} source/header files!")

if __name__ == "__main__":
    main()
