/*
 * Decompiled function: FUN_00459f68
 * Entry Point: 00459f68
 * Size: 1665 bytes
 */
#include "duel.h"


undefined4 FUN_00459f68(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f324 + arg_1 * 0x20) = *(int *)(&DAT_0068f324 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    uVar1 = FUN_0049b309(arg_1,1,1);
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    uVar1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = FUN_0049b309(arg_1,1,1), iVar2 != 0)) {
      if (arg_1 == DAT_00666458) {
        Ai_CalcManaRequirement_004ba890(arg_1,1,-1);
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,1,1);
        *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      if (DAT_00681ea4 == 1) {
        *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      else {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
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
        *(uint *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (*(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff) * 0x100;
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
            *(undefined2 *)(&DAT_006826da + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      uVar1 = FUN_0049b309(arg_1,1,1);
    }
    else if (arg_3 == 0x3a) {
      uVar1 = FUN_0049b309(arg_1,1,1);
    }
    else {
      if ((arg_3 == 0x8f) && (*(int *)(&DAT_0068f2e4 + arg_1 * 0x20) != 0)) {
        DAT_0066642c = DAT_0066642c | 1;
      }
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


