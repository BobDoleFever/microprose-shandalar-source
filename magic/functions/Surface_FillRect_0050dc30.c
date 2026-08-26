/*
 * Decompiled function: Surface_FillRect
 * Entry Point: 0050dc30
 * Size: 176 bytes
 */
#include "magic.h"


void Surface_FillRect(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,uint arg_6)

{
  int iVar1;
  COLORREF color;
  uint uVar2;
  HBRUSH hbr;
  RECT local_10;
  
  local_10.left = arg_2;
  local_10.right = arg_2 + arg_4;
  local_10.top = arg_3;
  local_10.bottom = arg_5 + arg_3;
  iVar1 = (&DAT_0070a850)[*arg_1];
  if ((int)arg_6 < 0) {
    uVar2 = -arg_6;
    color = 0xffffff;
    if (arg_6 != 0xff000001) {
      color = ((uVar2 & 0xffff) >> 8 | 0x20000) << 8 | (uVar2 >> 0x10 & 0xff) << 0x10 | uVar2 & 0xff
      ;
    }
  }
  else if (arg_6 == 0xff) {
    color = 0xffffff;
  }
  else {
    color = arg_6 & 0xffff | 0x1000000;
  }
  hbr = CreateSolidBrush(color);
  FillRect(*(HDC *)(iVar1 + 4),&local_10,hbr);
  DeleteObject(hbr);
  return;
}


