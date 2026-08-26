/*
 * Decompiled function: FUN_00433c39
 * Entry Point: 00433c39
 * Size: 77 bytes
 */
#include "duel.h"


int FUN_00433c39(char *str_1)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  for (; *str_1 != '\0'; str_1 = str_1 + 1) {
    iVar1 = Mem_AllocOrFree_0049f725(*(undefined4 *)(DAT_005f6c50 + 0x20),*str_1);
    local_8 = local_8 + iVar1;
  }
  return local_8;
}


