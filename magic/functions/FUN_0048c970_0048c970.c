/*
 * Decompiled function: FUN_0048c970
 * Entry Point: 0048c970
 * Size: 319 bytes
 */
#include "magic.h"


void FUN_0048c970(int arg_1)

{
  int iVar1;
  
  DAT_0054aad4 = 0;
  DAT_0054aab0 = 0;
  Pic_Subsystem_0044b8da();
  iVar1 = FUN_0048cb40();
  if (iVar1 != -1) {
    if (arg_1 == -1) {
      Pic_Subsystem_0044b8aa();
      arg_1 = FUN_00489710(&g_OverworldWorldState,0x30,0x20);
      Pic_Subsystem_0044b8da();
    }
    if (arg_1 != -1) {
      DAT_00627a78 = arg_1;
      s_D_MAGIC0_SVE_00527b48[7] = FUN_0048c6d0(arg_1);
      iVar1 = FUN_0048caaf(s_D_MAGIC0_SVE_00527b48);
      if (iVar1 != 0) {
        if (DAT_0054aad4 == 0) {
          strcpy(&g_OverworldWorldState,s_Game_has_been_saved__00527ca4);
        }
        else {
          strcpy(&g_OverworldWorldState,s_Game_NOT_saved__00527cbc);
          Surface_FillRect((int *)g_DisplaySurfaceScreen,0x40,0x7f,0xc0,0x22,0xc);
        }
        if (DAT_0054aad4 == 0xd) {
          strcat(&g_OverworldWorldState,s_Write_access_denied__00527cd0);
        }
        if (DAT_0054aad4 == 0x1c) {
          strcat(&g_OverworldWorldState,s_Disk_Full__00527ce8);
        }
        strcat(&g_OverworldWorldState,s_Press_key_to_continue__00527cf8);
      }
    }
  }
  Pic_Subsystem_0044b8aa();
  return;
}


