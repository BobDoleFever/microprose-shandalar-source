/*
 * Decompiled function: FUN_0040a883
 * Entry Point: 0040a883
 * Size: 218 bytes
 */
#include "magic.h"


void FUN_0040a883(char *arg_1)

{
  uint arg_2;
  int arg_8;
  uint arg_4;
  DWORD arg_5;
  
  arg_2 = Ai_Util_004c3bc4(0x40);
  arg_8 = Ai_Util_004c3bc4(0x30);
  arg_4 = Ai_Util_004c3bc4(0x200);
  arg_5 = Ai_Util_004c3bc4(0x118);
  FUN_00510b70(1,0,DAT_0052245c + -0x118,arg_1,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_8,arg_4,arg_5);
  FUN_0050b9d5(g_DisplaySurfaceBackBuffer);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2,arg_8,arg_4,arg_5,
               (int *)g_DisplaySurfaceScreen,arg_2,arg_8);
  return;
}


