/*
 * Decompiled function: Ai_Subsystem_004cc053
 * Entry Point: 004cc053
 * Size: 111 bytes
 */
#include "magic.h"


undefined1 Ai_Subsystem_004cc053(int arg1,int arg2)

{
  undefined1 uVar1;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = (&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34];
  }
  return uVar1;
}


