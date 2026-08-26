/*
 * Decompiled function: Palette_Subsystem_00496f10
 * Entry Point: 00496f10
 * Size: 80 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_00496f10(void)

{
  ShowWindow(g_MainAppHwnd,0);
  ShowWindow(_hwndScreen,5);
  BringWindowToTop(_hwndScreen);
  SetFocus(_hwndScreen);
  DAT_0063ee18 = 0;
  return 0;
}


