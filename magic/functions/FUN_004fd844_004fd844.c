/*
 * Decompiled function: FUN_004fd844
 * Entry Point: 004fd844
 * Size: 380 bytes
 */
#include "magic.h"


undefined4 FUN_004fd844(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      if ((g_CurrentTurnPhase == arg_1) && (g_IsAiThinking != 1)) {
        local_8 = Pic_Load_004509e8(arg_1,(int)(&DAT_006ff710 + arg_1 * 2000),500,
                                    s_Pick_a_creature_00530914,1);
      }
      else {
        local_8 = FUN_004fd9c0(arg_1,2);
      }
      if (((local_8 != -1) && (*(int *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000) != -1)) &&
         (((&g_MasterCardColorTable)[*(int *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000) * 0x34] &
          2) != 0)) {
        iVar2 = Pic_Subsystem_00451291(arg_1,*(int *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000));
        if (iVar2 != -1) {
          *(undefined4 *)(&g_CardSlot_Flags + iVar2 * 0x120 + arg_1 * 0x5b20) = 0x30002;
        }
        *(undefined4 *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000) = 0xffffffff;
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


