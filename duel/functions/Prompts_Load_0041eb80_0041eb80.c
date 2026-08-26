/*
 * Decompiled function: Prompts_Load_0041eb80
 * Entry Point: 0041eb80
 * Size: 2793 bytes
 */
#include "duel.h"


undefined4 Prompts_Load_0041eb80(void)

{
  int iVar1;
  LOGFONTA *pLVar2;
  HPEN pHVar3;
  undefined4 uVar4;
  uint local_118 [66];
  int local_10;
  int local_c;
  int local_8;
  
  Mem_AllocOrFree_004d9630(local_118,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint *)s__Magim____TTF_004f3040);
  AddFontResourceA((LPCSTR)local_118);
  Mem_AllocOrFree_004d9630(local_118,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint *)s__Magis____TTF_004f3050);
  AddFontResourceA((LPCSTR)local_118);
  Mem_AllocOrFree_004d9630(local_118,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint *)s__Tt0127m__TTF_004f3060);
  AddFontResourceA((LPCSTR)local_118);
  Mem_AllocOrFree_004d9630(local_118,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint *)s__Tt0085m__TTF_004f3070);
  AddFontResourceA((LPCSTR)local_118);
  Mem_AllocOrFree_004d9630(local_118,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint *)s__Tt0298m__TTF_004f3080);
  AddFontResourceA((LPCSTR)local_118);
  Mem_AllocOrFree_004d9630(local_118,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint *)s__Tt0299m__TTF_004f3090);
  AddFontResourceA((LPCSTR)local_118);
  Mem_AllocOrFree_004d9630(local_118,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_118,(uint *)s__Tt0300m__TTF_004f30a0);
  AddFontResourceA((LPCSTR)local_118);
  DAT_004f4628 = 3;
  _sprintf((char *)local_118,s__s_Damage_pic_004f30b0,&DAT_005f7800);
  DAT_0050b1f8 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_CardCounters_pic_004f30c0,&DAT_005f7800);
  DAT_0050af8c = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_ManaSymbols_pic_004f30d4,&DAT_005f7800);
  DAT_0050b204 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_CardSets_pic_004f30e8,&DAT_005f7800);
  DAT_0050add8 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_Abilities_pic_004f30f8,&DAT_005f7800);
  DAT_0050b1b8 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_ManaStripes_pic_004f310c,&DAT_005f7800);
  DAT_0050adf4 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_Summon_pic_004f3120,&DAT_005f7800);
  DAT_0050af98 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_Dying_pic_004f3130,&DAT_005f7800);
  DAT_0050ac24 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_Target_pic_004f3140,&DAT_005f7800);
  DAT_0050adf0 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_CantTarget_pic_004f3150,&DAT_005f7800);
  DAT_0050b1e4 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_WillUntap_pic_004f3164,&DAT_005f7800);
  DAT_0050ac30 = FUN_0043d713((char *)local_118);
  _sprintf((char *)local_118,s__s_CardBack_pic_004f3178,&DAT_005f7800);
  DAT_0050b178 = FUN_0043d713((char *)local_118);
  FUN_00434660(s_prompts_txt_004f3194,s_COLORWORDS_004f3188);
  local_10 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    Mem_AllocOrFree_004d9630((uint *)(local_c * 10 + 0x6c1260),(uint *)(&DAT_006679f0 + iVar1));
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    Mem_AllocOrFree_004d9630((uint *)(local_c * 10 + 0x6c1320),(uint *)(&DAT_006679f0 + iVar1));
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    Mem_AllocOrFree_004d9630((uint *)(&DAT_006c1220 + local_c * 10),(uint *)(&DAT_006679f0 + iVar1))
    ;
  }
  FUN_00434660(s_prompts_txt_004f31ac,s_LANDWORDS_004f31a0);
  local_10 = 0;
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    Mem_AllocOrFree_004d9630((uint *)(local_c * 10 + 0x6c12e0),(uint *)(&DAT_006679f0 + iVar1));
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    Mem_AllocOrFree_004d9630((uint *)(local_c * 10 + 0x6c12a0),(uint *)(&DAT_006679f0 + iVar1));
  }
  for (local_c = 1; local_c < 6; local_c = local_c + 1) {
    iVar1 = local_10 * 0xfa;
    local_10 = local_10 + 1;
    Mem_AllocOrFree_004d9630((uint *)(&DAT_006c1360 + local_c * 10),(uint *)(&DAT_006679f0 + iVar1))
    ;
  }
  pLVar2 = (LOGFONTA *)FUN_00472731(s_BigCardTitle_004f31b8,0);
  DAT_0050b13c = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_BigCardSubtitle_004f31c8,0);
  DAT_0050ac2c = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_BigCardPT_004f31d8,0);
  DAT_0050af88 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_BigCardText_004f31e4,0);
  DAT_0050af94 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_BigCardText_004f31f0,1);
  DAT_0050b1ec = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_SmallCardTitle_004f31fc,0);
  DAT_0050b1b4 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_SmallCardPT_004f320c,0);
  DAT_0050ade4 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_Damage_004f3218,0);
  DAT_0050abd8 = CreateFontIndirectA(pLVar2);
  pLVar2 = (LOGFONTA *)FUN_00472731(s_IDTag_004f3220,0);
  DAT_0050af9c = CreateFontIndirectA(pLVar2);
  DAT_0050af90 = FUN_00472b02(0xbe);
  DAT_0050b1d0 = FUN_00472b02(0xca);
  DAT_0050ade0 = FUN_00472b02(0xc9);
  DAT_0050add4 = FUN_00472b02(0xbf);
  DAT_0050b200 = FUN_00472b02(0xd8);
  DAT_0050b23c = FUN_00472b02(0x31);
  DAT_0050b1fc = FUN_00472b02(0x9e);
  DAT_0050adc8 = FUN_00472b02(0x9e);
  DAT_0050abd4 = FUN_00472b02(0x7c);
  DAT_0050adcc = FUN_00472b02(0x2f);
  DAT_0050add0 = FUN_00472b02(0xbf);
  DAT_0050ac28 = FUN_00472b02(0x5d);
  DAT_0050b1d8 = FUN_00472b02(0x1f);
  DAT_0050b244 = FUN_00472b02(0xc9);
  DAT_0050b138 = FUN_00472b02(0xc4);
  DAT_0050b248 = FUN_00472b02(0xc4);
  DAT_0050b1bc = CreatePen(0,0,DAT_0050b248);
  DAT_0050b1c8 = CreatePen(6,2,DAT_0050ac28);
  DAT_0050b240 = CreatePen(6,2,DAT_0050b1d8);
  local_8 = 1;
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    pHVar3 = CreatePen(6,3,(local_c * 0x14 & 0xffU) << 8 | (uint)(byte)((char)local_c * '\n') |
                           (uint)(byte)((char)local_c * 'K') << 0x10);
    *(HPEN *)(&DAT_0050b150 + local_c * 4) = pHVar3;
    if (*(int *)(&DAT_0050b150 + local_c * 4) == 0) {
      local_8 = 0;
    }
  }
  DAT_0050b1d4 = CreateSolidBrush(DAT_0050af90);
  DAT_0050b1e0 = CreateSolidBrush(DAT_0050b1d0);
  DAT_0050b1c4 = 0;
  DAT_0050adec = 0;
  DAT_0050b1e8 = 0;
  DAT_0050b1f4 = 0;
  DAT_0050b1dc = 0;
  DAT_0050ac1c = 0;
  DAT_0050abdc = 0;
  DAT_0050b1cc = 0;
  DAT_0050abd0 = 0;
  DAT_0050b1f0 = 0;
  DAT_0050abe0 = 0;
  DAT_0050b17c = 0;
  DAT_0050b14c = 0;
  DAT_0050addc = 0;
  DAT_0050afa0 = 0;
  DAT_0050ade8 = 0;
  DAT_0050ac20 = 0;
  DAT_0050b1c0 = 0;
  if (((((((((DAT_0050b1f8 == 0) || (DAT_0050af8c == 0)) || (DAT_0050b204 == 0)) ||
          ((DAT_0050add8 == 0 || (DAT_0050b1b8 == 0)))) || (DAT_0050adf4 == 0)) ||
        (((DAT_0050af98 == 0 || (DAT_0050ac24 == 0)) ||
         ((DAT_0050adf0 == 0 ||
          (((DAT_0050b1e4 == 0 || (DAT_0050ac30 == 0)) || (DAT_0050b178 == 0)))))))) ||
       ((DAT_0050b13c == (HFONT)0x0 || (DAT_0050ac2c == (HFONT)0x0)))) ||
      (((DAT_0050af94 == (HFONT)0x0 ||
        (((DAT_0050b1ec == (HFONT)0x0 || (DAT_0050b1b4 == (HFONT)0x0)) ||
         ((DAT_0050ade4 == (HFONT)0x0 ||
          (((DAT_0050abd8 == (HFONT)0x0 || (DAT_0050af9c == (HFONT)0x0)) ||
           (DAT_0050b1bc == (HPEN)0x0)))))))) ||
       (((DAT_0050b1c8 == (HPEN)0x0 || (DAT_0050b240 == (HPEN)0x0)) || (local_8 == 0)))))) ||
     ((DAT_0050b1d4 == (HBRUSH)0x0 || (DAT_0050b1e0 == (HBRUSH)0x0)))) {
    Font_LoadTTF_Magim_TTF_0041f669();
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


