/*
 * Decompiled function: FUN_1001cbfc
 * Entry Point: 1001cbfc
 * Size: 1594 bytes
 */
#include "deckdll.h"


uint32_t FUN_1001cbfc(HDC hdc,int *y,char *str_3,int height)

{
  int val_1;
  char *char_ptr_2;
  uint32_t uval_3;
  int val_4;
  int val_5;
  HGDIOBJ pvVar6;
  size_t sVar7;
  char local_b0 [52];
  int local_7c;
  int local_78;
  size_t local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint32_t local_64;
  int local_60;
  tagTEXTMETRICA local_5c;
  int local_24;
  tagRECT local_20;
  tagSIZE local_10;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (y == (int *)0x0)) || (str_3 == (char *)0x0)) {
    uval_3 = 0;
  }
  else if (*str_3 == '\0') {
    uval_3 = 0;
  }
  else {
    local_70 = SaveDC(hdc);
    local_64 = 0;
    local_8 = 0;
    GetTextMetricsA(hdc,&local_5c);
    val_4 = local_5c.tmExternalLeading + local_5c.tmHeight;
    SetRect(&local_20,0,0,0,local_5c.tmHeight);
    LPtoDP(hdc,(LPPOINT)&local_20,2);
    SetRect(&local_20,0,0,local_20.bottom - local_20.top,0);
    DPtoLP(hdc,(LPPOINT)&local_20,2);
    local_7c = ((local_20.right - local_20.left) * 0x4b) / 100;
    val_5 = ((local_20.right - local_20.left) * 0x55) / 100;
    local_24 = (local_5c.tmHeight * 0x4b) / 100;
    local_78 = local_5c.tmHeight;
    IntersectClipRect(hdc,*y,y[1],y[2],y[3]);
    pvVar6 = GetStockObject(4);
    SelectObject(hdc,pvVar6);
    pvVar6 = GetStockObject(8);
    SelectObject(hdc,pvVar6);
    local_60 = *y;
    local_6c = y[1];
    while (*str_3 != '\0') {
      if (*str_3 == ' ') {
        local_68 = 0;
        local_b0[0] = *str_3;
        val_1 = local_68;
        while( true ) {
          local_68 = val_1 + 1;
          str_3 = str_3 + 1;
          if ((*str_3 == '\0') || (*str_3 != ' ')) break;
          local_b0[val_1 + 1] = *str_3;
          val_1 = local_68;
        }
        local_b0[val_1 + 1] = '\0';
        GetTextExtentPoint32A(hdc,local_b0,local_68,&local_10);
        if ((y[2] < local_10.cx + local_60) || (local_60 <= *y)) {
          uval_3 = local_60 - *y;
          if (local_60 - *y <= (int)local_64) {
            uval_3 = local_64;
          }
          local_6c = local_6c + val_4;
          local_60 = *y;
          local_64 = uval_3;
        }
        else {
          sVar7 = strlen(local_b0);
          TextOutA(hdc,local_60,local_6c,local_b0,sVar7);
          local_60 = local_60 + local_10.cx;
        }
      }
      else if ((*str_3 == '\0') || (*str_3 != '\n')) {
        if ((*str_3 < -0x12) || ((uint32_t)(int)*str_3 < 0x80000000)) {
          local_68 = 0;
          local_b0[0] = *str_3;
          val_1 = local_68;
          while( true ) {
            local_68 = val_1 + 1;
            str_3 = str_3 + 1;
            if (((*str_3 == '\0') || (*str_3 == ' ')) ||
               ((*str_3 == '\n' || ((-0x13 < *str_3 && (*str_3 < '\0')))))) break;
            local_b0[val_1 + 1] = *str_3;
            val_1 = local_68;
          }
          local_b0[val_1 + 1] = '\0';
          GetTextExtentPoint32A(hdc,local_b0,local_68,&local_10);
          if (y[2] < local_10.cx + local_60) {
            local_6c = local_6c + val_4;
            local_60 = *y;
          }
          sVar7 = strlen(local_b0);
          TextOutA(hdc,local_60,local_6c,local_b0,sVar7);
          local_60 = local_60 + local_10.cx;
        }
        else {
          local_68 = 0;
          local_b0[0] = *str_3;
          char_ptr_2 = str_3;
          val_1 = local_68;
          while( true ) {
            local_68 = val_1 + 1;
            str_3 = char_ptr_2 + 1;
            if (((*str_3 == '\0') || (*str_3 < -0x12)) || ((uint32_t)(int)*str_3 < 0x80000000)) break;
            local_b0[val_1 + 1] = *str_3;
            char_ptr_2 = str_3;
            val_1 = local_68;
          }
          local_b0[val_1 + 1] = '\0';
          local_10.cx = local_68 * local_7c;
          if (y[2] < local_10.cx + local_60) {
            local_6c = local_6c + val_4;
            local_60 = *y;
          }
          local_74 = strlen(local_b0);
          for (local_68 = 0; local_68 < (int)local_74; local_68 = local_68 + 1) {
            if (height == 0) {
              Ellipse(hdc,local_60 + (val_5 - local_7c) / 2,local_6c + (local_78 - local_24) / 2,
                      local_7c + (val_5 - local_7c) / 2 + local_60,
                      local_24 + (local_78 - local_24) / 2 + local_6c);
            }
            else {
              thunk_FUN_1001c8d1(hdc,(char)*(int32_t *)(local_b0 + local_68),
                                 local_60 + (val_5 - local_7c) / 2,
                                 local_6c + (local_78 - local_24) / 2,local_7c,local_24);
            }
            local_60 = local_60 + val_5;
          }
          if (*str_3 == ':') {
            local_b0[0] = *str_3;
            str_3 = char_ptr_2 + 2;
            local_68 = 1;
            local_b0[1] = 0;
            GetTextExtentPoint32A(hdc,local_b0,1,&local_10);
            sVar7 = strlen(local_b0);
            TextOutA(hdc,local_60,local_6c,local_b0,sVar7);
            local_60 = local_60 + local_10.cx;
          }
        }
      }
      else {
        str_3 = str_3 + 1;
        local_6c = local_6c + val_4;
        local_60 = *y;
      }
    }
    uval_3 = local_60 - *y;
    if (local_60 - *y <= (int)local_64) {
      uval_3 = local_64;
    }
    local_8 = (val_4 + local_6c) - y[1];
    local_64 = uval_3;
    RestoreDC(hdc,local_70);
    uval_3 = local_8 << 0x10 | local_64 & 0xffff;
  }
  return uval_3;
}


