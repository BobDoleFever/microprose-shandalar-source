/*
 * Decompiled function: thunk_FUN_1001f5d7
 * Entry Point: 10001212
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001f5d7(LPRECT arg_1,uint32_t y,int *width,uint32_t height)

{
  uint8_t auStack_94 [4];
  int iStack_90;
  int iStack_8c;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  uint32_t auStack_64 [18];
  tagRECT tStack_1c;
  int iStack_c;
  int iStack_8;
  
  auStack_64[0] = 0x20;
  auStack_64[1] = 0x400;
  auStack_64[2] = 0x40;
  auStack_64[3] = 0x80;
  auStack_64[4] = 0x100;
  auStack_64[5] = 0x200;
  auStack_64[6] = 1;
  auStack_64[7] = 2;
  auStack_64[8] = 4;
  auStack_64[9] = 8;
  auStack_64[10] = 0x10;
  auStack_64[0xb] = 0x800;
  auStack_64[0xc] = 0x1000;
  auStack_64[0xd] = 0x2000;
  auStack_64[0xe] = 0x4000;
  auStack_64[0xf] = 0x8000;
  auStack_64[0x10] = 0x10000;
  auStack_64[0x11] = 0x11;
  if (arg_1 != (LPRECT)0x0) {
    if (width == (int *)0x0) {
      SetRect(arg_1,0,0,0,0);
    }
    else if (height == 0) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      iStack_74 = ((width[2] - *width) * 0x11) / 100;
      iStack_8 = iStack_74;
      if (DAT_1013e5d0 != (HANDLE)0x0) {
        GetObjectA(DAT_1013e5d0,0x18,auStack_94);
        iStack_78 = iStack_90;
        iStack_7c = iStack_8c / (int)(auStack_64[0x11] + 1);
        iStack_8 = (iStack_74 * iStack_7c) / iStack_90;
      }
      iStack_68 = *width + 1;
      iStack_70 = (width[3] + -1) - iStack_8;
      SetRect(&tStack_1c,0,0,0,0);
      iStack_c = 1;
      for (iStack_6c = 0; iStack_6c < (int)auStack_64[0x11]; iStack_6c = iStack_6c + 1) {
        if ((height & auStack_64[iStack_6c]) != 0) {
          if (auStack_64[iStack_6c] == y) {
            SetRect(&tStack_1c,iStack_68,iStack_70,iStack_74 + iStack_68,iStack_8 + iStack_70);
          }
          iStack_68 = iStack_68 + iStack_74 + 1;
          if (((iStack_c < 3) &&
              (width[2] - ((width[2] - *width) * 0x19) / 100 < iStack_74 + iStack_68)) ||
             ((2 < iStack_c && (width[2] < iStack_74 + iStack_68)))) {
            iStack_68 = *width + 1;
            iStack_70 = iStack_70 - (iStack_8 + 1);
            iStack_c = iStack_c + 1;
          }
        }
      }
      CopyRect(arg_1,&tStack_1c);
    }
  }
  return;
}


