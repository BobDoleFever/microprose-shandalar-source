/*
 * engine.h - native replacements of verified duel-engine functions.
 *
 * Each native function works on a Vm: a memory image addressed like the original program (mem.h),
 * the address layout of the program it stands in for (MAGIC.EXE or DUEL.EXE, which carry the same
 * engine at different addresses), and a hook through which it calls functions that are not native
 * yet. In the difftest harness that hook replays calls recorded from the original; hosted inside the
 * emulator it would call the emulated original.
 *
 * The functions are written from the decompiled bodies in magic/magic_unified.c, checked against
 * their DUEL.EXE twins in duel/duel_unified.c, and named as in docs/SYMBOL_VERIFICATION.md.
 * Field and callee names below describe what the code does; the decompiler's names for the same
 * addresses are given in comments and are not all right.
 */
#ifndef NATIVE_ENGINE_H
#define NATIVE_ENGINE_H

#include <stdint.h>

#include "mem.h"

/* ---- Card slot table: base + player * SLOT_PLAYER_STRIDE + slot * SLOT_STRIDE ----------------- */
#define SLOT_PLAYER_STRIDE 0x5b20u
#define SLOT_STRIDE 0x120u

/* Field offsets inside a slot, identical in both programs (MAGIC base 0x006a5f30, DUEL 0x006826c0). */
#define SLOT_ORIGINAL_CARD 0x00u  /* dword: card index a stand-in object represents (g_ActiveCardsInPlay) */
#define SLOT_CARD 0x04u           /* dword: index into the master card table, -1 = empty (g_CardSlot_CardId) */
#define SLOT_FLAGS 0x0cu          /* dword/byte: bit 2 tested by the queries (g_CardSlot_Flags) */
#define SLOT_S16_10 0x10u         /* short: returned by query code 0x35; the death check compares toughness with it */
#define SLOT_CHAR_12 0x12u        /* char: copied into the stack's aux entry; compared with a player in code 0x3c */
#define SLOT_POWER_CACHE 0x14u    /* short: last power computed by query 0x32 */
#define SLOT_TOUGH_CACHE 0x16u    /* short: last toughness computed by query 0x33 */
#define SLOT_POWER_MOD 0x18u      /* short: added to the printed power */
#define SLOT_TOUGH_MOD 0x1au      /* short: added to the printed toughness */
#define SLOT_COLOR_BYTE 0x1cu     /* byte: set from the master record's colour byte by query 0x3c */
#define SLOT_COLOR_MASK 0x1du     /* byte: colour mask, input of the colour/type flags */
#define SLOT_BYTE_20 0x20u        /* byte: cleared for a stand-in object */
#define SLOT_DWORD_28 0x28u       /* dword: copied into the stack's aux entry; compared with a slot in code 0x3c */
#define SLOT_DISPLAY 0x34u        /* dword: kept when a slot is overwritten by a stand-in object */
#define SLOT_ABILITIES1 0x38u     /* dword; byte +0x38 bit 0x40 and byte +0x39 bit 0x40 (doubles power) are tested */
#define SLOT_ABILITIES2 0x3cu     /* dword; its top byte (+0x3f) holds "recompute" bits 1, 2, 4 and 8 */
#define SLOT_DWORD_44 0x44u       /* dword: copied to a stand-in object */
#define SLOT_DWORD_50 0x50u       /* dword: cleared for a stand-in object */
#define SLOT_STANDIN_PLAYER 0xf0u /* dword: the stand-in's source player */
#define SLOT_STANDIN_SLOT 0xf4u   /* dword: the stand-in's source slot */
#define SLOT_BYTE_11F 0x11fu      /* byte: cleared when query 0x3c restores the original card */

/* ---- Master card table: base + index * MASTER_STRIDE (MAGIC 0x0051aeb8, DUEL 0x004ff590) ------- */
#define MASTER_STRIDE 0x34u
#define MASTER_CARD_ID 0x00u   /* dword: card id, indexes the 0x98-byte card-info table */
#define MASTER_TYPE 0x04u      /* byte: 0x01 land, 0x02 creature, 0x04 enchantment, 0x08 spell, 0x10, 0x20 */
#define MASTER_COLOR 0x06u     /* char: colour mask (1 colourless, 2..0x20 the five colours) */
#define MASTER_POWER 0x0au     /* short: printed power */
#define MASTER_TOUGHNESS 0x0cu /* short: printed toughness */
#define MASTER_HANDLER 0x10u   /* dword: the card's own event handler, handler(player, slot, event_code) */
#define MASTER_ABILITIES 0x14u /* dword: printed abilities */
#define MASTER_FLAGS 0x18u     /* dword: bit 0x1000 taps for mana, bit 1 excludes it */

