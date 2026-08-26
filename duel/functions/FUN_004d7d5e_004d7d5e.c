/*
 * Decompiled function: FUN_004d7d5e
 * Entry Point: 004d7d5e
 * Size: 121 bytes
 */
#include "duel.h"


int FUN_004d7d5e(int arg_1)

{
  int local_8;
  
  if (arg_1 != -1) {
    for (local_8 = 0; local_8 < DAT_00665ed0 + 0x10; local_8 = local_8 + 1) {
      if (*(int *)(&DAT_004ff590 + local_8 * 0x34) == arg_1) {
        return local_8;
      }
    }
  }
  return -1;
}


