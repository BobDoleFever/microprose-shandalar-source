/*
 * Decompiled function: Palette_Subsystem_004a0f97
 * Entry Point: 004a0f97
 * Size: 611 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a0f97(LPRECT arg_1,uint y,int *width,uint height)

{
  undefined1 local_94 [4];
  int local_90;
  int local_8c;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint local_64 [18];
  tagRECT local_1c;
  int local_c;
  int local_8;
  
  local_64[0] = 0x20;
  local_64[1] = 0x400;
  local_64[2] = 0x40;
  local_64[3] = 0x80;
  local_64[4] = 0x100;
  local_64[5] = 0x200;
  local_64[6] = 1;
  local_64[7] = 2;
  local_64[8] = 4;
  local_64[9] = 8;
  local_64[10] = 0x10;
  local_64[0xb] = 0x800;
  local_64[0xc] = 0x1000;
  local_64[0xd] = 0x2000;
  local_64[0xe] = 0x4000;
  local_64[0xf] = 0x8000;
  local_64[0x10] = 0x10000;
  local_64[0x11] = 0x11;
  if (arg_1 != (LPRECT)0x0) {
    if (width == (int *)0x0) {
      SetRect(arg_1,0,0,0,0);
    }
    else if (height == 0) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      local_74 = ((width[2] - *width) * 0x11) / 100;
      local_8 = local_74;
      if (DAT_0054b960 != (HANDLE)0x0) {
        GetObjectA(DAT_0054b960,0x18,local_94);
        local_78 = local_90;
        local_7c = local_8c / (int)(local_64[0x11] + 1);
        local_8 = (local_74 * local_7c) / local_90;
      }
      local_68 = *width + 1;
      local_70 = (width[3] + -1) - local_8;
      SetRect(&local_1c,0,0,0,0);
      local_c = 1;
      for (local_6c = 0; local_6c < (int)local_64[0x11]; local_6c = local_6c + 1) {
        if ((height & local_64[local_6c]) != 0) {
          if (local_64[local_6c] == y) {
            SetRect(&local_1c,local_68,local_70,local_74 + local_68,local_8 + local_70);
          }
          local_68 = local_68 + local_74 + 1;
          if (((local_c < 3) &&
              (width[2] - ((width[2] - *width) * 0x19) / 100 < local_74 + local_68)) ||
             ((2 < local_c && (width[2] < local_74 + local_68)))) {
            local_68 = *width + 1;
            local_70 = local_70 - (local_8 + 1);
            local_c = local_c + 1;
          }
        }
      }
      CopyRect(arg_1,&local_1c);
    }
  }
  return;
}


