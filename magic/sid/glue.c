/*
 * sid/glue.c - Master Aggregator Module for Shandalar Engine Subsystems
 * Reconstructed MicroProse Source Architecture (Sid Meier & Ned Way, 1997)
 *
 * Subsystems contained:
 * 1. glue_timer.c        - High-Precision Hardware Timer & Profiling Clock
 * 2. glue_spell_chain.c  - Spell Resolution Stack & Spell Chain Window UI
 * 3. glue_card_scripts.c - Specific Card Rules Scripts & Activated/Triggered Abilities
 * 4. glue_card_queries.c - Permanent Queries, Iterators, Counter Manipulation & Targeting
 * 5. glue_adventure.c    - Shandalar Overworld Campaign, Town Dialogs & Audio Events
 * 6. glue_duel_ui.c      - Tactical Duel Combat Arena Window, Debug Cheats & Status Banners
 * 7. glue_bazaar.c       - Bazaar Card Trading Shop & Haar Wavelet Art Decompressor
 */

#include "glue_timer.c"
#include "glue_spell_chain.c"
#include "glue_card_scripts.c"
#include "glue_card_queries.c"
#include "glue_adventure.c"
#include "glue_duel_ui.c"
#include "glue_bazaar.c"
