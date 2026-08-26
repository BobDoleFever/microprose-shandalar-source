/*
 * Decompiled function: Ai_Subsystem_004b613b
 * Entry Point: 004b613b
 * Size: 108 bytes
 */
#include "magic.h"


undefined1 Ai_Subsystem_004b613b(int arg1,int arg2)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar2 == 0) {
    iVar2 = Ai_Subsystem_004b5c4b(arg1,arg2);
    if (iVar2 == -1) {
      uVar1 = 0;
    }
    else {
      uVar1 = (&g_MasterCardColorTable)[iVar2 * 0x34];
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