#define CARD_INFO_STRIDE 0x98u

/* ---- Functions the native code calls but does not implement ---------------------------------- */
typedef enum {
    CALLEE_CARD_HANDLER,         /* a card's own event handler: its address is read from the master record (+0x10), so
                                  * it differs per call and has no entry in the layout (vm_call_at) */
    CALLEE_SCAN_CHECK,           /* FUN_004728c3 / FUN_0048af80(player, slot): tested after a turn-start scan */
    CALLEE_BROADCAST_CARD_EVENT, /* Magic_BroadcastCardEvent(player, slot, event) */
    CALLEE_COMBAT_DAMAGE_STEP,   /* FUN_00472fae / FUN_0048b64f(): run after a turn-start scan of the turn player */
    CALLEE_MARK_CARD,            /* Pic_Subsystem_0044867e / Duel_DrawCardSprite(player, slot, what) */
    CALLEE_AFTER_MARK,           /* Pic_Subsystem_004488a0() */
    CALLEE_FIND_FREE_SLOT,       /* Pic_Subsystem_00451291(player, card): allocate a slot */
    CALLEE_AI_PREROLL_RANDOM,    /* FUN_004398be / Ai_Util_0040a1ff(): fills the AI's table of 100 random numbers (calls _rand) */
    CALLEE_FUNCTION,             /* any other function, at the address passed in (called from lifted code, lift_bridge.c) */
    CALLEE_COUNT
} Callee;

/* ---- Native functions ------------------------------------------------------------------------- */
typedef enum {
    FN_QUERY_CARD_ATTRIBUTE,
    FN_IS_MANA_SOURCE,
    FN_DROP_TOP_SPELL,
    FN_PUSH_SPELL_STACK,
    FN_CLEAR_SPELL_STACK,
    FN_GET_COLOR_AND_TYPE_FLAGS,
    FN_PUSH_EVENT_CONTEXT,
    FN_POP_EVENT_CONTEXT,
    FN_CARD_IS_IN_PLAY,
    FN_COLOR_MASK_TO_INDEX,
    FN_REMAP_COLOR_INDEX_FF,
    FN_REMAP_COLOR_INDEX_F9,
    FN_AI_RECORD_CHOICE,
    FN_AI_REPLAY_CHOICE,
    FN_AI_COMMIT_BEST_PLAN,
    FN_AI_CLEAR_PLAN,
    FN_AI_GET_PLAN_CURSOR,
    FN_AI_PLAN_CURSOR_BACK,
    FN_AI_PEEK_PLANNED_SLOT,
    FN_AI_PEEK_PLANNED_CHOICE,
    FN_AI_GET_LAND_COLOR_MASKS,
    FN_SCAN_CARDS,
    FN_CRT_MEMCPY,
    FN_AI_SAVE_GAME_STATE,
    FN_AI_RESTORE_GAME_STATE,
    FN_AI_PUSH_BOARD_STATE,
    FN_AI_POP_BOARD_STATE,
    FN_AI_RESET_RANDOM_CURSOR,
    FN_AI_BEGIN_TRIAL,
    FN_CRT_MEMSET,
    FN_COUNT
} NativeFn;

