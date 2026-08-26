/*
 * Decompiled function: Ai_Subsystem_004cd20e
 * Entry Point: 00451ccb
 * Size: 372 bytes
 */
#include "duel.h"


undefined4 Ai_Subsystem_004cd20e(void)

{
  undefined4 uVar1;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    uVar1 = FUN_00439892(5);
    switch(uVar1) {
    case 0:
      FUN_00439659(s_decks_0016_dck_004f8610,local_8,1,0xffffffff);
      local_10 = 2;
      break;
    case 1:
      FUN_00439659(s_decks_0283_dck_004f8620,local_8,1,0xffffffff);
      local_10 = 10;
      break;
    case 2:
      FUN_00439659(s_decks_0150_dck_004f8630,local_8,1,0xffffffff);
      local_10 = 0x10;
      break;
    case 3:
      FUN_00439659(s_decks_0076_dck_004f8640,local_8,1,0xffffffff);
      local_10 = 0x17;
      break;
    case 4:
      FUN_00439659(s_decks_0102_dck_004f8650,local_8,1,0xffffffff);
      local_10 = 0x20;
    }
  }
  DAT_00505988 = 0;
  DAT_00505984 = 1;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    (&DAT_0068ed90)[local_c] = 0xffffffff;
    (&DAT_0068ed50)[local_c] = (&DAT_0068ed90)[local_c];
  }
  DAT_0068f0b0 = 1;
  Mem_AllocOrFree_004d4e10(0,local_10);
  DAT_0068f0b0 = 0;
  return 0;
}


