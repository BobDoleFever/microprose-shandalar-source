/*
 * Decompiled function: FUN_10039c49
 * Entry Point: 10039c49
 * Size: 876 bytes
 */
#include "deckdll.h"


uint32_t FUN_10039c49(int arg_1)

{
  int local_c;
  uint32_t local_8;
  
  local_8 = 0;
  if (arg_1 == 1) {
    for (local_c = 0; local_c < DAT_101cf920; local_c = local_c + 1) {
      if (*(int *)(&DAT_1016a628 + local_c * 0x10) == 0) {
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 1) {
          local_8 = local_8 | 1;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 2) {
          local_8 = local_8 | 2;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 5) {
          local_8 = local_8 | 4;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 7) {
          local_8 = local_8 | 8;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 8) {
          local_8 = local_8 | 0x10;
        }
        if (*(int *)(&DAT_10176ac4 + (&DAT_1016a620)[local_c * 4] * 0x98) == 1) {
          local_8 = local_8 | 0x20;
        }
        if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 0) {
          local_8 = local_8 | 1;
        }
        else if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 1) {
          local_8 = local_8 | 2;
        }
        else if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 2) {
          local_8 = local_8 | 4;
        }
        else if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 3) {
          local_8 = local_8 | 8;
        }
        else if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 4) {
          local_8 = local_8 | 0x10;
        }
      }
    }
  }
  else {
    for (local_c = 0; local_c < DAT_101cf920; local_c = local_c + 1) {
      if (*(int *)(&DAT_1016a628 + local_c * 0x10) == 1) {
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 1) {
          local_8 = local_8 | 1;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 2) {
          local_8 = local_8 | 2;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 5) {
          local_8 = local_8 | 4;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 7) {
          local_8 = local_8 | 8;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_c * 4] * 0x98) == 8) {
          local_8 = local_8 | 0x10;
        }
        if (*(int *)(&DAT_10176ac4 + (&DAT_1016a620)[local_c * 4] * 0x98) == 1) {
          local_8 = local_8 | 0x20;
        }
        if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 0) {
          local_8 = local_8 | 1;
        }
        else if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 1) {
          local_8 = local_8 | 2;
        }
        else if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 2) {
          local_8 = local_8 | 4;
        }
        else if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 3) {
          local_8 = local_8 | 8;
        }
        else if (*(int *)(&DAT_1016a624 + local_c * 0x10) == 4) {
          local_8 = local_8 | 0x10;
        }
      }
    }
  }
  return local_8;
}


