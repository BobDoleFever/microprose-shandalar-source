/*
 * Decompiled function: thunk_FUN_10031af5
 * Entry Point: 10001357
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10031af5(int32_t arg_1,LPCSTR str_2,void *arg_3)

{
  char acStack_208 [500];
  int32_t uStack_14;
  HGLOBAL pvStack_10;
  BITMAPINFO *pBStack_c;
  HRSRC pHStack_8;
  
  uStack_14 = 0;
  pHStack_8 = FindResourceA(DAT_101cf334,str_2,(LPCSTR)0x2);
  if (pHStack_8 != (HRSRC)0x0) {
    pvStack_10 = LoadResource(DAT_101cf334,pHStack_8);
    if (pvStack_10 != (HGLOBAL)0x0) {
      pBStack_c = LockResource(pvStack_10);
      if (pBStack_c != (BITMAPINFO *)0x0) {
        uStack_14 = thunk_FUN_10031cb7(pBStack_c,arg_3);
      }
    }
  }
  if (DAT_10176354 != 0) {
    sprintf(acStack_208,s__08X_LoadDIBSection___s__10046674,uStack_14,str_2);
    OutputDebugStringA(acStack_208);
  }
  return uStack_14;
}


