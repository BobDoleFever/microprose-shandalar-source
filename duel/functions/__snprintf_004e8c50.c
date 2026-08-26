/*
 * Decompiled function: __snprintf
 * Entry Point: 004e8c50
 * Size: 235 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __snprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __snprintf(char *str_1,size_t arg_2,char *str_3,...)

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
  if (str_3 == (char *)0x0) {
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
  local_24._cnt = arg_2;
  iVar2 = __output(&local_24,(byte *)str_3,(undefined4 *)&stack0x00000010);
  local_24._cnt = local_24._cnt - 1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = '\0';
  }
  return iVar2;
}


