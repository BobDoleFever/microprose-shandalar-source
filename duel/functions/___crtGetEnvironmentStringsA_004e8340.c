/*
 * Decompiled function: ___crtGetEnvironmentStringsA
 * Entry Point: 004e8340
 * Size: 602 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___crtGetEnvironmentStringsA
   
   Library: Visual Studio 1998 Debug */

LPVOID __cdecl ___crtGetEnvironmentStringsA(void)

{
  char *pcVar1;
  LPWCH pWVar2;
  int iVar3;
  int cbMultiByte;
  LPSTR ptr_1;
  LPCH local_1c;
  LPWCH local_18;
  char *local_10;
  LPWCH local_c;
  
  local_18 = (LPWCH)0x0;
  local_1c = (LPCH)0x0;
  if (DAT_0050a678 == 0) {
    local_18 = GetEnvironmentStringsW();
    if (local_18 == (LPWCH)0x0) {
      local_1c = GetEnvironmentStrings();
      if (local_1c == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_0050a678 = 2;
    }
    else {
      DAT_0050a678 = 1;
    }
  }
  if (DAT_0050a678 == 1) {
    if ((local_18 == (LPWCH)0x0) && (local_18 = GetEnvironmentStringsW(), local_18 == (LPWCH)0x0)) {
      ptr_1 = (LPSTR)0x0;
    }
    else {
      local_c = local_18;
      pWVar2 = local_c;
      while (local_c = pWVar2, *local_c != L'\0') {
        pWVar2 = local_c + 1;
        if (local_c[1] == L'\0') {
          pWVar2 = local_c + 2;
        }
      }
      iVar3 = ((int)local_c - (int)local_18 >> 1) + 1;
      cbMultiByte = WideCharToMultiByte(0,0,local_18,iVar3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      if ((cbMultiByte == 0) ||
         (local_1c = (LPCH)__malloc_dbg(cbMultiByte,2,"aw_env.c",0xfb), local_1c == (LPSTR)0x0)) {
        FreeEnvironmentStringsW(local_18);
        ptr_1 = (LPSTR)0x0;
      }
      else {
        iVar3 = WideCharToMultiByte(0,0,local_18,iVar3,local_1c,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0)
        ;
        if (iVar3 == 0) {
          __free_dbg(local_1c,2);
          local_1c = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(local_18);
        ptr_1 = local_1c;
      }
    }
  }
  else if (DAT_0050a678 == 2) {
    if ((local_1c == (LPCH)0x0) && (local_1c = GetEnvironmentStrings(), local_1c == (LPCH)0x0)) {
      ptr_1 = (LPSTR)0x0;
    }
    else {
      local_10 = local_1c;
      pcVar1 = local_10;
      while (local_10 = pcVar1, *local_10 != '\0') {
        pcVar1 = local_10 + 1;
        if (local_10[1] == '\0') {
          pcVar1 = local_10 + 2;
        }
      }
      ptr_1 = (LPSTR)__malloc_dbg(local_10 + (1 - (int)local_1c),2,"aw_env.c",0x126);
      if (ptr_1 == (LPSTR)0x0) {
        FreeEnvironmentStringsA(local_1c);
        ptr_1 = (LPSTR)0x0;
      }
      else {
        FID_conflict__memcpy(ptr_1,local_1c,(size_t)(local_10 + (1 - (int)local_1c)));
        FreeEnvironmentStringsA(local_1c);
      }
    }
  }
  else {
    ptr_1 = (LPSTR)0x0;
  }
  return ptr_1;
}


