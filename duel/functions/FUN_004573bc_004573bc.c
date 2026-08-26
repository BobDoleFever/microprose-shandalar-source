/*
 * Decompiled function: FUN_004573bc
 * Entry Point: 004573bc
 * Size: 1907 bytes
 */
#include "duel.h"


int FUN_004573bc(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int arg_2_00;
  int arg_3_00;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f330 + arg_1 * 0x20) = *(int *)(&DAT_0068f330 + arg_1 * 0x20) + 1;
  }
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    iVar2 = FUN_0049b309(arg_1,4,1);
  }
  else if (arg_3 == 0x90) {
    FUN_00430768(0);
    iVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = FUN_0049b309(arg_1,4,1), uVar1 = DAT_0068ed04, iVar2 != 0)) {
      DAT_00681ea0 = 0;
      if (arg_1 == DAT_00666458) {
        if (((arg_1 == DAT_00676504) ||
            ((*(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000) == 0x30000)) ||
           (DAT_0066643c != 1)) {
          DAT_0068ed04 = -1;
        }
        else {
          DAT_0068ed04 = 3 - ((*(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000)
                             >> 0x10);
        }
        Ai_CalcManaRequirement_004ba890(arg_1,4,-1);
        DAT_0068ed04 = uVar1;
        if (DAT_00681ea0 < 1) {
          DAT_00681ea4 = 1;
        }
      }
      else {
        Ai_CalcManaRequirement_004ba890(arg_1,4,1);
        DAT_00681ea0 = 1;
      }
      *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000;
      if (DAT_00681ea4 == 1) {
        *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      else {
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
            *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
          }
        }
      }
    }
    if (arg_3 == 0x39) {
      arg_3_00 = 3;
      arg_2_00 = 0;
      iVar2 = FUN_0049b309(arg_1,4,1);
      iVar2 = FUN_0049aa14(iVar2,arg_2_00,arg_3_00);
      iVar2 = iVar2 - *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    else {
      if (((((DAT_0068f230 == 0xcd) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
          ((arg_1 == DAT_0068ecb0 && ((&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0')))) &&
         (arg_1 == DAT_00681ec4)) {
        if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) < 4) {
          *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
          *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
        }
        else {
          if (arg_3 == 0x7d) {
            DAT_0066642c = DAT_0066642c | 2;
          }
          if ((arg_3 == 0x7e) || (arg_3 == 199)) {
            FUN_0046e571(arg_1,arg_2,2);
          }
        }
      }
      if (arg_3 == 199) {
        if (arg_1 == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ef60 + arg_1 * 0x20) * 0xc;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ef60 + arg_1 * 0x20) * -0xc;
        }
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}


