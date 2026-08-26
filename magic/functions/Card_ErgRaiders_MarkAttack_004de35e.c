/*
 * Decompiled function: Card_ErgRaiders_MarkAttack
 * Entry Point: 004de35e
 * Size: 308 bytes
 */
#include "magic.h"


undefined4 Card_ErgRaiders_MarkAttack(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if ((((arg_3 == 0x78) && (arg_2 == DAT_006b2d5c)) && (arg_1 == DAT_007006c8)) &&
     ((&DAT_0051aebd)
      [*(int *)(&g_CardSlot_CardId + g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20)
       * 0x34] == '\0')) {
    g_ActivePalette = 1;
  }
  if ((arg_3 == 0x15) && (arg_1 == g_DefendingPlayer)) {
    iVar1 = FUN_004726c5(arg_1,arg_2);
    if (iVar1 != 0) {
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 4;
      DAT_006a5f20 = DAT_006a5f20 + 1;
    }
  }
  if (((arg_3 == 0x22) || (arg_3 == 199)) &&
     ((arg_1 == g_DefendingPlayer &&
      ((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20054) == 0)))) {
    Pic_Subsystem_0044867e(arg_1,arg_2,4);
  }
  return 0;
}


