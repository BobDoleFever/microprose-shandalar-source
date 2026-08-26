/*
 * Decompiled function: FUN_00409c73
 * Entry Point: 00409c73
 * Size: 63 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00409c73(undefined4 arg_1)

{
  _DAT_005382f8 = 0;
  _DAT_005382fc = arg_1;
  _DAT_00538300 = 0xffffffff;
  PostMessageA(g_MainAppHwnd,0x464,0,0x5382f8);
  return;
}


