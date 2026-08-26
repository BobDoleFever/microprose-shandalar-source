/*
 * Decompiled function: __alloc_osfhnd
 * Entry Point: 004e5a50
 * Size: 333 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __alloc_osfhnd
   
   Library: Visual Studio 1998 Debug */

int __cdecl __alloc_osfhnd(void)

{
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  local_c = -1;
  local_10 = 0;
  do {
    if (0x3f < local_10) {
      return local_c;
    }
    if ((&DAT_006c1b90)[local_10] == 0) {
      local_8 = (undefined4 *)__malloc_dbg(0x100,2,"osfinfo.c",0x79);
      if (local_8 == (undefined4 *)0x0) {
        return local_c;
      }
      (&DAT_006c1b90)[local_10] = local_8;
      DAT_006c1c90 = DAT_006c1c90 + 0x20;
      for (; local_8 < (undefined4 *)((&DAT_006c1b90)[local_10] + 0x100); local_8 = local_8 + 2) {
        *(undefined1 *)(local_8 + 1) = 0;
        *local_8 = 0xffffffff;
        *(undefined1 *)((int)local_8 + 5) = 10;
      }
      return local_10 << 5;
    }
    for (local_8 = (undefined4 *)(&DAT_006c1b90)[local_10];
        local_8 < (undefined4 *)((&DAT_006c1b90)[local_10] + 0x100); local_8 = local_8 + 2) {
      if ((*(byte *)(local_8 + 1) & 1) == 0) {
        *local_8 = 0xffffffff;
        local_c = ((int)local_8 - (&DAT_006c1b90)[local_10] >> 3) + local_10 * 0x20;
        break;
      }
    }
    if (local_c != -1) {
      return local_c;
    }
    local_10 = local_10 + 1;
  } while( true );
}


