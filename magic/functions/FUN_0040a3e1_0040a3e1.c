/*
 * Decompiled function: FUN_0040a3e1
 * Entry Point: 0040a3e1
 * Size: 65 bytes
 */
#include "magic.h"


void FUN_0040a3e1(void)

{
  int iVar1;
  
  iVar1 = DAT_005239ec;
  while (iVar1 != 0) {
    Pic_Subsystem_0044b84b();
    iVar1 = DAT_0067bda0;
  }
  while (iVar1 = Mem_AllocOrFree_00408089(), iVar1 != 0) {
    FUN_0048ac2f();
  }
  return;
}


