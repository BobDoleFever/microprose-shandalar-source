/*
 * Decompiled function: FUN_00426181
 * Entry Point: 00426181
 * Size: 760 bytes
 */
#include "duel.h"


void FUN_00426181(HDC hdc,int *y,int width,int height)

{
  int iVar1;
  int local_68;
  int local_64;
  int local_60 [5];
  undefined1 local_4c [4];
  int local_48;
  int local_44;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (y != (int *)0x0)) && (iVar1 = FUN_00447114(width,height), iVar1 != -1))
  {
    local_30 = SaveDC(hdc);
    iVar1 = FUN_00447aec(width,height);
    if (iVar1 != 0) {
      local_60[4] = FUN_0044788d(width,height);
      FUN_00448aa1(local_60);
      for (local_60[3] = 0; local_60[3] < 2; local_60[3] = local_60[3] + 1) {
        for (local_60[2] = 0; local_60[2] < local_60[local_60[3]]; local_60[2] = local_60[2] + 1) {
          FUN_0044743d(&local_68,local_60[3],local_60[2]);
          iVar1 = FUN_00447184(local_60[3],local_60[2]);
          if (((iVar1 == 0x11d) && (local_68 == width)) && (local_64 == height)) {
            local_60[4] = local_60[4] | 8;
          }
        }
      }
      GetObjectA(DAT_0050adf4,0x18,local_4c);
      local_24 = local_48 / 2;
      local_34 = local_44 / 6;
      SetRect(&local_18,(y[2] + ((local_24 * 7) / 0x14) * -6) - local_24,y[1] + 1,-1,-1);
      IntersectClipRect(hdc,*y,y[1],y[2],y[1] + ((y[3] - y[1]) * 0xf) / 100);
      for (local_2c = 0; local_2c < 7; local_2c = local_2c + 1) {
        if ((local_60[4] & 1 << ((byte)local_2c & 0x1f)) != 0) {
          local_20 = 0;
          if (local_2c == 5) {
            local_1c = 0;
          }
          else if (local_2c == 2) {
            local_1c = local_34;
          }
          else if (local_2c == 1) {
            local_1c = local_34 * 2;
          }
          else if (local_2c == 4) {
            local_1c = local_34 * 3;
          }
          else if (local_2c == 3) {
            local_1c = local_34 << 2;
          }
          else if (local_2c == 0) {
            local_1c = local_34 * 5;
          }
          else if (local_2c == 6) {
            local_1c = local_34 * 5;
          }
          local_8 = local_24;
          local_28 = local_1c;
          FUN_00470cfa(hdc,&local_18.left,DAT_0050adf4,local_24,local_34,0,local_1c,local_24,
                       local_1c);
        }
        OffsetRect(&local_18,(local_24 * 7) / 0x14,0);
      }
    }
    RestoreDC(hdc,local_30);
  }
  return;
}


