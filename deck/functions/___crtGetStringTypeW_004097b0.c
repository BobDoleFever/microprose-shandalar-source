/*
 * Decompiled function: ___crtGetStringTypeW
 * Entry Point: 004097b0
 * Size: 607 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___crtGetStringTypeW
   
   Library: Visual Studio 1998 Debug */

void __cdecl
___crtGetStringTypeW(DWORD arg_1,LPCWSTR arg_2,int arg_3,LPWORD arg_4,UINT arg_5,LCID arg_6)

{
  BOOL BVar1;
  int arg_2_00;
  LPCSTR lpMultiByteStr;
  int val_2;
  LPWORD local_10;
  WORD local_8 [2];
  
  if (DAT_0041392c == 0) {
    BVar1 = GetStringTypeW(1,L"",1,local_8);
    if (BVar1 == 0) {
      BVar1 = GetStringTypeA(0,1,"",1,local_8);
      if (BVar1 == 0) {
        return;
      }
      DAT_0041392c = 2;
    }
    else {
      DAT_0041392c = 1;
    }
  }
  if (DAT_0041392c == 1) {
    GetStringTypeW(arg_1,arg_2,arg_3,arg_4);
  }
  else if (DAT_0041392c == 2) {
    local_10 = (LPWORD)0x0;
    if (arg_5 == 0) {
      arg_5 = DAT_00413088;
    }
    arg_2_00 = WideCharToMultiByte(arg_5,0x220,arg_2,arg_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((arg_2_00 != 0) &&
       (lpMultiByteStr = __calloc_dbg(1,arg_2_00,2,"aw_str.c",0x76), lpMultiByteStr != (LPCSTR)0x0))
    {
      val_2 = WideCharToMultiByte(arg_5,0x220,arg_2,arg_3,lpMultiByteStr,arg_2_00,(LPCSTR)0x0,
                                  (LPBOOL)0x0);
      if ((val_2 != 0) &&
         (local_10 = (LPWORD)__malloc_dbg(arg_2_00 * 2 + 2,2,0x410e18,0x80), local_10 != (LPWORD)0x0
         )) {
        if (arg_6 == 0) {
          arg_6 = DAT_00413078;
        }
        local_10[arg_3] = 0xffff;
        local_10[arg_3 + -1] = local_10[arg_3];
        GetStringTypeA(arg_6,arg_1,lpMultiByteStr,arg_2_00,local_10);
        if ((local_10[arg_3 + -1] != 0xffff) && (local_10[arg_3] == 0xffff)) {
          FID_conflict__memcpy(arg_4,local_10,arg_3 * 2);
        }
      }
      __free_dbg(lpMultiByteStr,2);
      __free_dbg(local_10,2);
    }
  }
  return;
}


