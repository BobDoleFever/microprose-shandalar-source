/*
 * Decompiled function: get_short_arg
 * Entry Point: 00409790
 * Size: 31 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _get_short_arg
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl get_short_arg(int *ptr_1)

{
  *ptr_1 = *ptr_1 + 4;
  return CONCAT22((short)((uint32_t)*ptr_1 >> 0x10),*(int16_t *)(*ptr_1 + -4));
}


