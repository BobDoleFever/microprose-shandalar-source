/*
 * Decompiled function: FUN_00411f98
 * Entry Point: 00411f98
 * Size: 435 bytes
 */
#include "magic.h"


undefined4 FUN_00411f98(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    uVar1 = FUN_0040d949(arg_1,7,1);
  }
  else {
    if (((arg_3 == 0x6d) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      iVar2 = FUN_0040d949(arg_1,7,1);
      if (iVar2 != 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      }
    }
    if (arg_3 == 0x72) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,4);
    }
    if ((((g_PlayerManaPool == 0xce) || (arg_3 == 199)) &&
        ((g_OverworldMapGrid == arg_2 &&
         ((g_OverworldPlayerCoordX == arg_1 && (g_DefendingPlayer == arg_1)))))) &&
       (arg_1 == DAT_006a4b5c)) {
      if (arg_3 == 0x7d) {
        g_ActivePalette = g_ActivePalette | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Naf_s_Asp_takes_1_life__005196ac,0);
        Mem_AllocOrFree_0041df33(arg_1,1,arg_1,arg_2);
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      if (g_IsAiThinking == 1) {
        Mem_AllocOrFree_0041df33(arg_1,1,arg_1,arg_2);
      }
      *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


