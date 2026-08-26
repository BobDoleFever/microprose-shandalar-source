/*
 * Decompiled function: get_int_arg
 * Entry Point: 004dfe20
 * Size: 30 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _get_int_arg
   
   Library: Visual Studio 1998 Debug */

undefined4 __cdecl get_int_arg(int *arg_1)

{
  *arg_1 = *arg_1 + 4;
  return *(undefined4 *)(*arg_1 + -4);
}


