/*
 * Decompiled function: Card_RockHydra_RegrowHead
 * Entry Point: 004e378b
 * Size: 970 bytes
 */
#include "magic.h"


undefined4 Card_RockHydra_RegrowHead(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int local_8;
  
  if (((arg_3 == 0x6c) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = g_TurnCounter;
  }
  if (((arg_3 == 2) && (arg_2 == g_OverworldMapGrid)) &&
     ((arg_1 == g_OverworldPlayerCoordX && (iVar2 = FUN_0040d949(arg_1,4,3), iVar2 != 0)))) {
    g_ActivePalette = g_ActivePalette | 1;
  }
  if ((arg_2 == g_OverworldMapGrid) && (arg_1 == g_OverworldPlayerCoordX)) {
    if ((arg_3 == 0x32) || (arg_3 == 0x33)) {
      g_ActivePalette =
           g_ActivePalette +
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    if ((((arg_3 == 0x6e) &&
         ((char)(&g_CardSlot_Toughness)
                [g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20] == arg_1)) &&
        (*(int *)(&g_CardSlot_OriginalCardId +
                 g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) == arg_2)) &&
       (*(int *)(&g_CardSlot_ConvertedManaCost +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) != 0)) {
      for (local_8 = 0;
          local_8 < *(int *)(&g_CardSlot_ConvertedManaCost +
                            g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20);
          local_8 = local_8 + 1) {
        bVar1 = false;
        iVar2 = FUN_0040d949(arg_1,4,1);
        if ((iVar2 != 0) &&
           (iVar2 = Ai_Subsystem_004cc56d
                              (arg_1,arg_1,arg_2,-1,-1,s_Restore_Hydra_Head__Never_mind__0052ef14,0)
           , iVar2 == 0)) {
          Ai_CalcManaRequirement_004ba890(arg_1,4,1);
          if (g_ActivePlayer == 1) {
            g_ActivePlayer = -1;
          }
          else {
            bVar1 = true;
          }
        }
        if (!bVar1) break;
        *(int *)(&g_CardSlot_ConvertedManaCost +
                g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost +
                     g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) + -1;
      }
      iVar2 = FUN_0040a305(*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20),
                           0,*(int *)(&g_CardSlot_ConvertedManaCost +
                                     g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20))
      ;
      *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) - iVar2;
      *(int *)(&g_CardSlot_ConvertedManaCost +
              g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) =
           *(int *)(&g_CardSlot_ConvertedManaCost +
                   g_OverworldMapGrid * 0x120 + g_OverworldPlayerCoordX * 0x5b20) - iVar2;
    }
    if (((arg_3 == 4) && (arg_2 == g_OverworldMapGrid)) &&
       ((arg_1 == g_OverworldPlayerCoordX &&
        ((iVar2 = FUN_0040d949(arg_1,4,3), iVar2 != 0 &&
         (iVar2 = Ai_Subsystem_004cc56d
                            (arg_1,arg_1,arg_2,-1,-1,s_Grow_new_Hydra_head__Never_mind__0052ef38,0),
         iVar2 == 0)))))) {
      Ai_CalcManaRequirement_004ba890(arg_1,4,3);
      if (g_ActivePlayer == 1) {
        g_ActivePlayer = -1;
      }
      else {
        *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
      }
    }
  }
  return 0;
}


