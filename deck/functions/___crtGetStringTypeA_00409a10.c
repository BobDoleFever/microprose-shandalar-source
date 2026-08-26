/*
 * Decompiled function: ___crtGetStringTypeA
 * Entry Point: 00409a10
 * Size: 406 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___crtGetStringTypeA
   
   Library: Visual Studio 1998 Debug */

BOOL __cdecl
___crtGetStringTypeA
          (_locale_t arg_1,DWORD arg_2,LPCSTR arg_3,int arg_4,LPWORD arg_5,int arg_6,BOOL arg_7)

{
  BOOL reg_eax;
  int val_1;
  LPCWSTR local_14;
  BOOL local_c;
  WORD local_8 [2];
  
  local_c = reg_eax;
  if (DAT_00413930 == 0) {
    local_c = GetStringTypeA(0,1,"",1,local_8);
    if (local_c == 0) {
      local_c = GetStringTypeW(1,L"",1,local_8);
      if (local_c == 0) {
        return 0;
      }
      DAT_00413930 = 1;
    }
    else {
      DAT_00413930 = 2;
    }
  }
  if (DAT_00413930 == 2) {
    if (arg_6 == 0) {
      arg_6 = DAT_00413078;
    }
    local_c = GetStringTypeA(arg_6,(DWORD)arg_1,(LPCSTR)arg_2,(int)arg_3,(LPWORD)arg_4);
  }
  else if (DAT_00413930 == 1) {
    local_c = 0;
    local_14 = (LPCWSTR)0x0;
    if (arg_5 == (LPWORD)0x0) {
      arg_5 = DAT_00413088;
    }
    val_1 = MultiByteToWideChar((UINT)arg_5,9,(LPCSTR)arg_2,(int)arg_3,(LPWSTR)0x0,0);
    if (((val_1 != 0) &&
        (local_14 = (LPCWSTR)__calloc_dbg(2,val_1,2,"aw_str.c",0x104), local_14 != (LPCWSTR)0x0)) &&
       (val_1 = MultiByteToWideChar((UINT)arg_5,1,(LPCSTR)arg_2,(int)arg_3,local_14,val_1),
       val_1 != 0)) {
      local_c = GetStringTypeW((DWORD)arg_1,local_14,val_1,(LPWORD)arg_4);
    }
    __free_dbg(local_14,2);
  }
  return local_c;
}


