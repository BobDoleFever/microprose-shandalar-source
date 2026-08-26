/*
 * Decompiled function: FUN_10021005
 * Entry Point: 10021005
 * Size: 150 bytes
 */
#include "deckdll.h"


void FUN_10021005(HDC hdc,int *arg_2,int arg_3)

{
  HPEN h;
  int nSavedDC;
  HGDIOBJ h_00;
  
  h = CreatePen(6,3,DAT_1013e5f0);
  if (arg_3 != 0) {
    nSavedDC = SaveDC(hdc);
    SelectObject(hdc,h);
    h_00 = GetStockObject(5);
    SelectObject(hdc,h_00);
    Rectangle(hdc,*arg_2,arg_2[1],arg_2[2],arg_2[3]);
    RestoreDC(hdc,nSavedDC);
  }
  DeleteObject(h);
  return;
}


