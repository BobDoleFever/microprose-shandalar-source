/*
 * Decompiled function: thunk_FUN_10003410
 * Entry Point: 1000140b
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10003410(int32_t arg_1,int arg_2,int arg_3)

{
  int32_t *u_ptr_1;
  int val_2;
  size_t _Size;
  
  if (arg_3 == 8) {
    _Size = 0x42c;
  }
  else {
    _Size = 0x2c;
  }
  u_ptr_1 = malloc(_Size);
  *u_ptr_1 = 0x28;
  val_2 = 0;
  u_ptr_1[1] = arg_1;
  u_ptr_1[2] = -arg_2;
  *(int16_t *)(u_ptr_1 + 3) = 1;
  *(short *)((int)u_ptr_1 + 0xe) = (short)arg_3;
  u_ptr_1[4] = 0;
  u_ptr_1[5] = 0;
  u_ptr_1[6] = 0;
  u_ptr_1[7] = 0;
  if (arg_3 == 8) {
    u_ptr_1[8] = 0x100;
    u_ptr_1[9] = 0x100;
    u_ptr_1 = u_ptr_1 + 10;
    do {
      *(short *)u_ptr_1 = (short)val_2;
      u_ptr_1 = (int32_t *)((int)u_ptr_1 + 2);
      val_2 = val_2 + 1;
    } while (val_2 < 0x100);
    return;
  }
  u_ptr_1[8] = 0;
  u_ptr_1[9] = 0;
  return;
}


