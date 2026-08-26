/*
 * Decompiled function: Ai_TownEncounter_004c3b19
 * Entry Point: 004c3b19
 * Size: 138 bytes
 */
#include "magic.h"


void Ai_TownEncounter_004c3b19(uint arg_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (int)arg_1 >> 0x1f;
  iVar1 = arg_1 + (uVar2 & 7);
  uVar3 = iVar1 >> 0x1f;
  strcat(&g_OverworldWorldState,
         (&PTR_s_Amanaxis_00522460)[((iVar1 >> 3 ^ uVar3) - uVar3 & 0xf ^ uVar3) - uVar3]);
  if (*(int *)(&DAT_0067bdf0 + arg_1 * 100) == 1) {
    strcat(&g_OverworldWorldState,s_Village_0052ddb0);
  }
  else {
    strcat(&g_OverworldWorldState,
           (&PTR_s_Tower_005224a0)[((arg_1 ^ uVar2) - uVar2 & 0xf ^ uVar2) - uVar2]);
  }
  return;
}


