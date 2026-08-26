/*
 * Decompiled function: FUN_1000b760
 * Entry Point: 1000b760
 * Size: 61 bytes
 */
#include "statwin.h"


uint32_t __fastcall FUN_1000b760(int arg_1)

{
  int val_1;
  
  val_1 = (uint32_t)*(uint16_t *)(*(int *)(arg_1 + 4) + 0xe) * *(int *)(*(int *)(arg_1 + 4) + 4);
  return ((int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc;
}


