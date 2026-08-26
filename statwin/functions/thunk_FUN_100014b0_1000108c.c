/*
 * Decompiled function: thunk_FUN_100014b0
 * Entry Point: 1000108c
 * Size: 5 bytes
 */
#include "statwin.h"


int __cdecl thunk_FUN_100014b0(int arg_1,int32_t arg_2,uint32_t arg_3)

{
  int val_1;
  FARPROC pFVar2;
  int iStack_c;
  
  if (DAT_10011524 == 0) {
    DAT_1001e87c = LoadLibraryA(PTR_s_magsnd_1001152c);
    if (DAT_1001e87c == (HMODULE)0x0) {
      val_1 = 4;
    }
    else {
      for (iStack_c = 0; iStack_c < 0x1b; iStack_c = iStack_c + 1) {
        pFVar2 = GetProcAddress(DAT_1001e87c,(LPCSTR)(iStack_c + 1U & 0xffff));
        (&DAT_1001e8a0)[iStack_c] = pFVar2;
        if ((&DAT_1001e8a0)[iStack_c] == (code *)0x0) {
          FreeLibrary(DAT_1001e87c);
          thunk_FUN_10001cdc();
          return 4;
        }
      }
      if ((arg_1 == 0) && ((arg_3 & 2) == 0)) {
        FreeLibrary(DAT_1001e87c);
        thunk_FUN_10001cdc();
        val_1 = 5;
      }
      else {
        val_1 = (*DAT_1001e8a0)(arg_1,arg_2,arg_3);
        if (val_1 == 0) {
          DAT_10011528 = 1;
          if ((arg_3 & 2) != 0) {
            DAT_10011520 = 1;
          }
          DAT_10011524 = 1;
          val_1 = 0;
        }
        else {
          FreeLibrary(DAT_1001e87c);
          thunk_FUN_10001cdc();
        }
      }
    }
  }
  else {
    val_1 = 2;
  }
  return val_1;
}


