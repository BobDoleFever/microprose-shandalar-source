/*
 * Decompiled function: ___sbh_find_block
 * Entry Point: 004e2440
 * Size: 162 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 1998 Debug */

int ___sbh_find_block(undefined *arg_1,undefined4 *arg_2,uint *arg_3)

{
  uint uVar1;
  undefined **local_c;
  
  local_c = &PTR_LOOP_005099e0;
  while (((local_c[0x204] == (undefined *)0x0 || (arg_1 <= local_c[0x204])) ||
         (local_c[0x204] + 0x400000 <= arg_1))) {
    local_c = (undefined **)*local_c;
    if (local_c == &PTR_LOOP_005099e0) {
      return 0;
    }
  }
  *arg_2 = local_c;
  uVar1 = (uint)arg_1 & 0xfffff000;
  *arg_3 = uVar1;
  return ((int)((int)arg_1 - (uVar1 + 0x100)) >> 4) + 8 + uVar1;
}


