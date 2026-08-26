/*
 * Decompiled function: FUN_004ac2b1
 * Entry Point: 004ac2b1
 * Size: 695 bytes
 */
#include "duel.h"


undefined4 FUN_004ac2b1(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x74) {
    FUN_0043071d(0);
    if (DAT_0068ecd0 == -1) {
      uVar2 = 0;
    }
    else {
      iVar1 = Rules_ParseFilter_0041c0ab
                        (DAT_0068ecd0,DAT_0068eccc,(undefined1 *)0x0,arg_1,2,2,0,0,0,0,0,0,0,-1,-1,
                         0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 99;
      }
    }
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if ((arg_1 == DAT_00676510) || (DAT_0068ecd0 != -1)) {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068ecd0;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068eccc;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
      else {
        DAT_00681ea4 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + -0x24;
    }
    if ((arg_3 == 0x38) && (1 < *(int *)(&DAT_0068ed18 + arg_1 * 0x20))) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
    }
    if (arg_3 == 0x71) {
      iVar1 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),(undefined1 *)0x0,
                         arg_1,2,2,0,0,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,2,0,0);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else if (((&DAT_006826cc)
                [*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 0x20) != 0) {
        FUN_0046e571(*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                     *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),1);
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


