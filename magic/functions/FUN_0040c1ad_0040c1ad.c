/*
 * Decompiled function: FUN_0040c1ad
 * Entry Point: 0040c1ad
 * Size: 199 bytes
 */
#include "magic.h"


void FUN_0040c1ad(char *arg_1,int y,int width,undefined4 arg_4)

{
  int iVar1;
  int iVar2;
  
  if (y < 0) {
    y = 0;
  }
  if (width < 0) {
    width = 0;
  }
  iVar1 = FUN_0040c465(arg_1);
  if (DAT_00522458 <= y + iVar1) {
    iVar2 = DAT_00522458 + -1;
    iVar1 = FUN_0040c465(arg_1);
    y = iVar2 - iVar1;
  }
  iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  if (DAT_0052245c <= width + iVar1) {
    iVar2 = DAT_0052245c + -1;
    iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    width = iVar2 - iVar1;
  }
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x18) = arg_4;
  FUN_0050f820((int *)g_DisplaySurfaceScreen,y,width,arg_1);
  return;
}


