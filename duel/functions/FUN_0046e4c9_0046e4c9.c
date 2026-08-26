/*
 * Decompiled function: FUN_0046e4c9
 * Entry Point: 0046e4c9
 * Size: 168 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0046e4c9(int x,int y,int width,undefined4 arg_4)

{
  undefined4 uVar1;
  
  if ((width == 0x7d) &&
     ((((&DAT_006826cd)[y * 0x120 + x * 0x5b20] & 1) != 0 || (DAT_006663f4 != 0)))) {
    uVar1 = 0;
  }
  else if (DAT_0068f230 < 200) {
    uVar1 = 0;
  }
  else {
    DAT_0066642c = 0;
    DAT_0068ecb0 = x;
    DAT_00690c48 = y;
    _DAT_0068ee68 = arg_4;
    DAT_0068ecfc = 0xffffffff;
    Magic_ScanCards(width);
    uVar1 = DAT_0066642c;
  }
  return uVar1;
}


