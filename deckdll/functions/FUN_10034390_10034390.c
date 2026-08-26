/*
 * Decompiled function: FUN_10034390
 * Entry Point: 10034390
 * Size: 305 bytes
 */
#include "deckdll.h"


uint32_t FUN_10034390(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  int val_1;
  uint32_t *u_ptr_2;
  uint32_t uval_3;
  uint32_t uval_4;
  int32_t local_10;
  
  if (arg_1 == 0) {
    local_10 = 0;
  }
  else if ((((arg_2 == 0x20) || (arg_2 == 0x18)) || (arg_2 == 0x10)) || (arg_2 == 8)) {
    val_1 = (int)(arg_2 + (arg_2 >> 0x1f & 7U)) >> 3;
    uval_3 = arg_3 * val_1 >> 0x1f;
    uval_3 = 4 - (((arg_3 * val_1 ^ uval_3) - uval_3 & 3 ^ uval_3) - uval_3);
    uval_4 = (int)uval_3 >> 0x1f;
    u_ptr_2 = (uint32_t *)((arg_3 * val_1 + (((uval_3 ^ uval_4) - uval_4 & 3 ^ uval_4) - uval_4)) * arg_5 +
                      arg_4 * val_1 + arg_1);
    if (arg_2 == 0x20) {
      local_10 = *u_ptr_2;
    }
    else if (arg_2 == 0x18) {
      local_10 = (uint32_t)(uint8_t)*u_ptr_2 << 0x10 | (uint32_t)*(uint8_t *)((int)u_ptr_2 + 1) << 8 |
                 (uint32_t)*(uint8_t *)((int)u_ptr_2 + 2);
    }
    else if (arg_2 == 0x10) {
      local_10 = (uint32_t)CONCAT11((uint8_t)*u_ptr_2,*(uint8_t *)((int)u_ptr_2 + 1));
    }
    else if (arg_2 == 8) {
      local_10 = (uint32_t)(uint8_t)*u_ptr_2;
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}


