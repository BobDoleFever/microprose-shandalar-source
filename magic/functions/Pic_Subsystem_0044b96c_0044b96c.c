/*
 * Decompiled function: Pic_Subsystem_0044b96c
 * Entry Point: 0044b96c
 * Size: 81 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0044b96c(int arg_1)

{
  int iVar1;
  
  if ((arg_1 != 0) && (g_IsAiThinking != 1)) {
    Mem_AllocOrFree_005016f9();
    do {
      iVar1 = Mem_AllocOrFree_00501721();
    } while (iVar1 < DAT_0052244c * arg_1);
  }
  return 0;
}


