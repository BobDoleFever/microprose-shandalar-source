/*
 * Decompiled function: Ai_Subsystem_004c05ba
 * Entry Point: 004c05ba
 * Size: 293 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004c05ba(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  DWORD DVar4;
  int *piVar5;
  int arg_7;
  int arg_8;
  
  DAT_00558dc8 = 0xffffffff;
  _DAT_0052d774 = 0xffffffff;
  DAT_0052d778 = 1;
  if (g_IsAiThinking == 0) {
    Mem_AllocOrFree_00510e20(1,PTR_s_advinter800_pic_00530d98);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                 (int *)g_DisplaySurfaceScreen,0,0);
    FUN_0041f2af(0,4);
  }
  DAT_00641884 = 0;
  if (DAT_005574a4 == 0) {
    arg_8 = 0;
    arg_7 = 0;
    piVar5 = (int *)PTR_DAT_005174bc;
    iVar1 = Ai_Util_004c3bc4(0x1e0);
    iVar2 = Ai_Util_004c3bc4(0x148);
    DVar4 = iVar1 - iVar2;
    uVar3 = Ai_Util_004c3bc4(0x280);
    iVar1 = Ai_Util_004c3bc4(0x148);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,iVar1,uVar3,DVar4,piVar5,arg_7,arg_8);
    iVar2 = 0;
    iVar1 = 0;
    piVar5 = (int *)PTR_DAT_005174e4;
    DVar4 = Ai_Util_004c3bc4(0x148);
    uVar3 = Ai_Util_004c3bc4(0x40);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,uVar3,DVar4,piVar5,iVar1,iVar2);
    DAT_005574a4 = 1;
  }
  return;
}


