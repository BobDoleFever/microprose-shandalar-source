/*
 * Decompiled function: Town_Process_00508c3e
 * Entry Point: 00508c3e
 * Size: 153 bytes
 */
#include "magic.h"


void Town_Process_00508c3e(void)

{
  if (DAT_006265f4 <= Gold) {
    DAT_00522448 = DAT_00522448 + 10;
    Gold = Gold - DAT_006265f4;
  }
  Ai_Subsystem_004c3c5c(1);
  *(undefined4 *)g_DisplaySurfaceScreen = 1;
  FUN_0040a883(s_village_pic_0053201c +
               ((*(int *)(&DAT_0067bdf0 + DAT_0061e0d4 * 100) == 1) - 1 & 0xc));
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  FUN_00507b44(0x53173c,1);
  return;
}


