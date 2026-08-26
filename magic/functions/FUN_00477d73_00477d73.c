/*
 * Decompiled function: FUN_00477d73
 * Entry Point: 00477d73
 * Size: 1008 bytes
 */
#include "magic.h"


void FUN_00477d73(HWND hwnd,char *str_2,uint arg_3)

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
LAB_00477daf:
    ShowWindow(hwnd,0);
  }
  else {
    sVar1 = strlen(str_2);
    if (sVar1 == 0) goto LAB_00477daf;
  }
  if ((arg_3 == 0) || ((arg_3 & 1) == 0)) {
    ShowWindow(DAT_00676e38,0);
  }
  if ((arg_3 == 0) || ((arg_3 & 2) == 0)) {
    ShowWindow(DAT_00676e34,0);
  }
  local_30 = 0;
  local_64 = GetDC(hwnd);
  GetClientRect(hwnd,&local_60);
  local_18 = (local_60.bottom - local_60.top) + local_20 * -2;
  FUN_0047820f(hwnd,local_64,&local_60.left);
  psizl = &local_50;
  sVar1 = strlen(&DAT_006b2d70);
  GetTextExtentPoint32A(local_64,&DAT_006b2d70,sVar1,psizl);
  local_44 = local_50.cx + local_18 / 2;
  local_60.right = 2000;
  local_24 = Palette_Subsystem_0049e53b(local_64,(int)&local_60,(int)str_2);
  local_24 = local_24 & 0xffff;
  ReleaseDC(hwnd,local_64);
  if (((arg_3 & 2) != 0) || ((arg_3 & 1) != 0)) {
    SetWindowPos(DAT_00676e34,(HWND)0x0,0,0,local_44,local_18,6);
    local_30 = local_30 + local_44 + local_2c;
  }
  if ((arg_3 & 1) != 0) {
    SetWindowPos(DAT_00676e38,(HWND)0x0,0,0,local_44,local_18,6);
    local_30 = local_30 + local_44 + local_2c;
  }
  if (str_2 != (char *)0x0) {
    sVar1 = strlen(str_2);
    if (sVar1 != 0) {
      hdc = GetDC(hwnd);
      GetClientRect(hwnd,&local_74);
      FUN_0047820f(hwnd,hdc,&local_74.left);
      local_74.right = 2000;
      local_24 = Palette_Subsystem_0049e53b(hdc,(int)&local_74,(int)str_2);
      local_24 = local_24 & 0xffff;
      ReleaseDC(hwnd,hdc);
      SetWindowTextA(hwnd,str_2);
      goto LAB_00477fb6;
    }
  }
  local_24 = 0;
  SetWindowTextA(hwnd,&DAT_00525db4);
LAB_00477fb6:
  GetWindowRect(hwnd,&local_14);
  SetWindowPos(hwnd,(HWND)0x0,0,0,local_48 * 2 + local_30 + local_24 + 0x19,
               local_14.bottom - local_14.top,6);
  GetClientRect(hwnd,&local_14);
  local_1c = local_14.left + local_48;
  if ((arg_3 & 2) != 0) {
    GetWindowRect(DAT_00676e34,&local_40);
    local_1c = local_1c + local_2c;
    local_28 = (local_14.bottom - local_14.top) / 2 - (local_40.bottom - local_40.top) / 2;
    SetWindowPos(DAT_00676e34,(HWND)0x0,local_1c,local_28,0,0,5);
  }
  if ((arg_3 & 1) != 0) {
    GetWindowRect(DAT_00676e38,&local_40);
    local_1c = local_1c + (local_40.right - local_40.left) + local_2c;
    local_28 = (local_14.bottom - local_14.top) / 2 - (local_40.bottom - local_40.top) / 2;
    SetWindowPos(DAT_00676e38,(HWND)0x0,local_1c,local_28,0,0,5);
  }
  FUN_00478163(hwnd);
  InvalidateRect(DAT_00676e38,(RECT *)0x0,1);
  InvalidateRect(DAT_00676e34,(RECT *)0x0,1);
  InvalidateRect(hwnd,(RECT *)0x0,1);
  if ((arg_3 & 1) != 0) {
    ShowWindow(DAT_00676e38,5);
  }
  if ((arg_3 & 2) != 0) {
    ShowWindow(DAT_00676e34,5);
  }
  if (str_2 != (char *)0x0) {
    sVar1 = strlen(str_2);
    if (sVar1 != 0) {
      ShowWindow(hwnd,5);
    }
  }
  FUN_004f59f7();
  UpdateWindow(hwnd);
  return;
}


