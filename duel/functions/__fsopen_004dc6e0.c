/*
 * Decompiled function: __fsopen
 * Entry Point: 004dc6e0
 * Size: 258 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __fsopen
   
   Library: Visual Studio 1998 Debug */

FILE * __cdecl __fsopen(char *filename,char *str_2,int arg_3)

{
  code *pcVar1;
  int iVar2;
  FILE *pFVar3;
  
  if (filename == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0ab8,0x35,0,"file != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      pFVar3 = (FILE *)(*pcVar1)();
      return pFVar3;
    }
  }
  if (*filename == '\0') {
    iVar2 = __CrtDbgReport(2,0x4f0ab8,0x36,0,"*file != _T(\'\\0\')");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      pFVar3 = (FILE *)(*pcVar1)();
      return pFVar3;
    }
  }
  if (str_2 == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0ab8,0x37,0,"mode != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      pFVar3 = (FILE *)(*pcVar1)();
      return pFVar3;
    }
  }
  if (*str_2 == '\0') {
    iVar2 = __CrtDbgReport(2,0x4f0ab8,0x38,0,"*mode != _T(\'\\0\')");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      pFVar3 = (FILE *)(*pcVar1)();
      return pFVar3;
    }
  }
  pFVar3 = __getstream();
  if (pFVar3 == (FILE *)0x0) {
    pFVar3 = (FILE *)0x0;
  }
  else {
    pFVar3 = __openfile(filename,str_2,arg_3,pFVar3);
  }
  return pFVar3;
}


