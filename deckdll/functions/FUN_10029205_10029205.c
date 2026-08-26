/*
 * Decompiled function: FUN_10029205
 * Entry Point: 10029205
 * Size: 150 bytes
 */
#include "deckdll.h"


uint8_t * FUN_10029205(int arg1,int arg2)

{
  int local_c;
  uint8_t *local_8;
  
  local_8 = (uint8_t *)0x0;
  if (arg1 == -1) {
    local_8 = (uint8_t *)0x0;
  }
  else {
    local_c = 0;
    while ((local_c < DAT_101cdeb0 && (local_8 == (uint8_t *)0x0))) {
      if ((*(int *)(&DAT_10175570 + local_c * 0x18) == arg1) &&
         (*(int *)(&DAT_10175574 + local_c * 0x18) == arg2)) {
        local_8 = &DAT_10175560 + local_c * 0x18;
      }
      local_c = local_c + 1;
    }
  }
  return local_8;
}


