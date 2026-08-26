/*
 * Decompiled function: FUN_0050b3de
 * Entry Point: 0050b3de
 * Size: 480 bytes
 */
#include "magic.h"


void FUN_0050b3de(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,char *str_7)

{
  int xLeft;
  int yTop;
  tagRECT local_18;
  int local_8;
  
  if (arg_6 == 0) {
    arg_4 = Ai_Util_004c3ba3(arg_4);
    arg_5 = Ai_Util_004c3ba3(arg_5);
  }
  else {
    arg_4 = Ai_Util_004c3ba3(arg_4);
    arg_5 = Ai_Util_004c3ba3(arg_5);
    if (0xf0 < arg_3 + 0x70) {
      arg_3 = 0x7f;
    }
  }
  xLeft = Ai_Util_004c3ba3(arg_2);
  yTop = Ai_Util_004c3ba3(arg_3);
  SetRect(&local_18,xLeft,yTop,arg_4 + xLeft,arg_5 + yTop);
  if (arg_6 == 0) {
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
  if ((str_7 != (char *)0x0) && (*str_7 != '\0')) {
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    local_8 = FUN_0040c465(str_7);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,((xLeft + arg_4 / 2) - local_8 / 2) + -10,
                      yTop + -0x18,local_8 + 0x14,0x14,DAT_00678514);
    FUN_0040c3cc(str_7,xLeft + arg_4 / 2,yTop + -0x14,0xff);
  }
  return;
}


