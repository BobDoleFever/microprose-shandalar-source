/*
 * Decompiled function: FUN_004583e0
 * Entry Point: 004583e0
 * Size: 319 bytes
 */
#include "duel.h"


undefined4 FUN_004583e0(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f330 + arg_1 * 0x20) = *(int *)(&DAT_0068f330 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    uVar1 = FUN_0049b309(arg_1,4,1);
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_0049b309(arg_1,4,1);
      if (iVar2 != 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,4,1);
        if (DAT_00681ea4 != 1) {
          *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
        }
      }
    }
    if (arg_3 == 0x72) {
      iVar2 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,arg_1,arg_2);
      if (iVar2 != -1) {
        *(short *)(&DAT_006826da + iVar2 * 0x120 + arg_1 * 0x5b20) =
             (short)*(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
    }
    if (arg_3 == 0x3a) {
      uVar1 = FUN_0049b309(arg_1,4,1);
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


