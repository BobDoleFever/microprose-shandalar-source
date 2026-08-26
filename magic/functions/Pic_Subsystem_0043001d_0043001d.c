/*
 * Decompiled function: Pic_Subsystem_0043001d
 * Entry Point: 0043001d
 * Size: 407 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0043001d(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1))
       && (g_ActivePlayerPriority == arg_1)) {
      if (DAT_006b3018 == 0) {
        g_SpellStackDepth = g_SpellStackDepth + -0xf0;
      }
      else {
        iVar2 = FUN_0040d949(g_ActivePlayerPriority,7,1);
        g_SpellStackDepth = g_SpellStackDepth + (iVar2 / 2 + (DAT_006b3018 - _DAT_006b301c)) * 0x18;
      }
    }
    if (((arg_3 == 0x85) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 0x40) !=
         0)) && ((g_OverworldPlayerCoordX == DAT_0063edc0 && (g_DefendingPlayer == DAT_0063edc0))))
    {
      *(uint *)(&g_CardSlot_SpecialState +
               g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) =
           *(uint *)(&g_CardSlot_SpecialState +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) | 3;
      (&DAT_006a6048)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] =
           (&DAT_006a6048)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] + '\x02';
    }
    uVar1 = 0;
  }
  return uVar1;
}


