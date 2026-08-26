/*
 * Decompiled function: entry
 * Entry Point: 10007190
 * Size: 313 bytes
 */
#include "magsnd.h"


int entry(HMODULE arg_1,int arg_2,int32_t arg_3)

{
  int val_1;
  int local_8;
  
  local_8 = 1;
  if ((arg_2 == 0) && (DAT_1000a530 == 0)) {
    local_8 = 0;
  }
  else {
    if ((arg_2 == 1) || (arg_2 == 2)) {
      if (DAT_1000bf70 != (code *)0x0) {
        local_8 = (*DAT_1000bf70)(arg_1,arg_2,arg_3);
      }
      if (local_8 != 0) {
        local_8 = __CRT_INIT_12(arg_1,arg_2);
      }
      if (local_8 == 0) {
        return 0;
      }
    }
    local_8 = _DllMain_12(arg_1,arg_2);
    if ((arg_2 == 1) && (local_8 == 0)) {
      __CRT_INIT_12(arg_1,0);
    }
    if ((arg_2 == 0) || (arg_2 == 3)) {
      val_1 = __CRT_INIT_12(arg_1,arg_2);
      if (val_1 == 0) {
        local_8 = 0;
      }
      if ((local_8 != 0) && (DAT_1000bf70 != (code *)0x0)) {
        local_8 = (*DAT_1000bf70)(arg_1,arg_2,arg_3);
      }
    }
  }
  return local_8;
}


