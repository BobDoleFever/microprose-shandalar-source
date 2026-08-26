/*
 * Decompiled function: __expand_base
 * Entry Point: 00407600
 * Size: 195 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __expand_base
   
   Library: Visual Studio 1998 Debug */

uint8_t * __cdecl __expand_base(uint8_t *ptr_1,uint32_t arg_2)

{
  int val_1;
  int local_14;
  uint8_t *local_10;
  uint8_t *local_c;
  int32_t *local_8;
  
  if (arg_2 < 0xffffffe1) {
    if (arg_2 == 0) {
      arg_2 = 0x10;
    }
    else {
      arg_2 = arg_2 + 0xf & 0xfffffff0;
    }
    local_10 = (uint8_t *)___sbh_find_block(ptr_1,&local_14,(uint32_t *)&local_8);
    if (local_10 == (uint8_t *)0x0) {
      local_c = HeapReAlloc(DAT_004156ac,0x10,ptr_1,arg_2);
    }
    else {
      local_c = (uint8_t *)0x0;
      if ((arg_2 <= DAT_004138ac) &&
         (val_1 = ___sbh_resize_block(local_14,local_8,local_10,arg_2 >> 4), val_1 != 0)) {
        local_c = ptr_1;
      }
    }
  }
  else {
    local_c = (uint8_t *)0x0;
  }
  return local_c;
}


