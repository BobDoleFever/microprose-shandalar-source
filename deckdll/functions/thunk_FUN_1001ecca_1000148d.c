/*
 * Decompiled function: thunk_FUN_1001ecca
 * Entry Point: 1000148d
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1001ecca(HDC hdc,int y,int width,int height)

{
  int iStack_68;
  int iStack_60;
  int32_t uStack_5c;
  uint8_t auStack_58 [4];
  int iStack_54;
  int iStack_50;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  tagRECT tStack_30;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  tagRECT tStack_14;
  
  if ((hdc == (HDC)0x0) || (y == 0)) {
    uStack_5c = 0;
  }
  else if ((width < 0) || (0x16 < width)) {
    uStack_5c = 0;
  }
  else if (DAT_1013e3a4 == (HANDLE)0x0) {
    uStack_5c = 0;
  }
  else {
    thunk_FUN_1001ee4b(&tStack_30,(int *)y,height);
    GetObjectA(DAT_1013e3a4,0x18,auStack_58);
    iStack_34 = iStack_54;
    iStack_40 = iStack_50 / 0x18;
    iStack_20 = tStack_30.bottom - tStack_30.top;
    iStack_18 = (iStack_54 * iStack_20) / iStack_40;
    iStack_68 = iStack_18;
    if (1 < height) {
      iStack_68 = ((tStack_30.right - tStack_30.left) - iStack_18) / (height + -1);
    }
    iStack_1c = width * iStack_40;
    iStack_38 = iStack_50 - iStack_40;
    iStack_60 = tStack_30.right - iStack_18;
    for (iStack_3c = 0; iStack_3c < height; iStack_3c = iStack_3c + 1) {
      SetRect(&tStack_14,iStack_60,tStack_30.top,iStack_18 + iStack_60,iStack_20 + tStack_30.top);
      thunk_FUN_1003197a(hdc,&tStack_14.left,DAT_1013e3a4,iStack_34,iStack_40,0,iStack_1c,0,
                         iStack_38);
      iStack_60 = iStack_60 - iStack_68;
    }
    uStack_5c = 1;
  }
  return uStack_5c;
}


