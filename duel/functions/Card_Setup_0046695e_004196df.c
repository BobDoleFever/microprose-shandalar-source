/*
 * Decompiled function: Card_Setup_0046695e
 * Entry Point: 004196df
 * Size: 349 bytes
 */
#include "duel.h"


undefined4 Card_Setup_0046695e(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + 0xc;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,1);
    if ((iVar1 == 0) || (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,1), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Tap_which_card__004f2c00);
      if (local_8 != -1) {
        *(uint *)(&DAT_006826cc + local_8 * 0x120 + DAT_0068eef0 * 0x5b20) =
             *(uint *)(&DAT_006826cc + local_8 * 0x120 + DAT_0068eef0 * 0x5b20) | 0x10;
        FUN_0048c50b(DAT_0068eef0,local_8,0x7c);
      }
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}


