/*
 * Decompiled function: FUN_0041dd17
 * Entry Point: 0041dd17
 * Size: 249 bytes
 */
#include "duel.h"


int FUN_0041dd17(int arg1,int arg2)

{
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_8 = 0;
  while ((local_8 < 2 && (local_10 == 0))) {
    local_c = 0;
    while ((local_c < (int)(&DAT_00666408)[local_8] && (local_10 == 0))) {
      if (((*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) == DAT_0068f104) &&
          ((char)(&DAT_006826d2)[local_c * 0x120 + local_8 * 0x5b20] == arg1)) &&
         (*(int *)(&DAT_006826e8 + local_c * 0x120 + local_8 * 0x5b20) == arg2)) {
        local_10 = 1;
      }
      local_c = local_c + 1;
    }
    local_8 = local_8 + 1;
  }
  return local_10;
}


