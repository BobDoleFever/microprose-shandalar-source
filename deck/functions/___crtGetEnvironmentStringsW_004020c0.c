/*
 * Decompiled function: ___crtGetEnvironmentStringsW
 * Entry Point: 004020c0
 * Size: 689 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___crtGetEnvironmentStringsW
   
   Library: Visual Studio 1998 Debug */

LPVOID __cdecl ___crtGetEnvironmentStringsW(void)

{
  LPWCH pWVar1;
  LPWCH reg_eax;
  uint32_t x;
  int val_2;
  size_t len_3;
  LPWCH local_18;
  LPWCH local_14;
  int local_10;
  LPWCH local_c;
  
  local_18 = (LPWCH)0x0;
  local_10 = 0;
  if (DAT_00412b5c == 0) {
    reg_eax = GetEnvironmentStringsW();
    if (reg_eax == (LPWCH)0x0) {
      reg_eax = (LPWCH)GetEnvironmentStrings();
      if (reg_eax == (LPWCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_00412b5c = 2;
      local_18 = reg_eax;
    }
    else {
      DAT_00412b5c = 1;
      local_18 = reg_eax;
    }
  }
  if (DAT_00412b5c == 1) {
    if ((local_18 == (LPWCH)0x0) && (local_18 = GetEnvironmentStringsW(), local_18 == (LPWCH)0x0)) {
      reg_eax = (LPWCH)0x0;
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
      x = (int)local_14 + (2 - (int)local_18);
      reg_eax = (LPWCH)__malloc_dbg(x,2,0x41007c,0x57);
      if (reg_eax == (LPWCH)0x0) {
        FreeEnvironmentStringsW(local_18);
        reg_eax = (LPWCH)0x0;
      }
      else {
        FID_conflict__memcpy(reg_eax,local_18,x);
        FreeEnvironmentStringsW(local_18);
      }
    }
  }
  else if (DAT_00412b5c == 2) {
    if ((local_18 == (LPWCH)0x0) &&
       (local_18 = (LPWCH)GetEnvironmentStrings(), local_18 == (LPWCH)0x0)) {
      reg_eax = (LPWCH)0x0;
    }
    else {
      for (local_c = local_18; (char)*local_c != '\0'; local_c = (LPWCH)((int)local_c + len_3 + 1))
      {
        val_2 = MultiByteToWideChar(DAT_00413088,1,(LPCSTR)local_c,-1,(LPWSTR)0x0,0);
        if (val_2 == 0) {
          return (LPVOID)0x0;
        }
        local_10 = local_10 + val_2;
        len_3 = _strlen((char *)local_c);
      }
      reg_eax = (LPWCH)__malloc_dbg((local_10 + 1) * 2,2,0x41007c,0x87);
      if (reg_eax == (LPWCH)0x0) {
        FreeEnvironmentStringsA((LPCH)local_18);
        reg_eax = (LPWCH)0x0;
      }
      else {
        local_c = local_18;
        local_14 = reg_eax;
        while ((char)*local_c != '\0') {
          val_2 = MultiByteToWideChar(DAT_00413088,1,(LPCSTR)local_c,-1,local_14,
                                      (local_10 + 1) - ((int)local_14 - (int)reg_eax >> 1));
          if (val_2 == 0) {
            __free_dbg(reg_eax,2);
            FreeEnvironmentStringsA((LPCH)local_18);
            return (LPVOID)0x0;
          }
          len_3 = _strlen((char *)local_c);
          local_c = (LPWCH)((int)local_c + len_3 + 1);
          len_3 = _wcslen(local_14);
          local_14 = local_14 + len_3 + 1;
        }
        *local_14 = L'\0';
        FreeEnvironmentStringsA((LPCH)local_18);
      }
    }
  }
  return reg_eax;
}


