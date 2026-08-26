/*
 * Decompiled function: __setargv
 * Entry Point: 00401c30
 * Size: 204 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setargv(void)

{
  uint8_t *local_14;
  int local_10;
  int32_t *local_c;
  int local_8;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_00414228,0x104);
  DAT_00412aa4 = &DAT_00414228;
  if (*DAT_00415818 == 0) {
    local_14 = &DAT_00414228;
  }
  else {
    local_14 = DAT_00415818;
  }
  parse_cmdline(local_14,(int32_t *)0x0,(uint8_t *)0x0,&local_10,&local_8);
  local_c = (int32_t *)__malloc_dbg(local_10 * 4 + local_8,2,0x410070,0x75);
  if (local_c == (int32_t *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(local_14,local_c,(uint8_t *)(local_c + local_10),&local_10,&local_8);
  _DAT_00412a88 = local_10 + -1;
  _DAT_00412a8c = local_c;
  return (int)local_c;
}


