/*
 * Decompiled function: FUN_0042a99c
 * Entry Point: 0042a99c
 * Size: 172 bytes
 */
#include "duel.h"


undefined4 FUN_0042a99c(void)

{
  if ((DAT_0066ab04 != -1) && (DAT_0066aaf4 != 1)) {
    if ((DAT_0068f2c4 < DAT_0066ab04) || (DAT_0066aac4 != DAT_00666458)) {
      return 1;
    }
    if ((DAT_0068f230 != -1) && (DAT_0068f2c4 == DAT_0066ab04)) {
      return 1;
    }
    if ((DAT_0066ab04 < DAT_0068f2c4) && (DAT_0066aac4 == DAT_00666458)) {
      DAT_0066ab04 = -1;
    }
  }
  return 0;
}


