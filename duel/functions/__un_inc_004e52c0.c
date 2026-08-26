/*
 * Decompiled function: __un_inc
 * Entry Point: 004e52c0
 * Size: 37 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __un_inc
   
   Library: Visual Studio 1998 Debug */

void __un_inc(int arg1,FILE *fp)

{
  if (arg1 != -1) {
    _ungetc(arg1,fp);
  }
  return;
}


