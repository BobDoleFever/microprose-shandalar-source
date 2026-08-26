/*
 * Decompiled function: ___STRINGTOLD
 * Entry Point: 004ed110
 * Size: 88 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___STRINGTOLD
   
   Library: Visual Studio 1998 Debug */

uint __cdecl ___STRINGTOLD(_LDOUBLE *x,char **y,char *width,int height)

{
  INTRNCVT_STATUS IVar1;
  uint local_18;
  _LDBL12 local_10;
  
  local_18 = ___strgtold12(&local_10,y,width,height,0,0,0);
  IVar1 = __ld12told(&local_10,x);
  if (IVar1 == INTRNCVT_OVERFLOW) {
    local_18 = local_18 | 2;
  }
  return local_18;
}


