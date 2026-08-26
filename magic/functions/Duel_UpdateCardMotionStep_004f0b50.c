/*
 * Decompiled function: Duel_UpdateCardMotionStep
 * Entry Point: 004f0b50
 * Size: 576 bytes
 */
#include "magic.h"


int Duel_UpdateCardMotionStep(uint arg_1)

{
  int iVar1;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  int aiStack_20 [7];
  
  if ((int)arg_1 < 5) {
    local_30 = 99;
  }
  else {
    for (local_28 = 0; local_28 < 7; local_28 = local_28 + 1) {
      aiStack_20[local_28] = 0;
    }
    local_2c = 0;
    local_30 = 0;
    for (local_28 = 0; local_28 < 500; local_28 = local_28 + 1) {
      if ((*(int *)(&deck + local_28 * 4) != -1) && (((&DAT_00702151)[local_28 * 4] & 0x40) == 0)) {
        local_2c = local_2c + 1;
        iVar1 = FUN_00473cc5((&DAT_0051aebe)[(*(uint *)(&deck + local_28 * 4) & 0xfff) * 0x34]);
        aiStack_20[iVar1] = aiStack_20[iVar1] + 1;
      }
      if ((*(uint *)(&deck + local_28 * 4) & 0xffff7fff) == arg_1) {
        local_30 = local_30 + 1;
        DAT_00565a08 = local_28;
      }
    }
    local_24 = -1;
    for (local_28 = 1; local_28 < 7; local_28 = local_28 + 1) {
      if ((int)local_24 < aiStack_20[local_28]) {
        local_24 = aiStack_20[local_28];
      }
    }
    DAT_0052f000 = 0;
    for (local_28 = 1; local_28 < 7; local_28 = local_28 + 1) {
      if ((int)(local_24 * 2) / 3 <= aiStack_20[local_28]) {
        DAT_0052f000 = DAT_0052f000 | 1 << ((byte)local_28 & 0x1f);
      }
    }
    local_24 = 1;
    if (0x27 < local_2c) {
      local_24 = 2;
    }
    if (0x3b < local_2c) {
      local_24 = 3;
    }
    if ((DAT_0067f374 & 0x20) != 0) {
      local_24 = local_24 + 1;
    }
    if (((&DAT_0051aed1)[arg_1 * 0x34] & 1) == 0) {
      if (((&DAT_0051aed6)[arg_1 * 0x34] & 0xc1) == 0) {
        local_24 = local_24 / 2;
      }
    }
    else {
      local_24 = (uint)(DAT_0067f380 <= (int)local_24);
    }
    local_30 = local_24 - local_30;
  }
  return local_30;
}


