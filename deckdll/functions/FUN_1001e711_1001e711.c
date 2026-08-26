/*
 * Decompiled function: FUN_1001e711
 * Entry Point: 1001e711
 * Size: 361 bytes
 */
#include "deckdll.h"


void FUN_1001e711(HDC hdc,int *arg_2,int32_t arg_3)

{
  size_t len_1;
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
    sprintf(local_1c,&DAT_100438e0,arg_3);
    SelectObject(hdc,DAT_1013e1fc);
    SetTextAlign(hdc,10);
    SetBkMode(hdc,1);
    local_c = 100;
    local_10 = 0x8c;
    SetTextColor(hdc,DAT_1013e1f8);
    len_1 = strlen(local_1c);
    TextOutA(hdc,local_c + -1,local_10 + -1,local_1c,len_1);
    SetTextColor(hdc,DAT_1013e1e0);
    len_1 = strlen(local_1c);
    TextOutA(hdc,local_c + -3,local_10 + -3,local_1c,len_1);
    RestoreDC(hdc,local_8);
  }
  return;
}


