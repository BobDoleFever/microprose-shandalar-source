/*
 * Decompiled function: _fseek
 * Entry Point: 004dca30
 * Size: 304 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _fseek
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fseek(FILE *fp,long arg_2,int arg_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if ((fp == (FILE *)0x0) && (iVar2 = __CrtDbgReport(2,0x4f0ae8,0x92,0,"str != NULL"), iVar2 == 1))
  {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if (((fp->_flag & 0x83) == 0) || (((arg_3 != 0 && (arg_3 != 1)) && (arg_3 != 2)))) {
    DAT_00509420 = 0x16;
    iVar2 = -1;
  }
  else {
    fp->_flag = fp->_flag & 0xffffffef;
    if (arg_3 == 1) {
      lVar3 = _ftell(fp);
      arg_2 = arg_2 + lVar3;
      arg_3 = 0;
    }
    __flush(fp);
    if ((fp->_flag & 0x80) == 0) {
      if ((((fp->_flag & 1) != 0) && ((fp->_flag & 8) != 0)) && ((fp->_flag & 0x400) == 0)) {
        fp->_bufsiz = 0x200;
      }
    }
    else {
      fp->_flag = fp->_flag & 0xfffffffc;
    }
    lVar3 = __lseek(fp->_file,arg_2,arg_3);
    if (lVar3 == -1) {
      iVar2 = -1;
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}


