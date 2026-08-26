/*
 * Decompiled function: FUN_10020a41
 * Entry Point: 10020a41
 * Size: 759 bytes
 */
#include "deckdll.h"


void FUN_10020a41(HDC hdc,int *y,int width,int height)

{
  int val_1;
  int local_68;
  int local_64;
  int local_60 [5];
  uint8_t local_4c [4];
  int local_48;
  int local_44;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int32_t local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (y != (int *)0x0)) &&
     (val_1 = thunk_FUN_100242fb(width,height), val_1 != -1)) {
    local_30 = SaveDC(hdc);
    val_1 = thunk_FUN_100242e9(width,height);
    if (val_1 != 0) {
      local_60[4] = thunk_FUN_100242d7(width,height);
      thunk_FUN_100242c5(local_60);
      for (local_60[3] = 0; local_60[3] < 2; local_60[3] = local_60[3] + 1) {
        for (local_60[2] = 0; local_60[2] < local_60[local_60[3]]; local_60[2] = local_60[2] + 1) {
          thunk_FUN_100242ba(&local_68,local_60[3],local_60[2]);
          val_1 = thunk_FUN_100241ba(local_60[3],local_60[2]);
          if (((val_1 == 0x11d) && (local_68 == width)) && (local_64 == height)) {
            local_60[4] = local_60[4] | 8;
          }
        }
      }
      GetObjectA(DAT_1013e20c,0x18,local_4c);
      local_24 = local_48 / 2;
      local_34 = local_44 / 6;
      SetRect(&local_18,(y[2] + ((local_24 * 7) / 0x14) * -6) - local_24,y[1] + 1,-1,-1);
      IntersectClipRect(hdc,*y,y[1],y[2],y[1] + ((y[3] - y[1]) * 0xf) / 100);
      for (local_2c = 0; local_2c < 7; local_2c = local_2c + 1) {
        if ((local_60[4] & 1 << ((uint8_t)local_2c & 0x1f)) != 0) {
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
          thunk_FUN_1003197a(hdc,&local_18.left,DAT_1013e20c,local_24,local_34,0,local_1c,local_24,
                             local_1c);
        }
        OffsetRect(&local_18,(local_24 * 7) / 0x14,0);
      }
    }
    RestoreDC(hdc,local_30);
  }
  return;
}


