/*
 * Decompiled function: __ultoa
 * Entry Point: 004e1030
 * Size: 41 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ultoa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __ultoa(ulong arg_1,char *str_2,int arg_3)

{
  xtoa(arg_1,str_2,arg_3,0);
  return str_2;
}


