/*
 * Decompiled function: FUN_0040f681
 * Entry Point: 0040f681
 * Size: 104 bytes
 */
#include "magic.h"


int FUN_0040f681(int *arg1,undefined4 *arg2)

{
  int local_8;
  
  local_8 = 1;
  *arg2 = arg1;
  for (; (char)*arg1 != '\0'; arg1 = (int *)((int)arg1 + 1)) {
    if (*arg1 == 0xa0a0a0a) {
      arg2[local_8] = arg1 + 1;
      local_8 = local_8 + 1;
    }
  }
  arg2[local_8] = arg1;
  return local_8;
}


