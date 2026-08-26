/*
 * Decompiled function: _getc
 * Entry Point: 004dd270
 * Size: 28 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _getc
   
   Library: Visual Studio 1998 Debug */

int __cdecl _getc(FILE *fp)

{
  int iVar1;
  
  iVar1 = _fgetc(fp);
  return iVar1;
}


