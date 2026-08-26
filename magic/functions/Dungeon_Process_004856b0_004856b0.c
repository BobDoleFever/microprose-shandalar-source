/*
 * Decompiled function: Dungeon_Process_004856b0
 * Entry Point: 004856b0
 * Size: 14542 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Dungeon_Process_004856b0(uint arg1,int arg2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  void *pvVar12;
  uint uVar13;
  int local_964 [11];
  int local_938;
  int local_934;
  int local_930;
  int local_92c;
  int local_928;
  int local_924;
  int local_920;
  int local_91c;
  int local_918;
  int local_914;
  char *local_910;
  char *local_90c;
  char *local_908;
  char *local_904;
  char *local_900;
  int local_8fc;
  int local_8f8;
  void *local_8f4;
  void *local_8ec;
  int local_8cc;
  int local_8c8;
  uint local_8c4;
  int local_8c0;
  uint local_8bc;
  uint local_8b8;
  undefined *local_8b4;
  uint auStack_8b0 [10];
  int local_888;
  int local_884;
  uint local_880;
  uint local_87c;
  LPVOID local_878;
  uint local_874;
  uint local_870;
  int local_86c;
  int local_868;
  uint local_864;
  uint local_860;
  uint local_85c;
  int local_850;
  int local_84c;
  int local_848;
  int local_844;
  int local_840;
  int local_83c;
  int local_838;
  undefined4 local_834;
  int local_830;
  uint local_82c [518];
  LPVOID local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_8b4 = PTR_FUN_00527b3c;
  Adventure_Audio_StopAllTracks();
  if (*(int *)(&DAT_0067f2d0 + arg1 * 0x14) == 0) {
    Sound_LoadWav_x_DuelSounds_artifact_0040de30(*(int *)(&DAT_0067f2dc + arg1 * 0x14));
    DAT_0067f384 = DAT_0067f384 + 1;
    Adventure_LoadFacePalette(0);
  }
  else {
    FUN_0046f21e(s_dbox2_spr_00527110,0xd5,0xd2);
    local_14 = *(LPVOID *)(&DAT_0067f2d0 + arg1 * 0x14);
    DAT_006b2d64 = arg2;
    DAT_00695df0 = (int)(char)(&DAT_00522629)[(int)local_14 * 0x44];
    local_880 = DAT_00695df0 + (int)(char)(&DAT_00522628)[(int)local_14 * 0x44] / 2;
    if ('\n' < (char)(&DAT_0052262a)[(int)local_14 * 0x44]) {
      local_880 = 0;
    }
    Adventure_Audio_PlayDuelIntro(0);
    if ((&DAT_0052262a)[(int)local_14 * 0x44] == '\v') {
      local_8bc = Bazaar_GetCardBaseValue(DAT_00531590);
    }
    else {
      local_8bc = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)local_14 * 0x44));
      if (local_8bc == 0xffffffff) {
        local_8bc = arg2 - 1;
      }
    }
    DAT_006b2d98 = 0xffffffff;
    DAT_006b2d94 = 0xffffffff;
    DAT_006b2d90 = 0xffffffff;
    DAT_006b2dd8 = 0xffffffff;
    DAT_006b2dd4 = 0xffffffff;
    DAT_006b2dd0 = -1;
    FUN_004909d3((int)local_14,0xffffffff,0,-1);
    if ((&DAT_0052262a)[(int)local_14 * 0x44] != '\v') {
      do {
        do {
          DAT_006b2dd0 = FUN_0040a02a(DAT_0052eff8);
        } while (DAT_006b2dd0 < 5);
      } while (((((&DAT_0051aed1)[DAT_006b2dd0 * 0x34] & 1) != 0) ||
               (iVar3 = FUN_00485005(DAT_006b2dd0), iVar3 == 0)) ||
              (*(int *)(&g_MasterCardTypeTable + DAT_006b2dd0 * 0x34) ==
               *(int *)(&DAT_0052262c + (int)local_14 * 0x44)));
    }
    if ((&DAT_0052262a)[(int)local_14 * 0x44] == '\f') {
      local_840 = 3;
    }
    else {
      local_840 = 1;
    }
    Adventure_ShowDefeatScreen();
    for (local_874 = 0; (int)local_874 < local_840; local_874 = local_874 + 1) {
      do {
        do {
          local_878 = (LPVOID)FUN_0040a1d2(500);
        } while (*(int *)(&deck + (int)local_878 * 4) == -1);
      } while ((((&DAT_00702151)[(int)local_878 * 4] & 0x40) != 0) ||
              ((*(uint *)(&deck + (int)local_878 * 4) & 0xfff) < 5));
      (&DAT_006b2d90)[local_874] = *(uint *)(&deck + (int)local_878 * 4) & 0xfff;
    }
    local_834 = 2;
    local_910 = s_prdblk_pic_00527128;
    local_90c = s_prdblu_pic_00527140;
    local_908 = s_prdgrn_pic_00527158;
    local_904 = s_prdrd_pic_00527170;
    local_900 = s_prdwt_pic_00527188;
    FUN_005112b0(0,(short)DAT_00530d9c);
    FUN_00510b70(1,0,0,(char *)(&local_914)[arg2],
                 (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
    FUN_005115a0(0,(short)DAT_00530d9c);
    FUN_004f3955(_hdcScreen);
    Mem_AllocOrFree_00510e20(1,s_prdfrma_pic_00527194);
    Mem_AllocOrFree_0050fc00();
    local_8f4 = (void *)Sprite_EncodeFromSurface(1,1,1,0x68,0x2c);
    local_914 = Sprite_EncodeFromSurface(1,1,0x2e,0x67,0x31);
    local_8cc = Sprite_EncodeFromSurface(1,1,0x60,0x66,0x2c);
    local_8fc = Sprite_EncodeFromSurface(1,1,0x8d,0x79,0x2c);
    local_8c8 = Sprite_EncodeFromSurface(1,1,0xba,0x91,0x72);
    pvVar12 = local_8f4;
    iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 6));
    iVar4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 4));
    iVar5 = Ai_Util_004c3bc4(0x173);
    iVar6 = Ai_Util_004c3bc4(0x14);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar6,iVar5,iVar4,iVar3,(int)pvVar12);
    iVar3 = local_914;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_914 + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_914 + 4));
    iVar6 = Ai_Util_004c3bc4(0x16d);
    iVar7 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 4));
    iVar8 = Ai_Util_004c3bc4(0x14);
    iVar9 = Ai_Util_004c3bc4(8);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,(iVar7 + iVar8) - iVar9,iVar6,iVar5,iVar4,iVar3)
    ;
    iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_914 + 4));
    iVar4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 4));
    iVar5 = Ai_Util_004c3bc4(8);
    local_8f8 = Ai_Util_004c3bc4(0x14);
    local_8f8 = ((iVar3 + iVar4) - iVar5) / 2 + local_8f8;
    iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 4));
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_8cc + 4));
    iVar5 = Ai_Util_004c3bc4(8);
    local_8f8 = local_8f8 - ((iVar3 + iVar4) - iVar5) / 2;
    iVar3 = local_8fc;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 4));
    iVar6 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 6));
    iVar7 = Ai_Util_004c3bc4(0x173);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,local_8f8,iVar6 + iVar7,iVar5,iVar4,iVar3);
    iVar3 = local_8cc;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_8cc + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_8cc + 4));
    iVar6 = Ai_Util_004c3bc4((int)*(short *)((int)local_8f4 + 6));
    iVar7 = Ai_Util_004c3bc4(0x173);
    iVar6 = iVar6 + iVar7;
    iVar7 = Ai_Util_004c3bc4((int)*(short *)(local_8fc + 4));
    iVar7 = local_8f8 + iVar7;
    iVar8 = Ai_Util_004c3bc4(8);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar7 - iVar8,iVar6,iVar5,iVar4,iVar3);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xd2,0x5b,0x188);
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xd2,0xbd,0x188);
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xd2,0x5b,0x1b5);
    Minit_Subsystem_00452827();
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xd2,0xc3,0x1b5);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 2;
    iVar3 = local_8c8;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_8c8 + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_8c8 + 4));
    iVar6 = Ai_Util_004c3bc4(0x15e);
    iVar7 = Ai_Util_004c3bc4(0x1d4);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar7,iVar6,iVar5,iVar4,iVar3);
    Ai_CalcManaRequirement_004c003d();
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xd2,0x21f,0x199);
    FUN_0050fc20();
    Mem_AllocOrFree_0050fc50(local_8f4);
    iVar6 = 0;
    iVar5 = 0;
    iVar3 = Ai_Util_004c3bc4(10);
    iVar4 = Ai_Util_004c3bc4(0x140);
    Pic_Load_advfac64_00489188(local_14,iVar4,iVar3,iVar5,iVar6);
    Mem_AllocOrFree_00510e20(1,s_prdfrmb_pic_005271b4);
    *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
    Mem_AllocOrFree_0050fc00();
    local_8ec = (void *)Sprite_EncodeFromSurface(1,1,0x17e,0x98,0x23);
    local_918 = Sprite_EncodeFromSurface(1,1,0x1a2,0x80,0x23);
    FUN_0050fc20();
    pvVar12 = local_8ec;
    iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8ec + 6));
    iVar4 = Ai_Util_004c3bc4((int)*(short *)((int)local_8ec + 4));
    iVar5 = Ai_Util_004c3bc4(5);
    iVar6 = Ai_Util_004c3bc4(0x220 - (int)*(short *)((int)local_8ec + 4) / 2);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar6,iVar5,iVar4,iVar3,(int)pvVar12);
    iVar3 = Ai_Util_004c3bc4((int)*(short *)((int)local_8ec + 6) / 2 + 5);
    iVar4 = Ai_Util_004c3bc4(0x220);
    FUN_0040d009((int)g_DisplaySurfaceScreen,0xe6,iVar4,iVar3);
    iVar3 = local_918;
    iVar4 = Ai_Util_004c3bc4((int)*(short *)(local_918 + 6));
    iVar5 = Ai_Util_004c3bc4((int)*(short *)(local_918 + 4));
    iVar6 = Ai_Util_004c3bc4(5);
    iVar7 = Ai_Util_004c3bc4(100 - (int)*(short *)(local_918 + 4) / 2);
    Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar7,iVar6,iVar5,iVar4,iVar3);
    iVar3 = Ai_Util_004c3bc4((int)*(short *)(local_918 + 6) / 2 + 5);
    iVar4 = Ai_Util_004c3bc4(100);
    FUN_0040d009((int)g_DisplaySurfaceScreen,0xe6,iVar4,iVar3);
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    Mem_AllocOrFree_0050fc50(local_8ec);
    g_OverworldWorldState = 0;
    Adventure_FormatNewsString((int)local_14,0,0);
    strcat(&g_OverworldWorldState,s__s_ANTE__005271dc);
    if ((g_IsAiThinking == 0) && ((&DAT_0052262a)[(int)local_14 * 0x44] != '\v')) {
      FUN_0050b206(DAT_006b2dd0,0xe8,0x18,1,&DAT_005271e8);
    }
    local_83c = FUN_0040a305(local_880 * 10,10,local_880 * 0x32);
    if ((&DAT_0052262a)[(int)local_14 * 0x44] != '\v') {
      local_86c = 0;
      local_838 = 0;
      local_924 = (int)(*(int *)(&DAT_0067f2d4 + arg1 * 0x14) +
                       (*(int *)(&DAT_0067f2d4 + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5;
      local_928 = (int)(*(int *)(&DAT_0067f2d8 + arg1 * 0x14) +
                       (*(int *)(&DAT_0067f2d8 + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5;
      local_91c = *(int *)(&DAT_0067f000 + (arg2 + -1) * 0x30);
      local_920 = *(int *)(&DAT_0067f004 + (arg2 + -1) * 0x30);
      iVar3 = abs(local_924 - local_91c);
      if ((iVar3 <= DAT_0067f380 / 2 + 2) &&
         (iVar3 = abs(local_928 - local_920), iVar3 <= DAT_0067f380 / 2 + 2)) {
        local_838 = 1;
      }
      if (arg1 == 7) {
        local_838 = 2;
      }
LAB_0048627e:
      for (local_874 = 0; (int)local_874 < local_840; local_874 = local_874 + 1) {
        if (g_IsAiThinking == 0) {
          FUN_0050b206((&DAT_006b2d90)[local_874],local_874 * 0x18 + 10,local_874 * 0xc + 0x18,1,
                       &DAT_005271ec);
        }
      }
      local_850 = 0;
      for (local_874 = 0; ((int)local_874 < 1000 && ((&DAT_0067b9b0)[local_874] != '\0'));
          local_874 = local_874 + 1) {
        if (((&DAT_0052262a)[(int)local_14 * 0x44] == ((&DAT_0067b9b0)[local_874] & 0xf)) &&
           ((int)(char)(&DAT_0067b9b0)[local_874] >> 4 == arg2)) {
          local_850 = local_850 + 1;
        }
      }
      if (local_838 == 1) {
        strcpy(&g_OverworldWorldState,s_Those_who_near_the_stronghold_of_005271f0);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_will_be_met_with_the_firm_00527220);
        strcat(&g_OverworldWorldState,s_you_must____Duel_00527254);
        Adventure_FormatNewsString((int)local_14,1,0);
        strcat(&g_OverworldWorldState,&DAT_00527268);
      }
      else if (local_838 == 2) {
        strcpy(&g_OverworldWorldState,s_Those_who_would_challenge_the_Gr_0052726c);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_for_Supremacy_of_00527294);
        uVar13 = Duel_GetCardDrawOriginY
                           ((int)(*(int *)(&DAT_0067f2d4 + arg1 * 0x14) +
                                 (*(int *)(&DAT_0067f2d4 + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5,
                            (int)(*(int *)(&DAT_0067f2d8 + arg1 * 0x14) +
                                 (*(int *)(&DAT_0067f2d8 + arg1 * 0x14) >> 0x1f & 0x1fU)) >> 5);
        Ai_TownEncounter_004c3b19(uVar13);
        strcat(&g_OverworldWorldState,s_must____Duel_005272b0);
        Adventure_FormatNewsString((int)local_14,1,0);
        strcat(&g_OverworldWorldState,&DAT_005272c0);
      }
      else if (local_850 < 5) {
        strcpy(&g_OverworldWorldState,s_Those_who_enter_the_domain_of_th_005272c4);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_must_pay_for_the_privileg_005272f0);
        strcat(&g_OverworldWorldState,s_Will_you____Duel_00527318);
        Adventure_FormatNewsString((int)local_14,1,0);
        strcat(&g_OverworldWorldState,&DAT_0052732c);
      }
      else {
        strcpy(&g_OverworldWorldState,&DAT_00527330);
        strcat(&g_OverworldWorldState,s_Lairs_00522614 + (int)local_14 * 0x44);
        strcat(&g_OverworldWorldState,s_who_inhabit_the_domain_of_the_Mi_00527338);
        pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_Wizard_tremble_in_fear_of_your_v_00527360);
        strcat(&g_OverworldWorldState,s_Will_you____Accept_tribute_for_y_0052738c);
      }
      local_8c4 = 1;
      if ((((local_878 == (LPVOID)0x0) || (Gold < local_83c)) || (local_838 != 0)) ||
         (4 < local_850)) {
        local_864 = 0xffffffff;
      }
      else {
        strcat(&g_OverworldWorldState,s_Pay_005273bc);
        pcVar10 = _itoa(local_83c,&DAT_00539d50,10);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,s_gold__005273c4);
        local_864 = local_8c4;
        local_8c4 = local_8c4 + 1;
      }
      if (((local_850 < DAT_0067f380 * 2 + 2) || (local_838 != 0)) || (4 < local_850)) {
        local_860 = 0xffffffff;
      }
      else {
        strcat(&g_OverworldWorldState,s_Answer_a_riddle__005273cc);
        local_860 = local_8c4;
        local_8c4 = local_8c4 + 1;
      }
      if ((((_DAT_0067f374 & 1) == 0) || (local_86c != 0)) || (local_840 != 1)) {
        if (local_86c == 0) {
          local_85c = 0xffffffff;
        }
        else {
          strcat(&g_OverworldWorldState,&DAT_005273f4);
          local_85c = 0xffffffff;
        }
      }
      else {
        strcat(&g_OverworldWorldState,s_Change_ante_card__005273e0);
        local_85c = local_8c4;
        local_8c4 = local_8c4 + 1;
      }
      if (g_IsAiThinking < 0) {
        local_870 = 0;
      }
      else {
        do {
          uVar11 = Ai_Util_004c3bc4(0x100);
          iVar3 = DAT_00522458 / 2;
          iVar4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
          local_870 = FUN_00489710(&g_OverworldWorldState,(iVar3 - iVar4 / 2) + -2,uVar11);
        } while (local_870 == 0xffffffff);
      }
      if (((((int)local_870 < 1) && (4 < local_850)) && (-(int)local_14 != DAT_0067f2c0)) &&
         (local_838 == 0)) {
        local_964[10] = FUN_0040a1d2(3);
        local_938 = FUN_0040a1d2(3);
        strcpy(&g_OverworldWorldState,s_I_thank_your_for_your_mercy_gran_005273f8);
        if (local_964[10] == 0) {
          strcat(&g_OverworldWorldState,s_A_spell_from_my_deck__00527430);
        }
        else if (local_964[10] == 1) {
          strcat(&g_OverworldWorldState,s_The_location_of_WORLDMAGIC_cards_00527448);
        }
        else if (local_964[10] == 2) {
          strcat(&g_OverworldWorldState,s_Secrets_from_the_0052746c);
          pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_Castle__00527480);
        }
        if (local_938 == 0) {
          strcat(&g_OverworldWorldState,&DAT_0052748c);
          cVar1 = (&DAT_00522628)[(int)local_14 * 0x44];
          iVar3 = FUN_0040a1d2(10 - DAT_0067f380);
          local_930 = (cVar1 + iVar3) * 10;
          pcVar10 = _itoa(local_930,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_Gold_00527490);
        }
        else if (local_938 == 1) {
          strcat(&g_OverworldWorldState,s_40_Food_00527498);
        }
        else if (local_938 == 2) {
          strcat(&g_OverworldWorldState,&DAT_005274a4);
          local_934 = FUN_0040a1d2(3);
          local_934 = local_934 + 1;
          local_92c = FUN_0040a1d2(5);
          local_92c = local_92c + 1;
          pcVar10 = _itoa(local_934,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,&DAT_005274a8);
          pcVar10 = (char *)Mem_AllocOrFree_00473d7e(local_92c);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_Jewel_005274ac);
          strcat(&g_OverworldWorldState,&DAT_005274b4 + ((local_934 == 1) - 1 & 4));
        }
        strcat(&g_OverworldWorldState,s_Duel_Anyway_005274bc);
        local_870 = FUN_00489710(&g_OverworldWorldState,0x80,0xc0);
        if ((local_870 == 0) && (local_964[10] == 0)) {
          FUN_004909d3((int)local_14,0xffffffff,0,-1);
          for (arg1 = 0; (int)arg1 < 500; arg1 = arg1 + 1) {
            uVar11 = FUN_0040a02a(DAT_0052eff8);
            *(undefined4 *)(&DAT_0069ef00 + arg1 * 4) = uVar11;
            if (((&DAT_0051aed1)[*(int *)(&DAT_0069ef00 + arg1 * 4) * 0x34] & 1) != 0) {
              *(undefined4 *)(&DAT_0069ef00 + arg1 * 4) = 0xffffffff;
            }
          }
          SelectPalette(_hdcScreen,DAT_00626834,0);
          FUN_005112b0(0,(short)DAT_00530d9c);
          FUN_0046f21e(s_dbox_spr_005274cc,0x71,0xe3);
          local_8bc = Pic_Load_004509e8(g_CurrentTurnPhase,0x69ef00,500,s_Pick_a_spell_005274dc,1);
          if ((*(int *)(&DAT_0069ef00 + local_8bc * 4) != -1) &&
             (local_878 = (LPVOID)Pic_Subsystem_00451e40(*(uint *)(&DAT_0069ef00 + local_8bc * 4)),
             local_878 != (LPVOID)0xffffffff)) {
            *(uint *)(&deck + (int)local_878 * 4) = *(uint *)(&deck + (int)local_878 * 4) | 0x4000;
          }
        }
        if ((local_870 == 0) && (local_964[10] == 1)) {
          strcpy(&g_OverworldWorldState,s_Which_WM_spell_do_you_seek____005274ec);
          local_84c = 0;
          for (arg1 = 0; (int)arg1 < 0xc; arg1 = arg1 + 1) {
            if ((_DAT_0067f374 & 1 << ((byte)arg1 & 0x1f)) == 0) {
              strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[arg1]);
              strcat(&g_OverworldWorldState,&DAT_0052750c);
              local_82c[local_84c] = arg1;
              local_84c = local_84c + 1;
            }
          }
          if (local_84c == 0) {
            g_OverworldWorldState = 0;
            strcpy(&g_OverworldWorldState,s_You_have_already_gathered_all_of_00527510);
            local_870 = FUN_004896be(&g_OverworldWorldState,0x50,100);
          }
          else {
            local_870 = FUN_00489710(&g_OverworldWorldState,0xa0,200);
            if (local_870 != 0xffffffff) {
              local_874 = *(uint *)(&DAT_005224e8 + local_82c[local_870] * 0x10);
              *(uint *)(&DAT_0067be00 + local_874 * 100) =
                   *(uint *)(&DAT_0067be00 + local_874 * 100) | 2;
              FUN_0040c81c(0x80,*(int *)(&DAT_0067bdf4 + local_874 * 100),
                           *(int *)(&DAT_0067bdf8 + local_874 * 100));
              strcpy(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_82c[local_870]])
              ;
              strcat(&g_OverworldWorldState,s_may_be_found_in_0052754c);
              Ai_TownEncounter_004c3b19(local_874);
              strcat(&g_OverworldWorldState,&DAT_00527560);
              FUN_00489710(&g_OverworldWorldState,0x5a,0x6e);
              Adventure_ReloadWorldPalette(0);
              Adventure_LoadFacePalette(0);
              SelectPalette(_hdcScreen,DAT_00626834,0);
              FUN_005112b0(0,(short)DAT_00530d9c);
              Ai_CastleEncounter_004c24b3(0);
            }
          }
        }
        if ((local_870 == 0) && (local_964[10] == 2)) {
          if (*(int *)(&DAT_006410bc + arg2 * 4) == 0) {
            if (((byte)*(undefined4 *)(&DAT_0067f010 + (arg2 + -1) * 0x30) & 7) == 7) {
              Castle_Process_00492ddf(arg2 + -1);
            }
            else {
              SelectPalette(_hdcScreen,DAT_00626834,0);
              FUN_005112b0(0,(short)DAT_00530d9c);
              FUN_0048ea81(arg2 + -1);
            }
          }
          else {
            g_OverworldWorldState = 0;
            strcpy(&g_OverworldWorldState,s_You_have_already_destroyed_the_00527564);
            pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
            strcat(&g_OverworldWorldState,pcVar10);
            strcat(&g_OverworldWorldState,s_Castle__00527584);
            FUN_004896be(&g_OverworldWorldState,0x54,0x74);
          }
        }
        if (local_870 == 1) {
          if (local_938 == 0) {
            Gold = Gold + local_930;
          }
          else if (local_938 == 1) {
            DAT_00522448 = DAT_00522448 + 0x28;
          }
          else if (local_938 == 2) {
            *(int *)(&DAT_0067bdbc + local_92c * 4) =
                 *(int *)(&DAT_0067bdbc + local_92c * 4) + local_934;
          }
        }
        if (local_870 != 2) goto LAB_00488f4b;
      }
      else {
        if (local_85c == local_870) goto LAB_00486fd1;
        if (local_860 == local_870) {
          iVar3 = Palette_Subsystem_00498a18();
          if (iVar3 == 0) {
            Adventure_Audio_PlayDuelIntro(2);
            strcpy(&g_OverworldWorldState,s_Lost_this_card_00527590);
            Mem_AllocOrFree_00510e20(1,s_losedul2_pic_005275a0);
            Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                               (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
            FUN_0050b206(DAT_006b2d90,0x17,0x50,1,&g_OverworldWorldState);
            FUN_0040a3e1();
            Ai_Subsystem_004cd1d1();
            FUN_00489630(DAT_006b2d90);
          }
          else {
            FUN_00501736(0x1e);
          }
          LoadPalNoPic(s_Prdblk_pic_005275b0);
          SelectPalette(_hdcScreen,DAT_00626834,0);
          FUN_005112b0(0,(short)DAT_00530d9c);
          FUN_0050d560(0,0);
          LoadPalNoPic(s_advfac64_pic_005275bc);
          FUN_0046f21e(s_dbox_spr_005275cc,0x71,0xe3);
          return 0;
        }
        if (local_864 == local_870) {
          Gold = Gold - local_83c;
          SelectPalette(_hdcScreen,DAT_00626834,0);
          FUN_005112b0(0,(short)DAT_00530d9c);
          LoadPalNoPic(s_advfac64_pic_005275d8);
          FUN_0046f21e(s_dbox_spr_005275e8,0x71,0xe3);
          return 0;
        }
      }
      goto LAB_00487364;
    }
    for (local_874 = 0; (int)local_874 < local_840; local_874 = local_874 + 1) {
      if (g_IsAiThinking == 0) {
        FUN_0050b206((&DAT_006b2d90)[local_874],local_874 * 0x18 + 10,local_874 * 0xc + 0x18,1,
                     &DAT_005275f4);
      }
    }
    strcpy(&g_OverworldWorldState,s_The_Evil_005275f8);
    pcVar10 = (char *)Mem_AllocOrFree_00473d7e(arg2);
    strcat(&g_OverworldWorldState,pcVar10);
    strcat(&g_OverworldWorldState,s_Wizard_has_sent_00527604);
    FUN_00488f92(arg2);
    strcat(&g_OverworldWorldState,&DAT_00527618);
    strcat(&g_OverworldWorldState,s_most_trusted_servant_to_0052761c);
    strcat(&g_OverworldWorldState,s_test_your_strength_00527638);
    strcat(&g_OverworldWorldState,s_you_must____Duel_0052764c);
    Adventure_FormatNewsString((int)local_14,1,0);
    strcat(&g_OverworldWorldState,&DAT_00527660);
    FUN_0040a3e1();
    uVar11 = Ai_Util_004c3bc4(0x100);
    iVar3 = DAT_00522458 / 2;
    iVar4 = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
    FUN_00489710(&g_OverworldWorldState,(iVar3 - iVar4 / 2) + -2,uVar11);
    Adventure_Audio_StopAllTracks();
LAB_00487364:
    local_c = 0;
    for (local_874 = 0; (int)local_874 < 1000; local_874 = local_874 + 1) {
      if ((&DAT_0067b9b0)[local_874] != '\0') {
        local_c = local_c + 1;
      }
    }
    local_878 = *(LPVOID *)(&DAT_006a48f0 + arg2 * 4);
    if ('\n' < (char)(&DAT_0052262a)[(int)local_14 * 0x44]) {
      local_878 = DAT_0052f000;
    }
    local_848 = *(int *)(&DAT_006a4908 + arg2 * 4);
    if ('\n' < (char)(&DAT_0052262a)[(int)local_14 * 0x44]) {
      local_848 = DAT_00626804;
    }
    iVar3 = FUN_0040a305(3 - local_c / 3,0,3);
    DAT_0063ee24 = -iVar3;
    if ((DAT_0067f380 == 3) || ('\n' < (char)(&DAT_0052262a)[(int)local_14 * 0x44])) {
      DAT_0063ee24 = 0;
    }
    if ((&DAT_0052262a)[(int)local_14 * 0x44] == '\v') {
      DAT_0063ee24 = *(int *)(&DAT_005224e4 + DAT_00531590 * 0x10) / 500 + -1;
    }
    if (-DAT_0067f380 < DAT_0063ee24) {
      local_878 = DAT_0052f000;
    }
    local_8b8 = (uint)((int)(CONCAT44(DAT_0067f37c >> 0x1f,DAT_0067f37c >> 2) % 3) == 0);
    if (local_8b8 != 0) {
      Adventure_Audio_PlayEffect(s_x_sound_dsummon_wav_00527664,0xf,100,100,0);
      if ((((&DAT_00522638)[(int)local_14 * 0x44] & 4) != 0) &&
         (iVar3 = FUN_0040a1d2(3), iVar3 == 0)) {
        iVar3 = FUN_0040a1d2(0x23);
        local_878 = (LPVOID)(iVar3 + 1);
        strcpy(&g_OverworldWorldState,s_decks_0_00527678);
        if ((*(int *)(&DAT_0052262c + (int)local_878 * 0x44) < 100) &&
           (strcat(&g_OverworldWorldState,&DAT_00527680),
           *(int *)(&DAT_0052262c + (int)local_878 * 0x44) < 10)) {
          strcat(&g_OverworldWorldState,&DAT_00527684);
        }
        pcVar10 = _itoa(*(int *)(&DAT_0052262c + (int)local_878 * 0x44),&DAT_00539d50,10);
        strcat(&g_OverworldWorldState,pcVar10);
        strcat(&g_OverworldWorldState,&DAT_00527688);
        FUN_00409f99(&g_OverworldWorldState,0,0,-1);
        DAT_0052effc = 0;
        strcpy(&g_OverworldWorldState,s_Why_don_t_you_try_this_deck__00527690);
        FUN_00489710(&g_OverworldWorldState,0xa0,0xa0);
      }
      if ((((*(uint *)(&DAT_00522638 + (int)local_14 * 0x44) & 0x110) != 0) &&
          (iVar3 = FUN_0040a1d2(3), iVar3 == 0)) && (-(int)local_14 != DAT_0067f2c0)) {
        do {
          do {
            iVar3 = FUN_0040a1d2(3);
            local_878 = (LPVOID)((int)local_14 + iVar3 + 1);
          } while (local_878 == (LPVOID)0x37);
        } while (((int)local_878 < 0x24) && ((int)local_878 % 7 == 0));
        iVar6 = 1;
        iVar5 = 0;
        iVar3 = Ai_Util_004c3bc4(10);
        iVar4 = Ai_Util_004c3bc4(0x140);
        Pic_Load_advfac64_00489188(local_878,iVar4,iVar3,iVar5,iVar6);
        g_OverworldWorldState = 0;
        Adventure_FormatNewsString((int)local_14,0,0);
        strcat(&g_OverworldWorldState,s_summons_005276b0);
        Adventure_FormatNewsString((int)local_878,1,0);
        strcat(&g_OverworldWorldState,&DAT_005276bc);
        FUN_00489710(&g_OverworldWorldState,0xa0,0x78);
        local_14 = local_878;
        local_880 = DAT_00695df0 + (int)(char)(&DAT_00522628)[(int)local_878 * 0x44] / 2;
      }
      if (((&DAT_00522638)[(int)local_14 * 0x44] & 0xc1) != 0) {
        DAT_006b2fe0 = Pic_Subsystem_0045268f(*(int *)(&DAT_00522640 + (int)local_14 * 0x44));
      }
      if (((&DAT_00522638)[(int)local_14 * 0x44] & 0xcb) != 0) {
        g_OverworldWorldState = 0;
        Adventure_FormatNewsString((int)local_14,0,0);
        strcat(&g_OverworldWorldState,s_has_005276c0);
        local_888 = 1;
        if (((&DAT_00522638)[(int)local_14 * 0x44] & 2) != 0) {
          if (DAT_0067f37c % 3 == 0) {
            strcat(&g_OverworldWorldState,s_Mind_Control_005276c8);
          }
          else {
            local_888 = 0;
          }
        }
        if (((&DAT_00522638)[(int)local_14 * 0x44] & 8) != 0) {
          DAT_0067a6b4 = 1;
          strcat(&g_OverworldWorldState,s_First_Strike_005276d8);
        }
        if (((&DAT_00522638)[(int)local_14 * 0x44] & 0xc1) != 0) {
          if (DAT_0063ee24 < 0) {
            DAT_006b2fe0 = -1;
            local_888 = 0;
          }
          else {
            Adventure_AppendNewsDetails((int)s_Swamp_0051aea9[DAT_006b2fe0 * 0x34],0);
            strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + DAT_006b2fe0 * 0x34);
          }
        }
        strcat(&g_OverworldWorldState,&DAT_005276e8);
        if (local_888 != 0) {
          FUN_00489710(&g_OverworldWorldState,0xb4,0x8c);
        }
      }
    }
    for (local_874 = 0; (int)local_874 < 7; local_874 = local_874 + 1) {
      if (((local_874 != arg1) && (*(int *)(&DAT_0067f2d0 + local_874 * 0x14) != 0)) &&
         ((iVar3 = FUN_0040a36f(DAT_0052eff0 - *(int *)(&DAT_0067f2d4 + local_874 * 0x14),
                                DAT_0052eff4 - *(int *)(&DAT_0067f2d8 + local_874 * 0x14)),
          iVar3 < 0x40 && (*(int *)(&DAT_0067f2d0 + local_874 * 0x14) != -1)))) {
        FUN_0046e70d(local_874,local_874 + 8);
        *(undefined4 *)(&DAT_0067f2d0 + local_874 * 0x14) = 0xffffffff;
      }
    }
    FUN_004909d3((int)local_14,local_8bc,(uint)local_878,local_848);
    Palette_Subsystem_00496eaf();
    FUN_005112b0(0,(short)DAT_00530d9c);
    SelectPalette(_hdcScreen,DAT_00626834,0);
    FUN_0046f21e(s_dbox_spr_005276ec,0x71,0xe3);
    Pic_Subsystem_00423c82(0);
    local_964[9] = -1;
    while (local_964[9] != 0) {
      Pic_Subsystem_00424020(0,local_964 + 9);
    }
    local_8 = Pic_Load_0044ef70(local_8bc,local_14);
    LoadPalNoPic(s_advfac64_pic_005276f8);
    if (local_8 == 1) {
      local_964[7] = 0xca;
      local_964[6] = 0x8c;
      local_964[8] = 0x118;
      Duel_ResetCardAnimationState((&DAT_0052262a)[(int)local_14 * 0x44],(byte)arg2);
      FUN_0040b3c2(2,(uint)local_14 | 0x80);
      Adventure_Map_UpdateLightingAndPalette(2,DAT_006b2d64 << 0x10 | (uint)local_14);
      if (-(int)local_14 == DAT_0067f2c0) {
        DAT_0067f2c0 = DAT_0067f2c0 + -100;
      }
      if ((char)(&DAT_0052262a)[(int)local_14 * 0x44] < '\v') {
        local_830 = FUN_0050b00c();
        local_874 = local_880;
        local_8c4 = 0;
        do {
          do {
            do {
              uVar13 = 1;
              bVar2 = FUN_0040a1d2(6);
              local_8bc = Pic_Subsystem_00451d90(1 << (bVar2 & 0x1f),uVar13);
              iVar3 = Pic_Subsystem_004521a6
                                (1 << ((byte)arg2 & 0x1f),
                                 (int)(char)(&DAT_0051aebe)[local_8bc * 0x34],
                                 (-(uint)((local_8c4 & 1) == 0) & 2) + 1);
            } while (iVar3 == 0);
            iVar3 = Duel_UpdateCardMotionStep(local_8bc);
          } while (((iVar3 < 1) || (((&DAT_0051aed1)[local_8bc * 0x34] & 9) != 0)) ||
                  (iVar3 = FUN_00485005(local_8bc), iVar3 == 0));
          if (((int)local_8c4 < 3) && ((&DAT_006b2dd0)[local_8c4] != -1)) {
            local_8bc = (&DAT_006b2dd0)[local_8c4];
          }
          auStack_8b0[local_8c4] = local_8bc;
          local_8c4 = local_8c4 + 1;
          uVar13 = *(uint *)(&DAT_0051aed0 + local_8bc * 0x34);
          iVar3 = Pic_Subsystem_00452551(local_8bc);
          local_874 = local_874 - (((uVar13 & 0x400) >> 10) + iVar3);
        } while (0 < (int)local_874);
        Adventure_Audio_PlayDuelIntro(1);
        Mem_AllocOrFree_00510de0(1,s_winbak01_pic_00527708);
        Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                           (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
        local_8c0 = (int)(300 / (longlong)(int)(local_8c4 + 1));
        for (arg1 = 0; (int)arg1 < (int)local_8c4; arg1 = arg1 + 1) {
          iVar3 = Pic_Subsystem_00452551(auStack_8b0[arg1]);
          strcpy(&g_OverworldWorldState,(char *)(&DAT_0052b73c)[iVar3]);
          pcVar10 = &g_OverworldWorldState;
          iVar4 = 1;
          iVar3 = FUN_0040a1d2(10);
          FUN_0050b206(auStack_8b0[arg1],
                       (local_8c0 * arg1 + 0x6f) - (int)((local_8c4 - 1) * local_8c0) / 2,
                       iVar3 + 0x10,iVar4,pcVar10);
        }
        if (local_830 == -1) {
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 5;
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xff,0x140,0x15e);
          Ai_Subsystem_004cd1d1();
          for (arg1 = 0; (int)arg1 < (int)local_8c4; arg1 = arg1 + 1) {
            local_878 = (LPVOID)Pic_Subsystem_00451e40(auStack_8b0[arg1]);
            if (local_878 != (LPVOID)0xffffffff) {
              *(uint *)(&deck + (int)local_878 * 4) = *(uint *)(&deck + (int)local_878 * 4) | 0x4000
              ;
            }
          }
        }
        else {
          local_868 = 0xcb;
          Mem_AllocOrFree_00510e20(1,s_endplak_pic_00527718);
          iVar3 = Ai_Util_004c3bc4(0x36);
          iVar4 = Ai_Util_004c3bc4(0x128);
          iVar5 = Ai_Util_004c3bc4(0x195);
          iVar6 = Ai_Util_004c3bc4(0x34);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x128,0x36,
                             (int *)g_DisplaySurfaceScreen,iVar6,iVar5,iVar4,iVar3);
          g_OverworldWorldState = 0;
          FUN_0048e2b0(local_830);
          FUN_0040c336(&g_OverworldWorldState,100,local_868 + 3,0xca);
          local_868 = local_868 + 9;
          g_OverworldWorldState = 0;
          for (local_874 = 0; (int)local_874 < 3; local_874 = local_874 + 1) {
            if (*(int *)(&DAT_0067eff0 + local_874 * 4 + local_830 * 0x30) != -1) {
              if (local_874 != 0) {
                strcat(&g_OverworldWorldState,&DAT_00527724);
              }
              strcat(&g_OverworldWorldState,
                     s_Swamp_0051aea9 +
                     *(int *)(&DAT_0067eff0 + local_874 * 4 + local_830 * 0x30) * 0x34);
            }
          }
          FUN_0040c2e9(&g_OverworldWorldState,100,local_868,0xca);
          local_868 = local_868 + 7;
          local_878 = (LPVOID)0x0;
          for (local_874 = 0; (int)local_874 < 4; local_874 = local_874 + 1) {
            if ((*(uint *)(&DAT_0067f010 + local_830 * 0x30) & 1 << ((byte)local_874 & 0x1f)) != 0)
            {
              local_878 = (LPVOID)((int)local_878 + 1);
            }
          }
          if (local_878 == (LPVOID)0x0) {
            strcpy(&g_OverworldWorldState,s__first_clue__00527728);
          }
          else if (local_878 == (LPVOID)0x1) {
            strcpy(&g_OverworldWorldState,s__second_clue__00527738);
          }
          else if (local_878 == (LPVOID)0x2) {
            strcpy(&g_OverworldWorldState,s__third_clue__00527748);
          }
          FUN_0040c2e9(&g_OverworldWorldState,100,local_868,200);
          strcpy(&g_OverworldWorldState,s_You_have_defeated_the_slimy_00527758);
          Adventure_FormatNewsString((int)local_14,0,0);
          strcat(&g_OverworldWorldState,s___Will_you____Take_the_cards__Ta_00527778);
          FUN_0050afbd();
          iVar3 = FUN_004896be(&g_OverworldWorldState,0x40,0x7c);
          if (iVar3 == 0) {
            if (local_830 != -1) {
              *(uint *)(&DAT_0067f014 + local_830 * 0x30) =
                   *(uint *)(&DAT_0067f014 + local_830 * 0x30) | 0x200;
            }
            for (arg1 = 0; (int)arg1 < (int)local_8c4; arg1 = arg1 + 1) {
              local_878 = (LPVOID)Pic_Subsystem_00451e40(auStack_8b0[arg1]);
              if (local_878 != (LPVOID)0xffffffff) {
                *(uint *)(&deck + (int)local_878 * 4) =
                     *(uint *)(&deck + (int)local_878 * 4) | 0x4000;
              }
            }
          }
          else {
            FUN_0048ea81(local_830);
          }
        }
        FUN_0040a3e1();
        local_10 = *(uint *)(&DAT_0052263c + (int)local_14 * 0x44);
        if (local_8b8 == 0) {
          local_10 = 0;
        }
        iVar3 = FUN_0040a1d2(0x28);
        if (iVar3 < (int)local_880) {
          local_964[1] = 2;
          local_964[2] = 1;
          local_964[3] = 4;
          local_964[4] = 3;
          local_964[5] = 0;
          *(int *)(&DAT_0067bdbc + arg2 * 4) = *(int *)(&DAT_0067bdbc + arg2 * 4) + 1;
          Mem_AllocOrFree_00510e20(1,s_winbak02_pic_005277c4);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                             (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
          FUN_0040a3e1();
          strcpy(&g_OverworldWorldState,s_Won_this_Amulet__005277d4);
          local_964[0] = FUN_0050f440((int *)g_DisplaySurfaceScreen,&g_OverworldWorldState);
          iVar7 = 0;
          iVar3 = Ai_Util_004c3bc4(0x30);
          iVar3 = iVar3 + 0xe;
          iVar4 = local_964[0] + 0x10;
          iVar5 = Ai_Util_004c3bc4(0xa0);
          iVar6 = Ai_Util_004c3bc4(0xa0);
          FUN_0048a3cc((iVar6 - local_964[0] / 2) + -8,iVar5,iVar4,iVar3,iVar7);
          iVar3 = Ai_Util_004c3bc4(0xae);
          iVar4 = Ai_Util_004c3bc4(0xa0);
          FUN_0040d269((int)g_DisplaySurfaceScreen,0xff,iVar4,iVar3);
          iVar3 = (&DAT_006776a0)[local_964[arg2]];
          iVar4 = Ai_Util_004c3bc4(0x22);
          iVar5 = Ai_Util_004c3bc4(0x1a);
          iVar6 = Ai_Util_004c3bc4(0xbd);
          iVar7 = Ai_Util_004c3bc4(0xa0);
          iVar8 = Ai_Util_004c3bc4(0xd);
          Sprite_DrawScaled((int *)g_DisplaySurfaceScreen,iVar7 - iVar8,iVar6,iVar5,iVar4,iVar3);
          if (local_10 == 0) {
            FUN_0040a3e1();
            Ai_Subsystem_004cd1d1();
          }
        }
        else if ((local_10 == 0) && (local_8b8 != 0)) {
          bVar2 = FUN_0040a1d2(0xc);
          local_10 = 1 << (bVar2 & 0x1f) & 0x1a19;
        }
        if (local_10 != 0) {
          Adventure_Audio_PlayEffect(s_x_sound_treasure_wav_0052783c,0xf,100,100,0);
          Mem_AllocOrFree_00510e20(1,s_winbak02_pic_00527854);
          Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                             (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
          iVar6 = 0;
          iVar5 = 1;
          iVar3 = Ai_Util_004c3bc4(0x23);
          iVar4 = Ai_Util_004c3bc4(local_964[6]);
          Pic_Load_advfac64_00489188(local_14,iVar4,iVar3,iVar5,iVar6);
          *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
          g_OverworldWorldState = 0;
          strcpy(&g_OverworldWorldState,s_You_are_00527864);
          strcat(&g_OverworldWorldState,(&PTR_s_an_Adequate_Apprentice_00527100)[DAT_0067f380]);
          strcat(&g_OverworldWorldState,&DAT_00527870);
          strcat(&g_OverworldWorldState,s_says_the_00527874);
          Adventure_FormatNewsString((int)local_14,0,0);
          strcat(&g_OverworldWorldState,&DAT_00527880);
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          local_964[8] = local_964[8] + 0x28;
          strcpy(&g_OverworldWorldState,s_You_get_00527884);
        }
        if (((local_10 & 1) != 0) && (g_PlayerCreatureCount != DAT_00627868)) {
          DAT_00627a7c = g_PlayerCreatureCount - DAT_00627868;
          strcat(&g_OverworldWorldState,s_your_lives___00527890);
          pcVar10 = _itoa(g_PlayerCreatureCount,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s___carried_over_to_the_next_duel__005278a0);
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 0x800) != 0) {
          iVar3 = FUN_0040a1d2(4);
          DAT_00522454 = (LPVOID)(iVar3 + 1);
          strcat(&g_OverworldWorldState,&DAT_005278c4);
          pcVar10 = _itoa((int)DAT_00522454,&DAT_00539d50,10);
          strcat(&g_OverworldWorldState,pcVar10);
          strcat(&g_OverworldWorldState,s_lives_in_next_duel__005278c8);
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 0x402) != 0) {
          do {
            local_844 = FUN_0040a1d2(0x40);
            local_868 = FUN_0040a1d2(0x40);
            iVar3 = FUN_0040c761(local_844,local_868);
          } while (iVar3 == 0);
          DAT_0052eff0 = local_844 * 0x20 + 0x10;
          DAT_0052eff4 = local_868 * 0x20 + 0x10;
          DAT_00641884 = 0;
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 4) != 0) {
          DAT_00522454 = (LPVOID)Pic_Subsystem_0045268f
                                           (*(int *)(&DAT_00522640 + (int)local_14 * 0x44));
          local_878 = (LPVOID)Pic_Subsystem_00451e40((uint)DAT_00522454);
          if (local_878 != (LPVOID)0xffffffff) {
            *(uint *)(&deck + (int)local_878 * 4) = *(uint *)(&deck + (int)local_878 * 4) | 0x4000;
          }
          strcpy(&g_OverworldWorldState,s_You_won_005278ec);
          Adventure_AppendNewsDetails((int)s_Swamp_0051aea9[(int)DAT_00522454 * 0x34],0);
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (int)DAT_00522454 * 0x34);
          FUN_0050b206((int)DAT_00522454,0xa0,0x70,1,&g_OverworldWorldState);
          DAT_00522454 = (LPVOID)0xffffffff;
        }
        if ((local_10 & 0x10) != 0) {
          DAT_00522454 = (LPVOID)0x0;
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 0x20) != 0) {
          DAT_00522454 = (LPVOID)Pic_Subsystem_0045268f
                                           (*(int *)(&DAT_00522640 + (int)local_14 * 0x44));
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (int)DAT_00522454 * 0x34);
          strcat(&g_OverworldWorldState,s_in_the_next_duel__00527920);
          FUN_0050b206((int)DAT_00522454,0xa0,0x70,1,&g_OverworldWorldState);
        }
        if ((local_10 & 0x180) != 0) {
          do {
            do {
              local_878 = (LPVOID)FUN_0040a1d2(g_MasterCardCount + -0x29);
            } while (((&g_MasterCardColorTable)[(int)local_878 * 0x34] & 0x42) != 0x40);
          } while (((int)local_878 < 5) || (iVar3 = FUN_00485005((int)local_878), iVar3 == 0));
          DAT_00522454 = local_878;
          Adventure_AppendNewsDetails((int)s_Swamp_0051aea9[(int)local_878 * 0x34],0);
          strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + (int)DAT_00522454 * 0x34);
          strcat(&g_OverworldWorldState,s_in_the_next_duel__00527934);
          FUN_0050b206((int)DAT_00522454,0xa0,0x70,1,&g_OverworldWorldState);
        }
        if ((local_10 & 0x200) != 0) {
          iVar3 = FUN_0040a1d2(0x1e);
          DAT_00522448 = DAT_00522448 + iVar3 + 0x14;
          strcat(&g_OverworldWorldState,s_Extra_FOOD__00527948);
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
        }
        if ((local_10 & 0x40) != 0) {
          strcat(&g_OverworldWorldState,s_any_card_of_your_choice__00527954);
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          Ai_Subsystem_004cd1d1();
          Adventure_ReloadWorldPalette(1);
          local_8bc = Palette_Color_0049716e(s_Pick_a_card_00527970,0,0xffffffff,1,0);
          while (local_8bc == 0xffffffff) {
            local_8bc = Palette_Color_0049716e(s_Pick_a_card_0052797c,0,0xffffffff,0,0);
          }
          if (local_8bc != 0xffffffff) {
            iVar3 = Pic_Subsystem_00451e40(local_8bc);
            *(uint *)(&deck + iVar3 * 4) = *(uint *)(&deck + iVar3 * 4) | 0x4000;
          }
          local_10 = 0;
        }
        if ((local_10 & 0x1000) != 0) {
          strcat(&g_OverworldWorldState,s_a_duplicate_card_of_your_choice__00527988);
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          Ai_Subsystem_004cd1d1();
          Adventure_ReloadWorldPalette(1);
          for (arg1 = 0; (int)arg1 < 500; arg1 = arg1 + 1) {
            local_82c[arg1] = *(uint *)(&deck + arg1 * 4);
            if (local_82c[arg1] != 0xffffffff) {
              local_82c[arg1] = local_82c[arg1] & 0xfff;
            }
          }
          local_8bc = Pic_Load_004509e8(g_CurrentTurnPhase,(int)local_82c,500,s_Pick_a_card_005279b0
                                        ,1);
          if (local_8bc != 0xffffffff) {
            iVar3 = Pic_Subsystem_00451e40(local_82c[local_8bc]);
            *(uint *)(&deck + iVar3 * 4) = *(uint *)(&deck + iVar3 * 4) | 0x4000;
          }
          local_10 = 0;
        }
        if ((local_10 & 8) != 0) {
          strcat(&g_OverworldWorldState,s_Extra_GOLD__005279bc);
          FUN_0040d4d1((int)g_DisplaySurfaceScreen,local_964[7],local_964[6],local_964[8]);
          Gold = Gold + 100;
        }
        FUN_0040a3e1();
        if (local_10 != 0) {
          Ai_Subsystem_004cd1d1();
        }
        iVar3 = FUN_0040a1d2((int)(0x40 / (longlong)(DAT_0067f380 + 1)));
        if (iVar3 < (int)local_880) {
          *(LPVOID *)(&DAT_006a48f0 + arg2 * 4) = DAT_0052f000;
        }
        iVar3 = FUN_0040a1d2((int)(0x80 / (longlong)(DAT_0067f380 + 1)));
        if (iVar3 < (int)local_880) {
          *(int *)(&DAT_006a4908 + arg2 * 4) = DAT_00626804;
        }
      }
    }
    if (local_8 == 0) {
      Adventure_Audio_PlayDuelIntro(2);
      Mem_AllocOrFree_00510e20(1,s_losedul2_pic_005279c8);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
      FUN_0040b3c2(2,local_14);
      for (local_884 = 0; local_884 < 3; local_884 = local_884 + 1) {
        FUN_0040a305((Gold / 0x28) * 10,0,100);
        local_878 = (LPVOID)0x0;
        local_87c = (&DAT_006b2d90)[local_884];
        if (local_87c != 0xffffffff) {
          strcpy(&g_OverworldWorldState,s_Lost_this_card_005279d8);
          if (local_878 != (LPVOID)0x0) {
            strcat(&g_OverworldWorldState,s_and_005279e8);
            pcVar10 = _itoa((int)local_878,&DAT_00539d50,10);
            strcat(&g_OverworldWorldState,pcVar10);
            strcat(&g_OverworldWorldState,s_gold__005279f0);
          }
          FUN_0050b206(local_87c,0x17,0x50,1,&g_OverworldWorldState);
          FUN_0040a3e1();
          Ai_Subsystem_004cd1d1();
          FUN_00489630(local_87c);
        }
      }
    }
    if (local_8 == -1) {
      Mem_AllocOrFree_00510e20(1,s_losedul2_pic_005279f8);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
      iVar5 = 0;
      iVar4 = 1;
      iVar3 = Ai_Util_004c3bc4(0x3c);
      Pic_Load_advfac64_00489188
                (local_14,(int)(DAT_00522458 + (DAT_00522458 >> 0x1f & 3U)) >> 2,iVar3,iVar4,iVar5);
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
      strcpy(&g_OverworldWorldState,s_The_people_are_disappointed_you_c_00527a08);
      Adventure_FormatNewsString((int)local_14,0,0);
      iVar3 = Ai_Util_004c3bc4(300);
      FUN_0040d201((int)g_DisplaySurfaceScreen,0xca,
                   (int)(DAT_00522458 + (DAT_00522458 >> 0x1f & 3U)) >> 2,iVar3);
      iVar3 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
      iVar3 = Ai_Util_004c3bc4(iVar3 * 4 + 300);
      FUN_0040d201((int)g_DisplaySurfaceScreen,0xca,
                   (int)(DAT_00522458 + (DAT_00522458 >> 0x1f & 3U)) >> 2,iVar3);
      FUN_0040a3e1();
      Ai_Subsystem_004cd1d1();
    }
  }
LAB_00488f4b:
  FUN_0046f21e(s_dbox_spr_00527a78,0x71,0xe3);
  SelectPalette(_hdcScreen,DAT_00626834,0);
  LoadPalNoPic(s_advfac64_pic_00527a84);
  FUN_0040a3e1();
  return local_8;
LAB_00486fd1:
  do {
    do {
      local_878 = (LPVOID)FUN_0040a1d2(500);
    } while (*(int *)(&deck + (int)local_878 * 4) == -1);
  } while ((((&DAT_00702151)[(int)local_878 * 4] & 0x40) != 0) ||
          ((*(uint *)(&deck + (int)local_878 * 4) & 0xfff) < 5));
  DAT_006b2d90 = *(uint *)(&deck + (int)local_878 * 4) & 0xfff;
  local_86c = 1;
  local_850 = 0;
  goto LAB_0048627e;
}


