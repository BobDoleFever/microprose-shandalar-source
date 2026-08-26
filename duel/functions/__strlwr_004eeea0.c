/*
 * Decompiled function: __strlwr
 * Entry Point: 004eeea0
 * Size: 293 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __strlwr
   
   Library: Visual Studio 1998 Debug */

char * __cdecl __strlwr(char *str_1)

{
  LPSTR arg_6;
  int iVar1;
  BOOL unaff_ESI;
  int unaff_EDI;
  char *local_10;
  uint *local_c;
  
  local_c = (uint *)0x0;
  if (DAT_0050a730 == (_locale_t)0x0) {
    for (local_10 = str_1; *local_10 != '\0'; local_10 = local_10 + 1) {
      if (('@' < *local_10) && (*local_10 < '[')) {
        *local_10 = *local_10 + ' ';
      }
    }
  }
  else {
    arg_6 = (LPSTR)___crtLCMapStringA(DAT_0050a730,(LPCWSTR)0x100,(DWORD)str_1,(LPCSTR)0xffffffff,0,
                                      (LPSTR)0x0,0,unaff_EDI,unaff_ESI);
    if (((arg_6 != (LPSTR)0x0) &&
        (local_c = (uint *)__malloc_dbg(arg_6,2,"strlwr.c",100), local_c != (uint *)0x0)) &&
       (iVar1 = ___crtLCMapStringA(DAT_0050a730,(LPCWSTR)0x100,(DWORD)str_1,(LPCSTR)0xffffffff,
                                   (int)local_c,arg_6,0,unaff_EDI,unaff_ESI), iVar1 != 0)) {
      Mem_AllocOrFree_004d9630((uint *)str_1,local_c);
    }
    __free_dbg(local_c,2);
  }
  return str_1;
}


