/*
 * Decompiled function: store_dt
 * Entry Point: 004e69b0
 * Size: 63 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _store_dt
   
   Library: Visual Studio 1998 Debug */

char * __cdecl store_dt(char *str_1,int arg2)

{
  *str_1 = (char)(arg2 / 10) + '0';
  str_1[1] = (char)(arg2 % 10) + '0';
  return str_1 + 2;
}


