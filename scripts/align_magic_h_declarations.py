#!/usr/bin/env python3
import re

def align():
    with open("/Users/ben/decomp/include/magic.h", "r") as f:
        content = f.read()

    # Align prototypes in magic.h with magic_engine.h
    replacements = {
        r'bool\s+Magic_ResolveSpellStack\([^)]*\);;?': 'void Magic_ResolveSpellStack(void);',
        r'void\s+Magic_PayManaCost\([^)]*\);;?': 'int Magic_PayManaCost(int player_id, int color_mask, int total_cost);',
        r'void\s+Magic_TapCardForMana\([^)]*\);;?': 'void Magic_TapCardForMana(int player_id, int card_slot);',
        r'undefined4\s+Magic_UpkeepPhase\([^)]*\);;?': 'void Magic_UpkeepPhase(void);',
        r'undefined4\s+Magic_MainTurnPhase\([^)]*\);;?': 'void Magic_MainTurnPhase(void);',
        r'undefined4\s+Magic_CombatPhase\([^)]*\);;?': 'void Magic_CombatPhase(void);',
        r'undefined4\s+Magic_EndTurnPhase\([^)]*\);;?': 'void Magic_EndTurnPhase(void);',
        r'undefined4\s+Magic_DiscardToHandSize\([^)]*\);;?': 'void Magic_DiscardToHandSize(int player_id);',
        r'undefined4\s+Magic_CleanupPhase\([^)]*\);;?': 'void Magic_CleanupPhase(void);',
        r'undefined4\s+Magic_UntapTurnPhase\([^)]*\);;?': 'void Magic_UntapTurnPhase(void);',
        r'undefined4\s+Magic_DrawCardPhase\([^)]*\);;?': 'void Magic_DrawCardPhase(void);',
    }

    for pat, rep in replacements.items():
        content = re.sub(pat, rep, content)

    with open("/Users/ben/decomp/include/magic.h", "w") as f:
        f.write(content)
    print("Aligned magic.h prototypes!")

if __name__ == "__main__":
    align()
