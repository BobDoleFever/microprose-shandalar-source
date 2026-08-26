/*
 * Decompiled function: __chdir
 * Entry Point: 004eec70
 * Size: 226 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __chdir
   
   Library: Visual Studio 1998 Debug */

int __cdecl __chdir(char *str_1)

{
  BOOL BVar1;
  DWORD DVar2;
  uint uVar3;
  CHAR local_110;
  undefined1 local_10f;
  undefined1 local_10e;
  undefined1 local_10d;
  byte local_10c;
  byte local_10b;
  
  BVar1 = SetCurrentDirectoryA(str_1);
  if ((BVar1 != 0) && (DVar2 = GetCurrentDirectoryA(0x105,(LPSTR)&local_10c), DVar2 != 0)) {
    if (((local_10c == 0x5c) || (local_10c == 0x2f)) && (local_10c == local_10b)) {
      return 0;
    }
    local_110 = '=';
    uVar3 = __mbctoupper((uint)local_10c);
    local_10f = (undefined1)uVar3;
    local_10e = 0x3a;
    local_10d = 0;
    BVar1 = SetEnvironmentVariableA(&local_110,(LPCSTR)&local_10c);
    if (BVar1 != 0) {
      return 0;
    }
  }
  DVar2 = GetLastError();
  __dosmaperr(DVar2);
  return -1;
}


