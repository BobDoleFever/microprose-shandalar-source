/*
 * Decompiled function: FUN_0040a2c0
 * Entry Point: 0040a2c0
 * Size: 69 bytes
 */
#include "magic.h"


undefined4 FUN_0040a2c0(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  DAT_00701018 = DVar1 & 0x7fff;
  srand(DAT_00701018 * 0x43);
  DAT_00701014 = 1;
  return 0;
}


