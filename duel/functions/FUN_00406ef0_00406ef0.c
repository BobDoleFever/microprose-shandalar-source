/*
 * Decompiled function: FUN_00406ef0
 * Entry Point: 00406ef0
 * Size: 712 bytes
 */
#include "duel.h"


undefined4 FUN_00406ef0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 local_10;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (param_1 == DAT_0068ecb0)) &&
       ((param_1 == DAT_00676504 && (*(int *)(&DAT_006669f0 + param_1 * 2000) == -1)))) {
      DAT_00681ea4 = 1;
    }
    if (param_3 == 0x71) {
      if (((param_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
        FUN_00434660(s_prompts_txt_004f2374,s_DEMONIC_TUTOR_004f2364);
        local_8 = FUN_004d6639(param_1,&DAT_006669f0 + param_1 * 2000,500,&DAT_006679f0,1,
                               &DAT_004f2380);
        if ((local_8 != -1) && (*(int *)(&DAT_006669f0 + local_8 * 4 + param_1 * 2000) != -1)) {
          FUN_004d695b(param_1,*(undefined4 *)(&DAT_006669f0 + local_8 * 4 + param_1 * 2000));
          FUN_004d7acc(param_1,local_8);
        }
      }
      else {
        if (param_1 == DAT_00676510) {
          local_10 = 0x42;
        }
        else {
          if (DAT_0066aaf4 == 1) {
            DAT_0068f2c8 = FUN_00439892(4);
            FUN_0043064a();
          }
          else {
            FUN_004307b2();
          }
          switch(DAT_0068f2c8) {
          case 0:
            local_10 = 2;
            break;
          case 1:
            local_10 = 0x40;
            break;
          case 2:
            local_10 = 8;
            break;
          case 3:
            local_10 = 0x10;
          }
        }
        local_8 = FUN_00408121(param_1,param_1,local_10);
        if (local_8 == -1) {
          local_8 = FUN_00408121(param_1,param_1,0xffffffff);
        }
        if ((local_8 != -1) && (*(int *)(&DAT_006669f0 + local_8 * 4 + param_1 * 2000) != -1)) {
          FUN_004d695b(param_1,*(undefined4 *)(&DAT_006669f0 + local_8 * 4 + param_1 * 2000));
          FUN_004d7acc(param_1,local_8);
        }
      }
      if (local_8 != -1) {
        FUN_00451482(0,0x30);
        FUN_004d7946(param_1);
      }
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


