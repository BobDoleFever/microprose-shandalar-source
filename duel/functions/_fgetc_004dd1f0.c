/*
 * Decompiled function: _fgetc
 * Entry Point: 004dd1f0
 * Size: 126 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _fgetc
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fgetc(FILE *fp)

{
  code *pcVar1;
  int iVar2;
  uint local_8;
  
  if (fp == (FILE *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0b20,0x29,0,"stream != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  fp->_cnt = fp->_cnt + -1;
  if (fp->_cnt < 0) {
    local_8 = __filbuf(fp);
  }
  else {
    local_8 = (uint)(byte)*fp->_ptr;
    fp->_ptr = fp->_ptr + 1;
  }
  return local_8;
}


