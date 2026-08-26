/*
 * Decompiled function: CardInDeck
 * Entry Point: 00450869
 * Size: 44 bytes
 */
#include "duel.h"


uint CardInDeck(uint arg_1)

{
  uint uVar1;
  
                    /* 0x50869  2  CardInDeck */
  if (arg_1 == 0xffffffff) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = arg_1 & 0x4000;
  }
  return uVar1;
}


