/*
 * Decompiled function: Timer_GetElapsedFraction
 * Entry Point: 004cd72a
 * Size: 53 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Timer_GetElapsedFraction(void)

{
  int iVar1;
  
  iVar1 = Timer_GetTicks();
  return ((iVar1 - _DAT_00565728) * 100) / 0x151d;
}


