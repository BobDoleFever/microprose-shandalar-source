/*
 * Decompiled function: FUN_00461047
 * Entry Point: 00461047
 * Size: 612 bytes
 */
#include "duel.h"


bool FUN_00461047(int arg1,int arg2)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined *puVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (arg1 == DAT_00676510) {
    if (DAT_0066aaf4 == 1) {
      local_14 = 0xffffffff;
      DAT_0068eef0 = 1 - arg1;
    }
    else {
      piVar14 = &local_10;
      uVar13 = 1;
      puVar12 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = FUN_004521e2(arg1,arg2);
      iVar5 = Action_ValidateTarget_0041e2a2
                        (arg1,2,1 - arg1,0x1200,2,0,0,uVar1,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,
                         uVar9,uVar10,uVar11,puVar12,uVar13,piVar14);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
        local_14 = 0xffffffff;
        DAT_0068eef0 = -1;
      }
      else {
        local_14 = local_c;
        DAT_0068eef0 = local_10;
      }
    }
  }
  else {
    if (DAT_0066aaf4 == 1) {
      iVar5 = FUN_00439892(3);
      DAT_0068f2c8 = (uint)(iVar5 == 0);
      FUN_0043064a();
    }
    else {
      FUN_004307b2();
    }
    if (DAT_0068f2c8 == 0) {
      piVar14 = &local_10;
      uVar13 = 1;
      puVar12 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar1 = FUN_004521e2(arg1,arg2);
      Action_ValidateTarget_0041e2a2
                (arg1,2,1 - arg1,0x1200,2,0,0,uVar1,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10
                 ,uVar11,puVar12,uVar13,piVar14);
      local_14 = local_c;
      DAT_0068eef0 = local_10;
    }
    else {
      local_14 = 0xffffffff;
      DAT_0068eef0 = 1 - arg1;
      if (DAT_0066aaf4 == 1) {
        DAT_0068f2c8 = 0;
        DAT_0068f0bc = CONCAT31((uint3)((DAT_0068eef0 == 0) - 1 >> 8) & 1,0xff);
        FUN_0043064a();
      }
      else {
        FUN_004307b2();
      }
    }
  }
  bVar2 = DAT_00681ea4 != 1;
  if (bVar2) {
    *(undefined4 *)(&DAT_0068271c + arg2 * 0x120 + arg1 * 0x5b20) = local_14;
    *(int *)(&DAT_00682718 + arg2 * 0x120 + arg1 * 0x5b20) = DAT_0068eef0;
    (&DAT_006827b8)[arg2 * 0x120 + arg1 * 0x5b20] = 1;
  }
  return bVar2;
}


