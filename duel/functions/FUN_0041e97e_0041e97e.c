/*
 * Decompiled function: FUN_0041e97e
 * Entry Point: 0041e97e
 * Size: 184 bytes
 */
#include "duel.h"


undefined4 FUN_0041e97e(int arg1,int arg2)

{
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  if (*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) < 5) {
    local_8 = 1;
  }
  else {
    for (local_c = 0; local_c < 5; local_c = local_c + 1) {
      if ((&DAT_0068f0e0)[local_c] ==
          *(int *)(&DAT_004ff590 + *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34)) {
        local_8 = 1;
      }
    }
  }
  return local_8;
}


