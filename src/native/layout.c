/*
 * layout.c - addresses of the duel engine's globals and functions in MAGIC.EXE and DUEL.EXE.
 *
 * Every address was read off the decompiled body of the function that uses it, in both programs
 * (magic/magic_unified.c and its twin in duel/duel_unified.c), not taken from a symbol name: several
 * DUEL.EXE names in the maps point at neighbouring fields.
 */
#include <string.h>

#include "engine.h"

const Layout LAYOUT_MAGIC = {
    .program = "MAGIC",
    .slot_base = 0x006a5f30,
    .master_base = 0x0051aeb8,
    .card_info_base = 0x006b3074, /* read as DAT_006b3088 = base + 0x14 */
    .player_card_count = 0x006808b8,
    .spell_stack_count = 0x006a3f78,
    .spell_stack_entries = 0x006ff4d0,
    .spell_stack_objects = 0x006fecc0,
    .spell_stack_aux = 0x006ff390,
    .spell_stack_step = 0x00696880,
    .spell_stack_flags = 0x00695d70,
    .stack_object_card_id = 0x006fd3f4,
    .current_step_code = 0x006ff4c0,
    .step_fallback = 0x006ff558,
    .is_ai_thinking = 0x006a285c,
    .event_depth = 0x0063ee18,
    .query_counter = 0x00677340,
    .query_saved = 0x0067bdb0,
    .event_source_player = 0x006b2534,
    .event_source_slot = 0x0070100c,
    .event_card_id = 0x006a4f70,
    .event_card_color = 0x006b2fe4,
    .event_target_slot = 0x006b2d5c,
    .card_event_result = 0x0068a660,
    .duel_mode_flags = 0x006a4a08,
    .token_card_base = 0x006ff2e0,
    .callee = {
        [CALLEE_SCAN_CARDS] = 0x00473f06,
        [CALLEE_IS_TAPPED] = 0x00471c32,
        [CALLEE_COLOR_OVERRIDE_FF] = 0x0041d963,
        [CALLEE_COLOR_OVERRIDE_F9] = 0x0041d9d2,
        [CALLEE_COLOR_MASK_TO_INDEX] = 0x00473cc5,
        [CALLEE_MARK_CARD] = 0x0044867e,
        [CALLEE_AFTER_MARK] = 0x004488a0,
        [CALLEE_FIND_FREE_SLOT] = 0x00451291,
        [CALLEE_PUSH_EVENT_CONTEXT] = 0x00474428,
        [CALLEE_POP_EVENT_CONTEXT] = 0x004744de,
    },
    .entry = {
        [FN_QUERY_CARD_ATTRIBUTE] = 0x00473179,
        [FN_IS_MANA_SOURCE] = 0x00474389,
        [FN_DROP_TOP_SPELL] = 0x00475bb0,
        [FN_PUSH_SPELL_STACK] = 0x004751d7,
        [FN_CLEAR_SPELL_STACK] = 0x00474d1e,
        [FN_GET_COLOR_AND_TYPE_FLAGS] = 0x004d0a42,
    },
};

const Layout LAYOUT_DUEL = {
    .program = "DUEL",
    .slot_base = 0x006826c0,
    .master_base = 0x004ff590,
    .card_info_base = 0x00618ac4, /* read as DAT_00618ad8 = base + 0x14; the doc's name-pointer table */
    .player_card_count = 0x00666408,
    .spell_stack_count = 0x006764b8,
    .spell_stack_entries = 0x0068f240,
    .spell_stack_objects = 0x0068efb0,
    .spell_stack_aux = 0x0068f120,
    .spell_stack_step = 0x00666960,
    .spell_stack_flags = 0x00666460,
    .stack_object_card_id = 0x0068eee0,
    .current_step_code = 0x0068f230,
    .step_fallback = 0x0068f2c4,
    .is_ai_thinking = 0x0066aaf4,
    .event_depth = 0x0068eed8,
    .query_counter = 0x006663e0,
    .query_saved = 0x005ef980,
    .event_source_player = 0x0068ecb0,
    .event_source_slot = 0x00690c48,
    .event_card_id = 0x00681ecc,
    .event_card_color = 0x0068ee64,
    .event_target_slot = 0x0068ecfc,
    .card_event_result = 0x0066642c,
    .duel_mode_flags = 0x00681eb0,
    .token_card_base = 0x0068f104,
    .callee = {
        [CALLEE_SCAN_CARDS] = 0x0048c5a8,
        [CALLEE_IS_TAPPED] = 0x0048a33f,
        [CALLEE_COLOR_OVERRIDE_FF] = 0x004af74c,
        [CALLEE_COLOR_OVERRIDE_F9] = 0x004af7bb,
        [CALLEE_COLOR_MASK_TO_INDEX] = 0x0048c367,
        [CALLEE_MARK_CARD] = 0x0046e571,
        [CALLEE_AFTER_MARK] = 0x0046e793,
        [CALLEE_FIND_FREE_SLOT] = 0x004d695b,
        [CALLEE_PUSH_EVENT_CONTEXT] = 0x0048cac9,
        [CALLEE_POP_EVENT_CONTEXT] = 0x0048cb7f,
    },
    .entry = {
        [FN_QUERY_CARD_ATTRIBUTE] = 0x0048b81a,
        [FN_IS_MANA_SOURCE] = 0x0048ca2a,
        [FN_DROP_TOP_SPELL] = 0x0048e251,
        [FN_PUSH_SPELL_STACK] = 0x0048d878,
        [FN_CLEAR_SPELL_STACK] = 0x0048d3bf,
        [FN_GET_COLOR_AND_TYPE_FLAGS] = 0x004521e2,
    },
};

const Layout *layout_for(const char *program)
{
    if (strcmp(program, "MAGIC") == 0)
        return &LAYOUT_MAGIC;
    if (strcmp(program, "DUEL") == 0)
        return &LAYOUT_DUEL;
    return NULL;
}
