/*
 * Decompiled function: FUN_004241e8
 * Entry Point: 004241e8
 * Size: 547 bytes
 */
#include "duel.h"


void FUN_004241e8(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5)

{
  int iVar1;
  char local_20 [8];
  int local_18;
  tagRECT local_14;
  
  if ((((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) && ((arg_3 == 0 || (arg_3 == 1)))) &&
     (((arg_4 != -1 && (arg_5 != 0)) && (iVar1 = FUN_004471f7(arg_3,arg_4), iVar1 == 1)))) {
    local_18 = SaveDC(hdc);
    local_14.left = *arg_2 + ((arg_2[2] - *arg_2) * 0x50) / 100;
    local_14.top = arg_2[1];
    local_14.right = *arg_2 + ((arg_2[2] - *arg_2) * 0x5f) / 100;
    local_14.bottom = arg_2[1] + ((arg_2[3] - arg_2[1]) * 0xe) / 100;
    SetMapMode(hdc,8);
    SetWindowExtEx(hdc,local_14.right - local_14.left,0x14,(LPSIZE)0x0);
    SetViewportExtEx(hdc,local_14.right - local_14.left,local_14.bottom - local_14.top,(LPSIZE)0x0);
    DPtoLP(hdc,(LPPOINT)&local_14,2);
    _sprintf(local_20,&DAT_004f3614,arg_4);
    SelectObject(hdc,DAT_0050af9c);
    if (arg_3 == 0) {
      SetBkColor(hdc,DAT_0050abd4);
    }
    else {
      SetBkColor(hdc,DAT_0050adcc);
    }
    OffsetRect(&local_14,1,1);
    SetTextColor(hdc,DAT_0050ade0);
    SetBkMode(hdc,2);
    DrawTextA(hdc,local_20,-1,&local_14,0x25);
    OffsetRect(&local_14,-1,-1);
    SetTextColor(hdc,DAT_0050add0);
    SetBkMode(hdc,1);
    DrawTextA(hdc,local_20,-1,&local_14,0x25);
    RestoreDC(hdc,local_18);
  }
  return;
}


