/*
 * Decompiled function: _calloc
 * Entry Point: 004037b0
 * Size: 38 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _calloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl _calloc(size_t arg_1,size_t arg_2)

{
  uint8_t *u_ptr_1;
  
  u_ptr_1 = __calloc_dbg(arg_1,arg_2,1,0,0);
  return u_ptr_1;
}


