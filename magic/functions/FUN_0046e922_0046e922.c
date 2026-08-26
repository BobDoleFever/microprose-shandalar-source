/*
 * Decompiled function: FUN_0046e922
 * Entry Point: 0046e922
 * Size: 62 bytes
 */
#include "magic.h"


int FUN_0046e922(uint arg_1)

{
  char cVar1;
  undefined1 local_8;
  
  do {
    cVar1 = FUN_0040a1d2(5);
    local_8 = cVar1 + 1;
  } while ((arg_1 & 1 << (local_8 & 0x1f)) != 0);
  return 1 << (local_8 & 0x1f);
}


