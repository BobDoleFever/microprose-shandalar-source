/*
 * Decompiled function: _fflush
 * Entry Point: 004e11e0
 * Size: 126 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _fflush
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fflush(FILE *fp)

{
  int iVar1;
  
  if (fp == (FILE *)0x0) {
    iVar1 = flsall(0);
  }
  else {
    iVar1 = __flush(fp);
    if (iVar1 == 0) {
      if ((fp->_flag & 0x4000) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = __commit(fp->_file);
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = -1;
        }
      }
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}


