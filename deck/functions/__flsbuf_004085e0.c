/*
 * Decompiled function: __flsbuf
 * Entry Point: 004085e0
 * Size: 660 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __flsbuf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __flsbuf(int arg1,FILE *arg2)

{
  code *char_ptr_1;
  FILE *fp;
  int val_2;
  uint32_t uval_3;
  uint8_t *local_1c;
  uint32_t local_10;
  uint32_t local_8;
  
  if ((arg2 == (FILE *)0x0) && (val_2 = __CrtDbgReport(2,0x410d70,0x69,0,"str != NULL"), val_2 == 1)
     ) {
    char_ptr_1 = (code *)swi(3);
    val_2 = (*char_ptr_1)();
    return val_2;
  }
  fp = arg2;
  uval_3 = arg2->_file;
  if (((arg2->_flag & 0x82) == 0) || ((arg2->_flag & 0x40) != 0)) {
    arg2->_flag = arg2->_flag | 0x20;
    uval_3 = 0xffffffff;
  }
  else {
    if ((arg2->_flag & 1) != 0) {
      arg2->_cnt = 0;
      if ((arg2->_flag & 0x10) == 0) {
        arg2->_flag = arg2->_flag | 0x20;
        return -1;
      }
      arg2->_ptr = arg2->_base;
      arg2->_flag = arg2->_flag & 0xfffffffe;
    }
    arg2->_flag = arg2->_flag | 2;
    arg2->_flag = arg2->_flag & 0xffffffef;
    arg2->_cnt = 0;
    local_10 = arg2->_cnt;
    if (((arg2->_flag & 0x10cU) == 0) &&
       (((arg2 != (FILE *)0x413960 && (arg2 != (FILE *)0x413980)) ||
        (val_2 = __isatty(uval_3), val_2 == 0)))) {
      __getbuf(fp);
    }
    if ((fp->_flag & 0x108U) == 0) {
      local_8 = 1;
      local_10 = __write(uval_3,&arg1,1);
    }
    else {
      if (((int)fp->_ptr - (int)fp->_base < 0) &&
         (val_2 = __CrtDbgReport(2,0x410d70,0xa0,0,
                                 "(\"inconsistent IOB fields\", stream->_ptr - stream->_base >= 0)")
         , val_2 == 1)) {
        char_ptr_1 = (code *)swi(3);
        val_2 = (*char_ptr_1)();
        return val_2;
      }
      local_8 = (int)fp->_ptr - (int)fp->_base;
      fp->_ptr = fp->_base + 1;
      fp->_cnt = fp->_bufsiz + -1;
      if ((int)local_8 < 1) {
        if (uval_3 == 0xffffffff) {
          local_1c = &DAT_00412d80;
        }
        else {
          local_1c = (uint8_t *)
                     (*(int *)((int)&DAT_004156c0 + ((int)(uval_3 & 0xffffffe0) >> 3)) +
                     (uval_3 & 0x1f) * 8);
        }
        if ((local_1c[4] & 0x20) != 0) {
          __lseek(uval_3,0,2);
        }
      }
      else {
        local_10 = __write(uval_3,fp->_base,local_8);
      }
      *fp->_base = (char)arg1;
    }
    if (local_10 == local_8) {
      uval_3 = arg1 & 0xff;
    }
    else {
      fp->_flag = fp->_flag | 0x20;
      uval_3 = 0xffffffff;
    }
  }
  return uval_3;
}


