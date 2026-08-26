/*
 * Decompiled function: __getstream
 * Entry Point: 004e3540
 * Size: 274 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __getstream
   
   Library: Visual Studio 1998 Debug */

FILE * __cdecl __getstream(void)

{
  undefined4 uVar1;
  FILE *local_c;
  int local_8;
  
  local_c = (FILE *)0x0;
  local_8 = 0;
  do {
    if (DAT_006c2ca0 <= local_8) {
LAB_004e35fb:
      if (local_c != (FILE *)0x0) {
        local_c->_cnt = 0;
        local_c->_flag = local_c->_cnt;
        local_c->_base = (char *)0x0;
        local_c->_ptr = local_c->_base;
        local_c->_tmpfname = local_c->_ptr;
        local_c->_file = -1;
      }
      return local_c;
    }
    if (*(int *)(DAT_006c1c98 + local_8 * 4) == 0) {
      uVar1 = __malloc_dbg(0x20,2,"stream.c",0x55);
      *(undefined4 *)(DAT_006c1c98 + local_8 * 4) = uVar1;
      if (*(int *)(DAT_006c1c98 + local_8 * 4) != 0) {
        local_c = *(FILE **)(DAT_006c1c98 + local_8 * 4);
      }
      goto LAB_004e35fb;
    }
    if ((*(byte *)(*(int *)(DAT_006c1c98 + local_8 * 4) + 0xc) & 0x83) == 0) {
      local_c = *(FILE **)(DAT_006c1c98 + local_8 * 4);
      goto LAB_004e35fb;
    }
    local_8 = local_8 + 1;
  } while( true );
}


