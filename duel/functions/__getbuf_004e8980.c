/*
 * Decompiled function: __getbuf
 * Entry Point: 004e8980
 * Size: 188 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 1998 Debug */

void __cdecl __getbuf(FILE *fp)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  
  if (fp == (FILE *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f1228,0x2e,0,"str != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  _DAT_005099d0 = _DAT_005099d0 + 1;
  pcVar3 = (char *)__malloc_dbg(0x1000,2,"_getbuf.c",0x3b);
  fp->_base = pcVar3;
  if (fp->_base == (char *)0x0) {
    fp->_flag = fp->_flag | 4;
    fp->_base = (char *)&fp->_charbuf;
    fp->_bufsiz = 2;
  }
  else {
    fp->_flag = fp->_flag | 8;
    fp->_bufsiz = 0x1000;
  }
  fp->_ptr = fp->_base;
  fp->_cnt = 0;
  return;
}


