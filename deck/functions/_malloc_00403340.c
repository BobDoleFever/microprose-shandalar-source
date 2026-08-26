/*
 * Decompiled function: _malloc
 * Entry Point: 00403340
 * Size: 40 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl _malloc(size_t arg_1)

{
  int32_t *u_ptr_1;
  
  u_ptr_1 = __nh_malloc_dbg(arg_1,DAT_004138f8,1,0,0);
  return u_ptr_1;
}


