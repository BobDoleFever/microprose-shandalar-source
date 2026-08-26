/*
 * Decompiled function: Minit_Subsystem_0045f4af
 * Entry Point: 0045f4af
 * Size: 467 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_0045f4af(int x,int y,int width,int height)

{
  byte bVar1;
  int iVar2;
  
  if (((width == 0x6c) && (g_OverworldMapGrid == y)) && (g_OverworldPlayerCoordX == x)) {
    g_SpellStackDepth =
         g_SpellStackDepth +
         *(int *)(&DAT_0063ee30 + height * 4 + g_ActivePlayerPriority * 0x20) * 0xc;
  }
  if (((g_PlayerManaPool == 0xd3) && (g_OverworldMapGrid == y)) &&
     ((g_OverworldPlayerCoordX == x &&
      ((DAT_006a4b5c == x && (((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x20) == 0)))))) {
    iVar2 = FUN_0040d949(x,7,1);
    if (iVar2 != 0) {
      bVar1 = FUN_0041d9d2(x,y,height);
      if (((1 << (bVar1 & 0x1f) &
           (int)(char)(&DAT_006a5f4d)[DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20]) != 0) &&
         ((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId + DAT_006b2e14 * 0x120 + DAT_00695f08 * 0x5b20) * 0x34] !=
          '\x01')) {
        if (width == 0x7d) {
          if (g_ActivePlayerPriority == x) {
            g_ActivePalette = g_ActivePalette | 2;
          }
          else {
            g_ActivePalette = g_ActivePalette | 1;
          }
        }
        if (width == 0x7e) {
          Ai_CalcManaRequirement_004ba890(x,0,1);
          if ((g_ActivePlayer != 1) &&
             ((&g_PlayerCreatureCount)[x] = (&g_PlayerCreatureCount)[x] + 1,
             g_ActivePlayerPriority == x)) {
            g_SpellStackDepth = g_SpellStackDepth + -0x18;
          }
        }
      }
    }
  }
  return 0;
}


