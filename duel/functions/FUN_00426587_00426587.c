/*
 * Decompiled function: FUN_00426587
 * Entry Point: 00426587
 * Size: 153 bytes
 */
#include "duel.h"


void FUN_00426587(HDC hdc,int *arg2)

{
  HBRUSH h;
  HGDIOBJ pvVar1;
  
  SetROP2(hdc,0xd);
  h = CreateHatchBrush(3,0x808080);
  SetBkMode(hdc,1);
  SelectObject(hdc,h);
  pvVar1 = GetStockObject(8);
  SelectObject(hdc,pvVar1);
  Rectangle(hdc,*arg2,arg2[1],arg2[2],arg2[3]);
  pvVar1 = GetStockObject(0);
  SelectObject(hdc,pvVar1);
  DeleteObject(h);
  return;
}


