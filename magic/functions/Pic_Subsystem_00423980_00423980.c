/*
 * Decompiled function: Pic_Subsystem_00423980
 * Entry Point: 00423980
 * Size: 353 bytes
 */
#include "magic.h"


int Pic_Subsystem_00423980(int hInst,undefined4 hWnd,uint flags)

{
  int iVar1;
  FARPROC pFVar2;
  int local_c;
  
  if (DAT_00520d44 == 0) {
    DAT_0067f3c8 = LoadLibraryA(PTR_s_magsnd_00520d4c);
    if (DAT_0067f3c8 == (HMODULE)0x0) {
      iVar1 = 4;
    }
    else {
      for (local_c = 0; local_c < 0x1b; local_c = local_c + 1) {
        pFVar2 = GetProcAddress(DAT_0067f3c8,(LPCSTR)(local_c + 1U & 0xffff));
        (&DAT_0067f3d0)[local_c] = pFVar2;
        if ((&DAT_0067f3d0)[local_c] == (code *)0x0) {
          FreeLibrary(DAT_0067f3c8);
          Pic_Subsystem_004241ae();
          return 4;
        }
      }
      if ((hInst == 0) && ((flags & 2) == 0)) {
        FreeLibrary(DAT_0067f3c8);
        Pic_Subsystem_004241ae();
        iVar1 = 5;
      }
      else {
        iVar1 = (*DAT_0067f3d0)(hInst,hWnd,flags);
        if (iVar1 == 0) {
          DAT_00520d48 = 1;
          if ((flags & 2) != 0) {
            DAT_00520d40 = 1;
          }
          DAT_00520d44 = 1;
          iVar1 = 0;
        }
        else {
          FreeLibrary(DAT_0067f3c8);
          Pic_Subsystem_004241ae();
        }
      }
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}


