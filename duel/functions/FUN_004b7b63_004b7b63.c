/*
 * Decompiled function: FUN_004b7b63
 * Entry Point: 004b7b63
 * Size: 1009 bytes
 */
#include "duel.h"


void FUN_004b7b63(HWND hwnd,char *str_2,uint arg_3)

{
  size_t sVar1;
  HDC hdc;
  tagSIZE *psizl;
  tagRECT local_74;
  HDC local_64;
  tagRECT local_60;
  tagSIZE local_50;
  int local_48;
  int local_44;
  tagRECT local_40;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  tagRECT local_14;
  
  local_48 = 4;
  local_20 = 4;
  local_2c = 7;
  if (str_2 == (char *)0x0) {
LAB_004b7b9f:
    ShowWindow(hwnd,0);
  }
  else {
    sVar1 = _strlen(str_2);
    if (sVar1 == 0) goto LAB_004b7b9f;
  }
  if ((arg_3 == 0) || ((arg_3 & 1) == 0)) {
    ShowWindow(DAT_005f2f98,0);
  }
  if ((arg_3 == 0) || ((arg_3 & 2) == 0)) {
    ShowWindow(DAT_005f2f94,0);
  }
  local_30 = 0;
  local_64 = GetDC(hwnd);
  GetClientRect(hwnd,&local_60);
  local_18 = (local_60.bottom - local_60.top) + local_20 * -2;
  FUN_004b8001(hwnd,local_64,&local_60.left);
  psizl = &local_50;
  sVar1 = _strlen(&DAT_00618960);
  GetTextExtentPoint32A(local_64,&DAT_00618960,sVar1,psizl);
  local_44 = local_50.cx + local_18 / 2;
  local_60.right = 2000;
  local_24 = FUN_004222b9(local_64,(int)&local_60,(int)str_2);
  local_24 = local_24 & 0xffff;
  ReleaseDC(hwnd,local_64);
  if (((arg_3 & 2) != 0) || ((arg_3 & 1) != 0)) {
    SetWindowPos(DAT_005f2f94,(HWND)0x0,0,0,local_44,local_18,6);
    local_30 = local_30 + local_44 + local_2c;
  }
  if ((arg_3 & 1) != 0) {
    SetWindowPos(DAT_005f2f98,(HWND)0x0,0,0,local_44,local_18,6);
    local_30 = local_30 + local_44 + local_2c;
  }
  if (str_2 != (char *)0x0) {
    sVar1 = _strlen(str_2);
    if (sVar1 != 0) {
      hdc = GetDC(hwnd);
      GetClientRect(hwnd,&local_74);
      FUN_004b8001(hwnd,hdc,&local_74.left);
      local_74.right = 2000;
      local_24 = FUN_004222b9(hdc,(int)&local_74,(int)str_2);
      local_24 = local_24 & 0xffff;
      ReleaseDC(hwnd,hdc);
      SetWindowTextA(hwnd,str_2);
      goto LAB_004b7da3;
    }
  }
  local_24 = 0;
  SetWindowTextA(hwnd,&DAT_005070d0);
LAB_004b7da3:
  GetWindowRect(hwnd,&local_14);
  SetWindowPos(hwnd,(HWND)0x0,0,0,local_48 * 2 + local_24 + local_30 + 0x19,
               local_14.bottom - local_14.top,6);
  GetClientRect(hwnd,&local_14);
  local_1c = local_14.left + local_48;
  if ((arg_3 & 2) != 0) {
    GetWindowRect(DAT_005f2f94,&local_40);
    local_1c = local_1c + local_2c;
    local_28 = (local_14.bottom - local_14.top) / 2 - (local_40.bottom - local_40.top) / 2;
    SetWindowPos(DAT_005f2f94,(HWND)0x0,local_1c,local_28,0,0,5);
  }
  if ((arg_3 & 1) != 0) {
    GetWindowRect(DAT_005f2f98,&local_40);
    local_1c = local_1c + (local_40.right - local_40.left) + local_2c;
    local_28 = (local_14.bottom - local_14.top) / 2 - (local_40.bottom - local_40.top) / 2;
    SetWindowPos(DAT_005f2f98,(HWND)0x0,local_1c,local_28,0,0,5);
  }
  FUN_004b7f54(hwnd);
  InvalidateRect(DAT_005f2f98,(RECT *)0x0,1);
  InvalidateRect(DAT_005f2f94,(RECT *)0x0,1);
  InvalidateRect(hwnd,(RECT *)0x0,1);
  if ((arg_3 & 1) != 0) {
    ShowWindow(DAT_005f2f98,5);
  }
  if ((arg_3 & 2) != 0) {
    ShowWindow(DAT_005f2f94,5);
  }
  if (str_2 != (char *)0x0) {
    sVar1 = _strlen(str_2);
    if (sVar1 != 0) {
      ShowWindow(hwnd,5);
    }
  }
  FUN_0047283d();
  UpdateWindow(hwnd);
  return;
}


