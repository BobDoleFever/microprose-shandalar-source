/*
 * shandalar/magic_engine.h - MicroProse Core Turn Engine & State Machine
 * Original Author: Sid Meier (sid/Magic.c)
 * Comments follow Simplified Technical English (ASD-STE100) rules.
 */
#ifndef SHANDALAR_MAGIC_ENGINE_H
#define SHANDALAR_MAGIC_ENGINE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Match Turn Phases.
 * Identifies the current step in a player turn.
 */
typedef enum TurnPhase {
    PHASE_UNTAP    = 0, /* Untap step: Untap lands, creatures, and artifacts. */
    PHASE_UPKEEP   = 1, /* Upkeep step: Pay upkeep costs and check triggers. */
    PHASE_DRAW     = 2, /* Draw step: Active player draws a card from library. */
    PHASE_MAIN_1   = 3, /* Pre-combat main phase: Cast spells and play lands. */
    PHASE_COMBAT   = 4, /* Combat phase: Declare attackers, declare blockers, apply damage. */
    PHASE_MAIN_2   = 5, /* Post-combat main phase: Cast remaining spells. */
    PHASE_DISCARD  = 6, /* Discard step: Discard cards down to maximum hand size. */
    PHASE_CLEANUP  = 7  /* Cleanup step: Remove temporary damage and end-of-turn effects. */
} TurnPhase;

/*
 * Card Slot Status Bitflags.
 * Used in g_CardSlot_Flags to track card state on the battlefield.
 */
typedef enum CardStatusFlags {
    STATUS_TAPPED          = 0x0001, /* Card is tapped (turned sideways). */
    STATUS_SUMMONING_SICK  = 0x0002, /* Creature has summoning sickness. */
    STATUS_ATTACKING       = 0x0004, /* Creature is currently attacking. */
    STATUS_BLOCKING        = 0x0008, /* Creature is currently blocking. */
    STATUS_ENCHANTED       = 0x0010, /* Card has an attached aura/enchantment. */
    STATUS_DESTROYED       = 0x0020  /* Card is marked for graveyard destruction. */
} CardStatusFlags;

/*
 * Core Magic Engine API Functions
 */

/*
 * Magic_ScanCards
 * Purpose: Scan all active cards on the battlefield for state changes and triggers.
 * Procedure:
 * 1. Increment the recursion depth counter and check that depth is less than 10.
 * 2. Count active card slots for Player 0 and Player 1.
 * 3. Call the card script action callback for each active card.
 * 4. Update status flags and trigger pending continuous effects.
 * Parameter phase_id: The identifier of the current game phase.
 */
void Magic_ScanCards(int phase_id);

/*
 * Magic_TriggerCardEvent
 * Purpose: Run one card's own script handler (the function pointer at offset 0x10 of its
 *   master card record) for an event, with the card-event context set up around it.
 * Parameter player: Index of the player that owns the card (0 or 1).
 * Parameter slot: Index of the card slot.
 * Parameter event_code: The event identifier passed to the card script.
 * Parameter target_player, target_slot: The event's target, stored in g_EventTargetPlayer and
 *   g_EventTargetSlot.
 * Returns: Result code from the card script callback (99 means it asked to stop).
 * Verified in part on the live game; see docs/SYMBOL_VERIFICATION.md.
 */
int Magic_TriggerCardEvent(int player, int slot, int event_code, int target_player, int target_slot);

/*
 * Magic_IsManaSource
 * Purpose: Resolve the top spell or activated ability on the resolution stack.
 * Procedure:
 * 1. Check if the spell stack contains any active entries.
 * 2. Execute the spell effect function.
 * 3. Move resolved spell card to the graveyard or battlefield.
 * 4. Decrement the stack depth counter.
 */
void Magic_IsManaSource(void);

/*
 * Magic_PushEventContext
 * Purpose: Save the current card-event context onto a stack (32 frames, depth in
 *   DAT_0052577c) so events can nest. Saves g_EventSourcePlayer, g_EventSourceSlot,
 *   g_EventCardId, g_EventCardColorMask, g_EventTargetPlayer, g_EventTargetSlot and g_CardEventResult.
 * Verified against the running game; the original label "pay mana cost" was wrong.
 *   See docs/SYMBOL_VERIFICATION.md.
 */
