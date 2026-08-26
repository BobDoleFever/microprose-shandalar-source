/*
 * Decompiled function: FUN_004ceabe
 * Entry Point: 004ceabe
 * Size: 1006 bytes
 */
#include "duel.h"


undefined4 FUN_004ceabe(uint arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_11;
  undefined4 uVar3;
  uint arg_12;
  undefined4 uVar4;
  uint arg_13;
  undefined4 uVar5;
  undefined4 uVar6;
  int arg_15;
  undefined4 uVar7;
  uint arg_16;
  undefined4 uVar8;
  uint arg_17;
  undefined4 uVar9;
  uint arg_18;
  undefined4 uVar10;
  uint arg_19;
  undefined4 uVar11;
  uint arg_20;
  uint local_8;
  
  if (arg_3 == 0x74) {
    if (DAT_00676510 == arg_1) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar5 = 0xffffffff;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = FUN_004521e2(arg_1,arg_2);
      uVar1 = FUN_0041bcf0((int *)0x0,0,arg_1,2,2,0x200,2,0,0,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11);
    }
    else if (arg_5 + arg_4 < 0) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar5 = 0xffffffff;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = FUN_004521e2(arg_1,arg_2);
      uVar1 = FUN_0041bcf0((int *)0x0,0,arg_1,2,2,0x200,2,0,0,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11);
    }
    else {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      uVar6 = 0xffffffff;
      uVar5 = 0xffffffff;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = FUN_004521e2(arg_1,arg_2);
      uVar1 = FUN_0041bcf0((int *)0x0,0,arg_1,2,2,0x200,2,0,0,uVar1,uVar3,uVar4,uVar5,uVar6,uVar7,
                           uVar8,uVar9,uVar10,uVar11);
    }
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      if (arg_5 + arg_4 < 0) {
        local_8 = 1 - arg_1;
      }
      else {
        local_8 = arg_1;
      }
      iVar2 = FUN_00468130(arg_1,local_8,arg_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      }
    }
    if (arg_3 == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(arg_1,arg_2);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),(undefined1 *)0x0,
                         arg_1,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,arg_16,arg_17,
                         arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        FUN_0046e571(arg_1,arg_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&DAT_00682718)[arg_2 * 0x120 + arg_1 * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
    }
    if (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) {
      if (((arg_3 == 0x32) &&
          (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
         (((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0 &&
          (DAT_00690c48 != -1)))) {
        DAT_0066642c = DAT_0066642c + arg_4;
      }
      if (((arg_3 == 0x33) &&
          (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
         (((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0 &&
          (DAT_00690c48 != -1)))) {
        DAT_0066642c = DAT_0066642c + arg_5;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


