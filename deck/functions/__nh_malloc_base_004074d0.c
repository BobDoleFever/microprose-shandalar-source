/*
 * Decompiled function: __nh_malloc_base
 * Entry Point: 004074d0
 * Size: 150 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __nh_malloc_base
   
   Library: Visual Studio 1998 Debug */

uint8_t * __cdecl __nh_malloc_base(uint32_t arg1,int arg2)

{
  int val_1;
  uint8_t *local_8;
  
  if (arg1 < 0xffffffe1) {
    if (arg1 == 0) {
      arg1 = 1;
    }
    do {
      if (arg1 < 0xffffffe1) {
        local_8 = __heap_alloc_base(arg1);
      }
      else {
        local_8 = (uint8_t *)0x0;
      }
      if (local_8 != (uint8_t *)0x0) {
        return local_8;
      }
      if (arg2 == 0) {
        return (uint8_t *)0x0;
      }
      val_1 = __callnewh(arg1);
    } while (val_1 != 0);
  }
  return (uint8_t *)0x0;
}


