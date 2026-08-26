/*
 * Decompiled function: _fscanf
 * Entry Point: 004dcee0
 * Size: 139 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _fscanf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fscanf(FILE *fp,char *str_2,...)

{
  code *pcVar1;
  int iVar2;
  
  if (fp == (FILE *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0af8,0x36,0,"stream != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  if (str_2 == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0af8,0x37,0,"format != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  iVar2 = __input((int)fp,(byte *)str_2,(undefined4 *)&stack0x0000000c);
  return iVar2;
}


