/*
 * Decompiled function: FUN_004222b9
 * Entry Point: 004222b9
 * Size: 129 bytes
 */
#include "duel.h"


undefined4 FUN_004222b9(HDC hdc,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int nSavedDC;
  
  if (((hdc == (HDC)0x0) || (arg_2 == 0)) || (arg_3 == 0)) {
    uVar1 = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    IntersectClipRect(hdc,0,0,1,1);
    uVar1 = FUN_0042233a(hdc,(int *)arg_2,(char *)arg_3,0);
    RestoreDC(hdc,nSavedDC);
  }
  return uVar1;
}


