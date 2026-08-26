/*
 * Decompiled function: _fclose
 * Entry Point: 004dc820
 * Size: 237 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _fclose
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fclose(FILE *fp)

{
  code *pcVar1;
  int iVar2;
  int local_8;
  
  local_8 = -1;
  if ((fp->_flag & 0x40) == 0) {
    if (fp == (FILE *)0x0) {
      iVar2 = __CrtDbgReport(2,0x4f0ad0,0x77,0,"str != NULL");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        iVar2 = (*pcVar1)();
        return iVar2;
      }
    }
    if ((fp->_flag & 0x83) != 0) {
      local_8 = __flush(fp);
      __freebuf(fp);
      iVar2 = __close(fp->_file);
      if (iVar2 < 0) {
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


