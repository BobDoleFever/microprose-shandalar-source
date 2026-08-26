/*
 * Decompiled function: FUN_00402fea
 * Entry Point: 00402fea
 * Size: 1851 bytes
 */
#include "duel.h"


undefined4 FUN_00402fea(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,3,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    FUN_0041bcf0(-(uint)(DAT_0068f100 == 0) & 0x68ed04,0,param_1,2,2,0x200,0,0,0,uVar1);
    if ((param_1 == DAT_00676504) &&
       ((DAT_0068ed04 == 0 || (iVar2 = FUN_0049b309(param_1,7,4), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    return uVar1;
  }
  if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
    iVar2 = FUN_00404a71(param_1,*(undefined4 *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120)
                        );
    DAT_0068f2d4 = DAT_0068f2d4 - (int)(0x24 / (longlong)iVar2);
    (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 0;
    local_18 = 0;
    local_10 = 0;
    while (((local_18 < DAT_00681ea0 && (local_10 == 0)) && (DAT_00681ea4 != 1))) {
      local_14 = FUN_004af74c(param_1,param_2,4);
      local_14 = local_14 + -1;
      FUN_00434660(s_prompts_txt_004f2160,s_VOLCANIC_ERUPTION_004f214c);
      _sprintf(&DAT_006679f0,&DAT_006679f0,local_18 + 1,DAT_00681ea0);
      if (local_14 == 4) {
        FUN_004718de(&DAT_006679f0,s_mountain_004f2174,0,s_PLAINS_004f216c);
      }
      else if (local_14 == 0) {
        FUN_004718de(&DAT_006679f0,s_mountain_004f2188,0,s_SWAMP_004f2180);
      }
      else if (local_14 == 1) {
        FUN_004718de(&DAT_006679f0,s_mountain_004f219c,0,s_ISLAND_004f2194);
      }
      else if (local_14 == 2) {
        FUN_004718de(&DAT_006679f0,s_mountain_004f21b0,0,s_FOREST_004f21a8);
      }
      uVar1 = FUN_004521e2(param_1,param_2,0,0,local_14,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_20);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,0,0,0,uVar1);
      if (iVar2 == 0) {
        if (local_1c == -1) {
          DAT_00681ea4 = 1;
        }
        else {
          local_10 = 1;
        }
      }
      else {
        *(uint *)(&DAT_006826cc + local_20 * 0x5b20 + local_1c * 0x120) =
             *(uint *)(&DAT_006826cc + local_20 * 0x5b20 + local_1c * 0x120) | 0x300000;
        FUN_00451482(0,0x20);
        *(int *)(&DAT_00682718 +
                param_1 * 0x5b20 +
                param_2 * 0x120 + (char)(&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] * 8) =
             local_20;
        *(int *)(&DAT_0068271c +
                param_1 * 0x5b20 +
                param_2 * 0x120 + (char)(&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] * 8) =
             local_1c;
        (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] =
             (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] + '\x01';
      }
      local_18 = local_18 + 1;
    }
    for (local_18 = 0; local_18 < (char)(&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120];
        local_18 = local_18 + 1) {
      *(uint *)(&DAT_006826cc +
               *(int *)(&DAT_0068271c + local_18 * 8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               *(int *)(&DAT_00682718 + local_18 * 8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20)
           = *(uint *)(&DAT_006826cc +
                      *(int *)(&DAT_0068271c + local_18 * 8 + param_2 * 0x120 + param_1 * 0x5b20) *
                      0x120 + *(int *)(&DAT_00682718 +
                                      local_18 * 8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20) &
             0xffcfffff;
    }
    if (DAT_00681ea4 == 1) {
      (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 0;
    }
  }
  if (param_3 == 0x71) {
    local_14 = FUN_004af74c(param_1,param_2,4);
    local_14 = local_14 + -1;
    local_8 = 0;
    for (local_18 = 0; local_18 < (char)(&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120];
        local_18 = local_18 + 1) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,local_14,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)
                            (&DAT_00682718 + local_18 * 8 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)
                            (&DAT_0068271c + local_18 * 8 + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,0,0,0,uVar1);
      if (iVar2 == 0) {
        local_8 = local_8 + 1;
      }
      else {
        FUN_0046e571(*(undefined4 *)
                      (&DAT_00682718 + local_18 * 8 + param_2 * 0x120 + param_1 * 0x5b20),
                     *(undefined4 *)
                      (&DAT_0068271c + local_18 * 8 + param_2 * 0x120 + param_1 * 0x5b20),2);
      }
    }
    if ((char)(&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] == local_8) {
      DAT_00681ea4 = 1;
    }
    if ((DAT_00681ea4 != 1) && (local_c = FUN_004d695b(param_1,DAT_0068f2d0), local_c != -1)) {
      *(undefined4 *)(&DAT_006826c0 + local_c * 0x120 + param_1 * 0x5b20) =
           *(undefined4 *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120);
      *(uint *)(&DAT_006826cc + local_c * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + local_c * 0x120 + param_1 * 0x5b20) | 2;
      *(undefined4 *)(&DAT_00682704 + local_c * 0x120 + param_1 * 0x5b20) = 0x109;
      *(int *)(&DAT_006826e4 + local_c * 0x120 + param_1 * 0x5b20) =
           (char)(&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] - local_8;
      FUN_0048eb25(param_1,local_c);
    }
    (&DAT_006827b8)[param_1 * 0x5b20 + param_2 * 0x120] = 0;
    FUN_0046e571(param_1,param_2,1);
  }
  return 0;
}


