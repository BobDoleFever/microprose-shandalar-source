/*
 * Decompiled function: FUN_00415450
 * Entry Point: 00415450
 * Size: 824 bytes
 */
#include "duel.h"


undefined4 FUN_00415450(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (arg_3 == 0x73) {
    if (((((byte)DAT_00681eb0 & 4) == 0) || (iVar1 = FUN_0049b309(arg_1,7,2), iVar1 == 0)) ||
       (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
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
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,2), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,2);
      if ((local_8 == -1) ||
         (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) != DAT_0068f104
         )) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
    }
    if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      if (*(int *)(&DAT_006826e4 +
                  *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) != 0) {
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) + -1;
      }
      *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if ((arg_3 == 0x22) && (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0)) {
      Pic_Subsystem_0044895f(arg_1,arg_2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


