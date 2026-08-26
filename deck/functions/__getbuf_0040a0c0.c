/*
 * Decompiled function: __getbuf
 * Entry Point: 0040a0c0
 * Size: 188 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 1998 Debug */

void __cdecl __getbuf(FILE *fp)

{
  code *char_ptr_1;
  int val_2;
  char *char_ptr_3;
  
  if (fp == (FILE *)0x0) {
    val_2 = __CrtDbgReport(2,0x410e2c,0x2e,0,"str != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
  }
  _DAT_00413bc0 = _DAT_00413bc0 + 1;
  char_ptr_3 = (char *)__malloc_dbg(0x1000,2,0x410e2c,0x3b);
  fp->_base = char_ptr_3;
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


