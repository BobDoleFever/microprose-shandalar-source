/*
 * Decompiled function: FUN_004cffc5
 * Entry Point: 004cffc5
 * Size: 2124 bytes
 */
#include "duel.h"


undefined4 FUN_004cffc5(int param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x40,0,0,uVar2);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      do {
        FUN_00434660(s_prompts_txt_00508ea0,s_COPY_ARTIFACT_00508e90);
        uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                             &DAT_006679f0,1,&local_10);
        iVar3 = FUN_0041e2a2(param_1,2,2,0x200,0x40,0,0,uVar2);
        if (iVar3 == 0) {
          DAT_00681ea4 = 1;
        }
        else if (((&DAT_004ff594)
                  [*(int *)(&DAT_006826c0 + local_10 * 0x5b20 + local_c * 0x120) * 0x34] & 0x40) ==
                 0) {
          if (DAT_0066aaf4 != 1) {
            FUN_00450eed(s_Illegal_target__didn_t_enter_pla_00508eac);
            Sleep(2000);
            FUN_00450eed(&DAT_00508ee0);
          }
        }
        else {
          *(int *)(&DAT_00682718 +
                  param_2 * 0x120 +
                  param_1 * 0x5b20 + (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8)
               = local_10;
          *(int *)(&DAT_0068271c +
                  param_2 * 0x120 +
                  param_1 * 0x5b20 + (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8)
               = local_c;
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        }
      } while ((DAT_00681ea4 != 1) &&
              (((&DAT_004ff594)
                [*(int *)(&DAT_006826c0 + local_10 * 0x5b20 + local_c * 0x120) * 0x34] & 0x40) == 0)
              );
    }
    if (param_3 == 0x71) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar3 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,0x40,0,0,uVar2);
      if (iVar3 == 0) {
        FUN_0046e571(param_1,param_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        bVar1 = false;
        if ((*(int *)(&DAT_004ff590 +
                     *(int *)(&DAT_006826c0 +
                             *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                             *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) *
                     0x34) == 0x207) ||
           (*(int *)(&DAT_004ff590 +
                    *(int *)(&DAT_006826c0 +
                            *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                            *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) *
                    0x34) == 0x20d)) {
          bVar1 = true;
        }
        if (bVar1) {
          local_8 = FUN_004af68f(*(undefined4 *)
                                  (&DAT_006826c4 +
                                  *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) *
                                  0x5b20 + *(int *)(&DAT_0068271c +
                                                   param_2 * 0x120 + param_1 * 0x5b20) * 0x120));
        }
        else {
          local_8 = FUN_004af68f(*(undefined4 *)
                                  (&DAT_006826c0 +
                                  *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) *
                                  0x5b20 + *(int *)(&DAT_0068271c +
                                                   param_2 * 0x120 + param_1 * 0x5b20) * 0x120));
        }
        if (local_8 != -1) {
          *(int *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
          *(undefined4 *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) =
               *(undefined4 *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20);
          *(undefined4 *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) = 0x1000000;
          (&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] =
               (&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34]
               | 4;
        }
        (&DAT_006826dd)[param_2 * 0x120 + param_1 * 0x5b20] =
             (&DAT_006826dd)
             [*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) * 0x120];
        if (bVar1) {
          if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34]
              & 2) != 0) {
            *(int *)(&DAT_0068ee80 + param_1 * 4) = *(int *)(&DAT_0068ee80 + param_1 * 4) + 1;
          }
          if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34]
              & 0x40) != 0) {
            (&DAT_0068ee88)[param_1] = (&DAT_0068ee88)[param_1] + 1;
          }
          if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34]
              & 4) != 0) {
            *(int *)(&DAT_0068ee90 + param_1 * 4) = *(int *)(&DAT_0068ee90 + param_1 * 4) + 1;
          }
          *(uint *)(&DAT_0066aad0 + param_1 * 4) =
               *(uint *)(&DAT_0066aad0 + param_1 * 4) |
               (uint)(byte)(&DAT_004ff594)
                           [*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34];
          *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
               *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) |
               (param_1 == 0) - 1 & 0x400000 | 0x30082;
          DAT_00666754 = param_1;
          DAT_0068edd0 = param_2;
          FUN_0048e8a8(DAT_00666458,0xdb,s_Card_into_play_00508ee4,0);
        }
        else {
          FUN_004bda20(param_1,param_2);
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if ((((param_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) && (DAT_00690c48 == param_2)) &&
       ((DAT_0068ecb0 == param_1 && (iVar3 = FUN_0048a33f(param_1,param_2), iVar3 != 0)))) {
      DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20);
    }
    uVar2 = 0;
  }
  return uVar2;
}


