/*
 * Decompiled function: FUN_10032b18
 * Entry Point: 10032b18
 * Size: 191 bytes
 */
#include "deckdll.h"


int32_t FUN_10032b18(char *str_1,COLORREF arg_2,HBRUSH arg_3)

{
  HDC hdc;
  size_t c;
  tagRECT local_14;
  
  SetRect(&local_14,0,0x23f,0x8c,0x26c);
  if (DAT_10046634 != 0xffffffff) {
    hdc = CreateDCA(s_DISPLAY_10046704,(LPCSTR)0x0,(LPCSTR)0x0,(DEVMODEA *)0x0);
    SetTextColor(hdc,arg_2);
    SetBkMode(hdc,1);
    FillRect(hdc,&local_14,arg_3);
    c = strlen(str_1);
    TextOutA(hdc,local_14.left + 5,local_14.top + 5,str_1,c);
    DeleteDC(hdc);
    Sleep(DAT_10046634);
  }
  return 1;
}


