/*
 * Decompiled function: get_int_arg
 * Entry Point: 00409740
 * Size: 30 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _get_int_arg
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl get_int_arg(int *ptr_1)

{
  *ptr_1 = *ptr_1 + 4;
  return *(int32_t *)(*ptr_1 + -4);
}


