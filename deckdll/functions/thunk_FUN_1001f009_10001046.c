/*
 * Decompiled function: thunk_FUN_1001f009
 * Entry Point: 10001046
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1001f009(int arg_1,int *arg_2,int arg_3,int arg_4,int arg_5)

{
  int yTop;
  int iStack_6c;
  int iStack_60;
  int32_t uStack_5c;
  uint8_t auStack_58 [4];
  int iStack_54;
  int iStack_50;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  tagRECT tStack_14;
  
  if ((arg_1 == 0) || (arg_2 == (int *)0x0)) {
    uStack_5c = 0;
  }
  else if (arg_4 + arg_3 + arg_5 == 0) {
    uStack_5c = 1;
  }
  else if (DAT_1013e3a4 == (HANDLE)0x0) {
    uStack_5c = 0;
  }
  else {
    GetObjectA(DAT_1013e3a4,0x18,auStack_58);
    iStack_34 = iStack_54;
    iStack_40 = iStack_50 / 0x18;
    iStack_2c = arg_2[3] - arg_2[1];
    iStack_20 = (arg_2[2] - *arg_2) / 3;
    iStack_18 = *arg_2;
    iStack_28 = iStack_20 + iStack_18;
    iStack_30 = iStack_20 + iStack_28;
    yTop = arg_2[1];
    iStack_38 = iStack_50 - iStack_40;
    iStack_1c = (iStack_54 * iStack_2c) / iStack_40;
    for (iStack_6c = iStack_1c;
        (iStack_20 < (arg_5 + -1) * iStack_6c + iStack_1c && (2 < iStack_6c));
        iStack_6c = iStack_6c + -1) {
    }
    iStack_60 = (arg_5 + -1) * iStack_6c + iStack_18;
    for (iStack_3c = 0; iStack_3c < arg_5; iStack_3c = iStack_3c + 1) {
      iStack_24 = iStack_40 * 0x14;
      SetRect(&tStack_14,iStack_60,yTop,iStack_1c + iStack_60,iStack_2c + yTop);
      thunk_FUN_1003197a((HDC)arg_1,&tStack_14.left,DAT_1013e3a4,iStack_34,iStack_40,0,iStack_24,0,
                         iStack_38);
      iStack_60 = iStack_60 - iStack_6c;
    }
    for (iStack_6c = iStack_1c;
        (iStack_20 < (arg_4 + -1) * iStack_6c + iStack_1c && (2 < iStack_6c));
        iStack_6c = iStack_6c + -1) {
    }
    iStack_60 = (arg_4 + -1) * iStack_6c + iStack_28;
    for (iStack_3c = 0; iStack_3c < arg_4; iStack_3c = iStack_3c + 1) {
      iStack_24 = iStack_40 * 0x16;
      SetRect(&tStack_14,iStack_60,yTop,iStack_1c + iStack_60,iStack_2c + yTop);
      thunk_FUN_1003197a((HDC)arg_1,&tStack_14.left,DAT_1013e3a4,iStack_34,iStack_40,0,iStack_24,0,
                         iStack_38);
      iStack_60 = iStack_60 - iStack_6c;
    }
    for (iStack_6c = iStack_1c;
        (iStack_20 < (arg_3 + -1) * iStack_6c + iStack_1c && (2 < iStack_6c));
        iStack_6c = iStack_6c + -1) {
    }
    iStack_60 = (arg_3 + -1) * iStack_6c + iStack_30;
    for (iStack_3c = 0; iStack_3c < arg_3; iStack_3c = iStack_3c + 1) {
      iStack_24 = iStack_40 * 0x15;
      SetRect(&tStack_14,iStack_60,yTop,iStack_1c + iStack_60,iStack_2c + yTop);
      thunk_FUN_1003197a((HDC)arg_1,&tStack_14.left,DAT_1013e3a4,iStack_34,iStack_40,0,iStack_24,0,
                         iStack_38);
      iStack_60 = iStack_60 - iStack_6c;
    }
    uStack_5c = 1;
  }
  return uStack_5c;
}


