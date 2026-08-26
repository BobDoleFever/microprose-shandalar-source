/*
 * Decompiled function: thunk_FUN_10039c49
 * Entry Point: 100010fa
 * Size: 5 bytes
 */
#include "deckdll.h"


uint32_t thunk_FUN_10039c49(int arg_1)

{
  int iStack_c;
  uint32_t uStack_8;
  
  uStack_8 = 0;
  if (arg_1 == 1) {
    for (iStack_c = 0; iStack_c < DAT_101cf920; iStack_c = iStack_c + 1) {
      if (*(int *)(&DAT_1016a628 + iStack_c * 0x10) == 0) {
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 1) {
          uStack_8 = uStack_8 | 1;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 2) {
          uStack_8 = uStack_8 | 2;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 5) {
          uStack_8 = uStack_8 | 4;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 7) {
          uStack_8 = uStack_8 | 8;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 8) {
          uStack_8 = uStack_8 | 0x10;
        }
        if (*(int *)(&DAT_10176ac4 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 1) {
          uStack_8 = uStack_8 | 0x20;
        }
        if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 0) {
          uStack_8 = uStack_8 | 1;
        }
        else if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 1) {
          uStack_8 = uStack_8 | 2;
        }
        else if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 2) {
          uStack_8 = uStack_8 | 4;
        }
        else if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 3) {
          uStack_8 = uStack_8 | 8;
        }
        else if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 4) {
          uStack_8 = uStack_8 | 0x10;
        }
      }
    }
  }
  else {
    for (iStack_c = 0; iStack_c < DAT_101cf920; iStack_c = iStack_c + 1) {
      if (*(int *)(&DAT_1016a628 + iStack_c * 0x10) == 1) {
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 1) {
          uStack_8 = uStack_8 | 1;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 2) {
          uStack_8 = uStack_8 | 2;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 5) {
          uStack_8 = uStack_8 | 4;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 7) {
          uStack_8 = uStack_8 | 8;
        }
        if (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 8) {
          uStack_8 = uStack_8 | 0x10;
        }
        if (*(int *)(&DAT_10176ac4 + (&DAT_1016a620)[iStack_c * 4] * 0x98) == 1) {
          uStack_8 = uStack_8 | 0x20;
        }
        if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 0) {
          uStack_8 = uStack_8 | 1;
        }
        else if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 1) {
          uStack_8 = uStack_8 | 2;
        }
        else if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 2) {
          uStack_8 = uStack_8 | 4;
        }
        else if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 3) {
          uStack_8 = uStack_8 | 8;
        }
        else if (*(int *)(&DAT_1016a624 + iStack_c * 0x10) == 4) {
          uStack_8 = uStack_8 | 0x10;
        }
      }
    }
  }
  return uStack_8;
}


