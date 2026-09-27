#!/usr/bin/env python3
import re

def main():
    filepath = "/Users/ben/decomp/src/magic/sid/Ai.c"
    with open(filepath, "r") as f:
        content = f.read()

    comments = {
        "Ai_SaveGameState": """/*
 * Ai_SaveGameState
 * Purpose: Copy the current game state to the backup memory buffer.
 * Procedure:
 * 1. Set the backup counter to zero.
 * 2. Copy card arrays, player structures, and life totals to the backup buffer.
 * 3. Verify that the ScWilly evaluation score is valid (ScWilly >= 0).
 */""",
        "Ai_RestoreGameState": """/*
 * Ai_RestoreGameState
 * Purpose: Copy the saved game state from the backup buffer to active memory.
 * Procedure:
 * 1. Copy all card data back to active card structures.
 * 2. Restore life totals, mana pool values, and turn counters.
 * 3. Reset temporary lookahead variables.
 */""",
        "Ai_PushBoardState": """/*
 * Ai_PushBoardState
 * Purpose: Push the active board state onto the decision tree stack.
 * Use this function before starting deep lookahead simulation.
 */""",
        "Ai_PopBoardState": """/*
 * Ai_PopBoardState
 * Purpose: Pop and restore the previous board state from the decision tree stack.
 * Use this function after completing lookahead simulation.
 */""",
        "Ai_ClearPlan": """/*
 * Ai_ClearPlan
 * Purpose: Clear all evaluation state variables for a new tactical analysis pass.
 * Sets the active creature counter to zero and resets default score tables.
 */""",
        "Ai_BeginTrial": """/*
 * Ai_BeginTrial
 * Purpose: Calculate the total tactical score for the active player.
 * Procedure:
 * 1. Initialize the score lookup table to default values (99).
 * 2. Restore the baseline game state.
 * 3. Return the calculated total score.
 */""",
        "Ai_RecordChoice": """/*
 * Ai_RecordChoice
 * Purpose: Calculate attacking power and defensive toughness of creatures on the board.
 * Procedure:
 * 1. Read the power and toughness attributes of the active creature.
 * 2. Store the evaluated values in the creature score array.
 * 3. Increment the active creature counter.
 */""",
        "Ai_GetOpponentPlayerScore": """/*
 * Ai_GetOpponentPlayerScore
 * Purpose: Calculate the threat score of opponent cards on the board.
 * Evaluates creature abilities, card count in hand, and open mana.
 */""",
        "Ai_CalcLifeAdvantage": """/*
 * Ai_CalcLifeAdvantage
 * Purpose: Calculate the score value for the life point difference.
 * Gives a positive score when player life is higher than opponent life.
 */""",
        "Ai_ReplayChoice": """/*
 * Ai_ReplayChoice
 * Purpose: Calculate the score value for card advantage.
 * Gives a higher score for more cards in hand and available cards in the library.
 */""",
        "Ai_CommitBestPlan": """/*
 * Ai_CommitBestPlan
 * Purpose: Calculate the composite score of the full board position.
 * Procedure:
 * 1. Iterate through all active cards on the battlefield.
 * 2. Copy evaluated scores into the master position buffer.
 * 3. Set the position valid flag to 1.
 */""",
        "Ai_EvaluateBoard": """/*
 * Ai_EvaluateBoard
 * Purpose: Simulate a complete combat step between the attacking player and defending player.
 * Procedure:
 * 1. Check legal blocking assignments with Ai_FilterValidBlockers.
 * 2. Calculate potential damage dealt to creatures and defending player.
 * 3. Calculate life point changes and determine combat advantage score.
 */""",
        "Ai_PenalizeCounterattack": """/*
 * Ai_PenalizeCounterattack
 * Purpose: Select the optimal set of creatures to attack during combat.
 * Procedure:
 * 1. Evaluate combat strength for each untapped creature.
 * 2. Simulate combat outcomes against possible opponent blockers.
 * 3. Mark the best candidates with the attack flag.
 */""",
        "Ai_ChooseBlockers": """/*
 * Ai_ChooseBlockers
 * Purpose: Assign defending creatures to block attacking creatures.
 * Procedure:
 * 1. Check legal blocker restrictions for each attacking creature.
 * 2. Optimize blocker pairings to destroy attackers and protect high-value creatures.
 * 3. Assign combat damage priorities.
 */""",
        "Ai_FilterValidBlockers": """/*
 * Ai_FilterValidBlockers
 * Purpose: Verify if a defending creature can legally block a specific attacking creature.
 * Procedure:
 * 1. Check flying and reach attributes.
 * 2. Check landwalk abilities against active land types.
 * 3. Check protection abilities against the attacker color.
 * Returns: 1 if block is legal, or 0 if block is illegal.
 */""",
        "Duel_ShowStartOfDuelDialog": """/*
 * Duel_ShowStartOfDuelDialog
 * Purpose: Distribute lethal combat damage to blockers and trample damage to the defending player.
 */""",
        "Ai_DuelDialogProc": """/*
 * Ai_DuelDialogProc
 * Purpose: Process window and dialog messages for duel match interactions.
 * Handles coin toss, mulligan choices, and user confirmation prompts.
 */""",
        "Ai_StartDuelWndProc": """/*
 * Ai_StartDuelWndProc
 * Purpose: Process window messages for duel initialization and ante selection.
 */""",
        "Ai_DuelMainWndProc": """/*
 * Ai_DuelMainWndProc
 * Purpose: Main window procedure for active duel match play.
 * Handles turn transitions, spell animation triggers, and match completion.
 */""",
        "Ai_LoadStartDuelBackdrop": """/*
 * Ai_LoadStartDuelBackdrop
 * Purpose: Load and display the match introduction background picture.
 */""",
        "Ai_LoadStartDuel2Backdrop": """/*
 * Ai_LoadStartDuel2Backdrop
 * Purpose: Load and display the secondary duel setup background picture.
 */""",
        "Ai_LoadEndDuelBackdrop": """/*
 * Ai_LoadEndDuelBackdrop
 * Purpose: Load and display the victory or defeat match results background picture.
 */"""
    }

    # Replace each function header comment with STE comment
    for func_name, ste_comment in comments.items():
        pattern = r"(/\*\s+\*\s+Decompiled function:\s+" + re.escape(func_name) + r"\s+\*\s+Entry Point:[^\n]+\n\s+\*\s+Size:[^\n]+\n\s+\*/)"
        replacement = ste_comment + "\n\\1"
        if re.search(pattern, content):
            content = re.sub(pattern, replacement, content, count=1)
            print(f"Added STE comment for {func_name}")
        else:
            print(f"Warning: pattern not found for {func_name}")

    with open(filepath, "w") as f:
        f.write(content)

    print("Updated Ai.c with Simplified Technical English comments!")

if __name__ == "__main__":
    main()
