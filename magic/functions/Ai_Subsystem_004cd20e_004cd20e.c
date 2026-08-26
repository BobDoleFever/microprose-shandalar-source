/*
 * Decompiled function: Ai_Subsystem_004cd20e
 * Entry Point: 004cd20e
 * Size: 452 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004cd20e(void)

{
  undefined4 uVar1;
  LPVOID local_10;
  int local_c;
  int local_8;
  
  Mem_AllocOrFree_00510de0(1,s_title_pic_0052e5e0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  FUN_00501736(0x78);
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    uVar1 = FUN_0040a1d2(5);
    switch(uVar1) {
    case 0:
      FUN_00409f99(s_decks_0016_dck_0052e5ec,local_8,1,-1);
      local_10 = (LPVOID)0x2;
      break;
    case 1:
      FUN_00409f99(s_decks_0283_dck_0052e5fc,local_8,1,-1);
      local_10 = (LPVOID)0xa;
      break;
    case 2:
      FUN_00409f99(s_decks_0150_dck_0052e60c,local_8,1,-1);
      local_10 = (LPVOID)0x10;
      break;
    case 3:
      FUN_00409f99(s_decks_0076_dck_0052e61c,local_8,1,-1);
      local_10 = (LPVOID)0x17;
      break;
    case 4:
      FUN_00409f99(s_decks_0102_dck_0052e62c,local_8,1,-1);
      local_10 = (LPVOID)0x20;
    }
  }
  DAT_0052effc = 0;
  DAT_0052eff8 = 1;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    (&DAT_006b2dd0)[local_c] = 0xffffffff;
    (&DAT_006b2d90)[local_c] = (&DAT_006b2dd0)[local_c];
  }
  DAT_006fedc0 = 1;
  Pic_Load_0044ef70(0,local_10);
  DAT_006fedc0 = 0;
  Ai_Subsystem_004c05ba();
  return 0;
}


