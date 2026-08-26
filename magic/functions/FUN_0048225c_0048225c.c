/*
 * Decompiled function: FUN_0048225c
 * Entry Point: 0048225c
 * Size: 91 bytes
 */
#include "magic.h"


bool FUN_0048225c(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_004726c5(arg1,arg2);
  uVar2 = Ai_Subsystem_004b6288(arg1,arg2);
  return (uVar2 & 0x40) != 0 && iVar1 != 0;
}


