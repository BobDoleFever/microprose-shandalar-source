/*
 * Decompiled function: Palette_Subsystem_004a00d1
 * Entry Point: 004a00d1
 * Size: 361 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a00d1(HDC hdc,int *arg_2,undefined4 arg_3)

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
    sprintf(local_1c,&DAT_0052c1f8,arg_3);
    SelectObject(hdc,DAT_0054b58c);
    SetTextAlign(hdc,10);
    SetBkMode(hdc,1);
    local_c = 100;
    local_10 = 0x8c;
    SetTextColor(hdc,DAT_0054b588);
    sVar1 = strlen(local_1c);
    TextOutA(hdc,local_c + -1,local_10 + -1,local_1c,sVar1);
    SetTextColor(hdc,DAT_0054b570);
    sVar1 = strlen(local_1c);
    TextOutA(hdc,local_c + -3,local_10 + -3,local_1c,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}


