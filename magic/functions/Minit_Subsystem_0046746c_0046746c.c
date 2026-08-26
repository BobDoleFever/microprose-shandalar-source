/*
 * Decompiled function: Minit_Subsystem_0046746c
 * Entry Point: 0046746c
 * Size: 288 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0046746c(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,3);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (Ai_CalcManaRequirement_004ba890(arg_1,0,3), g_ActivePlayer != 1)) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      Minit_Subsystem_0046758c();
    }
    uVar2 = 0;
  }
  return uVar2;
}


