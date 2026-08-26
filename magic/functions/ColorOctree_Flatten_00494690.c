/*
 * Decompiled function: ColorOctree_Flatten
 * Entry Point: 00494690
 * Size: 81 bytes
 */
#include "magic.h"


int ColorOctree_Flatten(int *arg1,int *arg2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*arg1 != 0) {
    *arg2 = arg1[1];
    return 1;
  }
  piVar2 = arg1 + 2;
  iVar3 = 8;
  do {
    if ((int *)*piVar2 != (int *)0x0) {
      iVar1 = ColorOctree_Flatten((int *)*piVar2,arg2);
      iVar4 = iVar4 + iVar1;
      arg2 = arg2 + iVar1;
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar4;
}


