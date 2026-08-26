/*
 * Decompiled function: Ai_Subsystem_004cbdda
 * Entry Point: 004cbdda
 * Size: 54 bytes
 */
#include "magic.h"


void Ai_Subsystem_004cbdda(int arg1,int arg2)

{
                    /* 0xcbdda  8  SetCardInDeck */
  if (arg2 == 1) {
    *(uint *)(&deck + arg1 * 4) = *(uint *)(&deck + arg1 * 4) | 0x4000;
  }
  else {
    *(uint *)(&deck + arg1 * 4) = *(uint *)(&deck + arg1 * 4) & 0x8fff;
  }
  return;
}


