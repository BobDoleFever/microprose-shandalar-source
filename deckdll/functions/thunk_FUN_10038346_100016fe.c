/*
 * Decompiled function: thunk_FUN_10038346
 * Entry Point: 100016fe
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10038346(int arg_1)

{
  int val_1;
  int iStack_c;
  uint32_t uStack_8;
  
  uStack_8 = (uint32_t)(*(int *)(DAT_1017697c + 0x58) == 0);
  if (DAT_101cece0 < 0x3b) {
    for (iStack_c = 0; iStack_c < DAT_101cece4; iStack_c = iStack_c + 1) {
      if ((*(int *)(iStack_c * 0xc + 0x101cded0) == arg_1) &&
         (val_1 = (*DAT_10175eec)(arg_1), 4 < val_1)) {
        return *(int *)(iStack_c * 0xc + 0x101cded4) - (uStack_8 + 3);
      }
    }
  }
  else {
    for (iStack_c = 0; iStack_c < DAT_101cece4; iStack_c = iStack_c + 1) {
      if ((*(int *)(iStack_c * 0xc + 0x101cded0) == arg_1) &&
         (val_1 = (*DAT_10175eec)(arg_1), 4 < val_1)) {
        return *(int *)(iStack_c * 0xc + 0x101cded4) - (uStack_8 * 99 + 4);
      }
    }
  }
  return 0;
}


