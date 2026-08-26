/*
 * Decompiled function: thunk_FUN_1001cb7b
 * Entry Point: 100012a3
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1001cb7b(HDC hdc,int arg_2,int arg_3)

{
  int32_t uval_1;
  int nSavedDC;
  
  if (((hdc == (HDC)0x0) || (arg_2 == 0)) || (arg_3 == 0)) {
    uval_1 = 0;
  }
  else {
    nSavedDC = SaveDC(hdc);
    IntersectClipRect(hdc,0,0,1,1);
    uval_1 = thunk_FUN_1001cbfc(hdc,(int *)arg_2,(char *)arg_3,0);
    RestoreDC(hdc,nSavedDC);
  }
  return uval_1;
}


