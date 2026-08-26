/*
 * Decompiled function: FUN_10019440
 * Entry Point: 10019440
 * Size: 2805 bytes
 */
#include "deckdll.h"


int32_t FUN_10019440(void)

{
  int val_1;
  LOGFONTA *pLVar2;
  HPEN pHVar3;
  int32_t uval_4;
  char local_118 [264];
  int local_10;
  int local_c;
  int local_8;
  
  strcpy(local_118,&DAT_10158770);
  strcat(local_118,s__Magim____TTF_10043314);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_10158770);
  strcat(local_118,s__Magis____TTF_10043324);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_10158770);
  strcat(local_118,s__Tt0127m__TTF_10043334);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_10158770);
  strcat(local_118,s__Tt0085m__TTF_10043344);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_10158770);
  strcat(local_118,s__Tt0298m__TTF_10043354);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_10158770);
  strcat(local_118,s__Tt0299m__TTF_10043364);
  AddFontResourceA(local_118);
  strcpy(local_118,&DAT_10158770);
  strcat(local_118,s__Tt0300m__TTF_10043374);
  AddFontResourceA(local_118);
  DAT_10041580 = 3;
  sprintf(local_118,s__s_Damage_pic_10043384,&DAT_10158890);
  DAT_1013e610 = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_CardCounters_pic_10043394,&DAT_10158890);
  DAT_1013e3a4 = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_ManaSymbols_pic_100433a8,&DAT_10158890);
  DAT_1013e61c = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_CardSets_pic_100433bc,&DAT_10158890);
  DAT_1013e1f0 = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_Abilities_pic_100433cc,&DAT_10158890);
  DAT_1013e5d0 = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_ManaStripes_pic_100433e0,&DAT_10158890);
  DAT_1013e20c = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_Summon_pic_100433f4,&DAT_10158890);
  DAT_1013e3b0 = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_Dying_pic_10043404,&DAT_10158890);
  DAT_1013e03c = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_Target_pic_10043414,&DAT_10158890);
  DAT_1013e208 = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_CantTarget_pic_10043424,&DAT_10158890);
  DAT_1013e5fc = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_WillUntap_pic_10043438,&DAT_10158890);
  DAT_1013e048 = thunk_FUN_1003afa3(local_118);
  sprintf(local_118,s__s_CardBack_pic_1004344c,&DAT_10158890);
  DAT_1013e590 = thunk_FUN_1003afa3(local_118);
  thunk_FUN_10034b40(s_prompts_txt_10043468,s_COLORWORDS_1004345c);
  local_10 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    val_1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x10140850),&DAT_1016e4c0 + val_1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    val_1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x10140910),&DAT_1016e4c0 + val_1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    val_1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x101407c0),&DAT_1016e4c0 + val_1);
  }
  thunk_FUN_10034b40(s_prompts_txt_10043480,s_LANDWORDS_10043474);
  local_10 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    val_1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x101408d0),&DAT_1016e4c0 + val_1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    val_1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x10140890),&DAT_1016e4c0 + val_1);
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    val_1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    strcpy((char *)(local_c * 10 + 0x10140950),&DAT_1016e4c0 + val_1);
  }
  pLVar2 = (LOGFONTA *)thunk_FUN_100333bb(s_BigCardTitle_1004348c,0);
  DAT_1013e554 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)thunk_FUN_100333bb(s_BigCardSubtitle_1004349c,0);
  DAT_1013e044 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)thunk_FUN_100333bb(s_BigCardPT_100434ac,0);
  DAT_1013e3a0 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)thunk_FUN_100333bb(s_BigCardText_100434b8,0);
  DAT_1013e3ac = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)thunk_FUN_100333bb(s_BigCardText_100434c4,1);
  DAT_1013e604 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)thunk_FUN_100333bb(s_SmallCardTitle_100434d0,0);
  DAT_1013e5cc = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)thunk_FUN_100333bb(s_SmallCardPT_100434e0,0);
  DAT_1013e1fc = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)thunk_FUN_100333bb(s_Damage_100434ec,0);
  DAT_1013dff0 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)thunk_FUN_100333bb(s_IDTag_100434f4,0);
  DAT_1013e3b4 = CreateFontIndirectA(pLVar2);
  DAT_1013e3a8 = thunk_FUN_1003378c(0xbe);
  DAT_1013e5e8 = thunk_FUN_1003378c(0xca);
  DAT_1013e1f8 = thunk_FUN_1003378c(0xc9);
  DAT_1013e1ec = thunk_FUN_1003378c(0xbf);
  DAT_1013e618 = thunk_FUN_1003378c(0xd8);
  DAT_1013e654 = thunk_FUN_1003378c(0x31);
  DAT_1013e614 = thunk_FUN_1003378c(0x9e);
  DAT_1013e1e0 = thunk_FUN_1003378c(0x9e);
  DAT_1013dfec = thunk_FUN_1003378c(0x7c);
  DAT_1013e1e4 = thunk_FUN_1003378c(0x2f);
  DAT_1013e1e8 = thunk_FUN_1003378c(0xbf);
  DAT_1013e040 = thunk_FUN_1003378c(0x5d);
  DAT_1013e5f0 = thunk_FUN_1003378c(0x1f);
  DAT_1013e65c = thunk_FUN_1003378c(0xc9);
  DAT_1013e550 = thunk_FUN_1003378c(0xc4);
  DAT_1013e660 = thunk_FUN_1003378c(0xc4);
  DAT_1013e5d4 = CreatePen(0,0,DAT_1013e660);
  DAT_1013e5e0 = CreatePen(6,2,DAT_1013e040);
  DAT_1013e658 = CreatePen(6,2,DAT_1013e5f0);
  local_8 = 1;
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    pHVar3 = CreatePen(6,3,(local_c * 0x14 & 0xffU) << 8 | (uint32_t)(uint8_t)((char)local_c * '\n') |
                           (uint32_t)(uint8_t)((char)local_c * 'K') << 0x10);
    *(HPEN *)(&DAT_1013e568 + local_c * 4) = pHVar3;
    if (*(int *)(&DAT_1013e568 + local_c * 4) == 0) {
      local_8 = 0;
    }
  }
  DAT_1013e5ec = CreateSolidBrush(DAT_1013e3a8);
  DAT_1013e5f8 = CreateSolidBrush(DAT_1013e5e8);
  DAT_1013e5dc = 0;
  DAT_1013e204 = 0;
  DAT_1013e600 = 0;
  DAT_1013e60c = 0;
  DAT_1013e5f4 = 0;
  DAT_1013e034 = 0;
  DAT_1013dff4 = 0;
  DAT_1013e5e4 = 0;
  DAT_1013dfe8 = 0;
  DAT_1013e608 = 0;
  DAT_1013dff8 = 0;
  DAT_1013e594 = 0;
  DAT_1013e564 = 0;
  DAT_1013e1f4 = 0;
  DAT_1013e3b8 = 0;
  DAT_1013e200 = 0;
  DAT_1013e038 = 0;
  DAT_1013e5d8 = 0;
  if (((((((((DAT_1013e610 == 0) || (DAT_1013e3a4 == 0)) || (DAT_1013e61c == 0)) ||
          ((DAT_1013e1f0 == 0 || (DAT_1013e5d0 == 0)))) || (DAT_1013e20c == 0)) ||
        (((DAT_1013e3b0 == 0 || (DAT_1013e03c == 0)) ||
         ((DAT_1013e208 == 0 ||
          (((DAT_1013e5fc == 0 || (DAT_1013e048 == 0)) || (DAT_1013e590 == 0)))))))) ||
       ((DAT_1013e554 == (HFONT)0x0 || (DAT_1013e044 == (HFONT)0x0)))) ||
      (((DAT_1013e3ac == (HFONT)0x0 ||
        (((DAT_1013e604 == (HFONT)0x0 || (DAT_1013e5cc == (HFONT)0x0)) ||
         ((DAT_1013e1fc == (HFONT)0x0 ||
          (((DAT_1013dff0 == (HFONT)0x0 || (DAT_1013e3b4 == (HFONT)0x0)) ||
           (DAT_1013e5d4 == (HPEN)0x0)))))))) ||
       (((DAT_1013e5e0 == (HPEN)0x0 || (DAT_1013e658 == (HPEN)0x0)) || (local_8 == 0)))))) ||
     ((DAT_1013e5ec == (HBRUSH)0x0 || (DAT_1013e5f8 == (HBRUSH)0x0)))) {
    thunk_FUN_10019f35();
    uval_4 = 0;
  }
  else {
    uval_4 = 1;
  }
  return uval_4;
}


