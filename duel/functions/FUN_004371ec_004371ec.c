/*
 * Decompiled function: FUN_004371ec
 * Entry Point: 004371ec
 * Size: 846 bytes
 */
#include "duel.h"


void FUN_004371ec(HDC hdc,RECT *arg_2,int arg_3)

{
  HBRUSH hbr;
  char *pcVar1;
  size_t sVar2;
  undefined1 local_7c [4];
  int local_78;
  int local_74;
  int local_64;
  tagRECT local_60;
  HANDLE local_50;
  tagPOINT local_4c;
  int local_44;
  HANDLE local_40;
  uint local_3c [13];
  HWND local_8;
  
  if (arg_3 == 0) {
    local_8 = DAT_00601550;
  }
  else {
    local_8 = DAT_00617438;
  }
  local_40 = (HANDLE)GetWindowLongA(local_8,0);
  if (arg_3 == 0) {
    local_50 = *(HANDLE *)(&DAT_00516708 + DAT_006169f0 * 4);
  }
  else {
    local_50 = *(HANDLE *)(&DAT_00516708 + DAT_00663e6c * 4);
  }
  if (local_50 == (HANDLE)0x0) {
    hbr = GetStockObject(4);
    FillRect(hdc,arg_2,hbr);
  }
  else {
    FUN_004709ae((int)hdc,(int)arg_2,local_50);
  }
  if (local_40 != (HANDLE)0x0) {
    GetObjectA(local_40,0x18,local_7c);
    local_78 = local_78 / 2;
    local_64 = SaveDC(hdc);
    SetMapMode(hdc,7);
    SetWindowOrgEx(hdc,local_78 / 2,local_74 / 2,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,arg_2->left + (arg_2->right - arg_2->left) / 2,
                     arg_2->top + (arg_2->bottom - arg_2->top) / 2,(LPPOINT)0x0);
    SetWindowExtEx(hdc,local_78,local_74,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2->right - arg_2->left,arg_2->bottom - arg_2->top,(LPSIZE)0x0);
    SetRect(&local_60,0,0,local_78,local_74);
    FUN_00470c78(hdc,&local_60,local_40);
    RestoreDC(hdc,local_64);
  }
  if (arg_3 == 1) {
    FUN_00448412((char *)local_3c);
  }
  else {
    Mem_AllocOrFree_004d9630(local_3c,(uint *)&DAT_006015b0);
    pcVar1 = _strchr((char *)local_3c,0x2d);
    if (pcVar1 != (char *)0x0) {
      pcVar1 = _strchr((char *)local_3c,0x2d);
      *pcVar1 = '\0';
    }
  }
  sVar2 = _strlen((char *)local_3c);
  if (sVar2 != 0) {
    local_44 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,arg_2->right - arg_2->left,100,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2->right - arg_2->left,arg_2->bottom - arg_2->top,(LPSIZE)0x0);
    SelectObject(hdc,DAT_00516704);
    SetBkMode(hdc,1);
    SetTextAlign(hdc,0xe);
    local_4c.x = arg_2->left + (arg_2->right - arg_2->left) / 2;
    local_4c.y = arg_2->bottom;
    DPtoLP(hdc,&local_4c,1);
    SetTextColor(hdc,DAT_005166ec);
    sVar2 = _strlen((char *)local_3c);
    TextOutA(hdc,local_4c.x + 1,local_4c.y + 1,(LPCSTR)local_3c,sVar2);
    SetTextColor(hdc,DAT_005166e8);
    sVar2 = _strlen((char *)local_3c);
    TextOutA(hdc,local_4c.x,local_4c.y,(LPCSTR)local_3c,sVar2);
    RestoreDC(hdc,local_44);
  }
  return;
}


