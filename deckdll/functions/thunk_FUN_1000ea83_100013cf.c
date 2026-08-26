/*
 * Decompiled function: thunk_FUN_1000ea83
 * Entry Point: 100013cf
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1000ea83(uint32_t arg1,uint32_t *arg2)

{
  int val_1;
  int val_2;
  int val_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t uval_6;
  
  val_1 = ((arg1 & 0xff0000) >> 0x10) * 8;
  uval_4 = *(uint32_t *)(&DAT_102012d4 + val_1);
  val_2 = (arg1 >> 8 & 0xff) * 8;
  uval_5 = *(uint32_t *)(&DAT_10201ad4 + val_2);
  val_3 = (arg1 & 0xff) * 8;
  uval_6 = *(uint32_t *)(&DAT_102022d4 + val_3);
  *arg2 = *(uint32_t *)(&DAT_102012d0 + val_1) | *(uint32_t *)(&DAT_10201ad0 + val_2) |
          *(uint32_t *)(&DAT_102022d0 + val_3);
  arg2[1] = uval_4 | uval_5 | uval_6;
  return;
}


