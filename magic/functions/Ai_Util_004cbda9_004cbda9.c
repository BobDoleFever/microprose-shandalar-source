/*
 * Decompiled function: Ai_Util_004cbda9
 * Entry Point: 004cbda9
 * Size: 44 bytes
 */
#include "magic.h"


uint Ai_Util_004cbda9(uint arg_1)

{
  uint uVar1;
  
                    /* 0xcbda9  2  CardInDeck */
  if (arg_1 == 0xffffffff) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = arg_1 & 0x4000;
  }
  return uVar1;
}


