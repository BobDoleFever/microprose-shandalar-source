/*
 * Decompiled function: Pic_Subsystem_0044b84b
 * Entry Point: 0044b84b
 * Size: 95 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044b84b(void)

{
  uint uVar1;
  
  if (DAT_005239ec == 0) {
    DAT_0067bda8 = 0;
    DAT_0067bda4 = 0;
    DAT_0067bda0 = 0;
  }
  else {
    uVar1 = Mem_AllocOrFree_00512210();
    DAT_0067bda0 = uVar1 | DAT_007039c4;
    DAT_0067bda4 = DAT_007039cc;
    DAT_0067bda8 = DAT_007039c8;
  }
  return;
}


