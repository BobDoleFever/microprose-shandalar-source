/*
 * Decompiled function: thunk_FUN_1001e527
 * Entry Point: 1000159b
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001e527(HDC hdc,int *y,uint32_t width,uint32_t height)

{
  size_t len_1;
  LPCSTR pCVar2;
  char acStack_14 [12];
  int iStack_8;
  
  if ((hdc != (HDC)0x0) && (y != (int *)0x0)) {
    iStack_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,y[2] - *y,y[3] - y[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*y,y[1],(LPPOINT)0x0);
    acStack_14[0] = '\0';
    if ((width & 0x4000) == 0) {
      pCVar2 = &DAT_100438d0;
      len_1 = strlen(acStack_14);
      wsprintfA(acStack_14 + len_1,pCVar2,width);
    }
    else {
      strcat(acStack_14,&DAT_100438cc);
    }
    strcat(acStack_14,&DAT_100438d4);
    if ((height & 0x4000) == 0) {
      pCVar2 = &DAT_100438dc;
      len_1 = strlen(acStack_14);
      wsprintfA(acStack_14 + len_1,pCVar2,height);
    }
    else {
      strcat(acStack_14,&DAT_100438d8);
    }
    SelectObject(hdc,DAT_1013e1fc);
    SetTextAlign(hdc,10);
    SetBkMode(hdc,1);
    SetTextColor(hdc,DAT_1013e1f8);
    len_1 = strlen(acStack_14);
    TextOutA(hdc,0xca,0x11a,acStack_14,len_1);
    SetTextColor(hdc,DAT_1013e614);
    len_1 = strlen(acStack_14);
    TextOutA(hdc,0xc6,0x116,acStack_14,len_1);
    RestoreDC(hdc,iStack_8);
  }
  return;
}


