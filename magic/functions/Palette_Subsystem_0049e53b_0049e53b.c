/*
 * Decompiled function: Palette_Subsystem_0049e53b
 * Entry Point: 0049e53b
 * Size: 129 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_0049e53b(HDC hdc,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int nSavedDC;
  
  if (((hdc == (HDC)0x0) || (arg_2 == 0)) || (arg_3 == 0)) {
    uVar1 = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    IntersectClipRect(hdc,0,0,1,1);
    uVar1 = Palette_Subsystem_0049e5bc(hdc,(int *)arg_2,(char *)arg_3,0);
    RestoreDC(hdc,nSavedDC);
  }
  return uVar1;
}


