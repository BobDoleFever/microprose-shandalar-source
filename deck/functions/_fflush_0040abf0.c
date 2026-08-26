/*
 * Decompiled function: _fflush
 * Entry Point: 0040abf0
 * Size: 126 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _fflush
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fflush(FILE *fp)

{
  int val_1;
  
  if (fp == (FILE *)0x0) {
    val_1 = flsall(0);
  }
  else {
    val_1 = __flush(fp);
    if (val_1 == 0) {
      if ((fp->_flag & 0x4000) == 0) {
        val_1 = 0;
      }
      else {
        val_1 = __commit(fp->_file);
        if (val_1 == 0) {
          val_1 = 0;
        }
        else {
          val_1 = -1;
        }
      }
    }
    else {
      val_1 = -1;
    }
  }
  return val_1;
}


