/*
 * Decompiled function: FUN_0043064a
 * Entry Point: 0043064a
 * Size: 211 bytes
 */
#include "duel.h"


void FUN_0043064a(void)

{
  if (DAT_0050b37c < 0x100) {
    *(uint *)(&DAT_0050f170 + DAT_0050b37c * 4) = DAT_0068f0bc;
    *(undefined4 *)(&DAT_00512d78 + DAT_0050b37c * 4) =
         *(undefined4 *)
          (&DAT_006826c4 + (DAT_0068f0bc & 0xff) * 0x120 + ((DAT_0068f0bc & 0x100) >> 8) * 0x5b20);
    *(undefined4 *)(&DAT_00513178 + DAT_0050b37c * 4) = DAT_004f3c6c;
    (&DAT_00511a00)[DAT_0050b37c] = DAT_0068f2c8;
    DAT_0050b37c = DAT_0050b37c + 1;
    if ((DAT_00511a00 == 99) || (DAT_00511600 == 99)) {
      DAT_0068f0bc = 0xffffffff;
    }
  }
  else {
    DAT_00681ea4 = 1;
  }
  DAT_004f3c6c = 0;
  return;
}


