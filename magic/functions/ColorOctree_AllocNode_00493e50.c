/*
 * Decompiled function: ColorOctree_AllocNode
 * Entry Point: 00493e50
 * Size: 29 bytes
 */
#include "magic.h"


undefined4 * ColorOctree_AllocNode(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = malloc(0x30);
  puVar3 = puVar1;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  return puVar1;
}


