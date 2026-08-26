/*
 * Decompiled function: thunk_FUN_1001cbfc
 * Entry Point: 100014e2
 * Size: 5 bytes
 */
#include "deckdll.h"


uint32_t thunk_FUN_1001cbfc(HDC hdc,int *y,char *str_3,int height)

{
  int val_1;
  char *char_ptr_2;
  uint32_t uval_3;
  int val_4;
  int val_5;
  HGDIOBJ pvVar6;
  size_t sVar7;
  char acStack_b0 [52];
  int iStack_7c;
  int iStack_78;
  size_t sStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  uint32_t uStack_64;
  int iStack_60;
  tagTEXTMETRICA tStack_5c;
  int iStack_24;
  tagRECT tStack_20;
  tagSIZE tStack_10;
  int iStack_8;
  
  if (((hdc == (HDC)0x0) || (y == (int *)0x0)) || (str_3 == (char *)0x0)) {
    uval_3 = 0;
  }
  else if (*str_3 == '\0') {
    uval_3 = 0;
  }
  else {
    iStack_70 = SaveDC(hdc);
    uStack_64 = 0;
    iStack_8 = 0;
    GetTextMetricsA(hdc,&tStack_5c);
    val_4 = tStack_5c.tmExternalLeading + tStack_5c.tmHeight;
    SetRect(&tStack_20,0,0,0,tStack_5c.tmHeight);
    LPtoDP(hdc,(LPPOINT)&tStack_20,2);
    SetRect(&tStack_20,0,0,tStack_20.bottom - tStack_20.top,0);
    DPtoLP(hdc,(LPPOINT)&tStack_20,2);
    iStack_7c = ((tStack_20.right - tStack_20.left) * 0x4b) / 100;
    val_5 = ((tStack_20.right - tStack_20.left) * 0x55) / 100;
    iStack_24 = (tStack_5c.tmHeight * 0x4b) / 100;
    iStack_78 = tStack_5c.tmHeight;
    IntersectClipRect(hdc,*y,y[1],y[2],y[3]);
    pvVar6 = GetStockObject(4);
    SelectObject(hdc,pvVar6);
    pvVar6 = GetStockObject(8);
    SelectObject(hdc,pvVar6);
    iStack_60 = *y;
    iStack_6c = y[1];
    while (*str_3 != '\0') {
      if (*str_3 == ' ') {
        iStack_68 = 0;
        acStack_b0[0] = *str_3;
        val_1 = iStack_68;
        while( true ) {
          iStack_68 = val_1 + 1;
          str_3 = str_3 + 1;
          if ((*str_3 == '\0') || (*str_3 != ' ')) break;
          acStack_b0[val_1 + 1] = *str_3;
          val_1 = iStack_68;
        }
        acStack_b0[val_1 + 1] = '\0';
        GetTextExtentPoint32A(hdc,acStack_b0,iStack_68,&tStack_10);
        if ((y[2] < tStack_10.cx + iStack_60) || (iStack_60 <= *y)) {
          uval_3 = iStack_60 - *y;
          if (iStack_60 - *y <= (int)uStack_64) {
            uval_3 = uStack_64;
          }
          iStack_6c = iStack_6c + val_4;
          iStack_60 = *y;
          uStack_64 = uval_3;
        }
        else {
          sVar7 = strlen(acStack_b0);
          TextOutA(hdc,iStack_60,iStack_6c,acStack_b0,sVar7);
          iStack_60 = iStack_60 + tStack_10.cx;
        }
      }
      else if ((*str_3 == '\0') || (*str_3 != '\n')) {
        if ((*str_3 < -0x12) || ((uint32_t)(int)*str_3 < 0x80000000)) {
          iStack_68 = 0;
          acStack_b0[0] = *str_3;
          val_1 = iStack_68;
          while( true ) {
            iStack_68 = val_1 + 1;
            str_3 = str_3 + 1;
            if (((*str_3 == '\0') || (*str_3 == ' ')) ||
               ((*str_3 == '\n' || ((-0x13 < *str_3 && (*str_3 < '\0')))))) break;
            acStack_b0[val_1 + 1] = *str_3;
            val_1 = iStack_68;
          }
          acStack_b0[val_1 + 1] = '\0';
          GetTextExtentPoint32A(hdc,acStack_b0,iStack_68,&tStack_10);
          if (y[2] < tStack_10.cx + iStack_60) {
            iStack_6c = iStack_6c + val_4;
            iStack_60 = *y;
          }
          sVar7 = strlen(acStack_b0);
          TextOutA(hdc,iStack_60,iStack_6c,acStack_b0,sVar7);
          iStack_60 = iStack_60 + tStack_10.cx;
        }
        else {
          iStack_68 = 0;
          acStack_b0[0] = *str_3;
          char_ptr_2 = str_3;
          val_1 = iStack_68;
          while( true ) {
            iStack_68 = val_1 + 1;
            str_3 = char_ptr_2 + 1;
            if (((*str_3 == '\0') || (*str_3 < -0x12)) || ((uint32_t)(int)*str_3 < 0x80000000)) break;
            acStack_b0[val_1 + 1] = *str_3;
            char_ptr_2 = str_3;
            val_1 = iStack_68;
          }
          acStack_b0[val_1 + 1] = '\0';
          tStack_10.cx = iStack_68 * iStack_7c;
          if (y[2] < tStack_10.cx + iStack_60) {
            iStack_6c = iStack_6c + val_4;
            iStack_60 = *y;
          }
          sStack_74 = strlen(acStack_b0);
          for (iStack_68 = 0; iStack_68 < (int)sStack_74; iStack_68 = iStack_68 + 1) {
            if (height == 0) {
              Ellipse(hdc,iStack_60 + (val_5 - iStack_7c) / 2,
                      iStack_6c + (iStack_78 - iStack_24) / 2,
                      iStack_7c + (val_5 - iStack_7c) / 2 + iStack_60,
                      iStack_24 + (iStack_78 - iStack_24) / 2 + iStack_6c);
            }
            else {
              thunk_FUN_1001c8d1(hdc,(char)*(int32_t *)(acStack_b0 + iStack_68),
                                 iStack_60 + (val_5 - iStack_7c) / 2,
                                 iStack_6c + (iStack_78 - iStack_24) / 2,iStack_7c,iStack_24);
            }
            iStack_60 = iStack_60 + val_5;
          }
          if (*str_3 == ':') {
            acStack_b0[0] = *str_3;
            str_3 = char_ptr_2 + 2;
            iStack_68 = 1;
            acStack_b0[1] = 0;
            GetTextExtentPoint32A(hdc,acStack_b0,1,&tStack_10);
            sVar7 = strlen(acStack_b0);
            TextOutA(hdc,iStack_60,iStack_6c,acStack_b0,sVar7);
            iStack_60 = iStack_60 + tStack_10.cx;
          }
        }
      }
      else {
        str_3 = str_3 + 1;
        iStack_6c = iStack_6c + val_4;
        iStack_60 = *y;
      }
    }
    uval_3 = iStack_60 - *y;
    if (iStack_60 - *y <= (int)uStack_64) {
      uval_3 = uStack_64;
    }
    iStack_8 = (val_4 + iStack_6c) - y[1];
    uStack_64 = uval_3;
    RestoreDC(hdc,iStack_70);
    uval_3 = iStack_8 << 0x10 | uStack_64 & 0xffff;
  }
  return uval_3;
}


