/*
 * Decompiled function: FUN_100392dc
 * Entry Point: 100392dc
 * Size: 419 bytes
 */
#include "deckdll.h"


void FUN_100392dc(int x,int y,int width,int height)

{
  int *i_ptr_1;
  bool flag_2;
  int local_14;
  int local_10;
  int *local_c;
  
  if (x == 0) {
    local_14 = height + 0xe18;
    local_c = (int *)(height + 0xe90);
  }
  else if (x == 1) {
    local_14 = height + 0xe94;
    local_c = (int *)(height + 0xf0c);
  }
  else if (x == 2) {
    local_14 = height + 0xf10;
    local_c = (int *)(height + 0xf88);
  }
  else if (x == 5) {
    local_14 = height + 0x1084;
    local_c = (int *)(height + 0x10fc);
  }
  else if (x == 4) {
    local_14 = height + 0x1008;
    local_c = (int *)(height + 0x1080);
  }
  else {
    if (x != 3) {
      return;
    }
    local_14 = height + 0xf8c;
    local_c = (int *)(height + 0x1004);
  }
  local_10 = 0;
  flag_2 = false;
  while ((local_10 < *local_c && (!flag_2))) {
    if (*(int *)(local_14 + local_10 * 0xc) == y) {
      i_ptr_1 = (int *)(local_14 + 4 + local_10 * 0xc);
      *i_ptr_1 = *i_ptr_1 + width;
      flag_2 = true;
    }
    local_10 = local_10 + 1;
  }
  if (!flag_2) {
    *(int *)(local_14 + *local_c * 0xc) = y;
    *(int *)(local_14 + 4 + *local_c * 0xc) = width;
    *(int32_t *)(local_14 + 8 + *local_c * 0xc) = (&DAT_10176ab4)[y * 0x26];
    *local_c = *local_c + 1;
  }
  return;
}


