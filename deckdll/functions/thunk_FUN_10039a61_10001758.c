/*
 * Decompiled function: thunk_FUN_10039a61
 * Entry Point: 10001758
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10039a61(int x,int y,int width,int height)

{
  bool flag_1;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int *piStack_c;
  
  if (x == 0) {
    iStack_18 = height + 0x117c;
    piStack_c = (int *)(height + 0x11f4);
  }
  else if (x == 1) {
    iStack_18 = height + 0x11f8;
    piStack_c = (int *)(height + 0x1270);
  }
  else if (x == 2) {
    iStack_18 = height + 0x1274;
    piStack_c = (int *)(height + 0x12ec);
  }
  else if (x == 5) {
    iStack_18 = height + 0x13e8;
    piStack_c = (int *)(height + 0x1460);
  }
  else if (x == 4) {
    iStack_18 = height + 0x136c;
    piStack_c = (int *)(height + 0x13e4);
  }
  else if (x == 3) {
    iStack_18 = height + 0x12f0;
    piStack_c = (int *)(height + 0x1368);
  }
  else {
    if (x != 6) {
      return;
    }
    iStack_18 = height + 0x1100;
    piStack_c = (int *)(height + 0x1178);
  }
  iStack_10 = 0;
  flag_1 = false;
  while ((iStack_10 < *piStack_c && (!flag_1))) {
    if (*(int *)(iStack_18 + iStack_10 * 0xc) == y) {
      for (iStack_14 = iStack_10; iStack_14 < *piStack_c + -1; iStack_14 = iStack_14 + 1) {
        *(int32_t *)(iStack_18 + iStack_14 * 0xc) =
             *(int32_t *)(iStack_18 + (iStack_14 * 3 + 3) * 4);
        *(int32_t *)(iStack_18 + 4 + iStack_14 * 0xc) =
             *(int32_t *)(iStack_18 + 4 + (iStack_14 * 3 + 3) * 4);
        *(int32_t *)(iStack_18 + 8 + iStack_14 * 0xc) =
             *(int32_t *)(iStack_18 + 8 + (iStack_14 * 3 + 3) * 4);
      }
      *piStack_c = *piStack_c + -1;
      width = width + -1;
      if (width < 1) {
        flag_1 = true;
      }
    }
    iStack_10 = iStack_10 + 1;
  }
  return;
}


