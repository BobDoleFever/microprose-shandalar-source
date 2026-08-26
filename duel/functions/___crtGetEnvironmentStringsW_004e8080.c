/*
 * Decompiled function: ___crtGetEnvironmentStringsW
 * Entry Point: 004e8080
 * Size: 689 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___crtGetEnvironmentStringsW
   
   Library: Visual Studio 1998 Debug */

LPVOID __cdecl ___crtGetEnvironmentStringsW(void)

{
  LPWCH pWVar1;
  LPWCH in_EAX;
  size_t sVar2;
  int iVar3;
  LPWCH local_18;
  LPWCH local_14;
  int local_10;
  LPWCH local_c;
  
  local_18 = (LPWCH)0x0;
  local_10 = 0;
  if (DAT_0050a674 == 0) {
    in_EAX = GetEnvironmentStringsW();
    if (in_EAX == (LPWCH)0x0) {
      in_EAX = (LPWCH)GetEnvironmentStrings();
      if (in_EAX == (LPWCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_0050a674 = 2;
      local_18 = in_EAX;
    }
    else {
      DAT_0050a674 = 1;
      local_18 = in_EAX;
    }
  }
  if (DAT_0050a674 == 1) {
    if ((local_18 == (LPWCH)0x0) && (local_18 = GetEnvironmentStringsW(), local_18 == (LPWCH)0x0)) {
      in_EAX = (LPWCH)0x0;
    }
    else {
      local_14 = local_18;
      pWVar1 = local_14;
      while (local_14 = pWVar1, *local_14 != L'\0') {
        pWVar1 = local_14 + 1;
        if (local_14[1] == L'\0') {
          pWVar1 = local_14 + 2;
        }
      }
      sVar2 = (int)local_14 + (2 - (int)local_18);
      in_EAX = (LPWCH)__malloc_dbg(sVar2,2,"aw_env.c",0x57);
      if (in_EAX == (LPWCH)0x0) {
        FreeEnvironmentStringsW(local_18);
        in_EAX = (LPWCH)0x0;
      }
      else {
        FID_conflict__memcpy(in_EAX,local_18,sVar2);
        FreeEnvironmentStringsW(local_18);
      }
    }
  }
  else if (DAT_0050a674 == 2) {
    if ((local_18 == (LPWCH)0x0) &&
       (local_18 = (LPWCH)GetEnvironmentStrings(), local_18 == (LPWCH)0x0)) {
      in_EAX = (LPWCH)0x0;
    }
    else {
      for (local_c = local_18; (char)*local_c != '\0'; local_c = (LPWCH)((int)local_c + sVar2 + 1))
      {
        iVar3 = MultiByteToWideChar(DAT_0050a740,1,(LPCSTR)local_c,-1,(LPWSTR)0x0,0);
        if (iVar3 == 0) {
          return (LPVOID)0x0;
        }
        local_10 = local_10 + iVar3;
        sVar2 = _strlen((char *)local_c);
      }
      in_EAX = (LPWCH)__malloc_dbg((local_10 + 1) * 2,2,"aw_env.c",0x87);
      if (in_EAX == (LPWCH)0x0) {
        FreeEnvironmentStringsA((LPCH)local_18);
        in_EAX = (LPWCH)0x0;
      }
      else {
        local_c = local_18;
        local_14 = in_EAX;
        while ((char)*local_c != '\0') {
          iVar3 = MultiByteToWideChar(DAT_0050a740,1,(LPCSTR)local_c,-1,local_14,
                                      (local_10 + 1) - ((int)local_14 - (int)in_EAX >> 1));
          if (iVar3 == 0) {
            __free_dbg(in_EAX,2);
            FreeEnvironmentStringsA((LPCH)local_18);
            return (LPVOID)0x0;
          }
          sVar2 = _strlen((char *)local_c);
          local_c = (LPWCH)((int)local_c + sVar2 + 1);
          sVar2 = _wcslen(local_14);
          local_14 = local_14 + sVar2 + 1;
        }
        *local_14 = L'\0';
        FreeEnvironmentStringsA((LPCH)local_18);
      }
    }
  }
  return in_EAX;
}


