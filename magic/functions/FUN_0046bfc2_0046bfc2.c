/*
 * Decompiled function: FUN_0046bfc2
 * Entry Point: 0046bfc2
 * Size: 221 bytes
 */
#include "magic.h"


int FUN_0046bfc2(HDC hdc,RECT *arg_2,int width,int arg_4)

{
  int iVar1;
  HBRUSH hbr;
  int local_8;
  
  if ((hdc == (HDC)0x0) || (arg_2 == (RECT *)0x0)) {
    local_8 = 0;
  }
  else if (width == -1) {
    local_8 = 0;
  }
  else if (*(int *)(&DAT_006b30b4 + width * 0x98) < 2) {
    iVar1 = FUN_0046bf31(width,arg_4);
    if (iVar1 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_004f3b5f((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_00696a20 + width * 0x10));
    }
    if (local_8 == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  else {
    local_8 = FUN_0046c54b(hdc,arg_2,width,arg_4);
  }
  return local_8;
}


