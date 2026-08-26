/*
 * Decompiled function: FUN_004a9ad1
 * Entry Point: 004a9ad1
 * Size: 673 bytes
 */
#include "duel.h"


undefined4 FUN_004a9ad1(int arg_1,int arg_2,int arg_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 arg_11;
  int iVar7;
  uint uVar8;
  undefined4 arg_13;
  uint uVar9;
  undefined4 arg_14;
  uint uVar10;
  undefined4 arg_15;
  uint uVar11;
  undefined4 arg_16;
  uint uVar12;
  undefined4 arg_17;
  char *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    FUN_0043071d(0);
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    bVar1 = FUN_004af7bb(arg_1,arg_2,1);
    iVar4 = 1 << (bVar1 & 0x1f);
    arg_11 = 0;
    uVar2 = FUN_004521e2(arg_1,arg_2);
    uVar2 = FUN_0041bcf0((int *)0x0,0,arg_1,2,2,0x200,2,0x40,0,uVar2,arg_11,iVar4,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
      arg_20 = &local_c;
      uVar2 = 1;
      arg_18 = s_Target_Creature_005062e8;
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar4 = -1;
      bVar1 = FUN_004af7bb(arg_1,arg_2,1);
      uVar5 = 1 << (bVar1 & 0x1f);
      uVar6 = 0;
      uVar3 = FUN_004521e2(arg_1,arg_2);
      iVar4 = Action_ValidateTarget_0041e2a2
                        (arg_1,2,1 - arg_1,0x200,2,0x40,0,uVar3,uVar6,uVar5,iVar4,iVar7,uVar8,uVar9,
                         uVar10,uVar11,uVar12,arg_18,uVar2,arg_20);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
      }
    }
    if (arg_3 == 0x71) {
      local_c = *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
      uVar12 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0xffffffff;
      uVar8 = 0xffffffff;
      iVar7 = -1;
      iVar4 = -1;
      bVar1 = FUN_004af7bb(arg_1,arg_2,1);
      uVar5 = 1 << (bVar1 & 0x1f);
      uVar6 = 0;
      uVar3 = FUN_004521e2(arg_1,arg_2);
      iVar4 = Rules_ParseFilter_0041c0ab
                        (local_c,local_8,(undefined1 *)0x0,arg_1,2,2,0x200,2,0x40,0,uVar3,uVar6,
                         uVar5,iVar4,iVar7,uVar8,uVar9,uVar10,uVar11,uVar12);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_0046e571(local_c,local_8,1);
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


