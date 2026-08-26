/*
 * Decompiled function: FUN_0042b120
 * Entry Point: 0042b120
 * Size: 238 bytes
 */
#include "duel.h"


undefined4 FUN_0042b120(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0048a33f(arg1,arg2);
  if ((((iVar1 == 0) ||
       (((&DAT_004ff5a9)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x10) == 0
       )) || (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) ||
     ((((&DAT_006826ce)[arg2 * 0x120 + arg1 * 0x5b20] & 3) != 0 &&
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) != 0))))
  {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


