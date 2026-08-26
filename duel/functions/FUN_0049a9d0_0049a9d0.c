/*
 * Decompiled function: FUN_0049a9d0
 * Entry Point: 0049a9d0
 * Size: 68 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049a9d0(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  DAT_00664dbc = DVar1 & 0x7fff;
  Mem_AllocOrFree_004d9830(DAT_00664dbc * 0x43);
  _DAT_00664db8 = 1;
  return 0;
}