/* Addresses of one program. Comments give the decompiler's names (MAGIC / DUEL). */
typedef struct Layout {
    const char *program; /* "MAGIC" or "DUEL" */
    uint32_t slot_base;
    uint32_t master_base;
    uint32_t card_info_base;       /* DAT_006b3088 / DAT_00618ad8 (+0x14 into each 0x98-byte record) */
    uint32_t player_card_count;    /* int[2]: slots in use per player (g_PlayerActiveCardCount) */
    uint32_t spell_stack_count;    /* g_SpellStackCount */
    uint32_t spell_stack_entries;  /* uint[32]: card | event << 16 | target << 24 (g_SpellStackEntries) */
    uint32_t spell_stack_objects;  /* (player, slot) pairs, -1 terminated (g_SpellStackObjects) */
    uint32_t spell_stack_aux;      /* (char slot+0x12, slot+0x28) pairs (DAT_006ff390 / DAT_0068f120) */
    uint32_t spell_stack_step;     /* int[32]: step code when pushed (DAT_00696880 / DAT_00666960) */
    uint32_t spell_stack_flags;    /* int[32]: the push's flags argument (DAT_00695d70 / DAT_00666460) */
    uint32_t stack_object_card_id; /* g_StackObjectCardId */
    uint32_t current_step_code;    /* g_CurrentStepCode / g_DuelCurrentEventCode */
    uint32_t step_fallback;        /* g_ScWillyScore / g_DuelCombatPhaseState: stored when no step runs */
    uint32_t is_ai_thinking;       /* g_IsAiThinking */
    uint32_t event_depth;          /* DAT_0063ee18 / DAT_0068eed8: non-zero inside an event */
    uint32_t query_counter;        /* DAT_00677340 / DAT_006663e0: incremented by every query */
    uint32_t query_saved;          /* DAT_0067bdb0 / DAT_005ef980: saved on entry, restored on return */
    uint32_t event_source_player;  /* g_EventSourcePlayer */
    uint32_t event_source_slot;    /* g_EventSourceSlot */
    uint32_t event_card_id;        /* g_EventCardId */
    uint32_t event_card_color;     /* g_EventCardColorMask */
    uint32_t event_target_player;  /* g_EventTargetPlayer (DAT_007006c8 / DAT_00690310) */
    uint32_t event_target_slot;    /* g_EventTargetSlot */
    uint32_t event_context_depth;  /* DAT_0052577c / DAT_004fab4c: frames saved by the event-context push */
    uint32_t event_context_stack;  /* DAT_00676e40 / DAT_00665ee0: 32 frames of 0x28 bytes (7 dwords used) */
    uint32_t card_event_result;    /* g_CardEventResult */
    uint32_t duel_mode_flags;      /* g_DuelModeFlags */
    uint32_t token_card_base;      /* DAT_006ff2e0 / g_DuelTargetCardId: first of 0x1d token card indexes */
    /* Magic_ScanCards: runs every card's handler for one event. MAGIC / DUEL. */
    uint32_t scan_event_code;      /* _DAT_006b1584 / _DAT_0068dd04: the event being scanned */
    uint32_t scan_counter;         /* _DAT_00627a0c / _DAT_00666728: incremented by every scan */
    uint32_t scan_depth;           /* DAT_006fe3f8 / DAT_0068ef48: nesting of scans (an assert above 9) */
    uint32_t scan_order_player;    /* DAT_007006e0 / DAT_00690320: int[500], player of each card in play order, -1 ends */
    uint32_t scan_order_slot;      /* DAT_006a5750 / DAT_00681ee0: int[500], its slot */
    uint32_t scan_current_card;    /* _DAT_0068a704 / _DAT_00666448: player * 0x80 + slot of the card being run */
    uint32_t master_count;         /* g_MasterCardCount / DAT_00665ed0: card indexes above this + 0x10 are an error */
    uint32_t turn_player;          /* g_TurnPlayer */
    uint32_t scan_flag;            /* DAT_006ff2d4 / DAT_0068f0f4: set to -1 when a scan marks a card */
    uint32_t global_handler;       /* DAT_0068a64c / DAT_00666418: a card index whose handler runs after every scan, or -1 */
    /* The AI's plan lists: five arrays of 256 dwords per list, one shared cursor (docs, "The AI"). MAGIC / DUEL. */
    uint32_t ai_cursor;            /* DAT_0054be44 / DAT_0050b37c: trial list length and replay cursor */
    uint32_t ai_trial_choice;      /* DAT_005524c8 / DAT_00511a00 */
    uint32_t ai_trial_slot;        /* DAT_0054fc38 / DAT_0050f170: packed slot (low byte slot, bit 8 player, mode bits) */
    uint32_t ai_trial_card;        /* DAT_00553840 / DAT_00512d78: the slot's card index when recorded */
    uint32_t ai_trial_mode;        /* DAT_00553c40 / DAT_00513178 */
    uint32_t ai_best_choice;       /* DAT_005520c8 / DAT_00511600 */
    uint32_t ai_best_slot;         /* DAT_0054f838 / DAT_0050ed70 */
    uint32_t ai_best_card;         /* DAT_00553440 / DAT_00512978 */
    uint32_t ai_best_mode;         /* DAT_005514f8 / DAT_00510a30 */
    uint32_t ai_best_len;          /* DAT_00556928 / DAT_00515e60: set when the best list starts with "no choice" */
    uint32_t ai_packed_slot;       /* DAT_006fefa8 / DAT_0068f0bc: the slot of the choice being made */
    uint32_t ai_choice_value;      /* g_AiChoiceValue (DAT_006ff55c / DAT_0068f2c8) */
    uint32_t ai_plan_mode;         /* DAT_0052ce1c / DAT_004f3c6c: 1 land, 2 cast or activate, 3 target, 4 response */
    uint32_t ai_overflow_flag;     /* g_ActivePlayer / g_DuelHumanPlayerIndex: set to 1 when the list is full */
    uint32_t ai_committed;         /* DAT_00633434 / DAT_0067650c: set to 1 by every commit of a best plan */
    uint32_t ai_peeked_choice;     /* DAT_0062785c / DAT_00666410: written by the planned-choice peek */
    uint32_t ai_random_cursor;     /* DAT_00538334 / DAT_00516744: next pre-rolled random number; reset to 0 by every restore */
    uint32_t ai_trial_word_a;      /* DAT_00701008 / DAT_00690c44: cleared at the start of a trial, and copied to ai_cursor */
    uint32_t ai_trial_word_b;      /* DAT_0063ee70 / DAT_0068ef98: set to -1 at the start of a trial */
    uint32_t ai_search_stage;      /* DAT_006808a8 / DAT_00666400: the search stage; -1 outside the search */
    uint32_t land_counts_x;        /* DAT_0063ee50 / DAT_0068ef70: five per-colour land counts (colour 1 to 5) */
    uint32_t land_counts_y;        /* DAT_0063ee30 / DAT_0068ef50: the other player's */
    uint32_t callee[CALLEE_COUNT];
    uint32_t entry[FN_COUNT];      /* where the original functions start */
} Layout;

