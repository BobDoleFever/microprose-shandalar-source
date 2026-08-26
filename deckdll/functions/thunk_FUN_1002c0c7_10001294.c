/*
 * Decompiled function: thunk_FUN_1002c0c7
 * Entry Point: 10001294
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1002c0c7(int *arg_1,int arg_2,LPRECT arg_3)

{
  tagRECT tStack_18;
  int iStack_8;
  
  iStack_8 = (arg_1[3] - arg_1[1]) + -2;
  SetRect(&tStack_18,*arg_1 + 1,arg_1[1] + 1,*arg_1 + iStack_8 + 1,arg_1[3] + -2);
  if (((DAT_1017646c & 2) == 0) && ((DAT_1017646c & 0xc) == 0)) {
    OffsetRect(&tStack_18,iStack_8 * (arg_2 + -0xd),0);
  }
  else {
    OffsetRect(&tStack_18,iStack_8 * (arg_2 + -10),0);
  }
  if (0xc < arg_2) {
    tStack_18.left = tStack_18.left + -0x10;
    tStack_18.right = tStack_18.right + -0x10;
  }
  if ((0x13 < arg_2) && (arg_2 < 0x17)) {
    tStack_18.left = tStack_18.left + iStack_8 * -2;
    tStack_18.right = tStack_18.right + iStack_8 * -2;
  }
  if (0x16 < arg_2) {
    tStack_18.left = tStack_18.left - (iStack_8 + 0x10);
    tStack_18.right = tStack_18.right - (iStack_8 + 0x10);
  }
  if (0x1b < arg_2) {
    tStack_18.left = tStack_18.left - (0x10 - iStack_8);
    tStack_18.right = tStack_18.right - (0x10 - iStack_8);
  }
  CopyRect(arg_3,&tStack_18);
  return 1;
}


