/*
 * Decompiled function: __stbuf
 * Entry Point: 004e6640
 * Size: 330 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __stbuf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __stbuf(FILE *fp)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  
  if ((fp == (FILE *)0x0) && (iVar2 = __CrtDbgReport(2,0x4f0ef0,0x41,0,"str != NULL"), iVar2 == 1))
  {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  iVar2 = __isatty(fp->_file);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    if (fp == (FILE *)0x509770) {
      local_c = 0;
    }
    else {
      if (fp != (FILE *)&DAT_00509790) {
        return 0;
      }
      local_c = 1;
    }
    _DAT_005099d0 = _DAT_005099d0 + 1;
    if ((fp->_flag & 0x10cU) == 0) {
      if (*(int *)(&DAT_0050a5a8 + local_c * 4) == 0) {
        uVar3 = __malloc_dbg(0x1000,2,"_sftbuf.c",0x5e);
        *(undefined4 *)(&DAT_0050a5a8 + local_c * 4) = uVar3;
        if (*(int *)(&DAT_0050a5a8 + local_c * 4) == 0) {
          return 0;
        }
      }
      fp->_base = *(char **)(&DAT_0050a5a8 + local_c * 4);
      fp->_ptr = fp->_base;
      fp->_bufsiz = 0x1000;
      fp->_cnt = fp->_bufsiz;
      fp->_flag = fp->_flag | 0x1102;
      iVar2 = 1;
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}


