/*
 * Decompiled function: Minit_Subsystem_004545c7
 * Entry Point: 004545c7
 * Size: 310 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004545c7(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if ((((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      FUN_0046f5d1(arg_1);
      FUN_0046f5d1(arg_1);
      for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
        if (0 < (int)(&DAT_006b3008)[arg_1]) {
          Prompts_Load_0046fa40(arg_1,0,0);
        }
      }
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar1 = 0;
  }
  return uVar1;
}


