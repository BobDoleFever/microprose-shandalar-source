/*
 * Decompiled function: FUN_0048e32b
 * Entry Point: 0048e32b
 * Size: 218 bytes
 */
#include "duel.h"


undefined4 FUN_0048e32b(int x,int arg_2,undefined4 arg_3,undefined4 arg_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_0068eee4;
  if (((DAT_006764b8 == 0) && (iVar2 = FUN_0042a99c(), iVar2 != 0)) && (x != -2)) {
    DAT_0068eee4 = 1;
  }
  do {
    DAT_0068f110 = 0;
    uVar3 = FUN_0048e405(x,arg_2,arg_3,arg_4);
    if ((DAT_0068f110 == 0) || (0 < DAT_006764b8)) break;
  } while (DAT_0066aaf4 != 1);
  DAT_0068eee4 = uVar1;
  if (DAT_006764b8 == 0) {
    DAT_0068eee4 = 0;
    *(uint *)(&DAT_006667c0 + DAT_00666458 * 0x98 + DAT_0068f2c4 * 4) =
         *(uint *)(&DAT_006667c0 + DAT_00666458 * 0x98 + DAT_0068f2c4 * 4) & 0xfffffffd;
  }
  return uVar3;
}


