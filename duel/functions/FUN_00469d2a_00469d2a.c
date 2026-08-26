/*
 * Decompiled function: FUN_00469d2a
 * Entry Point: 00469d2a
 * Size: 487 bytes
 */
#include "duel.h"


undefined4 FUN_00469d2a(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_504 [320];
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,3,2);
    if ((iVar1 == 0) || (iVar1 = FUN_0049b309(arg_1,7,3), iVar1 == 0)) {
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
    if (arg_3 == 0x6d) {
      DAT_0068ece0 = 1;
      Ai_CalcManaRequirement_004ba890(arg_1,3,2);
      if (DAT_00681ea4 != 1) {
        uVar2 = FUN_00439892(0x14);
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = uVar2;
        iVar1 = FUN_004699cd(arg_1,arg_2,(int)local_504);
        iVar1 = FUN_00439892(iVar1);
        *(undefined4 *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_504[iVar1 * 2];
        *(undefined4 *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = local_504[iVar1 * 2 + 1];
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
    }
    if ((arg_3 == 0x72) && ((&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0')) {
      Palette_Subsystem_004a8111
                (arg_1,arg_2,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
    }
    uVar2 = 0;
  }
  return uVar2;
}


