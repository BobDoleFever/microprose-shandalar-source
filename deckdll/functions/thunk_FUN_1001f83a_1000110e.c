/*
 * Decompiled function: thunk_FUN_1001f83a
 * Entry Point: 1000110e
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001f83a(HDC hdc,int *arg_2,char *str_3,int arg_4,int arg_5)

{
  size_t len_1;
  COLORREF CStack_70;
  char acStack_6c [100];
  int iStack_8;
  
  if (((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) && (str_3 != (char *)0x0)) {
    strcpy(acStack_6c,str_3);
    iStack_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2[2] - *arg_2,arg_2[3] - arg_2[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*arg_2,arg_2[1],(LPPOINT)0x0);
    if (arg_4 == 0) {
      CStack_70 = DAT_1013e1ec;
    }
    else if (arg_4 == 2) {
      CStack_70 = DAT_1013e618;
    }
    else {
      CStack_70 = DAT_1013e654;
    }
    SelectObject(hdc,DAT_1013e5cc);
    SetTextAlign(hdc,0);
    if (arg_5 == 0) {
      SetBkMode(hdc,2);
      SetBkColor(hdc,DAT_1013e550);
    }
    else {
      SetBkMode(hdc,1);
    }
    SetTextColor(hdc,DAT_1013e1f8);
    len_1 = strlen(acStack_6c);
    TextOutA(hdc,5,1,acStack_6c,len_1);
    SetTextColor(hdc,CStack_70);
    SetBkMode(hdc,1);
    len_1 = strlen(acStack_6c);
    TextOutA(hdc,2,-2,acStack_6c,len_1);
    RestoreDC(hdc,iStack_8);
  }
  return;
}


