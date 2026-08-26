/*
 * Decompiled function: __ftbuf
 * Entry Point: 004e6790
 * Size: 182 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ftbuf
   
   Library: Visual Studio 1998 Debug */

void __cdecl __ftbuf(int arg1,FILE *arg2)

{
  code *pcVar1;
  int iVar2;
  
  if (((arg1 != 0) && (arg1 != 1)) &&
     (iVar2 = __CrtDbgReport(2,0x4f0ef0,0x96,0,"flag == 0 || flag == 1"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (arg1 == 0) {
    if ((arg2->_flag & 0x1000) != 0) {
      __flush(arg2);
    }
  }
  else if ((arg2->_flag & 0x1000) != 0) {
    __flush(arg2);
    arg2->_flag = arg2->_flag & 0xffffeeff;
    arg2->_bufsiz = 0;
    arg2->_ptr = (char *)0x0;
    arg2->_base = arg2->_ptr;
  }
  return;
}


