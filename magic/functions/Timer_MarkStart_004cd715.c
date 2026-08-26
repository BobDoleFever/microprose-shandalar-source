/*
 * Decompiled function: Timer_MarkStart
 * Entry Point: 004cd715
 * Size: 21 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Timer_MarkStart(void)

{
  _DAT_00565728 = Timer_GetTicks();
  return;
}


