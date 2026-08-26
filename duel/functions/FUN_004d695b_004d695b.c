/*
 * Decompiled function: FUN_004d695b
 * Entry Point: 004d695b
 * Size: 186 bytes
 */
#include "duel.h"


int FUN_004d695b(int arg1,int arg2)

{
  int local_8;
  
  if (arg2 != -1) {
    for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
      if (*(int *)(&DAT_006826c0 + local_8 * 0x120 + arg1 * 0x5b20) == -1) {
        FUN_004d6a15(arg1,arg2,local_8);
        if ((int)(&DAT_00666408)[arg1] <= local_8) {
          (&DAT_00666408)[arg1] = local_8 + 1;
          return local_8;
        }
        return local_8;
      }
    }
    FUN_004d7e62(s_AddCard_error_005092d0);
  }
  return -1;
}


