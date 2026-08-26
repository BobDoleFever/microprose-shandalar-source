/*
 * Decompiled function: FUN_00419061
 * Entry Point: 00419061
 * Size: 607 bytes
 */
#include "duel.h"


undefined4 FUN_00419061(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) &&
        (iVar1 = FUN_0049b309(arg_1,7,3), iVar1 != 0)) &&
       (((*(uint *)(&DAT_0066aad0 + (1 - arg_1) * 4) | *(uint *)(&DAT_0066aad0 + DAT_00676510 * 4))
        & 2) != 0)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0)) &&
       (iVar1 = FUN_0049b309(arg_1,7,3), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,3);
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      if (local_c == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
      }
    }
    if (((arg_3 == 0x72) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) &&
       (iVar1 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,
                             (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                             *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20)), iVar1 != -1)
       ) {
      *(undefined2 *)(&DAT_006826d8 + iVar1 * 0x120 + arg_1 * 0x5b20) = 0xfffe;
      *(undefined2 *)(&DAT_006826da + iVar1 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


