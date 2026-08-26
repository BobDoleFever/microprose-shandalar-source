/*
 * Decompiled function: FUN_10038346
 * Entry Point: 10038346
 * Size: 294 bytes
 */
#include "deckdll.h"


int FUN_10038346(int arg_1)

{
  int val_1;
  int local_c;
  uint32_t local_8;
  
  local_8 = (uint32_t)(*(int *)(DAT_1017697c + 0x58) == 0);
  if (DAT_101cece0 < 0x3b) {
    for (local_c = 0; local_c < DAT_101cece4; local_c = local_c + 1) {
      if ((*(int *)(local_c * 0xc + 0x101cded0) == arg_1) &&
         (val_1 = (*DAT_10175eec)(arg_1), 4 < val_1)) {
        return *(int *)(local_c * 0xc + 0x101cded4) - (local_8 + 3);
      }
    }
  }
  else {
    for (local_c = 0; local_c < DAT_101cece4; local_c = local_c + 1) {
      if ((*(int *)(local_c * 0xc + 0x101cded0) == arg_1) &&
         (val_1 = (*DAT_10175eec)(arg_1), 4 < val_1)) {
        return *(int *)(local_c * 0xc + 0x101cded4) - (local_8 * 99 + 4);
      }
    }
  }
  return 0;
}


