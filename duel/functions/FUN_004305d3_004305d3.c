/*
 * Decompiled function: FUN_004305d3
 * Entry Point: 004305d3
 * Size: 119 bytes
 */
#include "duel.h"


void FUN_004305d3(void)

{
  int local_8;
  
  DAT_00690c44 = 0;
  DAT_0050b37c = 0;
  DAT_0068ef98 = 0xffffffff;
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    (&DAT_00511a00)[local_8] = 99;
  }
  FUN_0042fea9();
  if (DAT_0066aaf4 != 1) {
    DAT_00666400 = 0xffffffff;
  }
  return;
}


