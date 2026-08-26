/*
 * Decompiled function: __ui64toa
 * Entry Point: 00407ea0
 * Size: 42 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __ui64toa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __ui64toa(ulonglong arg_1,char *str_2,int arg_3)

{
  x64toa(arg_1,str_2,arg_3,0);
  return str_2;
}


