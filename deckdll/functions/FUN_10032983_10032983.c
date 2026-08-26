/*
 * Decompiled function: FUN_10032983
 * Entry Point: 10032983
 * Size: 261 bytes
 */
#include "deckdll.h"


int FUN_10032983(HWND hwnd,char *str_2)

{
  int val_1;
  HGDIOBJ h;
  HDC hdc;
  char local_104 [200];
  tagTEXTMETRICA local_3c;
  
  if (hwnd == (HWND)0x0) {
    val_1 = 0;
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
    thunk_FUN_10031425(hdc);
    if (h != (HGDIOBJ)0x0) {
      SelectObject(hdc,h);
    }
    val_1 = thunk_FUN_1001c315(hdc,local_104);
    GetTextMetricsA(hdc,&local_3c);
    val_1 = val_1 + local_3c.tmHeight * 3;
    ReleaseDC(hwnd,hdc);
  }
  return val_1;
}


