/*
 * Decompiled function: FUN_0050b206
 * Entry Point: 0050b206
 * Size: 472 bytes
 */
#include "magic.h"


void FUN_0050b206(int arg_1,int arg_2,int arg_3,int arg_4,char *str_5)

{
  int xLeft;
  int yTop;
  int local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if (arg_4 == 0) {
    local_1c = Ai_Util_004c3ba3(0x30);
    local_20 = Ai_Util_004c3ba3(0x30);
  }
  else {
    local_1c = Ai_Util_004c3ba3(0x50);
    local_20 = Ai_Util_004c3ba3(0x70);
    if (0xf0 < arg_3 + 0x70) {
      arg_3 = 0x7f;
    }
  }
  xLeft = Ai_Util_004c3ba3(arg_2);
  yTop = Ai_Util_004c3ba3(arg_3);
  SetRect(&local_18,xLeft,yTop,local_1c + xLeft,local_20 + yTop);
  if (arg_4 == 0) {
    Palette_Subsystem_0049f8cd
              (*(HDC *)((&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen] + 4),&local_18.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + arg_1 * 0x34) * 0x98),0,
               1);
  }
  else {
    Palette_Subsystem_0049c7c7
              (*(HDC *)((&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen] + 4),&local_18.left,
               (WPARAM *)(&DAT_006b3070 + *(int *)(&g_MasterCardTypeTable + arg_1 * 0x34) * 0x98),0,
               1,1);
  }
  if ((str_5 != (char *)0x0) && (*str_5 != '\0')) {
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    local_8 = FUN_0040c465(str_5);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,((xLeft + local_1c / 2) - local_8 / 2) + -10,
                      yTop + -0x18,local_8 + 0x14,0x14,DAT_00678514);
    FUN_0040c3cc(str_5,xLeft + local_1c / 2,yTop + -0x14,0xff);
  }
  return;
}


