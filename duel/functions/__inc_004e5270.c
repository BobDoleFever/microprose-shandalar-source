/*
 * Decompiled function: __inc
 * Entry Point: 004e5270
 * Size: 79 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __inc
   
   Library: Visual Studio 1998 Debug */

uint __inc(FILE *fp)

{
  byte *pbVar1;
  uint uVar2;
  
  fp->_cnt = fp->_cnt + -1;
  if (fp->_cnt < 0) {
    uVar2 = __filbuf(fp);
  }
  else {
    pbVar1 = (byte *)fp->_ptr;
    fp->_ptr = fp->_ptr + 1;
    uVar2 = (uint)*pbVar1;
  }
  return uVar2;
}


