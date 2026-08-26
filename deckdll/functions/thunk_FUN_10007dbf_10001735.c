/*
 * Decompiled function: thunk_FUN_10007dbf
 * Entry Point: 10001735
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10007dbf(HDC hdc,RECT *arg_2,char *str_3)

{
  size_t len_1;
  DWORD DVar2;
  tagSIZE *lpsz;
  tagSIZE tStack_28;
  tagRECT tStack_20;
  int iStack_10;
  HPEN pHStack_c;
  HPEN pHStack_8;
  
  CopyRect(&tStack_20,arg_2);
  lpsz = &tStack_28;
  len_1 = strlen(str_3);
  GetTextExtentPointA(hdc,str_3,len_1,lpsz);
  DVar2 = GetSysColor(0x10);
  pHStack_8 = CreatePen(0,1,DVar2);
  DVar2 = GetSysColor(0x16);
  pHStack_c = CreatePen(0,1,DVar2);
  iStack_10 = SaveDC(hdc);
  SetBkMode(hdc,1);
  OffsetRect(&tStack_20,1,1);
  DVar2 = GetSysColor(0x16);
  SetTextColor(hdc,DVar2);
  SelectObject(hdc,pHStack_c);
  MoveToEx(hdc,tStack_20.left,tStack_20.top + tStack_28.cy / 2,(LPPOINT)0x0);
  LineTo(hdc,tStack_20.left + 10,tStack_20.top + tStack_28.cy / 2);
  len_1 = strlen(str_3);
  TextOutA(hdc,tStack_20.left + 0xe,tStack_20.top,str_3,len_1);
  MoveToEx(hdc,tStack_20.left + tStack_28.cx + 0x12,tStack_20.top + tStack_28.cy / 2,(LPPOINT)0x0);
  LineTo(hdc,tStack_20.right,tStack_20.top + tStack_28.cy / 2);
  LineTo(hdc,tStack_20.right,tStack_20.bottom);
  LineTo(hdc,tStack_20.left,tStack_20.bottom);
  LineTo(hdc,tStack_20.left,tStack_20.top + tStack_28.cy / 2);
  OffsetRect(&tStack_20,-1,-1);
  DVar2 = GetSysColor(0x10);
  SetTextColor(hdc,DVar2);
  SelectObject(hdc,pHStack_8);
  MoveToEx(hdc,tStack_20.left,tStack_20.top + tStack_28.cy / 2,(LPPOINT)0x0);
  LineTo(hdc,tStack_20.left + 10,tStack_20.top + tStack_28.cy / 2);
  len_1 = strlen(str_3);
  TextOutA(hdc,tStack_20.left + 0xe,tStack_20.top,str_3,len_1);
  MoveToEx(hdc,tStack_20.left + tStack_28.cx + 0x12,tStack_20.top + tStack_28.cy / 2,(LPPOINT)0x0);
  LineTo(hdc,tStack_20.right,tStack_20.top + tStack_28.cy / 2);
  LineTo(hdc,tStack_20.right,tStack_20.bottom);
  LineTo(hdc,tStack_20.left,tStack_20.bottom);
  LineTo(hdc,tStack_20.left,tStack_20.top + tStack_28.cy / 2);
  RestoreDC(hdc,iStack_10);
  DeleteObject(pHStack_8);
  DeleteObject(pHStack_c);
  return;
}


