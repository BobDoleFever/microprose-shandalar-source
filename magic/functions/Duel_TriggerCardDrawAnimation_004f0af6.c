/*
 * Decompiled function: Duel_TriggerCardDrawAnimation
 * Entry Point: 004f0af6
 * Size: 90 bytes
 */
#include "magic.h"


void Duel_TriggerCardDrawAnimation(void)

{
  int iVar1;
  uint local_8;
  
  for (local_8 = 0; (int)local_8 < g_MasterCardCount; local_8 = local_8 + 1) {
    while( true ) {
      iVar1 = Duel_UpdateCardMotionStep(local_8);
      if (-1 < iVar1) break;
      *(uint *)(&deck + DAT_00565a08 * 4) = *(uint *)(&deck + DAT_00565a08 * 4) | 0x4000;
    }
  }
  return;
}


