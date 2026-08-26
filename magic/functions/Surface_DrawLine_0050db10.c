/*
 * Decompiled function: Surface_DrawLine
 * Entry Point: 0050db10
 * Size: 157 bytes
 */
#include "magic.h"


void Surface_DrawLine(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  int iVar1;
  HPEN h;
  HGDIOBJ h_00;
  COLORREF color;
  
  iVar1 = (&DAT_0070a850)[*arg_1];
  if (arg_6 < 0) {
    color = -arg_6;
  }
  else {
    color = (uint)(byte)(&DAT_0070a451)[arg_6 * 4] << 8 |
            (uint)(byte)(&DAT_0070a452)[arg_6 * 4] << 0x10 | (uint)(byte)(&DAT_0070a450)[arg_6 * 4];
  }
  h = CreatePen(0,1,color);
  h_00 = SelectObject(*(HDC *)(iVar1 + 4),h);
  MoveToEx(*(HDC *)(iVar1 + 4),arg_2,arg_3,(LPPOINT)0x0);
  LineTo(*(HDC *)(iVar1 + 4),arg_4,arg_5);
  SelectObject(*(HDC *)(iVar1 + 4),h_00);
  DeleteObject(h);
  return;
}


