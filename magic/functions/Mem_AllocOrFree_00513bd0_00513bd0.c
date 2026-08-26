/*
 * Decompiled function: Mem_AllocOrFree_00513bd0
 * Entry Point: 00513bd0
 * Size: 47 bytes
 */
#include "magic.h"


/* WARNING: Unable to track spacebase fully for stack */

void Mem_AllocOrFree_00513bd0(void)

{
  uint in_EAX;
  undefined1 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = &stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x1000;
  }
  *(undefined4 *)(puVar1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}


