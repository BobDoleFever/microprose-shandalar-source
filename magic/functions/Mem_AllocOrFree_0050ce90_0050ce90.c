/*
 * Decompiled function: Mem_AllocOrFree_0050ce90
 * Entry Point: 0050ce90
 * Size: 21 bytes
 */
#include "magic.h"


undefined4 Mem_AllocOrFree_0050ce90(undefined4 arg1,int arg2)

{
  undefined4 uVar1;
  
  if (arg2 != 0) {
    uVar1 = FUN_0050edf0((char *)arg2);
    return uVar1;
  }
  return 0;
}


