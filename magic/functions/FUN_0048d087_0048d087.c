/*
 * Decompiled function: FUN_0048d087
 * Entry Point: 0048d087
 * Size: 466 bytes
 */
#include "magic.h"


undefined4 FUN_0048d087(char *str_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  
  if (DAT_0063ee18 == 0) {
    strcpy(str_1 + 9,&DAT_00527e4c);
    iVar1 = FUN_00512ba0(2,str_1);
    if (iVar1 != 0) {
      strcpy(&g_OverworldWorldState,s_Error_writing_map_file__00527e50);
      FUN_00489710(&g_OverworldWorldState,4,0x40);
      DAT_0054aad4 = 1;
      return 0;
    }
  }
  strcpy(str_1 + 9,&DAT_00527e6c);
  DAT_0054aab8 = _open(str_1,0x8301,0x80);
  if (DAT_0054aab8 == -1) {
    strcpy(&g_OverworldWorldState,s_File_Error__00527e70);
    strcat(&g_OverworldWorldState,str_1);
    strcat(&g_OverworldWorldState,&DAT_00527e80);
    FUN_00489710(&g_OverworldWorldState,100,0x50);
    uVar2 = 0;
  }
  else {
    DAT_0054aab0 = 0;
    FUN_0048d259();
    _close(DAT_0054aab8);
    local_44 = 4;
    local_40 = 0;
    local_3c = 0;
    local_38 = 800;
    local_34 = 600;
    local_30 = 1;
    local_2c = 0xf;
    local_28 = 4;
    local_24 = 0;
    local_20 = &local_44;
    DAT_0070a860 = DAT_0067bdd4;
    strcpy(str_1 + 9,&DAT_00527e84);
    FUN_00512c00(4,0,0,*(undefined4 *)(DAT_0067bdd4 + 0x20),*(undefined4 *)(DAT_0067bdd4 + 0x24),0,
                 str_1);
    DAT_0070a860 = 0;
    if (DAT_0054aad4 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


