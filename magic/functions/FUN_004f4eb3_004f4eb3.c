/*
 * Decompiled function: FUN_004f4eb3
 * Entry Point: 004f4eb3
 * Size: 261 bytes
 */
#include "magic.h"


int FUN_004f4eb3(HWND hwnd,char *str_2)

{
  int iVar1;
  HGDIOBJ h;
  HDC hdc;
  char local_104 [200];
  tagTEXTMETRICA local_3c;
  
  if (hwnd == (HWND)0x0) {
    iVar1 = 0;
  }
  else {
    h = (HGDIOBJ)SendMessageA(hwnd,0x31,0,0);
    if (str_2 == (char *)0x0) {
      GetWindowTextA(hwnd,local_104,200);
    }
    else {
      strcpy(local_104,str_2);
    }
    hdc = GetDC(hwnd);
    FUN_004f3955(hdc);
    if (h != (HGDIOBJ)0x0) {
      SelectObject(hdc,h);
    }
    iVar1 = Palette_Subsystem_0049dcd5(hdc,local_104);
    GetTextMetricsA(hdc,&local_3c);
    iVar1 = iVar1 + local_3c.tmHeight * 3;
    ReleaseDC(hwnd,hdc);
  }
  return iVar1;
}


