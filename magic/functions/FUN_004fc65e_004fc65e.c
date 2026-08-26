/*
 * Decompiled function: FUN_004fc65e
 * Entry Point: 004fc65e
 * Size: 576 bytes
 */
#include "magic.h"


undefined4 FUN_004fc65e(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if ((arg_1 == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
        do {
          local_8 = Pic_Load_004509e8(arg_1,(int)(&DAT_006ff710 + arg_1 * 2000),500,
                                      s_Pick_an_artifact_00530648,1);
          if (local_8 == -1) break;
        } while (((&g_MasterCardColorTable)
                  [*(int *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000) * 0x34] & 0x40) == 0);
      }
      else {
        local_8 = FUN_004fd9c0(arg_1,0x40);
      }
      if (((local_8 == -1) || (*(int *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000) == -1)) ||
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000) * 0x34] &
          0x40) == 0)) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120) = local_8;
      }
    }
    if (arg_3 == 0x71) {
      iVar1 = *(int *)(&g_CardSlot_ConvertedManaCost + arg_1 * 0x5b20 + arg_2 * 0x120);
      if ((iVar1 != -1) &&
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + iVar1 * 4 + arg_1 * 2000) * 0x34] &
          0x40) != 0)) {
        Pic_Subsystem_00451291(arg_1,*(int *)(&DAT_006ff710 + iVar1 * 4 + arg_1 * 2000));
        *(undefined4 *)(&DAT_006ff710 + iVar1 * 4 + arg_1 * 2000) = 0xffffffff;
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


