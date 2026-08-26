/*
 * Decompiled function: Ai_Subsystem_004cc2cc
 * Entry Point: 004cc2cc
 * Size: 108 bytes
 */
#include "magic.h"


int Ai_Subsystem_004cc2cc(int arg1,int arg2)

{
  int iVar1;
  
  if (*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)(char)(&DAT_0051aec0)
                       [*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + arg2 * 0x120) * 0x34];
  }
  return iVar1;
}


