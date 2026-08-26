/*
 * Decompiled function: Ai_Subsystem_004cc25b
 * Entry Point: 004cc25b
 * Size: 108 bytes
 */
#include "magic.h"


int Ai_Subsystem_004cc25b(int arg1,int arg2)

{
  int iVar1;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)(char)(&DAT_0051aebf)
                       [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34];
  }
  return iVar1;
}


