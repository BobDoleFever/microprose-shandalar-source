/*
 * Decompiled function: FUN_00463699
 * Entry Point: 00463699
 * Size: 190 bytes
 */
#include "duel.h"


undefined4 FUN_00463699(int arg1,int arg2)

{
  if (((char)(&DAT_006826d2)[arg2 * 0x120 + arg1 * 0x5b20] == DAT_00522424) &&
     (*(int *)(&DAT_006826e8 + arg2 * 0x120 + arg1 * 0x5b20) == DAT_00522414)) {
    *(undefined4 *)(&DAT_006826e8 + arg2 * 0x120 + arg1 * 0x5b20) = DAT_00522410;
  }
  return 0;
}


