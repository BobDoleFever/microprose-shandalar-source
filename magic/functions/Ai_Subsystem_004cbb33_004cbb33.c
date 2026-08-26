/*
 * Decompiled function: Ai_Subsystem_004cbb33
 * Entry Point: 004cbb33
 * Size: 106 bytes
 */
#include "magic.h"


uint Ai_Subsystem_004cbb33(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = Ai_Util_004cbc36(arg1,arg2);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else if (((&DAT_0051aed0)[iVar1 * 0x34] & 0x20) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = Ai_Util_004cbb04(arg1,arg2);
    uVar2 = uVar2 & 0xf;
  }
  return uVar2;
}


