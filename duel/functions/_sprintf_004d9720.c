/*
 * Decompiled function: _sprintf
 * Entry Point: 004d9720
 * Size: 236 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _sprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _sprintf(char *str_1,char *str_2,...)

{
  code *pcVar1;
  int iVar2;
  FILE local_24;
  
  if (str_1 == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f01fc,0x5d,0,"string != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  if (str_2 == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f01fc,0x5e,0,"format != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  local_24._flag = 0x42;
  local_24._base = str_1;
  local_24._ptr = str_1;
  local_24._cnt = 0x7fffffff;
  iVar2 = __output(&local_24,(byte *)str_2,(undefined4 *)&stack0x0000000c);
  local_24._cnt = local_24._cnt + -1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = '\0';
  }
  return iVar2;
}


