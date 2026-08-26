/*
 * Decompiled function: FUN_1001c5f1
 * Entry Point: 1001c5f1
 * Size: 736 bytes
 */
#include "deckdll.h"


uint32_t FUN_1001c5f1(HDC hdc,int arg_2,int arg_3,LONG arg_4,char *str_5)

{
  uint32_t uval_1;
  HFONT pHVar2;
  size_t len_3;
  int val_4;
  int32_t *puVar5;
  LOGFONTA local_d4;
  int local_98;
  int local_94;
  HFONT local_90;
  tagTEXTMETRICA local_8c;
  int local_54;
  UINT local_50;
  int32_t local_4c;
  int32_t local_48;
  int32_t local_44;
  int32_t local_40;
  int32_t local_3c;
  uint8_t local_38;
  uint8_t local_37;
  uint8_t local_36;
  uint8_t local_35;
  uint8_t local_34;
  uint8_t local_33;
  uint8_t local_32;
  uint8_t local_31;
  uint8_t local_30;
  int32_t local_2f;
  _ABC local_10;
  
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 400;
  local_38 = 0;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0;
  local_32 = 0;
  local_31 = 0;
  local_30 = 0;
  puVar5 = &local_2f;
  for (val_4 = 7; val_4 != 0; val_4 = val_4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(int16_t *)puVar5 = 0;
  *(uint8_t *)((int)puVar5 + 2) = 0;
  if ((hdc == (HDC)0x0) || (str_5 == (char *)0x0)) {
    uval_1 = 0;
  }
  else {
    local_94 = SaveDC(hdc);
    memcpy(&local_d4,&local_4c,0x3c);
    local_d4.lfHeight = arg_4;
    strcpy(local_d4.lfFaceName,s_REGULAR_1004373c);
    local_90 = CreateFontIndirectA(&local_d4);
    if (local_90 == (HFONT)0x0) {
      local_90 = GetStockObject(0xd);
    }
    SelectObject(hdc,local_90);
    GetTextMetricsA(hdc,&local_8c);
    local_54 = local_8c.tmHeight;
    local_98 = local_8c.tmHeight;
    local_50 = GetTextAlign(hdc);
    if (((uint8_t)local_50 & 0x18) == 0x18) {
      arg_3 = arg_3 - local_8c.tmAscent;
    }
    else if ((local_50 & 8) != 0) {
      arg_3 = arg_3 - local_8c.tmHeight;
    }
    if (((uint8_t)local_50 & 6) == 6) {
      val_4 = thunk_FUN_1001c315(hdc,str_5);
      arg_2 = arg_2 - val_4 / 2;
    }
    else if ((local_50 & 2) != 0) {
      val_4 = thunk_FUN_1001c315(hdc,str_5);
      arg_2 = arg_2 - val_4;
    }
    SetTextAlign(hdc,0);
    for (; *str_5 != '\0'; str_5 = str_5 + 1) {
      if ((*str_5 < -0x12) || ((uint32_t)(int)*str_5 < 0x80000000)) {
        GetCharABCWidthsA(hdc,(int)*str_5,(int)*str_5,&local_10);
        TextOutA(hdc,arg_2,arg_3,str_5,1);
        arg_2 = local_10.abcC + local_10.abcB + arg_2 + local_10.abcA;
      }
      else {
        thunk_FUN_1001c8d1(hdc,*str_5,arg_2,arg_3,local_98,local_54);
        arg_2 = arg_2 + local_98;
      }
    }
    SetTextAlign(hdc,local_50);
    RestoreDC(hdc,local_94);
    pHVar2 = GetStockObject(0xd);
    if (pHVar2 != local_90) {
      DeleteObject(local_90);
    }
    len_3 = strlen(str_5);
    uval_1 = len_3 * local_98 & 0xffff | local_54 << 0x10;
  }
  return uval_1;
}


