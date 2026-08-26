/*
 * Decompiled function: __realloc_dbg
 * Entry Point: 00403880
 * Size: 55 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __realloc_dbg
   
   Library: Visual Studio 1998 Debug */

int * __cdecl __realloc_dbg(void *ptr_1,uint32_t arg_2,uint32_t arg_3,int arg_4,int arg_5)

{
  int *i_ptr_1;
  
  i_ptr_1 = realloc_help(ptr_1,arg_2,arg_3,arg_4,arg_5,1);
  return i_ptr_1;
}


