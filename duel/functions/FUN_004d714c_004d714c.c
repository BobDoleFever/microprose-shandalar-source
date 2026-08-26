/*
 * Decompiled function: FUN_004d714c
 * Entry Point: 004d714c
 * Size: 154 bytes
 */
#include "duel.h"


undefined4 FUN_004d714c(void)

{
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
      if (*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) == -1) {
        *(undefined4 *)(&DAT_006826c0 + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
      }
    }
  }
  return 0;
}


