/*
 * Decompiled function: Ai_Subsystem_004cc1e8
 * Entry Point: 004cc1e8
 * Size: 110 bytes
 */
#include "magic.h"


char * Ai_Subsystem_004cc1e8(int arg1,int arg2)

{
  char *pcVar1;
  
  if (*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
    pcVar1 = &DAT_0052e5c8;
  }
  else {
    pcVar1 = s_Swamp_0051aea9 + *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34;
  }
  return pcVar1;
}


