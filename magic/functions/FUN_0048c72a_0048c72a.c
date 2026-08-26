/*
 * Decompiled function: FUN_0048c72a
 * Entry Point: 0048c72a
 * Size: 387 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0048c72a(int arg_1)

{
  int iVar1;
  uint local_8;
  
  DAT_0054aab0 = 1;
  Pic_Subsystem_0044b8da();
  iVar1 = FUN_0048cb40();
  if (iVar1 == -1) {
    Pic_Subsystem_0044b8aa();
    iVar1 = -1;
  }
  else {
    if (arg_1 == -1) {
      strcpy(&g_OverworldWorldState,&DAT_00527c50);
      _DAT_0063ee7c = 0;
      for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
        s_D_MAGIC0_SVE_00527b48[7] = FUN_0048c6d0(local_8);
        iVar1 = FUN_0048c8b2(s_D_MAGIC0_SVE_00527b48,1);
        if (iVar1 != 0) {
          _DAT_0063ee7c = _DAT_0063ee7c | 1 << ((byte)local_8 & 0x1f);
        }
      }
      Pic_Subsystem_0044b8aa();
      DAT_00627a78 = FUN_00489710(&g_OverworldWorldState,0x30,0x40);
      Pic_Subsystem_0044b8da();
      if ((_DAT_0063ee7c & 1 << ((byte)DAT_00627a78 & 0x1f)) == 0) {
        DAT_00627a78 = -1;
      }
    }
    else {
      DAT_00627a78 = arg_1;
    }
    if (DAT_00627a78 != -1) {
      s_D_MAGIC0_SVE_00527b48[7] = FUN_0048c6d0(DAT_00627a78);
      iVar1 = FUN_0048c8b2(s_D_MAGIC0_SVE_00527b48,0);
      if (iVar1 == 0) {
        DAT_00627a78 = -1;
      }
    }
    if (DAT_00627a78 == -1) {
      FUN_00489710(s_Error_Loading_Save_Game_File_EXI_00527c68,100,0x50);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    Pic_Subsystem_0044b8aa();
    iVar1 = DAT_00627a78;
  }
  return iVar1;
}


