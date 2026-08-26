/*
 * Decompiled function: write_char
 * Entry Point: 00409610
 * Size: 117 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _write_char
   
   Library: Visual Studio 1998 Debug */

void __cdecl write_char(int arg_1,FILE *fp,int *ptr_3)

{
  uint32_t local_8;
  
  fp->_cnt = fp->_cnt + -1;
  if (fp->_cnt < 0) {
    local_8 = __flsbuf(arg_1,fp);
  }
  else {
    *fp->_ptr = (char)arg_1;
    local_8 = (uint32_t)(uint8_t)*fp->_ptr;
    fp->_ptr = fp->_ptr + 1;
  }
  if (local_8 == 0xffffffff) {
    *ptr_3 = -1;
  }
  else {
    *ptr_3 = *ptr_3 + 1;
  }
  return;
}


