/*
 * Decompiled function: FUN_0048e405
 * Entry Point: 0048e405
 * Size: 1187 bytes
 */
#include "duel.h"


int FUN_0048e405(int x,int y,uint *arg_3,undefined4 arg_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_98;
  int local_94;
  uint local_8c [32];
  undefined4 local_c;
  undefined4 local_8;
  
  uVar3 = DAT_00676500;
  uVar2 = DAT_00666744;
  uVar1 = DAT_00666404;
  local_c = DAT_0068f230;
  DAT_0068f230 = 0xffffffff;
  DAT_0068f2d8 = DAT_0068f2d8 + 1;
  if (DAT_0068f2d8 == 1) {
    DAT_0068ecc4 = 0;
  }
  else if ((((DAT_0068ecc4 < DAT_0068f2d8) && (y != 0x8e)) && (y != 0x70)) && (y != 0xd3)) {
    DAT_0068ecc4 = DAT_0068f2d8;
  }
  local_94 = 0;
  DAT_00666744 = arg_4;
  local_8 = DAT_004fac20;
  if ((x == -2) && (iVar4 = FUN_0042a99c(), iVar4 == 0)) {
    DAT_004fac20 = 1;
  }
  else {
    DAT_004fac20 = 0;
  }
  iVar4 = FUN_0042a99c();
  if ((iVar4 == 0) &&
     ((*(int *)(&DAT_006667c0 + y * 4 + DAT_00666458 * 0x98) != 0 ||
      ((DAT_00666458 == DAT_0066aac4 && (DAT_0066ab04 == y)))))) {
    DAT_00666404 = 1;
  }
  else {
    DAT_00666404 = 0;
  }
  if ((-1 < x) && (DAT_00666404 == 0)) {
LAB_0048e800:
    DAT_0068f2d8 = DAT_0068f2d8 + -1;
    if ((DAT_0068f2d8 == 0) && (DAT_006826b4 = 0xffffffff, DAT_0068eedc == 0)) {
      DAT_0068eee4 = 0;
      DAT_00681ed0 = 0;
    }
    DAT_0068ef98 = 0xffffffff;
    DAT_00666404 = uVar1;
    DAT_004fac20 = local_8;
    DAT_00676500 = uVar3;
    DAT_0068f230 = local_c;
    DAT_00666744 = uVar2;
    if (local_94 != 0) {
      DAT_0067650c = 0;
    }
    return local_94;
  }
  Mem_AllocOrFree_004d9630(local_8c,arg_3);
  if ((DAT_0068f2c4 == 4) && (DAT_0068f2d8 == 1)) {
    DAT_00681eb4 = DAT_00666458;
    FUN_0048f1b1();
  }
  do {
    do {
      if (DAT_00666458 == 0) {
        DAT_00666440 = 1;
      }
      else if (x < 0) {
        DAT_00666440 = 2;
      }
      else {
        DAT_00666440 = 0;
      }
      if (DAT_0068f2d8 < 2) {
        DAT_0068ef98 = 0xffffffff;
      }
      DAT_00681ea4 = 0;
      DAT_00676500 = 0;
      local_98 = Pic_Subsystem_004458b0(DAT_00666458,local_8c);
      if (local_98 != 0) {
        DAT_0068f110 = 1;
      }
      if (((DAT_00666458 == DAT_00676510) && (local_98 != 0)) && (DAT_0066aaf4 != 1)) {
        local_94 = 1;
      }
      if ((DAT_0068f2d8 < DAT_0068ecc4) && (-1 < DAT_006764b8)) {
        local_98 = 0;
      }
    } while ((local_98 != 0) || (((DAT_00676500 & 1) != 0 && (DAT_0068f2d8 == 1))));
    if ((DAT_0068f2c4 == 4) && (DAT_0068f2d8 == 1)) {
      DAT_00681eb4 = 1 - DAT_00666458;
      FUN_0048f1b1();
    }
    while( true ) {
      if (DAT_00666458 == 0) {
        if (x < 0) {
          DAT_00666440 = 2;
        }
        else {
          DAT_00666440 = 0;
        }
      }
      else {
        DAT_00666440 = 1;
      }
      if (DAT_0068f2d8 < 2) {
        DAT_0068ef98 = 0xffffffff;
      }
      DAT_00681ea4 = 0;
      DAT_00676500 = 0;
      if (((DAT_0068f2d8 < DAT_0068ecc4) && (-1 < DAT_006764b8)) ||
         (iVar4 = Pic_Subsystem_004458b0(1 - DAT_00666458,local_8c), iVar4 == 0)) goto LAB_0048e800;
      DAT_0068f110 = 1;
      if (DAT_0066aaf4 != 1) break;
      if ((DAT_00666458 != DAT_00676510) && (((DAT_00676500 & 1) == 0 || (DAT_0068f2d8 != 1))))
      goto LAB_0048e800;
    }
  } while( true );
}


