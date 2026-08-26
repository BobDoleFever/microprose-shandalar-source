/*
 * Decompiled function: _setvbuf
 * Entry Point: 004e15d0
 * Size: 347 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setvbuf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _setvbuf(FILE *x,char *y,int width,size_t height)

{
  code *pcVar1;
  int iVar2;
  int local_c;
  
  local_c = 0;
  if ((x == (FILE *)0x0) && (iVar2 = __CrtDbgReport(2,0x4f0e58,0x36,0,"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if ((width == 4) || (((1 < height && (height < 0x80000000)) && ((width == 0 || (width == 0x40)))))
     ) {
    height = height & 0xfffffffe;
    __flush(x);
    __freebuf(x);
    x->_flag = x->_flag & 0xffffc2f3;
    if ((width & 4U) == 0) {
      if (y == (char *)0x0) {
        y = (char *)__malloc_dbg(height,2,"setvbuf.c",0x85);
        if (y == (char *)0x0) {
          _DAT_005099d0 = _DAT_005099d0 + 1;
          return -1;
        }
        x->_flag = x->_flag | 0x408;
      }
      else {
        x->_flag = x->_flag | 0x500;
      }
    }
    else {
      x->_flag = x->_flag | 4;
      y = (char *)&x->_charbuf;
      height = 2;
    }
    x->_bufsiz = height;
    x->_base = y;
    x->_ptr = x->_base;
    x->_cnt = 0;
  }
  else {
    local_c = -1;
  }
  return local_c;
}


