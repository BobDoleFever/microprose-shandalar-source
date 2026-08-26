/*
 * Decompiled function: Minit_Subsystem_004586d8
 * Entry Point: 004586d8
 * Size: 445 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004586d8(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0) ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      Pic_Subsystem_0044867e(arg_1,arg_2,4);
    }
    if (arg_3 == 0x72) {
      for (local_8 = 0; local_8 < 500; local_8 = local_8 + 1) {
        if (*(int *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000) != -1) {
          Pic_Subsystem_0045245e(arg_1,*(undefined4 *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000));
          *(undefined4 *)(&DAT_006ff710 + local_8 * 4 + arg_1 * 2000) = 0xffffffff;
        }
      }
      Ai_Subsystem_004cc9c5(0,0x30);
      Pic_Subsystem_00452276(arg_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


