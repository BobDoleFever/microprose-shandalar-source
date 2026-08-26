/*
 * Decompiled function: thunk_FUN_10028d12
 * Entry Point: 10001780
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10028d12(HDC hdc,RECT *arg_2,int width,int height)

{
  int val_1;
  HBRUSH hbr;
  int iStack_8;
  
  if ((hdc == (HDC)0x0) || (arg_2 == (RECT *)0x0)) {
    iStack_8 = 0;
  }
  else if (width == -1) {
    iStack_8 = 0;
  }
  else if (*(int *)(&DAT_10176af4 + width * 0x98) < 2) {
    val_1 = thunk_FUN_10028c81(width,height);
    if (val_1 == 0) {
      iStack_8 = 0;
    }
    else {
      iStack_8 = thunk_FUN_1003162f((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_10162910 + width * 0x10));
    }
    if (iStack_8 == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  else {
    iStack_8 = thunk_FUN_1002929b(hdc,arg_2,width,height);
  }
  return iStack_8;
}


