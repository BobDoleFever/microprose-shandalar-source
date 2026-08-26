/*
 * Decompiled function: __ultoa
 * Entry Point: 00407d20
 * Size: 41 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __ultoa
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __ultoa(uint32_t arg_1,char *str_2,int arg_3)

{
  xtoa(arg_1,str_2,arg_3,0);
  return str_2;
}


