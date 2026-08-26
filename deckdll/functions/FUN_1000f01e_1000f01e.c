/*
 * Decompiled function: FUN_1000f01e
 * Entry Point: 1000f01e
 * Size: 230 bytes
 */
#include "deckdll.h"


int32_t FUN_1000f01e(uint32_t *x,int y,int width,int height)

{
  uint8_t uval_1;
  uint32_t arg_1;
  int local_1c;
  int local_18;
  int local_14;
  uint32_t *local_c;
  uint32_t local_8;
  
  local_c = x;
  for (local_18 = 0; local_18 < y; local_18 = local_18 + 1) {
    local_1c = 0;
    local_14 = 0;
    local_8 = *x;
    for (; local_14 < width * 3; local_14 = local_14 + 3) {
      arg_1 = local_8 & 0xffffff;
      local_8 = *(uint32_t *)(local_14 + 3 + (int)x);
      uval_1 = thunk_FUN_1000ed78(arg_1);
      *(uint8_t *)(local_1c + (int)local_c) = uval_1;
      if (*(uint32_t *)(&DAT_10128a30 + (uint32_t)*(uint8_t *)(local_1c + (int)local_c) * 4) != arg_1) {
        *(int32_t *)(&DAT_10128a30 + (uint32_t)*(uint8_t *)(local_1c + (int)local_c) * 4) = 0;
      }
      local_1c = local_1c + 1;
    }
    x = (uint32_t *)((int)x + height + width * 3);
    local_c = (uint32_t *)((int)local_c + height + width);
  }
  return 0;
}


