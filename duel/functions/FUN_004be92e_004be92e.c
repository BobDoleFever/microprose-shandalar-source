/*
 * Decompiled function: FUN_004be92e
 * Entry Point: 004be92e
 * Size: 951 bytes
 */
#include "duel.h"


undefined4 FUN_004be92e(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,1,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_00508910,s_ANIMATE_WALL_00508900);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,1,0,0,
                           &DAT_006679f0,1,&local_c);
      iVar2 = FUN_0041e2a2(param_1,2,param_1,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120) = local_c;
        *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120) = local_8;
        (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 1;
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,1,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_1 * 0x5b20 + param_2 * 0x120),
                           *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120),0,
                           param_1,2,2,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        FUN_0046e571(param_1,param_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] =
             (&DAT_00682718)[param_1 * 0x5b20 + param_2 * 0x120];
        *(undefined4 *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) =
             *(undefined4 *)(&DAT_0068271c + param_1 * 0x5b20 + param_2 * 0x120);
        *(uint *)(&DAT_006826f8 +
                 *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                 (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20) =
             *(uint *)(&DAT_006826f8 +
                      *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                      (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20) | 0x800;
      }
      (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 0;
    }
    if (((param_3 == 0x77) && (param_2 == DAT_00690c48)) &&
       ((param_1 == DAT_0068ecb0 &&
        (*(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) != -1)))) {
      *(uint *)(&DAT_006826f8 +
               *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
               (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20) =
           *(uint *)(&DAT_006826f8 +
                    *(int *)(&DAT_006826e8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120 +
                    (char)(&DAT_006826d2)[param_1 * 0x5b20 + param_2 * 0x120] * 0x5b20) & 0xfffff7ff
      ;
    }
    uVar1 = 0;
  }
  return uVar1;
}


