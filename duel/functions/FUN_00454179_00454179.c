/*
 * Decompiled function: FUN_00454179
 * Entry Point: 00454179
 * Size: 573 bytes
 */
#include "duel.h"


undefined4 FUN_00454179(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 local_c [4];
  undefined4 local_8;
  
  if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
    FUN_00434660(s_prompts_txt_004f8834,s_VESUVAN_DOPPELGANGER_004f881c);
    iVar1 = FUN_0041e2a2(param_1,2,2,0x200,2,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0
                         ,0,0,&DAT_006679f0,1,local_c);
    if (iVar1 == 0) {
      FUN_0046e571(param_1,param_2,1);
      DAT_00681ea4 = 1;
    }
    else {
      (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] = local_c[0];
      *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
    }
  }
  if (param_3 == 0x71) {
    *(undefined4 *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) =
         *(undefined4 *)
          (&DAT_006826c4 +
          *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
          (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20);
    (&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20] =
         (&DAT_004ff596)
         [*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) * 0x34];
    *(uint *)(&DAT_006826f8 + param_2 * 0x120 + param_1 * 0x5b20) =
         *(uint *)(&DAT_006826f8 + param_2 * 0x120 + param_1 * 0x5b20) | 0x2000;
    FUN_0048c907(param_1,param_2,0x6c,1 - param_1,0xffffffff);
  }
  return 0;
}


