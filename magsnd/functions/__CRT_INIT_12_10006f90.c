/*
 * Decompiled function: __CRT_INIT@12
 * Entry Point: 10006f90
 * Size: 505 bytes
 */
#include "magsnd.h"


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
    if (DAT_1000a530 < 1) {
      return 0;
    }
    DAT_1000a530 = DAT_1000a530 + -1;
  }
  if (DAT_1000a534 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_1000a534 = DAT_1000a534 + 1;
    }
    else {
      DAT_1000a534 = DAT_1000a534 + -1;
    }
  }
  _DAT_1000bf50 = *(int32_t *)_adjust_fdiv_exref;
  if (arg_2 == 1) {
    if ((DAT_1000a534 < 0) || (DAT_1000a530 == 0)) {
      if (DAT_1000a534 < 0) {
        DAT_1000bf6c = (int *)malloc_dbg(0x80,2,"crtdll.c",200);
        if (DAT_1000bf6c == (int *)0x0) {
          return 0;
        }
      }
      else if ((DAT_1000a530 == 0) &&
              (DAT_1000bf6c = GlobalAlloc(0x2000,0x80), DAT_1000bf6c == (int *)0x0)) {
        return 0;
      }
      *DAT_1000bf6c = 0;
      DAT_1000bf5c = DAT_1000bf6c;
      initterm(&DAT_1000a000,&DAT_1000a104);
      DAT_1000a530 = DAT_1000a530 + 1;
    }
  }
  else if ((arg_2 == 0) &&
          (((DAT_1000a534 < 0 || (DAT_1000a530 == 0)) && (DAT_1000bf6c != (int *)0x0)))) {
    local_c = DAT_1000bf5c;
    while (local_c = local_c + -1, DAT_1000bf6c <= local_c) {
      if (*local_c != 0) {
        (*(code *)*local_c)();
      }
    }
    if (DAT_1000a534 < 0) {
      free_dbg(DAT_1000bf6c,2);
    }
    else {
      GlobalFree(DAT_1000bf6c);
    }
    DAT_1000bf6c = (int *)0x0;
  }
  return 1;
}


