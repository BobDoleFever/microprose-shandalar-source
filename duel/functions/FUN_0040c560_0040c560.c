/*
 * Decompiled function: FUN_0040c560
 * Entry Point: 0040c560
 * Size: 1322 bytes
 */
#include "duel.h"


undefined4 FUN_0040c560(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short local_c;
  
  if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (param_1 == DAT_0068ecb0)) {
    if (param_1 != DAT_00676510) {
      if (DAT_0066aaf4 == 1) {
        DAT_0068f2c8 = FUN_00439892(7);
        FUN_0043064a();
      }
      else {
        FUN_004307b2();
      }
    }
    FUN_004348b2(s_prompts_txt_004f278c,s_SHAPESHIFTER_004f277c);
    local_c = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_006679f0,DAT_0068f2c8)
    ;
    if (param_1 == DAT_00676504) {
      local_c = (short)DAT_0068f2c8;
    }
    iVar2 = FUN_004af68f(*(undefined4 *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20));
    if (iVar2 != -1) {
      *(short *)(&DAT_004ff59a + iVar2 * 0x34) = local_c;
      *(short *)(&DAT_004ff59c + iVar2 * 0x34) = 7 - local_c;
      *(int *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20) = iVar2;
      *(undefined4 *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20) =
           *(undefined4 *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20);
      *(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826fc + param_2 * 0x120 + param_1 * 0x5b20) | 0x1000000;
    }
  }
  if (((param_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) &&
     ((DAT_00690c48 == param_2 && (param_1 == DAT_0068ecb0)))) {
    iVar2 = FUN_0048a33f(param_1,param_2);
    if (iVar2 != 0) {
      DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + param_2 * 0x120 + param_1 * 0x5b20);
    }
  }
  if (param_3 == 0x73) {
    if ((((DAT_0068f2c4 == 4) && (param_1 == DAT_00666458)) &&
        (*(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) == 0)) &&
       (param_1 == DAT_00681eb4)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (((param_3 == 0x6d) && (DAT_00690c48 == param_2)) && (param_1 == DAT_0068ecb0)) {
      *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = param_1;
      *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = param_2;
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      *(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) =
           *(int *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) + 1;
    }
    if ((param_3 == 0x72) &&
       (*(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) != -1)) {
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
      FUN_004348b2(s_prompts_txt_004f27a8,s_SHAPESHIFTER_004f2798);
      sVar1 = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_006679f0,4);
      *(short *)(&DAT_004ff59a +
                *(int *)(&DAT_006826c4 +
                        *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) * 0x34
                ) = sVar1;
      *(short *)(&DAT_004ff59c +
                *(int *)(&DAT_006826c4 +
                        *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                        *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) * 0x34
                ) = 7 - sVar1;
    }
    if (param_3 == 0x22) {
      *(undefined4 *)(&DAT_006826f0 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}


