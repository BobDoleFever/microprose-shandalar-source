/*
 * Decompiled function: Ai_Subsystem_004bf23a
 * Entry Point: 004bf23a
 * Size: 633 bytes
 */
#include "magic.h"


void Ai_Subsystem_004bf23a(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  DWORD DVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  
  iVar9 = DAT_00677fc0;
  iVar5 = DAT_00677e14;
  if (DAT_00522450 != -1) {
    iVar1 = DAT_0067bddc - DAT_00641020;
    if (DAT_0052f008 == 0) {
      uVar2 = Ai_Util_004c3bc4(0x23a);
      iVar3 = Ai_Util_004c3bc4(0x148);
      iVar4 = Ai_Util_004c3bc4(0x135);
      iVar3 = iVar3 - iVar4;
      DVar7 = *(DWORD *)(PTR_DAT_005174bc + 0x10);
      piVar11 = (int *)g_DisplaySurfaceBackBuffer;
      uVar8 = uVar2;
      iVar4 = Ai_Util_004c3bc4(0x280);
      FUN_0050dce0((int *)PTR_DAT_005174bc,uVar2,0,iVar4 - uVar2,DVar7,piVar11,uVar8,iVar3);
      iVar3 = DAT_00677e14;
      iVar4 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 6));
      iVar5 = Ai_Util_004c3bc4((int)*(short *)(iVar5 + 4));
      iVar10 = 0;
      iVar6 = Ai_Util_004c3bc4(0x181);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar6,iVar10,iVar5,iVar4,iVar3);
      iVar5 = (&DAT_00677fc0)[DAT_0067f37c & 7];
      iVar3 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 6));
      iVar4 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 4));
      iVar6 = Ai_Util_004c3bc4(0x15);
      iVar10 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar10,iVar6,iVar4,iVar3,iVar5);
      iVar5 = *(int *)(&DAT_00677f50 + ((DAT_0067bddc - DAT_00641020) % 0xe) * 4);
      iVar3 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 6));
      iVar4 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 4));
      iVar6 = Ai_Util_004c3bc4(0x15);
      iVar10 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar10,iVar6,iVar4,iVar3,iVar5);
      iVar5 = *(int *)(&DAT_00678360 + (((int)(iVar1 + (iVar1 >> 0x1f & 0xfU)) >> 4) + 1) * 4);
      iVar1 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 6));
      iVar3 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 4));
      iVar4 = Ai_Util_004c3bc4(0x15);
      iVar6 = Ai_Util_004c3bc4(0x23a);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar6,iVar4,iVar3,iVar1,iVar5);
      iVar5 = Ai_Util_004c3bc4(0x148);
      iVar1 = Ai_Util_004c3bc4(0x23a);
      piVar11 = (int *)g_DisplaySurfaceScreen;
      DVar7 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 6));
      uVar8 = Ai_Util_004c3bc4((int)*(short *)(iVar9 + 4));
      iVar9 = Ai_Util_004c3bc4(0x13);
      uVar2 = Ai_Util_004c3bc4(0x23a);
      FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,uVar2,iVar9,uVar8,DVar7,piVar11,iVar1,iVar5);
    }
  }
  return;
}


