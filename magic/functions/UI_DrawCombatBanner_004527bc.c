/*
 * Decompiled function: UI_DrawCombatBanner
 * Entry Point: 004527bc
 * Size: 80 bytes
 */
#include "magic.h"


void UI_DrawCombatBanner(void)

{
  Pic_Subsystem_0044b8da();
  Surface_FillRect((int *)g_DisplaySurfaceScreen,200,0x3c,0xf0,0x118,0xbc);
  FUN_0040c3cc(s_COMBAT_00523f00,0x140,0xc4,0xff);
  return;
}


