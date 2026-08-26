/*
 * Decompiled function: FUN_1003947f
 * Entry Point: 1003947f
 * Size: 351 bytes
 */
#include "deckdll.h"


void FUN_1003947f(int x,int y,int32_t arg_3,int height)

{
  int local_c;
  int *local_8;
  
  if (x == 0) {
    local_c = height + 0x117c;
    local_8 = (int *)(height + 0x11f4);
  }
  else if (x == 1) {
    local_c = height + 0x11f8;
    local_8 = (int *)(height + 0x1270);
  }
  else if (x == 2) {
    local_c = height + 0x1274;
    local_8 = (int *)(height + 0x12ec);
  }
  else if (x == 5) {
    local_c = height + 0x13e8;
    local_8 = (int *)(height + 0x1460);
  }
  else if (x == 4) {
    local_c = height + 0x136c;
    local_8 = (int *)(height + 0x13e4);
  }
  else if (x == 3) {
    local_c = height + 0x12f0;
    local_8 = (int *)(height + 0x1368);
  }
  else {
    if (x != 6) {
      return;
    }
    local_c = height + 0x1100;
    local_8 = (int *)(height + 0x1178);
  }
  *(int *)(local_c + *local_8 * 0xc) = y;
  *(int32_t *)(local_c + 4 + *local_8 * 0xc) = arg_3;
  *(int32_t *)(local_c + 8 + *local_8 * 0xc) = (&DAT_10176ab4)[y * 0x26];
  *local_8 = *local_8 + 1;
  return;
}


