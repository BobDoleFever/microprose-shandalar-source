/*
 * Decompiled function: FUN_00409cb9
 * Entry Point: 00409cb9
 * Size: 897 bytes
 */
#include "duel.h"


undefined4 FUN_00409cb9(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  if (param_3 == 0x73) {
    if (((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2)
         == 0)) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if (param_3 == 0x6d) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x24;
      if (((param_1 == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
        local_10 = -1;
        local_c = 1;
        while ((local_c < 6 && (local_10 == -1))) {
          if ((0 < (&DAT_0068ece0)[local_c]) &&
             (((int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20] &
              1 << ((byte)local_c & 0x1f)) != 0)) {
            local_10 = local_c;
          }
          local_c = local_c + 1;
        }
        if ((local_10 == -1) && (0 < DAT_0068ece0)) {
          local_10 = 1;
        }
        if ((local_10 == -1) && (0 < DAT_0068ecf8)) {
          local_10 = 1;
        }
        if (local_10 == -1) {
          DAT_00681ea4 = 1;
        }
      }
      else {
        local_10 = -1;
      }
      if (DAT_00681ea4 != 1) {
        FUN_00434660(s_prompts_txt_004f26b8,s_BLACK_LOTUS_004f26ac);
        iVar2 = FUN_004513fa(param_1,&DAT_006679f0,1,local_10,
                             (int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20]);
        if (iVar2 == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_0049b235(param_1,iVar2,3);
          DAT_0068f0f4 = iVar2;
          if (DAT_0066aaf4 != 1) {
            FUN_0048d00c(0xf);
          }
          *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
               *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
          if (DAT_00676510 != param_1) {
            FUN_004d9630(&DAT_005f6810,s_to_produce_004f26c4);
            uVar1 = FUN_0048c420(iVar2);
            FUN_004d9640(&DAT_005f6810,uVar1);
            FUN_004d9640(&DAT_005f6810,s_mana__004f26d0);
            FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_005f6810,0);
          }
          FUN_0046e571(param_1,param_2,3);
        }
      }
    }
    if ((((param_3 == 0x7f) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) &&
       (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0)) {
      FUN_0049af5c(param_1,(int)(char)(&DAT_006826dc)[param_2 * 0x120 + param_1 * 0x5b20],3);
    }
    uVar1 = 0;
  }
  return uVar1;
}


