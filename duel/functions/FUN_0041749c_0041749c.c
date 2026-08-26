/*
 * Decompiled function: FUN_0041749c
 * Entry Point: 0041749c
 * Size: 1032 bytes
 */
#include "duel.h"


int FUN_0041749c(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,2);
  }
  else if (arg_3 == 0x90) {
    DAT_00666410 = 2;
    iVar1 = 0;
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,2), iVar1 != 0)) &&
       ((Ai_CalcManaRequirement_004ba890(arg_1,0,2), DAT_00681ea4 != 1 &&
        (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)))) {
      *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_006826e4 +
                *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) + 1;
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
          iVar1 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (iVar1 != -1) {
            *(undefined2 *)(&DAT_006826d8 + iVar1 * 0x120 + arg_1 * 0x5b20) = 1;
            *(uint *)(&DAT_006826e4 + iVar1 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      iVar1 = *(int *)(&DAT_0068ed2c + arg_1 * 0x20) / 2;
    }
    else {
      if ((arg_3 == 0x8f) && (1 < *(int *)(&DAT_0068f2fc + arg_1 * 0x20))) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (arg_3 == 199) {
        if (arg_1 == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + ((*(int *)(&DAT_0068ef6c + arg_1 * 0x20) / 2) * 3 + 3) * 4;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + ((*(int *)(&DAT_0068ef6c + arg_1 * 0x20) / 2) * 3 + 3) * -4;
        }
      }
      if ((arg_3 == 0x22) || (arg_3 == 199)) {
        *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}


