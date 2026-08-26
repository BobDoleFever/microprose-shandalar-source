/*
 * Decompiled function: FUN_004c1ba3
 * Entry Point: 004c1ba3
 * Size: 1370 bytes
 */
#include "duel.h"


undefined4 FUN_004c1ba3(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == param_1) &&
       (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) &&
     (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0)) {
    *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
         *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) + 1;
    FUN_0046e571(param_1,param_2,3);
  }
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,1 - param_1,1 - param_1,0x200,0x40,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_005089ac,s_RELIC_BIND_005089a0);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_10);
      iVar2 = FUN_0041e2a2(param_1,1 - param_1,1 - param_1,0x200,0x40,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        if (((&DAT_004ff5a8)[*(int *)(&DAT_006826c4 + local_10 * 0x5b20 + local_c * 0x120) * 0x34] &
            1) != 0) {
          DAT_0068f2d4 = DAT_0068f2d4 +
                         (((char)(&DAT_004ff598)
                                 [*(int *)(&DAT_006826c4 + local_10 * 0x5b20 + local_c * 0x120) *
                                  0x34] * 3 + 6) * 8) / 2;
        }
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,1 - param_1,1 - param_1,0x200,0x40,0,0,uVar1);
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
    if (((param_3 == 0x81) &&
        (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48)) &&
       (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0 &&
        (DAT_00690c48 != -1)))) {
      local_8 = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,
                             s_Gain_life__Take_Damage__005089b8,
                             (int)(&DAT_00681ea8)[1 - param_1] <= (int)(&DAT_00681ea8)[param_1]);
      FUN_00434660(s_prompts_txt_005089e0,s_RELIC_BIND_005089d4);
      if ((int)(&DAT_00681ea8)[param_1] < (int)(&DAT_00681ea8)[1 - param_1]) {
        local_14 = param_1;
      }
      else {
        local_14 = 1 - param_1;
      }
      FUN_0041e2a2(param_1,2,local_14,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff
                   ,0xffffffff,0,0,&DAT_00667aea,0,&local_10);
      if (local_8 == 0) {
        (&DAT_00681ea8)[local_10] = (&DAT_00681ea8)[local_10] + 1;
      }
      else {
        FUN_004afd1c(local_10,1,param_1,param_2);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


