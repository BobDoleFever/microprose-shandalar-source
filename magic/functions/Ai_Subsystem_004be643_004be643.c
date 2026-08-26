/*
 * Decompiled function: Ai_Subsystem_004be643
 * Entry Point: 004be643
 * Size: 3048 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004be643(int arg_1,int arg_2,int arg_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  DWORD DVar9;
  uint arg_4;
  int iVar10;
  HDC pHVar11;
  int iVar12;
  int arg_9;
  undefined4 arg_5;
  int local_fc [4];
  int local_ec [4];
  int local_dc [4];
  int local_cc [4];
  int local_bc [4];
  int local_ac;
  int local_a8;
  int local_a4 [17];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50 [2];
  int local_48 [2];
  uint local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_28 = *(undefined4 *)g_DisplaySurfaceBackBuffer;
  Pic_Subsystem_0044b8da();
  if (DAT_00522458 == 0x280) {
    DAT_00557478 = 0x280;
    DAT_005574ac = 0x1e0;
    DAT_0055747c = 0x80;
    DAT_005574b0 = 0x20;
  }
  else if (DAT_00522458 == 800) {
    DAT_00557478 = 800;
    DAT_005574ac = 600;
    DAT_0055747c = 0xa0;
    DAT_005574b0 = 0x28;
  }
  else if (DAT_00522458 == 0x400) {
    DAT_00557478 = 0x400;
    DAT_005574ac = 0x300;
    DAT_0055747c = 0xcc;
    DAT_005574b0 = 0x33;
  }
  DAT_006498d8 = arg_1;
  DAT_006498dc = arg_2;
  _DAT_00557484 = (int)(arg_1 + (arg_1 >> 0x1f & 0x1fU)) >> 5;
  _DAT_00557488 = (int)(arg_2 + (arg_2 >> 0x1f & 0x1fU)) >> 5;
  *(undefined4 *)g_DisplaySurfaceScreen = *(undefined4 *)g_DisplaySurfaceBackBuffer;
  Ai_Util_004be240();
  DAT_0052d77c = 0x50;
  piVar1 = (int *)FUN_0050e6f0(local_bc,(int)g_DisplaySurfaceBackBuffer,0,0x80,
                               *(int *)(g_DisplaySurfaceScreen + 0xc),
                               *(int *)(g_DisplaySurfaceScreen + 0x10) + -0x80);
  local_24 = *piVar1;
  local_20 = piVar1[1];
  local_1c = piVar1[2];
  local_18 = piVar1[3];
  piVar1 = (int *)FUN_0050e6f0(local_cc,(int)g_DisplaySurfaceScreen,0,0x80,
                               *(int *)(g_DisplaySurfaceScreen + 0xc),
                               *(int *)(g_DisplaySurfaceScreen + 0x10) + -0x80);
  local_14 = *piVar1;
  local_10 = piVar1[1];
  local_c = piVar1[2];
  local_8 = piVar1[3];
  Ai_Subsystem_004c06df(arg_1,arg_2);
  Ai_Subsystem_004be525(arg_1,arg_2,local_48,local_50);
  iVar2 = Ai_Util_004c3ba3(0x8c);
  iVar3 = Ai_Util_004c3ba3(0x100);
  FUN_0050e6f0(local_dc,(int)g_DisplaySurfaceScreen,0x40,DAT_005574b0 * 2 + DAT_0052d77c + 0x10,
               iVar3,iVar2);
  Ai_Subsystem_004be25f
            (g_DisplaySurfaceScreen,(local_48[0] - DAT_00678430 / 2) + _DAT_006498d0,
             (local_50[0] - DAT_006779d0) + DAT_006498d4,DAT_006498d4 + local_50[0],
             (&DAT_00679370)[(DAT_006410d4 + 2U & 7) * 5 + DAT_006410dc]);
  Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,local_48[0] - DAT_00678434 / 2,
                     local_50[0] - DAT_006779d4,
                     (&DAT_00679424)[(DAT_006410d4 + 2U & 7) * 5 + DAT_006410dc]);
  g_OverworldWorldState = 0;
  pcVar4 = _itoa(local_30,&DAT_00557498,10);
  strcat(&g_OverworldWorldState,pcVar4);
  strcat(&g_OverworldWorldState,&DAT_0052db48);
  pcVar4 = _itoa(local_38,&DAT_00557498,10);
  strcat(&g_OverworldWorldState,pcVar4);
  local_3c = 0;
  do {
    if (7 < (int)local_3c) {
      Ai_Subsystem_004be357();
      *(undefined4 *)g_DisplaySurfaceScreen = 0;
      local_a4[0x10] = DAT_00677e10;
      local_a4[6] = 0x40;
      local_a4[7] = 0x50;
      local_a4[8] = 0x66;
      local_a4[0xd] = 0x48;
      local_a4[0xe] = 0x5a;
      local_a4[0xf] = 0x72;
      local_a4[0] = 0xcb;
      local_a4[1] = 0xfd;
      local_a4[2] = 0x143;
      local_a4[3] = 0x1af;
      local_a4[4] = 0x21a;
      local_a4[5] = 0x2b0;
      local_a4[10] = 0x2f;
      local_a4[0xb] = 0x3c;
      local_a4[0xc] = 0x4d;
      iVar2 = DAT_00677e10;
      iVar3 = Ai_Util_004c3bc4((int)*(short *)(DAT_00677e10 + 6));
      iVar6 = Ai_Util_004c3bc4((int)*(short *)(local_a4[0x10] + 4));
      iVar5 = Ai_Util_004c3bc4(0x105);
      iVar5 = iVar5 + DAT_005574b0 * 2 + DAT_0052d77c + 0x10;
      iVar7 = Ai_Util_004c3bc4(0x141);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,iVar7 + 0x40,iVar5,iVar6,iVar3,iVar2);
      if (DAT_00522458 == 0x280) {
        local_a4[9] = 0;
      }
      else if (DAT_00522458 == 800) {
        local_a4[9] = 1;
      }
      else if (DAT_00522458 == 0x400) {
        local_a4[9] = 2;
      }
      iVar6 = local_a4[local_a4[9] + 0xd] + DAT_005574b0 * 2 + DAT_0052d77c;
      iVar2 = DAT_00677fb0;
      iVar3 = Ai_Util_004c3bc4(0x30);
      Sprite_DrawDirect((int *)g_DisplaySurfaceBackBuffer,0x40,(iVar6 + 0x10) - iVar3,iVar2);
      iVar6 = DAT_005574b0 * 2 + DAT_0052d77c + 0x10;
      iVar2 = local_a4[local_a4[9]];
      iVar3 = DAT_00677fe4;
      iVar5 = Ai_Util_004c3bc4(0x40);
      Sprite_DrawDirect((int *)g_DisplaySurfaceBackBuffer,(iVar2 + 0x40) - iVar5,iVar6,iVar3);
      iVar6 = DAT_005574b0 * 2 + DAT_0052d77c + 0x10;
      iVar2 = local_a4[local_a4[9] + 3];
      iVar3 = DAT_00677fe4;
      iVar5 = Ai_Util_004c3bc4(0x40);
      Sprite_DrawDirect((int *)g_DisplaySurfaceBackBuffer,(iVar2 + 0x40) - iVar5,iVar6,iVar3);
      if (DAT_0064101c == 0) {
        if (DAT_00522458 == 0x400) {
          iVar2 = Ai_Util_004c3ba3(0x18);
          iVar3 = Ai_Util_004c3ba3(0x20);
          uVar8 = iVar3 + 4U & 0xfffffffc;
          piVar1 = (int *)g_DisplaySurfaceScreen;
          DVar9 = Ai_Util_004c3ba3(0x8c);
          iVar3 = Ai_Util_004c3ba3(0x100);
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0x40,DAT_005574b0 * 2 + DAT_0052d77c + 0x10
                       ,iVar3 - 2,DVar9,piVar1,uVar8,iVar2);
        }
        else {
          iVar2 = Ai_Util_004c3ba3(0x18);
          uVar8 = Ai_Util_004c3ba3(0x20);
          uVar8 = uVar8 & 0xfffffffc;
          piVar1 = (int *)g_DisplaySurfaceScreen;
          DVar9 = Ai_Util_004c3ba3(0x8c);
          arg_4 = Ai_Util_004c3ba3(0x100);
          FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0x40,DAT_005574b0 * 2 + DAT_0052d77c + 0x10
                       ,arg_4,DVar9,piVar1,uVar8,iVar2);
        }
      }
      else {
        local_a8 = (&DAT_0070a850)[*(int *)g_DisplaySurfaceBackBuffer];
        local_ac = (&DAT_0070a850)[*(int *)g_DisplaySurfaceScreen];
        if (DAT_00522458 == 0x400) {
          iVar2 = DAT_005574b0 * 2 + DAT_0052d77c + 0x10;
          arg_9 = 0x40;
          pHVar11 = *(HDC *)(local_a8 + 4);
          iVar12 = 8;
          iVar10 = 8;
          iVar3 = Ai_Util_004c3ba3(0x8c);
          iVar6 = Ai_Util_004c3ba3(0x100);
          iVar6 = iVar6 + -2;
          iVar5 = Ai_Util_004c3ba3(0x18);
          iVar7 = Ai_Util_004c3ba3(0x20);
          FUN_00511b90(*(HDC *)(local_ac + 4),iVar7 + 4U & 0xfffffffc,iVar5,iVar6,iVar3,iVar10,
                       iVar12,pHVar11,arg_9,iVar2);
          FUN_00501736(0x2d);
        }
        else {
          iVar2 = DAT_005574b0 * 2 + DAT_0052d77c + 0x10;
          iVar12 = 0x40;
          pHVar11 = *(HDC *)(local_a8 + 4);
          iVar10 = 6;
          iVar7 = 6;
          iVar3 = Ai_Util_004c3ba3(0x8c);
          iVar6 = Ai_Util_004c3ba3(0x100);
          iVar5 = Ai_Util_004c3ba3(0x18);
          uVar8 = Ai_Util_004c3ba3(0x20);
          FUN_00511b90(*(HDC *)(local_ac + 4),uVar8 & 0xfffffffc,iVar5,iVar6,iVar3,iVar7,iVar10,
                       pHVar11,iVar12,iVar2);
          FUN_00501736(0x2d);
        }
        DAT_0064101c = 0;
      }
      FUN_0050e6f0(local_ec,(int)g_DisplaySurfaceBackBuffer,local_24,local_20,local_1c,local_18);
      FUN_0050e6f0(local_fc,(int)g_DisplaySurfaceScreen,local_14,local_10,local_c,local_8);
      *(undefined4 *)g_DisplaySurfaceBackBuffer = local_28;
      if ((arg_3 == 0) && (DAT_0052d778 == 0)) {
        *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
        Pic_Subsystem_0044b8aa();
        Ai_CalcManaRequirement_004bf4b3(0);
        Ai_Subsystem_004bf23a();
      }
      else {
        Ai_Subsystem_004c3c5c(0);
        DAT_0052d778 = 0;
        Pic_Subsystem_0044b8aa();
      }
      return;
    }
    Ai_Subsystem_004be49b
              (*(uint *)(&DAT_0067f2d4 + local_3c * 0x14) & 0xffffffe0,
               *(uint *)(&DAT_0067f2d8 + local_3c * 0x14) & 0xffffffe0,&local_60,&local_54);
    Ai_Subsystem_004be43f
              (*(uint *)(&DAT_0067f2d4 + local_3c * 0x14) & 0x1f,
               *(uint *)(&DAT_0067f2d8 + local_3c * 0x14) & 0x1f,&local_58,&local_5c);
    local_48[0] = local_58 + local_60;
    local_50[0] = local_5c + local_54;
    local_60 = (int)(*(int *)(&DAT_0067f2d4 + local_3c * 0x14) +
                    (*(int *)(&DAT_0067f2d4 + local_3c * 0x14) >> 0x1f & 0x1fU)) >> 5;
    local_54 = (int)(*(int *)(&DAT_0067f2d8 + local_3c * 0x14) +
                    (*(int *)(&DAT_0067f2d8 + local_3c * 0x14) >> 0x1f & 0x1fU)) >> 5;
    if (((*(int *)(&DAT_0067f2d0 + local_3c * 0x14) != -1) &&
        (iVar2 = abs(local_60 - _DAT_00557484), iVar2 < 2)) &&
       (iVar2 = abs(local_54 - _DAT_00557488), iVar2 < 2)) {
      local_34 = *(int *)(&DAT_0067f2d0 + local_3c * 0x14);
      if (((&DAT_00522630)[local_34 * 0x44] & 2) != 0) {
        local_34 = local_34 - (DAT_0067f37c >> 5 & 3);
      }
      if (((&DAT_00522631)[local_34 * 0x44] & 1) != 0) {
        iVar2 = FUN_0040a36f(local_48[0] + -0x140,local_50[0] + -0xf0);
        iVar3 = Ai_Util_004c3ba3(0x80);
        if (iVar3 < iVar2) goto LAB_004be98f;
      }
      iVar2 = local_50[0];
      if (*(int *)(&DAT_0067f2d0 + local_3c * 0x14) == 0) {
        arg_5 = *(undefined4 *)
                 (&DAT_00677420 +
                 (char)(&DAT_0052d7a8)[*(int *)(&DAT_0067f2dc + local_3c * 0x14)] * 4);
        iVar6 = local_50[0];
        iVar5 = Ai_Util_004c3ba3(0x30);
        iVar3 = local_48[0];
        iVar2 = iVar2 - iVar5;
        iVar5 = Ai_Util_004c3ba3(0x20);
        Ai_Subsystem_004be25f(g_DisplaySurfaceScreen,iVar3 - iVar5,iVar2,iVar6,arg_5);
        iVar3 = local_50[0];
        iVar2 = *(int *)(&DAT_00677438 +
                        (char)(&DAT_0052d7a8)[*(int *)(&DAT_0067f2dc + local_3c * 0x14)] * 4);
        iVar5 = Ai_Util_004c3ba3(0x30);
        iVar6 = local_48[0];
        iVar5 = (iVar3 - iVar5) - DAT_006498d4;
        iVar3 = Ai_Util_004c3ba3(0x20);
        Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,(iVar6 - iVar3) - _DAT_006498d0,iVar5,iVar2
                          );
      }
      else {
        local_40 = local_3c;
        Ai_Subsystem_004be25f
                  (g_DisplaySurfaceScreen,local_48[0] - *(int *)(&DAT_006783f0 + local_3c * 4) / 2,
                   local_50[0] - *(int *)(&DAT_00677990 + local_3c * 4),local_50[0],
                   *(undefined4 *)
                    (&g_OverworldFoodAmount +
                    local_3c * 0xb4 +
                    ((int)(char)(&DAT_0067f2e0)[local_3c * 0x14] + 2U & 7) * 0x14 +
                    (char)(&DAT_0067f2e1)[local_3c * 0x14] * 4));
        local_40 = local_3c + 8;
        Sprite_DrawClipped((int *)g_DisplaySurfaceScreen,
                           (local_48[0] - *(int *)(&DAT_006783f0 + local_40 * 4) / 2) -
                           _DAT_006498d0,
                           (local_50[0] - *(int *)(&DAT_00677990 + local_40 * 4)) - DAT_006498d4,
                           *(int *)(&g_OverworldFoodAmount +
                                   local_40 * 0xb4 +
                                   ((int)(char)(&DAT_0067f2e0)[local_3c * 0x14] + 2U & 7) * 0x14 +
                                   (char)(&DAT_0067f2e1)[local_3c * 0x14] * 4));
      }
      if ((((int)DAT_0067f37c >> 3 ^ local_3c & 3) & 3) == 0) {
        *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 3;
        g_OverworldWorldState = 0;
        Adventure_FormatNewsString(local_34,0,0);
      }
    }
LAB_004be98f:
    local_3c = local_3c + 1;
  } while( true );
}


