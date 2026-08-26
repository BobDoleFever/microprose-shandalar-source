/*
 * Decompiled function: Palette_Subsystem_004a5f7c
 * Entry Point: 004a5f7c
 * Size: 96 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a5f7c(void)

{
  undefined4 arg2;
  
  arg2 = FUN_0050d0b0(9,DAT_00522458,0x81,8);
  FUN_0050d370(9,arg2);
  *(undefined4 *)(PTR_DAT_0052c2ec + 0x20) = 1;
  FUN_0050dce0((int *)g_DisplaySurfaceWork,0,0,DAT_00522458,0x80,(int *)PTR_DAT_0052c2ec,0,0);
  return;
}


