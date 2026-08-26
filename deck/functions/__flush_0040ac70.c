/*
 * Decompiled function: __flush
 * Entry Point: 0040ac70
 * Size: 186 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __flush
   
   Library: Visual Studio 1998 Debug */

int __cdecl __flush(FILE *fp)

{
  uint32_t arg_3;
  uint32_t uval_1;
  int local_8;
  
  local_8 = 0;
  if (((((uint8_t)fp->_flag & 3) == 2) && ((fp->_flag & 0x108U) != 0)) &&
     (arg_3 = (int)fp->_ptr - (int)fp->_base, 0 < (int)arg_3)) {
    uval_1 = __write(fp->_file,fp->_base,arg_3);
    if (uval_1 == arg_3) {
      if ((fp->_flag & 0x80) != 0) {
        fp->_flag = fp->_flag & 0xfffffffd;
      }
    }
    else {
      fp->_flag = fp->_flag | 0x20;
      local_8 = -1;
    }
  }
  fp->_ptr = fp->_base;
  fp->_cnt = 0;
  return local_8;
}


