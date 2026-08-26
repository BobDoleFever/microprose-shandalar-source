/*
 * Decompiled function: Card_HurkylsRecall_PickArtifact
 * Entry Point: 004e4508
 * Size: 582 bytes
 */
#include "magic.h"


void Card_HurkylsRecall_PickArtifact(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if ((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) {
      FUN_0040d949(arg_1,5,2);
    }
  }
  else if (((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,5,2), iVar1 != 0)) &&
          (Ai_CalcManaRequirement_004ba890(arg_1,5,2), g_ActivePlayer != 1)) {
    if ((arg_1 == g_CurrentTurnPhase) && (g_IsAiThinking != 1)) {
      do {
        local_8 = Pic_Load_004509e8(arg_1,(int)(&DAT_006ff710 + arg_1 * 2000),500,
                                    s_Pick_an_artifact_0052ef90,0);
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
      iVar1 = Pic_Subsystem_00451291(arg_1,*(int *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000));
      if (iVar1 != -1) {
        *(undefined4 *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000) = 0xffffffff;
      }
    }
    if (g_ActivePlayer != 1) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
  }
  return;
}


