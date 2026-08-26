/*
 * Decompiled function: ColorOctree_FreeTree
 * Entry Point: 004942a0
 * Size: 106 bytes
 */
#include "magic.h"


int ColorOctree_FreeTree(int *arg_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  if (*arg_1 == 0) {
    piVar3 = arg_1 + 2;
    iVar4 = 8;
    do {
      if ((int *)*piVar3 != (int *)0x0) {
        iVar1 = ColorOctree_FreeTree((int *)*piVar3);
        iVar2 = iVar2 + iVar1;
      }
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if ((void *)arg_1[10] != (void *)0x0) {
      free((void *)arg_1[10]);
    }
    free(arg_1);
    return iVar2;
  }
  free(arg_1);
  return 1;
}


