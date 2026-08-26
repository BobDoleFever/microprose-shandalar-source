/*
 * Decompiled function: FUN_0046b41c
 * Entry Point: 0046b41c
 * Size: 159 bytes
 */
#include "magic.h"


bool FUN_0046b41c(int arg1,int arg2)

{
  return ((*(uint *)(arg1 + 0xc) ^ *(uint *)(arg2 + 0xc) & 0x10) & 0x10) == 0 &&
         (((*(uint *)(arg1 + 0xc) ^ *(uint *)(arg2 + 0xc) & 0x30000) & 0x30000) == 0 &&
         (*(int *)(arg1 + 0x44) == *(int *)(arg2 + 0x44) && *(int *)(arg1 + 4) == *(int *)(arg2 + 4)
         ));
}


