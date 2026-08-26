/*
 * Decompiled function: FUN_0040bcff
 * Entry Point: 0040bcff
 * Size: 1147 bytes
 */
#include "magic.h"


void FUN_0040bcff(uint arg1,uint arg2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (DAT_005384dc == -1) {
    DAT_005384dc = arg1;
    DAT_005384e0 = arg2;
    Ai_Subsystem_004c3aa1(arg1,arg2,(int *)&local_c,(int *)&local_14);
    local_c = (int)(local_c * DAT_00522458) / 0x280;
    local_14 = (int)(local_14 * DAT_0052245c) / 0x1e0;
    iVar1 = Ai_Util_004c3bc4(0x40);
    local_14 = local_14 + iVar1;
  }
  else {
    Ai_Subsystem_004c3aa1(DAT_005384dc,DAT_005384e0,(int *)&local_8,(int *)&local_10);
    local_8 = (int)(local_8 * DAT_00522458) / 0x280;
    local_10 = (int)(local_10 * DAT_0052245c) / 0x1e0;
    iVar1 = Ai_Util_004c3bc4(0x40);
    local_10 = local_10 + iVar1;
    Ai_Subsystem_004c3aa1(arg1,arg2,(int *)&local_c,(int *)&local_14);
    local_c = (int)(local_c * DAT_00522458) / 0x280;
    local_14 = (int)(local_14 * DAT_0052245c) / 0x1e0;
    iVar1 = Ai_Util_004c3bc4(0x40);
    local_14 = local_14 + iVar1;
    DAT_005384dc = arg1;
    DAT_005384e0 = arg2;
    iVar1 = local_c - local_8;
    iVar4 = local_14 - local_10;
    arg1 = local_8;
    arg2 = local_10;
    iVar2 = abs(iVar4);
    iVar3 = abs(iVar1);
    if (iVar2 < iVar3) {
      while (local_c != arg1) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,arg1,arg2,2,2,0xff);
        FUN_00501736(5);
        if ((arg1 & 1) == 0) {
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg1,arg2,2,2,(int *)g_DisplaySurfaceScreen
                       ,arg1,arg2);
        }
        else {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,arg1,arg2,2,2,0);
        }
        iVar2 = FUN_0040a33c(iVar1);
        arg1 = arg1 + iVar2;
        iVar2 = abs(arg1 - local_8);
        iVar3 = abs(iVar1);
        arg2 = local_10 + (iVar2 * iVar4) / iVar3;
      }
    }
    else {
      while (local_14 != arg2) {
        Surface_FillRect((int *)g_DisplaySurfaceScreen,arg1,arg2,2,2,0xff);
        FUN_00501736(5);
        if ((arg2 & 1) == 0) {
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg1,arg2,2,2,(int *)g_DisplaySurfaceScreen
                       ,arg1,arg2);
        }
        else {
          Surface_FillRect((int *)g_DisplaySurfaceScreen,arg1,arg2,2,2,0);
        }
        iVar2 = FUN_0040a33c(iVar4);
        arg2 = arg2 + iVar2;
        iVar2 = abs(arg2 - local_10);
        iVar3 = abs(iVar4);
        arg1 = local_8 + (iVar2 * iVar1) / iVar3;
      }
    }
  }
  DAT_005384c8 = local_c;
  DAT_005384cc = local_14;
  if (g_OverworldWorldState != '\0') {
    FUN_0040a305(local_c - 0x50,0,0xa0);
    FUN_0040a305(local_14 - 10,0,0xbf);
    iVar1 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
    iVar4 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    *(undefined4 *)(g_DisplaySurfaceWork + 0x20) = *(undefined4 *)(g_DisplaySurfaceScreen + 0x20);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,(local_c - 2) - iVar1 / 2,local_14 - 2,iVar1 + 2,
                 iVar4 + 2,(int *)g_DisplaySurfaceWork,0,0xa0);
    Ai_Subsystem_004c2340((undefined4 *)g_DisplaySurfaceWork,0,0xa0,iVar1 + 2,iVar4 + 2,0x3f3f3f,1);
    FUN_0040d269((int)g_DisplaySurfaceWork,0xff,iVar1 / 2 + 1,iVar4 / 2 + 0xa1);
    FUN_0050dce0((int *)g_DisplaySurfaceWork,0,0xa0,iVar1 + 2,iVar4 + 2,
                 (int *)g_DisplaySurfaceScreen,(local_c - 2) - iVar1 / 2,local_14 - 2);
  }
  return;
}


