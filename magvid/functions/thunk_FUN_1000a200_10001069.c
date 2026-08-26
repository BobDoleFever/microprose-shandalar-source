/*
 * Decompiled function: thunk_FUN_1000a200
 * Entry Point: 10001069
 * Size: 5 bytes
 */
#include "magvid.h"


uint32_t __fastcall thunk_FUN_1000a200(int arg_1)

{
  int val_1;
  
  val_1 = (uint32_t)*(uint16_t *)(*(int *)(arg_1 + 4) + 0xe) * *(int *)(*(int *)(arg_1 + 4) + 4);
  return ((int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3) + 3U & 0xfffffffc;
}


