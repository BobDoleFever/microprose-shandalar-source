/*
 * Decompiled function: FUN_0040abf9
 * Entry Point: 0040abf9
 * Size: 260 bytes
 */
#include "magic.h"


void FUN_0040abf9(char *arg_1)

{
  int iVar1;
  int iVar2;
  int arg_7;
  int arg_8;
  int arg_9;
  int arg_10;
  
  arg_7 = Ai_Util_004c3bc4(0x40);
  arg_8 = Ai_Util_004c3bc4(0x30);
  arg_9 = Ai_Util_004c3bc4(0x200);
  arg_10 = Ai_Util_004c3bc4(0x118);
  iVar1 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
  iVar2 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
  FUN_00510b70(1,0,DAT_0052245c + -0x118,arg_1,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c + -0x118,0x200,0x118,
                     (int *)g_DisplaySurfaceBackBuffer,arg_7,arg_8,arg_9,arg_10);
  FUN_0050b9d5(g_DisplaySurfaceBackBuffer);
  FUN_005119e0(*(HDC *)(iVar2 + 4),arg_7,arg_8,arg_9,arg_10,5,5,*(HDC *)(iVar1 + 4));
  FUN_00501736(0x2d);
  return;
}


