/*
 * Decompiled function: Ai_Subsystem_004b5cbb
 * Entry Point: 004b5cbb
 * Size: 110 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004b5cbb(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ai_Subsystem_004b5919(arg1,arg2);
  if (iVar1 == 0) {
    iVar1 = Ai_Subsystem_004b5c4b(arg1,arg2);
    if (iVar1 == -1) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = *(undefined4 *)(&g_MasterCardTypeTable + iVar1 * 0x34);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


