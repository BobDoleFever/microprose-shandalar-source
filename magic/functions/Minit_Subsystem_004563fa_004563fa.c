/*
 * Decompiled function: Minit_Subsystem_004563fa
 * Entry Point: 004563fa
 * Size: 339 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_004563fa(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  if (arg_3 == 1) {
    uVar1 = Minit_Subsystem_004528c0(arg_1,arg_2,1,0);
  }
  else if (arg_3 == 0x73) {
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
      FUN_0040d875(arg_1,0,1);
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      DAT_006ff2d4 = 0;
      DAT_00679ecc = 0;
      CardQuery_ForEachPermanent(Minit_Subsystem_00456552,arg_1);
      if (DAT_00679ecc == 7) {
        FUN_0040d875(arg_1,0,1);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


