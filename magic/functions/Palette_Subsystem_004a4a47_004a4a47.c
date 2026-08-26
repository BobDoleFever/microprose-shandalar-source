/*
 * Decompiled function: Palette_Subsystem_004a4a47
 * Entry Point: 004a4a47
 * Size: 2575 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a4a47(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_48;
  int local_44;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_2 == 0) {
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
  }
  iVar1 = Ai_Util_004c3ba3(0xf0);
  iVar2 = Ai_Util_004c3ba3(0x140);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen,0,0,
                     iVar2,iVar1);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  g_OverworldWorldState = 0;
  FUN_0048e2b0(arg_3);
  iVar1 = FUN_0040c465(&g_OverworldWorldState);
  local_44 = 0;
  iVar2 = (int)*(short *)(DAT_0054be30 + 4);
  iVar3 = (int)*(short *)(DAT_0054be34 + 4);
  for (local_30 = *(short *)(DAT_0054be38 + 4) + iVar2 + -0x32; local_30 < iVar1;
      local_30 = local_30 + iVar3) {
    local_44 = local_44 + 1;
  }
  iVar1 = Ai_Util_004c3bc4(0x140);
  local_48 = (iVar1 - (local_44 * iVar3) / 2) - iVar2;
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_48,1,DAT_0054be30);
  local_48 = local_48 + iVar2;
  while (local_44 != 0) {
    Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_48,1,DAT_0054be34);
    local_48 = local_48 + iVar3;
    local_44 = local_44 + -1;
  }
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,local_48,1,DAT_0054be38);
  iVar3 = 0xff;
  iVar2 = 0x12;
  iVar1 = Ai_Util_004c3bc4(0x140);
  FUN_0040c421(&g_OverworldWorldState,iVar1,iVar2,iVar3);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
  if (DAT_00522454 != -1) {
    g_OverworldWorldState = 0;
    Palette_Subsystem_004a5e4c();
    iVar2 = 0x30;
    iVar1 = Ai_Util_004c3bc4(0x140);
    FUN_0040d269((int)g_DisplaySurfaceScreen,0xd0,iVar1,iVar2);
  }
  for (local_14 = 0xe; -1 < local_14; local_14 = local_14 + -1) {
    for (local_1c = 0; (int)local_1c < 0xd; local_1c = local_1c + 1) {
      Palette_Subsystem_004a554b(local_14,local_1c,&local_24,&local_28);
      if ((arg_1 == 0) && (((&DAT_00649c21)[local_1c * 4 + local_14 * 0x34] & 1) == 0)) {
        if ((((-1 < local_24) && (-1 < local_28)) && (local_24 < 0x241)) &&
           ((local_28 < 0x191 && (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) == 0))))
        {
          local_20 = 0;
          for (local_8 = 1; local_8 < 9; local_8 = local_8 + 2) {
            if (((&DAT_00649c21)
                 [(*(int *)(&DAT_00522378 + local_8 * 4) + local_14) * 0x34 +
                  (*(int *)(&DAT_005223e0 + local_8 * 4) + local_1c) * 4] & 1) != 0) {
              local_20 = local_20 + 1;
            }
          }
          if (1 < (int)local_20) {
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_00678700,0x40,
                       0x40);
          }
        }
      }
      else {
        if (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) != 0) {
          local_20 = (uint)(*(int *)(&DAT_00649c20 + (local_14 + 1) * 0x34 + local_1c * 4) == 0);
          if ((&DAT_00649c1c)[local_14 * 0xd + local_1c] == 0) {
            local_20 = local_20 | 2;
          }
          switch(*(undefined4 *)(&DAT_0054ba18 + local_1c * 4 + local_14 * 0x34)) {
          case 0:
            break;
          case 1:
            local_20 = local_20 + 4;
            break;
          case 2:
            local_20 = local_20 + 0x18;
            break;
          case 3:
            local_20 = local_20 + 0x1c;
          }
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,
                     (&DAT_006786b0)[local_20],0x40,0x40);
          local_20 = (uint)(*(int *)(local_14 * 0x34 + 0x649c24 + local_1c * 4) == 0);
          if (*(int *)(&DAT_00649c20 + (local_14 + -1) * 0x34 + local_1c * 4) == 0) {
            local_20 = local_20 | 2;
          }
          if (local_1c == 0xc) {
            local_20 = local_20 | 1;
          }
          if ((local_1c & 1) != 0) {
            local_20 = local_20 + 4;
          }
          Ai_Subsystem_004be3c4
                    (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,
                     *(undefined4 *)(&DAT_006786e0 + local_20 * 4),0x40,0x40);
        }
        g_OverworldWorldState = 0;
        if ((((&DAT_00649c20)[local_1c * 4 + local_14 * 0x34] & 0xf0) != 0) || (local_1c == 0xc)) {
          local_20 = (int)(*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) +
                          (*(int *)(&DAT_00649c20 + local_1c * 4 + local_14 * 0x34) >> 0x1f & 0xfU))
                     >> 4 & 0xf;
          switch(local_20) {
          case 1:
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_006786d8,0x40,
                       0x40);
            break;
          case 2:
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_006786d4,0x40,
                       0x40);
            break;
          case 3:
            break;
          case 4:
            break;
          case 5:
            break;
          case 6:
            break;
          case 7:
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_006786d0,0x40,
                       0x40);
            break;
          case 0xf:
            Ai_Subsystem_004be3c4
                      (g_DisplaySurfaceScreen,local_24 + -0x20,local_28 + -0x30,DAT_00678774,0x40,
                       0x40);
          }
          if (((int)local_20 < 3) || (6 < (int)local_20)) {
            if (local_1c == 0xc) {
              strcpy(&g_OverworldWorldState,&DAT_0052c510);
            }
            FUN_0040c336(&g_OverworldWorldState,local_24 / 2,local_28 / 2 + -2,0xff);
          }
          else {
            local_20 = local_20 - 3;
            strcpy(&g_OverworldWorldState,
                   &DAT_00522600 + *(int *)(&DAT_0054ba00 + local_20 * 4) * 0x44);
            local_2c = 5;
            for (local_18 = 1; local_18 < 9; local_18 = local_18 + 2) {
              local_8 = (int)(char)(&DAT_0054bd68)
                                   [*(int *)(&DAT_005223e0 + local_18 * 4) + local_1c +
                                    (*(int *)(&DAT_00522378 + local_18 * 4) + local_14) * 0xd];
              if ((local_8 != 0) && (local_8 < (char)(&DAT_0054bd68)[local_1c + local_14 * 0xd])) {
                local_2c = local_18;
              }
            }
            iVar1 = *(int *)(&g_OverworldFoodAmount +
                            (local_20 * 4 + 0x20) * 0x2d + (local_2c + 2U & 7) * 0x14);
            iVar2 = Ai_Util_004c3bc4(local_28 + 4);
            iVar2 = iVar2 - *(int *)(&DAT_00677990 + local_20 * 4);
            iVar3 = Ai_Util_004c3bc4(local_24 + 4);
            Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                              iVar3 - *(int *)(&DAT_006783f0 + local_20 * 4) / 2,iVar2,iVar1);
            iVar1 = *(int *)(&g_OverworldFoodAmount + local_20 * 0xb4 + (local_2c + 2U & 7) * 0x14);
            iVar2 = Ai_Util_004c3bc4(local_28 + 4);
            iVar2 = iVar2 - *(int *)(&DAT_00677990 + local_20 * 4);
            iVar3 = Ai_Util_004c3bc4(local_24 + 4);
            Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,
                              iVar3 - *(int *)(&DAT_006783f0 + local_20 * 4) / 2,iVar2,iVar1);
          }
        }
        if ((DAT_0054bd28 == local_14) && (DAT_0054bd2c == local_1c)) {
          local_c = local_24;
          local_10 = local_28;
        }
      }
    }
  }
  if ((arg_2 != 0) && (*(int *)(&DAT_0067effc + arg_3 * 0x30) != -1)) {
    local_20 = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + arg_3 * 0x30));
    strcpy(&g_OverworldWorldState,s_Swamp_0051aea9 + local_20 * 0x34);
    strcat(&g_OverworldWorldState,s_in_effect__0052c518);
    iVar1 = DAT_0054ba14;
    iVar2 = Ai_Util_004c3ba3(0x10f);
    iVar2 = iVar2 / 2;
    iVar3 = Ai_Util_004c3ba3(0xc5);
    iVar3 = iVar3 / 2;
    iVar4 = Ai_Util_004c3ba3(0x34);
    iVar4 = iVar4 / 2;
    iVar5 = Ai_Util_004c3ba3(0xdc);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar5 / 2,iVar4,iVar3,iVar2,iVar1);
    FUN_0050b3de(local_20,0x7a,0x29,0x4b,0x70,1,&DAT_0052c524);
    FUN_0040c381(&g_OverworldWorldState,0x76,0x20,0x1b);
  }
  *(undefined4 *)g_DisplaySurfaceScreen = 0;
  if (arg_2 == 0) {
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                 (int *)g_DisplaySurfaceScreen,0,0);
  }
  else {
    FUN_0050e040((int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c,
                 (int *)g_DisplaySurfaceBackBuffer,0,0);
  }
  iVar1 = (&DAT_00679424)[DAT_0052c2a0 * 5];
  iVar2 = Ai_Util_004c3bc4(local_10);
  iVar2 = iVar2 - DAT_006779d4;
  iVar3 = Ai_Util_004c3bc4(local_c);
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar3 - DAT_00678434 / 2,iVar2,iVar1);
  iVar1 = (&DAT_00679370)[DAT_0052c2a0 * 5];
  iVar2 = Ai_Util_004c3bc4(local_10);
  iVar2 = iVar2 - DAT_006779d0;
  iVar3 = Ai_Util_004c3bc4(local_c);
  Sprite_DrawDirect((int *)g_DisplaySurfaceScreen,iVar3 - DAT_00678430 / 2,iVar2,iVar1);
  return;
}


