/*
 * Decompiled function: _sscanf
 * Entry Point: 004dd040
 * Size: 193 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _sscanf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _sscanf(char *str_1,char *str_2,...)

{
  code *pcVar1;
  int iVar2;
  char *local_24;
  size_t local_20;
  char *local_1c;
  undefined4 local_18;
  
  if (str_1 == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0b14,0x42,0,"string != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  if (str_2 == (char *)0x0) {
    iVar2 = __CrtDbgReport(2,0x4f0b14,0x43,0,"format != NULL");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
  }
  local_18 = 0x49;
  local_1c = str_1;
  local_24 = str_1;
  local_20 = _strlen(str_1);
  iVar2 = __input((int)&local_24,(byte *)str_2,(undefined4 *)&stack0x0000000c);
  return iVar2;
}


