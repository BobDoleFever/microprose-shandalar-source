/*
 * Decompiled function: FUN_0040f78d
 * Entry Point: 0040f78d
 * Size: 554 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0040f78d(int arg_1)

{
  int iVar1;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  iVar1 = arg_1 * 7;
  local_20 = (int)(char)(&DAT_00522628)[arg_1 * 0x1dc];
  if ((iVar1 < 0x25) && (iVar1 % 7 != 0)) {
    local_20 = local_20 + DAT_0067f380 * 2;
  }
  else if ((iVar1 < 0x25) && (iVar1 % 7 == 0)) {
    local_20 = local_20 + DAT_0067f380 * 5;
  }
  else if (iVar1 < 0x37) {
    local_20 = local_20 + DAT_0067f380 * 2;
  }
  else if (0x36 < iVar1) {
    local_20 = local_20 + DAT_0067f380 * 0x32;
  }
  if ((&DAT_0052262a)[arg_1 * 0x1dc] == '\v') {
    for (local_10 = 0; local_10 < 10; local_10 = local_10 + 1) {
      if ((_DAT_0067f374 & 1 << ((byte)local_10 & 0x1f)) != 0) {
        local_20 = local_20 + 1;
      }
    }
  }
  if ((&DAT_0052262a)[arg_1 * 0x1dc] == '\f') {
    local_18 = 0;
    local_8 = 0;
    for (local_10 = 0; (local_10 < 1000 && ((&DAT_0067b9b0)[local_10] != '\0'));
        local_10 = local_10 + 1) {
      if ((int)(char)(&DAT_0067b9b0)[local_10] >> 4 == 1 << ((byte)arg_1 & 0x1f)) {
        local_18 = local_18 + 1;
      }
    }
    for (local_14 = 0; local_14 < 0x80; local_14 = local_14 + 1) {
      if (((&DAT_0067be01)[local_14 * 100] != '\0') &&
         ((*(int *)(&DAT_0067be00 + local_14 * 100) >> 8) + -1 == local_10)) {
        local_8 = local_8 + 1;
      }
    }
    iVar1 = ((local_20 + 10) - local_18) + DAT_0067f380 * local_8;
    local_20 = DAT_0067f380 * 5 + 0x14;
    if (local_20 <= iVar1) {
      local_20 = iVar1;
    }
  }
  return local_20;
}


