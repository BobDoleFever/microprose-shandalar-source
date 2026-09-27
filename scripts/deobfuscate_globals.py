#!/usr/bin/env python3
import csv
import re

def main():
    global_renames = {
        # Core Card Array & Battlefield (0x006a5f30 base)
        "006a5f30": "g_ActiveCardsInPlay",
        "006a5f34": "g_CardSlot_CardId",
        "006a5f38": "g_CardSlot_Controller",
        "006a5f3c": "g_CardSlot_Flags",
        "006a5f40": "g_CardSlot_Power",
        "006a5f42": "g_CardSlot_Toughness",
        "006a5f43": "g_CardSlot_DamageReceived",
        "006a5f44": "g_CardSlot_Counters",
        "006a5f4e": "g_CardSlot_ColorMask",
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
        "006a6044": "g_CardSlot_SpecialState",

        # Player & Turn State
        "006a49fc": "g_ActivePlayer",
        "0068a71c": "g_TurnPlayer",
        "006a49e0": "g_CurrentTurnPhase",
        "006a49f8": "g_TurnCounter",
        "006a492c": "g_ActivePlayerPriority",
        "006a285c": "g_IsAiThinking",
        "006a4a00": "g_PlayerCreatureCount",
        "006a4a08": "g_DuelModeFlags",
        "00695e80": "g_PlayerLifeTotals",
        "006808b8": "g_PlayerActiveCardCount",
        "006ff558": "g_ScWillyScore",
        "006ff55c": "g_AiDecisionScore",
        "006ff680": "g_SpellStackDepth",
        "006ff4c0": "g_CurrentStepCode",

        # Master Card Catalog & Rules Table
        "0067f440": "g_MasterCardCount",
        "0051aea8": "g_MasterCardTable",
        "0051aeb8": "g_MasterCardTypeTable",
        "0051aebc": "g_MasterCardColorTable",
        "00517444": "g_DisplaySurfaceScreen",
        "0051746c": "g_DisplaySurfaceBackBuffer",
        "00517494": "g_DisplaySurfaceWork",

        # Win32 Frontend & GDI Handles
        "006b2e34": "g_MainAppHwnd",
        "006fecb0": "g_AppHInstance",
        "0068a654": "g_HdcBackBuffer",
        "0068a660": "g_CardEventResult",
        "0068a630": "g_ScreenDC",
        "006fe488": "g_DuelArenaHwnd",
        "00700eb0": "g_DialogPromptHwnd",

        # Overworld RPG Campaign & World State
        "00626850": "g_OverworldWorldState",
        "0070100c": "g_EventSourceSlot",
        "006b2534": "g_EventSourcePlayer",
        "006b2d68": "g_OverworldPlayerCoordY",
        "0069f750": "g_OverworldGoldAmount",
        "00678830": "g_OverworldFoodAmount"
    }

    print(f"Total core engine globals mapped: {len(global_renames)}")

    with open("/Users/ben/decomp/engine_globals_map.csv", "w", encoding="utf-8") as out_f:
        w = csv.writer(out_f)
        w.writerow(["Address", "NewName"])
        for addr, name in global_renames.items():
            w.writerow([addr, name])

if __name__ == "__main__":
    main()
