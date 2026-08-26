/*
 * Decompiled function: FUN_10023a88
 * Entry Point: 10023a88
 * Size: 222 bytes
 */
#include "deckdll.h"


int32_t FUN_10023a88(uint8_t *arg_1)

{
  uint32_t uval_1;
  int val_2;
  uint32_t local_10;
  int local_c;
  
  local_c = (int)DAT_10140772;
  while (0 < local_c) {
    uval_1 = fgetc(DAT_1013f3cc);
    if (((uint8_t)uval_1 & 0xc0) == 0xc0) {
      uval_1 = uval_1 & 0x3f;
      val_2 = fgetc(DAT_1013f3cc);
      if (uval_1 < 2) {
        *arg_1 = (uint8_t)val_2;
        arg_1 = arg_1 + 1;
        local_c = local_c + -1;
      }
      else {
        for (local_10 = 0; local_10 < uval_1; local_10 = local_10 + 1) {
          *arg_1 = (uint8_t)val_2;
          arg_1 = arg_1 + 1;
        }
        local_c = local_c - uval_1;
      }
    }
    else {
      *arg_1 = (uint8_t)uval_1;
      arg_1 = arg_1 + 1;
      local_c = local_c + -1;
    }
  }
  return 1;
}


