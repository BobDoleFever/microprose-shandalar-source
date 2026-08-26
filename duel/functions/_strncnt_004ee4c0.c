/*
 * Decompiled function: _strncnt
 * Entry Point: 004ee4c0
 * Size: 100 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _strncnt
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl _strncnt(char *str_1,size_t arg_2)

{
  size_t local_c;
  char *local_8;
  
  local_c = arg_2;
  for (local_8 = str_1; (local_c != 0 && (*local_8 != '\0')); local_8 = local_8 + 1) {
    local_c = local_c - 1;
  }
  if (*local_8 == '\0') {
    arg_2 = (int)local_8 - (int)str_1;
  }
  return arg_2;
}


