/*
 * Decompiled function: FUN_10013a4c
 * Entry Point: 10013a4c
 * Size: 151 bytes
 */
#include "deckdll.h"


uint8_t * FUN_10013a4c(int arg1,int arg2)

{
  uint8_t *local_c;
  int local_8;
  
  local_c = (uint8_t *)0x0;
  if (arg1 == -1) {
    local_c = (uint8_t *)0x0;
  }
  else {
    local_8 = 0;
    while ((local_8 < DAT_10158728 && (local_c == (uint8_t *)0x0))) {
      if (((&DAT_101cf600)[local_8 * 6] == arg1) && ((&DAT_101cf604)[local_8 * 6] == arg2)) {
        local_c = &DAT_101cf5f0 + local_8 * 0x18;
      }
      local_8 = local_8 + 1;
    }
  }
  return local_c;
}


