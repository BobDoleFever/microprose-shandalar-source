/*
 * Decompiled function: FUN_10007dbf
 * Entry Point: 10007dbf
 * Size: 710 bytes
 */
#include "deckdll.h"


void FUN_10007dbf(HDC hdc,RECT *arg_2,char *str_3)

{
  size_t len_1;
  DWORD DVar2;
  tagSIZE *lpsz;
  tagSIZE local_28;
  tagRECT local_20;
  int local_10;
  HPEN local_c;
  HPEN local_8;
  
  CopyRect(&local_20,arg_2);
  lpsz = &local_28;
  len_1 = strlen(str_3);
  GetTextExtentPointA(hdc,str_3,len_1,lpsz);
  DVar2 = GetSysColor(0x10);
  local_8 = CreatePen(0,1,DVar2);
  DVar2 = GetSysColor(0x16);
  local_c = CreatePen(0,1,DVar2);
  local_10 = SaveDC(hdc);
  SetBkMode(hdc,1);
  OffsetRect(&local_20,1,1);
  DVar2 = GetSysColor(0x16);
  SetTextColor(hdc,DVar2);
  SelectObject(hdc,local_c);
  MoveToEx(hdc,local_20.left,local_20.top + local_28.cy / 2,(LPPOINT)0x0);
  LineTo(hdc,local_20.left + 10,local_20.top + local_28.cy / 2);
  len_1 = strlen(str_3);
  TextOutA(hdc,local_20.left + 0xe,local_20.top,str_3,len_1);
  MoveToEx(hdc,local_20.left + local_28.cx + 0x12,local_20.top + local_28.cy / 2,(LPPOINT)0x0);
  LineTo(hdc,local_20.right,local_20.top + local_28.cy / 2);
  LineTo(hdc,local_20.right,local_20.bottom);
  LineTo(hdc,local_20.left,local_20.bottom);
  LineTo(hdc,local_20.left,local_20.top + local_28.cy / 2);
  OffsetRect(&local_20,-1,-1);
  DVar2 = GetSysColor(0x10);
  SetTextColor(hdc,DVar2);
  SelectObject(hdc,local_8);
  MoveToEx(hdc,local_20.left,local_20.top + local_28.cy / 2,(LPPOINT)0x0);
  LineTo(hdc,local_20.left + 10,local_20.top + local_28.cy / 2);
  len_1 = strlen(str_3);
  TextOutA(hdc,local_20.left + 0xe,local_20.top,str_3,len_1);
  MoveToEx(hdc,local_20.left + local_28.cx + 0x12,local_20.top + local_28.cy / 2,(LPPOINT)0x0);
  LineTo(hdc,local_20.right,local_20.top + local_28.cy / 2);
  LineTo(hdc,local_20.right,local_20.bottom);
  LineTo(hdc,local_20.left,local_20.bottom);
  LineTo(hdc,local_20.left,local_20.top + local_28.cy / 2);
  RestoreDC(hdc,local_10);
  DeleteObject(local_8);
  DeleteObject(local_c);
  return;
}


