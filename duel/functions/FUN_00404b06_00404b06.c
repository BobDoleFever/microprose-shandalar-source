/*
 * Decompiled function: FUN_00404b06
 * Entry Point: 00404b06
 * Size: 206 bytes
 */
#include "duel.h"


int FUN_00404b06(int arg_1,int arg_2,int arg_3)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  for (arg_1 = 0; arg_1 < 2; arg_1 = arg_1 + 1) {
    if ((arg_3 == -1) || (arg_3 == arg_1)) {
      for (local_8 = 0; local_8 < (int)(&DAT_00666408)[arg_1]; local_8 = local_8 + 1) {
        if ((*(int *)(&DAT_006826c4 + local_8 * 0x120 + arg_1 * 0x5b20) == arg_2) &&
           (((&DAT_006826cc)[local_8 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
          local_c = local_c + 1;
        }
      }
    }
  }
  return local_c;
}


