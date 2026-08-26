/*
 * Decompiled function: thunk_FUN_10032bd7
 * Entry Point: 100014d8
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10032bd7(int arg_1,HBRUSH arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4,COLORREF arg_5,int arg_6)

{
  HDC hdc;
  HGDIOBJ h;
  size_t c;
  tagSIZE *psizl;
  RECT RStack_64;
  HGDIOBJ pvStack_54;
  tagRECT tStack_50;
  CHAR aCStack_40 [52];
  tagSIZE tStack_c;
  
  hdc = *(HDC *)(arg_1 + 0x18);
  CopyRect(&tStack_50,(RECT *)(arg_1 + 0x1c));
  GetWindowTextA(*(HWND *)(arg_1 + 0x14),aCStack_40,0x32);
  thunk_FUN_10031425(hdc);
  OffsetRect(&tStack_50,-*(int *)(arg_1 + 0x1c),-*(int *)(arg_1 + 0x20));
  if ((*(uint8_t *)(arg_1 + 0x10) & 1) == 0) {
    FillRect(hdc,&tStack_50,arg_2);
    SelectObject(hdc,arg_3);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right,0);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,0,tStack_50.bottom);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right + -1,1);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,1,tStack_50.bottom + -1);
    SelectObject(hdc,arg_4);
    MoveToEx(hdc,tStack_50.right + -1,1,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right + -1,tStack_50.bottom);
    MoveToEx(hdc,1,tStack_50.bottom + -1,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right,tStack_50.bottom + -1);
    MoveToEx(hdc,tStack_50.right + -2,2,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right + -2,tStack_50.bottom + -1);
    MoveToEx(hdc,2,tStack_50.bottom + -2,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right + -1,tStack_50.bottom + -2);
  }
  else {
    FillRect(hdc,&tStack_50,arg_2);
    h = GetStockObject(7);
    SelectObject(hdc,h);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right,0);
    MoveToEx(hdc,0,0,(LPPOINT)0x0);
    LineTo(hdc,0,tStack_50.bottom);
    SelectObject(hdc,arg_4);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right + -1,1);
    MoveToEx(hdc,1,1,(LPPOINT)0x0);
    LineTo(hdc,1,tStack_50.bottom + -1);
    SelectObject(hdc,arg_3);
    MoveToEx(hdc,tStack_50.right + -1,1,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right + -1,tStack_50.bottom);
    MoveToEx(hdc,1,tStack_50.bottom + -1,(LPPOINT)0x0);
    LineTo(hdc,tStack_50.right,tStack_50.bottom + -1);
    OffsetRect(&tStack_50,2,2);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,arg_5);
  pvStack_54 = (HGDIOBJ)SendMessageA(*(HWND *)(arg_1 + 0x14),0x31,0,0);
  SelectObject(hdc,pvStack_54);
  DrawTextA(hdc,aCStack_40,-1,&tStack_50,0x25);
  if ((arg_6 != 0) && ((*(uint8_t *)(arg_1 + 0x10) & 0x10) != 0)) {
    psizl = &tStack_c;
    c = strlen(aCStack_40);
    GetTextExtentPoint32A(hdc,aCStack_40,c,psizl);
    RStack_64.left = ((tStack_50.right - tStack_50.left) / 2 - tStack_c.cx / 2) + -3;
    RStack_64.right = tStack_c.cx + RStack_64.left + 6;
    RStack_64.top = ((tStack_50.bottom - tStack_50.top) / 2 - tStack_c.cy / 2) + -3;
    RStack_64.bottom = tStack_c.cy + RStack_64.top + 6;
    DrawFocusRect(hdc,&RStack_64);
  }
  return;
}


