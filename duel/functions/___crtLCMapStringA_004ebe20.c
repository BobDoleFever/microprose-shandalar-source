/*
 * Decompiled function: ___crtLCMapStringA
 * Entry Point: 004ebe20
 * Size: 791 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___crtLCMapStringA
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtLCMapStringA(_locale_t arg_1,LPCWSTR arg_2,DWORD arg_3,LPCSTR arg_4,int arg_5,LPSTR arg_6,
                  int arg_7,int arg_8,BOOL arg_9)

{
  LPCSTR in_EAX;
  int iVar1;
  LPCWSTR lpWideCharStr;
  int iVar2;
  int local_14;
  LPCWSTR local_c;
  
  if (DAT_0050a8dc == 0) {
    in_EAX = (LPCSTR)LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
    if (in_EAX == (LPCSTR)0x0) {
      in_EAX = (LPCSTR)LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
      if (in_EAX == (LPCSTR)0x0) {
        return 0;
      }
      DAT_0050a8dc = 1;
    }
    else {
      DAT_0050a8dc = 2;
    }
  }
  if (0 < (int)arg_4) {
    in_EAX = (LPCSTR)_strncnt((char *)arg_3,(size_t)arg_4);
    arg_4 = in_EAX;
  }
  if (DAT_0050a8dc == 2) {
    iVar1 = LCMapStringA((LCID)arg_1,(DWORD)arg_2,(LPCSTR)arg_3,(int)arg_4,(LPSTR)arg_5,(int)arg_6);
    return iVar1;
  }
  if (DAT_0050a8dc != 1) {
    return (int)in_EAX;
  }
  local_c = (LPCWSTR)0x0;
  if (arg_7 == 0) {
    arg_7 = DAT_0050a740;
  }
  iVar1 = MultiByteToWideChar(arg_7,9,(LPCSTR)arg_3,(int)arg_4,(LPWSTR)0x0,0);
  if (iVar1 == 0) {
    return 0;
  }
  lpWideCharStr = (LPCWSTR)__malloc_dbg(iVar1 * 2,2,"aw_map.c",0x16d);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return 0;
  }
  iVar2 = MultiByteToWideChar(arg_7,1,(LPCSTR)arg_3,(int)arg_4,lpWideCharStr,iVar1);
  if ((iVar2 != 0) &&
     (local_14 = LCMapStringW((LCID)arg_1,(DWORD)arg_2,lpWideCharStr,iVar1,(LPWSTR)0x0,0),
     local_14 != 0)) {
    if (((uint)arg_2 & 0x400) == 0) {
      local_c = (LPCWSTR)__malloc_dbg(local_14 * 2,2,"aw_map.c",0x191);
      if ((local_c == (LPCWSTR)0x0) ||
         (iVar1 = LCMapStringW((LCID)arg_1,(DWORD)arg_2,lpWideCharStr,iVar1,local_c,local_14),
         iVar1 == 0)) goto LAB_004ec10f;
      if (arg_6 == (LPSTR)0x0) {
        local_14 = WideCharToMultiByte(arg_7,0x220,local_c,local_14,(LPSTR)0x0,0,(LPCSTR)0x0,
                                       (LPBOOL)0x0);
        iVar1 = local_14;
      }
      else {
        local_14 = WideCharToMultiByte(arg_7,0x220,local_c,local_14,(LPSTR)arg_5,(int)arg_6,
                                       (LPCSTR)0x0,(LPBOOL)0x0);
        iVar1 = local_14;
      }
    }
    else {
      if (arg_6 == (LPSTR)0x0) goto LAB_004ec0eb;
      if ((int)arg_6 < local_14) goto LAB_004ec10f;
      iVar1 = LCMapStringW((LCID)arg_1,(DWORD)arg_2,lpWideCharStr,iVar1,(LPWSTR)arg_5,(int)arg_6);
    }
    if (iVar1 != 0) {
LAB_004ec0eb:
      __free_dbg(lpWideCharStr,2);
      __free_dbg(local_c,2);
      return local_14;
    }
  }
LAB_004ec10f:
  __free_dbg(lpWideCharStr,2);
  __free_dbg(local_c,2);
  return 0;
}


