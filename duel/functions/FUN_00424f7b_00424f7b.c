/*
 * Decompiled function: FUN_00424f7b
 * Entry Point: 00424f7b
 * Size: 445 bytes
 */
#include "duel.h"


void FUN_00424f7b(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5)

{
  size_t sVar1;
  COLORREF local_70;
  uint local_6c [25];
  int local_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) && (arg_3 != 0)) {
    Mem_AllocOrFree_004d9630(local_6c,(uint *)arg_3);
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2[2] - *arg_2,arg_2[3] - arg_2[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*arg_2,arg_2[1],(LPPOINT)0x0);
    if (arg_4 == 0) {
      local_70 = DAT_0050add4;
    }
    else if (arg_4 == 2) {
      local_70 = DAT_0050b200;
    }
    else {
      local_70 = DAT_0050b23c;
    }
    SelectObject(hdc,DAT_0050b1b4);
    SetTextAlign(hdc,0);
    if (arg_5 == 0) {
      SetBkMode(hdc,2);
      SetBkColor(hdc,DAT_0050b138);
    }
    else {
      SetBkMode(hdc,1);
    }
    SetTextColor(hdc,DAT_0050ade0);
    sVar1 = _strlen((char *)local_6c);
    TextOutA(hdc,5,1,(LPCSTR)local_6c,sVar1);
    SetTextColor(hdc,local_70);
    SetBkMode(hdc,1);
    sVar1 = _strlen((char *)local_6c);
    TextOutA(hdc,2,-2,(LPCSTR)local_6c,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}


