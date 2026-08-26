/*
 * Decompiled function: FUN_00471cf1
 * Entry Point: 00471cf1
 * Size: 261 bytes
 */
#include "duel.h"


int FUN_00471cf1(HWND hwnd,int arg2)

{
  int iVar1;
  HGDIOBJ h;
  HDC hdc;
  uint local_104 [50];
  tagTEXTMETRICA local_3c;
  
  if (hwnd == (HWND)0x0) {
    iVar1 = 0;
  }
  else {
    h = (HGDIOBJ)SendMessageA(hwnd,0x31,0,0);
    if (arg2 == 0) {
      GetWindowTextA(hwnd,(LPSTR)local_104,200);
    }
    else {
      Mem_AllocOrFree_004d9630(local_104,(uint *)arg2);
    }
    hdc = GetDC(hwnd);
    FUN_004707a4(hdc);
    if (h != (HGDIOBJ)0x0) {
      SelectObject(hdc,h);
    }
    iVar1 = FUN_00421a54(hdc,(char *)local_104);
    GetTextMetricsA(hdc,&local_3c);
    iVar1 = iVar1 + local_3c.tmHeight * 3;
    ReleaseDC(hwnd,hdc);
  }
  return iVar1;
}


