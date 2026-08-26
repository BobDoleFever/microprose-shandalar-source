/*
 * Decompiled function: thunk_FUN_1003947f
 * Entry Point: 1000178a
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1003947f(int x,int y,int32_t arg_3,int height)

{
  int iStack_c;
  int *piStack_8;
  
  if (x == 0) {
    iStack_c = height + 0x117c;
    piStack_8 = (int *)(height + 0x11f4);
  }
  else if (x == 1) {
    iStack_c = height + 0x11f8;
    piStack_8 = (int *)(height + 0x1270);
  }
  else if (x == 2) {
    iStack_c = height + 0x1274;
    piStack_8 = (int *)(height + 0x12ec);
  }
  else if (x == 5) {
    iStack_c = height + 0x13e8;
    piStack_8 = (int *)(height + 0x1460);
  }
  else if (x == 4) {
    iStack_c = height + 0x136c;
    piStack_8 = (int *)(height + 0x13e4);
  }
  else if (x == 3) {
    iStack_c = height + 0x12f0;
    piStack_8 = (int *)(height + 0x1368);
  }
  else {
    if (x != 6) {
      return;
    }
    iStack_c = height + 0x1100;
    piStack_8 = (int *)(height + 0x1178);
  }
  *(int *)(iStack_c + *piStack_8 * 0xc) = y;
  *(int32_t *)(iStack_c + 4 + *piStack_8 * 0xc) = arg_3;
  *(int32_t *)(iStack_c + 8 + *piStack_8 * 0xc) = (&DAT_10176ab4)[y * 0x26];
  *piStack_8 = *piStack_8 + 1;
  return;
}


