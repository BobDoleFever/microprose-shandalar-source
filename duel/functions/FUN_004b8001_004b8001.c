/*
 * Decompiled function: FUN_004b8001
 * Entry Point: 004b8001
 * Size: 350 bytes
 */
#include "duel.h"


void FUN_004b8001(HWND hwnd,HDC hdc,int *arg_3)

{
  BOOL BVar1;
  int iVar2;
  tagRECT local_50;
  HGDIOBJ local_40;
  tagTEXTMETRICA local_3c;
  
  local_40 = (HGDIOBJ)GetWindowLongA(hwnd,0);
  if (local_40 != (HGDIOBJ)0x0) {
    SelectObject(hdc,local_40);
  }
  GetTextMetricsA(hdc,&local_3c);
  *arg_3 = *arg_3 + local_3c.tmHeight / 2;
  arg_3[1] = arg_3[1] + 4;
  arg_3[3] = arg_3[3] + -3;
  BVar1 = IsWindowVisible(DAT_005f2f98);
  if (BVar1 != 0) {
    GetWindowRect(DAT_005f2f98,&local_50);
    MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_50,2);
    iVar2 = local_50.right + local_3c.tmHeight / 2;
    if (iVar2 <= *arg_3) {
      iVar2 = *arg_3;
    }
    *arg_3 = iVar2;
  }
  BVar1 = IsWindowVisible(DAT_005f2f94);
  if (BVar1 != 0) {
    GetWindowRect(DAT_005f2f94,&local_50);
    MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_50,2);
    iVar2 = local_50.right + local_3c.tmHeight / 2;
    if (iVar2 <= *arg_3) {
      iVar2 = *arg_3;
    }
    *arg_3 = iVar2;
  }
  SetMapMode(hdc,8);
  SetWindowExtEx(hdc,arg_3[2] - *arg_3,0x14,(LPSIZE)0x0);
  SetViewportExtEx(hdc,arg_3[2] - *arg_3,arg_3[3] - arg_3[1],(LPSIZE)0x0);
  return;
}


