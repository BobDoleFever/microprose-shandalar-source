/*
 * Decompiled function: FUN_0048e8f2
 * Entry Point: 0048e8f2
 * Size: 495 bytes
 */
#include "duel.h"


undefined4 FUN_0048e8f2(int x,undefined4 arg_2,undefined4 arg_3,int height)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int local_18;
  
  uVar5 = DAT_0068ef98;
  uVar4 = DAT_00681ec4;
  uVar3 = DAT_00666758;
  uVar2 = DAT_00666744;
  uVar1 = DAT_00666440;
  DAT_0068eedc = DAT_0068eedc + 1;
  DAT_00666744 = arg_2;
  DAT_00681ec4 = x;
  do {
    if (x == 0) {
      DAT_00666440 = 1;
    }
    else {
      DAT_00666440 = 2;
    }
    DAT_0068f230 = arg_2;
    if (height == 0) {
      DAT_0068ef98 = 0;
    }
    else {
      DAT_0068ef98 = 0x30;
    }
    DAT_00681ea4 = 0;
    DAT_00666454 = 0;
    DAT_00666758 = 0;
    iVar6 = Pic_Subsystem_004458b0(x,arg_3);
    DAT_006826b4 = uVar5 & 0x30;
  } while (((DAT_00666758 & (-(uint)(iVar6 == 0) & 0xfffffffe) + 6) != 0) ||
          ((height != 0 && (iVar6 != 0))));
  DAT_0068f230 = 0xffffffff;
  DAT_0068eedc = DAT_0068eedc + -1;
  DAT_00666440 = uVar1;
  DAT_0068ef98 = uVar5;
  if (DAT_0068eedc == 0) {
    for (x = 0; x < 2; x = x + 1) {
      for (local_18 = 0; local_18 < (int)(&DAT_00666408)[x]; local_18 = local_18 + 1) {
        *(uint *)(&DAT_006826cc + x * 0x5b20 + local_18 * 0x120) =
             *(uint *)(&DAT_006826cc + x * 0x5b20 + local_18 * 0x120) & 0xfffffeff;
      }
    }
    if (DAT_0068f2d8 == 0) {
      DAT_0068eee4 = 0;
      DAT_00681ed0 = 0;
    }
  }
  DAT_00666758 = uVar3;
  DAT_00681ec4 = uVar4;
  DAT_00666744 = uVar2;
  return 0;
}


