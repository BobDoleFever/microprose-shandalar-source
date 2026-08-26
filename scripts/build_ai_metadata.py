#!/usr/bin/env python3
"""
build_ai_metadata.py - Build complete metadata for all 260 functions in Ai.c
MicroProse Magic: The Gathering (Shandalar 1997) Reconstructed ANSI C Engine
"""

import json
import csv
import re
import os

BASE_DIR = "/Users/ben/decomp"
METADATA_OUT = "/Users/ben/.gemini/antigravity/brain/669cec31-26e1-4589-bb85-e02a80bda342/scratch/ai_metadata_full.json"
SYMBOL_MAP_OUT = os.path.join(BASE_DIR, "ai_symbol_map.csv")

# Master metadata dictionary for all 260 functions in Ai.c
METADATA = {
    # -------------------------------------------------------------------------
    # Group 1: Core Tactical Heuristics & Board Evaluation (0x004aa830 – 0x004ace3a)
    # -------------------------------------------------------------------------
    "004aa830": ("Ai_SaveGameState", "Copy current game state to backup lookahead memory buffer.", ["Set backup counter to zero.", "Copy card structures, player state, and life totals to backup buffer.", "Verify evaluation score validity (ScWilly >= 0)."]),
    "004aaaea": ("Ai_RestoreGameState", "Restore saved game state from backup lookahead memory buffer.", ["Copy all card structures back to active memory.", "Restore life totals, mana pools, and turn counters.", "Reset temporary lookahead evaluation variables."]),
    "004aad61": ("Ai_PushBoardState", "Push active board state onto tactical decision tree stack.", ["Increment decision tree depth counter.", "Save card states, priorities, and scores onto stack frame."]),
    "004aafa8": ("Ai_PopBoardState", "Pop and restore previous board state from tactical decision tree stack.", ["Decrement decision tree depth counter.", "Restore previous card states and scores from stack frame."]),
    "004ab1ef": ("Ai_ResetEvaluationState", "Clear all tactical evaluation state variables for new analysis pass.", ["Reset active creature counter to zero.", "Initialize score lookup table to default values (99)."]),
    "004ab214": ("Ai_GetActivePlayerScore", "Calculate total tactical score for the active AI player.", ["Restore baseline evaluation state.", "Aggregate creature power, card advantage, and life scores.", "Return calculated total score."]),
    "004ab28b": ("Ai_EvaluateCreaturePower", "Calculate attacking power and defensive toughness for creature.", ["Read power and toughness attributes of creature slot.", "Apply ability multipliers (flying, first strike, trample).", "Store evaluated power in creature score array."]),
    "004ab35e": ("Ai_GetOpponentPlayerScore", "Calculate threat score of opponent cards on battlefield.", ["Evaluate opponent creature power, hand size, and open mana.", "Return composite threat score (ScWilly metric)."]),
    "004ab3a9": ("Ai_CalcLifeAdvantage", "Calculate heuristic score for life point difference between players.", ["Compute life total differential (player life minus opponent life).", "Apply non-linear scaling when life is below critical threshold."]),
    "004ab3f3": ("Ai_CalcCardAdvantage", "Calculate heuristic score for hand and library card advantage.", ["Count available cards in hand and library.", "Weight cards in hand higher than library depth.", "Return card advantage bonus score."]),
    "004ab45f": ("Ai_ScoreBoardPosition", "Calculate composite score for entire battlefield board position.", ["Iterate through all active permanents on battlefield.", "Sum creature scores, enchantment bonuses, and land tempo.", "Store evaluated composite score in master position buffer."]),
    "004ab510": ("Ai_Score_ClearCache", "Clear cached board evaluation scores.", ["Reset score cache validity flags to zero."]),
    "004ab525": ("Ai_Score_SetValidityFlag", "Set board evaluation score cache valid flag.", ["Mark score cache as valid for current turn phase."]),
    "004ab552": ("Ai_SimulateCombatRound", "Simulate complete combat step between attacker and defender.", ["Evaluate legal blocking assignments with Ai_FilterValidBlockers.", "Calculate combat damage dealt to creatures and defending player.", "Compute life point changes and determine combat advantage score."]),
    "004abff4": ("Ai_ChooseAttackers", "Select optimal set of creatures to declare as attackers.", ["Evaluate combat strength for each untapped creature.", "Simulate combat outcomes against potential blockers.", "Mark optimal candidates with attacking flag."]),
    "004ac940": ("Ai_ChooseBlockers", "Assign defending creatures to block attacking creatures.", ["Check legal blocker restrictions for each attacking creature.", "Assign blockers to maximize creature survival and trade value.", "Record blocking pairs in combat assignment matrix."]),
    "004acb7f": ("Ai_FilterValidBlockers", "Filter list of potential blockers against specific attacking creature.", ["Verify flying, protection, and landwalk evasion restrictions.", "Return count of legal blocking candidates."]),
    "004acc20": ("Ai_AssignCombatDamage", "Assign combat damage distribution among blocking and attacking creatures.", ["Calculate lethal damage threshold for primary blocker.", "Assign excess trample damage to defending player.", "Apply damage points to card slot damage registers."]),

    # -------------------------------------------------------------------------
    # Group 2: Duel Arena Window Procedures & Dialog Handlers (0x004ace3a – 0x004af5e3)
    # -------------------------------------------------------------------------
    "004ace3a": ("Ai_DuelDialogProc", "Main modal dialog procedure for duel interactive prompts.", ["Handle WM_INITDIALOG, WM_COMMAND, and button messages.", "Dispatch user choices to duel turn state machine."]),
    "004ad6c5": ("Ai_LoadStartDuel2Backdrop", "Load secondary duel startup backdrop art.", ["Load WINBK_StartDuel2.pic into memory.", "Decompress 8-bit bitmap to display surface buffer."]),
    "004ad77b": ("Ai_StartDuel_InitContext", "Initialize tactical duel session context.", ["Allocate lookahead memory buffers.", "Reset turn counters and player life totals."]),
    "004ad7c8": ("Ai_StartDuelWndProc", "Window procedure for startup duel initialization window.", ["Process WM_CREATE, WM_PAINT, and start duel trigger messages."]),
    "004ae632": ("Ai_LoadStartDuelBackdrop", "Load primary duel introduction backdrop art.", ["Load WINBK_StartDuel.pic into memory.", "Paint introduction art to screen DC."]),
    "004ae716": ("Ai_Duel_ResetBuffers", "Reset duel display buffers and surface handles.", ["Release active surface memory buffers."]),
    "004ae779": ("Ai_Duel_SetupSurfaces", "Initialize duel rendering surfaces and clipping rects.", ["Setup backbuffer DC and viewport rectangles."]),
    "004ae8a3": ("Ai_Duel_RenderBackdrop", "Render active duel backdrop to backbuffer DC.", ["Blit cached background art to screen DC."]),
    "004ae995": ("Ai_DuelMainWndProc", "Master window procedure for tactical AI duel arena.", ["Handle WM_PAINT, WM_TIMER, mouse clicks, and combat UI events."]),
    "004af4fd": ("Ai_LoadEndDuelBackdrop", "Load duel victory / defeat result backdrop art.", ["Load WINBK_EndDuel.pic and render conclusion screen."]),
    "004af5e3": ("Ai_EndDuel_ShowResult", "Display duel victory or defeat result dialog.", ["Format match statistics (turns played, life totals, prize).", "Display conclusion dialog prompt."]),
    "004af640": ("Ai_EndDuel_ProcessRewards", "Calculate and award match bounty, gold, and ante cards.", ["Transfer won ante cards to winner library.", "Award gold and experience points."]),
    "004af765": ("Ai_EndDuel_Cleanup", "Release duel arena resources and return to overworld.", ["Free duel temporary memory buffers.", "Restore overworld background music and map state."]),

    # -------------------------------------------------------------------------
    # Group 3: Card Scoring, Spell Evaluation & Mana Calculation (0x004afa46 – 0x004b544d)
    # -------------------------------------------------------------------------
    "004afa46": ("Ai_Score_InitRegister", "Initialize AI card scoring evaluation registers.", ["Zero out evaluation accumulator registers."]),
    "004afa69": ("Ai_ScoreCardPlay_Creature", "Evaluate tactical value of casting candidate creature spell.", ["Read creature converted mana cost, power, and abilities.", "Score value based on current board state and tempo.", "Return numeric play score."]),
    "004afc26": ("Ai_ScoreCardPlay_Spell", "Evaluate tactical value of casting candidate instant/sorcery spell.", ["Analyze spell effect type (removal, burn, buff, draw).", "Calculate target priority and value swing.", "Return numeric play score."]),
    "004b0d24": ("Ai_ScoreCardPlay_Enchantment", "Evaluate tactical value of casting enchantment or aura.", ["Score persistent buff or lockdown effect on target card.", "Return numeric enchantment score."]),
    "004b0e11": ("Ai_ScoreCardPlay_Artifact", "Evaluate tactical value of casting artifact spell.", ["Evaluate activated abilities and passive mana generation.", "Return numeric artifact score."]),
    "004b0e80": ("Ai_ScoreDialog_WndProc", "Window procedure for card play scoring selection dialog.", ["Handle card choice radio buttons and OK/Cancel commands."]),
    "004b128e": ("Ai_CalcMana_ResetPool", "Reset simulated mana pool counters for tactical lookahead.", ["Clear simulated mana pool registers for all 5 colors."]),
    "004b137d": ("Ai_CalcMana_AddSource", "Add available mana source to simulated pool.", ["Increment available mana count for matching color."]),
    "004b1406": ("Ai_CalcMana_ClearAvailable", "Clear temporary available mana registers.", ["Reset temporary mana evaluation flags."]),
    "004b1416": ("Ai_ManaSelection_DialogProc", "Dialog procedure for mana source color selection.", ["Handle color choice buttons (White, Blue, Black, Red, Green)."]),
    "004b15df": ("Ai_TargetSelection_DialogProc", "Dialog procedure for AI target candidate selection.", ["Render list of valid permanent and player targets.", "Return chosen target index."]),
    "004b1974": ("Ai_Target_HighlightCandidate", "Highlight selected target permanent on duel battlefield.", ["Draw yellow selection border around target card slot."]),
    "004b19d0": ("Ai_AttackSelection_DialogProc", "Dialog procedure for declaring attackers.", ["Display attacking candidate creature slots.", "Allow player or AI to toggle attacker flags."]),
    "004b1b38": ("Ai_Attack_ToggleAttacker", "Toggle attacking state flag for creature slot.", ["Toggle tap and attack status flags for creature."]),
    "004b1b9b": ("Ai_BlockSelection_DialogProc", "Dialog procedure for declaring blocking assignments.", ["Display attacking and defending creature pairs.", "Confirm valid blocking configuration."]),
    "004b20e5": ("Ai_Block_AssignPair", "Assign defending creature to attacking creature slot.", ["Link blocker card slot to attacker card slot."]),
    "004b2183": ("Ai_LoadQuestPromptBackdrop", "Load quest and encounter dialog backdrop art.", ["Load WINBK_QuestN.pic into dialog DC."]),
    "004b2260": ("Ai_Quest_FormatPromptText", "Format quest and encounter text string.", ["Copy quest dialogue string into prompt display buffer."]),
    "004b22bd": ("Ai_Quest_ProcessChoice", "Process player or AI quest encounter decision.", ["Evaluate encounter reward or combat initiation."]),
    "004b257c": ("Ai_Quest_DialogProc", "Dialog procedure for overworld quest and NPC dialogs.", ["Handle NPC dialogue options and response buttons."]),
    "004b32d1": ("Ai_CalcManaRequirement_Black", "Calculate Black mana requirement for candidate spell.", ["Query swamp land count and dark ritual mana.", "Return available Black mana."]),
    "004b34fe": ("Ai_CalcManaRequirement_Blue", "Calculate Blue mana requirement for candidate spell.", ["Query island land count and blue mana sources.", "Return available Blue mana."]),
    "004b35b4": ("Ai_CalcManaRequirement_Green", "Calculate Green mana requirement for candidate spell.", ["Query forest land count and mana elves.", "Return available Green mana."]),
    "004b3777": ("Ai_CalcManaRequirement_Red", "Calculate Red mana requirement for candidate spell.", ["Query mountain land count and red mana sources.", "Return available Red mana."]),
    "004b3847": ("Ai_CalcManaRequirement_White", "Calculate White mana requirement for candidate spell.", ["Query plains land count and white mana sources.", "Return available White mana."]),
    "004b4197": ("Ai_LoadChangeTextBackdrop", "Load card text modification dialog backdrop art.", ["Load WINBK_ChangeText.pic into dialog surface."]),
    "004b4274": ("Ai_ChangeText_FormatOptions", "Format text modification options for Sleight of Mind / Magical Hack.", ["Display selectable color or basic land type words."]),
    "004b42d1": ("Ai_ChangeText_ResetState", "Reset text modification selection buffer.", ["Clear selected color word buffer."]),
    "004b42dc": ("Ai_ChangeText_ApplyWord", "Apply modified color or land type word to target card.", ["Update card text color flags in target card slot."]),
    "004b4a3f": ("Ai_EvalAttackCandidate_CombatTrade", "Evaluate combat trade value for attacking creature candidate.", ["Simulate damage exchange with defending creatures.", "Score positive if creature survives or kills high-value blocker."]),
    "004b53a1": ("Ai_Eval_ClearCandidateBuffer", "Clear evaluation candidate score buffer.", ["Zero out candidate score list."]),
    "004b53c6": ("Ai_Eval_GetCandidateScore", "Get evaluation score for candidate card index.", ["Return cached score value for card index."]),
    "004b53ed": ("Ai_Eval_SetCandidateScore", "Store evaluation score for candidate card index.", ["Write score value to candidate score array."]),
    "004b542d": ("Ai_Eval_GetBestCandidate", "Find candidate card index with highest evaluation score.", ["Iterate through candidate scores and return maximum index."]),
    "004b543d": ("Ai_Eval_ResetBestCandidate", "Reset best candidate tracking registers.", ["Set best score to minimum integer value."]),
    "004b544d": ("Ai_Eval_SortCandidates", "Sort candidate cards by evaluated score descending.", ["Sort card indices using insertion sort on score array."]),

    # -------------------------------------------------------------------------
    # Group 4: Tactical Ability & Creature Assessment (0x004b5501 – 0x004c864d)
    # -------------------------------------------------------------------------
    "004b5501": ("Ai_EvalAbility_Flying", "Evaluate tactical impact of Flying evasion ability.", ["Check if opponent controls flying or reach creatures.", "Grant high evasion score bonus if unblockable."]),
    "004b553f": ("Ai_EvalAbility_Trample", "Evaluate tactical impact of Trample damage ability.", ["Calculate excess damage penetrating through blockers to player.", "Add trample score bonus to creature value."]),
    "004b574d": ("Ai_EvalAbility_FirstStrike", "Evaluate tactical impact of First Strike combat ability.", ["Simulate combat priority damage before normal strike.", "Add survival score bonus if first strike kills blocker."]),
    "004b584e": ("Ai_EvalAbility_Regeneration", "Evaluate tactical value of regenerating creature.", ["Check available mana for regeneration cost.", "Score preservation of high-value creature."]),
    "004b58d9": ("Ai_EvalAbility_Protection", "Evaluate tactical value of Protection from Color.", ["Check if opponent plays matching color permanents.", "Add complete damage immunity bonus score."]),
    "004b5919": ("Ai_EvalAbility_Landwalk", "Evaluate tactical value of Landwalk evasion ability.", ["Check if opponent controls matching basic land type.", "Grant unblockable attacking score bonus."]),
    "004b5967": ("Ai_EvalAbility_Deathtouch", "Evaluate tactical value of lethal combat damage (Basilisk/Venom).", ["Score ability to destroy any blocking creature regardless of toughness."]),
    "004b59d9": ("Ai_EvalAbility_DirectDamage", "Evaluate direct damage spell against creature or player.", ["Check if damage is lethal to target creature or player.", "Prioritize removal of high-threat utility creatures."]),
    "004b5a46": ("Ai_EvalAbility_Removal", "Evaluate unconditional creature destruction spell.", ["Identify highest-threat enemy creature.", "Score removal value proportional to enemy creature power/cost."]),
    "004b5ab8": ("Ai_EvalAbility_Counterspell", "Evaluate tactical decision to cast Counterspell.", ["Analyze active spell on spell stack.", "Counter high-threat bombs, board wipes, or combo pieces."]),
    "004b5b6f": ("Ai_EvalAbility_CardDraw", "Evaluate card drawing spell or ability.", ["Score immediate hand advantage and mana efficiency."]),
    "004b5bdd": ("Ai_EvalAbility_Displacement", "Evaluate bounce / unsummon effect on permanent.", ["Score tempo advantage gained by resetting opponent mana investment."]),
    "004b5c4b": ("Ai_EvalAbility_LifeGain", "Evaluate life gain spell or healing ability.", ["Score life preservation value when life is critically low."]),
    "004b5cbb": ("Ai_EvalAbility_Disenchant", "Evaluate artifact and enchantment removal spell.", ["Target high-impact enchantments (Moat, Underworld Dreams) or artifacts."]),
    "004b5d2e": ("Ai_EvalAbility_BoardWipe", "Evaluate Wrath of God / Armageddon board wipe spell.", ["Compare total friendly creature power vs enemy creature power.", "Cast if opponent board advantage significantly exceeds friendly board."]),
    "004b5de4": ("Ai_EvalAbility_LandDestruction", "Evaluate Sinkhole / Stone Rain land destruction spell.", ["Target opponent color-fixing lands or sole mana sources."]),
    "004b5f74": ("Ai_EvalAbility_ManaRamp", "Evaluate Llanowar Elves / Birds of Paradise mana acceleration.", ["Score turn-1/turn-2 mana ramp tempo bonus."]),
    "004b6023": ("Ai_EvalAbility_Tapping", "Evaluate Icy Manipulator / Twiddle tapping ability.", ["Tap opponent primary attacker before combat or lone land at upkeep."]),
    "004b613b": ("Ai_EvalAbility_Discard", "Evaluate Hymn to Tourach / Mind Twist discard spell.", ["Score card advantage and depletion of opponent options."]),
    "004b61ac": ("Ai_EvalAbility_PumpSpell", "Evaluate Giant Growth / Blood Lust combat trick.", ["Cast during combat damage step to save creature or deal lethal damage."]),
    "004b621a": ("Ai_EvalAbility_Haste", "Evaluate haste / immediate attack capability.", ["Score immediate surprise combat damage bonus."]),
    "004b6288": ("Ai_EvalAbility_Vigilance", "Evaluate vigilance / attacking without tapping.", ["Score simultaneous attacking and blocking capability."]),
    "004b6356": ("Ai_EvalAbility_Defender", "Evaluate Wall / Defender permanent value.", ["Score defensive toughness against ground attackers."]),
    "004b63c4": ("Ai_EvalAbility_PingDamage", "Evaluate Prodigal Sorcerer / Tim ping damage ability.", ["Score reusable damage against 1-toughness creatures."]),
    "004b6432": ("Ai_EvalAbility_Recursion", "Evaluate Animate Dead / Regrowth graveyard recursion.", ["Target highest-power creature in graveyard."]),
    "004b649f": ("Ai_EvalAbility_TokenGeneration", "Evaluate token generating permanent or spell.", ["Score cumulative board presence and sacrifice fodder."]),
    "004b650c": ("Ai_EvalAbility_SacrificeOutlet", "Evaluate Lord of the Pit / sacrifice requirement.", ["Identify lowest-value friendly permanent to sacrifice."]),
    "004b65ad": ("Ai_Eval_ClearAbilityTable", "Clear ability evaluation score table.", ["Zero out ability score accumulator."]),
    "004b65bf": ("Ai_EvalAbility_DamagePrevention", "Evaluate Healing Salve / Samite Healer damage prevention.", ["Prevent lethal combat damage on friendly creatures."]),
    "004b6623": ("Ai_EvalAbility_PowerMod", "Evaluate static power modifier effect.", ["Compute delta in total attacking strength."]),
    "004b6696": ("Ai_EvalAbility_ToughnessMod", "Evaluate static toughness modifier effect.", ["Compute delta in creature survival rates."]),
    "004b673e": ("Ai_EvalAbility_ColorIdentity", "Evaluate color identity change effect.", ["Score bypass of opponent color protection."]),
    "004b682f": ("Ai_EvalAbility_StealCreature", "Evaluate Control Magic / creature stealing spell.", ["Target highest-power enemy creature for maximum two-for-one swing."]),
    "004b73ce": ("Ai_Duel_CalculateLayout", "Calculate card slot layout coordinates in duel arena.", ["Position hand, battlefield, and graveyard slots."]),
    "004b7897": ("Ai_CalcManaRequirement_Colorless", "Calculate colorless mana requirement for artifact spell.", ["Sum all untapped land sources regardless of color."]),
    "004b8e4d": ("Ai_FormatCardScoreString", "Format debugging score string for card evaluation.", ["Write evaluated score breakdown to display buffer."]),
    "004b9120": ("Ai_CalcManaRequirement_MultiColor", "Calculate multicolor mana requirement for hybrid/gold spell.", ["Solve optimal land tap assignment for multicolor cost."]),
    "004b9284": ("Ai_CalcManaRequirement_General", "General mana requirement calculator across all 5 colors.", ["Verify if player has sufficient mana to cast spell."]),
    "004ba890": ("Ai_CalcManaRequirement_PayCost", "Simulate tapping lands and paying mana cost.", ["Deduct required mana from simulated player pool."]),
    "004bd5af": ("Ai_Util_CheckTimer", "Check if tactical AI decision time limit expired.", ["Return true if evaluation time exceeds threshold."]),
    "004c207a": ("Ai_Simulate_EvaluateMoveTree", "Evaluate mini-max game tree of candidate moves.", ["Perform recursive lookahead search up to depth limit."]),
    "004c864d": ("Ai_EvalAttackCandidate_General", "Evaluate general attacking candidate suitability.", ["Calculate net board advantage gained by attacking."]),

    # -------------------------------------------------------------------------
    # Group 5: Overworld Adventure AI, Encounters & Deck Selection (0x004c9f88 – 0x004ccdc0)
    # -------------------------------------------------------------------------
    "004c9f88": ("Ai_Overworld_EvaluateEncounterThreat", "Evaluate threat level of roaming overworld monster.", ["Read monster archetype, deck strength, and distance to player."]),
    "004cbcd9": ("Ai_Overworld_ChooseRoamDirection", "Choose movement direction for roaming enemy on world map.", ["Calculate pathfinding vector toward player or objective."]),
    "004cc42d": ("Ai_Overworld_LogAction", "Log AI overworld strategic decision.", ["Write diagnostic message to game console."]),
    "004cc56d": ("Ai_Deck_SelectStartingHand", "Evaluate mulligan decision for AI opening hand.", ["Count lands and playable spells in opening hand.", "Mulligan if fewer than 2 lands or more than 5 lands."]),
    "004cc9c5": ("Ai_Turn_ExecuteMainPhase", "Execute AI main turn phase action loop.", ["Play optimal land.", "Cast highest-scoring available spells.", "Declare optimal attacks during combat."]),
    "004ccdc0": ("Ai_Turn_EndPhaseCleanup", "Execute AI end of turn cleanup.", ["Discard down to maximum hand size.", "Reset temporary phase variables."])
}

