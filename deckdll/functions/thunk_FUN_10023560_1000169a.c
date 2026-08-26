/*
 * Decompiled function: thunk_FUN_10023560
 * Entry Point: 1000169a
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10023560(int32_t *arg_1,int32_t arg_2,int arg_3)

{
  *arg_1 = 0x28;
  arg_1[1] = arg_2;
  arg_1[2] = -arg_3;
  *(int16_t *)(arg_1 + 3) = 1;
  *(int16_t *)((int)arg_1 + 0xe) = 0x18;
  arg_1[4] = 0;
  arg_1[5] = 0;
  arg_1[6] = 0;
  arg_1[7] = 0;
  arg_1[8] = 0x100;
  arg_1[9] = 0x100;
  return;
}


