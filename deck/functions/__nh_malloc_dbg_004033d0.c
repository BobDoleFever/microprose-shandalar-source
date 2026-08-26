/*
 * Decompiled function: __nh_malloc_dbg
 * Entry Point: 004033d0
 * Size: 101 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __nh_malloc_dbg
   
   Library: Visual Studio 1998 Debug */

int32_t * __cdecl __nh_malloc_dbg(uint32_t arg_1,int arg_2,uint32_t arg_3,int arg_4,int32_t arg_5)

{
  int32_t *u_ptr_1;
  int val_2;
  
  while( true ) {
    u_ptr_1 = __heap_alloc_dbg(arg_1,arg_3,arg_4,arg_5);
    if (u_ptr_1 != (int32_t *)0x0) {
      return u_ptr_1;
    }
    if (arg_2 == 0) break;
    val_2 = __callnewh(arg_1);
    if (val_2 == 0) {
      return (int32_t *)0x0;
    }
  }
  return (int32_t *)0x0;
}


