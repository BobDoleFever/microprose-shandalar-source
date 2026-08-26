/*
 * Decompiled function: FUN_004aa5bf
 * Entry Point: 004aa5bf
 * Size: 1231 bytes
 */
#include "duel.h"


undefined4 FUN_004aa5bf(int param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    if (DAT_0068ecd0 == -1) {
      FUN_0043071d(0);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0xff,0,0,uVar2);
    }
    else if (((param_1 == DAT_00676510) ||
             ((param_1 == DAT_00676504 && (DAT_00666458 == DAT_00676510)))) &&
            (iVar3 = FUN_0041c0ab(DAT_0068ecd0,DAT_0068eccc,0,param_1,2,2,0,0xff,0,0,0,0,0,
                                  0xffffffff,0xffffffff,0xffffffff,0xffffffff,2,0,0), iVar3 != 0)) {
      uVar2 = 99;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      if (DAT_0068ecd0 == -1) {
        FUN_00434660(s_prompts_txt_00506368,s_ANY_LACE_0050635c);
        uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                             &DAT_006679f0,1,&local_14);
        iVar3 = FUN_0041e2a2(param_1,2,2,0x200,0xff,0,0,uVar2);
        if (iVar3 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_14;
          *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_10;
          (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        }
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_0068ecd0;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = DAT_0068eccc;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      local_8 = 0;
      if (DAT_0068ecd0 == -1) {
        uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
        iVar3 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                             param_1,2,2,0x200,0xff,0,0,uVar2);
        if (iVar3 != 0) {
          local_8 = local_8 + 1;
        }
      }
      else {
        iVar3 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                             param_1,2,2,0,0xff,0,0,0,0,0,0xffffffff,0xffffffff,0xffffffff,
                             0xffffffff,2,0,0);
        if (iVar3 != 0) {
          local_8 = local_8 + 1;
        }
      }
      if (local_8 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        local_14 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
        local_10 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
        local_c = FUN_0048c367((int)(char)(&DAT_004ff596)
                                          [*(int *)(&DAT_006826c4 +
                                                   param_2 * 0x120 + param_1 * 0x5b20) * 0x34]);
        bVar1 = FUN_004af7bb(param_1,param_2,local_c);
        (&DAT_006826dd)[local_14 * 0x5b20 + local_10 * 0x120] = (char)(1 << (bVar1 & 0x1f));
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x1d);
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


