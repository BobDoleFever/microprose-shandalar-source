/*
 * Decompiled function: ___wtomb_environ
 * Entry Point: 004ed720
 * Size: 205 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___wtomb_environ
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___wtomb_environ(void)

{
  int iVar1;
  char **str_1;
  int *local_8;
  
  local_8 = DAT_00509450;
  while( true ) {
    if (*local_8 == 0) {
      return 0;
    }
    iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*local_8,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) {
      return -1;
    }
    str_1 = (char **)__malloc_dbg(iVar1,2,"wtombenv.c",0x3d);
    if (str_1 == (char **)0x0) {
      return -1;
    }
    iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*local_8,-1,(LPSTR)str_1,iVar1,(LPCSTR)0x0,(LPBOOL)0x0)
    ;
    if (iVar1 == 0) break;
    ___crtsetenv(str_1,0);
    local_8 = local_8 + 1;
  }
  return -1;
}


