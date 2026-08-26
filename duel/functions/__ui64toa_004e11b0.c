/*
 * Decompiled function: __ui64toa
 * Entry Point: 004e11b0
 * Size: 42 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ui64toa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __ui64toa(ulonglong arg_1,char *str_2,int arg_3)

{
  x64toa((undefined4)arg_1,arg_1._4_4_,str_2,arg_3,0);
  return str_2;
}


