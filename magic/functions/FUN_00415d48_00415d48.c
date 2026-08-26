/*
 * Decompiled function: FUN_00415d48
 * Entry Point: 00415d48
 * Size: 176 bytes
 */
#include "magic.h"


undefined4 FUN_00415d48(int arg1,int arg2)

{
  if (((&g_CardSlot_Flags)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
    *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) | 0x10;
    if (((&g_MasterCardColorTable)
         [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 1) != 0) {
      DAT_006ff2d4 = 0xffffffff;
    }
    FUN_00473e69(arg1,arg2,0x81);
  }
  return 0;
}


