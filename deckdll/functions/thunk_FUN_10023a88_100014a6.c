/*
 * Decompiled function: thunk_FUN_10023a88
 * Entry Point: 100014a6
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10023a88(uint8_t *arg_1)

{
  uint32_t uval_1;
  int val_2;
  uint32_t uStack_10;
  int iStack_c;
  
  iStack_c = (int)DAT_10140772;
  while (0 < iStack_c) {
    uval_1 = fgetc(DAT_1013f3cc);
    if (((uint8_t)uval_1 & 0xc0) == 0xc0) {
      uval_1 = uval_1 & 0x3f;
      val_2 = fgetc(DAT_1013f3cc);
      if (uval_1 < 2) {
        *arg_1 = (uint8_t)val_2;
        arg_1 = arg_1 + 1;
        iStack_c = iStack_c + -1;
      }
      else {
        for (uStack_10 = 0; uStack_10 < uval_1; uStack_10 = uStack_10 + 1) {
          *arg_1 = (uint8_t)val_2;
          arg_1 = arg_1 + 1;
        }
        iStack_c = iStack_c - uval_1;
      }
    }
    else {
      *arg_1 = (uint8_t)uval_1;
      arg_1 = arg_1 + 1;
      iStack_c = iStack_c + -1;
    }
  }
  return 1;
}


