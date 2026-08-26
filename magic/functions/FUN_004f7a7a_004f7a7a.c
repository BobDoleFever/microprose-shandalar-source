/*
 * Decompiled function: FUN_004f7a7a
 * Entry Point: 004f7a7a
 * Size: 380 bytes
 */
#include "magic.h"


undefined4 FUN_004f7a7a(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (arg_1 == g_OverworldPlayerCoordX)) {
      if ((arg_1 == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
        Ai_Subsystem_004cd198();
        iVar2 = Ai_Subsystem_004cc814
                          (arg_1,s_Darkpact__Swap_ante_005303cc,0,s_Swap_my_ante_005303bc,
                           s_Swap_opponent_s_ante_005303a4,(char *)0x0);
        if (iVar2 == 0) {
          local_c = arg_1;
        }
        else {
          local_c = 1 - arg_1;
        }
      }
      else {
        local_c = arg_1;
      }
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
    }
    if (arg_3 == 0x71) {
      if (*(int *)(&DAT_0069e730 + arg_1 * 2000) != -1) {
        uVar1 = (&DAT_006b2d90)
                [*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x10];
        (&DAT_006b2d90)
        [*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x10] =
             *(undefined4 *)(&DAT_0069e730 + arg_1 * 2000);
        *(undefined4 *)(&DAT_0069e730 + arg_1 * 2000) = uVar1;
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


