/*
 * Decompiled function: thunk_FUN_10020a41
 * Entry Point: 10001037
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10020a41(HDC hdc,int *y,int width,int height)

{
  int val_1;
  int iStack_68;
  int iStack_64;
  int aiStack_60 [5];
  uint8_t auStack_4c [4];
  int iStack_48;
  int iStack_44;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int32_t uStack_20;
  int iStack_1c;
  tagRECT tStack_18;
  int iStack_8;
  
  if (((hdc != (HDC)0x0) && (y != (int *)0x0)) &&
     (val_1 = thunk_FUN_100242fb(width,height), val_1 != -1)) {
    iStack_30 = SaveDC(hdc);
    val_1 = thunk_FUN_100242e9(width,height);
    if (val_1 != 0) {
      aiStack_60[4] = thunk_FUN_100242d7(width,height);
      thunk_FUN_100242c5(aiStack_60);
      for (aiStack_60[3] = 0; aiStack_60[3] < 2; aiStack_60[3] = aiStack_60[3] + 1) {
        for (aiStack_60[2] = 0; aiStack_60[2] < aiStack_60[aiStack_60[3]];
            aiStack_60[2] = aiStack_60[2] + 1) {
          thunk_FUN_100242ba(&iStack_68,aiStack_60[3],aiStack_60[2]);
          val_1 = thunk_FUN_100241ba(aiStack_60[3],aiStack_60[2]);
          if (((val_1 == 0x11d) && (iStack_68 == width)) && (iStack_64 == height)) {
            aiStack_60[4] = aiStack_60[4] | 8;
          }
        }
      }
      GetObjectA(DAT_1013e20c,0x18,auStack_4c);
      iStack_24 = iStack_48 / 2;
      iStack_34 = iStack_44 / 6;
      SetRect(&tStack_18,(y[2] + ((iStack_24 * 7) / 0x14) * -6) - iStack_24,y[1] + 1,-1,-1);
      IntersectClipRect(hdc,*y,y[1],y[2],y[1] + ((y[3] - y[1]) * 0xf) / 100);
      for (iStack_2c = 0; iStack_2c < 7; iStack_2c = iStack_2c + 1) {
        if ((aiStack_60[4] & 1 << ((uint8_t)iStack_2c & 0x1f)) != 0) {
          uStack_20 = 0;
          if (iStack_2c == 5) {
            iStack_1c = 0;
          }
          else if (iStack_2c == 2) {
            iStack_1c = iStack_34;
          }
          else if (iStack_2c == 1) {
            iStack_1c = iStack_34 * 2;
          }
          else if (iStack_2c == 4) {
            iStack_1c = iStack_34 * 3;
          }
          else if (iStack_2c == 3) {
            iStack_1c = iStack_34 << 2;
          }
          else if (iStack_2c == 0) {
            iStack_1c = iStack_34 * 5;
          }
          else if (iStack_2c == 6) {
            iStack_1c = iStack_34 * 5;
          }
          iStack_8 = iStack_24;
          iStack_28 = iStack_1c;
          thunk_FUN_1003197a(hdc,&tStack_18.left,DAT_1013e20c,iStack_24,iStack_34,0,iStack_1c,
                             iStack_24,iStack_1c);
        }
        OffsetRect(&tStack_18,(iStack_24 * 7) / 0x14,0);
      }
    }
    RestoreDC(hdc,iStack_30);
  }
  return;
}


