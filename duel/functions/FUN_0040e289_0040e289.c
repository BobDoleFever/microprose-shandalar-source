/*
 * Decompiled function: FUN_0040e289
 * Entry Point: 0040e289
 * Size: 727 bytes
 */
#include "duel.h"


undefined4 FUN_0040e289(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  if (param_3 == 0x73) {
    iVar1 = FUN_0049b309(param_1,7,2);
    if ((iVar1 == 0) ||
       (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
          != 0)) || (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((param_3 == 0x6d) && (iVar1 = FUN_0049b309(param_1,7,2), iVar1 != 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      FUN_0042b6b0(param_1,0,2);
      if (DAT_00681ea4 != 1) {
        if (param_1 == DAT_00676510) {
          local_8 = -1;
        }
        else if (DAT_0066aaf4 == 1) {
          local_8 = DAT_0068dd00 % 5 + 1;
          DAT_0068f2c8 = local_8;
          FUN_0043064a();
        }
        else {
          FUN_004307b2();
          if (DAT_0068f2c8 < 6) {
            local_8 = DAT_0068f2c8;
          }
          else {
            DAT_00681ea4 = 1;
          }
        }
        if (DAT_00681ea4 != 1) {
          FUN_00434660(s_prompts_txt_004f28c8,s_CELESTIAL_PRISM_004f28b8);
          iVar1 = FUN_004513fa(param_1,&DAT_006679f0,1,local_8,
                               (int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20]);
          if (iVar1 == -1) {
            DAT_00681ea4 = 1;
          }
          if (DAT_00681ea4 != 1) {
            FUN_0049b235(param_1,iVar1,1);
            FUN_0049b00c(param_1,(int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20],1);
            *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
                 *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
            DAT_0068f0f4 = iVar1;
            if (param_1 != DAT_00676510) {
              FUN_004d9630(&DAT_005f6810,s_to_produce_004f28d4);
              uVar2 = FUN_0048c420(iVar1);
              FUN_004d9640(&DAT_005f6810,uVar2);
              FUN_004d9640(&DAT_005f6810,s_mana__004f28e0);
              FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_005f6810,0);
            }
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


