/*
 * Decompiled function: Ai_Subsystem_004b650c
 * Entry Point: 004b650c
 * Size: 161 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b650c(int x,int y,int *width,int *height)

{
  int iVar1;
  
  if (((width != (int *)0x0) && (height != (int *)0x0)) &&
     (iVar1 = Ai_Subsystem_004b5919(x,y), iVar1 == 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *width = (int)*(short *)(&DAT_0068a748 + y * 0x120 + x * 0x5b20);
    *height = (int)*(short *)(&DAT_0068a74a + y * 0x120 + x * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}


