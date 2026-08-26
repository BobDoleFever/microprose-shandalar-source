/*
 * Decompiled function: FID_conflict:__atodbl
 * Entry Point: 004eb210
 * Size: 58 bytes
 */
#include "duel.h"


/* Library Function - Multiple Matches With Different Base Names
    __atodbl
    __atoflt
   
   Library: Visual Studio 1998 Debug */

int __cdecl FID_conflict___atodbl(_CRT_FLOAT *ptr_1,char *str_2)

{
  INTRNCVT_STATUS IVar1;
  char *local_14;
  _LDBL12 local_10;
  
  ___strgtold12(&local_10,&local_14,str_2,0,0,0,0);
  IVar1 = FID_conflict___ld12tod(&local_10,(_CRT_DOUBLE *)ptr_1);
  return IVar1;
}