extern const Layout LAYOUT_MAGIC;
extern const Layout LAYOUT_DUEL;
const Layout *layout_for(const char *program);

typedef uint32_t (*CallHook)(void *ctx, Callee callee, uint32_t addr, int nargs, const uint32_t *args);

typedef struct Vm {
    Mem *mem;
    const Layout *L;
    CallHook call;
    void *call_ctx;
} Vm;

/* Call a function that is not native (through the hook). */
uint32_t vm_call(Vm *vm, Callee callee, int nargs, const uint32_t *args);
/* A build that links lift_bridge.c sets this: native code that runs a card's handler (the scan) then runs the lifted
 * handler when there is one, instead of calling out through the hook. Returns 1 if it ran the call. */
extern int (*native_handler_dispatch)(Vm *vm, uint32_t addr, int nargs, const uint32_t *args, uint32_t *ret);
/* The same for a callee whose address is not fixed (a card handler): the address is passed in. */
uint32_t vm_call_at(Vm *vm, Callee callee, uint32_t addr, int nargs, const uint32_t *args);

static inline uint32_t slot_addr(const Vm *vm, int32_t player, int32_t slot, uint32_t field)
{
    return vm->L->slot_base + (uint32_t)player * SLOT_PLAYER_STRIDE + (uint32_t)slot * SLOT_STRIDE + field;
}

static inline uint32_t master_addr(const Vm *vm, int32_t index, uint32_t field)
{
    return vm->L->master_base + (uint32_t)index * MASTER_STRIDE + field;
}

/* How often each native function has been entered, nested calls included (native_host.c reads it to charge the guest's clock
 * for the work the original would have done). */
extern uint64_t native_entries[FN_COUNT];
#define NATIVE_ENTER(id) (native_entries[id]++)
/* Native functions the host does not stand in for: lifted code that calls one goes out to the original (native_host.h). */
extern unsigned char native_disabled[FN_COUNT];
/* Set in shadow mode: lifted code calls only the native functions that count their original's instructions exactly (self_charging);
 * the others are run as their lifted twins, or by the original, so that no instruction goes uncounted. */
extern int native_exact_only;