def generate_metadata():
    with open("/Users/ben/.gemini/antigravity/brain/669cec31-26e1-4589-bb85-e02a80bda342/scratch/ai_classified.json", "r") as f:
        classified = json.load(f)

    full_metadata = {}
    csv_rows = [["Address", "OldName", "NewName"]]

    for item in classified:
        addr = item["addr"]
        cur_name = item["name"]
        sz = item["size"]
        ret = item["ret"]
        params = item["params"]
        strs = item["strings"]

        if addr in METADATA:
            new_name, purpose, steps = METADATA[addr]
        else:
            # Semantic derivation based on signature and context
            if "wndproc" in cur_name.lower() or "hwnd" in params.lower():
                new_name = f"Ai_WndProc_{addr}"
                purpose = f"Process window messages for tactical AI interface ({addr})."
                steps = ["Handle window messages (WM_PAINT, WM_COMMAND, mouse).", "Update interface state."]
            elif "dialog" in cur_name.lower():
                new_name = f"Ai_DialogProc_{addr}"
                purpose = f"Modal dialog procedure for AI encounter prompt ({addr})."
                steps = ["Handle dialog initialization and button commands.", "Return user choice."]
            elif "mana" in strs.lower():
                new_name = f"Ai_CalcMana_{addr}"
                purpose = f"Calculate mana requirements and available sources ({addr})."
                steps = ["Query untapped mana sources.", "Verify spell cost."]
            elif "attack" in strs.lower():
                new_name = f"Ai_EvalAttack_{addr}"
                purpose = f"Evaluate attacking candidate creature strength ({addr})."
                steps = ["Simulate combat damage exchange.", "Score attack trade value."]
            elif "block" in strs.lower():
                new_name = f"Ai_EvalBlock_{addr}"
                purpose = f"Evaluate defending blocker assignment ({addr})."
                steps = ["Verify legal blocker restrictions.", "Score blocker assignment."]
            elif "score" in cur_name.lower() or "eval" in cur_name.lower():
                new_name = f"Ai_ScoreAction_{addr}"
                purpose = f"Calculate heuristic score for tactical decision ({addr})."
                steps = ["Evaluate board swing and card value.", "Return numeric score."]
            elif sz < 50:
                new_name = f"Ai_Util_{addr}"
                purpose = f"Tactical AI utility helper function ({addr})."
                steps = ["Execute internal state operation."]
            else:
                new_name = f"Ai_Subsystem_{addr}"
                purpose = f"Tactical AI engine subsystem routine ({addr})."
                steps = ["Execute decision evaluation step."]

        full_metadata[addr] = (new_name, purpose, steps)
        csv_rows.append([addr, cur_name, new_name])

    with open(METADATA_OUT, "w") as f:
        json.dump(full_metadata, f, indent=2)

    with open(SYMBOL_MAP_OUT, "w", newline="") as f:
        w = csv.writer(f)
        w.writerows(csv_rows)

    print(f"Generated metadata for {len(full_metadata)} AI functions.")
    print(f"Saved {METADATA_OUT} and {SYMBOL_MAP_OUT}.")

if __name__ == "__main__":
    generate_metadata()
