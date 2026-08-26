/*
 * Decompiled function: FUN_004fc023
 * Entry Point: 004fc023
 * Size: 706 bytes
 */
#include "magic.h"


undefined4 FUN_004fc023(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  uint local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if ((g_CurrentTurnPhase == arg_1) && (g_IsAiThinking != 1)) {
        iVar2 = Ai_Subsystem_004cc814
                          (arg_1,s_Drafna_s_Restoration__005305f4,0,s_My_graveyard_005305e4,
                           s_Opponent_s_graveyard_005305cc,(char *)0x0);
        if (iVar2 == 0) {
          local_c = arg_1;
        }
        else {
          local_c = 1 - arg_1;
        }
        local_8 = Pic_Load_004509e8(arg_1,(int)(&DAT_006ff710 + local_c * 2000),500,
                                    s_Pick_an_artifact_00530610,1);
        if ((local_8 != 0xffffffff) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&DAT_006ff710 + local_8 * 4 + local_c * 2000) * 0x34] & 0x40) == 0)) {
          local_8 = 0xffffffff;
        }
      }
      else {
        local_c = arg_1;
        local_8 = FUN_004fd9c0(arg_1,0x40);
      }
      if (((local_8 == 0xffffffff) || (*(int *)(&DAT_006ff710 + local_8 * 4 + local_c * 2000) == -1)
          ) || (((&g_MasterCardColorTable)
                 [*(int *)(&DAT_006ff710 + local_8 * 4 + local_c * 2000) * 0x34] & 0x40) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             local_c << 8 | local_8;
      }
    }
    if (arg_3 == 0x71) {
      iVar2 = *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      if (((iVar2 != -1) && (*(int *)(&DAT_006ff710 + iVar2 * 4 + local_c * 2000) != -1)) &&
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + iVar2 * 4 + local_c * 2000) * 0x34] &
          0x40) != 0)) {
        Pic_Subsystem_004524db(local_c,*(undefined4 *)(&DAT_006ff710 + iVar2 * 4 + local_c * 2000));
        *(undefined4 *)(&DAT_006ff710 + iVar2 * 4 + local_c * 2000) = 0xffffffff;
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


