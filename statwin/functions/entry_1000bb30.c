/*
 * Decompiled function: entry
 * Entry Point: 1000bb30
 * Size: 313 bytes
 */
#include "statwin.h"


int entry(HINSTANCE hInstance,int arg_2,int32_t arg_3)

{
  int val_1;
  int local_8;
  
  local_8 = 1;
  if ((arg_2 == 0) && (DAT_10013020 == 0)) {
    local_8 = 0;
  }
  else {
    if ((arg_2 == 1) || (arg_2 == 2)) {
      if (DAT_1001e92c != (code *)0x0) {
        local_8 = (*DAT_1001e92c)(hInstance,arg_2,arg_3);
      }
      if (local_8 != 0) {
        local_8 = __CRT_INIT_12(hInstance,arg_2);
      }
      if (local_8 == 0) {
        return 0;
      }
    }
    local_8 = thunk_FUN_10001f30(hInstance,arg_2);
    if ((arg_2 == 1) && (local_8 == 0)) {
      __CRT_INIT_12(hInstance,0);
    }
    if ((arg_2 == 0) || (arg_2 == 3)) {
      val_1 = __CRT_INIT_12(hInstance,arg_2);
      if (val_1 == 0) {
        local_8 = 0;
      }
      if ((local_8 != 0) && (DAT_1001e92c != (code *)0x0)) {
        local_8 = (*DAT_1001e92c)(hInstance,arg_2,arg_3);
      }
    }
  }
  return local_8;
}


