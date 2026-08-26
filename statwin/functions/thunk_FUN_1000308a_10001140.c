/*
 * Decompiled function: thunk_FUN_1000308a
 * Entry Point: 10001140
 * Size: 5 bytes
 */
#include "statwin.h"


void __cdecl thunk_FUN_1000308a(int32_t arg_1)

{
  int32_t uStack_28;
  int32_t uStack_24;
  int32_t uStack_20;
  uint32_t uStack_c;
  int32_t uStack_8;
  
  if (DAT_1001178c != 0) {
    uStack_8 = thunk_FUN_10001c1a();
    memset(&uStack_28,0,0x20);
    uStack_24 = 0;
    uStack_28 = 400;
    uStack_20 = 0;
    uStack_c = uStack_c | 5;
    thunk_FUN_10001685(arg_1,0xff,&uStack_28);
    thunk_FUN_10001722(0xff,&uStack_28);
  }
  return;
}


