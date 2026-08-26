/*
 * Decompiled function: Palette_Color_0049ae00
 * Entry Point: 0049ae00
 * Size: 2805 bytes
 */
#include "magic.h"


undefined4 Palette_Color_0049ae00(void)

{
  int iVar1;
  LOGFONTA *pLVar2;
  HPEN pHVar3;
  undefined4 uVar4;
  char local_118 [264];
  int local_10;
  int local_c;
  int local_8;
  
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Magim____TTF_0052bc2c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Magis____TTF_0052bc3c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0127m__TTF_0052bc4c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0085m__TTF_0052bc5c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0298m__TTF_0052bc6c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0299m__TTF_0052bc7c);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_006807a0);
  strcat(local_118,s__Tt0300m__TTF_0052bc8c);
  AddFontResourceA(local_118);
  DAT_0052a1b8 = 3;
  sprintf(local_118,s__s_Damage_pic_0052bc9c,&DAT_006808d0);
  DAT_0054b9a0 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_CardCounters_pic_0052bcac,&DAT_006808d0);
  DAT_0054b734 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_ManaSymbols_pic_0052bcc0,&DAT_006808d0);
  DAT_0054b9ac = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_CardSets_pic_0052bcd4,&DAT_006808d0);
  DAT_0054b580 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_Abilities_pic_0052bce4,&DAT_006808d0);
  DAT_0054b960 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_ManaStripes_pic_0052bcf8,&DAT_006808d0);
  DAT_0054b59c = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_Summon_pic_0052bd0c,&DAT_006808d0);
  DAT_0054b740 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_Dying_pic_0052bd1c,&DAT_006808d0);
  DAT_0054b3cc = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_Target_pic_0052bd2c,&DAT_006808d0);
  DAT_0054b598 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_CantTarget_pic_0052bd3c,&DAT_006808d0);
  DAT_0054b98c = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_WillUntap_pic_0052bd50,&DAT_006808d0);
  DAT_0054b3d8 = Pic_Load_00423833(local_118);
  sprintf(local_118,s__s_CardBack_pic_0052bd64,&DAT_006808d0);
  DAT_0054b920 = Pic_Load_00423833(local_118);
  Pic_Subsystem_00424500(s_prompts_txt_0052bd80,s_COLORWORDS_0052bd74);
  local_10 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x649f70),&g_OverworldGoldAmount + iVar1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x64a030),&g_OverworldGoldAmount + iVar1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy(&DAT_00649f30 + local_c * 10,&g_OverworldGoldAmount + iVar1);
  }
  Pic_Subsystem_00424500(s_prompts_txt_0052bd98,s_LANDWORDS_0052bd8c);
  local_10 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x649ff0),&g_OverworldGoldAmount + iVar1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x649fb0),&g_OverworldGoldAmount + iVar1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy(&DAT_0064a070 + local_c * 10,&g_OverworldGoldAmount + iVar1);
  }
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardTitle_0052bda4,0);
  DAT_0054b8e4 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardSubtitle_0052bdb4,0);
  DAT_0054b3d4 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardPT_0052bdc4,0);
  DAT_0054b730 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardText_0052bdd0,0);
  DAT_0054b73c = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_BigCardText_0052bddc,1);
  DAT_0054b994 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_SmallCardTitle_0052bde8,0);
  DAT_0054b95c = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_SmallCardPT_0052bdf8,0);
  DAT_0054b58c = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_Damage_0052be04,0);
  DAT_0054b380 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_004f58eb(s_IDTag_0052be0c,0);
  DAT_0054b744 = CreateFontIndirectA(pLVar2);
  DAT_0054b738 = FUN_004f5cbc(0xbe);
  DAT_0054b978 = FUN_004f5cbc(0xca);
  DAT_0054b588 = FUN_004f5cbc(0xc9);
  DAT_0054b57c = FUN_004f5cbc(0xbf);
  DAT_0054b9a8 = FUN_004f5cbc(0xd8);
  DAT_0054b9e4 = FUN_004f5cbc(0x31);
  DAT_0054b9a4 = FUN_004f5cbc(0x9e);
  DAT_0054b570 = FUN_004f5cbc(0x9e);
  DAT_0054b37c = FUN_004f5cbc(0x7c);
  DAT_0054b574 = FUN_004f5cbc(0x2f);
  DAT_0054b578 = FUN_004f5cbc(0xbf);
  DAT_0054b3d0 = FUN_004f5cbc(0x5d);
  DAT_0054b980 = FUN_004f5cbc(0x1f);
  DAT_0054b9ec = FUN_004f5cbc(0xc9);
  DAT_0054b8e0 = FUN_004f5cbc(0xc4);
  DAT_0054b9f0 = FUN_004f5cbc(0xc4);
  DAT_0054b964 = CreatePen(0,0,DAT_0054b9f0);
  DAT_0054b970 = CreatePen(6,2,DAT_0054b3d0);
  DAT_0054b9e8 = CreatePen(6,2,DAT_0054b980);
  local_8 = 1;
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    pHVar3 = CreatePen(6,3,(local_c * 0x14 & 0xffU) << 8 | (uint)(byte)((char)local_c * '\n') |
                           (uint)(byte)((char)local_c * 'K') << 0x10);
    *(HPEN *)(&DAT_0054b8f8 + local_c * 4) = pHVar3;
    if (*(int *)(&DAT_0054b8f8 + local_c * 4) == 0) {
      local_8 = 0;
    }
  }
  DAT_0054b97c = CreateSolidBrush(DAT_0054b738);
  DAT_0054b988 = CreateSolidBrush(DAT_0054b978);
  DAT_0054b96c = 0;
  DAT_0054b594 = 0;
  DAT_0054b990 = 0;
  DAT_0054b99c = 0;
  DAT_0054b984 = 0;
  DAT_0054b3c4 = 0;
  DAT_0054b384 = 0;
  DAT_0054b974 = 0;
  DAT_0054b378 = 0;
  DAT_0054b998 = 0;
  DAT_0054b388 = 0;
  DAT_0054b924 = 0;
  DAT_0054b8f4 = 0;
  DAT_0054b584 = 0;
  DAT_0054b748 = 0;
  DAT_0054b590 = 0;
  DAT_0054b3c8 = 0;
  DAT_0054b968 = 0;
  if (((((((((DAT_0054b9a0 == 0) || (DAT_0054b734 == 0)) || (DAT_0054b9ac == 0)) ||
          ((DAT_0054b580 == 0 || (DAT_0054b960 == 0)))) || (DAT_0054b59c == 0)) ||
        (((DAT_0054b740 == 0 || (DAT_0054b3cc == 0)) ||
         ((DAT_0054b598 == 0 ||
          (((DAT_0054b98c == 0 || (DAT_0054b3d8 == 0)) || (DAT_0054b920 == 0)))))))) ||
       ((DAT_0054b8e4 == (HFONT)0x0 || (DAT_0054b3d4 == (HFONT)0x0)))) ||
      (((DAT_0054b73c == (HFONT)0x0 ||
        (((DAT_0054b994 == (HFONT)0x0 || (DAT_0054b95c == (HFONT)0x0)) ||
         ((DAT_0054b58c == (HFONT)0x0 ||
          (((DAT_0054b380 == (HFONT)0x0 || (DAT_0054b744 == (HFONT)0x0)) ||
           (DAT_0054b964 == (HPEN)0x0)))))))) ||
       (((DAT_0054b970 == (HPEN)0x0 || (DAT_0054b9e8 == (HPEN)0x0)) || (local_8 == 0)))))) ||
     ((DAT_0054b97c == (HBRUSH)0x0 || (DAT_0054b988 == (HBRUSH)0x0)))) {
    Palette_Subsystem_0049b8f5();
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


