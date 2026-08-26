/*
 * Decompiled function: FUN_0050b65f
 * Entry Point: 0050b65f
 * Size: 865 bytes
 */
#include "magic.h"


void FUN_0050b65f(int arg_1,int arg_2,int arg_3,int arg_4,char *str_5)

{
  int arg_3_00;
  int arg_6;
  int iVar1;
  uint arg_2_00;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int arg_2_01;
  int arg_3_01;
  int local_10;
  
  bVar5 = arg_4 == 2;
  arg_2_00 = arg_1 - 0x2b;
  arg_3_00 = arg_2 + -0x26;
  switch(arg_4) {
  case 0:
    arg_4 = 0;
    break;
  case 1:
    arg_4 = 1;
    break;
  case 2:
    arg_4 = 1;
    break;
  case 3:
    return;
  }
  if (bVar5) {
    Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_1 + -0x21,arg_2 + -0x1e,
                      *(short *)(*(int *)(&DAT_00678390 + arg_3 * 4) + 4) + -4,
                      *(short *)(*(int *)(&DAT_00678390 + arg_3 * 4) + 6) + -2,
                      *(int *)(&DAT_00678390 + arg_3 * 4));
    iVar3 = *(int *)(&DAT_00678260 + arg_4 * 0x10);
    Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_1 + -0x29,arg_2 + -0x24,
                      *(short *)(iVar3 + 4) + -4,*(short *)(iVar3 + 6) + -2,
                      *(int *)(&DAT_00678260 + arg_4 * 0x10));
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2_00,arg_3_00,(int)*(short *)(iVar3 + 4),
                 (int)*(short *)(iVar3 + 6),(int *)g_DisplaySurfaceScreen,arg_2_00,arg_3_00);
  }
  else {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_1 + -0x23,arg_2 + -0x20,
                      *(int *)(&DAT_00678390 + arg_3 * 4));
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00,arg_3_00,
                      *(int *)(&DAT_00678260 + arg_4 * 0x10));
  }
  if (DAT_006265f0 != 0) {
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    iVar3 = Ai_Util_004c3bc4(8);
    iVar2 = iVar2 + iVar3;
    iVar3 = *(int *)(&DAT_00678268 + arg_4 * 0x10);
    arg_6 = *(int *)(&DAT_00678264 + arg_4 * 0x10);
    iVar1 = *(int *)(arg_4 * 0x10 + 0x67826c);
    arg_3_01 = 999;
    arg_2_01 = 0x60;
    iVar4 = FUN_0040c465(str_5);
    iVar4 = FUN_0040a305(iVar4 + 0x20,arg_2_01,arg_3_01);
    for (local_10 = 0; local_10 < (int)(iVar4 + (iVar4 >> 0x1f & 0x3fU)) >> 6;
        local_10 = local_10 + 1) {
      Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(arg_1 - iVar4 / 2) + local_10 * 0x40,
                        arg_2 + 0x12,0x40,iVar2,arg_6);
    }
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_1 + iVar4 / 2 + -0x40,arg_2 + 0x12,0x40,
                      iVar2,*(int *)(&DAT_00678264 + arg_4 * 0x10));
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(arg_1 - iVar4 / 2) + -8,arg_2 + 0x12,
                      (int)*(short *)(iVar3 + 4),iVar2,*(int *)(&DAT_00678268 + arg_4 * 0x10));
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,arg_1 + iVar4 / 2,arg_2 + 0x12,
                      (int)*(short *)(iVar1 + 4),iVar2,*(int *)(arg_4 * 0x10 + 0x67826c));
    FUN_0040d009((int)g_DisplaySurfaceScreen,0xff,arg_1,arg_3_00 + iVar2 / 2 + 0x38);
  }
  return;
}


