/*
 * Decompiled function: Pic_Subsystem_00433466
 * Entry Point: 00433466
 * Size: 438 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00433466(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
       (((byte)*(undefined4 *)
                (&g_CardSlot_Flags + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120)
        & 0x22) == 2)) {
      cVar1 = (&DAT_006a5f4d)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      bVar2 = FUN_0041d9d2(arg_1,arg_2,2);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
        g_ActivePalette = g_ActivePalette + 1;
      }
    }
    if (((arg_3 == 0x85) && (g_OverworldMapGrid == arg_2)) &&
       ((g_OverworldPlayerCoordX == arg_1 &&
        ((g_DefendingPlayer == arg_1 && (DAT_0063edc0 == arg_1)))))) {
      *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_SpecialState + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
      (&DAT_006a604a)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006a604a)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x02';
    }
    if (arg_3 == 0x86) {
      Pic_Subsystem_0044867e(g_DialogPromptHwnd,g_DuelArenaHwnd,1);
    }
    if ((arg_3 == 199) && ((int)(&DAT_0063ee38)[arg_1 * 8] < 2)) {
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar3 = 0;
  }
  return uVar3;
}


