/*
 * Decompiled function: __setargv
 * Entry Point: 004e7bf0
 * Size: 204 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setargv(void)

{
  byte *local_14;
  int local_10;
  undefined4 *local_c;
  int local_8;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_005edb18,0x104);
  DAT_00509458 = &DAT_005edb18;
  if (*DAT_006c2ca8 == 0) {
    local_14 = &DAT_005edb18;
  }
  else {
    local_14 = DAT_006c2ca8;
  }
  parse_cmdline(local_14,(undefined4 *)0x0,(byte *)0x0,&local_10,&local_8);
  local_c = (undefined4 *)__malloc_dbg(local_10 * 4 + local_8,2,"stdargv.c",0x75);
  if (local_c == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(local_14,local_c,(byte *)(local_c + local_10),&local_10,&local_8);
  _DAT_0050943c = local_10 + -1;
  _DAT_00509440 = local_c;
  return (int)local_c;
}


