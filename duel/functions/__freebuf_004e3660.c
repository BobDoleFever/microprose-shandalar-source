/*
 * Decompiled function: __freebuf
 * Entry Point: 004e3660
 * Size: 138 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 1998 Debug */

void __cdecl __freebuf(FILE *fp)

{
  code *pcVar1;
  int iVar2;
  
  if (fp == (FILE *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0e98,0x30,0,"stream != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  if (((fp->_flag & 0x83) != 0) && ((fp->_flag & 8) != 0)) {
    __free_dbg(fp->_base,2);
    fp->_flag = fp->_flag & 0xfffffbf7;
    fp->_ptr = (char *)0x0;
    fp->_base = fp->_ptr;
    fp->_cnt = 0;
  }
  return;
}


