/*
 * Decompiled function: Palette_Subsystem_004981b5
 * Entry Point: 004981b5
 * Size: 1904 bytes
 */
#include "magic.h"


void Palette_Subsystem_004981b5(int arg_1)

{
  byte arg_1_00;
  char *str_2;
  int aiStack_12c [8];
  int aiStack_10c [7];
  int local_f0 [8];
  int local_d0;
  int aiStack_cc [7];
  int local_b0;
  int aiStack_ac [7];
  int local_90;
  int aiStack_8c [7];
  int local_70;
  int aiStack_6c [7];
  int local_50;
  int local_4c [8];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10 [3];
  
  DAT_0054b348 = 0;
  for (local_24 = 0; local_24 < 8; local_24 = local_24 + 1) {
    aiStack_12c[local_24] = 0;
    for (local_28 = 0; local_28 < 7; local_28 = local_28 + 1) {
      aiStack_10c[local_24 + local_28 * 8] = 0;
    }
  }
  for (local_24 = 0; local_24 < 3; local_24 = local_24 + 1) {
    local_10[local_24] = 0;
  }
  for (local_24 = 0; local_24 < 500; local_24 = local_24 + 1) {
    if (((&DAT_00702151)[local_24 * 4] & 0x40) == 0) {
      DAT_0054b348 = DAT_0054b348 + 1;
      local_18 = *(uint *)(&deck + local_24 * 4) & 0xfff;
      arg_1_00 = (&DAT_0051aebe)[local_18 * 0x34];
      local_2c = (int)(char)arg_1_00;
      if ((&DAT_0051aed4)[local_18 * 0x34] == '\x03') {
        local_10[2] = local_10[2] + 1;
      }
      else if ((&DAT_0051aed4)[local_18 * 0x34] == '\x02') {
        local_10[1] = local_10[1] + 1;
      }
      else {
        local_10[0] = local_10[0] + 1;
      }
      if (((&g_MasterCardColorTable)[local_18 * 0x34] & 1) != 0) {
        for (local_28 = 1; local_28 < 7; local_28 = local_28 + 1) {
          if ((1 << ((byte)local_28 & 0x1f) & (int)(char)(&DAT_0051aebe)[local_18 * 0x34]) != 0) {
            aiStack_12c[local_28] = aiStack_12c[local_28] + 1;
            aiStack_12c[7] = aiStack_12c[7] + 1;
          }
        }
      }
      local_2c = FUN_00473cc5(arg_1_00);
      switch((&g_MasterCardColorTable)[local_18 * 0x34]) {
      case 1:
        aiStack_10c[local_2c] = aiStack_10c[local_2c] + 1;
        local_f0[0] = local_f0[0] + 1;
        break;
      case 2:
        if ((int)*(short *)(&DAT_0051aec2 + local_18 * 0x34) +
            (int)*(short *)(&DAT_0051aec4 + local_18 * 0x34) < 5) {
          local_f0[local_2c + 1] = local_f0[local_2c + 1] + 1;
          local_d0 = local_d0 + 1;
        }
        else {
          aiStack_cc[local_2c] = aiStack_cc[local_2c] + 1;
          local_b0 = local_b0 + 1;
        }
        break;
      case 4:
        aiStack_ac[local_2c] = aiStack_ac[local_2c] + 1;
        local_90 = local_90 + 1;
        break;
      case 8:
        aiStack_8c[local_2c] = aiStack_8c[local_2c] + 1;
        local_70 = local_70 + 1;
        break;
      case 0x10:
      case 0x20:
        aiStack_6c[local_2c] = aiStack_6c[local_2c] + 1;
        local_50 = local_50 + 1;
        break;
      case 0x40:
      case 0x42:
        local_4c[local_2c] = local_4c[local_2c] + 1;
      }
    }
  }
  if (arg_1 != 0) {
    FUN_0050d560(0,0);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    local_1c = 0x10;
    local_20 = 0x10;
    strcpy(&g_OverworldWorldState,&DAT_0052b888);
    str_2 = _itoa(DAT_0054b348,&DAT_0054b350,10);
    strcat(&g_OverworldWorldState,str_2);
    strcat(&g_OverworldWorldState,s_cards__0052b88c);
    FUN_0040c381(&g_OverworldWorldState,local_1c,local_20,0xf6);
    FUN_0040c2e9(s_Total_0052b894,0x80,local_20,0xff);
    FUN_0040c2e9(s_Black_0052b89c,0xb0,local_20,0xff);
    FUN_0040c2e9(&DAT_0052b8a4,0xd0,local_20,0xff);
    FUN_0040c2e9(s_Green_0052b8ac,0xf0,local_20,0xff);
    FUN_0040c2e9(&DAT_0052b8b4,0x110,local_20,0xff);
    FUN_0040c2e9(s_White_0052b8b8,0x130,local_20,0xff);
    Surface_DrawLine((int *)g_DisplaySurfaceScreen,0,local_20 * 2 + 0x18,DAT_00522458 + -1,
                     local_20 * 2 + 0x18,0xf4);
    Surface_DrawLine((int *)g_DisplaySurfaceScreen,0x130,0,0x130,DAT_0052245c + -1,0xf4);
    local_20 = 0x20;
    FUN_0040c381(&DAT_0052b8c0,local_1c,0x20,0xff);
    Palette_Subsystem_004989a9(local_f0[0],0x80,local_20,0xff);
    for (local_24 = 1; local_24 < 6; local_24 = local_24 + 1) {
      Palette_Subsystem_004989a9(aiStack_12c[local_24],local_24 * 0x20 + 0x90,local_20,0xff);
    }
    for (local_28 = 1; local_20 = local_20 + 0xc, local_28 < 6; local_28 = local_28 + 1) {
      switch(local_28) {
      case 1:
        strcpy(&g_OverworldWorldState,s_Fast_creatures_0052b8c8);
        break;
      case 2:
        strcpy(&g_OverworldWorldState,s_Large_creatures_0052b8d8);
        break;
      case 3:
        strcpy(&g_OverworldWorldState,s_Enchantments_0052b8e8);
        break;
      case 4:
        strcpy(&g_OverworldWorldState,s_Sorceries_0052b8f8);
        break;
      case 5:
        strcpy(&g_OverworldWorldState,s_Fast_effects_0052b904);
      }
      FUN_0040c381(&g_OverworldWorldState,local_1c,local_20,0xff);
      Palette_Subsystem_004989a9(local_f0[local_28 * 8],0x80,local_20,0xff);
      for (local_24 = 1; local_24 < 6; local_24 = local_24 + 1) {
        Palette_Subsystem_004989a9
                  (aiStack_10c[local_24 + local_28 * 8],local_24 * 0x20 + 0x90,local_20,0xff);
      }
    }
    FUN_0040c381(s_Artifacts_0052b914,local_1c,local_20,0xff);
    Palette_Subsystem_004989a9(local_4c[0],0x80,local_20,0xff);
    local_20 = local_20 + 0x18;
    local_1c = 0x80;
    FUN_0040c381(s_Common__0052b920,0x80,local_20,0xf6);
    Palette_Subsystem_004989a9(local_10[0],local_1c + 0x30,local_20,0xf6);
    local_20 = local_20 + 8;
    FUN_0040c381(s_Uncommon__0052b92c,local_1c,local_20,0xf6);
    Palette_Subsystem_004989a9(local_10[1],local_1c + 0x30,local_20,0xf6);
    local_20 = local_20 + 8;
    FUN_0040c381(s_Rare__0052b938,local_1c,local_20,0xf6);
    Palette_Subsystem_004989a9(local_10[2],local_1c + 0x30,local_20,0xf6);
    local_20 = local_20 + 8;
    Ai_Subsystem_004cd1d1();
  }
  local_14 = local_d0;
  if (local_d0 < local_b0) {
    local_14 = local_b0;
  }
  DAT_00626804 = (uint)(local_d0 < local_b0);
  if (local_14 < local_70 + local_50) {
    DAT_00626804 = 2;
  }
  return;
}


