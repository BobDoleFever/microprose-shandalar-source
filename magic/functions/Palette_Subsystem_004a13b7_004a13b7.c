/*
 * Decompiled function: Palette_Subsystem_004a13b7
 * Entry Point: 004a13b7
 * Size: 424 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a13b7(HDC hdc,int *arg_2,int arg_3,undefined4 arg_4,int arg_5)

{
  size_t sVar1;
  COLORREF local_74;
  char local_70 [100];
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
      local_74 = DAT_0054b57c;
    }
    else if (arg_5 == 2) {
      local_74 = DAT_0054b9a8;
    }
    else {
      local_74 = DAT_0054b9e4;
    }
    if (*(int *)(arg_3 + 0x10) == 1) {
      local_c = 0x808080;
    }
    else {
      local_c = DAT_0054b588;
    }
    SetBkMode(hdc,1);
    SelectObject(hdc,DAT_0054b95c);
    strcpy(local_70,*(char **)(arg_3 + 8));
    SetTextAlign(hdc,0);
    SetTextColor(hdc,local_c);
    sVar1 = strlen(local_70);
    TextOutA(hdc,9,1,local_70,sVar1);
    SetTextColor(hdc,local_74);
    sVar1 = strlen(local_70);
    TextOutA(hdc,8,0,local_70,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}


