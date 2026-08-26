/*
 * Decompiled function: FUN_00478e3b
 * Entry Point: 00478e3b
 * Size: 94 bytes
 */
#include "duel.h"


void FUN_00478e3b(void)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_00522a68 + local_c * 4 + local_8 * 0x40) = 0;
    }
  }
  return;
}


