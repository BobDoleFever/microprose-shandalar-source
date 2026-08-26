/*
 * Decompiled function: FUN_0041196e
 * Entry Point: 0041196e
 * Size: 1645 bytes
 */
#include "duel.h"


undefined4 FUN_0041196e(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ef6c + param_1 * 0x20) * 6;
  }
  if (param_3 == 0x73) {
    if ((((byte)DAT_00681eb0 & 4) == 0) ||
       ((((((&DAT_006826ce)[param_2 * 0x120 + param_1 * 0x5b20] & 3) != 0 &&
          (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x34] & 2
           ) != 0)) || (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) != 0)) ||
        ((iVar1 = FUN_0049b309(param_1,7,3), iVar1 == 0 ||
         (iVar1 = FUN_0041bcf0(0,0,param_1,param_1,param_1,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff
                               ,0xffffffff,0xffffffff,0x20,0,0), iVar1 == 0)))))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 99;
    }
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if (((param_3 == 0x6d) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x10) == 0))
       && (FUN_0042b6b0(param_1,0,3), DAT_00681ea4 != 1)) {
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      local_10 = 0;
      local_c = 0;
      while (((local_10 < 2 && (local_c == 0)) && (DAT_00681ea4 != 1))) {
        FUN_00434660(s_prompts_txt_004f2a48,s_CONSERVATOR_004f2a3c);
        iVar1 = FUN_0041e2a2(param_1,param_1,param_1,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,
                             0xffffffff,0xffffffff,0x20,0,0,&DAT_006679f0,3,&local_18);
        if (iVar1 == 0) {
          if (local_14 == -1) {
            DAT_00681ea4 = 1;
          }
          else {
            local_c = 1;
          }
        }
        else {
          *(uint *)(&DAT_006826cc + local_18 * 0x5b20 + local_14 * 0x120) =
               *(uint *)(&DAT_006826cc + local_18 * 0x5b20 + local_14 * 0x120) | 0x200000;
          FUN_00451482(0,0x20);
          *(int *)(&DAT_00682718 +
                  param_2 * 0x120 +
                  param_1 * 0x5b20 + (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8)
               = local_18;
          *(int *)(&DAT_0068271c +
                  param_2 * 0x120 +
                  param_1 * 0x5b20 + (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] * 8)
               = local_14;
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] =
               (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] + '\x01';
        }
        local_10 = local_10 + 1;
      }
      for (local_10 = 0; local_10 < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
          local_10 = local_10 + 1) {
        *(uint *)(&DAT_006826cc +
                 *(int *)(&DAT_0068271c + local_10 * 8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x120
                 + *(int *)(&DAT_00682718 + local_10 * 8 + param_1 * 0x5b20 + param_2 * 0x120) *
                   0x5b20) =
             *(uint *)(&DAT_006826cc +
                      *(int *)(&DAT_0068271c + local_10 * 8 + param_1 * 0x5b20 + param_2 * 0x120) *
                      0x120 + *(int *)(&DAT_00682718 +
                                      local_10 * 8 + param_1 * 0x5b20 + param_2 * 0x120) * 0x5b20) &
             0xffcfffff;
      }
      if (DAT_00681ea4 == 1) {
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      }
      else {
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      local_8 = 0;
      for (local_10 = 0; local_10 < (char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20];
          local_10 = local_10 + 1) {
        local_18 = *(int *)(&DAT_00682718 + local_10 * 8 + param_1 * 0x5b20 + param_2 * 0x120);
        local_14 = *(int *)(&DAT_0068271c + local_10 * 8 + param_1 * 0x5b20 + param_2 * 0x120);
        iVar1 = FUN_0041c0ab(*(undefined4 *)
                              (&DAT_00682718 + local_10 * 8 + param_1 * 0x5b20 + param_2 * 0x120),
                             *(undefined4 *)
                              (&DAT_0068271c + local_10 * 8 + param_1 * 0x5b20 + param_2 * 0x120),0,
                             param_1,param_1,param_1,0x200,0,0,0,0,0,0,DAT_0068f104,0xffffffff,
                             0xffffffff,0xffffffff,0x20,0,0);
        if (iVar1 == 0) {
          local_8 = local_8 + 1;
        }
        else if (*(int *)(&DAT_006826e4 + local_18 * 0x5b20 + local_14 * 0x120) != 0) {
          *(int *)(&DAT_006826e4 + local_18 * 0x5b20 + local_14 * 0x120) =
               *(int *)(&DAT_006826e4 + local_18 * 0x5b20 + local_14 * 0x120) + -1;
        }
      }
      if ((char)(&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] == local_8) {
        DAT_00681ea4 = 1;
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20] = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}


