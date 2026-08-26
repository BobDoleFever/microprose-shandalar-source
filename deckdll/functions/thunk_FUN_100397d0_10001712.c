/*
 * Decompiled function: thunk_FUN_100397d0
 * Entry Point: 10001712
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_100397d0(int x,int y,int width,int height)

{
  int *i_ptr_1;
  bool flag_2;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int *piStack_c;
  
  if (x == 0) {
    iStack_18 = height + 0xe18;
    piStack_c = (int *)(height + 0xe90);
  }
  else if (x == 1) {
    iStack_18 = height + 0xe94;
    piStack_c = (int *)(height + 0xf0c);
  }
  else if (x == 2) {
    iStack_18 = height + 0xf10;
    piStack_c = (int *)(height + 0xf88);
  }
  else if (x == 5) {
    iStack_18 = height + 0x1084;
    piStack_c = (int *)(height + 0x10fc);
  }
  else if (x == 4) {
    iStack_18 = height + 0x1008;
    piStack_c = (int *)(height + 0x1080);
  }
  else {
    if (x != 3) {
      return;
    }
    iStack_18 = height + 0xf8c;
    piStack_c = (int *)(height + 0x1004);
  }
  iStack_10 = 0;
  flag_2 = false;
  while ((iStack_10 < *piStack_c && (!flag_2))) {
    if (*(int *)(iStack_18 + iStack_10 * 0xc) == y) {
      flag_2 = true;
      if (*(int *)(iStack_18 + 4 + iStack_10 * 0xc) == width) {
        for (iStack_14 = iStack_10; iStack_14 < *piStack_c + -1; iStack_14 = iStack_14 + 1) {
          *(int32_t *)(iStack_18 + iStack_14 * 0xc) =
               *(int32_t *)(iStack_18 + (iStack_14 * 3 + 3) * 4);
          *(int32_t *)(iStack_18 + 4 + iStack_14 * 0xc) =
               *(int32_t *)(iStack_18 + 4 + (iStack_14 * 3 + 3) * 4);
          *(int32_t *)(iStack_18 + 8 + iStack_14 * 0xc) =
               *(int32_t *)(iStack_18 + 8 + (iStack_14 * 3 + 3) * 4);
        }
        *piStack_c = *piStack_c + -1;
      }
      else if (width < *(int *)(iStack_18 + 4 + iStack_10 * 0xc)) {
        i_ptr_1 = (int *)(iStack_18 + 4 + iStack_10 * 0xc);
        *i_ptr_1 = *i_ptr_1 - width;
      }
      else {
        width = width - *(int *)(iStack_18 + 4 + iStack_10 * 0xc);
        flag_2 = false;
        for (iStack_14 = iStack_10; iStack_14 < *piStack_c + -1; iStack_14 = iStack_14 + 1) {
          *(int32_t *)(iStack_18 + iStack_14 * 0xc) =
               *(int32_t *)(iStack_18 + (iStack_14 * 3 + 3) * 4);
          *(int32_t *)(iStack_18 + 4 + iStack_14 * 0xc) =
               *(int32_t *)(iStack_18 + 4 + (iStack_14 * 3 + 3) * 4);
          *(int32_t *)(iStack_18 + 8 + iStack_14 * 0xc) =
               *(int32_t *)(iStack_18 + 8 + (iStack_14 * 3 + 3) * 4);
        }
        *piStack_c = *piStack_c + -1;
      }
    }
    iStack_10 = iStack_10 + 1;
  }
  return;
}


