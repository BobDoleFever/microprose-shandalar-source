/*
 * Decompiled function: ___crtMessageBoxA
 * Entry Point: 004e0ca0
 * Size: 223 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___crtMessageBoxA(LPCSTR arg_1,LPCSTR arg_2,UINT arg_3)

{
  HMODULE hModule;
  int iVar1;
  int local_8;
  
  local_8 = 0;
  if (DAT_00509744 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_00509744 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_00509744 != (FARPROC)0x0) {
        DAT_00509748 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_0050974c = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_004e0d25;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_004e0d25:
    if (DAT_00509748 != (FARPROC)0x0) {
      local_8 = (*DAT_00509748)();
    }
    if ((local_8 != 0) && (DAT_0050974c != (FARPROC)0x0)) {
      local_8 = (*DAT_0050974c)(local_8);
    }
    iVar1 = (*DAT_00509744)(local_8,arg_1,arg_2,arg_3);
  }
  return iVar1;
}


