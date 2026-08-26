/*
 * Decompiled function: FUN_004853c2
 * Entry Point: 004853c2
 * Size: 226 bytes
 */
#include "magic.h"


void FUN_004853c2(void)

{
  int local_8;
  
  FUN_0050d560(0,3);
  FUN_0040c421(s_My_Ante_005270b8,0xa0,100,0xff);
  FUN_0040c421(s_Opponent_s_Ante_005270c0,0xa0,1,0xff);
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    if ((&DAT_006b2dd0)[local_8] != -1) {
      FUN_00484e2d((&DAT_006b2dd0)[local_8],(local_8 + 1) * 0x6a,8,0,0xffffffff);
    }
    if ((&DAT_006b2d90)[local_8] != -1) {
      FUN_00484e2d((&DAT_006b2d90)[local_8],(local_8 + 1) * 0x6a,0x6c,0,0xffffffff);
    }
  }
  return;
}


