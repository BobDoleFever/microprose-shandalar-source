/*
 * Decompiled function: FUN_0050d520
 * Entry Point: 0050d520
 * Size: 55 bytes
 */
#include "magic.h"


void FUN_0050d520(int arg_1)

{
  int iVar1;
  
  iVar1 = (&DAT_0070a850)[arg_1];
  BitBlt(*(HDC *)(DAT_0070a850 + 4),0,0,*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x24),
         *(HDC *)(iVar1 + 4),0,0,0xcc0020);
  return;
}


