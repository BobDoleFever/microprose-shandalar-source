/*
 * Decompiled function: FUN_10014a60
 * Entry Point: 10014a60
 * Size: 59 bytes
 */
#include "deckdll.h"


void FUN_10014a60(undefined8 *arg1,uint32_t arg2)

{
  uint32_t uval_1;
  uint32_t uval_2;
  
  uval_1 = arg2;
  if (((uint32_t)arg1 & 4) != 0) {
    *(uint8_t *)arg1 = 0;
    arg1 = (undefined8 *)((int)arg1 + 4);
    uval_1 = arg2 - 1;
    if (uval_1 == 0 || (int)arg2 < 1) {
      return;
    }
  }
  uval_2 = uval_1 >> 1;
  if (uval_2 != 0) {
    while (uval_2 = uval_2 - 1, uval_2 != 0) {
      *arg1 = 0;
      arg1 = arg1 + 1;
    }
    *arg1 = 0;
  }
  if ((uval_1 & 1) != 0) {
    *(uint8_t *)arg1 = 0;
  }
  return;
}


