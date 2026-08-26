/*
 * Decompiled function: __calloc_dbg
 * Entry Point: 004037e0
 * Size: 110 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __calloc_dbg
   
   Library: Visual Studio 1998 Debug */

uint8_t * __cdecl __calloc_dbg(int arg_1,int arg_2,uint32_t arg_3,int arg_4,int32_t arg_5)

{
  uint8_t *u_ptr_1;
  uint8_t *local_10;
  
  u_ptr_1 = (uint8_t *)__malloc_dbg(arg_2 * arg_1,arg_3,arg_4,arg_5);
  if (u_ptr_1 != (uint8_t *)0x0) {
    for (local_10 = u_ptr_1; local_10 < u_ptr_1 + arg_2 * arg_1; local_10 = local_10 + 1) {
      *local_10 = 0;
    }
  }
  return u_ptr_1;
}


