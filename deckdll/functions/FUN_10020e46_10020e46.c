/*
 * Decompiled function: FUN_10020e46
 * Entry Point: 10020e46
 * Size: 153 bytes
 */
#include "deckdll.h"


void FUN_10020e46(HDC hdc,int *arg2)

{
  HBRUSH h;
  HGDIOBJ buf_ptr_1;
  
  SetROP2(hdc,0xd);
  h = CreateHatchBrush(3,0x808080);
  SetBkMode(hdc,1);
  SelectObject(hdc,h);
  buf_ptr_1 = GetStockObject(8);
  SelectObject(hdc,buf_ptr_1);
  Rectangle(hdc,*arg2,arg2[1],arg2[2],arg2[3]);
  buf_ptr_1 = GetStockObject(0);
  SelectObject(hdc,buf_ptr_1);
  DeleteObject(h);
  return;
}


