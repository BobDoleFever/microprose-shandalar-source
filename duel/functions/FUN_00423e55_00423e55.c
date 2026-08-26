/*
 * Decompiled function: FUN_00423e55
 * Entry Point: 00423e55
 * Size: 360 bytes
 */
#include "duel.h"


void FUN_00423e55(HDC hdc,int *arg_2,undefined4 arg_3)

{
  size_t sVar1;
  char local_1c [12];
  int local_10;
  int local_c;
  int local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,100,0x8c,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2[2] - *arg_2,arg_2[3] - arg_2[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*arg_2,arg_2[1],(LPPOINT)0x0);
    _sprintf(local_1c,&DAT_004f360c,arg_3);
    SelectObject(hdc,DAT_0050ade4);
    SetTextAlign(hdc,10);
    SetBkMode(hdc,1);
    local_c = 100;
    local_10 = 0x8c;
    SetTextColor(hdc,DAT_0050ade0);
    sVar1 = _strlen(local_1c);
    TextOutA(hdc,local_c + -1,local_10 + -1,local_1c,sVar1);
    SetTextColor(hdc,DAT_0050adc8);
    sVar1 = _strlen(local_1c);
    TextOutA(hdc,local_c + -3,local_10 + -3,local_1c,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}


