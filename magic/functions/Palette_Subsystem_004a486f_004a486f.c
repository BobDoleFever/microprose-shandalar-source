/*
 * Decompiled function: Palette_Subsystem_004a486f
 * Entry Point: 004a486f
 * Size: 472 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a486f(int arg1,int arg2)

{
  int iVar1;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  Palette_Subsystem_004a554b(DAT_0054bd28,DAT_0054bd2c,&local_10,&local_14);
  for (local_c = 1; (int)local_c <= (int)((-(uint)(arg2 == 0) & 4) + 4); local_c = local_c + 1) {
    iVar1 = local_10 - DAT_00678430 / 2;
    local_8 = local_14 - DAT_006779d0;
    FUN_0040c5d9(g_DisplaySurfaceBackBuffer,iVar1 / 2,local_8 / 2,DAT_00678430 / 2,DAT_006784b0 / 2,
                 g_DisplaySurfaceScreen,iVar1 / 2,local_8 / 2);
    iVar1 = Ai_Util_004c3bc4(local_10);
    iVar1 = iVar1 - DAT_00678430 / 2;
    local_8 = Ai_Util_004c3bc4(local_14);
    local_8 = local_8 - DAT_006779d0;
    if (local_c == 8) {
      local_1c = 0;
    }
    else {
      local_1c = (local_c & 3) + 1;
    }
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1,local_8,
                      (&DAT_00679424)[DAT_0052c2a0 * 5 + local_1c]);
    if (local_c == 8) {
      local_20 = 0;
    }
    else {
      local_20 = (local_c & 3) + 1;
    }
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar1,local_8,
                      (&DAT_00679370)[DAT_0052c2a0 * 5 + local_20]);
    local_10 = local_10 +
               ((int)((&DAT_0052237c)[arg1 - 2U & 7] * 0x10 +
                     ((&DAT_0052237c)[arg1 - 2U & 7] * 0x10 >> 0x1f & 3U)) >> 2);
    local_14 = local_14 +
               ((int)((&DAT_005223e4)[arg1 - 2U & 7] * 0x10 +
                     ((&DAT_005223e4)[arg1 - 2U & 7] * 0x10 >> 0x1f & 7U)) >> 3);
    FUN_00501736(5);
    FUN_0040a3e1();
  }
  return;
}


