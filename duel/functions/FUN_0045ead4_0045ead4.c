/*
 * Decompiled function: FUN_0045ead4
 * Entry Point: 0045ead4
 * Size: 753 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0045ead4(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (arg_1 == DAT_00676510) {
      if (((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
         (((DAT_0066aad4 | _DAT_0066aad0) & 2) != 0)) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else if (((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
            (((&DAT_0066aad0)[DAT_00676504 * 4] & 2) != 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      if (local_c == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
      }
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      iVar2 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,
                           (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                           *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20));
      if (iVar2 != -1) {
        *(undefined2 *)(&DAT_006826d8 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
        *(undefined2 *)(&DAT_006826da + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if ((arg_3 == 0x3b) &&
       ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20014) == 0)) {
      *(int *)(&DAT_00666730 + arg_1 * 4) = *(int *)(&DAT_00666730 + arg_1 * 4) + 1;
      *(int *)(&DAT_00666738 + arg_1 * 4) = *(int *)(&DAT_00666738 + arg_1 * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


