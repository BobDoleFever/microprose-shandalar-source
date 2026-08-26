/*
 * Decompiled function: FID_conflict:__expand
 * Entry Point: 00403850
 * Size: 38 bytes
 */
#include "deck.h"


/* Library Function - Multiple Matches With Different Base Names
    __expand
    _realloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl FID_conflict___expand(void *ptr_1,size_t arg_2)

{
  int *i_ptr_1;
  
  i_ptr_1 = __realloc_dbg(ptr_1,arg_2,1,0,0);
  return i_ptr_1;
}


