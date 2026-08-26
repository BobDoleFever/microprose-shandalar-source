/*
 * Decompiled function: __freebuf
 * Entry Point: 0040b150
 * Size: 138 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 1998 Debug */

void __cdecl __freebuf(FILE *fp)

{
  code *char_ptr_1;
  int val_2;
  
  if (fp == (FILE *)0x0) {
    val_2 = __CrtDbgReport(2,0x410e58,0x30,0,"stream != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
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


