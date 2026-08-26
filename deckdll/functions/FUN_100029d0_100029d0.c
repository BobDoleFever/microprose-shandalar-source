/*
 * Decompiled function: FUN_100029d0
 * Entry Point: 100029d0
 * Size: 110 bytes
 */
#include "deckdll.h"


void FUN_100029d0(undefined8 *arg_1,uint32_t arg_2,uint32_t arg_3)

{
  uint32_t uval_1;
  int val_2;
  uint32_t arg2;
  undefined8 uval_3;
  
  uval_1 = arg_2 << 8 | arg_2;
  arg2 = (int)uval_1 >> 0x1f | ((int)uval_1 >> 0x1f) << 0x10 | uval_1 >> 0x10;
  uval_3 = __allshl(0x20,arg2);
  uval_3 = CONCAT44(arg2 | (uint32_t)((ulonglong)uval_3 >> 0x20),uval_1 | uval_1 << 0x10 | (uint32_t)uval_3);
  val_2 = (arg_3 >> 3) - 1;
  do {
    *arg_1 = uval_3;
    arg_1 = arg_1 + 1;
    val_2 = val_2 + -1;
  } while (val_2 != 0);
  *arg_1 = uval_3;
  for (uval_1 = arg_3 & 7; uval_1 != 0; uval_1 = uval_1 - 1) {
    *(char *)arg_1 = (char)arg_2;
    arg_1 = (undefined8 *)((int)arg_1 + 1);
  }
  return;
}


