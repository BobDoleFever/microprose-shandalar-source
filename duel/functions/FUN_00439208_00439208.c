/*
 * Decompiled function: FUN_00439208
 * Entry Point: 00439208
 * Size: 235 bytes
 */
#include "duel.h"


int FUN_00439208(HDC hdc,RECT *arg_2,int width,int height)

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
    while ((local_c < DAT_00663df8 && (!bVar1))) {
      if ((*(int *)(&DAT_00616a20 + local_c * 0x18) == width) &&
         (*(int *)(&DAT_00616a24 + local_c * 0x18) == height)) {
        bVar1 = true;
        local_10 = local_c;
      }
      local_c = local_c + 1;
    }
    if (bVar1) {
      local_14 = FUN_004709ae((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_00616a10 + local_10 * 0x18));
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


