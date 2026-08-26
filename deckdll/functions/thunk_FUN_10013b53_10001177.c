/*
 * Decompiled function: thunk_FUN_10013b53
 * Entry Point: 10001177
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10013b53(HDC hdc,RECT *arg_2,int width,int height)

{
  bool flag_1;
  HBRUSH hbr;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  if (width == -1) {
    iStack_14 = 0;
  }
  else {
    iStack_c = 0;
    flag_1 = false;
    while ((iStack_c < DAT_10158728 && (!flag_1))) {
      if (((&DAT_101cf600)[iStack_c * 6] == width) && ((&DAT_101cf604)[iStack_c * 6] == height)) {
        flag_1 = true;
        iStack_10 = iStack_c;
      }
      iStack_c = iStack_c + 1;
    }
    if (flag_1) {
      iStack_14 = thunk_FUN_1003162f((int)hdc,(int)arg_2,
                                     *(HANDLE *)(&DAT_101cf5f0 + iStack_10 * 0x18));
    }
    else {
      iStack_14 = 0;
    }
    if (iStack_14 == 0) {
      hbr = GetStockObject(2);
      FillRect(hdc,arg_2,hbr);
    }
  }
  return iStack_14;
}


