/*
 * Decompiled function: FUN_00511930
 * Entry Point: 00511930
 * Size: 172 bytes
 */
#include "magic.h"


undefined4
FUN_00511930(HDC hdc,COLORREF arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8)

{
  HDC hdc_00;
  HBITMAP h;
  HBRUSH hbr;
  RECT local_10;
  
  local_10.left = 0;
  local_10.top = 0;
  local_10.right = arg_5;
  local_10.bottom = arg_6;
  hdc_00 = CreateCompatibleDC(hdc);
  h = CreateCompatibleBitmap(hdc,arg_5,arg_6);
  hbr = CreateSolidBrush(arg_2);
  SelectObject(hdc_00,h);
  FillRect(hdc_00,&local_10,hbr);
  FUN_005119e0(hdc,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8,hdc_00);
  DeleteDC(hdc_00);
  DeleteObject(hbr);
  DeleteObject(h);
  return 0;
}


