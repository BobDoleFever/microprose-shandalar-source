/*
 * Decompiled function: FUN_1002929b
 * Entry Point: 1002929b
 * Size: 235 bytes
 */
#include "deckdll.h"


int FUN_1002929b(HDC hdc,RECT *arg_2,int width,int height)

{
  bool flag_1;
  HBRUSH hbr;
  int local_14;
  int local_10;
  int local_c;
  
  if (width == -1) {
    local_14 = 0;
  }
  else {
    local_c = 0;
    flag_1 = false;
    while ((local_c < DAT_101cdeb0 && (!flag_1))) {
      if ((*(int *)(&DAT_10175570 + local_c * 0x18) == width) &&
         (*(int *)(&DAT_10175574 + local_c * 0x18) == height)) {
        flag_1 = true;
        local_10 = local_c;
      }
      local_c = local_c + 1;
    }
    if (flag_1) {
      local_14 = thunk_FUN_1003162f((int)hdc,(int)arg_2,*(HANDLE *)(&DAT_10175560 + local_10 * 0x18)
                                   );
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


