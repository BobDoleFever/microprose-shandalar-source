/*
 * Decompiled function: Palette_Subsystem_00495829
 * Entry Point: 00495829
 * Size: 136 bytes
 */
#include "magic.h"


void Palette_Subsystem_00495829(void)

{
  undefined4 local_8;
  
  Mem_AllocOrFree_004f6b02();
  Mem_AllocOrFree_004f6d88();
  FUN_004f48cb();
  FUN_004f3b2c(g_HdcBackBuffer,DAT_006ff384);
  DAT_006ff384 = (HGDIOBJ)0x0;
  g_HdcBackBuffer = (HDC)0x0;
  FUN_004f38dd();
  Palette_Subsystem_0049b8f5();
  FUN_00478a56();
  for (local_8 = 0; local_8 < DAT_006a49f4; local_8 = local_8 + 1) {
    FUN_0046c1b3(local_8);
  }
  FUN_0046c859();
  return;
}


