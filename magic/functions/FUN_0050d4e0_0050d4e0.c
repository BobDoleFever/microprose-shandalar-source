/*
 * Decompiled function: FUN_0050d4e0
 * Entry Point: 0050d4e0
 * Size: 63 bytes
 */
#include "magic.h"


void FUN_0050d4e0(int arg_1)

{
  if ((*(HDC *)((&DAT_0070a850)[arg_1] + 4) != (HDC)0x0) && (*(HDC *)(DAT_0070a850 + 4) != (HDC)0x0)
     ) {
    BitBlt(*(HDC *)(DAT_0070a850 + 4),0,0,*(int *)(DAT_0070a850 + 0x20),
           *(int *)(DAT_0070a850 + 0x24),*(HDC *)((&DAT_0070a850)[arg_1] + 4),0,0,0xcc0020);
  }
  return;
}


