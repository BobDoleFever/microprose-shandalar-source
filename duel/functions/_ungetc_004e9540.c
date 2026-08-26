/*
 * Decompiled function: _ungetc
 * Entry Point: 004e9540
 * Size: 299 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _ungetc
   
   Library: Visual Studio 1998 Debug */

int __cdecl _ungetc(int arg1,FILE *arg2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  if ((arg2 == (FILE *)0x0) && (iVar2 = __CrtDbgReport(2,0x4f1264,0x60,0,"str != NULL"), iVar2 == 1)
     ) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if ((arg1 == -1) ||
     (((arg2->_flag & 1) == 0 && (((arg2->_flag & 0x80) == 0 || ((arg2->_flag & 2) != 0)))))) {
    uVar3 = 0xffffffff;
  }
  else {
    if (arg2->_base == (char *)0x0) {
      __getbuf(arg2);
    }
    if (arg2->_base == arg2->_ptr) {
      if (arg2->_cnt != 0) {
        return -1;
      }
      arg2->_ptr = arg2->_ptr + 1;
    }
    if ((arg2->_flag & 0x40) == 0) {
      arg2->_ptr = arg2->_ptr + -1;
      *arg2->_ptr = (char)arg1;
    }
    else {
      arg2->_ptr = arg2->_ptr + -1;
      if (*arg2->_ptr != (char)arg1) {
        arg2->_ptr = arg2->_ptr + 1;
        return -1;
      }
    }
    arg2->_cnt = arg2->_cnt + 1;
    arg2->_flag = arg2->_flag & 0xffffffef;
    arg2->_flag = arg2->_flag | 1;
    uVar3 = arg1 & 0xff;
  }
  return uVar3;
}


