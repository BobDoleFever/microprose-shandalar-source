/*
 * Decompiled function: FUN_00467d65
 * Entry Point: 00467d65
 * Size: 210 bytes
 */
#include "duel.h"


void FUN_00467d65(undefined *arg1,int arg2)

{
  int local_10;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if ((arg2 == -1) || (local_8 == arg2)) {
      for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_8]; local_10 = local_10 + 1) {
        if ((*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) != -1) &&
           (((&DAT_006826cc)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
          (*(code *)arg1)(local_8,local_10,
                          *(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20));
        }
      }
    }
  }
  return;
}


