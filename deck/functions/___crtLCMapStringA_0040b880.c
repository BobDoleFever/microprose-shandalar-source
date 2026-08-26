/*
 * Decompiled function: ___crtLCMapStringA
 * Entry Point: 0040b880
 * Size: 791 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___crtLCMapStringA
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtLCMapStringA(_locale_t arg_1,LPCWSTR arg_2,DWORD arg_3,LPCSTR arg_4,int arg_5,LPSTR arg_6,
                  int arg_7,int arg_8,BOOL arg_9)

{
  LPCSTR reg_eax;
  int val_1;
  LPCWSTR lpWideCharStr;
  int val_2;
  int local_14;
  LPCWSTR local_c;
  
  if (DAT_00413d54 == 0) {
    reg_eax = (LPCSTR)LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (reg_eax == (LPCSTR)0x0) {
      reg_eax = (LPCSTR)LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (reg_eax == (LPCSTR)0x0) {
        return 0;
      }
      DAT_00413d54 = 1;
    }
    else {
      DAT_00413d54 = 2;
    }
  }
  if (0 < (int)arg_4) {
    reg_eax = (LPCSTR)_strncnt((char *)arg_3,(size_t)arg_4);
    arg_4 = reg_eax;
  }
  if (DAT_00413d54 == 2) {
    val_1 = LCMapStringA((LCID)arg_1,(DWORD)arg_2,(LPCSTR)arg_3,(int)arg_4,(LPSTR)arg_5,(int)arg_6);
    return val_1;
  }
  if (DAT_00413d54 != 1) {
    return (int)reg_eax;
  }
  local_c = (LPCWSTR)0x0;
  if (arg_7 == 0) {
    arg_7 = DAT_00413088;
  }
  val_1 = MultiByteToWideChar(arg_7,9,(LPCSTR)arg_3,(int)arg_4,(LPWSTR)0x0,0);
  if (val_1 == 0) {
    return 0;
  }
  lpWideCharStr = (LPCWSTR)__malloc_dbg(val_1 * 2,2,0x410e74,0x16d);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  val_2 = MultiByteToWideChar(arg_7,1,(LPCSTR)arg_3,(int)arg_4,lpWideCharStr,val_1);
  if ((val_2 != 0) &&
     (local_14 = LCMapStringW((LCID)arg_1,(DWORD)arg_2,lpWideCharStr,val_1,(LPWSTR)0x0,0),
     local_14 != 0)) {
    if (((uint32_t)arg_2 & 0x400) == 0) {
      local_c = (LPCWSTR)__malloc_dbg(local_14 * 2,2,0x410e74,0x191);
      if ((local_c == (LPCWSTR)0x0) ||
         (val_1 = LCMapStringW((LCID)arg_1,(DWORD)arg_2,lpWideCharStr,val_1,local_c,local_14),
         val_1 == 0)) goto LAB_0040bb6f;
      if (arg_6 == (LPSTR)0x0) {
        local_14 = WideCharToMultiByte(arg_7,0x220,local_c,local_14,(LPSTR)0x0,0,(LPCSTR)0x0,
                                       (LPBOOL)0x0);
        val_1 = local_14;
      }
      else {
        local_14 = WideCharToMultiByte(arg_7,0x220,local_c,local_14,(LPSTR)arg_5,(int)arg_6,
                                       (LPCSTR)0x0,(LPBOOL)0x0);
        val_1 = local_14;
      }
    }
    else {
      if (arg_6 == (LPSTR)0x0) goto LAB_0040bb4b;
      if ((int)arg_6 < local_14) goto LAB_0040bb6f;
      val_1 = LCMapStringW((LCID)arg_1,(DWORD)arg_2,lpWideCharStr,val_1,(LPWSTR)arg_5,(int)arg_6);
    }
    if (val_1 != 0) {
LAB_0040bb4b:
      __free_dbg(lpWideCharStr,2);
      __free_dbg(local_c,2);
      return local_14;
    }
  }
LAB_0040bb6f:
  __free_dbg(lpWideCharStr,2);
  __free_dbg(local_c,2);
  return 0;
}


