/*
 * Decompiled function: FUN_0047bba3
 * Entry Point: 0047bba3
 * Size: 495 bytes
 */
#include "duel.h"


undefined4 FUN_0047bba3(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
       ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) == 0 ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0
        )))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_00468130(arg_1,arg_1,arg_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) == arg_1) {
          iVar2 = FUN_0048b81a(*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                               *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),0x33,
                               0xffffffff);
          (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + iVar2;
          FUN_0046e571(*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                       *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),3);
        }
        *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


