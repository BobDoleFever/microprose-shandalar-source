/*
 * Decompiled function: FUN_0040a444
 * Entry Point: 0040a444
 * Size: 104 bytes
 */
#include "magic.h"


int FUN_0040a444(void)

{
  int iVar1;
  undefined4 local_8;
  
  if (g_IsAiThinking == 0) {
    do {
      Pic_Subsystem_0044b84b();
      if (DAT_0067bda0 != 0) break;
      iVar1 = Mem_AllocOrFree_00408089();
    } while (iVar1 == 0);
    local_8 = DAT_0067bda0;
    if (DAT_0067bda0 == 0) {
      local_8 = FUN_0048ac2f();
    }
    FUN_0040a3e1();
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


