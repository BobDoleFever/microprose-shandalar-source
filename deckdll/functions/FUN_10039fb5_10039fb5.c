/*
 * Decompiled function: FUN_10039fb5
 * Entry Point: 10039fb5
 * Size: 1243 bytes
 */
#include "deckdll.h"


void FUN_10039fb5(int arg1,uint8_t arg2)

{
  int local_8;
  
  if (arg1 == 1) {
    for (local_8 = 0; local_8 < DAT_101cf920; local_8 = local_8 + 1) {
      if (*(int *)(&DAT_1016a628 + local_8 * 0x10) == 1) {
        if ((((((arg2 & 1) == 0) ||
              (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 1)) &&
             (((arg2 & 2) == 0 ||
              (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 2)))) &&
            (((arg2 & 4) == 0 ||
             (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 5)))) &&
           ((((arg2 & 8) == 0 ||
             (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 7)) &&
            ((((arg2 & 0x10) == 0 ||
              (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 8)) &&
             (((arg2 & 0x20) == 0 ||
              (*(int *)(&DAT_10176ac4 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 1)))))))) {
          if ((((((arg2 & 1) != 0) && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 0)) ||
               (((arg2 & 2) != 0 && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 1)))) ||
              ((((arg2 & 4) != 0 && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 2)) ||
               (((arg2 & 8) != 0 && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 3)))))) ||
             (((arg2 & 0x10) != 0 && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 4)))) {
            *(int32_t *)(&DAT_1016a628 + local_8 * 0x10) = 0;
            *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) =
                 *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) | 1 << (DAT_10162904 & 0x1f);
            thunk_FUN_100391f0((&DAT_1016a620)[local_8 * 4],1,0x101cded0);
          }
        }
        else {
          *(int32_t *)(&DAT_1016a628 + local_8 * 0x10) = 0;
          *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) =
               *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) | 1 << (DAT_10162904 & 0x1f);
          thunk_FUN_100391f0((&DAT_1016a620)[local_8 * 4],1,0x101cded0);
        }
      }
    }
  }
  else {
    for (local_8 = 0; local_8 < DAT_101cf920; local_8 = local_8 + 1) {
      if (*(int *)(&DAT_1016a628 + local_8 * 0x10) == 0) {
        if ((((((arg2 & 1) == 0) ||
              (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 1)) &&
             (((arg2 & 2) == 0 ||
              (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 2)))) &&
            ((((arg2 & 4) == 0 ||
              (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 5)) &&
             (((arg2 & 8) == 0 ||
              (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 7)))))) &&
           ((((arg2 & 0x10) == 0 ||
             (*(int *)(&DAT_10176ac0 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 8)) &&
            (((arg2 & 0x20) == 0 ||
             (*(int *)(&DAT_10176ac4 + (&DAT_1016a620)[local_8 * 4] * 0x98) != 1)))))) {
          if (((((arg2 & 1) != 0) && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 0)) ||
              (((((arg2 & 2) != 0 && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 1)) ||
                (((arg2 & 4) != 0 && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 2)))) ||
               (((arg2 & 8) != 0 && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 3)))))) ||
             (((arg2 & 0x10) != 0 && (*(int *)(&DAT_1016a624 + local_8 * 0x10) == 4)))) {
            *(int32_t *)(&DAT_1016a628 + local_8 * 0x10) = 1;
            *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) =
                 *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) & ~(1 << (DAT_10162904 & 0x1f));
            thunk_FUN_100395de((&DAT_1016a620)[local_8 * 4],1,0x101cded0);
          }
        }
        else {
          *(int32_t *)(&DAT_1016a628 + local_8 * 0x10) = 1;
          *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) =
               *(uint32_t *)(&DAT_1016a62c + local_8 * 0x10) & ~(1 << (DAT_10162904 & 0x1f));
          thunk_FUN_100395de((&DAT_1016a620)[local_8 * 4],1,0x101cded0);
        }
      }
    }
  }
  return;
}


