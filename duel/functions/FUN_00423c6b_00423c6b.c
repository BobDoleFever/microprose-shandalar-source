/*
 * Decompiled function: FUN_00423c6b
 * Entry Point: 00423c6b
 * Size: 490 bytes
 */
#include "duel.h"


void FUN_00423c6b(HDC hdc,int *y,uint width,uint height)

{
  size_t sVar1;
  LPCSTR pCVar2;
  uint local_14 [3];
  int local_8;
  
  if ((hdc != (HDC)0x0) && (y != (int *)0x0)) {
    local_8 = SaveDC(hdc);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,200,0x118,(LPSIZE)0x0);
    SetViewportExtEx(hdc,y[2] - *y,y[3] - y[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,0,0,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*y,y[1],(LPPOINT)0x0);
    local_14[0]._0_1_ = 0;
    if ((width & 0x4000) == 0) {
      pCVar2 = &DAT_004f35fc;
      sVar1 = _strlen((char *)local_14);
      wsprintfA((LPSTR)((int)local_14 + sVar1),pCVar2,width);
    }
    else {
      FUN_004d9640(local_14,(uint *)&DAT_004f35f8);
    }
    FUN_004d9640(local_14,(uint *)&DAT_004f3600);
    if ((height & 0x4000) == 0) {
      pCVar2 = &DAT_004f3608;
      sVar1 = _strlen((char *)local_14);
      wsprintfA((LPSTR)((int)local_14 + sVar1),pCVar2,height);
    }
    else {
      FUN_004d9640(local_14,(uint *)&DAT_004f3604);
    }
    SelectObject(hdc,DAT_0050ade4);
    SetTextAlign(hdc,10);
    SetBkMode(hdc,1);
    SetTextColor(hdc,DAT_0050ade0);
    sVar1 = _strlen((char *)local_14);
    TextOutA(hdc,0xca,0x11a,(LPCSTR)local_14,sVar1);
    SetTextColor(hdc,DAT_0050b1fc);
    sVar1 = _strlen((char *)local_14);
    TextOutA(hdc,0xc6,0x116,(LPCSTR)local_14,sVar1);
    RestoreDC(hdc,local_8);
  }
  return;
}


