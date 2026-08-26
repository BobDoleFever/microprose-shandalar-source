/*
 * Decompiled function: Ai_Subsystem_004be357
 * Entry Point: 004be357
 * Size: 109 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004be357(void)

{
  int local_8;
  
  for (local_8 = DAT_00556c64; local_8 != -1; local_8 = *(int *)(&DAT_00558dd8 + local_8 * 4)) {
    Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,
                       *(int *)(&DAT_00557cc0 + local_8 * 4) - _DAT_006498d0,
                       *(int *)(&DAT_005584c0 + local_8 * 4) - DAT_006498d4,
                       *(int *)(&DAT_005574c0 + local_8 * 4));
  }
  return;
}


