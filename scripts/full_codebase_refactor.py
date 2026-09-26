#!/usr/bin/env python3
"""
full_codebase_refactor.py - Comprehensive Symbolic Refactoring Engine
Extracts semantic names from string contexts, Win32 APIs, MTG rules, and updates
both the ANSI C source code and the Ghidra database.
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
# 1. Comprehensive Global DAT Symbol Map
# ------------------------------------------------------------------------------
GLOBAL_DAT_MAP = {
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
    "00666458": "g_DuelDefendingPlayer",
    "0066642c": "g_DuelCurrentTurnPhase",
    "00666408": "g_DuelPlayerCreatureCount",
    "00681ea0": "g_DuelTurnCounter",
    "00681eb0": "g_DuelPlayerManaPool",
    "00681ea8": "g_DuelPlayerLifeTotals",
    "00681ea4": "g_DuelHumanPlayerIndex",
    "00690c48": "g_DuelActiveCardSlot",
    "0068ecb0": "g_DuelActivePlayer",
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
    # Card Slot Structure Fields (0x006a5f30 base, 0x120 stride, 0x5b20 player stride)
    "006a5f30": "g_ActiveCardsInPlay",
    "006a5f34": "g_CardSlot_CardId",
    "006a5f38": "g_CardSlot_Controller",
    "006a5f3c": "g_CardSlot_Flags",
    "006a5f3e": "g_CardSlot_Subtypes",
    "006a5f40": "g_CardSlot_Power",
    "006a5f42": "g_CardSlot_Toughness",
    "006a5f43": "g_CardSlot_DamageReceived",
    "006a5f44": "g_CardSlot_Counters",
    "006a5f48": "g_CardSlot_PowerCounters",
    "006a5f4a": "g_CardSlot_ToughnessCounters",
    "006a5f4c": "g_CardSlot_PlusOneCounters",
    "006a5f4d": "g_CardSlot_MinusOneCounters",
    "006a5f4e": "g_CardSlot_ColorMask",
    "006a5f50": "g_CardSlot_CardTypeIndex",
    "006a5f54": "g_CardSlot_ConvertedManaCost",
    "006a5f58": "g_CardSlot_OriginalCardId",
    "006a5f5c": "g_CardSlot_TypeFlags",
    "006a5f60": "g_CardSlot_TargetSlot",
    "006a5f64": "g_CardSlot_DisplayIndex",
    "006a5f68": "g_CardSlot_Abilities1",
    "006a5f6c": "g_CardSlot_Abilities2",
    "006a5f88": "g_CardSlot_CombatTarget",
    "006a5f8c": "g_CardSlot_AttachedAura",
    "006a6020": "g_CardSlot_TapState",
    "006a6024": "g_CardSlot_SicknessState",
    "006a6028": "g_CardSlot_TurnPlayed",
    "006a6038": "g_CardSlot_ProtectionFlags",
    "006a6044": "g_CardSlot_SpecialState",
    "0067bdf0": "g_CardSlot_CreatureType",
    "0067be00": "g_CardSlot_StatusFlags",
    "0067bdb0": "g_CardSlot_PowerBonus",
    "0067b9a4": "g_CardSlot_ToughnessBonus",

    # Rules Engine, Turn Progression & Scan Logic
    "006fe3f8": "g_CardScanDepth",
    "0068a704": "g_CurrentScanningCardIndex",
    "007006e0": "g_CardDisplayOrder_Player",
    "006a5750": "g_CardDisplayOrder_Slot",
    "0051aec8": "g_CardScriptCallbackTable",
    "0051aec0": "g_MasterCardManaCostTable",
    "0051aebe": "g_MasterCardColorTable",
    "0051aebf": "g_MasterCardSubTypeTable2",
    "0051aebd": "g_MasterCardRarityTable",
    "0051aed1": "g_MasterCardFlagsTable",
    "0051aeb8": "g_MasterCardTypeTable",
    "0051aea8": "g_MasterCardTable",
    "0051aed0": "g_MasterCardSubtypeTable",
    "0068a64c": "g_GlobalEnchantmentCardId",
    "006a49fc": "g_ActivePlayer",
    "0068a71c": "g_DefendingPlayer",
    "006a49e0": "g_CurrentTurnPhase",
    "006a49f8": "g_TurnCounter",
    "006a492c": "g_ActivePlayerPriority",
    "006a4a00": "g_PlayerCreatureCount",
    "006a4a04": "g_PlayerDeckCardCount",
    "006a4a08": "g_PlayerHandCardCount",
    "00695e80": "g_PlayerLifeTotals",
    "006808b8": "g_PlayerActiveCardCount",
    "006ff558": "g_ScWillyScore",
    "006ff55c": "g_AiDecisionScore",
    "006ff680": "g_SpellStackDepth",
    "006ff4c0": "g_PlayerManaPool",
    "00696740": "g_PlayerManaPoolAvailable",
    "0063ee4c": "g_PlayerManaPoolDelta",
    "0067f440": "g_MasterCardCount",
    "006ff2d4": "g_PendingAttackersTargetSlot",
    "006ff2e0": "g_PendingSpellTargetSlot",
    "006a4920": "g_CombatPhaseFlags",
    "006a4924": "g_TurnPriorityState",
    "006ff2f0": "g_ActiveCombatRoundCounter",
    "006ff1ac": "g_AiAttackingCreatureCount",
    "006ff19c": "g_AiBlockingCreatureCount",
    "006a5f20": "g_ActiveBattlefieldFlag",
    "006a3f78": "g_AiEvaluatedMoveCount",
    "006fefa8": "g_AiCurrentSearchPath",
    "006fe400": "g_AiDuelTurnState",
    "006fedc0": "g_AiTurnDecisionFlag",
    "00695ec8": "g_AiCombatDamageAssigned",
    "00695e88": "g_AiPlayerLifeDifferential",
    "0069e720": "g_AiLookaheadTreeRoot",
    "0068a73c": "g_AiEvaluationTimeout",
    "00695ea0": "g_AiPlayerHandDifferential",
    "0067f2d4": "g_AiCardEvaluationScore",
    "0067f2d8": "g_AiCardSynergyScore",
    "00627a7c": "g_AiCombatLookaheadTarget",
    "0069e730": "g_PlayerDeckCardList",
    "006ff710": "g_PlayerGraveyardList",
    "006b2d2c": "g_SelectedTargetSlot",
    "006b2d3c": "g_SelectedTargetPlayer",
    "006a2828": "g_PlayerPoisonCounters",
    "00649c20": "g_PaletteColorMatchBuffer",
    "0067f014": "g_TownBuildingFlagsTable",
    "0067bda4": "g_MouseScreenCoordX",
    "0067bda8": "g_MouseScreenCoordY",
    "00680770": "g_MouseCaptureFlag",

    # AI Lookahead Backup Buffers (Ai_SaveGameState / Ai_RestoreGameState)
    "00627a90": "g_AiSavedCardsInPlay",
    "006330f0": "g_AiSavedMasterCardTable",
    "00554050": "g_AiSavedLookaheadTreeCurrentNode",
    "0054e818": "g_AiSavedEvaluationPassCounter",
    "0054c620": "g_AiSavedTemporaryBuffer",
    "0054e7d8": "g_AiSavedCombatScore_Total",
    "0054e790": "g_AiSavedLookaheadDepth",
    "00555900": "g_AiSavedCombatScore_Attacker",
    "005532a0": "g_AiSavedManaReserveBuffer",
    "00553438": "g_AiSavedPlayerCreatureCount",
    "00554048": "g_AiSavedActiveTurnState",
    "00555100": "g_AiSavedDuelTurnState",
    "005550f8": "g_AiSavedLifeTotals",
    "005501a0": "g_AiSavedAbilityScoreBuffer",
    "0054f7b8": "g_AiSavedSelectedAbilityIndex",
    "005529b8": "g_AiSavedCardDisplayOrder_Player",
    "005518f8": "g_AiSavedCardDisplayOrder_Slot",
    "00555980": "g_AiSavedPlayerHandCardCount",
    "00550480": "g_AiSavedScWillyScore",
    "006498f0": "g_AiSavedScWillyScoreAlt",
    "00554ff0": "g_AiSavedDefendingPlayer",
    "0055319c": "g_AiSavedActiveBattlefieldFlag",
    "0054be40": "g_AiSavedActivePlayer",
    "00552938": "g_AiSavedPlayerManaPool",
    "00554ff8": "g_AiSavedDuelArenaStatusFlags",
    "00550308": "g_AiSavedCombatEvaluationState",
    "005558f8": "g_AiSavedPlayerActiveCardCount",
    "0054e5e8": "g_AiSavedEvaluatedMoveCount",
    "00550178": "g_AiSavedPlayerLifeDifferential",
    "005528cc": "g_AiSavedCardDisplayOrderCount",
    "00550038": "g_AiSavedDialogPromptBuffer",
    "00550450": "g_AiSavedMasterCardCountBuffer",
    "00550180": "g_AiSavedSelectedTargetCard",
    "00556928": "g_AiSavedGameStateCounter",

    # AI Heuristic Weights & Decision Tables
    "00559a94": "g_AiCreaturePowerEval",
    "00559a20": "g_AiCreatureToughnessEval",
    "00559b1c": "g_AiCombatScoreBuffer",
    "006b2d40": "g_AiSelectedTargetCard",
    "0063ee90": "g_AiLookaheadDepth",
    "005574b0": "g_AiPlayerScoreTable",
    "005596b8": "g_AiAttackerList",
    "00522450": "g_AiManaColorCost_White",
    "00522454": "g_AiManaColorCost_Blue",
    "00522458": "g_AiManaColorCost_Red",
    "0052245c": "g_AiManaColorCost_Green",
    "005595f8": "g_AiBlockerList",
    "0054be44": "g_AiBestScoreTable",
    "00627a20": "g_AiTempTargetBuffer",
    "006b2e90": "g_AiCurrentChoiceIndex",
    "0055a050": "g_AiCombatDamageTable",
    "0067f2c0": "g_AiHandEvaluationBuffer",
    "006410f0": "g_AiBestScore",
    "006410f4": "g_AiBestCardIndex",
    "006410f8": "g_AiBestTargetPlayer",
    "00559848": "g_AiCandidateCardList",
    "00556ae8": "g_AiHeuristicWeight_CreaturePower",
    "00633430": "g_AiGameStateBackupBuffer",
    "0052d5cc": "g_AiHeuristicWeight_LifeAdvantage",
    "00559808": "g_AiCandidateScoreList",
    "006b2d58": "g_AiSelectedTargetPlayer",
    "006b3064": "g_AiDecisionMatrix_Row",
    "0052d77c": "g_AiHeuristicWeight_CardAdvantage",
    "00559f88": "g_AiCombatSimulationState",
    "00641870": "g_AiDecisionTreeDepth",
    "00559638": "g_AiBlockerAssignmentList",
    "006fe444": "g_DuelArenaStatusFlags",
    "00556a90": "g_AiHeuristicWeight_DirectDamage",
    "006498d0": "g_AiLookaheadScore_Player0",
    "006498d4": "g_AiLookaheadScore_Player1",
    "006498d8": "g_AiLookaheadDelta",
    "006498dc": "g_AiLookaheadBestMove",
    "0055a008": "g_AiDamageAssignmentBuffer",
    "0063ee30": "g_AiCombatScore_Attacker",
    "0063ee18": "g_AiCombatScore_Blocker",
    "0063edd0": "g_AiCombatScore_Total",
    "006b2e2c": "g_AiSelectedActionCode",
    "00556b18": "g_AiHeuristicWeight_BoardThreat",
    "00556c60": "g_AiHeuristicWeight_Regeneration",
    "0055699c": "g_AiHeuristicWeight_ManaEfficiency",
    "005569d8": "g_AiHeuristicWeight_Evasion",
    "006ff4ac": "g_AiManaPoolReserve",
    "0052d770": "g_AiHeuristicWeight_HandAdvantage",
    "0055a010": "g_AiLethalDamageFlag",
    "00556938": "g_AiHeuristicWeight_Aggression",
    "006b2e28": "g_AiCandidateActionCount",
    "006b2d60": "g_AiSelectedCardTargetSlot",
    "006776a0": "g_AiBackupBoardRegister",
    "00559890": "g_AiCandidatePriorityList",
    "00559b80": "g_AiCombatRoundResult",
    "005520c8": "g_AiCardScore_BasicLand",
    "00556b20": "g_AiHeuristicWeight_Removal",
    "00627864": "g_AiTemporaryCardState",
    "0055747c": "g_AiHeuristicWeight_Tempo",

    # Directories, Paths & Campaign State
    "006807a0": "g_GameInstallDirectory",
    "006ff1b0": "g_PlayDeckDirectory",
    "006a4a50": "g_FacesDirectory",
    "006808d0": "g_CardArtDirectory",
    "00696910": "g_DuelSoundsDirectory",
    "006ff570": "g_DuelDatFilePath",
    "006a28c0": "g_SaveGameDirectory",
    "006a49f4": "g_CardsDatLoadedHandle",
    "0069f750": "g_OverworldGoldAmount",
    "00678830": "g_OverworldFoodAmount",
    "00626850": "g_OverworldWorldState",
    "0070100c": "g_EventSourceSlot",
    "006b2534": "g_EventSourcePlayer",
    "006b2d68": "g_OverworldPlayerCoordY",
    "0052eff0": "g_OverworldMapPixelX",
    "0052eff4": "g_OverworldMapPixelY",
    "006a28b0": "g_PlayerGoldCoins",
    "006b2e30": "g_PlayerAmuletGems",
    "005659f8": "g_CampaignMenuHandle",

    # Graphics, Palettes, KIM/PIC & Haar Wavelets
    "00517444": "g_DisplaySurfaceScreen",
    "0051746c": "g_DisplaySurfaceBackBuffer",
    "00517494": "g_DisplaySurfaceWork",
    "0070a850": "g_ScreenSurfaces",
    "0068a654": "g_HdcBackBuffer",
    "0068a660": "g_CardEventResult",
    "0068a630": "g_ScreenDC",
    "0054aefc": "g_OctreeColorTreeRoot",
    "0054b324": "g_PaletteDitherInitialized",
    "0052afc0": "g_ActiveDitherPaletteId",
    "00703930": "g_PicFileStream",
    "00536860": "g_PicSourceWidth",
    "00536864": "g_PicSourceHeight",
    "00538ad4": "g_PicAlignedRowPitch",
    "00538adc": "g_PicScanlineCounter",
    "007039cc": "g_MouseCursorX",
    "007039c8": "g_MouseCursorY",
    "0067f7d0": "g_SoundChannelTable",
    "00519c24": "g_CurrentActiveAudioTrack",
    "00519ff4": "g_SoundMidiSequenceId",
    "00530d9c": "g_MidiMusicTrackId",
    "006261d8": "g_PcxDecoderWidth",
    "006261dc": "g_PcxDecoderHeight",

    # Win32 Frontend Handles
    "006b2e34": "g_MainAppHwnd",
    "006fecb0": "g_AppHInstance",
    "006fe488": "g_DuelArenaHwnd",
    "00700eb0": "g_DialogPromptHwnd",
}

# ------------------------------------------------------------------------------
# 2. Comprehensive Function Symbol Map
# ------------------------------------------------------------------------------
FUNCTION_MAP = {
    # UI & Dialog Procs
    "00401000": "UI_BigCardDialogProc",
    "00401c91": "UI_RegisterSmallCardClass",
    "00401e65": "UI_RegisterBigCardClass",
    "00401f70": "UI_CardListWndProc",
    "0040360b": "Rules_ParseCardQueryFilter",
    "00405370": "UI_FormatActionPrompt",
    "00405802": "UI_ReportIllegalTarget",
    "004060e0": "Catalog_LoadInfoCsv",
    "004063b8": "Catalog_LoadMasterCsv",
    "004064f8": "Catalog_SaveConciseCsv",
    "0040659f": "Catalog_LoadConciseCsv",
    "00406681": "Catalog_SearchMasterCsv",
    "00406b4c": "Catalog_ParseDeckProfile",
    "0040706f": "Story_LoadCampaignText",
    "0040710a": "Story_LoadTaleText",
    "004071ce": "Story_LoadHintsText",
    "0040741b": "Story_SearchHintByKeyword",
    "00407b34": "Bazaar_CardSellerDialogue",
    "00407e40": "UI_ProcessKeyboardInput",
    "004080b2": "Util_CopyMemoryBuffer",
    "0040816b": "Util_MoveMemoryBuffer",
    "004081b0": "UI_RegisterCueCardClass",
    "004082d1": "UI_UnregisterCueCardClass",
    "0040836a": "UI_CueCardWndProc",
    "004088d0": "UI_UpdateCueCardPosition",
    "00408e20": "UI_RegisterFaceClass",
    "00409052": "UI_UnregisterFaceClass",
    "004090f6": "UI_DuelArenaMenuProc",
    "004097e2": "UI_RenderDuelStatusBanner",
    "00409b2c": "UI_ShowDuelArenaWindow",
    "00409c73": "UI_PostDuelArenaMessage",
    "00409d10": "Subsystem_LoadStatWinDll",
    "00409db6": "Subsystem_FreeStatWinDll",
    "0040a16e": "UI_RenderOpponentLibraryPrompt",
    "0040a1a3": "UI_RenderPlayerLibraryPrompt",
    "0040a1d2": "Util_GetRandomNumber",
    "0040a1ff": "Util_GetRandomInRange",
    "0040a2c0": "Util_SeedRandomGenerator",
    "0040a4fc": "Overworld_LoadAdventureFacesAndPalette",
    "0040b00c": "Sound_PlayButtonClick",
    "0040b7fa": "Story_FormatQuestLogEntry",
    "0040c3cc": "UI_DrawCombatString",
    "0040de30": "Bazaar_BuyCardDialogue",
    "0040eb5a": "Overworld_ResolveDungeonVictory",
    "0040eeb4": "Bazaar_TradeCardDialogue",
    "0040f514": "UI_PromptDeckInspection",
    "0040fcfd": "Story_DisplayTownNewsflash",

    # Card Scripts (0x0041xxxx - 0x0046xxxx)
    "00411f98": "CardScript_NafsAsp_DamageTrigger",
    "0041268a": "UI_PromptLifeBidValidation",
    "00414947": "CardScript_NaturalSelection",
    "00414d99": "CardScript_ManaShort",
    "004150fe": "CardScript_AncestralRecall",
    "0041529a": "CardScript_Simulacrum",
    "00415517": "CardScript_Shatter",
    "004156c9": "CardScript_Disenchant",
    "00415920": "CardScript_Twiddle",
    "00415df8": "CardScript_Tunnel",
    "00416222": "CardScript_HowlFromBeyond",
    "0041652b": "CardScript_Berserk",
    "004167ac": "CardScript_Righteousness",
    "00416a6a": "CardScript_Bloodlust",
    "00416d36": "CardScript_SwordsToPlowshares",
    "00416f1a": "CardScript_DeathWard",
    "004172a6": "CardScript_HurkylsRecall",
    "00417f38": "CardScript_LightningBolt",
    "00417ff5": "CardScript_Crumble",
    "00418254": "CardScript_GiantGrowth",
    "004184e1": "CardScript_Unsummon",
    "00418785": "CardScript_Purelace",
    "00418d2a": "CardScript_MagicalHack",
    "004195a4": "CardScript_SleightOfMind",
    "00419d5e": "CardScript_BlueElementalBlast",
    "0041b1ae": "CardScript_RedElementalBlast",
    "0041b98a": "CardScript_HealingSalve",
    "0041c22f": "CardScript_SamiteHealer",
    "0041c8e1": "CardScript_EyeForAnEye",
    "0041d1ab": "CardScript_Fissure",
    "004207a8": "UI_CampaignSaveLoadMenuProc",
    "00421b32": "Story_DisplayCampaignScoreSummary",
    "004230bd": "Overworld_LoadWorldMagicBackdrop",
    "0042351b": "Pic_LoadImageFile",
    "004232f0": "Pic_AllocateImageBuffer",
    "00423833": "Pic_LoadKimPicture",
    "004238ba": "Pic_OpenArchiveStream",
    "00423919": "Pic_SeekImageStream",
    "004244a0": "UI_LoadHallBackdrop",
    "004248b0": "UI_LoadPhaseBackdrop",
    "00424a1e": "UI_LoadPhaseCombatBackdrop",
    "00424b1f": "UI_PhaseDisplayWndProc",
    "004267c5": "UI_CombatDefenseWndProc",
    "00427e36": "UI_CombatAttackWndProc",
    "00429237": "CardScript_SylvanLibrary",
    "004297ed": "CardScript_LandTax",
    "00429e7d": "CardScript_Kismet",
    "0042ae1d": "CardScript_AnimateArtifact",
    "0042bb2e": "CardScript_AnimateWall",
    "0042bee5": "CardScript_ControlMagic",
    "0042bf45": "CardScript_StealArtifact",
    "0042dd1f": "CardScript_Feedback",
    "0042e2d9": "CardScript_Brainwash",
    "0042e8c0": "CardScript_SpiritShackle",
    "0042ed9f": "CardScript_RelicBind",
    "0042f87b": "CardScript_PowerLeak",
    "00430f0a": "CardScript_CursedLand",
    "004319c5": "CardScript_EvilPresence",
    "00431ed3": "CardScript_LivingArtifact",
    "004325fe": "CardScript_Blight",
    "00433c62": "CardScript_AspectOfWolf",
    "004345a9": "CardScript_SpiritLink",
    "00434b1f": "CardScript_CreatureBond",
    "00434f32": "CardScript_GaseousForm",
    "004353b3": "CardScript_Backfire",
    "00435abf": "CardScript_HolyArmor",
    "00436500": "CardScript_Blessing",
    "00436f60": "CardScript_Firebreathing",
    "0043793a": "CardScript_Invisibility",
    "00437df6": "CardScript_Seeker",
    "00438ced": "CardScript_Paralyze",
    "00439b92": "CardScript_Cocoon",
    "00439d8b": "CardScript_Burrowing",
    "00439e06": "CardScript_Wanderlust",
    "0043a32c": "CardScript_InstillEnergy",
    "0043ac68": "CardScript_Flood",
    "0043b6eb": "CardScript_Lance",
    "0043b74e": "CardScript_FishliverOil",
    "0043ba6e": "CardScript_HolyStrength",
    "0043bad0": "CardScript_GiantStrength",
    "0043bb32": "CardScript_Immolation",
    "0043bb94": "CardScript_DivineTransformation",
    "0043bbf6": "CardScript_UnholyStrength",
    "0043bc58": "CardScript_Weakness",
    "0043c287": "CardScript_AnyWard",
    "0043c8f5": "CardScript_UnstableMutation",
    "0043d1c3": "CardScript_CopyArtifact",
    "0043ebbf": "CardScript_Regeneration",
    "0043f19e": "CardScript_EternalWarrior",
    "0043f51d": "CardScript_TheBrute",
    "0043faf7": "CardScript_Earthbind",
    "0043fe8e": "CardScript_CircleOfProtection",
    "0044068c": "CardScript_PhantasmalTerrain",
    "00440db5": "CardScript_WildGrowth",
    "00441167": "CardScript_Flight",
    "004420a1": "Catalog_LoadAllBigCardArtPics",
    "00443b63": "UI_AttackPhaseDisplayWndProc",
    "004450c3": "UI_LoadGraveyardBackdrops",
    "004455e3": "UI_RegisterThinkingCardClass",
    "004458b0": "UI_PromptFastEffectsDialog",
    "004475a4": "Rules_ProcessDamagePrevention",
    "004488a0": "Rules_SendCardsToGraveyard",
    "0044895f": "Rules_CardLeavingPlay",
    "00449340": "UI_RegisterExpandedGraveyardClass",
    "004494ff": "UI_GraveyardMenuProc",
    "0044a402": "UI_GraveyardListWndProc",
    "0044a862": "UI_AnteDisplayWndProc",
    "0044b460": "Font_LoadCustomFonts",
    "0044bad4": "UI_PlayerHandCardWndProc",
    "0044d61a": "UI_DrawPlayerHandWindow",
    "0044eca0": "SaveGame_SaveGauntletFile",
    "0044edf5": "SaveGame_AutoSave",
    "0044ef70": "Deck_LoadOneDeckProfile",
    "004509e8": "UI_DeckSelectionMenu",
    "00451291": "Deck_AddCardToDeck",
    "00452793": "Engine_ReportFatalError",
    "004527bc": "UI_DrawCombatBanner",
    "0045280c": "Ai_TriggerTurnPhaseEvaluation",
    "00452827": "Engine_CountActiveCreatures",
    "004528c0": "UI_DrawManaSymbolBox",
    "00452b71": "UI_PromptDualLandManaChoice",
    "004532f1": "UI_PromptCityOfBrassManaChoice",
    "0045350d": "CardScript_Desert",
    "004537b0": "CardScript_Oasis",
    "00453c60": "CardScript_ElephantsGraveyard",
    "00453fdb": "CardScript_StripMine",
    "00454702": "CardScript_LibraryOfAlexandria",
    "004549ea": "CardScript_MishrasFactory",
    "004555c8": "CardScript_AssemblyWorker",
    "0045672f": "CardScript_Arena",
    "00456f29": "CardScript_BlackLotus",
    "004572aa": "CardScript_TimeVault",
    "00457e67": "CardScript_AladdinsLamp",
    "004590b4": "CardScript_MishrasWarMachine",
    "004594d8": "CardScript_PrimalClay",
    "004597d4": "CardScript_Shapeshifter",
    "00459d0a": "CardScript_Tetravite",
    "0045a252": "CardScript_Tetravus",
    "0045a825": "CardScript_Triskelion",
    "0045a9ff": "CardScript_UrzasAvenger",
    "0045b156": "CardScript_Millstone",
    "0045b502": "CardScript_CelestialPrism",
    "0045b7d9": "CardScript_FellwarStone",
    "0045bd50": "CardScript_AshnodsBattlegear",
    "0045c59a": "CardScript_TawnosWeaponry",
    "0045d1f0": "CardScript_CandelabraOfTawnos",
    "0045d8dc": "CardScript_Forcefield",
    "0045dda5": "CardScript_DisruptingScepter",
    "0045ebe4": "CardScript_Conservator",
    "004605e4": "CardScript_EbonyHorse",
    "004617ad": "CardScript_JandorsSaddlebags",
    "00461ba1": "CardScript_JadeMonolith",
    "004622d9": "CardScript_AmuletOfKroog",
    "00462a0a": "CardScript_GrapeshotCatapult",
    "00462f7e": "CardScript_BronzeTablet",
    "00463cd1": "CardScript_AladdinsRing",
    "00463ef0": "CardScript_RodOfRuin",
    "00465165": "CardScript_FlyingCarpet",
    "00465a75": "CardScript_HelmOfChatzuk",
    "00465e9c": "CardScript_CoralHelm",
    "00466541": "CardScript_TawnosWand",
    "00466d29": "CardScript_BottleOfSuleiman",
    "0046709c": "CardScript_GlassesOfUrza",
    "00467a68": "UI_CardContextMenu_Debug",
    "0046b4db": "UI_FormatCardCounterString",
    "0046bcc0": "Catalog_LoadWaveletArt",
    "0046c203": "Catalog_LoadWaveletArtAlt",
    "0046c8b0": "Sprite_LoadCampaignSprites",
    "0046d333": "Sprite_LoadCastleSprites",
    "0046f172": "Sprite_SelectResolutionFolder",
    "0046f5d1": "Magic_ExecuteDrawPhase",
    "0046fa40": "Magic_ExecuteDiscardPhase",
    "0046ff50": "Magic_ExecuteCastSpellPhase",
    "00470b36": "Magic_ResolveCastSpell",
    "0047103b": "Magic_ExecuteUpkeepPhase",
    "00471971": "Magic_ExecuteTapCardAction",
    "00471aba": "Magic_ExecuteProcessTriggers",
    "00471d16": "Magic_ExecuteDeclareBlockersPhase",
    "004728c3": "Rules_ValidateCardTargetSlot",
    "00472fae": "Rules_ProcessCombatDamageStep",
    "00473060": "Rules_TriggerEndOfTurnPhase",
    "004738a0": "Rules_ResolveSpellEffect",
    "00473cc5": "Rules_CalculateManaCostReduction",
    "00473ce8": "Rules_CalculateColorCost",
    "00473d09": "Rules_GetCardConvertedManaCost",
    "00473e69": "Rules_ApplyContinuousDamage",
    "00473f06": "Magic_ScanCards",
    "00476e60": "UI_PromptTellUserDialog",
    "004771fa": "UI_TellUserWndProc",
    "0047a2e6": "UI_MainMenu_LoadBeginScreen",
    "0047abf1": "UI_DifficultySelection_LoadScreen",
    "0047b208": "UI_ColorSpecialization_LoadScreen",
    "0047b899": "UI_CharacterFaceSelection_LoadScreen",
    "0047be64": "UI_PromptPlayerNameEntry",
    "0047c640": "UI_LoadPoisonCountersPic",
    "0047c7aa": "UI_LifePointsDisplayWndProc",
    "0047d460": "UI_AttackWindow_RegisterClasses",
    "0047da80": "UI_AttackWindow_WndProc",
    "00481586": "UI_LayoutAttackCards",
    "004822b7": "UI_LoadAttackSwordShieldPics",
    "00482dd6": "UI_MinimizedAttackWindowWndProc",
    "0048369c": "UI_CombatCommandBarWndProc",
    "00484738": "UI_LoadDungeonButtonsSprite",
    "004853c2": "UI_AnteCardDisplayWndProc",
    "00489188": "UI_LoadPlayerFacePortraits",
    "0048c72a": "SaveGame_LoadCampaignFile",
    "0048c970": "SaveGame_SaveCampaignFile",
    "0048d087": "Overworld_SaveMapFile",
    "0048f523": "UI_DungeonStatusDisplay",
    "004909d3": "Deck_LoadPreconstructedDeck",
    "00490d7b": "UI_LoadCityInfoPics",
    "0049239e": "Story_DisplayVictoryCelebration",
    "004938e0": "Catalog_CheckDuplicateShortNames",
    "00494c30": "Palette_ComputeColorDeltas",
    "00495430": "Display_CreateAppMemoryDC",
    "004958b1": "Duel_LaunchDuelInstance",
    "00495958": "Main_CreateGameWindows",
    "0049608e": "UI_RegisterDuelClasses",
    "0049716e": "Bazaar_TradeScreenWndProc",
    "004997e6": "UI_CardDescriptionTextBoxWndProc",
    "0049ae00": "UI_LoadCardFrameBitmaps",
    "0049b8f5": "Font_LoadTrueTypeFonts",
    "0049c3ac": "UI_LoadExpansionCardFrames",
    "0049c7c7": "UI_RenderCardTextBox",
    "0049eda9": "UI_FormatCardModifierText",
    "0049fb63": "UI_RenderBasicLandBackground",
    "004a2ef0": "Overworld_ResolveDungeonEncounter",
    "004a5722": "Overworld_ExploreDungeonFloor",
    "004a6fef": "CardScript_AswanJaguar",

    # AI Tactical Decision Subsystems (Ai.c)
    "004aa830": "Ai_SaveGameState",
    "004aaaea": "Ai_RestoreGameState",
    "004aad61": "Ai_PushBoardState",
    "004aafa8": "Ai_PopBoardState",
    "004ab1ef": "Ai_ResetEvaluationState",
    "004ab214": "Ai_GetActivePlayerScore",
    "004ab28b": "Ai_EvaluateCreaturePower",
    "004ab35e": "Ai_GetOpponentPlayerScore",
    "004ab3a9": "Ai_CalcLifeAdvantage",
    "004ab3f3": "Ai_CalcCardAdvantage",
    "004ab45f": "Ai_ScoreBoardPosition",
    "004ab510": "Ai_ClearCandidateScoreList",
    "004ab525": "Ai_SortCandidateScoreList",
    "004ab552": "Ai_SimulateCombatRound",
    "004abff4": "Ai_ChooseAttackers",
    "004ac940": "Ai_ChooseBlockers",
    "004acb7f": "Ai_FilterValidBlockers",
    "004acc20": "Ai_AssignCombatDamage",
    "004ace3a": "Ai_DuelDialogProc",
    "004ad6c5": "Ai_LoadStartDuel2Backdrop",
    "004ad77b": "Ai_InitCombatHeuristics",
    "004ad7c8": "Ai_StartDuelWndProc",
    "004ae632": "Ai_LoadStartDuelBackdrop",
    "004ae716": "Ai_EvaluateManaCurve",
    "004ae779": "Ai_ScoreBoardPermanents",
    "004ae8a3": "Ai_CalculateCombatOdds",
    "004ae995": "Ai_DuelMainWndProc",
    "004af4fd": "Ai_LoadEndDuelBackdrop",
    "004af5e3": "Ai_FindOptimalSpellTarget",
    "004af640": "Ai_EvaluateInstantSpells",
    "004af765": "Ai_ScoreAttackerCombination",
    "004afa46": "Ai_GetHighestPriorityMove",
    "004afa69": "Ai_EvaluateCreatureCast",
    "004afc26": "Ai_EvaluateSpellCast",
    "004b7897": "Rules_ApplyManaBurn",
    "004b7de8": "UI_PlayCoinTossAvi",
    "004b8cc3": "CardScript_Fireball",
    "004b9120": "UI_RegisterManaPoolClass",
    "004b9284": "UI_ManaPoolWndProc",
    "004ba890": "UI_PromptManaColorSelection",
    "004c05ba": "Overworld_LoadAdventureInterface800",
    "004c24b3": "Overworld_LoadMapScreenPics",
    "004c864d": "Rules_AssignCombatBlockerDamage",
    "004cd63b": "Timer_InitDavesExtraCoolTimer",
    "004cd760": "UI_RegisterSpellChainWindowClasses",
    "004cdb4f": "UI_SpellChainWndProc",
    "004cfb2f": "UI_SpellCardWndProc",
    "004cfe4d": "UI_SpellTargetCardWndProc",
    "004d0602": "UI_MinimizedSpellChainWndProc",
    "004d1cc4": "CardScript_Sinbad",
    "004d2610": "CardScript_XenicPoltergeist",
    "004d29da": "CardScript_VesuvanDoppelganger",
    "004d420e": "CardScript_PersonalIncarnation",
    "004d4762": "CardScript_AliFromCairo",
    "004d7065": "CardScript_GaeasLiege",
    "004d7a1b": "CardScript_SedgeTroll",
    "004d7bb5": "CardScript_LivingWall",
    "004d9f7e": "CardScript_TimeElemental",
    "004da482": "CardScript_NorthernPaladin",
    "004da858": "CardScript_RoyalAssassin",
    "004daa50": "CardScript_DwarvenDemolitionTeam",
    "004dac11": "CardScript_KingSuleiman",
    "004db024": "CardScript_NettlingImp",
    "004dba1c": "CardScript_SorceressQueen",
    "004dc2ca": "CardScript_StoneGiant",
    "004dc6c7": "CardScript_DwarvenWarriors",
    "004dc9ed": "CardScript_CavePeople",
    "004dce51": "CardScript_PradeshGypsies",
    "004de1c0": "CardScript_ErgRaiders",
    "004dec09": "CardScript_Leviathan",
    "004df04a": "CardScript_BrothersOfFire",
    "004df314": "CardScript_CrimsonManticore",
    "004df678": "CardScript_ProdigalSorcerer",
    "004dfd39": "CardScript_PirateShip",
    "004e0ab7": "CardScript_OrcishArtillery",
    "004e0c1c": "CardScript_PsionicEntity",

    # Later Rules & Subsystems
    "004f4025": "Pic_LoadDIBSection",
    "004f40e6": "Pic_LoadDIBSectionFromFile",
    "004f4548": "Pic_DestroyDIBSection",
    "004f45da": "Palette_LoadDuelPalette",
    "004f6180": "Catalog_LoadCardsDat",
    "004f72b0": "CardScript_Balance",
    "004f7658": "CardScript_Braingeyser",
    "004f7a7a": "CardScript_Darkpact",
    "004f8321": "CardScript_EnergyTap",
    "004f8672": "CardScript_StreamOfLife",
    "004f899b": "CardScript_VolcanicEruption",
    "004f9737": "CardScript_AshesToAshes",
    "004f9bbd": "CardScript_DesertTwister",
    "004f9e64": "CardScript_WinterBlast",
    "004fa586": "CardScript_FireballAlt",
    "004fb1e4": "CardScript_Detonate",
    "004fb6b5": "CardScript_WordOfBinding",
    "004fbbd4": "CardScript_RaiseDead",
    "004fc023": "CardScript_DrafnasRestoration",
    "004fc2e5": "CardScript_Regrowth",
    "004fc89e": "CardScript_DemonicTutor",
    "004fcb7a": "CardScript_UntamedWilds",
    "004fceea": "CardScript_Visions",
    "004fd3cf": "CardScript_MindTwist",
    "004fe05f": "CardScript_Pyrotechnics",
    "004fe67f": "CardScript_Disintegrate",
    "004fe9b6": "CardScript_DrainLife",
    "004fef61": "CardScript_StoneRain",
    "004ff17f": "CardScript_DrainPower",
    "004ffd9c": "UI_LoadOptionsBackdrop",
    "004ffedf": "UI_ApplyDebugCheats",
    "0050065d": "Config_LoadRegistrySettings",
    "00500a5b": "Config_SaveRegistrySettings",
    "005013be": "UI_WndProc_ShowPaletteClass",
    "005017a6": "Sound_PlayLocationMusic",
    "00507c86": "Town_DialogueMenuProc",
    "00508c3e": "Town_LoadTownBackdrop",
    "00509517": "Town_BuyCardsDialogue",
    "0050bba0": "Rules_ShufflePlayerLibrary",
    "0050bd27": "UI_LibraryCardCountWndProc",
    "0050d0b0": "Memory_AllocateVirtualPage",
    "0050d2a0": "Memory_FreeVirtualPage",
    "0050e2f0": "Graphics_MScaledRectCopy",
    "0050e850": "Graphics_GetLine",
    "0050edf0": "Font_LoadFontFile",
    "0050fcc0": "Sprite_LoadSpriteFile",
    "00510b70": "FileIO_OpenFileStream",
    "00512230": "Pcx_Load256ColorPcx",
    "00512500": "Pcx_DecodePcxHeader",
    "005126b0": "Pcx_DecodePcxScanline",
    "00512740": "Pcx_OpenPcxFileStream",
    "00513820": "UI_RegisterShowPaletteClass",
    "005138b0": "UI_ShowPaletteWndProc",
}

# ------------------------------------------------------------------------------
# 3. CSV File Synchronization
# ------------------------------------------------------------------------------
def update_symbol_csvs():
    print(">>> Updating CSV Symbol Mappings...")

    # 1. Update engine_globals_map.csv
    globals_csv = os.path.join(BASE_DIR, "engine_globals_map.csv")
    existing_globals = {}
    if os.path.exists(globals_csv):
        with open(globals_csv, 'r', encoding='utf-8') as f:
            r = csv.reader(f)
            next(r, None)
            for row in r:
                if len(row) >= 2:
                    existing_globals[row[0].strip()] = row[1].strip()

    for addr, name in GLOBAL_DAT_MAP.items():
        existing_globals[addr.lower()] = name

    with open(globals_csv, 'w', newline='', encoding='utf-8') as f:
        w = csv.writer(f)
        w.writerow(["Address", "NewName"])
        for addr, name in sorted(existing_globals.items()):
            w.writerow([addr, name])

    print(f"  -> engine_globals_map.csv updated with {len(existing_globals)} entries.")

    # 2. Update unified_engine_symbol_map.csv
    unified_csv = os.path.join(BASE_DIR, "unified_engine_symbol_map.csv")
    unified_map = {}
    if os.path.exists(unified_csv):
        with open(unified_csv, 'r', encoding='utf-8') as f:
            r = csv.reader(f)
            next(r, None)
            for row in r:
                if len(row) >= 3:
                    unified_map[row[0].strip()] = (row[1].strip(), row[2].strip())

    for addr, new_name in FUNCTION_MAP.items():
        addr_lower = addr.lower()
        old_name = unified_map.get(addr_lower, (f"FUN_{addr_lower}", f"FUN_{addr_lower}"))[0]
        unified_map[addr_lower] = (old_name, new_name)

    with open(unified_csv, 'w', newline='', encoding='utf-8') as f:
        w = csv.writer(f)
        w.writerow(["Address", "OldName", "NewName"])
        for addr, (old_name, new_name) in sorted(unified_map.items()):
            w.writerow([addr, old_name, new_name])

    print(f"  -> unified_engine_symbol_map.csv updated with {len(unified_map)} entries.")

    # 3. Update magic_symbol_renames.csv
    magic_csv = os.path.join(BASE_DIR, "magic_symbol_renames.csv")
    magic_map = {}
    if os.path.exists(magic_csv):
        with open(magic_csv, 'r', encoding='utf-8') as f:
            r = csv.reader(f)
            next(r, None)
            for row in r:
                if len(row) >= 3:
                    magic_map[row[0].strip()] = (row[1].strip(), row[2].strip())

    for addr, new_name in FUNCTION_MAP.items():
        addr_lower = addr.lower()
        old_name = magic_map.get(addr_lower, (f"FUN_{addr_lower}", f"FUN_{addr_lower}"))[0]
        magic_map[addr_lower] = (old_name, new_name)

    with open(magic_csv, 'w', newline='', encoding='utf-8') as f:
        w = csv.writer(f)
        w.writerow(["Address", "OldName", "NewName"])
        for addr, (old_name, new_name) in sorted(magic_map.items()):
            w.writerow([addr, old_name, new_name])

    print(f"  -> magic_symbol_renames.csv updated with {len(magic_map)} entries.")

# ------------------------------------------------------------------------------
# 4. Source Code Refactoring (C and H files)
# ------------------------------------------------------------------------------
def refactor_source_files():
    print(">>> Refactoring C and H source files...")

    # Build full replacement dictionary
    replacement_dict = {}

    for addr, new_name in GLOBAL_DAT_MAP.items():
        replacement_dict[f"DAT_{addr}"] = new_name
        replacement_dict[f"_DAT_{addr}"] = new_name

    for addr, new_name in FUNCTION_MAP.items():
        replacement_dict[f"FUN_{addr}"] = new_name
        # Also handle any existing hex-suffixed prefixes
        for prefix in ["Ai_Subsystem_", "Ai_ScoreCardPlay_", "Ai_Util_", "Pic_Load_", "Minit_Subsystem_", "Minit_Util_", "Mem_AllocOrFree_", "Pic_Subsystem_", "Pic_Util_", "UI_WndProc_", "UI_DialogProc_", "UI_CreateWindow_", "Assert_Handler_"]:
            replacement_dict[f"{prefix}{addr}"] = new_name

    files_to_process = glob.glob(os.path.join(BASE_DIR, "src/**/*.c"), recursive=True) + \
                       glob.glob(os.path.join(BASE_DIR, "include/**/*.h"), recursive=True)

    refactored_count = 0
    for fpath in files_to_process:
        with open(fpath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()

        orig = content

        # 1. Replace all global and function symbols
        for old_sym, new_sym in replacement_dict.items():
            if old_sym in content:
                content = re.sub(r'\b' + old_sym + r'\b', new_sym, content)

        if content != orig:
            with open(fpath, 'w', encoding='utf-8') as f:
                f.write(content)
            refactored_count += 1
            print(f"  -> Updated: {os.path.relpath(fpath, BASE_DIR)}")

    print(f"Successfully refactored {refactored_count} files.")

# ------------------------------------------------------------------------------
# 5. Ghidra Headless Database Synchronization
# ------------------------------------------------------------------------------
def sync_with_ghidra():
    print(">>> Synchronizing symbols with Ghidra Headless...")

    env = os.environ.copy()
    env["JAVA_HOME"] = JAVA_HOME
    env["PATH"] = f"{JAVA_HOME}/bin:" + env.get("PATH", "")

    scripts = [
        ("MAGIC.EXE", "RenameGlobalSymbols.java"),
        ("MAGIC.EXE", "ApplyUnifiedSymbols.java"),
        ("MAGIC.EXE", "RenameFunctionParameters.java"),
        ("DUEL.EXE", "RenameGlobalSymbols.java"),
        ("DUEL.EXE", "ApplyUnifiedSymbols.java"),
        ("DUEL.EXE", "RenameFunctionParameters.java"),
    ]

    for prog, script in scripts:
        print(f"  -> Running {script} on {prog}...")
        cmd = [
            GHIDRA_HEADLESS,
            "/Users/ben",
            "ShandalarDecomp",
            "-process", prog,
            "-noanalysis",
            "-scriptPath", os.path.join(BASE_DIR, "scripts"),
            "-postScript", script
        ]
        try:
            res = subprocess.run(cmd, env=env, capture_output=True, text=True, timeout=120)
            if res.returncode == 0:
                print(f"     [OK] {script} applied successfully to {prog}.")
            else:
                print(f"     [WARN] Ghidra output: {res.stderr[:200]}")
        except Exception as ex:
            print(f"     [ERR] Failed to execute {script}: {ex}")

# ------------------------------------------------------------------------------
# Main
# ------------------------------------------------------------------------------
def main():
    print("==========================================================")
    print(" MicroProse Magic: The Gathering (Shandalar 1997)")
    print(" Reconstructed ANSI C Engine Comprehensive Refactoring")
    print("==========================================================")

    update_symbol_csvs()
    refactor_source_files()
    sync_with_ghidra()

    print("\n>>> All refactoring and Ghidra sync tasks completed successfully!")

if __name__ == "__main__":
    main()
