/*
 * Decompiled function: StatWin_LoadSoundDll
 * Entry Point: 100014b0
 * Size: 351 bytes
 */
#include "statwin.h"


int __cdecl StatWin_LoadSoundDll(int arg_1,int32_t arg_2,uint32_t arg_3)

{
  int val_1;
  FARPROC pFVar2;
  int local_c;
  
  if (DAT_10011524 == 0) {
    DAT_1001e87c = LoadLibraryA(PTR_s_magsnd_1001152c);
    if (DAT_1001e87c == (HMODULE)0x0) {
      val_1 = 4;
    }
    else {
      for (local_c = 0; local_c < 0x1b; local_c = local_c + 1) {
        pFVar2 = GetProcAddress(DAT_1001e87c,(LPCSTR)(local_c + 1U & 0xffff));
        (&DAT_1001e8a0)[local_c] = pFVar2;
        if ((&DAT_1001e8a0)[local_c] == (code *)0x0) {
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


