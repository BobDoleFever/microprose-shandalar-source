/*
 * Decompiled function: FUN_004cd134
 * Entry Point: 004cd134
 * Size: 2364 bytes
 */
#include "duel.h"


undefined4 FUN_004cd134(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508d38,s_INSTILL_ENERGY_00508d28);
      iVar2 = FUN_00468130(param_1,param_1,param_2);
      DAT_00681ea4 = (uint)(iVar2 == 0);
      if ((DAT_00681ea4 != 1) && (DAT_00676504 == param_1)) {
        if (((&DAT_004ff595)
             [*(int *)(&DAT_006826c4 +
                      *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                      *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) * 0x34]
             == '\0') &&
           (((&DAT_006826f9)
             [*(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
              *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] & 8) == 0)) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x30;
        }
        if ((((&DAT_004ff5a8)
              [*(int *)(&DAT_006826c4 +
                       *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                       *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) * 0x34
              ] & 1) != 0) &&
           (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == param_1)) {
          DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
        }
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
        if (((&DAT_006826cc)
             [*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
              (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20] & 2) != 0) {
          *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 1;
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                   (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                        (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) &
               0xfffcffff;
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if (param_3 == 0x73) {
      iVar2 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
      if ((*(int *)(&DAT_00676150 + iVar2 * 4) == 0) ||
         (iVar2 = FUN_0049b68d(param_1,param_2,7,0), iVar2 != 0)) {
        if (((*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0) &&
            ((((&DAT_006826cc)
               [*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20] & 0x10) != 0 &&
             (DAT_00666458 == DAT_0068ecb0)))) &&
           (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0)) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if ((param_3 == 0x6d) && (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0))
      {
        iVar2 = FUN_0048c367((int)(char)(&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20]);
        if (*(int *)(&DAT_00676150 + iVar2 * 4) != 0) {
          FUN_0042ecaf(param_1,param_2,0,0);
        }
        if (DAT_00681ea4 != 1) {
          *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
               *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) + 1;
        }
      }
      if (param_3 == 0x72) {
        if (*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                   (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                        (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) &
               0xffffffef;
        }
      }
      if ((((((DAT_0068f230 == 0xd4) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) &&
           ((*(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) != 0 &&
            ((&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] != -1)))) &&
          ((*(int *)(&DAT_006826c4 +
                    *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                    (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) != -1 &&
           ((DAT_00666754 == param_1 && (DAT_0068edd0 == param_2)))))) && (param_1 == DAT_00681ec4))
      {
        if (param_3 == 0x7d) {
          DAT_0066642c = DAT_0066642c | 2;
        }
        if (param_3 == 0x7e) {
          *(uint *)(&DAT_006826cc +
                   *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                   (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
               *(uint *)(&DAT_006826cc +
                        *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                        (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) |
               0x30000;
        }
      }
      if (((param_3 == 0x22) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
        *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


