/*
 * Decompiled function: __i64toa
 * Entry Point: 00407d50
 * Size: 102 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __i64toa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __i64toa(longlong arg_1,char *str_2,int arg_3)

{
  int local_8;
  
  if (((arg_3 == 10) && (arg_1 < 0x100000000)) && (arg_1 < 0)) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  x64toa(arg_1,str_2,arg_3,local_8);
  return str_2;
}


