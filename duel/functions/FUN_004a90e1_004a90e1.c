/*
 * Decompiled function: FUN_004a90e1
 * Entry Point: 004a90e1
 * Size: 951 bytes
 */
#include "duel.h"


undefined4 FUN_004a90e1(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      if (DAT_00676510 == param_1) {
        FUN_00434660(s_prompts_txt_005062c8,s_HURKYLS_RECALL_005062b8);
        iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x1000,0,0,0,0,0,0,0xffffffff,0xffffffff,
                             0xffffffff,0xffffffff,0,0,0,&DAT_006679f0,1,&local_14);
        if (iVar2 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_14;
          *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        }
      }
      else {
        if (DAT_0066aaf4 == 1) {
          iVar2 = FUN_00439892(3);
          DAT_0068f2c8 = (uint)(iVar2 == 0);
          if (DAT_0068f2c8 != 0) {
            iVar2 = FUN_00467cce(1 - param_1,0x40);
            if (iVar2 == 0) {
              DAT_0068f2c8 = 0;
            }
            else {
              iVar2 = FUN_00467cce(param_1,0x40);
              if (iVar2 == 0) {
                DAT_0068f2c8 = 1;
              }
            }
          }
          FUN_0043064a();
        }
        else {
          FUN_004307b2();
        }
        if (DAT_0068f2c8 == 0) {
          *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = 1 - param_1;
        }
        else {
          *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = param_1;
        }
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = 0xffffffff;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == 0) {
        local_18 = 0;
      }
      else {
        local_18 = 0x1000;
      }
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
          iVar2 = FUN_0048a33f(local_8,local_c);
          if (((iVar2 != 0) &&
              (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34]
               & 0x40) != 0)) &&
             ((*(uint *)(&DAT_006826cc + local_c * 0x120 + local_8 * 0x5b20) & 0x1000) == local_18))
          {
            FUN_004af82a(local_8,local_c);
          }
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


