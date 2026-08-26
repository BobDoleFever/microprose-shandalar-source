/*
 * Decompiled function: thunk_FUN_100392dc
 * Entry Point: 10001136
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_100392dc(int x,int y,int width,int height)

{
  int *i_ptr_1;
  bool flag_2;
  int iStack_14;
  int iStack_10;
  int *piStack_c;
  
  if (x == 0) {
    iStack_14 = height + 0xe18;
    piStack_c = (int *)(height + 0xe90);
  }
  else if (x == 1) {
    iStack_14 = height + 0xe94;
    piStack_c = (int *)(height + 0xf0c);
  }
  else if (x == 2) {
    iStack_14 = height + 0xf10;
    piStack_c = (int *)(height + 0xf88);
  }
  else if (x == 5) {
    iStack_14 = height + 0x1084;
    piStack_c = (int *)(height + 0x10fc);
  }
  else if (x == 4) {
    iStack_14 = height + 0x1008;
    piStack_c = (int *)(height + 0x1080);
  }
  else {
    if (x != 3) {
      return;
    }
    iStack_14 = height + 0xf8c;
    piStack_c = (int *)(height + 0x1004);
  }
  iStack_10 = 0;
  flag_2 = false;
  while ((iStack_10 < *piStack_c && (!flag_2))) {
    if (*(int *)(iStack_14 + iStack_10 * 0xc) == y) {
      i_ptr_1 = (int *)(iStack_14 + 4 + iStack_10 * 0xc);
      *i_ptr_1 = *i_ptr_1 + width;
      flag_2 = true;
    }
    iStack_10 = iStack_10 + 1;
  }
  if (!flag_2) {
    *(int *)(iStack_14 + *piStack_c * 0xc) = y;
    *(int *)(iStack_14 + 4 + *piStack_c * 0xc) = width;
    *(int32_t *)(iStack_14 + 8 + *piStack_c * 0xc) = (&DAT_10176ab4)[y * 0x26];
    *piStack_c = *piStack_c + 1;
  }
  return;
}


