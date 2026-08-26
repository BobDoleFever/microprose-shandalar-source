/*
 * Decompiled function: ColorOctree_CollectLeaves
 * Entry Point: 004940c0
 * Size: 85 bytes
 */
#include "magic.h"


void ColorOctree_CollectLeaves(int *arg_1,int arg_2,int *arg_3)

{
  int *piVar1;
  int iVar2;
  
  if (*arg_1 != 0) {
    *(char *)(*arg_3 + arg_2) = (char)arg_1[1];
    *arg_3 = *arg_3 + 1;
    return;
  }
  piVar1 = arg_1 + 2;
  iVar2 = 8;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      ColorOctree_CollectLeaves((int *)*piVar1,arg_2,arg_3);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


