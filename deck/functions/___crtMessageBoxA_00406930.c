/*
 * Decompiled function: ___crtMessageBoxA
 * Entry Point: 00406930
 * Size: 223 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___crtMessageBoxA(LPCSTR arg_1,LPCSTR arg_2,UINT arg_3)

{
  HMODULE hModule;
  int val_1;
  int local_8;
  
  local_8 = 0;
  if (DAT_004138b0 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_004138b0 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_004138b0 != (FARPROC)0x0) {
        DAT_004138b4 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_004138b8 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_004069b5;
      }
    }
    val_1 = 0;
  }
  else {
LAB_004069b5:
    if (DAT_004138b4 != (FARPROC)0x0) {
      local_8 = (*DAT_004138b4)();
    }
    if ((local_8 != 0) && (DAT_004138b8 != (FARPROC)0x0)) {
      local_8 = (*DAT_004138b8)(local_8);
    }
    val_1 = (*DAT_004138b0)(local_8,arg_1,arg_2,arg_3);
  }
  return val_1;
}


