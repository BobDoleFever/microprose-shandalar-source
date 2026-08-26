/*
 * Decompiled function: Mem_AllocOrFree_00409e3c
 * Entry Point: 00409e3c
 * Size: 49 bytes
 */
#include "magic.h"


undefined4 Mem_AllocOrFree_00409e3c(undefined4 arg_1)

{
  undefined4 uVar1;
  
  if (DAT_00701024 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_00701024)(arg_1);
  }
  return uVar1;
}


