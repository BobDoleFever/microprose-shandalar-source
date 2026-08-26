/*
 * Decompiled function: Pic_Subsystem_00438995
 * Entry Point: 00438995
 * Size: 856 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_00438995(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      g_SpellStackDepth =
           g_SpellStackDepth +
           (*(int *)(&DAT_006b2e48 + (1 - arg_1) * 0x20) - *(int *)(&DAT_006b2e48 + arg_1 * 0x20));
    }
    if (arg_3 == 0x82) {
      cVar1 = (&DAT_006a5f4d)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      bVar2 = FUN_0041d9d2(arg_1,arg_2,2);
      if (((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0
         )) {
        *(uint *)(&DAT_006a6038 + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
             *(uint *)(&DAT_006a6038 + g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                      ) & 0xfffffffc;
      }
    }
    if (((arg_3 == 0x84) &&
        (((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] & 0x10)
         != 0)) &&
       ((g_DefendingPlayer == g_OverworldPlayerCoordX &&
        ((g_DefendingPlayer == DAT_0063edc0 &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0
         )))))) {
      cVar1 = (&DAT_006a5f4d)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      bVar2 = FUN_0041d9d2(arg_1,arg_2,2);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) {
        *(uint *)(&g_CardSlot_SpecialState +
                 g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
             *(uint *)(&g_CardSlot_SpecialState +
                      g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 0x10;
        (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
             (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] + '\x04'
        ;
      }
    }
    if (arg_3 == 0x6c) {
      cVar1 = (&DAT_006a5f4d)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120];
      bVar2 = FUN_0041d9d2(arg_1,arg_2,2);
      if (((1 << (bVar2 & 0x1f) & (int)cVar1) != 0) &&
         (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0
         )) {
        (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
             (&DAT_006a603c)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] + '\x04'
        ;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


