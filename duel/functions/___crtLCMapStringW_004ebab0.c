/*
 * Decompiled function: ___crtLCMapStringW
 * Entry Point: 004ebab0
 * Size: 760 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___crtLCMapStringW
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtLCMapStringW(LPCWSTR arg_1,DWORD arg_2,LPCWSTR arg_3,int arg_4,LPWSTR arg_5,int arg_6)

{
  int in_EAX;
  int iVar1;
  LPCSTR lpMultiByteStr;
  int iVar2;
  UINT in_stack_0000001c;
  size_t local_14;
  char *local_10;
  
  if (DAT_0050a8d8 == 0) {
    in_EAX = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (in_EAX == 0) {
      in_EAX = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (in_EAX == 0) {
        return 0;
      }
      DAT_0050a8d8 = 2;
    }
    else {
      DAT_0050a8d8 = 1;
    }
  }
  if (0 < arg_4) {
    in_EAX = wcsncnt(arg_3,arg_4);
    arg_4 = in_EAX;
  }
  if (DAT_0050a8d8 == 1) {
    iVar1 = LCMapStringW((LCID)arg_1,arg_2,arg_3,arg_4,arg_5,arg_6);
    return iVar1;
  }
  if (DAT_0050a8d8 != 2) {
    return in_EAX;
  }
  local_10 = (char *)0x0;
  if (in_stack_0000001c == 0) {
    in_stack_0000001c = DAT_0050a740;
  }
  iVar1 = WideCharToMultiByte(in_stack_0000001c,0x220,arg_3,arg_4,(LPSTR)0x0,0,(LPCSTR)0x0,
                              (LPBOOL)0x0);
  if (iVar1 == 0) {
    return 0;
  }
  lpMultiByteStr = (LPCSTR)__malloc_dbg(iVar1,2,"aw_map.c",0xcc);
  if (lpMultiByteStr == (LPCSTR)0x0) {
    return 0;
  }
  iVar2 = WideCharToMultiByte(in_stack_0000001c,0x220,arg_3,arg_4,lpMultiByteStr,iVar1,(LPCSTR)0x0,
                              (LPBOOL)0x0);
  if ((((iVar2 == 0) ||
       (local_14 = LCMapStringA((LCID)arg_1,arg_2,lpMultiByteStr,iVar1,(LPSTR)0x0,0), local_14 == 0)
       ) || (local_10 = (char *)__malloc_dbg(local_14,2,"aw_map.c",0xdb), local_10 == (char *)0x0))
     || (iVar1 = LCMapStringA((LCID)arg_1,arg_2,lpMultiByteStr,iVar1,local_10,local_14), iVar1 == 0)
     ) {
LAB_004ebd80:
    __free_dbg(lpMultiByteStr,2);
    __free_dbg(local_10,2);
    local_14 = 0;
  }
  else {
    if ((arg_2 & 0x400) == 0) {
      if (arg_6 == 0) {
        local_14 = MultiByteToWideChar(in_stack_0000001c,1,local_10,local_14,(LPWSTR)0x0,0);
      }
      else {
        local_14 = MultiByteToWideChar(in_stack_0000001c,1,local_10,local_14,arg_5,arg_6);
      }
      if (local_14 == 0) goto LAB_004ebd80;
    }
    else if (arg_6 != 0) {
      if ((int)local_14 <= arg_6) {
        arg_6 = local_14;
      }
      _strncpy((char *)arg_5,local_10,arg_6);
    }
    __free_dbg(lpMultiByteStr,2);
    __free_dbg(local_10,2);
  }
  return local_14;
}


