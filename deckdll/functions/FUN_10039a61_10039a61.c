/*
 * Decompiled function: FUN_10039a61
 * Entry Point: 10039a61
 * Size: 488 bytes
 */
#include "deckdll.h"


void FUN_10039a61(int x,int y,int width,int height)

{
  bool flag_1;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  
  if (x == 0) {
    local_18 = height + 0x117c;
    local_c = (int *)(height + 0x11f4);
  }
  else if (x == 1) {
    local_18 = height + 0x11f8;
    local_c = (int *)(height + 0x1270);
  }
  else if (x == 2) {
    local_18 = height + 0x1274;
    local_c = (int *)(height + 0x12ec);
  }
  else if (x == 5) {
    local_18 = height + 0x13e8;
    local_c = (int *)(height + 0x1460);
  }
  else if (x == 4) {
    local_18 = height + 0x136c;
    local_c = (int *)(height + 0x13e4);
  }
  else if (x == 3) {
    local_18 = height + 0x12f0;
    local_c = (int *)(height + 0x1368);
  }
  else {
    if (x != 6) {
      return;
    }
    local_18 = height + 0x1100;
    local_c = (int *)(height + 0x1178);
  }
  local_10 = 0;
  flag_1 = false;
  while ((local_10 < *local_c && (!flag_1))) {
    if (*(int *)(local_18 + local_10 * 0xc) == y) {
      for (local_14 = local_10; local_14 < *local_c + -1; local_14 = local_14 + 1) {
        *(int32_t *)(local_18 + local_14 * 0xc) =
             *(int32_t *)(local_18 + (local_14 * 3 + 3) * 4);
        *(int32_t *)(local_18 + 4 + local_14 * 0xc) =
             *(int32_t *)(local_18 + 4 + (local_14 * 3 + 3) * 4);
        *(int32_t *)(local_18 + 8 + local_14 * 0xc) =
             *(int32_t *)(local_18 + 8 + (local_14 * 3 + 3) * 4);
      }
      *local_c = *local_c + -1;
      width = width + -1;
      if (width < 1) {
        flag_1 = true;
      }
    }
    local_10 = local_10 + 1;
  }
  return;
}


