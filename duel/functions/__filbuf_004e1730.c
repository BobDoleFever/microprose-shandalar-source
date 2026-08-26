/*
 * Decompiled function: __filbuf
 * Entry Point: 004e1730
 * Size: 479 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __filbuf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __filbuf(FILE *fp)

{
  byte *pbVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined *local_c;
  
  if (fp == (FILE *)0x0) {
    iVar3 = __CrtDbgReport(2,0x4f0e64,0x69,0,"str != NULL");
    if (iVar3 == 1) {
      pcVar2 = (code *)swi(3);
      iVar3 = (*pcVar2)();
      return iVar3;
    }
  }
  if (((fp->_flag & 0x83) == 0) || ((fp->_flag & 0x40) != 0)) {
    uVar4 = 0xffffffff;
  }
  else if ((fp->_flag & 2) == 0) {
    fp->_flag = fp->_flag | 1;
    if ((fp->_flag & 0x10cU) == 0) {
      __getbuf(fp);
    }
    else {
      fp->_ptr = fp->_base;
    }
    iVar3 = __read(fp->_file,fp->_base,fp->_bufsiz);
    fp->_cnt = iVar3;
    if ((fp->_cnt == 0) || (fp->_cnt == -1)) {
      if (fp->_cnt == 0) {
        fp->_flag = fp->_flag | 0x10;
      }
      else {
        fp->_flag = fp->_flag | 0x20;
      }
      fp->_cnt = 0;
      uVar4 = 0xffffffff;
    }
    else {
      if ((fp->_flag & 0x82) == 0) {
        if (fp->_file == -1) {
          local_c = &DAT_0050a590;
        }
        else {
          local_c = (undefined *)
                    (*(int *)((int)&DAT_006c1b90 + ((int)(fp->_file & 0xffffffe0U) >> 3)) +
                    (fp->_file & 0x1fU) * 8);
        }
        if ((local_c[4] & 0x82) == 0x82) {
          fp->_flag = fp->_flag | 0x2000;
        }
      }
      if (((fp->_bufsiz == 0x200) && ((fp->_flag & 8) != 0)) && ((fp->_flag & 0x400) == 0)) {
        fp->_bufsiz = 0x1000;
      }
      fp->_cnt = fp->_cnt + -1;
      pbVar1 = (byte *)fp->_ptr;
      fp->_ptr = fp->_ptr + 1;
      uVar4 = (uint)*pbVar1;
    }
  }
  else {
    fp->_flag = fp->_flag | 0x20;
    uVar4 = 0xffffffff;
  }
  return uVar4;
}


