/*
 * Decompiled function: Castle_Process_00492ddf
 * Entry Point: 00492ddf
 * Size: 2808 bytes
 */
#include "magic.h"


void Castle_Process_00492ddf(int arg_1)

{
  byte bVar1;
  undefined4 uVar2;
  DWORD arg_5;
  uint arg_4;
  int iVar3;
  uint arg_2;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int local_88 [4];
  int local_78 [4];
  int local_68 [4];
  int local_58 [4];
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0x98;
  local_18 = 0xab;
  local_14 = 0x3a;
  FUN_005112b0(0,(short)DAT_00530d9c);
  LoadPalNoPic(s_advfac64_pic_005289ec);
  Mem_AllocOrFree_00510e20(1,s_cluebutn_pic_005289fc);
  Mem_AllocOrFree_0050fc00();
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    uVar2 = Sprite_EncodeFromSurface(1,local_c * 0x5a + 1,1,0x59,0x23);
    (&DAT_00676b90)[local_c] = (void *)uVar2;
    uVar2 = Sprite_EncodeFromSurface(1,local_c * 0x15 + 1,0x25,0x14,0x24);
    *(undefined4 *)(&DAT_00676c80 + local_c * 4) = uVar2;
  }
  if (DAT_00527fa8 == DAT_00527f98) {
    DAT_00527fa8 = Ai_Util_004c3bc4(DAT_00527fa8);
    DAT_00527fac = Ai_Util_004c3bc4(DAT_00527fac);
    DAT_00527fb0 = Ai_Util_004c3bc4(DAT_00527fb0);
    DAT_00527fb4 = Ai_Util_004c3bc4(DAT_00527fb4);
  }
  local_20 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_20);
  FUN_0041f17e(0x527f98,1,local_20);
  FUN_0050fc20();
  FUN_00510b70(1,0,DAT_0052245c - 0x1e0,s_clueback_pic_00528a0c,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c);
  FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
               (int *)g_DisplaySurfaceScreen,0,0);
  iVar8 = 0;
  iVar7 = 0;
  piVar6 = (int *)g_DisplaySurfaceBackBuffer;
  arg_5 = Ai_Util_004c3bc4(0x24);
  arg_4 = Ai_Util_004c3bc4(0x5a);
  iVar3 = Ai_Util_004c3bc4(0x1a2);
  arg_2 = Ai_Util_004c3bc4(0x16);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar3,arg_4,arg_5,piVar6,iVar7,iVar8);
  FUN_0041f213();
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
  g_OverworldWorldState = 0;
  FUN_0048e2b0(arg_1);
  if (arg_1 < 5) {
    strcat(&g_OverworldWorldState,s___00528a1c);
    pcVar4 = (char *)Mem_AllocOrFree_00473d7e(arg_1 + 1);
    strcat(&g_OverworldWorldState,pcVar4);
    strcat(&g_OverworldWorldState,s_Castle__00528a28);
    FUN_0040d1cd((int)g_DisplaySurfaceScreen,local_14,0x12,0x1c);
    local_10 = Ai_Util_004c3ba3(0x24);
  }
  else {
    local_10 = FUN_00492cb1(0x10,local_14);
    local_10 = Ai_Util_004c3ba3(0x1c);
  }
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    if (*(int *)(&DAT_0067eff0 + local_c * 4 + arg_1 * 0x30) != -1) {
      FUN_0050b206(*(int *)(&DAT_0067eff0 + local_c * 4 + arg_1 * 0x30),local_c * 0x29 + 0xa0,
                   (-(uint)(local_c == 0) & 8) + local_c * 4 + 0x76,1,&DAT_00528a34);
    }
  }
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 2) != 0) || (DAT_0067b9a4 != 0)) {
    iVar3 = local_10;
    uVar2 = local_8;
    iVar7 = Ai_Util_004c3ba3(0xc);
    FUN_0040c1ad(s_Creatures__00528a38,iVar7,iVar3,uVar2);
    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_10 = local_10 + iVar3;
    if (arg_1 < 5) {
      bVar1 = FUN_0049094c();
      (&DAT_0067f00d)[arg_1 * 0x30] = bVar1 | 0x80;
    }
    strcpy(&g_OverworldWorldState,s__Contains_00528a44);
    strcat(&g_OverworldWorldState,
           s_large_00528a50 + ((((&DAT_0067f00d)[arg_1 * 0x30] & 0x80) != 0) - 1 & 8));
    pcVar4 = (char *)Mem_AllocOrFree_00473d7e((int)(char)(&DAT_0067f00c)[arg_1 * 0x30]);
    strcat(&g_OverworldWorldState,pcVar4);
    strcat(&g_OverworldWorldState,s_creatures__00528a60);
    local_10 = FUN_00492cb1(local_10,local_18);
  }
  iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  iVar3 = local_10 + iVar3;
  local_10 = iVar3;
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 4) != 0) || (DAT_0067b9a4 != 0)) {
    uVar2 = local_8;
    iVar7 = Ai_Util_004c3ba3(0xc);
    FUN_0040c1ad(s_Dungeon_Rules__00528a6c,iVar7,iVar3,uVar2);
    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_10 = local_10 + iVar3;
    if (((&DAT_0067f014)[arg_1 * 0x30] & 0x10) != 0) {
      strcpy(&g_OverworldWorldState,&DAT_00528a7c);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e((int)(char)(&DAT_0067f00c)[arg_1 * 0x30]);
      strcat(&g_OverworldWorldState,pcVar4);
      strcat(&g_OverworldWorldState,s_cards_allowed__00528a84);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 0x20) != 0) {
      strcpy(&g_OverworldWorldState,s__One_deck_for_all_duels__00528a94);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 0x40) != 0) {
      strcpy(&g_OverworldWorldState,s__No_artifacts_allowed__00528ab0);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 0x80) != 0) {
      strcpy(&g_OverworldWorldState,s__No_instants_or_interrupts_allow_00528ac8);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 1) != 0) {
      strcpy(&g_OverworldWorldState,s__Life_losses_carried_over__00528aec);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (((&DAT_0067f014)[arg_1 * 0x30] & 2) != 0) {
      strcpy(&g_OverworldWorldState,s__Remaining_life_added_to_next_du_00528b08);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    if (*(int *)(&DAT_0067effc + arg_1 * 0x30) == -1) {
      if (*(int *)(&DAT_0067f014 + arg_1 * 0x30) == 0) {
        strcpy(&g_OverworldWorldState,s__No_special_rules__00528b48);
        local_10 = FUN_00492cb1(local_10,local_18);
      }
    }
    else {
      strcpy(&g_OverworldWorldState,&DAT_00528b2c);
      iVar3 = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + arg_1 * 0x30));
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar3 * 0x34);
      strcat(&g_OverworldWorldState,s_permanently_in_effect__00528b30);
      local_10 = FUN_00492cb1(local_10,local_18);
    }
    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_10 = local_10 + iVar3;
  }
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 1) != 0) || (DAT_0067b9a4 != 0)) {
    iVar3 = local_10;
    uVar2 = local_8;
    iVar7 = Ai_Util_004c3ba3(0xc);
    FUN_0040c1ad(s_Location__00528b5c,iVar7,iVar3,uVar2);
    iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
    local_10 = local_10 + iVar3;
    local_1c = *(int *)(&DAT_0067f000 + arg_1 * 0x30) -
               *(int *)(&DAT_0067bdf4 + *(int *)(&DAT_0067f008 + arg_1 * 0x30) * 100);
    local_24 = *(int *)(&DAT_0067f004 + arg_1 * 0x30) -
               *(int *)(&DAT_0067bdf8 + *(int *)(&DAT_0067f008 + arg_1 * 0x30) * 100);
    if (local_24 < 1) {
      strcpy(&g_OverworldWorldState,s__North_00528b78 + ((0 < local_1c) - 1 & 8));
    }
    else {
      strcpy(&g_OverworldWorldState,s__East_00528b68 + ((0 < local_1c) - 1 & 8));
    }
    strcat(&g_OverworldWorldState,&DAT_00528b88);
    Ai_TownEncounter_004c3b19(*(uint *)(&DAT_0067f008 + arg_1 * 0x30));
    strcat(&g_OverworldWorldState,&DAT_00528b90);
    local_10 = FUN_00492cb1(local_10,local_18);
  }
  if ((((&DAT_0067f010)[arg_1 * 0x30] & 1) != 0) || (DAT_0067b9a4 != 0)) {
    FUN_0040c550(g_DisplaySurfaceWork,0,0,0x50,0x32,g_DisplaySurfaceWork,0x50,0);
    uVar2 = 0;
    iVar3 = Ai_Util_004c3bc4(0xe1);
    iVar3 = iVar3 + -0x18;
    iVar7 = Ai_Util_004c3bc4(0x17e);
    iVar7 = iVar7 + -0x18;
    iVar8 = Ai_Util_004c3bc4(0xc);
    iVar8 = iVar8 + 10;
    iVar5 = Ai_Util_004c3bc4(0xf4);
    (*(code *)PTR_FUN_00527b3c)(iVar5 + 10,iVar8,iVar7,iVar3,uVar2);
    *(undefined4 *)g_DisplaySurfaceScreen = *(undefined4 *)g_DisplaySurfaceBackBuffer;
    Ai_Util_004be240();
    local_48 = *(undefined4 *)g_DisplaySurfaceBackBuffer;
    DAT_00641884 = 0;
    piVar6 = (int *)FUN_0050e6f0(local_58,(int)g_DisplaySurfaceBackBuffer,0,0x80,
                                 *(int *)(g_DisplaySurfaceScreen + 0xc),
                                 *(int *)(g_DisplaySurfaceScreen + 0x10) + -0x80);
    local_44 = *piVar6;
    local_40 = piVar6[1];
    local_3c = piVar6[2];
    local_38 = piVar6[3];
    piVar6 = (int *)FUN_0050e6f0(local_68,(int)g_DisplaySurfaceScreen,0,0x80,
                                 *(int *)(g_DisplaySurfaceScreen + 0xc),
                                 *(int *)(g_DisplaySurfaceScreen + 0x10) + -0x80);
    local_34 = *piVar6;
    local_30 = piVar6[1];
    local_2c = piVar6[2];
    local_28 = piVar6[3];
    Ai_Subsystem_004c06df
              (*(int *)(&DAT_0067f000 + arg_1 * 0x30) * 0x20 + 0x10,
               *(int *)(&DAT_0067f004 + arg_1 * 0x30) * 0x20 + 0x10);
    Ai_Subsystem_004be357();
    DAT_00641884 = 0;
    FUN_0050e6f0(local_78,(int)g_DisplaySurfaceBackBuffer,local_44,local_40,local_3c,local_38);
    FUN_0050e6f0(local_88,(int)g_DisplaySurfaceScreen,local_34,local_30,local_2c,local_28);
    *(undefined4 *)g_DisplaySurfaceBackBuffer = local_48;
    *(undefined4 *)g_DisplaySurfaceScreen = 0;
    FUN_0040c550(g_DisplaySurfaceBackBuffer,0x40,DAT_0052d77c,0xb3,100,g_DisplaySurfaceScreen,0x7f,
                 0xb);
    FUN_0040c550(g_DisplaySurfaceWork,0x50,0,0x50,0x32,g_DisplaySurfaceWork,0,0);
  }
  DAT_0054aae0 = -1;
  while (DAT_0054aae0 == -1) {
    Pic_Subsystem_0044b84b();
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  Palette_Subsystem_00496eaf();
  FUN_0041f391();
  Mem_AllocOrFree_0050fc50(DAT_00676b90);
  return;
}


