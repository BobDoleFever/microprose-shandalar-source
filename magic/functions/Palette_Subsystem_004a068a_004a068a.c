/*
 * Decompiled function: Palette_Subsystem_004a068a
 * Entry Point: 004a068a
 * Size: 385 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a068a(int x,int y,int width,int height)

{
  int local_68;
  int local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  int local_54;
  int local_50;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  tagRECT local_30;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  if ((x == 0) || (y == 0)) {
    local_5c = 0;
  }
  else if ((width < 0) || (0x16 < width)) {
    local_5c = 0;
  }
  else if (DAT_0054b734 == (HANDLE)0x0) {
    local_5c = 0;
  }
  else {
    Palette_Subsystem_004a080b(&local_30,(int *)y,height);
    GetObjectA(DAT_0054b734,0x18,local_58);
    local_34 = local_54;
    local_40 = local_50 / 0x18;
    local_20 = local_30.bottom - local_30.top;
    local_18 = (local_54 * local_20) / local_40;
    local_68 = local_18;
    if (1 < height) {
      local_68 = ((local_30.right - local_30.left) - local_18) / (height + -1);
    }
    local_1c = width * local_40;
    local_38 = local_50 - local_40;
    local_60 = local_30.right - local_18;
    for (local_3c = 0; local_3c < height; local_3c = local_3c + 1) {
      SetRect(&local_14,local_60,local_30.top,local_18 + local_60,local_20 + local_30.top);
      FUN_004f3eaa((HDC)x,&local_14.left,DAT_0054b734,local_34,local_40,0,local_1c,0,local_38);
      local_60 = local_60 - local_68;
    }
    local_5c = 1;
  }
  return local_5c;
}


