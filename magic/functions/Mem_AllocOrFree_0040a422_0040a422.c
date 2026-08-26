/*
 * Decompiled function: Mem_AllocOrFree_0040a422
 * Entry Point: 0040a422
 * Size: 34 bytes
 */
#include "magic.h"


void Mem_AllocOrFree_0040a422(void)

{
  int iVar1;
  
  while( true ) {
    iVar1 = Mem_AllocOrFree_00408089();
    if (iVar1 == 0) break;
    FUN_0048ac2f();
  }
  return;
}


