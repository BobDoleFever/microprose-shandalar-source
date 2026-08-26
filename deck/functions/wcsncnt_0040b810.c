/*
 * Decompiled function: wcsncnt
 * Entry Point: 0040b810
 * Size: 108 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _wcsncnt
   
   Library: Visual Studio 1998 Debug */

int __cdecl wcsncnt(short *ptr_1,int arg_2)

{
  int local_c;
  short *local_8;
  
  local_c = arg_2;
  for (local_8 = ptr_1; (local_c != 0 && (*local_8 != 0)); local_8 = local_8 + 1) {
    local_c = local_c + -1;
  }
  if (*local_8 == 0) {
    arg_2 = (int)local_8 - (int)ptr_1 >> 1;
  }
  return arg_2;
}


