/*
 * Decompiled function: __whiteout
 * Entry Point: 004e52f0
 * Size: 67 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __whiteout
   
   Library: Visual Studio 1998 Debug */

int __whiteout(int *arg1,FILE *fp)

{
  int arg_1;
  int iVar1;
  
  do {
    *arg1 = *arg1 + 1;
    arg_1 = __inc(fp);
    iVar1 = _isspace(arg_1);
  } while (iVar1 != 0);
  return arg_1;
}


