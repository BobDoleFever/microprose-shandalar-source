/*
 * Decompiled function: _fgets
 * Entry Point: 004dcdb0
 * Size: 301 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _fgets
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _fgets(char *str_1,int arg_2,FILE *fp)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  char *pcVar4;
  uint local_10;
  char *local_c;
  
  local_c = str_1;
  if ((str_1 == (char *)0x0) &&
     (iVar3 = __CrtDbgReport(2,0x4f0af0,0x3b,0,"string != NULL"), iVar3 == 1)) {
    pcVar2 = (code *)swi(3);
    pcVar4 = (char *)(*pcVar2)();
    return pcVar4;
  }
  if ((fp == (FILE *)0x0) && (iVar3 = __CrtDbgReport(2,0x4f0af0,0x3c,0,"str != NULL"), iVar3 == 1))
  {
    pcVar2 = (code *)swi(3);
    pcVar4 = (char *)(*pcVar2)();
    return pcVar4;
  }
  if (arg_2 < 1) {
    str_1 = (char *)0x0;
  }
  else {
    do {
      arg_2 = arg_2 + -1;
      if (arg_2 == 0) break;
      fp->_cnt = fp->_cnt + -1;
      if (fp->_cnt < 0) {
        local_10 = __filbuf(fp);
      }
      else {
        local_10 = (uint)(byte)*fp->_ptr;
        fp->_ptr = fp->_ptr + 1;
      }
      if (local_10 == 0xffffffff) {
        if (str_1 == local_c) {
          return (char *)0x0;
        }
        break;
      }
      pcVar4 = local_c + 1;
      *local_c = (char)local_10;
      cVar1 = *local_c;
      local_c = pcVar4;
    } while (cVar1 != '\n');
    *local_c = '\0';
  }
  return str_1;
}


