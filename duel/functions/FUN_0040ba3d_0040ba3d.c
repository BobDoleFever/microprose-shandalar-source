/*
 * Decompiled function: FUN_0040ba3d
 * Entry Point: 0040ba3d
 * Size: 1030 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040ba3d(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if ((((DAT_0066aad4 | _DAT_0066aad0) & 2) == 0) ||
       (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0,
       ((&DAT_004ff594)
        [*(int *)(&DAT_006826c4 +
                 *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 0x34] & 0x40) !=
       0)) {
      DAT_00681ea4 = 1;
    }
    if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      if (((&DAT_004ff594)
           [*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 0x34] & 0x40)
          == 0) {
        iVar2 = FUN_004a2b00(arg_1,arg_2,DAT_0066aaec,
                             (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                             *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20));
        if (iVar2 != -1) {
          *(undefined2 *)(&DAT_006826d8 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
          *(undefined2 *)(&DAT_006826da + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
          *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x20;
        }
        iVar2 = FUN_004af68f(*(int *)(&DAT_006826c4 +
                                     *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) *
                                     0x120 + (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                             0x5b20));
        if (iVar2 != -1) {
          (&DAT_004ff594)[iVar2 * 0x34] = 0x42;
          *(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) = iVar2;
        }
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20];
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    if (arg_3 == 0x3b) {
      *(int *)(&DAT_00666730 + arg_1 * 4) = *(int *)(&DAT_00666730 + arg_1 * 4) + 1;
      *(int *)(&DAT_00666738 + arg_1 * 4) = *(int *)(&DAT_00666738 + arg_1 * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


