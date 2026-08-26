/*
 * Decompiled function: ___crtGetEnvironmentStringsA
 * Entry Point: 00402380
 * Size: 602 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___crtGetEnvironmentStringsA
   
   Library: Visual Studio 1998 Debug */

LPVOID __cdecl ___crtGetEnvironmentStringsA(void)

{
  char *char_ptr_1;
  LPWCH pWVar2;
  int val_3;
  uint32_t x;
  LPSTR ptr_1;
  LPCH local_1c;
  LPWCH local_18;
  char *local_10;
  LPWCH local_c;
  
  local_18 = (LPWCH)0x0;
  local_1c = (LPCH)0x0;
  if (DAT_00412b60 == 0) {
    local_18 = GetEnvironmentStringsW();
    if (local_18 == (LPWCH)0x0) {
      local_1c = GetEnvironmentStrings();
      if (local_1c == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_00412b60 = 2;
    }
    else {
      DAT_00412b60 = 1;
    }
  }
  if (DAT_00412b60 == 1) {
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
      val_3 = ((int)local_c - (int)local_18 >> 1) + 1;
      x = WideCharToMultiByte(0,0,local_18,val_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      if ((x == 0) || (local_1c = (LPCH)__malloc_dbg(x,2,0x41007c,0xfb), local_1c == (LPSTR)0x0)) {
        FreeEnvironmentStringsW(local_18);
        ptr_1 = (LPSTR)0x0;
      }
      else {
        val_3 = WideCharToMultiByte(0,0,local_18,val_3,local_1c,x,(LPCSTR)0x0,(LPBOOL)0x0);
        if (val_3 == 0) {
          __free_dbg(local_1c,2);
          local_1c = (LPSTR)0x0;
        }
        FreeEnvironmentStringsW(local_18);
        ptr_1 = local_1c;
      }
    }
  }
  else if (DAT_00412b60 == 2) {
    if ((local_1c == (LPCH)0x0) && (local_1c = GetEnvironmentStrings(), local_1c == (LPCH)0x0)) {
      ptr_1 = (LPSTR)0x0;
    }
    else {
      local_10 = local_1c;
      char_ptr_1 = local_10;
      while (local_10 = char_ptr_1, *local_10 != '\0') {
        char_ptr_1 = local_10 + 1;
        if (local_10[1] == '\0') {
          char_ptr_1 = local_10 + 2;
        }
      }
      ptr_1 = (LPSTR)__malloc_dbg((uint32_t)(local_10 + (1 - (int)local_1c)),2,0x41007c,0x126);
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


