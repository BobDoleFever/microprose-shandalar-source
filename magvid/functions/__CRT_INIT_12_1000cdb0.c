/*
 * Decompiled function: __CRT_INIT@12
 * Entry Point: 1000cdb0
 * Size: 505 bytes
 */
#include "magvid.h"


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
    if (DAT_10010738 < 1) {
      return 0;
    }
    DAT_10010738 = DAT_10010738 + -1;
  }
  if (DAT_10010730 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_10010730 = DAT_10010730 + 1;
    }
    else {
      DAT_10010730 = DAT_10010730 + -1;
    }
  }
  _DAT_10032cdc = *(int32_t *)_adjust_fdiv_exref;
  if (arg_2 == 1) {
    if ((DAT_10010730 < 0) || (DAT_10010738 == 0)) {
      if (DAT_10010730 < 0) {
        DAT_10032d04 = (int *)malloc_dbg(0x80,2,"crtdll.c",200);
        if (DAT_10032d04 == (int *)0x0) {
          return 0;
        }
      }
      else if ((DAT_10010738 == 0) &&
              (DAT_10032d04 = GlobalAlloc(0x2000,0x80), DAT_10032d04 == (int *)0x0)) {
        return 0;
      }
      *DAT_10032d04 = 0;
      DAT_10032cf4 = DAT_10032d04;
      initterm(&DAT_10010000,&DAT_1001021c);
      DAT_10010738 = DAT_10010738 + 1;
    }
  }
  else if ((arg_2 == 0) &&
          (((DAT_10010730 < 0 || (DAT_10010738 == 0)) && (DAT_10032d04 != (int *)0x0)))) {
    local_c = DAT_10032cf4;
    while (local_c = local_c + -1, DAT_10032d04 <= local_c) {
      if (*local_c != 0) {
        (*(code *)*local_c)();
      }
    }
    if (DAT_10010730 < 0) {
      free_dbg(DAT_10032d04,2);
    }
    else {
      GlobalFree(DAT_10032d04);
    }
    DAT_10032d04 = (int *)0x0;
  }
  return 1;
}