/* Stop on a code path that is not implemented natively (an assert, and an abort under NDEBUG). */
#define NATIVE_UNIMPLEMENTED(what) native_unimplemented(what, __FILE__, __LINE__)
void native_unimplemented(const char *what, const char *file, int line);

uint32_t Native_Magic_QueryCardAttribute(Vm *vm, int32_t player, int32_t slot, int32_t event_code,
                                         uint32_t target_slot);
uint32_t Native_Magic_IsManaSource(Vm *vm, int32_t player, int32_t slot);
uint32_t Native_Magic_DropTopSpell(Vm *vm);
uint32_t Native_Magic_PushSpellStack(Vm *vm, int32_t player, int32_t slot, int32_t event_code,
                                     int32_t target_slot, uint32_t flags);
uint32_t Native_Magic_ClearSpellStack(Vm *vm);
uint32_t Native_Card_GetColorAndTypeFlags(Vm *vm, int32_t player, int32_t slot);
/* Runs every in-play card's handler for `event_code`, then the global handler. */
void Native_Magic_ScanCards(Vm *vm, int32_t event_code);
/* The C runtime's memcpy (a memmove, see crt.c) and what the original's code spends on a call, in instructions. A native
 * function whose cost depends on its arguments adds it to native_cost_extra as it runs. */
uint32_t Native_Crt_Memcpy(Vm *vm, uint32_t dst, uint32_t src, uint32_t n);
uint64_t crt_memcpy_instructions(uint32_t dst, uint32_t src, uint32_t n);
uint32_t Native_Crt_Memset(Vm *vm, uint32_t dst, uint32_t value, uint32_t n);
uint64_t crt_memset_instructions(uint32_t dst, uint32_t n);
extern uint64_t native_cost_extra;

/* The AI's snapshots of the game (ai_state.c): the search saves the game before it starts, and restores it before each trial; the
 * board push and pop are a second, one-deep snapshot. Ai_ResetRandomCursor puts the pre-rolled random numbers back at their start. */
void Native_Ai_SaveGameState(Vm *vm);
void Native_Ai_RestoreGameState(Vm *vm);
void Native_Ai_PushBoardState(Vm *vm);
void Native_Ai_PopBoardState(Vm *vm);
void Native_Ai_ResetRandomCursor(Vm *vm);
void Native_Ai_BeginTrial(Vm *vm);
void Native_Ai_RecordChoice(Vm *vm);
void Native_Ai_ReplayChoice(Vm *vm);
void Native_Ai_CommitBestPlan(Vm *vm);
void Native_Ai_ClearPlan(Vm *vm);
uint32_t Native_Ai_GetPlanCursor(Vm *vm);
void Native_Ai_PlanCursorBack(Vm *vm);
uint32_t Native_Ai_PeekPlannedSlot(Vm *vm, int32_t offset);
uint32_t Native_Ai_PeekPlannedChoice(Vm *vm, int32_t offset);
void Native_Ai_GetLandColorMasks(Vm *vm, uint32_t out_x, uint32_t out_y);
void Native_Magic_PushEventContext(Vm *vm);
void Native_Magic_PopEventContext(Vm *vm);
uint32_t Native_Card_IsInPlay(Vm *vm, int32_t player, int32_t slot);
uint32_t Native_Card_ColorMaskToColorIndex(uint32_t mask);
/* The two per-slot colour-remap lookups: the byte at slot + 0xf9 + index (F9) or + 0xff + index (FF) if it is
 * non-zero (as a signed char), else the index itself. */
int32_t Native_Card_RemapColorIndexF9(Vm *vm, int32_t player, int32_t slot, int32_t index);
int32_t Native_Card_RemapColorIndexFF(Vm *vm, int32_t player, int32_t slot, int32_t index);

/* Name, argument count and return width of each native function, for harnesses. */
typedef struct NativeInfo {
    NativeFn id;
    const char *name;
    int nargs;
    int ret_bits; /* 8 for a bool returned in AL, 32 otherwise, 0 for a void function (EAX is not compared) */
    uint32_t (*run)(Vm *vm, const uint32_t *args);
    int self_charging; /* 1: the function adds the instructions its original would have run to native_cost_extra itself, so the host does not charge a calibrated average per call */
} NativeInfo;

extern const NativeInfo NATIVE_FUNCTIONS[FN_COUNT];
const NativeInfo *native_find(const char *name);
const char *callee_name(Callee c);

#endif
