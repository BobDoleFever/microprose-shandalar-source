/*
 * Decompiled function: ___crtLCMapStringW
 * Entry Point: 0040b510
 * Size: 760 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___crtLCMapStringW
   
   Library: Visual Studio 1998 Debug */

int __cdecl
___crtLCMapStringW(LPCWSTR arg_1,DWORD arg_2,LPCWSTR arg_3,int arg_4,LPWSTR arg_5,int arg_6)

{
  int reg_eax;
  int val_1;
  uint32_t x;
  LPCSTR lpMultiByteStr;
  UINT stack_arg;
  uint32_t local_14;
  char *local_10;
  
  if (DAT_00413d50 == 0) {
    reg_eax = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (reg_eax == 0) {
      reg_eax = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (reg_eax == 0) {
        return 0;
      }
      DAT_00413d50 = 2;
    }
    else {
      DAT_00413d50 = 1;
    }
  }
  if (0 < arg_4) {
    reg_eax = wcsncnt(arg_3,arg_4);
    arg_4 = reg_eax;
  }
  if (DAT_00413d50 == 1) {
    val_1 = LCMapStringW((LCID)arg_1,arg_2,arg_3,arg_4,arg_5,arg_6);
    return val_1;
  }
  if (DAT_00413d50 != 2) {
    return reg_eax;
  }
  local_10 = (char *)0x0;
  if (stack_arg == 0) {
    stack_arg = DAT_00413088;
  }
  x = WideCharToMultiByte(stack_arg,0x220,arg_3,arg_4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if (x == 0) {
    return 0;
  }
  lpMultiByteStr = (LPCSTR)__malloc_dbg(x,2,0x410e74,0xcc);
  if (lpMultiByteStr == (LPCSTR)0x0) {
    return 0;
  }
  val_1 = WideCharToMultiByte(stack_arg,0x220,arg_3,arg_4,lpMultiByteStr,x,(LPCSTR)0x0,
                              (LPBOOL)0x0);
  if ((((val_1 == 0) ||
       (local_14 = LCMapStringA((LCID)arg_1,arg_2,lpMultiByteStr,x,(LPSTR)0x0,0), local_14 == 0)) ||
      (local_10 = (char *)__malloc_dbg(local_14,2,0x410e74,0xdb), local_10 == (char *)0x0)) ||
     (val_1 = LCMapStringA((LCID)arg_1,arg_2,lpMultiByteStr,x,local_10,local_14), val_1 == 0)) {
LAB_0040b7e0:
    __free_dbg(lpMultiByteStr,2);
    __free_dbg(local_10,2);
    local_14 = 0;
  }
  else {
    if ((arg_2 & 0x400) == 0) {
      if (arg_6 == 0) {
        local_14 = MultiByteToWideChar(stack_arg,1,local_10,local_14,(LPWSTR)0x0,0);
      }
      else {
        local_14 = MultiByteToWideChar(stack_arg,1,local_10,local_14,arg_5,arg_6);
      }
      if (local_14 == 0) goto LAB_0040b7e0;
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


