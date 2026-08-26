/*
 * Decompiled function: Palette_Subsystem_004a023a
 * Entry Point: 004a023a
 * Size: 344 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_004a023a(HDC hdc,int arg_2,undefined4 arg_3)

{
  undefined4 uVar1;
  int nSavedDC;
  char local_1c [8];
  tagRECT local_14;
  
  if ((hdc == (HDC)0x0) || (arg_2 == 0)) {
    uVar1 = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    Palette_Subsystem_004a0392(&local_14,(int *)arg_2);
    uVar1 = FUN_004f3e29(hdc,&local_14,DAT_0054b9a0);
    sprintf(local_1c,&DAT_0052c1fc,arg_3);
    SelectObject(hdc,DAT_0054b380);
    SetTextAlign(hdc,0);
    SetBkMode(hdc,1);
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,local_14.right - local_14.left,0x14,(LPSIZE)0x0);
    SetViewportExtEx(hdc,local_14.right - local_14.left,local_14.bottom - local_14.top,(LPSIZE)0x0);
    DPtoLP(hdc,(LPPOINT)&local_14,2);
    SetTextColor(hdc,DAT_0054b588);
    DrawTextA(hdc,local_1c,-1,&local_14,0x25);
    OffsetRect(&local_14,-2,-2);
    SetTextColor(hdc,DAT_0054b570);
    DrawTextA(hdc,local_1c,-1,&local_14,0x25);
    RestoreDC(hdc,nSavedDC);
  }
  return uVar1;
}


