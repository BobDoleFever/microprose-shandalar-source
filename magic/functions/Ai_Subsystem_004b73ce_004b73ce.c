/*
 * Decompiled function: Ai_Subsystem_004b73ce
 * Entry Point: 004b73ce
 * Size: 227 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b73ce(int x,int *y,int width,int *height)

{
  undefined4 uVar1;
  int local_8;
  
  if ((((x != 0) && (y != (int *)0x0)) && (width != 0)) && (height != (int *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
    *y = DAT_0069f740;
    for (local_8 = 0; local_8 < DAT_0069f740; local_8 = local_8 + 1) {
      uVar1 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006fec70 + local_8 * 4));
      *(undefined4 *)(x + local_8 * 4) = uVar1;
    }
    *height = DAT_00701004;
    for (local_8 = 0; local_8 < DAT_00701004; local_8 = local_8 + 1) {
      uVar1 = Ai_Subsystem_004cbd67(*(uint *)(&DAT_006ff6d0 + local_8 * 4));
      *(undefined4 *)(width + local_8 * 4) = uVar1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&g_ScreenDC);
  }
  return;
}


