/*
 * shandalar/cards.h - Card Database, Attributes, and Rules Engine
 * MicroProse Magic: The Gathering (Shandalar 1997)
 * Comments follow Simplified Technical English (ASD-STE100) rules.
 */
#ifndef SHANDALAR_CARDS_H
#define SHANDALAR_CARDS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * MTG Card Colors
 */
typedef enum CardColor {
    COLOR_COLORLESS = 0x00,
    COLOR_WHITE     = 0x01,
    COLOR_BLUE      = 0x02,
    COLOR_BLACK     = 0x04,
    COLOR_RED       = 0x08,
    COLOR_GREEN     = 0x10,
    COLOR_ARTIFACT  = 0x20,
    COLOR_LAND      = 0x40
} CardColor;

/*
 * MTG Card Script Event Codes
 * Passed to card script action callbacks (**(code **)(&g_CardScriptCallbackTable + card_id * 0x34))
 */
typedef enum CardEventCode {
    EVENT_CAN_CAST           = 0x01, /* Query whether card can legally be cast */
    EVENT_CAST_SPELL         = 0x02, /* Execute spell cast action / put on stack */
    EVENT_UPKEEP             = 0x03, /* Upkeep phase trigger */
    EVENT_DRAW               = 0x04, /* Draw phase trigger */
    EVENT_DECLARE_ATTACKERS  = 0x05, /* Attacker declaration step */
    EVENT_DECLARE_BLOCKERS   = 0x06, /* Blocker declaration step */
    EVENT_DEAL_DAMAGE        = 0x07, /* Combat damage assignment step */
    EVENT_END_OF_TURN        = 0x08, /* End of turn phase trigger */
    EVENT_CLEANUP            = 0x09, /* Cleanup phase trigger */
    EVENT_TAP_CARD           = 0x0A, /* Card is being tapped */
    EVENT_UNTAP_CARD         = 0x0B, /* Card is being untapped */
    EVENT_CONTINUOUS_EFFECT  = 0x14, /* Re-evaluate continuous modifiers */
    EVENT_RESOLVE_SPELL      = 0x15, /* Spell effect resolves from stack */
    EVENT_TRIGGER_ABILITY    = 0x20  /* Activated ability triggered */
} CardEventCode;

/*
 * Master Card Catalog Record Structure (Size: 0x34 = 52 bytes)
 */
typedef struct MasterCardRecord {
    char        name[32];             /* 0x00: Card name string */
    uint8_t     color;                /* 0x20: Primary color mask (CardColor) */
    uint8_t     type;                 /* 0x21: Primary card type (Creature, Instant, etc.) */
    uint8_t     subtype;              /* 0x22: Creature subtype / spell subtype */
    uint8_t     rarity;               /* 0x23: Common, Uncommon, Rare */
    uint16_t    mana_cost_colorless;  /* 0x24: Generic mana requirement */
    uint8_t     mana_cost_white;      /* 0x26: White mana required */
    uint8_t     mana_cost_blue;       /* 0x27: Blue mana required */
    uint8_t     mana_cost_black;      /* 0x28: Black mana required */
    uint8_t     mana_cost_red;        /* 0x29: Red mana required */
    uint8_t     mana_cost_green;      /* 0x2A: Green mana required */
    uint8_t     power;                /* 0x2B: Base creature power */
    uint8_t     toughness;            /* 0x2C: Base creature toughness */
    uint8_t     expansion_set;        /* 0x2D: Set code (Arabian Nights, Antiquities, etc.) */
    uint16_t    rules_flags;          /* 0x2E: Special rules bitflags */
    void*       script_callback;      /* 0x30: Function pointer to card rules handler */
} MasterCardRecord;

/*
 * Active Battlefield Card Slot Layout (Size: 0x120 = 288 bytes)
 * Player 0: 0x0000..0x5B1F (80 slots)
 * Player 1: 0x5B20..0xB63F (80 slots)
 */
#define MAX_PLAYERS              2
#define MAX_CARD_SLOTS_PER_PLAYER 80
#define CARD_SLOT_STRIDE         0x120
#define PLAYER_SLOT_STRIDE       0x5B20

#define CARD_SLOT_INDEX(player, slot) ((player) * PLAYER_SLOT_STRIDE + (slot) * CARD_SLOT_STRIDE)

/*
 * Helper Accessors for Card Slot Fields
 */
#define GET_SLOT_CARD_ID(p, s)      (*(int32_t *)((uint8_t *)&g_CardSlot_CardId + CARD_SLOT_INDEX(p, s)))
#define GET_SLOT_CONTROLLER(p, s)   (*(int32_t *)((uint8_t *)&g_CardSlot_Controller + CARD_SLOT_INDEX(p, s)))
#define GET_SLOT_FLAGS(p, s)        (*(int32_t *)((uint8_t *)&g_CardSlot_Flags + CARD_SLOT_INDEX(p, s)))
#define GET_SLOT_POWER(p, s)        (*(int16_t *)((uint8_t *)&g_CardSlot_Power + CARD_SLOT_INDEX(p, s)))
#define GET_SLOT_TOUGHNESS(p, s)    (*(int16_t *)((uint8_t *)&g_CardSlot_Toughness + CARD_SLOT_INDEX(p, s)))
#define GET_SLOT_DAMAGE(p, s)       (*(int16_t *)((uint8_t *)&g_CardSlot_DamageReceived + CARD_SLOT_INDEX(p, s)))
#define GET_SLOT_COUNTERS(p, s)     (*(int32_t *)((uint8_t *)&g_CardSlot_Counters + CARD_SLOT_INDEX(p, s)))
#define GET_SLOT_TARGET_SLOT(p, s)  (*(int32_t *)((uint8_t *)&g_CardSlot_TargetSlot + CARD_SLOT_INDEX(p, s)))
#define GET_SLOT_TAP_STATE(p, s)    (*(int32_t *)((uint8_t *)&g_CardSlot_TapState + CARD_SLOT_INDEX(p, s)))

/* Card Rules & Filters */
int  Rules_ParseFilter(const char* filter_expr, void* out_filter);
int  Action_PromptTarget(int spell_id, int target_type);
int  Action_ValidateTarget(int spell_id, int target_id);
int  Deck_FilterAttributes(int card_id, uint32_t color_mask);
int  Catalog_GetCardInfo(int card_index, void* out_card_struct);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_CARDS_H */
