/*
 * Decompiled function: FUN_00485c56
 * Entry Point: 00485c56
 * Size: 159 bytes
 */
#include "duel.h"


bool FUN_00485c56(int arg1,int arg2)

{
  return ((*(uint *)(arg2 + 0xc) ^ *(uint *)(arg1 + 0xc) & 0x10) & 0x10) == 0 &&
         (((*(uint *)(arg2 + 0xc) ^ *(uint *)(arg1 + 0xc) & 0x30000) & 0x30000) == 0 &&
         (*(int *)(arg2 + 0x44) == *(int *)(arg1 + 0x44) && *(int *)(arg2 + 4) == *(int *)(arg1 + 4)
         ));
}


