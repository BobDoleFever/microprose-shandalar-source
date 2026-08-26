/*
 * Decompiled function: FUN_00471e86
 * Entry Point: 00471e86
 * Size: 191 bytes
 */
#include "duel.h"


undefined4 FUN_00471e86(char *str_1,COLORREF arg_2,HBRUSH arg_3)

{
  HDC hdc;
  size_t c;
  tagRECT local_14;
  
  SetRect(&local_14,0,0x23f,0x8c,0x26c);
  if (DAT_004f9784 != 0xffffffff) {
    hdc = CreateDCA(s_DISPLAY_004f9854,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
    SetTextColor(hdc,arg_2);
    SetBkMode(hdc,1);
    FillRect(hdc,&local_14,arg_3);
    c = _strlen(str_1);
    TextOutA(hdc,local_14.left + 5,local_14.top + 5,str_1,c);
    DeleteDC(hdc);
    Sleep(DAT_004f9784);
  }
  return 1;
}


