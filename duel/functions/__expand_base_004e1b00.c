/*
 * Decompiled function: __expand_base
 * Entry Point: 004e1b00
 * Size: 195 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __expand_base
   
   Library: Visual Studio 1998 Debug */

LPVOID __expand_base(LPVOID arg1,uint arg2)

{
  int iVar1;
  int local_14;
  byte *local_10;
  LPVOID local_c;
  undefined4 *local_8;
  
  if (arg2 < 0xffffffe1) {
    if (arg2 == 0) {
      arg2 = 0x10;
    }
    else {
      arg2 = arg2 + 0xf & 0xfffffff0;
    }
    local_10 = (byte *)___sbh_find_block(arg1,&local_14,(uint *)&local_8);
    if (local_10 == (byte *)0x0) {
      local_c = HeapReAlloc(DAT_006c1c94,0x10,arg1,arg2);
    }
    else {
      local_c = (LPVOID)0x0;
      if ((arg2 <= DAT_0050a1fc) &&
         (iVar1 = ___sbh_resize_block(local_14,local_8,local_10,arg2 >> 4), iVar1 != 0)) {
        local_c = arg1;
      }
    }
  }
  else {
    local_c = (LPVOID)0x0;
  }
  return local_c;
}


