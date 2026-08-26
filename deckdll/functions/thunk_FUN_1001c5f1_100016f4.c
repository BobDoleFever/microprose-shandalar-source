/*
 * Decompiled function: thunk_FUN_1001c5f1
 * Entry Point: 100016f4
 * Size: 5 bytes
 */
#include "deckdll.h"


uint32_t thunk_FUN_1001c5f1(HDC hdc,int arg_2,int arg_3,LONG arg_4,char *str_5)

{
  uint32_t uval_1;
  HFONT pHVar2;
  size_t len_3;
  int val_4;
  int32_t *puVar5;
  LOGFONTA LStack_d4;
  int iStack_98;
  int iStack_94;
  HFONT pHStack_90;
  tagTEXTMETRICA tStack_8c;
  int iStack_54;
  UINT UStack_50;
  int32_t uStack_4c;
  int32_t uStack_48;
  int32_t uStack_44;
  int32_t uStack_40;
  int32_t uStack_3c;
  uint8_t uStack_38;
  uint8_t uStack_37;
  uint8_t uStack_36;
  uint8_t uStack_35;
  uint8_t uStack_34;
  uint8_t uStack_33;
  uint8_t uStack_32;
  uint8_t uStack_31;
  uint8_t uStack_30;
  int32_t uStack_2f;
  _ABC _Stack_10;
  
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 400;
  uStack_38 = 0;
  uStack_37 = 0;
  uStack_36 = 0;
  uStack_35 = 0;
  uStack_34 = 0;
  uStack_33 = 0;
  uStack_32 = 0;
  uStack_31 = 0;
  uStack_30 = 0;
  puVar5 = &uStack_2f;
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
    iStack_94 = SaveDC(hdc);
    memcpy(&LStack_d4,&uStack_4c,0x3c);
    LStack_d4.lfHeight = arg_4;
    strcpy(LStack_d4.lfFaceName,s_REGULAR_1004373c);
    pHStack_90 = CreateFontIndirectA(&LStack_d4);
    if (pHStack_90 == (HFONT)0x0) {
      pHStack_90 = GetStockObject(0xd);
    }
    SelectObject(hdc,pHStack_90);
    GetTextMetricsA(hdc,&tStack_8c);
    iStack_54 = tStack_8c.tmHeight;
    iStack_98 = tStack_8c.tmHeight;
    UStack_50 = GetTextAlign(hdc);
    if (((uint8_t)UStack_50 & 0x18) == 0x18) {
      arg_3 = arg_3 - tStack_8c.tmAscent;
    }
    else if ((UStack_50 & 8) != 0) {
      arg_3 = arg_3 - tStack_8c.tmHeight;
    }
    if (((uint8_t)UStack_50 & 6) == 6) {
      val_4 = thunk_FUN_1001c315(hdc,str_5);
      arg_2 = arg_2 - val_4 / 2;
    }
    else if ((UStack_50 & 2) != 0) {
      val_4 = thunk_FUN_1001c315(hdc,str_5);
      arg_2 = arg_2 - val_4;
    }
    SetTextAlign(hdc,0);
    for (; *str_5 != '\0'; str_5 = str_5 + 1) {
      if ((*str_5 < -0x12) || ((uint32_t)(int)*str_5 < 0x80000000)) {
        GetCharABCWidthsA(hdc,(int)*str_5,(int)*str_5,&_Stack_10);
        TextOutA(hdc,arg_2,arg_3,str_5,1);
        arg_2 = _Stack_10.abcC + _Stack_10.abcB + arg_2 + _Stack_10.abcA;
      }
      else {
        thunk_FUN_1001c8d1(hdc,*str_5,arg_2,arg_3,iStack_98,iStack_54);
        arg_2 = arg_2 + iStack_98;
      }
    }
    SetTextAlign(hdc,UStack_50);
    RestoreDC(hdc,iStack_94);
    pHVar2 = GetStockObject(0xd);
    if (pHVar2 != pHStack_90) {
      DeleteObject(pHStack_90);
    }
    len_3 = strlen(str_5);
    uval_1 = len_3 * iStack_98 & 0xffff | iStack_54 << 0x10;
  }
  return uval_1;
}


