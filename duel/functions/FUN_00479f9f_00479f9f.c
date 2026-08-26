/*
 * Decompiled function: FUN_00479f9f
 * Entry Point: 00479f9f
 * Size: 237 bytes
 */
#include "duel.h"


undefined4 FUN_00479f9f(int arg1,int arg2)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  do {
    if (1 < local_c) {
      return 0;
    }
    for (local_8 = 0; local_8 < (int)(&DAT_00666408)[local_c]; local_8 = local_8 + 1) {
      if ((((char)(&DAT_006826d2)[local_8 * 0x120 + local_c * 0x5b20] == arg1) &&
          (*(int *)(&DAT_006826e8 + local_8 * 0x120 + local_c * 0x5b20) == arg2)) &&
         (*(int *)(&DAT_004ff590 +
                  *(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) * 0x34) == 0x285)) {
        return 1;
      }
    }
    local_c = local_c + 1;
  } while( true );
}


