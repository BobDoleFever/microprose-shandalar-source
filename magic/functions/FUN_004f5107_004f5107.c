/*
 * Decompiled function: FUN_004f5107
 * Entry Point: 004f5107
 * Size: 974 bytes
 */
#include "magic.h"


void FUN_004f5107(int arg_1,HBRUSH arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4,COLORREF arg_5,int arg_6)

{
  HDC hdc;
  HGDIOBJ h;
  size_t c;
  tagSIZE *psizl;
  RECT local_64;
  HGDIOBJ local_54;
  tagRECT local_50;
  CHAR local_40 [52];
  tagSIZE local_c;
  
  hdc = *(HDC *)(arg_1 + 0x18);
  CopyRect(&local_50,(RECT *)(arg_1 + 0x1c));
  GetWindowTextA(*(HWND *)(arg_1 + 0x14),local_40,0x32);
  FUN_004f3955(hdc);
  OffsetRect(&local_50,-*(int *)(arg_1 + 0x1c),-*(int *)(arg_1 + 0x20));
  if ((*(byte *)(arg_1 + 0x10) & 1) == 0) {
    FillRect(hdc,&local_50,arg_2);
    SelectObject(hdc,arg_3);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,0);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,0,local_50.bottom);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,1);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,1,local_50.bottom + -1);
    SelectObject(hdc,arg_4);
    MoveToEx(hdc,local_50.right + -1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,local_50.bottom);
    MoveToEx(hdc,1,local_50.bottom + -1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,local_50.bottom + -1);
    MoveToEx(hdc,local_50.right + -2,2,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -2,local_50.bottom + -1);
    MoveToEx(hdc,2,local_50.bottom + -2,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,local_50.bottom + -2);
  }
  else {
    FillRect(hdc,&local_50,arg_2);
    h = GetStockObject(7);
    SelectObject(hdc,h);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,0);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,0,local_50.bottom);
    SelectObject(hdc,arg_4);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,1);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,1,local_50.bottom + -1);
    SelectObject(hdc,arg_3);
    MoveToEx(hdc,local_50.right + -1,1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right + -1,local_50.bottom);
    MoveToEx(hdc,1,local_50.bottom + -1,(LPPOINT)0x0);
    LineTo(hdc,local_50.right,local_50.bottom + -1);
    OffsetRect(&local_50,2,2);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,arg_5);
  local_54 = (HGDIOBJ)SendMessageA(*(HWND *)(arg_1 + 0x14),0x31,0,0);
  SelectObject(hdc,local_54);
  DrawTextA(hdc,local_40,-1,&local_50,0x25);
  if ((arg_6 != 0) && ((*(byte *)(arg_1 + 0x10) & 0x10) != 0)) {
    psizl = &local_c;
    c = strlen(local_40);
    GetTextExtentPoint32A(hdc,local_40,c,psizl);
    local_64.left = ((local_50.right - local_50.left) / 2 - local_c.cx / 2) + -3;
    local_64.right = local_c.cx + local_64.left + 6;
    local_64.top = ((local_50.bottom - local_50.top) / 2 - local_c.cy / 2) + -3;
    local_64.bottom = local_c.cy + local_64.top + 6;
    DrawFocusRect(hdc,&local_64);
  }
  return;
}


