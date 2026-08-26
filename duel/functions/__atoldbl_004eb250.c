/*
 * Decompiled function: __atoldbl
 * Entry Point: 004eb250
 * Size: 58 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __atoldbl
   
   Library: Visual Studio 1998 Debug */

int __cdecl __atoldbl(_LDOUBLE *ptr_1,char *str_2)

{
  INTRNCVT_STATUS IVar1;
  char *local_14;
  _LDBL12 local_10;
  
  ___strgtold12(&local_10,&local_14,str_2,1,0,0,0);
  IVar1 = __ld12told(&local_10,ptr_1);
  return IVar1;
}


