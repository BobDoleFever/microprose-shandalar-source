/*
 * Decompiled function: Palette_Subsystem_004a11fa
 * Entry Point: 004a11fa
 * Size: 445 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a11fa(HDC hdc,int *arg_2,char *str_3,int arg_4,int arg_5)

{
  size_t sVar1;
  COLORREF local_70;
  char local_6c [100];
  int local_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) && (str_3 != (char *)0x0)) {
    strcpy(local_6c,str_3);
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2[2] - *arg_2,arg_2[3] - arg_2[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*arg_2,arg_2[1],(LPPOINT)0x0);
    if (arg_4 == 0) {
      local_70 = DAT_0054b57c;
    }
    else if (arg_4 == 2) {
      local_70 = DAT_0054b9a8;
    }
    else {
      local_70 = DAT_0054b9e4;
    }
    SelectObject(hdc,DAT_0054b95c);
    SetTextAlign(hdc,0);
    if (arg_5 == 0) {
      SetBkMode(hdc,2);
      SetBkColor(hdc,DAT_0054b8e0);
    }
    else {
      SetBkMode(hdc,1);
    }
    SetTextColor(hdc,DAT_0054b588);
    sVar1 = strlen(local_6c);
    TextOutA(hdc,5,1,local_6c,sVar1);
    SetTextColor(hdc,local_70);
    SetBkMode(hdc,1);
    sVar1 = strlen(local_6c);
    TextOutA(hdc,2,-2,local_6c,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}


