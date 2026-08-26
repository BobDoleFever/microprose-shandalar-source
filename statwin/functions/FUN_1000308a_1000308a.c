/*
 * Decompiled function: FUN_1000308a
 * Entry Point: 1000308a
 * Size: 133 bytes
 */
#include "statwin.h"


void __cdecl FUN_1000308a(int32_t arg_1)

{
  int32_t local_28;
  int32_t local_24;
  int32_t local_20;
  uint32_t local_c;
  int32_t local_8;
  
  if (DAT_1001178c != 0) {
    local_8 = thunk_FUN_10001c1a();
    memset(&local_28,0,0x20);
    local_24 = 0;
    local_28 = 400;
    local_20 = 0;
    local_c = local_c | 5;
    thunk_FUN_10001685(arg_1,0xff,&local_28);
    thunk_FUN_10001722(0xff,&local_28);
  }
  return;
}


