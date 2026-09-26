#!/usr/bin/env python3
import re

def align():
    with open("/Users/ben/decomp/include/magic.h", "r") as f:
        content = f.read()

    # Align prototypes in magic.h with magic_engine.h
    replacements = {
        r'bool\s+Magic_ResolveSpellStack\([^)]*\);;?': 'void Magic_ResolveSpellStack(void);',
        r'void\s+Magic_PushEventContext\([^)]*\);;?': 'void Magic_PushEventContext(void);',
        r'void\s+Magic_PopEventContext\([^)]*\);;?': 'void Magic_PopEventContext(void);',
        r'undefined4\s+Duel_PlaySoundById\([^)]*\);;?': 'int Duel_PlaySoundById(int sound_id);',
        r'undefined4\s+Magic_MainTurnPhase\([^)]*\);;?': 'void Magic_MainTurnPhase(void);',
        r'undefined4\s+Magic_CombatPhase\([^)]*\);;?': 'void Magic_CombatPhase(void);',
        r'undefined4\s+Magic_EndTurnPhase\([^)]*\);;?': 'void Magic_EndTurnPhase(void);',
        r'undefined4\s+Magic_DiscardToHandSize\([^)]*\);;?': 'void Magic_DiscardToHandSize(int player_id);',
        r'undefined4\s+Magic_CleanupPhase\([^)]*\);;?': 'void Magic_CleanupPhase(void);',
        r'undefined4\s+Magic_UntapTurnPhase\([^)]*\);;?': 'void Magic_UntapTurnPhase(void);',
        r'undefined4\s+Duel_PreloadSoundEffects\([^)]*\);;?': 'void Duel_PreloadSoundEffects(void);',
    }

    for pat, rep in replacements.items():
        content = re.sub(pat, rep, content)

    with open("/Users/ben/decomp/include/magic.h", "w") as f:
        f.write(content)
    print("Aligned magic.h prototypes!")

if __name__ == "__main__":
    align()
