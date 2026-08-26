/*
 * Decompiled function: __heap_alloc
 * Entry Point: 00403440
 * Size: 34 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl __heap_alloc(size_t arg_1)

{
  int32_t *u_ptr_1;
  
  u_ptr_1 = __heap_alloc_dbg(arg_1,1,0,0);
  return u_ptr_1;
}


