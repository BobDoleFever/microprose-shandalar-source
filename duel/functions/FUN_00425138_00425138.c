/*
 * Decompiled function: FUN_00425138
 * Entry Point: 00425138
 * Size: 424 bytes
 */
#include "duel.h"


void FUN_00425138(HDC hdc,int *arg_2,int arg_3,undefined4 arg_4,int arg_5)

{
  size_t sVar1;
  COLORREF local_74;
  uint local_70 [25];
  COLORREF local_c;
  int local_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) && (arg_3 != 0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2[2] - *arg_2,arg_2[3] - arg_2[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*arg_2,arg_2[1],(LPPOINT)0x0);
    if (arg_5 == 0) {
      local_74 = DAT_0050add4;
    }
    else if (arg_5 == 2) {
      local_74 = DAT_0050b200;
    }
    else {
      local_74 = DAT_0050b23c;
    }
    if (*(int *)(arg_3 + 0x10) == 1) {
      local_c = 0x808080;
    }
    else {
      local_c = DAT_0050ade0;
    }
    SetBkMode(hdc,1);
    SelectObject(hdc,DAT_0050b1b4);
    Mem_AllocOrFree_004d9630(local_70,*(uint **)(arg_3 + 8));
    SetTextAlign(hdc,0);
    SetTextColor(hdc,local_c);
    sVar1 = _strlen((char *)local_70);
    TextOutA(hdc,9,1,(LPCSTR)local_70,sVar1);
    SetTextColor(hdc,local_74);
    sVar1 = _strlen((char *)local_70);
    TextOutA(hdc,8,0,(LPCSTR)local_70,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}


