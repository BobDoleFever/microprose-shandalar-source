/*
 * Decompiled function: FUN_0043071d
 * Entry Point: 0043071d
 * Size: 75 bytes
 */
#include "duel.h"


undefined4 FUN_0043071d(int arg_1)

{
  if ((DAT_0066aaf4 != 1) &&
     (DAT_0068f0bc = *(uint *)(&DAT_0050ed70 + (arg_1 + DAT_0050b37c) * 4),
     DAT_0068f0bc != 0xffffffff)) {
    DAT_0068f0bc = DAT_0068f0bc & 0xfff;
  }
  return 0;
}


