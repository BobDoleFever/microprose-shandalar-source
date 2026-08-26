/*
 * Decompiled function: FUN_00472f0c
 * Entry Point: 00472f0c
 * Size: 162 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00472f0c(undefined4 arg1,int arg2)

{
  char cVar1;
  int iVar2;
  
  DAT_0069f6d8 = 0xffffd8f1;
  g_IsAiThinking = 1;
  DAT_006808a8 = arg1;
  iVar2 = (DAT_0067f380 + 1) * arg2;
  DAT_006fe40c = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
  cVar1 = FUN_0040a1d2(5);
  _DAT_00679ed0 = 1 << (cVar1 + 1U & 0x1f);
  Ai_SaveGameState();
  Mem_AllocOrFree_005016f9();
  Timer_MarkStart();
  DAT_006b1580 = 0;
  DAT_006a2838 = 1;
  Pic_Subsystem_0044b8da();
  Mem_AllocOrFree_00512220(1,1,DAT_006784f0);
  Pic_Subsystem_0044b8aa();
  DAT_0067bdb0 = 0;
  return;
}


