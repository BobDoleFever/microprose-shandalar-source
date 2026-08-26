/*
 * Decompiled function: __CRT_INIT@12
 * Entry Point: 1003d970
 * Size: 505 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __CRT_INIT@12
   
   Library: Visual Studio 1998 Debug */

int32_t __CRT_INIT_12(int32_t arg1,int arg2)

{
  DWORD DVar1;
  int *local_c;
  char local_8;
  
  if (arg2 == 0) {
    if (DAT_1004bda0 < 1) {
      return 0;
    }
    DAT_1004bda0 = DAT_1004bda0 + -1;
  }
  if (DAT_1004bda4 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_1004bda4 = DAT_1004bda4 + 1;
    }
    else {
      DAT_1004bda4 = DAT_1004bda4 + -1;
    }
  }
  _DAT_102151ec = *(int32_t *)_adjust_fdiv_exref;
  if (arg2 == 1) {
    if ((DAT_1004bda4 < 0) || (DAT_1004bda0 == 0)) {
      if (DAT_1004bda4 < 0) {
        DAT_10215208 = (int *)malloc_dbg(0x80,2,"crtdll.c",200);
        if (DAT_10215208 == (int *)0x0) {
          return 0;
        }
      }
      else if ((DAT_1004bda0 == 0) &&
              (DAT_10215208 = GlobalAlloc(0x2000,0x80), DAT_10215208 == (int *)0x0)) {
        return 0;
      }
      *DAT_10215208 = 0;
      DAT_102151f8 = DAT_10215208;
      initterm(&DAT_10040000,&DAT_10040104);
      DAT_1004bda0 = DAT_1004bda0 + 1;
    }
  }
  else if ((arg2 == 0) &&
          (((DAT_1004bda4 < 0 || (DAT_1004bda0 == 0)) && (DAT_10215208 != (int *)0x0)))) {
    local_c = DAT_102151f8;
    while (local_c = local_c + -1, DAT_10215208 <= local_c) {
      if (*local_c != 0) {
        (*(code *)*local_c)();
      }
    }
    if (DAT_1004bda4 < 0) {
      free_dbg(DAT_10215208,2);
    }
    else {
      GlobalFree(DAT_10215208);
    }
    DAT_10215208 = (int *)0x0;
  }
  return 1;
}


