/*
 * Decompiled function: Ai_Subsystem_004b65bf
 * Entry Point: 004b65bf
 * Size: 100 bytes
 */
#include "magic.h"


uint Ai_Subsystem_004b65bf(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  uint local_8;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    uVar2 = Ai_Subsystem_004b6432(arg1,arg2);
    local_8 = (uint)((uVar2 & 0x1000) != 0);
  }
  else {
    local_8 = 0xffffffff;
  }
  return local_8;
}


