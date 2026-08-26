/*
 * Decompiled function: Pic_Load_advfac64_00489188
 * Entry Point: 00489188
 * Size: 1192 bytes
 */
#include "magic.h"


void Pic_Load_advfac64_00489188(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *arg_1_00;
  DWORD DVar5;
  uint uVar6;
  int iVar7;
  uint arg_2_00;
  int iVar8;
  int *piVar9;
  int arg_6;
  char *str_6;
  int arg_7;
  void *pvVar10;
  char *str_7;
  HDC pHVar11;
  char local_20 [24];
  void *local_8;
  
  Mem_AllocOrFree_00510e20(1,s_prdfrmc_pic_00527ab4 + ((arg_4 != 0) - 1 & 0xc));
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  if (arg_4 != 0) {
    FUN_00488fdb((undefined4 *)g_DisplaySurfaceBackBuffer,1,0x15a,0xb3,0x23,s_prdblk_pic_00527adc,
                 s_advfac64_pic_00527acc);
  }
  Mem_AllocOrFree_0050fc00();
  local_8 = (void *)Sprite_EncodeFromSurface(1,1,0x15a,0xb3,0x23);
  FUN_0050fc20();
  iVar2 = DAT_00522458;
  iVar1 = Ai_Util_004c3bc4(0xb4);
  iVar8 = DAT_0052245c;
  arg_2_00 = iVar2 - iVar1;
  iVar2 = Ai_Util_004c3bc4(0xb4);
  iVar8 = iVar8 - iVar2;
  if (arg_5 == 1) {
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
  }
  pvVar10 = local_8;
  iVar1 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 6));
  iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 4));
  iVar2 = arg_3;
  iVar4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 4) / 2);
  Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_2 - iVar4,iVar2,iVar3,iVar1,(int)pvVar10);
  g_OverworldWorldState = 0;
  Adventure_FormatNewsString(arg_1,0,0);
  iVar2 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 6) / 2);
  FUN_0040d009((int)g_DisplaySurfaceScreen,(-(uint)(arg_4 == 0) & 0x38) + 0xae,arg_2,arg_3 + iVar2);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
  if (arg_5 == 1) {
    *(undefined4 *)g_DisplaySurfaceScreen = 0;
  }
  iVar2 = Ai_Util_004c3bc4(0xb4);
  iVar1 = Ai_Util_004c3bc4(0xb4);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,1,0xa5,0xb4,0xb4,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar8,iVar1,iVar2);
  sprintf(local_20,s_faces__03d_pic_00527ae8,arg_1);
  FUN_00510b70(1,0,DAT_0052245c + -0xf0,local_20,(short *)0x0);
  Mem_AllocOrFree_0050fc00();
  arg_1_00 = (void *)Sprite_EncodeFromSurface(1,0,DAT_0052245c + -0xf0,0x8a,0xaa);
  FUN_0050fc20();
  pvVar10 = arg_1_00;
  iVar2 = Ai_Util_004c3bc4(0xaa);
  iVar1 = Ai_Util_004c3bc4(0x8a);
  iVar3 = Ai_Util_004c3bc4(5);
  iVar3 = iVar8 + iVar3;
  iVar4 = Ai_Util_004c3bc4(0x15);
  Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_2_00 + iVar4,iVar3,iVar1,iVar2,
                    (int)pvVar10);
  if (arg_4 != 0) {
    str_7 = s_advfac64_pic_00527af8;
    str_6 = s_prdblk_pic_00527b08;
    iVar2 = Ai_Util_004c3bc4(0xb4);
    iVar1 = Ai_Util_004c3bc4(0xb4);
    FUN_00488fdb((undefined4 *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar8,iVar1,iVar2,str_6,str_7);
  }
  if (arg_5 == 0) {
    iVar2 = Ai_Util_004c3bc4(0x2d);
    iVar2 = arg_3 + iVar2;
    iVar1 = Ai_Util_004c3bc4(0x5a);
    iVar1 = arg_2 - iVar1;
    piVar9 = (int *)g_DisplaySurfaceScreen;
    DVar5 = Ai_Util_004c3bc4(0xb4);
    uVar6 = Ai_Util_004c3bc4(0xb4);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar8,uVar6,DVar5,piVar9,iVar1,iVar2);
  }
  else {
    iVar2 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
    iVar1 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
    iVar3 = Ai_Util_004c3bc4(0x2d);
    iVar3 = arg_3 + iVar3;
    iVar4 = Ai_Util_004c3bc4(0x5a);
    iVar4 = arg_2 - iVar4;
    piVar9 = (int *)g_DisplaySurfaceBackBuffer;
    DVar5 = Ai_Util_004c3bc4(0xb4);
    uVar6 = Ai_Util_004c3bc4(0xb4);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar8,uVar6,DVar5,piVar9,iVar4,iVar3);
    pHVar11 = *(HDC *)(iVar2 + 4);
    arg_7 = 3;
    arg_6 = 3;
    iVar8 = Ai_Util_004c3bc4(0xb4);
    iVar3 = Ai_Util_004c3bc4(0xb4);
    iVar4 = Ai_Util_004c3bc4(0x2d);
    iVar4 = arg_3 + iVar4;
    iVar7 = Ai_Util_004c3bc4(0x5a);
    FUN_005119e0(*(HDC *)(iVar1 + 4),arg_2 - iVar7,iVar4,iVar3,iVar8,arg_6,arg_7,pHVar11);
    if (arg_5 == 1) {
      pHVar11 = *(HDC *)(iVar2 + 4);
      iVar7 = 2;
      iVar4 = 2;
      iVar2 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 6));
      iVar8 = Ai_Util_004c3bc4(*(short *)((int)local_8 + 4) + -0x16);
      iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8 + 4) / 2 + -0xb);
      FUN_005119e0(*(HDC *)(iVar1 + 4),arg_2 - iVar3,arg_3,iVar8,iVar2,iVar4,iVar7,pHVar11);
    }
  }
  Mem_AllocOrFree_0050fc50(arg_1_00);
  Mem_AllocOrFree_0050fc50(local_8);
  return;
}


