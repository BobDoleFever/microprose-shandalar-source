/*
 * Decompiled function: FUN_0044c82c
 * Entry Point: 0044c82c
 * Size: 196 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0044c82c(undefined4 arg1,short arg2)

{
  ushort uVar1;
  ushort uVar2;
  
  DAT_00694440 = 10;
  DAT_00694441 = 5;
  DAT_00694442 = 1;
  DAT_00694443 = 8;
  DAT_00694444 = 0;
  uVar1 = (ushort)arg1;
  DAT_00694448 = uVar1 - 1;
  DAT_00694446 = 0;
  DAT_0069444a = arg2 + -1;
  _DAT_0069444c = 0;
  _DAT_0069444e = 0;
  DAT_00694480 = 0;
  DAT_00694481 = 1;
  uVar2 = (ushort)((int)arg1 >> 0x1f);
  DAT_00694482 = uVar1 + (((uVar1 ^ uVar2) - uVar2 & 1 ^ uVar2) - uVar2);
  _DAT_00694484 = 1;
  _DAT_00694486 = 0;
  _DAT_00694488 = 0;
  FID_conflict___fwrite_lk(&DAT_00694440,0x80,1,DAT_00694434);
  return 0;
}


