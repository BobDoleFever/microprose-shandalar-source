/*
 * Decompiled function: FUN_00457ea3
 * Entry Point: 00457ea3
 * Size: 313 bytes
 */
#include "duel.h"


undefined4 FUN_00457ea3(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int arg_2_00;
  int arg_3_00;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f330 + arg_1 * 0x20) = *(int *)(&DAT_0068f330 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    if ((*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0) &&
       (iVar1 = FUN_0049b309(arg_1,4,1), iVar1 != 0)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,4,1), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,4,1);
    }
    if ((arg_3 == 0x72) && (iVar1 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,arg_1,arg_2), iVar1 != -1)
       ) {
      *(undefined2 *)(&DAT_006826d8 + iVar1 * 0x120 + arg_1 * 0x5b20) = 1;
    }
    if (arg_3 == 0x39) {
      arg_3_00 = 1;
      arg_2_00 = 0;
      iVar1 = FUN_0049b309(arg_1,4,1);
      uVar2 = FUN_0049aa14(iVar1,arg_2_00,arg_3_00);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


