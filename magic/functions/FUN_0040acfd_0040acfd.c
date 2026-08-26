/*
 * Decompiled function: FUN_0040acfd
 * Entry Point: 0040acfd
 * Size: 178 bytes
 */
#include "magic.h"


void FUN_0040acfd(char *arg_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
  iVar2 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
  FUN_00510b70(1,0,DAT_0052245c + -0x1e0,arg_1,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c + -0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c);
  FUN_005119e0(*(HDC *)(iVar2 + 4),0,0,DAT_00522458,DAT_0052245c,8,8,*(HDC *)(iVar1 + 4));
  return;
}


