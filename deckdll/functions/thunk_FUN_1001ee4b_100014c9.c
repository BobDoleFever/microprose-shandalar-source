/*
 * Decompiled function: thunk_FUN_1001ee4b
 * Entry Point: 100014c9
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001ee4b(LPRECT arg_1,int *arg_2,int arg_3)

{
  int iStack_58;
  uint8_t auStack_4c [4];
  int iStack_48;
  int iStack_44;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  tagRECT tStack_24;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (arg_1 != (LPRECT)0x0) {
    if (arg_2 == (int *)0x0) {
      SetRect(arg_1,0,0,0,0);
    }
    else if (arg_3 == 0) {
      SetRect(arg_1,0,0,0,0);
    }
    else {
      SetRect(&tStack_24,0,0,0,0);
      if (DAT_1013e3a4 != (HANDLE)0x0) {
        iStack_14 = *arg_2 + ((arg_2[2] - *arg_2) * 7) / 100;
        iStack_c = arg_2[2] - ((arg_2[2] - *arg_2) * 10) / 100;
        iStack_10 = arg_2[1] + ((arg_2[3] - arg_2[1]) * 8) / 100;
        iStack_8 = arg_2[1] + ((arg_2[3] - arg_2[1]) * 0x23) / 100;
        GetObjectA(DAT_1013e3a4,0x18,auStack_4c);
        iStack_30 = iStack_48;
        iStack_34 = iStack_44 / 0x18;
        iStack_2c = iStack_8 - iStack_10;
        iStack_28 = (iStack_48 * iStack_2c) / iStack_34;
        for (iStack_58 = iStack_28;
            (iStack_c < (arg_3 + -1) * iStack_58 + iStack_28 + iStack_14 && (1 < iStack_58));
            iStack_58 = iStack_58 + -1) {
        }
        SetRect(&tStack_24,iStack_14,iStack_10,(arg_3 + -1) * iStack_58 + iStack_28 + iStack_14,
                iStack_10 + iStack_2c);
      }
      CopyRect(arg_1,&tStack_24);
    }
  }
  return;
}


