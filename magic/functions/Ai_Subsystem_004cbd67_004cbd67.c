/*
 * Decompiled function: Ai_Subsystem_004cbd67
 * Entry Point: 004cbd67
 * Size: 61 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004cbd67(uint arg_1)

{
  undefined4 uVar1;
  
                    /* 0xcbd67  1  CardIDFromType */
  if (arg_1 == 0xffffffff) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(&g_MasterCardTypeTable + (arg_1 & 0xfff) * 0x34);
  }
  return uVar1;
}


