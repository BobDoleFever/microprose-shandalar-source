/*
 * Decompiled function: FUN_00437b05
 * Entry Point: 00437b05
 * Size: 135 bytes
 */
#include "duel.h"


void FUN_00437b05(void)

{
  undefined4 local_8;
  
  Mem_AllocOrFree_0043ce47();
  Mem_AllocOrFree_0043d0c9();
  FUN_00471717();
  FUN_0047097b(DAT_0060157c,DAT_00664c00);
  DAT_00664c00 = (HGDIOBJ)0x0;
  DAT_0060157c = (HDC)0x0;
  FUN_0047072d();
  Palette_Color_0049ae00();
  FUN_00486bc3();
  for (local_8 = 0; local_8 < DAT_0061743c; local_8 = local_8 + 1) {
    FUN_00438e72(local_8);
  }
  FUN_00439516();
  return;
}


