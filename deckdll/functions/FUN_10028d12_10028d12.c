/*
 * Decompiled function: FUN_10028d12
 * Entry Point: 10028d12
 * Size: 221 bytes
 */
#include "deckdll.h"


int FUN_10028d12(HDC hdc,RECT *arg_2,int width,int height)

{
  int val_1;
  HBRUSH hbr;
  int local_8;
  
  if ((hdc == (HDC)0x0) || (arg_2 == (RECT *)0x0)) {
    local_8 = 0;
  }
  else if (width == -1) {
    local_8 = 0;
  }
  else if (*(int *)(&DAT_10176af4 + width * 0x98) < 2) {
    val_1 = thunk_FUN_10028c81(width,height);
    if (val_1 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = thunk_FUN_1003162f((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_10162910 + width * 0x10));
    }
    if (local_8 == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  else {
    local_8 = thunk_FUN_1002929b(hdc,arg_2,width,height);
  }
  return local_8;
}


