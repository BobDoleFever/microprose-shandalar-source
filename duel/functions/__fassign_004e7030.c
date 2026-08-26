/*
 * Decompiled function: __fassign
 * Entry Point: 004e7030
 * Size: 83 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 1998 Debug */

void __cdecl __fassign(int arg_1,char *str_2,char *str_3)

{
  _CRT_FLOAT local_10;
  _CRT_FLOAT local_c;
  undefined4 local_8;
  
  if (arg_1 == 0) {
    FID_conflict___atodbl(&local_10,str_3);
    *(float *)str_2 = local_10.f;
  }
  else {
    FID_conflict___atodbl(&local_c,str_3);
    *(float *)str_2 = local_c.f;
    *(undefined4 *)(str_2 + 4) = local_8;
  }
  return;
}


