/*
 * Decompiled function: FUN_0048ce07
 * Entry Point: 0048ce07
 * Size: 640 bytes
 */
#include "magic.h"


undefined4 FUN_0048ce07(char *str_1)

{
  undefined4 uVar1;
  int local_5c [4];
  int local_4c [9];
  int *local_28;
  undefined4 local_20;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  strcpy(str_1 + 9,&DAT_00527e2c);
  DAT_0054aab8 = _open(str_1,0x8000);
  if (DAT_0054aab8 == -1) {
    strcpy(&g_OverworldWorldState,s_File_Error__00527e30);
    strcat(&g_OverworldWorldState,str_1);
    strcat(&g_OverworldWorldState,&DAT_00527e40);
    FUN_00489710(&g_OverworldWorldState,100,0x50);
    uVar1 = 0;
  }
  else {
    DAT_0054aab0 = 1;
    FUN_0048d259();
    _close(DAT_0054aab8);
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
        if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) {
          (&g_PlayerActiveCardCount)[local_8] = local_c;
        }
      }
    }
    if (DAT_0063ee18 == 0) {
      Pic_Subsystem_0044b8da();
      strcpy(str_1 + 9,&DAT_00527e44);
      Mem_AllocOrFree_00510e20(2,str_1);
      Pic_Subsystem_0044b8aa();
    }
    local_4c[0] = 4;
    local_4c[1] = 0;
    local_4c[2] = 0;
    local_4c[3] = 800;
    local_4c[4] = 600;
    local_4c[5] = 1;
    local_4c[6] = 0xf;
    local_4c[7] = 4;
    local_4c[8] = 0;
    local_28 = local_4c;
    local_14 = 0x89;
    local_18 = 0xa9;
    local_20 = FUN_0050d0b0(4,0x112,0xa9,8);
    FUN_0050d370(4,local_20);
    FUN_0050e6f0(local_5c,(int)local_28,0,0,local_14 * 2,local_18);
    Surface_FillRect(local_28,0,0,local_14 * 2,local_18,0);
    strcpy(str_1 + 9,&DAT_00527e48);
    Mem_AllocOrFree_00510e20(4,str_1);
    DAT_0067bdd8 = *(undefined4 *)(DAT_0070a860 + 8);
    DAT_0067bdd4 = DAT_0070a860;
    SelectObject(*(HDC *)(DAT_0070a860 + 4),*(HGDIOBJ *)(DAT_0070a860 + 0xc));
    DAT_0070a860 = 0;
    Sprite_Load__16faces_0047c1a7(DAT_006ff678);
    uVar1 = 1;
  }
  return uVar1;
}


