/*
 * Decompiled function: FUN_00459918
 * Entry Point: 00459918
 * Size: 1616 bytes
 */
#include "duel.h"


undefined4 FUN_00459918(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f324 + arg_1 * 0x20) = *(int *)(&DAT_0068f324 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    if (((DAT_00676504 == arg_1) && (DAT_00666458 == arg_1)) &&
       ((*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) != 0 && (DAT_0068f2c4 < 0x1a)))) {
      uVar1 = 0;
    }
    else {
      iVar2 = FUN_0049b309(arg_1,1,1);
      if ((iVar2 == 0) ||
         (0x1ffff < (int)(*(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffff0000)))
      {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    uVar1 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && (iVar2 = FUN_0049b309(arg_1,1,1), uVar1 = DAT_0068ed04, iVar2 != 0)) &&
       ((int)(*(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xffff0000) < 0x20000)) {
      if (((&DAT_006826f2)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0xf) == 0) {
        DAT_0068ed04 = 2;
      }
      else {
        DAT_0068ed04 = 1;
      }
      if (DAT_00666458 == arg_1) {
        Ai_CalcManaRequirement_004ba890(arg_1,1,-1);
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,1,1);
        DAT_00681ea0 = 1;
      }
      DAT_0068ed04 = uVar1;
      *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xf0000;
      if (DAT_00681ea4 != 1) {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
        *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) + DAT_00681ea0 * 0x10001;
        if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
          *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(uint *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff);
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0) {
          *(uint *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (iVar2 != -1) {
            *(undefined2 *)(&DAT_006826d8 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uVar1 = FUN_0049aa14(*(int *)(&DAT_0068ed14 + arg_1 * 0x20),0,
                           2 - *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20));
    }
    else {
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


