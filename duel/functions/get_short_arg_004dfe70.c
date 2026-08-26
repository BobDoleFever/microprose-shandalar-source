/*
 * Decompiled function: get_short_arg
 * Entry Point: 004dfe70
 * Size: 31 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _get_short_arg
   
   Library: Visual Studio 1998 Debug */

undefined4 __cdecl get_short_arg(int *arg_1)

{
  *arg_1 = *arg_1 + 4;
  return CONCAT22((short)((uint)*arg_1 >> 0x10),*(undefined2 *)(*arg_1 + -4));
}


