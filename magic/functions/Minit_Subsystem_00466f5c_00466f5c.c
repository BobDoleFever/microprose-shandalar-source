/*
 * Decompiled function: Minit_Subsystem_00466f5c
 * Entry Point: 00466f5c
 * Size: 320 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00466f5c(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0040d949(arg_1,7,1);
    if ((iVar1 == 0) || (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,7,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,0,1), g_ActivePlayer != 1)) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar1 = FUN_00471c32(local_8,local_c);
          if ((iVar1 != 0) && (iVar1 = FUN_0040a1d2(3), iVar1 == 0)) {
            Pic_Subsystem_0044867e(local_8,local_c,2);
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


