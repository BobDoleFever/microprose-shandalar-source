/*
 * Decompiled function: FUN_0048ec9a
 * Entry Point: 0048ec9a
 * Size: 106 bytes
 */
#include "magic.h"


int FUN_0048ec9a(int arg1,int arg2)

{
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0xe < local_8) {
      return -1;
    }
    if ((*(int *)(&DAT_0067f000 + local_8 * 0x30) == arg1) &&
       (*(int *)(&DAT_0067f004 + local_8 * 0x30) == arg2)) break;
    local_8 = local_8 + 1;
  }
  return local_8;
}


