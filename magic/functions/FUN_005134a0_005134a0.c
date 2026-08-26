/*
 * Decompiled function: FUN_005134a0
 * Entry Point: 005134a0
 * Size: 109 bytes
 */
#include "magic.h"


void FUN_005134a0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    iVar2 = iVar2 + 0xc;
    *(int *)(DAT_006261e4 + -4 + iVar2) = iVar1;
    *(int *)(DAT_006261e4 + -0xc + iVar2) = iVar1;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(DAT_006261e4 + -8 + iVar2) = 0xffffffff;
  } while (iVar2 < 0xc00);
  if (iVar1 < 0xffb) {
    iVar1 = iVar1 * 0xc;
    do {
      iVar1 = iVar1 + 0xc;
      *(undefined4 *)(DAT_006261e4 + -0xc + iVar1) = 0xffffffff;
    } while (iVar1 < 0xbfc4);
  }
  DAT_006261bc = 9;
  DAT_006261ec = 0x101;
  return;
}


