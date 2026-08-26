/*
 * Decompiled function: FUN_00438c81
 * Entry Point: 00438c81
 * Size: 221 bytes
 */
#include "duel.h"


int FUN_00438c81(HDC hdc,RECT *arg_2,int width,int arg_4)

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
  else if (*(int *)(&DAT_00618b04 + width * 0x98) < 2) {
    iVar1 = FUN_00438bf0(width,arg_4);
    if (iVar1 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_004709ae((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_0060d5b0 + width * 0x10));
    }
    if (local_8 == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  else {
    local_8 = FUN_00439208(hdc,arg_2,width,arg_4);
  }
  return local_8;
}


