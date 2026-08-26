/*
 * Decompiled function: FUN_004706d0
 * Entry Point: 004706d0
 * Size: 93 bytes
 */
#include "duel.h"


bool FUN_004706d0(void)

{
  if (DAT_004f9780 == 0) {
    FUN_004707f3(10,10,&DAT_004f9780,(BITMAPINFO *)0x0,&DAT_00522460,(undefined4 *)0x0,(int *)0x0);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_005224a8);
  }
  return DAT_004f9780 != 0;
}


