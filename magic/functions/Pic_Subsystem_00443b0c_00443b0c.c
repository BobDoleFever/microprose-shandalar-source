/*
 * Decompiled function: Pic_Subsystem_00443b0c
 * Entry Point: 00443b0c
 * Size: 87 bytes
 */
#include "magic.h"


WPARAM Pic_Subsystem_00443b0c(void)

{
  DWORD _Seed;
  WPARAM wParam;
  
  _Seed = GetTickCount();
  srand(_Seed);
  Ai_Subsystem_004cd3eb();
  wParam = Pic_Subsystem_0044f1de(0,DAT_006a49e8);
  PostMessageA(g_MainAppHwnd,0x401,wParam,0);
  return wParam;
}


