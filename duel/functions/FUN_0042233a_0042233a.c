/*
 * Decompiled function: FUN_0042233a
 * Entry Point: 0042233a
 * Size: 1600 bytes
 */
#include "duel.h"


uint FUN_0042233a(HDC hdc,int *y,char *str_3,int height)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  HGDIOBJ pvVar6;
  size_t sVar7;
  char local_b0 [52];
  int local_7c;
  int local_78;
  size_t local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint local_64;
  int local_60;
  tagTEXTMETRICA local_5c;
  int local_24;
  tagRECT local_20;
  tagSIZE local_10;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (y == (int *)0x0)) || (str_3 == (char *)0x0)) {
    uVar3 = 0;
  }
  else if (*str_3 == '\0') {
    uVar3 = 0;
  }
  else {
    local_70 = SaveDC(hdc);
    local_64 = 0;
    local_8 = 0;
    GetTextMetricsA(hdc,&local_5c);
    iVar4 = local_5c.tmHeight + local_5c.tmExternalLeading;
    SetRect(&local_20,0,0,0,local_5c.tmHeight);
    LPtoDP(hdc,(LPPOINT)&local_20,2);
    SetRect(&local_20,0,0,local_20.bottom - local_20.top,0);
    DPtoLP(hdc,(LPPOINT)&local_20,2);
    local_7c = ((local_20.right - local_20.left) * 0x4b) / 100;
    iVar5 = ((local_20.right - local_20.left) * 0x55) / 100;
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
        iVar1 = local_68;
        while( true ) {
          local_68 = iVar1 + 1;
          str_3 = str_3 + 1;
          if ((*str_3 == '\0') || (*str_3 != ' ')) break;
          local_b0[iVar1 + 1] = *str_3;
          iVar1 = local_68;
        }
        local_b0[iVar1 + 1] = '\0';
        GetTextExtentPoint32A(hdc,local_b0,local_68,&local_10);
        if ((y[2] < local_10.cx + local_60) || (local_60 <= *y)) {
          uVar3 = local_60 - *y;
          if (local_60 - *y <= (int)local_64) {
            uVar3 = local_64;
          }
          local_6c = local_6c + iVar4;
          local_60 = *y;
          local_64 = uVar3;
        }
        else {
          sVar7 = _strlen(local_b0);
          TextOutA(hdc,local_60,local_6c,local_b0,sVar7);
          local_60 = local_60 + local_10.cx;
        }
      }
      else if ((*str_3 == '\0') || (*str_3 != '\n')) {
        if ((*str_3 < -0x12) || ((uint)(int)*str_3 < 0x80000000)) {
          local_68 = 0;
          local_b0[0] = *str_3;
          iVar1 = local_68;
          while( true ) {
            local_68 = iVar1 + 1;
            str_3 = str_3 + 1;
            if (((*str_3 == '\0') || (*str_3 == ' ')) ||
               ((*str_3 == '\n' || ((-0x13 < *str_3 && (*str_3 < '\0')))))) break;
            local_b0[iVar1 + 1] = *str_3;
            iVar1 = local_68;
          }
          local_b0[iVar1 + 1] = '\0';
          GetTextExtentPoint32A(hdc,local_b0,local_68,&local_10);
          if (y[2] < local_10.cx + local_60) {
            local_6c = local_6c + iVar4;
            local_60 = *y;
          }
          sVar7 = _strlen(local_b0);
          TextOutA(hdc,local_60,local_6c,local_b0,sVar7);
          local_60 = local_60 + local_10.cx;
        }
        else {
          local_68 = 0;
          local_b0[0] = *str_3;
          pcVar2 = str_3;
          iVar1 = local_68;
          while( true ) {
            local_68 = iVar1 + 1;
            str_3 = pcVar2 + 1;
            if (((*str_3 == '\0') || (*str_3 < -0x12)) || ((uint)(int)*str_3 < 0x80000000)) break;
            local_b0[iVar1 + 1] = *str_3;
            pcVar2 = str_3;
            iVar1 = local_68;
          }
          local_b0[iVar1 + 1] = '\0';
          local_10.cx = local_68 * local_7c;
          if (y[2] < local_10.cx + local_60) {
            local_6c = local_6c + iVar4;
            local_60 = *y;
          }
          local_74 = _strlen(local_b0);
          for (local_68 = 0; local_68 < (int)local_74; local_68 = local_68 + 1) {
            if (height == 0) {
              Ellipse(hdc,local_60 + (iVar5 - local_7c) / 2,local_6c + (local_78 - local_24) / 2,
                      local_7c + (iVar5 - local_7c) / 2 + local_60,
                      local_24 + (local_78 - local_24) / 2 + local_6c);
            }
            else {
              FUN_0042200f((int)hdc,(char)*(undefined4 *)(local_b0 + local_68),
                           local_60 + (iVar5 - local_7c) / 2,local_6c + (local_78 - local_24) / 2,
                           local_7c,local_24);
            }
            local_60 = local_60 + iVar5;
          }
          if (*str_3 == ':') {
            local_b0[0] = *str_3;
            str_3 = pcVar2 + 2;
            local_68 = 1;
            local_b0[1] = 0;
            GetTextExtentPoint32A(hdc,local_b0,1,&local_10);
            sVar7 = _strlen(local_b0);
            TextOutA(hdc,local_60,local_6c,local_b0,sVar7);
            local_60 = local_60 + local_10.cx;
          }
        }
      }
      else {
        str_3 = str_3 + 1;
        local_6c = local_6c + iVar4;
        local_60 = *y;
      }
    }
    uVar3 = local_60 - *y;
    if (local_60 - *y <= (int)local_64) {
      uVar3 = local_64;
    }
    local_8 = (iVar4 + local_6c) - y[1];
    local_64 = uVar3;
    RestoreDC(hdc,local_70);
    uVar3 = local_8 << 0x10 | local_64 & 0xffff;
  }
  return uVar3;
}


