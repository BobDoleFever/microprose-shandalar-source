/*
 * Decompiled function: Palette_Subsystem_0049fee7
 * Entry Point: 0049fee7
 * Size: 490 bytes
 */
#include "magic.h"


void Palette_Subsystem_0049fee7(HDC hdc,int *y,uint width,uint height)

{
  size_t sVar1;
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
      pCVar2 = &DAT_0052c1e8;
      sVar1 = strlen(local_14);
      wsprintfA(local_14 + sVar1,pCVar2,width);
    }
    else {
      strcat(local_14,&DAT_0052c1e4);
    }
    strcat(local_14,&DAT_0052c1ec);
    if ((height & 0x4000) == 0) {
      pCVar2 = &DAT_0052c1f4;
      sVar1 = strlen(local_14);
      wsprintfA(local_14 + sVar1,pCVar2,height);
    }
    else {
      strcat(local_14,&DAT_0052c1f0);
    }
    SelectObject(hdc,DAT_0054b58c);
    SetTextAlign(hdc,10);
    SetBkMode(hdc,1);
    SetTextColor(hdc,DAT_0054b588);
    sVar1 = strlen(local_14);
    TextOutA(hdc,0xca,0x11a,local_14,sVar1);
    SetTextColor(hdc,DAT_0054b9a4);
    sVar1 = strlen(local_14);
    TextOutA(hdc,0xc6,0x116,local_14,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}


