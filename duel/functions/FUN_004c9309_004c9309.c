/*
 * Decompiled function: FUN_004c9309
 * Entry Point: 004c9309
 * Size: 2656 bytes
 */
#include "duel.h"


undefined4 FUN_004c9309(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 1) {
    *(int *)(&DAT_0068f334 + param_1 * 0x20) = *(int *)(&DAT_0068f334 + param_1 * 0x20) + 1;
  }
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
           *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20);
      FUN_00434660(s_prompts_txt_00508c08,s_BLESSING_00508bfc);
      iVar2 = FUN_00468130(param_1,param_1,param_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        FUN_0046e571(param_1,param_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] =
             (&DAT_00682718)[param_2 * 0x120 + param_1 * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if (param_3 == 0x73) {
      uVar1 = FUN_0049b68d(param_1,param_2,5,1);
    }
    else if (param_3 == 0x90) {
      if (DAT_00666458 == param_1) {
        iVar2 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
        if (*(int *)(&DAT_00676150 + iVar2 * 4) == 0) {
          FUN_00430768(0);
        }
        else {
          DAT_00666410 = 1;
        }
      }
      else {
        DAT_00666410 = 1;
      }
      DAT_0068f0bc = (int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] << 8 |
                     *(uint *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = 0;
    }
    else {
      if ((param_3 == 0x6d) && (iVar2 = FUN_0049b68d(param_1,param_2,5,1), iVar2 != 0)) {
        if (DAT_00666458 == param_1) {
          iVar2 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
          if (*(int *)(&DAT_00676150 + iVar2 * 4) == 0) {
            FUN_0042b6b0(param_1,5,0xffffffff);
          }
          else {
            DAT_00681ea0 = FUN_0042ecaf(param_1,param_2,5,1);
          }
          if (DAT_00681ea0 < 1) {
            DAT_00681ea4 = 1;
          }
          else {
            *(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00681ea0;
          }
        }
        else {
          iVar2 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
          if (*(int *)(&DAT_00676150 + iVar2 * 4) == 0) {
            FUN_0042b6b0(param_1,5,1);
          }
          else {
            FUN_0042ecaf(param_1,param_2,5,1);
          }
          *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 1;
        }
        if (DAT_00681ea4 == 1) {
          *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
        }
        else {
          *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) =
               (int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20];
          *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) =
               *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20);
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
          if (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0) {
            *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) | 0x80000;
          }
        }
      }
      if (param_3 == 0x72) {
        if (*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(uint *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) =
               *(int *)(&DAT_006826e4 +
                       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) +
               (*(uint *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) & 0xff);
          *(uint *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) =
               *(int *)(&DAT_006826e4 +
                       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) +
               (*(uint *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) & 0xff) * 0x100;
          (&DAT_006827b8)
          [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
           *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
          if (((&DAT_006826e6)
               [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] & 8) != 0) {
            *(uint *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) =
                 *(uint *)(&DAT_006826e4 +
                          *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                          *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) &
                 0xfff7ffff;
            iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,
                                 (int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                                 *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20)
                                );
            if (iVar2 != -1) {
              *(short *)(&DAT_006826d8 + iVar2 * 0x120 + param_1 * 0x5b20) =
                   (short)*(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20);
              *(short *)(&DAT_006826da + iVar2 * 0x120 + param_1 * 0x5b20) =
                   (short)*(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20);
              *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + param_1 * 0x5b20) =
                   *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + param_1 * 0x5b20) | 0x80000;
            }
          }
        }
      }
      if (param_3 == 199) {
        if (DAT_00676504 == param_1) {
          DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ef64 + param_1 * 0x20) * 3 + 6) * 4;
        }
        else {
          DAT_0068f2d4 = DAT_0068f2d4 + (*(int *)(&DAT_0068ef64 + param_1 * 0x20) * 3 + 6) * -4;
        }
      }
      if ((param_3 == 0x22) || (param_3 == 199)) {
        *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


