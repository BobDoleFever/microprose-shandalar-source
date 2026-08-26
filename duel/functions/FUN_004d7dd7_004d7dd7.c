/*
 * Decompiled function: FUN_004d7dd7
 * Entry Point: 004d7dd7
 * Size: 82 bytes
 */
#include "duel.h"


void FUN_004d7dd7(undefined4 arg_1)

{
  int iVar1;
  
  if (DAT_0066aaf4 != 1) {
    Mem_AllocOrFree_004b9448();
    iVar1 = Mem_AllocOrFree_0049f5c6(arg_1);
    if (8 < iVar1 + 8) {
      FUN_0045143b(arg_1);
    }
    Mem_AllocOrFree_004b943d();
  }
  return;
}


