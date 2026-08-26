/*
 * Decompiled function: FUN_100060dd
 * Entry Point: 100060dd
 * Size: 119 bytes
 */
#include "magvid.h"


void __cdecl FUN_100060dd(HWND hwnd)

{
  HMENU pHVar1;
  
  DAT_1001bf38 = (uint32_t)(DAT_1001bf38 == 0);
  pHVar1 = GetMenu(hwnd);
  pHVar1 = GetSubMenu(pHVar1,1);
  CheckMenuItem(pHVar1,0x9c55,(DAT_1001bf38 == 0) - 1 & 8);
  return;
}


