/*
 * Decompiled function: FUN_005063f6
 * Entry Point: 005063f6
 * Size: 238 bytes
 */
#include "magic.h"


undefined4 FUN_005063f6(int arg1,int arg2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00471c32(arg1,arg2);
  if ((((iVar1 == 0) ||
       (((&DAT_0051aed1)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x10)
        == 0)) || (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0)) ||
     ((((&DAT_006a5f3e)[arg2 * 0x120 + arg1 * 0x5b20] & 3) != 0 &&
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) != 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


