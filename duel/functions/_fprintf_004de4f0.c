/*
 * Decompiled function: _fprintf
 * Entry Point: 004de4f0
 * Size: 176 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _fprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fprintf(FILE *fp,char *str_2,...)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  if (fp == (FILE *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0b30,0x38,0,"str != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  if (str_2 == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0b30,0x39,0,"format != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  iVar2 = __stbuf(fp);
  iVar3 = __output(fp,(byte *)str_2,(undefined4 *)&stack0x0000000c);
  __ftbuf(iVar2,fp);
  return iVar3;
}


