/*
 * Decompiled function: __msize
 * Entry Point: 00404310
 * Size: 30 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __msize
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl __msize(void *ptr_1)

{
  size_t len_1;
  
  len_1 = __msize_dbg((int)ptr_1,1);
  return len_1;
}


