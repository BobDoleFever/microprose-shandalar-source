/*
 * Decompiled function: FUN_1001e527
 * Entry Point: 1001e527
 * Size: 490 bytes
 */
#include "deckdll.h"


void FUN_1001e527(HDC hdc,int *y,uint32_t width,uint32_t height)

{
  size_t len_1;
  LPCSTR pCVar2;
  char local_14 [12];
  int local_8;
  
  if ((hdc != (HDC)0x0) && (y != (int *)0x0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,y[2] - *y,y[3] - y[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*y,y[1],(LPPOINT)0x0);
    local_14[0] = '\0';
    if ((width & 0x4000) == 0) {
      pCVar2 = &DAT_100438d0;
      len_1 = strlen(local_14);
      wsprintfA(local_14 + len_1,pCVar2,width);
    }
    else {
      strcat(local_14,&DAT_100438cc);
    }
    strcat(local_14,&DAT_100438d4);
    if ((height & 0x4000) == 0) {
      pCVar2 = &DAT_100438dc;
      len_1 = strlen(local_14);
      wsprintfA(local_14 + len_1,pCVar2,height);
    }
    else {
      strcat(local_14,&DAT_100438d8);
    }
    SelectObject(hdc,DAT_1013e1fc);
    SetTextAlign(hdc,10);
    SetBkMode(hdc,1);
    SetTextColor(hdc,DAT_1013e1f8);
    len_1 = strlen(local_14);
    TextOutA(hdc,0xca,0x11a,local_14,len_1);
    SetTextColor(hdc,DAT_1013e614);
    len_1 = strlen(local_14);
    TextOutA(hdc,0xc6,0x116,local_14,len_1);
    RestoreDC(hdc,local_8);
  }
  return;
}


