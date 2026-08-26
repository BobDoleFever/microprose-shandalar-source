/*
 * Decompiled function: SetCardInDeck
 * Entry Point: 0045089a
 * Size: 54 bytes
 */
#include "duel.h"


void SetCardInDeck(int arg1,int arg2)

{
                    /* 0x5089a  6  SetCardInDeck */
  if (arg2 == 1) {
    *(uint *)(&deck + arg1 * 4) = *(uint *)(&deck + arg1 * 4) | 0x4000;
  }
  else {
    *(uint *)(&deck + arg1 * 4) = *(uint *)(&deck + arg1 * 4) & 0x8fff;
  }
  return;
}


