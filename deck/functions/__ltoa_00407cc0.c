/*
 * Decompiled function: __ltoa
 * Entry Point: 00407cc0
 * Size: 85 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __ltoa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __ltoa(long arg_1,char *str_2,int arg_3)

{
  int32_t local_8;
  
  if ((arg_3 == 10) && (arg_1 < 0)) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  xtoa(arg_1,str_2,arg_3,local_8);
  return str_2;
}