void Magic_PushEventContext(void);

/*
 * Magic_PopEventContext
 * Purpose: Restore the card-event context saved by Magic_PushEventContext (drop one
 *   stack frame and reload the seven event globals).
 * Verified against the running game (98 pops, restoring outer contexts); the original label
 *   "tap card for mana" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
void Magic_PopEventContext(void);

/*
 * Magic_UntapTurnPhase
 * Purpose: Execute the Untap step for the active player.
 * Untaps all tapped lands, creatures, and artifacts that can untap.
 */
void Magic_UntapTurnPhase(void);

/*
 * Duel_PlaySoundById
 * Purpose: Play one duel sound effect by id (0x00-0x2f); loads the .wav on first use.
 * Verified against the live game; see docs/SYMBOL_VERIFICATION.md.
 */
int Duel_PlaySoundById(int sound_id);

/*
 * Duel_PreloadSoundEffects
 * Purpose: Preload the 20 duel sound effects. Runs once when a duel starts.
 * Verified against the live game; see docs/SYMBOL_VERIFICATION.md.
 */
void Duel_PreloadSoundEffects(void);

/*
 * Magic_MainTurnPhase
 * Purpose: Execute the Main phase.
 * Grants priority to the active player to cast spells and play lands.
 */
void Magic_MainTurnPhase(void);

/*
 * Magic_PushSpellStack
 * Purpose: Push one card event (a spell, ability or trigger) onto the spell stack, a table of up to
 *   32 entries counted by g_SpellStackCount. Each entry packs the card id, the event code (bits 16-23)
 *   and the target slot (bits 24-31) into g_SpellStackEntries and records the owner and slot in
 *   g_SpellStackObjects. For cards with an id of 5 or more it also copies the card into a free slot as a
 *   stand-in object marked with g_StackObjectCardId.
 * Static evidence only; the original label "combat phase" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
void Magic_PushSpellStack(int player, int slot, int event_code, int target_slot, int flags);

/*
 * Magic_ResolveTopSpell
 * Purpose: Pop the top entry of the spell stack and run it: the card's own handler through
 *   Magic_TriggerCardEvent, or the in-step broadcast for event 0x7e, with extra handling for stand-in
 *   objects.
 * Static evidence only; the original label "end of turn" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
void Magic_ResolveTopSpell(void);

/*
 * Magic_DropTopSpell
 * Purpose: Pop the top entry of the spell stack without running it, clearing its stand-in card slot.
 * Static evidence only; the original label "discard to hand size" was wrong. See docs/SYMBOL_VERIFICATION.md.
 */
void Magic_DropTopSpell(void);

/*
 * Magic_CleanupPhase
 * Purpose: Remove temporary damage and reset continuous until-end-of-turn modifiers.
 */
void Magic_CleanupPhase(void);

/*
 * Deck_PickRandomSecondaryColor
 * Purpose: Select a random color that is not already in the player deck.
 * Parameter existing_color_mask: Bitmask of colors currently assigned.
 * Returns: Bitmask for the new secondary color (1 << color_index).
 */
int Deck_PickRandomSecondaryColor(uint32_t existing_color_mask);

/*
 * Deck_GenerateStartingResources
 * Purpose: Allocate starting deck cards, amulets, gold, and life for a new campaign.
 */
void Deck_GenerateStartingResources(void);

/*
 * Deck_PopulateCategoryCards
 * Purpose: Select and insert random cards into the player deck matching quotas, color, and rarity.
 * Parameter color_mask: Bitmask of valid colors.
 * Parameter num_lands: Count of basic land cards to add.
 * Parameter num_spells: Count of non-creature spell and artifact cards to add.
 * Parameter num_creatures: Count of creature cards to add.
 * Parameter guaranteed_rare_count: Count of guaranteed Rare cards to add (1 or 0).
 * Parameter allow_colorless_artifacts: 1 to allow colorless artifact rolls, 0 for colored spells only.
 * Returns: 0 on success.
 */
int32_t Deck_PopulateCategoryCards(uint32_t color_mask, int num_lands, int num_spells, int num_creatures, int guaranteed_rare_count, int allow_colorless_artifacts);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_MAGIC_ENGINE_H */
