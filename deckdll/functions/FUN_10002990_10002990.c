/*
 * Decompiled function: FUN_10002990
 * Entry Point: 10002990
 * Size: 45 bytes
 */
#include "deckdll.h"


void FUN_10002990(undefined8 *arg_1,undefined8 *arg_2,uint32_t arg_3)

{
  uint32_t uval_1;
  
  for (uval_1 = arg_3 >> 3; uval_1 != 0; uval_1 = uval_1 - 1) {
    *arg_1 = *arg_2;
    arg_2 = arg_2 + 1;
    arg_1 = arg_1 + 1;
  }
  uval_1 = arg_3 & 7;
  if (uval_1 != 0) {
    for (; uval_1 != 0; uval_1 = uval_1 - 1) {
      *(uint8_t *)arg_1 = *(uint8_t *)arg_2;
      arg_2 = (undefined8 *)((int)arg_2 + 1);
      arg_1 = (undefined8 *)((int)arg_1 + 1);
    }
  }
  return;
}


