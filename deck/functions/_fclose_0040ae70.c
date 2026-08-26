/*
 * Decompiled function: _fclose
 * Entry Point: 0040ae70
 * Size: 237 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _fclose
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fclose(FILE *fp)

{
  code *char_ptr_1;
  int val_2;
  int local_8;
  
  local_8 = -1;
  if ((fp->_flag & 0x40) == 0) {
    if (fp == (FILE *)0x0) {
      val_2 = __CrtDbgReport(2,0x410e4c,0x77,0,"str != NULL");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        val_2 = (*char_ptr_1)();
        return val_2;
      }
    }
    if ((fp->_flag & 0x83) != 0) {
      local_8 = __flush(fp);
      __freebuf(fp);
      val_2 = __close(fp->_file);
      if (val_2 < 0) {
        local_8 = -1;
      }
      else if (fp->_tmpfname != (char *)0x0) {
        __free_dbg(fp->_tmpfname,2);
        fp->_tmpfname = (char *)0x0;
      }
    }
    fp->_flag = 0;
  }
  else {
    fp->_flag = 0;
    local_8 = -1;
  }
  return local_8;
}


