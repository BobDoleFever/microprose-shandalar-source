/*
 * Decompiled function: Sprite_Load__16faces_0047b899
 * Entry Point: 0047b899
 * Size: 1112 bytes
 */
#include "magic.h"


int Sprite_Load__16faces_0047b899(void)

{
  int *piVar1;
  int iVar2;
  int local_90 [4];
  int local_80 [4];
  int local_70 [4];
  int local_60 [9];
  int *local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  char *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_005112b0(0,(short)DAT_00530d9c);
  FUN_00510b70(1,0,0,s_pedstls_pic_00526ab8,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceWork,0
                     ,0,DAT_00522458,DAT_0052245c);
  FUN_005115a0(0,(short)DAT_00530d9c);
  LoadPalNoPic(s_pedstls_pic_00526ac4);
  piVar1 = (int *)FUN_0050e6f0(local_70,(int)g_DisplaySurfaceWork,0,0,DAT_00522458,DAT_0052245c);
  local_14 = *piVar1;
  local_10 = piVar1[1];
  local_c = piVar1[2];
  local_8 = piVar1[3];
  Sprite_LoadAll(&DAT_00676dd0,s_16facesLow_spr_00526ad0);
  Sprite_LoadAll(&DAT_00676d80,s_16faces_spr_00526ae0);
  FUN_0040b441((int *)&DAT_005263f0,0xe);
  local_1c = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_1c);
  FUN_0041f17e(0x5263f0,0xf,local_1c);
  for (local_18 = 0; local_18 < 0xe; local_18 = local_18 + 1) {
    FUN_0047b73d(local_18,0);
  }
  DAT_00525f28 = -1;
  while (DAT_00525f28 == -1) {
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  if (DAT_00525f28 == 0) {
    FUN_0041f391();
    Mem_AllocOrFree_0041f12b(local_1c);
    iVar2 = -1;
  }
  else {
    FUN_0047c2fd(DAT_00525f28 + -1);
    FUN_0041f391();
    Mem_AllocOrFree_0041f12b(local_1c);
    local_60[0] = 4;
    local_60[1] = 0;
    local_60[2] = 0;
    local_60[3] = 800;
    local_60[4] = 600;
    local_60[5] = 1;
    local_60[6] = 0xf;
    local_60[7] = 4;
    local_60[8] = 0;
    local_3c = local_60;
    local_20 = (&DAT_00676d7c)[DAT_00525f28];
    local_28 = (int)*(short *)(local_20 + 4);
    local_2c = (int)*(short *)(local_20 + 6);
    local_34 = FUN_0050d0b0(4,local_28 * 2,local_2c,8);
    FUN_0050d370(4,local_34);
    FUN_0050e6f0(local_80,(int)local_3c,0,0,local_28 * 2,local_2c);
    LoadPalNoPic(s_menu4_pic_00526aec);
    Surface_FillRect(local_3c,0,0,local_28,local_2c,0);
    Sprite_DrawDirect(local_3c,0,0,local_20);
    for (local_38 = 0; local_38 < local_2c; local_38 = local_38 + 1) {
      local_24 = (char *)((*(int *)(DAT_0070a860 + 0x2c) + *(int *)(DAT_0070a860 + 0x20)) * local_38
                         + *(int *)(DAT_0070a860 + 0x18));
      for (local_30 = 0; local_30 < local_28; local_30 = local_30 + 1) {
        if (*local_24 == '\0') {
          local_24[local_28] = -1;
        }
        local_24 = local_24 + 1;
      }
    }
    DAT_0067bdd8 = *(undefined4 *)(DAT_0070a860 + 8);
    DAT_0067bdd4 = DAT_0070a860;
    SelectObject(*(HDC *)(DAT_0070a860 + 4),*(HGDIOBJ *)(DAT_0070a860 + 0xc));
    DAT_0070a860 = 0;
    Mem_AllocOrFree_0050fc50(DAT_00676dd0);
    Mem_AllocOrFree_0050fc50(DAT_00676d80);
    FUN_0050e6f0(local_90,(int)g_DisplaySurfaceWork,local_14,local_10,local_c,local_8);
    memset(s_Ned_Way_the_Ratiocinator_0052f020,0,0x40);
    strcpy(s_Ned_Way_the_Ratiocinator_0052f020,*(char **)(DAT_00525f28 * 4 + 0x5268dc));
    DAT_00676dc8 = strlen(s_Ned_Way_the_Ratiocinator_0052f020);
    Pic_Load_namepick_0047be64(s_Ned_Way_the_Ratiocinator_0052f020);
    strcpy(&DAT_0068a6a0,s_Ned_Way_the_Ratiocinator_0052f020);
    iVar2 = DAT_00525f28 + -1;
  }
  return iVar2;
}


