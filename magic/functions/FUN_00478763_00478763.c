/*
 * Decompiled function: FUN_00478763
 * Entry Point: 00478763
 * Size: 236 bytes
 */
#include "magic.h"


int FUN_00478763(HDC hdc,RECT *arg_2,int width,int height)

{
  bool bVar1;
  HBRUSH hbr;
  int local_14;
  int local_10;
  int local_c;
  
  if (width == -1) {
    local_14 = 0;
  }
  else {
    local_c = 0;
    bVar1 = false;
    while ((local_c < DAT_00680778 && (!bVar1))) {
      if (((&DAT_006fefc0)[local_c * 6] == width) && ((&DAT_006fefc4)[local_c * 6] == height)) {
        bVar1 = true;
        local_10 = local_c;
      }
      local_c = local_c + 1;
    }
    if (bVar1) {
      local_14 = FUN_004f3b5f((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_006fefb0 + local_10 * 0x18));
    }
    else {
      local_14 = 0;
    }
    if (local_14 == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  return local_14;
}


