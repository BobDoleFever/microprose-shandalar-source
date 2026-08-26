/*
 * Decompiled function: FUN_10003677
 * Entry Point: 10003677
 * Size: 295 bytes
 */
#include "statwin.h"


int32_t FUN_10003677(HWND hwnd,int arg_2,uint16_t arg_3)

{
  if (arg_2 == 0x110) {
    DAT_100117c8 = 1;
    return 1;
  }
  if (arg_2 == 0x111) {
    if (arg_3 < 0x3eb) {
      if (arg_3 == 0x3ea) {
        DAT_1001154c = 0;
        return 1;
      }
      if (arg_3 == 1) {
        EndDialog(hwnd,1);
        DAT_100117c8 = 0;
        return 1;
      }
      if (arg_3 == 2) {
        EndDialog(hwnd,1);
        DAT_100117c8 = 0;
        return 1;
      }
    }
    else if (arg_3 == 0x3eb) {
      DAT_1001154c = 1;
      return 1;
    }
  }
  else if (arg_2 == 0x3b9) {
    return 1;
  }
  return 0;
}


