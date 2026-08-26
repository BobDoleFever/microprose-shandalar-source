/*
 * Decompiled function: Pic_Load_004244a0
 * Entry Point: 004244a0
 * Size: 81 bytes
 */
#include "magic.h"


void Pic_Load_004244a0(void)

{
  Mem_AllocOrFree_00510de0(1,s_hallback_pic_00520d58);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  Ai_Subsystem_004cd1d1();
  return;
}


