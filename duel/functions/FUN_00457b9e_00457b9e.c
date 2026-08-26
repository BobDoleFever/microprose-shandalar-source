/*
 * Decompiled function: FUN_00457b9e
 * Entry Point: 00457b9e
 * Size: 773 bytes
 */
#include "duel.h"


undefined4 FUN_00457b9e(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x6c) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0x20;
  }
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f330 + arg_1 * 0x20) = *(int *)(&DAT_0068f330 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    if ((*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) ||
       (iVar1 = FUN_0049b309(arg_1,4,1), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,4,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,4,1), DAT_00681ea4 != 1)) {
      *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
      *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      if (arg_1 == DAT_00676504) {
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        *(undefined4 *)
         (&DAT_006826e4 +
         *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0x20;
        iVar1 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,DAT_00690af0,DAT_0068efa0);
        if (iVar1 != -1) {
          *(undefined4 *)(&DAT_006826e4 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0x20;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


