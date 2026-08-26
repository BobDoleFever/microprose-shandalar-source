/*
 * Decompiled function: Ai_Subsystem_004b6623
 * Entry Point: 004b6623
 * Size: 115 bytes
 */
#include "magic.h"


uint Ai_Subsystem_004b6623(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    iVar1 = Ai_Subsystem_004b5c4b(arg1,arg2);
    if (iVar1 == -1) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(&DAT_0051aed0 + iVar1 * 0x34) & 0x1000;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


