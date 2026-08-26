/*
 * Decompiled function: __itoa
 * Entry Point: 00407ba0
 * Size: 88 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __itoa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __itoa(int arg_1,char *str_2,int arg_3)

{
  if ((arg_3 == 10) && (arg_1 < 0)) {
    xtoa(arg_1,str_2,10,1);
  }
  else {
    xtoa(arg_1,str_2,arg_3,0);
  }
  return str_2;
}


