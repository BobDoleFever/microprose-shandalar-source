/*
 * Decompiled function: FUN_004fd11b
 * Entry Point: 004fd11b
 * Size: 692 bytes
 */
#include "magic.h"


undefined4 FUN_004fd11b(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  char cVar2;
  int arg2;
  undefined4 uVar3;
  int iVar4;
  int local_1c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      if ((g_CurrentTurnPhase == arg_1) && (g_IsAiThinking != 1)) {
        local_8 = Pic_Load_004509e8(arg_1,(int)(&DAT_0069e730 + arg_1 * 2000),500,
                                    s_Pick_an_artifact_005306fc,1);
      }
      else {
        local_8 = FUN_004fdad2(arg_1,arg_1,0x40);
      }
      if ((local_8 == -1) || (*(int *)(&DAT_0069e730 + local_8 * 4 + arg_1 * 2000) == -1)) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
      }
    }
    if (arg_3 == 0x71) {
      iVar4 = *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      if ((*(int *)(&DAT_0069e730 + iVar4 * 4 + arg_1 * 2000) != -1) &&
         (arg2 = *(int *)(&DAT_0069e730 + iVar4 * 4 + arg_1 * 2000),
         ((&g_MasterCardColorTable)[arg2 * 0x34] & 0x40) != 0)) {
        Pic_Subsystem_004523fd(arg_1,iVar4);
        if (local_1c != -1) {
          iVar4 = *(int *)(&g_CardSlot_CardId + local_1c * 0x120 + arg_1 * 0x5b20);
          Pic_Subsystem_0044867e(arg_1,local_1c,2);
          cVar1 = (&DAT_0051aec0)[arg2 * 0x34];
          cVar2 = (&DAT_0051aec0)[iVar4 * 0x34];
          while (0 < (int)cVar1 - (int)cVar2) {
            iVar4 = FUN_0040d949(arg_1,7,1);
            if (iVar4 == 0) break;
            Ai_CalcManaRequirement_004ba890(arg_1,0,1);
          }
          if ((int)cVar1 - (int)cVar2 < 1) {
            iVar4 = Pic_Subsystem_00451291(arg_1,arg2);
            if (iVar4 != -1) {
              *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + iVar4 * 0x120) =
                   *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + iVar4 * 0x120) | 0x30002;
            }
          }
        }
      }
      Pic_Subsystem_00452276(arg_1);
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


