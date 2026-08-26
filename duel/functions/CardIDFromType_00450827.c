/*
 * Decompiled function: CardIDFromType
 * Entry Point: 00450827
 * Size: 61 bytes
 */
#include "duel.h"


undefined4 CardIDFromType(uint arg_1)

{
  undefined4 uVar1;
  
                    /* 0x50827  1  CardIDFromType */
  if (arg_1 == 0xffffffff) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_004ff590 + (arg_1 & 0xfff) * 0x34);
  }
  return uVar1;
}


