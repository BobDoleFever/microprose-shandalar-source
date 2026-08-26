/*
 * Decompiled function: DeckBuilder_InitSubsystems
 * Entry Point: 0040161a
 * Size: 24 bytes
 */
#include "deck.h"


void DeckBuilder_InitSubsystems(void)

{
  int32_t reg_eax;
  int frame_base;
  
  DAT_00412ac4 = *(int32_t *)(frame_base + 8);
  DAT_00412ac0 = reg_eax;
  DAT_00412ac8 = frame_base;
  return;
}


