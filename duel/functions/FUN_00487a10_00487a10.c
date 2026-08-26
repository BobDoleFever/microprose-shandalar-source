/*
 * Decompiled function: FUN_00487a10
 * Entry Point: 00487a10
 * Size: 721 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00487a10(void)

{
  int local_c;
  int local_8;
  
  DAT_00676510 = 0;
  DAT_00676504 = 1;
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    (&DAT_006668f0)[local_8] = 0;
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      *(undefined4 *)(&DAT_0068f2e0 + local_c * 4 + local_8 * 0x20) = 0;
      *(undefined4 *)(&DAT_0068ef50 + local_c * 4 + local_8 * 0x20) =
           *(undefined4 *)(&DAT_0068f2e0 + local_c * 4 + local_8 * 0x20);
      *(undefined4 *)(&DAT_0068ed10 + local_c * 4 + local_8 * 0x20) =
           *(undefined4 *)(&DAT_0068ef50 + local_c * 4 + local_8 * 0x20);
      *(undefined4 *)(&DAT_00666570 + local_8 * 0xcc) = 0xffffffff;
      *(undefined4 *)(&DAT_00666900 + local_8 * 0x2c) = 0xffffffff;
      *(undefined4 *)(&DAT_0068f360 + local_8 * 4) = 0;
    }
  }
  DAT_0068efb0 = 0xffffffff;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if ((&DAT_004ff580)[(DAT_00665ed0 + local_c) * 0x34] == -1) {
      *(undefined4 *)(&DAT_004ff590 + (DAT_00665ed0 + local_c) * 0x34) = 0xffffffff;
    }
  }
  DAT_00681eb0 = 0;
  DAT_006663f0 = 0xffffffff;
  DAT_0066ab04 = 0xffffffff;
  DAT_0068f100 = 0;
  if (DAT_005f2f50 == 0) {
    _DAT_0068f0b8 = _DAT_0068f0b8 | 2;
  }
  else {
    _DAT_0068f0b8 = _DAT_0068f0b8 & 0xfffffffd;
  }
  DAT_006663f8 = 0;
  DAT_006826b4 = 0x30;
  DAT_0068ef98 = 0xffffffff;
  _DAT_0068eeec = 0xffffffff;
  _DAT_0066aad8 = 0xffffffff;
  DAT_00666748 = 0xffffffff;
  DAT_0068f0f4 = 0xffffffff;
  DAT_0068f0b0 = 0;
  _DAT_00676508 = 1;
  DAT_0068ef48 = 0;
  DAT_0068eee4 = 0;
  DAT_00690314 = 0;
  DAT_006826b0 = 0;
  DAT_0068f0f8 = 0xffffffff;
  DAT_00690318 = 0;
  DAT_00666740 = 1;
  DAT_0068f2d8 = 0;
  DAT_0068ecc4 = 0;
  DAT_0068eedc = 0;
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    (&DAT_0068ece0)[local_c] = 0;
  }
  DAT_0068ed04 = 0xffffffff;
  DAT_0068ecd0 = 0xffffffff;
  DAT_0068eccc = 0xffffffff;
  _DAT_006663e8 = 0;
  _DAT_006663ec = 0;
  return;
}


