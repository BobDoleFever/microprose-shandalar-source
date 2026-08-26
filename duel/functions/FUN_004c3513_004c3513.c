/*
 * Decompiled function: FUN_004c3513
 * Entry Point: 004c3513
 * Size: 2036 bytes
 */
#include "duel.h"


undefined4 FUN_004c3513(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  
  bVar1 = false;
  if (param_3 == 0x74) {
    uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,1,0,0,uVar2);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508a78,s_EROSION_00508a70);
      iVar3 = FUN_00468550(param_1,1 - param_1,param_2);
      DAT_00681ea4 = (uint)(iVar3 == 0);
      if (DAT_00681ea4 != 1) {
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676510) {
          iVar3 = FUN_0048c367((int)(char)(&DAT_004ff596)
                                          [*(int *)(&DAT_006826c4 +
                                                   *(int *)(&DAT_0068271c +
                                                           param_2 * 0x120 + param_1 * 0x5b20) *
                                                   0x120 + *(int *)(&DAT_00682718 +
                                                                   param_2 * 0x120 +
                                                                   param_1 * 0x5b20) * 0x5b20) *
                                           0x34]);
          DAT_0068f2d4 = DAT_0068f2d4 +
                         *(int *)(&DAT_0068ef50 + iVar3 * 4 + DAT_00676510 * 0x20) * -4 + 0x20;
        }
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
        }
      }
    }
    if (param_3 == 0x71) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar3 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,1,0,0,uVar2);
      if (iVar3 == 0) {
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
      if ((((DAT_0068f2c4 == 4) && (DAT_00666458 == DAT_00681eb4)) &&
          ((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00666458)) &&
         (((&DAT_006826e4)[param_2 * 0x120 + param_1 * 0x5b20] & 1) == 0)) {
        *(uint *)(&DAT_006827d4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006827d4 + param_2 * 0x120 + param_1 * 0x5b20) | 0x101;
        DAT_00676500 = DAT_00676500 | 3;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      if (((param_3 == 4) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
        *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) | 1;
        DAT_006664ec = 1;
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (param_3 == 0x86) {
        uVar2 = FUN_0048c367((int)(char)(&DAT_006826dc)
                                        [*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20
                                                 ) * 0x120 +
                                         (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] *
                                         0x5b20],1);
        iVar3 = FUN_0049b309((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],uVar2);
        iVar4 = FUN_0049b309((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],7,1);
        if (iVar3 == 1) {
          if ((iVar4 < 4) &&
             (10 < (int)(&DAT_00681ea8)[(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]]))
          {
            local_10 = 2;
          }
          else {
            local_10 = 1;
          }
        }
        else if ((iVar4 < 3) &&
                (0xf < (int)(&DAT_00681ea8)
                            [(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]])) {
          local_10 = 2;
        }
        else {
          local_10 = 0;
        }
        while (!bVar1) {
          iVar3 = FUN_0045102d((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                               param_1,param_2,
                               (int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                               *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20),
                               s_Destroy_enchanted_land__Pay_1_ma_00508a84,local_10);
          if (iVar3 == 0) {
            FUN_0046e571((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                         *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20),2);
            bVar1 = true;
          }
          else if (iVar3 == 1) {
            iVar3 = FUN_0049b309((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],7,1)
            ;
            if (iVar3 != 0) {
              *(uint *)(&DAT_006826cc +
                       *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                       (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
                   *(uint *)(&DAT_006826cc +
                            *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                            (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) |
                   0x40000;
              FUN_0042b6b0((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],0,1);
              if (DAT_00681ea4 == 1) {
                DAT_00681ea4 = 0;
              }
              else {
                bVar1 = true;
              }
            }
          }
          else if (iVar3 == 2) {
            (&DAT_00681ea8)[(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]] =
                 (&DAT_00681ea8)[(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]] + -1;
            bVar1 = true;
          }
        }
      }
      if (param_3 == 0x22) {
        *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) & 0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


