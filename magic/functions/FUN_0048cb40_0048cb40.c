/*
 * Decompiled function: FUN_0048cb40
 * Entry Point: 0048cb40
 * Size: 84 bytes
 */
#include "magic.h"


int FUN_0048cb40(void)

{
  int iVar1;
  char local_108 [260];
  
  if (DAT_00527c4c == -1) {
    GetCurrentDirectoryA(0x100,local_108);
    s_D_MAGIC0_SVE_00527b48[0] = local_108[0];
  }
  iVar1 = tolower((int)s_D_MAGIC0_SVE_00527b48[0]);
  return iVar1 + -0x61;
}


