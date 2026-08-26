/*
 * Decompiled function: Minit_Subsystem_00458596
 * Entry Point: 00458596
 * Size: 322 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00458596(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,2);
    if ((iVar1 == 0) ||
       (((((&DAT_006a5f3e)[arg_1 * 0x5b20 + arg_2 * 0x120] & 3) != 0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34] & 2) != 0)) ||
        (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
    }
    if (arg_3 == 0x72) {
      FUN_0046f5d1(arg_1);
      Prompts_Load_0046fa40(arg_1,0,0);
      *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}


