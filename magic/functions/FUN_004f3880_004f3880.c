/*
 * Decompiled function: FUN_004f3880
 * Entry Point: 004f3880
 * Size: 93 bytes
 */
#include "magic.h"


bool FUN_004f3880(void)

{
  if (DAT_00530180 == 0) {
    FUN_004f39a4(10,10,&DAT_00530180,(BITMAPINFO *)0x0,&DAT_0061d7f0,(undefined4 *)0x0,(int *)0x0);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
  }
  return DAT_00530180 != 0;
}


