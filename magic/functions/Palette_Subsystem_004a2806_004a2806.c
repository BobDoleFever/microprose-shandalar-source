/*
 * Decompiled function: Palette_Subsystem_004a2806
 * Entry Point: 004a2806
 * Size: 153 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a2806(HDC hdc,int *arg2)

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


