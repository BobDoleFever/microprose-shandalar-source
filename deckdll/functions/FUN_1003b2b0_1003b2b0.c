/*
 * Decompiled function: FUN_1003b2b0
 * Entry Point: 1003b2b0
 * Size: 353 bytes
 */
#include "deckdll.h"


int FUN_1003b2b0(int arg_1,int32_t arg_2,uint32_t arg_3)

{
  int val_1;
  FARPROC pFVar2;
  int local_c;
  
  if (DAT_1004bb90 == 0) {
    DAT_1013ee64 = LoadLibraryA(PTR_s_magsnd_1004bb98);
    if (DAT_1013ee64 == (HMODULE)0x0) {
      val_1 = 4;
    }
    else {
      for (local_c = 0; local_c < 0x1b; local_c = local_c + 1) {
        pFVar2 = GetProcAddress(DAT_1013ee64,(LPCSTR)(local_c + 1U & 0xffff));
        (&DAT_1013ee90)[local_c] = pFVar2;
        if ((&DAT_1013ee90)[local_c] == (code *)0x0) {
          FreeLibrary(DAT_1013ee64);
          thunk_FUN_1003bade();
          return 4;
        }
      }
      if ((arg_1 == 0) && ((arg_3 & 2) == 0)) {
        FreeLibrary(DAT_1013ee64);
        thunk_FUN_1003bade();
        val_1 = 5;
      }
      else {
        val_1 = (*DAT_1013ee90)(arg_1,arg_2,arg_3);
        if (val_1 == 0) {
          DAT_1004bb94 = 1;
          if ((arg_3 & 2) != 0) {
            DAT_1004bb8c = 1;
          }
          DAT_1004bb90 = 1;
          val_1 = 0;
        }
        else {
          FreeLibrary(DAT_1013ee64);
          thunk_FUN_1003bade();
        }
      }
    }
  }
  else {
    val_1 = 2;
  }
  return val_1;
}


