/*
 * Decompiled function: Pic_Subsystem_0042b5f5
 * Entry Point: 0042b5f5
 * Size: 1209 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0042b5f5(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      CardQuery_ForEachPermanent(Pic_Subsystem_0042baae,-1);
    }
    if ((arg_3 == 0x3c) && ((g_PlayerHandCardCount._2_1_ & 2) == 0)) {
      iVar3 = FUN_00471c32(arg_1,arg_2);
      if ((iVar3 != 0) &&
         ((g_OverworldMapGrid != -1 &&
          (((&g_MasterCardColorTable)[g_ActivePalette * 0x34] & 0x42) == 0x40)))) {
        local_10 = 0;
        bVar1 = false;
        while( true ) {
          iVar3 = (&g_PlayerActiveCardCount)[g_ActivePlayerPriority];
          if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <=
              (int)(&g_PlayerActiveCardCount)[g_CurrentTurnPhase]) {
            iVar3 = (&g_PlayerActiveCardCount)[g_CurrentTurnPhase];
          }
          if ((iVar3 <= local_10) || (bVar1)) break;
          if (((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + g_CurrentTurnPhase * 0x5b20) ==
                DAT_00695edc) &&
              (((&g_CardSlot_Flags)[local_10 * 0x120 + g_CurrentTurnPhase * 0x5b20] & 2) != 0)) &&
             (((char)(&g_CardSlot_Toughness)[local_10 * 0x120 + g_CurrentTurnPhase * 0x5b20] ==
               g_OverworldPlayerCoordX &&
              (*(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x120 + g_CurrentTurnPhase * 0x5b20)
               == g_OverworldMapGrid)))) {
            bVar1 = true;
          }
          if (((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + g_ActivePlayerPriority * 0x5b20) ==
                DAT_00695edc) &&
              (((&g_CardSlot_Flags)[local_10 * 0x120 + g_ActivePlayerPriority * 0x5b20] & 2) != 0))
             && (((char)(&g_CardSlot_Toughness)[local_10 * 0x120 + g_ActivePlayerPriority * 0x5b20]
                  == g_OverworldPlayerCoordX &&
                 (*(int *)(&g_CardSlot_OriginalCardId +
                          local_10 * 0x120 + g_ActivePlayerPriority * 0x5b20) == g_OverworldMapGrid)
                 ))) {
            bVar1 = true;
          }
          local_10 = local_10 + 1;
        }
        if (!bVar1) {
          iVar3 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                                       ));
          if (iVar3 != -1) {
            iVar4 = FUN_00410cc0(arg_1,arg_2,DAT_00695edc,g_OverworldPlayerCoordX,g_OverworldMapGrid
                                );
            if (iVar4 != -1) {
              *(int *)(&g_CardSlot_Controller + iVar4 * 0x120 + arg_1 * 0x5b20) = iVar3;
              *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&g_CardSlot_Abilities1 + iVar4 * 0x120 + arg_1 * 0x5b20) | 0x10020;
              FUN_00403250(&local_8,0,arg_1,2,2,0x200,0,0,0,0,0,0,
                           *(undefined4 *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120),
                           0xffffffff,0xffffffff,0xffffffff,0,0,0);
              *(int *)(&g_CardSlot_TargetSlot + iVar4 * 0x120 + arg_1 * 0x5b20) = local_8;
            }
            (&g_MasterCardColorTable)[iVar3 * 0x34] = 0x42;
            *(short *)(&DAT_0051aec4 + iVar3 * 0x34) =
                 (short)(char)(&DAT_0051aebf)
                              [*(int *)(&g_CardSlot_CardId +
                                       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                                       ) * 0x34] +
                 (short)(char)(&DAT_0051aec0)
                              [*(int *)(&g_CardSlot_CardId +
                                       g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120
                                       ) * 0x34];
            *(undefined2 *)(&DAT_0051aec2 + iVar3 * 0x34) =
                 *(undefined2 *)(&DAT_0051aec4 + iVar3 * 0x34);
            *(code **)(&DAT_0051aec8 + iVar3 * 0x34) = SpellChain_GetActiveCount;
            *(undefined4 *)(&DAT_0051aed0 + iVar3 * 0x34) = 0x8000;
            (&DAT_0051aebe)[iVar3 * 0x34] = 1;
          }
        }
      }
    }
    if (((arg_3 == 0x77) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      CardQuery_ForEachPermanent(Pic_Subsystem_0042baee,-1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


