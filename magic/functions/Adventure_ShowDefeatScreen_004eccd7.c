/*
 * Decompiled function: Adventure_ShowDefeatScreen
 * Entry Point: 004eccd7
 * Size: 509 bytes
 */
#include "magic.h"


void Adventure_ShowDefeatScreen(void)

{
  LONG arg2;
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 500; local_c = local_c + 1) {
    if (((*(int *)(&deck + local_c * 4) != -1) && (((&DAT_00702151)[local_c * 4] & 0x40) == 0)) &&
       (4 < (*(uint *)(&deck + local_c * 4) & 0xfff))) {
      local_8 = local_8 + 1;
    }
  }
  if (local_8 == 0) {
    FUN_005112b0(0,(short)DAT_00530d9c);
    Mem_AllocOrFree_00510de0(1,s_uth_arz_pic_0052fb3c);
    g_OverworldWorldState = 0;
    *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 5;
    if ((DAT_00522458 == 0x280) || (DAT_00522458 == 800)) {
      local_10 = 0x14;
    }
    else {
      local_10 = 0x10;
    }
    arg2 = Ai_Util_004c3bc4(local_10);
    FUN_0050f2e0(5,arg2);
    strcat(&g_OverworldWorldState,s_You_have_no_power_for_even_an_An_0052fb48);
    strcat(&g_OverworldWorldState,s_Your_Righteous_Quest_has_Failed_0052fb70);
    strcat(&g_OverworldWorldState,s_The_Evil_Planeswalker_Arzakon_an_0052fb94);
    strcat(&g_OverworldWorldState,s_have_worn_you_down_0052fbcc);
    strcat(&g_OverworldWorldState,s_The_people_will_suffer_a_thousan_0052fbe4);
    iVar1 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceBackBuffer + 0x20));
    FUN_0040d269((int)g_DisplaySurfaceBackBuffer,0xea,0x140,iVar1 * -7 + 0x1e0);
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
    FUN_0040a3e1();
    Ai_Subsystem_004cd1d1();
    FUN_005112b0(0,(short)DAT_00530d9c);
    DAT_006fe3f0 = 1;
    FUN_00409db6();
    Palette_Util_00496d20();
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  return;
}


