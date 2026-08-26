/*
 * Decompiled function: Sound_Init
 * Entry Point: 0043d870
 * Size: 351 bytes
 */
#include "duel.h"


int Sound_Init(int hInst,undefined4 hWnd,uint flags)

{
  int iVar1;
  FARPROC pFVar2;
  int local_c;
  
  if (DAT_004f79a4 == 0) {
    DAT_006944c8 = LoadLibraryA(PTR_s_magsnd_004f79ac);
    if (DAT_006944c8 == (HMODULE)0x0) {
      iVar1 = 4;
    }
    else {
      for (local_c = 0; local_c < 0x1b; local_c = local_c + 1) {
        pFVar2 = GetProcAddress(DAT_006944c8,(LPCSTR)(local_c + 1U & 0xffff));
        (&DAT_006944d0)[local_c] = pFVar2;
        if ((&DAT_006944d0)[local_c] == (code *)0x0) {
          FreeLibrary(DAT_006944c8);
          FUN_0043e09c();
          return 4;
        }
      }
      if ((hInst == 0) && ((flags & 2) == 0)) {
        FreeLibrary(DAT_006944c8);
        FUN_0043e09c();
        iVar1 = 5;
      }
      else {
        iVar1 = (*DAT_006944d0)(hInst,hWnd,flags);
        if (iVar1 == 0) {
          DAT_004f79a8 = 1;
          if ((flags & 2) != 0) {
            DAT_004f79a0 = 1;
          }
          DAT_004f79a4 = 1;
          iVar1 = 0;
        }
        else {
          FreeLibrary(DAT_006944c8);
          FUN_0043e09c();
        }
      }
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}


