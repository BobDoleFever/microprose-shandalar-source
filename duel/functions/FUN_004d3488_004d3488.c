/*
 * Decompiled function: FUN_004d3488
 * Entry Point: 004d3488
 * Size: 1213 bytes
 */
#include "duel.h"


undefined4 FUN_004d3488(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,1,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00509014,s_PHANTASMAL_TERRAIN_00509000);
      iVar2 = FUN_00468550(param_1,1 - param_1,param_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if (DAT_00676510 == param_1) {
          if (param_1 == 1) {
            local_c = FUN_00439892(5);
            local_c = local_c + 1;
          }
          else {
            local_c = -1;
          }
          local_8 = FUN_004513fa(param_1,s_Land_type__00509020,0,local_c,0x3e);
          if (local_8 == -1) {
            DAT_00681ea4 = 1;
          }
        }
        else if (DAT_0066aaf4 == 1) {
          local_8 = FUN_00439892(5);
          local_8 = local_8 + 1;
          DAT_0068f2c8 = local_8;
          FUN_0043064a();
        }
        else {
          FUN_004307b2();
          local_8 = DAT_0068f2c8;
        }
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == param_1) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x30;
        }
        *(int *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,1,0,0,uVar1);
      if (iVar2 == 0) {
        FUN_0046e571(param_1,param_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] =
             (&DAT_00682718)[param_2 * 0x120 + param_1 * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
        *(int *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(int *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20) + -1;
        *(undefined4 *)
         (&DAT_006826c4 +
         *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
         (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
             *(undefined4 *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20);
        *(uint *)(&DAT_006826fc +
                 *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                 (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) =
             *(uint *)(&DAT_006826fc +
                      *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
                      (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20) |
             0x1000000;
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if ((((param_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) &&
        ((*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48 &&
         (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0 &&
          (DAT_00690c48 != -1)))))) && (iVar2 = FUN_0048a33f(param_1,param_2), iVar2 != 0)) {
      DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20);
    }
    uVar1 = 0;
  }
  return uVar1;
}


