/*
 * Decompiled function: wcsncnt
 * Entry Point: 004eb950
 * Size: 110 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _wcsncnt
   
   Library: Visual Studio 1998 Debug */

int __cdecl wcsncnt(short *arg1,int arg2)

{
  int local_c;
  short *local_8;
  
  local_c = arg2 + 1;
  for (local_8 = arg1; (local_c = local_c + -1, local_c != 0 && (*local_8 != 0));
      local_8 = local_8 + 1) {
  }
  if ((local_c != 0) && (*local_8 == 0)) {
    arg2 = ((int)local_8 - (int)arg1 >> 1) + 1;
  }
  return arg2;
}


