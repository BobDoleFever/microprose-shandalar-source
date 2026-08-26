/*
 * Decompiled function: FUN_0043a094
 * Entry Point: 0043a094
 * Size: 775 bytes
 */
#include "duel.h"


undefined4 FUN_0043a094(int arg_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int local_30;
  int local_28;
  int local_1c;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_28 = 0;
  local_10 = 0;
  local_30 = 0;
  local_8 = 0;
  if (arg_1 == -1) {
    for (local_1c = 0; local_1c < 500; local_1c = local_1c + 1) {
      if ((*(int *)(&deck + local_1c * 4) != -1) && (((&DAT_006c13b1)[local_1c * 4] & 0xc0) == 0)) {
        bVar1 = (&DAT_004ff596)[(*(uint *)(&deck + local_1c * 4) & 0xfff) * 0x34];
        if ((bVar1 & 2) != 0) {
          local_8 = local_8 + 1;
        }
        if ((bVar1 & 0x20) != 0) {
          local_30 = local_30 + 1;
        }
        if ((bVar1 & 8) != 0) {
          local_10 = local_10 + 1;
        }
        if ((bVar1 & 0x10) != 0) {
          local_28 = local_28 + 1;
        }
        if ((bVar1 & 4) != 0) {
          local_c = local_c + 1;
        }
      }
    }
  }
  else {
    for (local_1c = 0; local_1c < 0x50; local_1c = local_1c + 1) {
      iVar2 = (&DAT_004f71c4)[arg_1 * 0xa0 + local_1c * 2];
      if ((*(int *)(&DAT_004f71c0 + local_1c * 8 + arg_1 * 0x280) != -1) && (iVar2 != 0)) {
        iVar3 = CardTypeFromID(*(int *)(&DAT_004f71c0 + local_1c * 8 + arg_1 * 0x280));
        bVar1 = (&DAT_004ff596)[iVar3 * 0x34];
        if ((bVar1 & 2) != 0) {
          local_8 = local_8 + iVar2;
        }
        if ((bVar1 & 0x20) != 0) {
          local_30 = local_30 + iVar2;
        }
        if ((bVar1 & 8) != 0) {
          local_10 = local_10 + iVar2;
        }
        if ((bVar1 & 0x10) != 0) {
          local_28 = local_28 + iVar2;
        }
        if ((bVar1 & 4) != 0) {
          local_c = local_c + iVar2;
        }
      }
    }
  }
  local_14 = 0;
  if ((((local_8 < local_30) || (local_8 < local_10)) || (local_8 < local_28)) ||
     (local_8 < local_c)) {
    if (((local_30 < local_8) || (local_30 < local_10)) ||
       ((local_30 < local_28 || (local_30 < local_c)))) {
      if (((local_10 < local_8) || (local_10 < local_30)) ||
         ((local_10 < local_28 || (local_10 < local_c)))) {
        if ((((local_28 < local_8) || (local_28 < local_10)) || (local_28 < local_30)) ||
           (local_28 < local_c)) {
          if (((local_8 <= local_c) && (local_10 <= local_c)) &&
             ((local_28 <= local_c && (local_30 <= local_c)))) {
            local_14 = 2;
          }
        }
        else {
          local_14 = 4;
        }
      }
      else {
        local_14 = 3;
      }
    }
    else {
      local_14 = 5;
    }
  }
  else {
    local_14 = 1;
  }
  return local_14;
}


