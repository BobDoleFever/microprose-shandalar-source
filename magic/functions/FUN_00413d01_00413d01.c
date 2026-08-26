/*
 * Decompiled function: FUN_00413d01
 * Entry Point: 00413d01
 * Size: 140 bytes
 */
#include "magic.h"


undefined4 FUN_00413d01(int arg1,int arg2)

{
  int iVar1;
  
  if ((g_DefendingPlayer == arg1) && (((&DAT_006a5f3d)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) == 0))
  {
    *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 0x8000;
    iVar1 = FUN_004726c5(arg1,arg2);
    if (iVar1 != 0) {
      DAT_006a5f20 = 1;
    }
  }
  return 0;
}


