/*
 * Decompiled function: FID_conflict:__mkdir
 * Entry Point: 004dd190
 * Size: 94 bytes
 */
#include "duel.h"


/* Library Function - Multiple Matches With Different Base Names
    __mkdir
    __wmkdir
   
   Library: Visual Studio 1998 Debug */

int __cdecl FID_conflict___mkdir(char *str_1)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  BVar1 = CreateDirectoryA(str_1,(LPSECURITY_ATTRIBUTES)0x0);
  if (BVar1 == 0) {
    local_8 = GetLastError();
  }
  else {
    local_8 = 0;
  }
  if (local_8 == 0) {
    iVar2 = 0;
  }
  else {
    __dosmaperr(local_8);
    iVar2 = -1;
  }
  return iVar2;
}


