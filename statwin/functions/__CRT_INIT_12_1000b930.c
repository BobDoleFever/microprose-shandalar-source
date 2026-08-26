/*
 * Decompiled function: __CRT_INIT@12
 * Entry Point: 1000b930
 * Size: 505 bytes
 */
#include "statwin.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __CRT_INIT@12
   
   Library: Visual Studio 1998 Debug */

int32_t __CRT_INIT_12(int32_t arg_1,int arg_2)

{
  DWORD DVar1;
  int *local_c;
  char local_8;
  
  if (arg_2 == 0) {
    if (DAT_10013020 < 1) {
      return 0;
    }
    DAT_10013020 = DAT_10013020 + -1;
  }
  if (DAT_10013024 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_10013024 = DAT_10013024 + 1;
    }
    else {
      DAT_10013024 = DAT_10013024 + -1;
    }
  }
  _DAT_1001e90c = *(int32_t *)_adjust_fdiv_exref;
  if (arg_2 == 1) {
    if ((DAT_10013024 < 0) || (DAT_10013020 == 0)) {
      if (DAT_10013024 < 0) {
        DAT_1001e928 = (int *)malloc_dbg(0x80,2,"crtdll.c",200);
        if (DAT_1001e928 == (int *)0x0) {
          return 0;
        }
      }
      else if ((DAT_10013020 == 0) &&
              (DAT_1001e928 = GlobalAlloc(0x2000,0x80), DAT_1001e928 == (int *)0x0)) {
        return 0;
      }
      *DAT_1001e928 = 0;
      DAT_1001e918 = DAT_1001e928;
      initterm(&DAT_10011000,&DAT_10011208);
      DAT_10013020 = DAT_10013020 + 1;
    }
  }
  else if ((arg_2 == 0) &&
          (((DAT_10013024 < 0 || (DAT_10013020 == 0)) && (DAT_1001e928 != (int *)0x0)))) {
    local_c = DAT_1001e918;
    while (local_c = local_c + -1, DAT_1001e928 <= local_c) {
      if (*local_c != 0) {
        (*(code *)*local_c)();
      }
    }
    if (DAT_10013024 < 0) {
      free_dbg(DAT_1001e928,2);
    }
    else {
      GlobalFree(DAT_1001e928);
    }
    DAT_1001e928 = (int *)0x0;
  }
  return 1;
}


