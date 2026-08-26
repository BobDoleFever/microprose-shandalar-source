/*
 * Decompiled function: Color_QuantizeRGBToPalette
 * Entry Point: 00494310
 * Size: 105 bytes
 */
#include "magic.h"


void Color_QuantizeRGBToPalette(uint arg1,uint *arg2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (arg1 & 0xff0000) >> 0x10;
  uVar1 = *(uint *)(&DAT_0064a8c4 + uVar4 * 8);
  uVar5 = (arg1 & 0xff00) >> 5;
  uVar2 = *(uint *)(&DAT_00673aa4 + uVar5);
  uVar3 = *(uint *)(&DAT_006752c4 + (arg1 & 0xff) * 8);
  *arg2 = *(uint *)(&DAT_0064a8c0 + uVar4 * 8) | *(uint *)(&DAT_00673aa0 + uVar5) |
          *(uint *)(&DAT_006752c0 + (arg1 & 0xff) * 8);
  arg2[1] = uVar1 | uVar2 | uVar3;
  return;
}


