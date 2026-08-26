/*
 * Decompiled function: __nh_malloc
 * Entry Point: 004033a0
 * Size: 38 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl __nh_malloc(size_t arg_1,int arg_2)

{
  int32_t *u_ptr_1;
  
  u_ptr_1 = __nh_malloc_dbg(arg_1,arg_2,1,0,0);
  return u_ptr_1;
}


