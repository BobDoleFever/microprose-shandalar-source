/*
 * Decompiled function: Palette_Subsystem_00496f60
 * Entry Point: 00496f60
 * Size: 68 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_00496f60(void)

{
  DAT_0063ee18 = 1;
  ShowWindow(_hwndScreen,0);
  ShowWindow(g_MainAppHwnd,5);
  SetFocus(g_MainAppHwnd);
  return 0;
}


