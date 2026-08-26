/*
 * Decompiled function: FUN_0048a3cc
 * Entry Point: 0048a3cc
 * Size: 803 bytes
 */
#include "magic.h"


void FUN_0048a3cc(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int arg_2_00;
  int arg_3_00;
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  iVar1 = (int)(arg_3 + 0x17 + (arg_3 + 0x17 >> 0x1f & 0xfU)) >> 4;
  iVar2 = (int)(arg_4 + 0x17 + (arg_4 + 0x17 >> 0x1f & 0xfU)) >> 4;
  arg_2_00 = (arg_1 + -4) - (iVar1 * 0x10 - (arg_3 + 8)) / 2;
  arg_3_00 = (arg_2 + -4) - (iVar2 * 0x10 - (arg_4 + 8)) / 2;
  *(undefined4 *)g_DisplaySurfaceScreen = 1;
  Surface_FillRect((int *)g_DisplaySurfaceScreen,arg_2_00,arg_3_00,iVar1 << 4,iVar2 << 4,0xe3);
  for (local_c = 0; local_c < iVar2; local_c = local_c + 1) {
    for (local_8 = 0; local_8 < iVar1; local_8 = local_8 + 1) {
      Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_8 * 0x10 + arg_2_00,
                        local_c * 0x10 + arg_3_00,(&DAT_006781d0)[arg_5 * 9]);
    }
  }
  for (local_8 = 0; local_8 < iVar1; local_8 = local_8 + 1) {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_8 * 0x10 + arg_2_00,arg_3_00 + -10,
                      *(int *)(&DAT_006781e4 + arg_5 * 0x24));
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_8 * 0x10 + arg_2_00,
                      iVar2 * 0x10 + arg_3_00 + -6,*(int *)(&DAT_006781ec + arg_5 * 0x24));
  }
  for (local_c = 0; local_c < iVar2; local_c = local_c + 1) {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00 + -10,local_c * 0x10 + arg_3_00,
                      *(int *)(&DAT_006781f0 + arg_5 * 0x24));
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1 * 0x10 + arg_2_00 + -6,
                      local_c * 0x10 + arg_3_00,*(int *)(&DAT_006781e8 + arg_5 * 0x24));
  }
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00 + -10,arg_3_00 + -10,
                    *(int *)(&DAT_006781d4 + arg_5 * 0x24));
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1 * 0x10 + arg_2_00 + -6,arg_3_00 + -10,
                    *(int *)(&DAT_006781d8 + arg_5 * 0x24));
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,arg_2_00 + -10,iVar2 * 0x10 + arg_3_00 + -6,
                    *(int *)(&DAT_006781dc + arg_5 * 0x24));
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1 * 0x10 + arg_2_00 + -6,
                    iVar2 * 0x10 + arg_3_00 + -6,*(int *)(&DAT_006781e0 + arg_5 * 0x24));
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2_00 - 10,arg_3_00 + -10,iVar1 * 0x10 + 0x14,
               iVar2 * 0x10 + 0x14,(int *)g_DisplaySurfaceScreen,arg_2_00 + -10,arg_3_00 + -10);
  return;
}


