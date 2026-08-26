/*
 * Decompiled function: Ai_Subsystem_004cc127
 * Entry Point: 004cc127
 * Size: 92 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004cc127(int arg1,int arg2)

{
  undefined4 uVar1;
  
  if (*(int *)(&g_CardSlot_Abilities2 + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(&g_CardSlot_Abilities2 + arg2 * 0x120 + arg1 * 0x5b20);
  }
  return uVar1;
}


