/*
 * Decompiled function: FUN_00492cb1
 * Entry Point: 00492cb1
 * Size: 302 bytes
 */
#include "magic.h"


int FUN_00492cb1(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  int y;
  ushort local_3f4 [2];
  char local_3f0 [1000];
  int local_8;
  
  iVar1 = FUN_0050f440((int *)g_DisplaySurfaceScreen,(char *)&g_OverworldWorldState);
  iVar2 = Ai_Util_004c3bc4(0xbe);
  if (iVar2 < iVar1) {
    local_8 = FUN_0050f390(4,(char)local_3f4[0]);
    local_3f4[0] = (ushort)g_OverworldWorldState;
    iVar1 = arg1;
    iVar2 = arg2;
    y = Ai_Util_004c3ba3(0x10);
    FUN_0040c1ad(local_3f4,y,iVar1,iVar2);
    iVar1 = Ai_Util_004c3bc4(0xbe);
    FUN_00407843(&DAT_00626851,local_3f0,iVar1 - local_8);
    iVar1 = arg1;
    iVar2 = Ai_Util_004c3ba3(0x10);
    FUN_0040d1cd((int)g_DisplaySurfaceScreen,arg2,local_8 + iVar2,iVar1);
    iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    iVar1 = iVar1 * 2;
  }
  else {
    iVar1 = arg1;
    iVar2 = Ai_Util_004c3ba3(0x10);
    FUN_0040c1ad(&g_OverworldWorldState,iVar2,iVar1,arg2);
    iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  }
  arg1 = arg1 + iVar1;
  return arg1;
}


