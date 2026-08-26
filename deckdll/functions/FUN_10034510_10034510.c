/*
 * Decompiled function: FUN_10034510
 * Entry Point: 10034510
 * Size: 278 bytes
 */
#include "deckdll.h"


void FUN_10034510(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int32_t arg_6)

{
  uint8_t uval_3;
  int val_1;
  int32_t *u_ptr_2;
  uint32_t uval_4;
  uint32_t uval_5;
  
  if ((arg_1 != 0) && ((((arg_2 == 0x20 || (arg_2 == 0x18)) || (arg_2 == 0x10)) || (arg_2 == 8)))) {
    val_1 = (int)(arg_2 + (arg_2 >> 0x1f & 7U)) >> 3;
    uval_4 = arg_3 * val_1 >> 0x1f;
    uval_4 = 4 - (((arg_3 * val_1 ^ uval_4) - uval_4 & 3 ^ uval_4) - uval_4);
    uval_5 = (int)uval_4 >> 0x1f;
    u_ptr_2 = (int32_t *)
             ((arg_3 * val_1 + (((uval_4 ^ uval_5) - uval_5 & 3 ^ uval_5) - uval_5)) * arg_5 +
              arg_4 * val_1 + arg_1);
    if (arg_2 == 0x20) {
      *u_ptr_2 = arg_6;
    }
    else {
      uval_3 = (uint8_t)((uint32_t)arg_6 >> 8);
      if (arg_2 == 0x18) {
        *(char *)u_ptr_2 = (char)((uint32_t)arg_6 >> 0x10);
        *(uint8_t *)((int)u_ptr_2 + 1) = uval_3;
        *(uint8_t *)((int)u_ptr_2 + 2) = (uint8_t)arg_6;
      }
      else if (arg_2 == 0x10) {
        *(uint8_t *)u_ptr_2 = uval_3;
        *(uint8_t *)((int)u_ptr_2 + 1) = (uint8_t)arg_6;
      }
      else if (arg_2 == 8) {
        *(uint8_t *)u_ptr_2 = (uint8_t)arg_6;
      }
    }
  }
  return;
}


