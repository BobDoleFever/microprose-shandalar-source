/*
 * Decompiled function: FUN_100397d0
 * Entry Point: 100397d0
 * Size: 657 bytes
 */
#include "deckdll.h"


void FUN_100397d0(int x,int y,int width,int height)

{
  int *i_ptr_1;
  bool flag_2;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  
  if (x == 0) {
    local_18 = height + 0xe18;
    local_c = (int *)(height + 0xe90);
  }
  else if (x == 1) {
    local_18 = height + 0xe94;
    local_c = (int *)(height + 0xf0c);
  }
  else if (x == 2) {
    local_18 = height + 0xf10;
    local_c = (int *)(height + 0xf88);
  }
  else if (x == 5) {
    local_18 = height + 0x1084;
    local_c = (int *)(height + 0x10fc);
  }
  else if (x == 4) {
    local_18 = height + 0x1008;
    local_c = (int *)(height + 0x1080);
  }
  else {
    if (x != 3) {
      return;
    }
    local_18 = height + 0xf8c;
    local_c = (int *)(height + 0x1004);
  }
  local_10 = 0;
  flag_2 = false;
  while ((local_10 < *local_c && (!flag_2))) {
    if (*(int *)(local_18 + local_10 * 0xc) == y) {
      flag_2 = true;
      if (*(int *)(local_18 + 4 + local_10 * 0xc) == width) {
        for (local_14 = local_10; local_14 < *local_c + -1; local_14 = local_14 + 1) {
          *(int32_t *)(local_18 + local_14 * 0xc) =
               *(int32_t *)(local_18 + (local_14 * 3 + 3) * 4);
          *(int32_t *)(local_18 + 4 + local_14 * 0xc) =
               *(int32_t *)(local_18 + 4 + (local_14 * 3 + 3) * 4);
          *(int32_t *)(local_18 + 8 + local_14 * 0xc) =
               *(int32_t *)(local_18 + 8 + (local_14 * 3 + 3) * 4);
        }
        *local_c = *local_c + -1;
      }
      else if (width < *(int *)(local_18 + 4 + local_10 * 0xc)) {
        i_ptr_1 = (int *)(local_18 + 4 + local_10 * 0xc);
        *i_ptr_1 = *i_ptr_1 - width;
      }
      else {
        width = width - *(int *)(local_18 + 4 + local_10 * 0xc);
        flag_2 = false;
        for (local_14 = local_10; local_14 < *local_c + -1; local_14 = local_14 + 1) {
          *(int32_t *)(local_18 + local_14 * 0xc) =
               *(int32_t *)(local_18 + (local_14 * 3 + 3) * 4);
          *(int32_t *)(local_18 + 4 + local_14 * 0xc) =
               *(int32_t *)(local_18 + 4 + (local_14 * 3 + 3) * 4);
          *(int32_t *)(local_18 + 8 + local_14 * 0xc) =
               *(int32_t *)(local_18 + 8 + (local_14 * 3 + 3) * 4);
        }
        *local_c = *local_c + -1;
      }
    }
    local_10 = local_10 + 1;
  }
  return;
}


