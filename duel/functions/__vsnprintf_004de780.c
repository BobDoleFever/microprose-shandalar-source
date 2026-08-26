/*
 * Decompiled function: __vsnprintf
 * Entry Point: 004de780
 * Size: 229 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __vsnprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __vsnprintf(char *str_1,size_t arg_2,char *str_3,va_list arg_4)

{
  code *pcVar1;
  int iVar2;
  FILE local_24;
  
  if (str_1 == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0b3c,0x5a,0,"string != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  if (str_3 == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0b3c,0x5b,0,"format != NULL");
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
  iVar2 = __output(&local_24,(byte *)str_3,(undefined4 *)arg_4);
  local_24._cnt = local_24._cnt - 1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = '\0';
  }
  return iVar2;
}


