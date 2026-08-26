/*
 * Decompiled function: Ai_Subsystem_004cbc65
 * Entry Point: 004cbc65
 * Size: 106 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004cbc65(int arg1,int arg2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((arg1 == -1) || (arg2 == -1)) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar2 = Ai_Util_004cbc36(arg1,arg2);
    if (iVar2 == -1) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = *(undefined4 *)(&g_MasterCardTypeTable + iVar2 * 0x34);
    }
  }
  return uVar1;
}


