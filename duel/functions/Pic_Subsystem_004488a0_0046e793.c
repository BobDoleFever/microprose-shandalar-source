/*
 * Decompiled function: Pic_Subsystem_004488a0
 * Entry Point: 0046e793
 * Size: 191 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_004488a0(void)

{
  if ((DAT_00666760 != 0) && (DAT_004f965c == 0)) {
    DAT_004f965c = 1;
    DAT_00681eb0 = DAT_00681eb0 | 0x200;
    FUN_0048e32b(-2,DAT_0068f2c4,s_Use_Regeneration_Effects_004f970c,0x70);
    DAT_00681eb0 = DAT_00681eb0 & 0xfffffdff;
    FUN_0048e8a8(DAT_00666458,0xd6,s_Graveyard_order_004f9728,0);
    FUN_0048e8a8(DAT_00666458,0xd5,s_Card_s__to_Graveyard_004f9738,0);
    DAT_00666760 = 0;
    DAT_004f965c = 0;
    FUN_00451482(0,0xff);
  }
  return 0;
}


