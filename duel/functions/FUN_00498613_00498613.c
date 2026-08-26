/*
 * Decompiled function: FUN_00498613
 * Entry Point: 00498613
 * Size: 91 bytes
 */
#include "duel.h"


bool FUN_00498613(int arg1,int arg2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0048ad82(arg1,arg2);
  uVar2 = FUN_00447751(arg1,arg2);
  return (uVar2 & 0x40) != 0 && iVar1 != 0;
}


