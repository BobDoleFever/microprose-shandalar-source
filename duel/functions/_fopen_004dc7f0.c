/*
 * Decompiled function: _fopen
 * Entry Point: 004dc7f0
 * Size: 34 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _fopen
   
   Library: Visual Studio 1998 Debug */

FILE * __cdecl _fopen(char *filename,char *str_2)

{
  FILE *pFVar1;
  
  pFVar1 = __fsopen(filename,str_2,0x40);
  return pFVar1;
}


