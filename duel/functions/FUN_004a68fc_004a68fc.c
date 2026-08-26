/*
 * Decompiled function: FUN_004a68fc
 * Entry Point: 004a68fc
 * Size: 723 bytes
 */
#include "duel.h"


undefined4 FUN_004a68fc(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x74) {
    FUN_0043071d(0);
    if (DAT_0068ecd0 == -1) {
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
      if ((((&DAT_004ff594)
            [*(int *)(&DAT_006826c4 + DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20) * 0x34] & 0x18)
           == 0) ||
         (iVar1 = Rules_ParseFilter_0041c0ab
                            (DAT_0068ecd0,DAT_0068eccc,(undefined1 *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,
                             -1,0xffffffff,0xffffffff,2,0,0), iVar1 == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if (DAT_0068ecd0 == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068ecd0;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068eccc;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
    }
    if (arg_3 == 0x71) {
      iVar1 = Pic_Subsystem_00451291
                        (arg_1,*(int *)(&DAT_006826c4 +
                                       *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                       0x5b20 + *(int *)(&DAT_0068271c +
                                                        arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120));
      if (iVar1 != -1) {
        (&DAT_006826dd)[iVar1 * 0x120 + arg_1 * 0x5b20] = 0x10;
        *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) | 8;
        DAT_00681ea0 = *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
        DAT_00681eb0 = DAT_00681eb0 | 0x400;
        Pic_Subsystem_0042ac1f(arg_1,iVar1);
        DAT_00681eb0 = DAT_00681eb0 & 0xfffffbff;
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


