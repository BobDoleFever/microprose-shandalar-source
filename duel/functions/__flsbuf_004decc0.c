/*
 * Decompiled function: __flsbuf
 * Entry Point: 004decc0
 * Size: 660 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __flsbuf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __flsbuf(int arg1,FILE *arg2)

{
  code *pcVar1;
  FILE *fp;
  int iVar2;
  uint uVar3;
  undefined *local_1c;
  uint local_10;
  uint local_8;
  
  if ((arg2 == (FILE *)0x0) && (iVar2 = __CrtDbgReport(2,0x4f0b94,0x69,0,"str != NULL"), iVar2 == 1)
     ) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  fp = arg2;
  uVar3 = arg2->_file;
  if (((arg2->_flag & 0x82) == 0) || ((arg2->_flag & 0x40) != 0)) {
    arg2->_flag = arg2->_flag | 0x20;
    uVar3 = 0xffffffff;
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
       (((arg2 != (FILE *)0x509770 && (arg2 != (FILE *)&DAT_00509790)) ||
        (iVar2 = __isatty(uVar3), iVar2 == 0)))) {
      __getbuf(fp);
    }
    if ((fp->_flag & 0x108U) == 0) {
      local_8 = 1;
      local_10 = __write(uVar3,&arg1,1);
    }
    else {
      if (((int)fp->_ptr - (int)fp->_base < 0) &&
         (iVar2 = __CrtDbgReport(2,0x4f0b94,0xa0,0,
                                 "(\"inconsistent IOB fields\", stream->_ptr - stream->_base >= 0)")
         , iVar2 == 1)) {
        pcVar1 = (code *)swi(3);
        iVar2 = (*pcVar1)();
        return iVar2;
      }
      local_8 = (int)fp->_ptr - (int)fp->_base;
      fp->_ptr = fp->_base + 1;
      fp->_cnt = fp->_bufsiz + -1;
      if ((int)local_8 < 1) {
        if (uVar3 == 0xffffffff) {
          local_1c = &DAT_0050a590;
        }
        else {
          local_1c = (undefined *)
                     (*(int *)((int)&DAT_006c1b90 + ((int)(uVar3 & 0xffffffe0) >> 3)) +
                     (uVar3 & 0x1f) * 8);
        }
        if ((local_1c[4] & 0x20) != 0) {
          __lseek(uVar3,0,2);
        }
      }
      else {
        local_10 = __write(uVar3,fp->_base,local_8);
      }
      *fp->_base = (char)arg1;
    }
    if (local_10 == local_8) {
      uVar3 = arg1 & 0xff;
    }
    else {
      fp->_flag = fp->_flag | 0x20;
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}


