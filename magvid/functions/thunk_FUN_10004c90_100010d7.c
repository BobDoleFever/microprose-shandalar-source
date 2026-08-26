/*
 * Decompiled function: thunk_FUN_10004c90
 * Entry Point: 100010d7
 * Size: 5 bytes
 */
#include "magvid.h"


int __cdecl thunk_FUN_10004c90(int arg_1,int32_t arg_2,uint32_t arg_3)

{
  int val_1;
  FARPROC pFVar2;
  int iStack_c;
  
  if (DAT_10010584 == 0) {
    DAT_10032c44 = LoadLibraryA(PTR_s_magsnd_1001058c);
    if (DAT_10032c44 == (HMODULE)0x0) {
      val_1 = 4;
    }
    else {
      for (iStack_c = 0; iStack_c < 0x1b; iStack_c = iStack_c + 1) {
        pFVar2 = GetProcAddress(DAT_10032c44,(LPCSTR)(iStack_c + 1U & 0xffff));
        (&DAT_10032c70)[iStack_c] = pFVar2;
        if ((&DAT_10032c70)[iStack_c] == (code *)0x0) {
          FreeLibrary(DAT_10032c44);
          thunk_FUN_100054bc();
          return 4;
        }
      }
      if ((arg_1 == 0) && ((arg_3 & 2) == 0)) {
        FreeLibrary(DAT_10032c44);
        thunk_FUN_100054bc();
        val_1 = 5;
      }
      else {
        val_1 = (*DAT_10032c70)(arg_1,arg_2,arg_3);
        if (val_1 == 0) {
          DAT_10010588 = 1;
          if ((arg_3 & 2) != 0) {
            DAT_10010580 = 1;
          }
          DAT_10010584 = 1;
          val_1 = 0;
        }
        else {
          FreeLibrary(DAT_10032c44);
          thunk_FUN_100054bc();
        }
      }
    }
  }
  else {
    val_1 = 2;
  }
  return val_1;
}


