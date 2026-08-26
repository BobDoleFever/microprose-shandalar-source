/*
 * Decompiled function: FUN_10009640
 * Entry Point: 10009640
 * Size: 294 bytes
 */
#include "statwin.h"


int __cdecl FUN_10009640(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  int val_1;
  FARPROC pFVar2;
  int local_c;
  
  if (DAT_10012fe4 == 0) {
    DAT_1001e874 = LoadLibraryA(PTR_s_magvid_10012fe8);
    if (DAT_1001e874 == (HMODULE)0x0) {
      val_1 = 7;
    }
    else {
      for (local_c = 0; local_c < 0x13; local_c = local_c + 1) {
        pFVar2 = GetProcAddress(DAT_1001e874,(LPCSTR)(local_c + 1U & 0xffff));
        (&DAT_1001e810)[local_c] = pFVar2;
        if ((&DAT_1001e810)[local_c] == (code *)0x0) {
          FreeLibrary(DAT_1001e874);
          thunk_FUN_10009bda();
          return 7;
        }
      }
      DAT_1001e878 = GetProcAddress(DAT_1001e874,(LPCSTR)(local_c + 1U & 0xffff));
      val_1 = (*DAT_1001e810)(arg_1,arg_2,arg_3);
      if (val_1 == 0) {
        DAT_10012fe4 = 1;
        val_1 = 0;
      }
      else {
        FreeLibrary(DAT_1001e874);
        thunk_FUN_10009bda();
      }
    }
  }
  else {
    val_1 = 6;
  }
  return val_1;
}


