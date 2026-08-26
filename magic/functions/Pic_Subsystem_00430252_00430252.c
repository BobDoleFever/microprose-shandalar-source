/*
 * Decompiled function: Pic_Subsystem_00430252
 * Entry Point: 00430252
 * Size: 922 bytes
 */
#include "magic.h"


uint Pic_Subsystem_00430252(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  uint arg_12;
  uint arg_13;
  int iVar2;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  
  if (arg_3 == 0x74) {
    if (g_CurrentTurnPhase == arg_1) {
      uVar1 = (DAT_006a2828 | DAT_006a282c) & 1;
    }
    else {
      uVar1 = (&DAT_006a2828)[g_ActivePlayerPriority] & 1;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      CardTarget_PromptTargetPermanent(arg_1,arg_1,arg_2);
      if (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
        g_ActivePlayer = 1;
      }
    }
    if (arg_3 == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uVar1 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20),
                         (char *)0x0,arg_1,2,2,0x200,1,0,0,uVar1,arg_12,arg_13,iVar2,arg_15,arg_16,
                         arg_17,arg_18,arg_19,arg_20);
      if (iVar2 == 0) {
        Pic_Subsystem_0044867e(arg_1,arg_2,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&g_CardSlot_CombatTarget)[arg_2 * 0x120 + arg_1 * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + arg_2 * 0x120 + arg_1 * 0x5b20);
        CardQuery_ForEachPermanent(Pic_Subsystem_004305f1,-1);
      }
      (&g_CardSlot_TurnPlayed)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
    }
    if (((arg_3 == 0x77) &&
        (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid
        )) && (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] ==
                g_OverworldPlayerCoordX && (g_OverworldMapGrid != -1)))) {
      g_ActivePalette = 1;
    }
    if ((((arg_3 == 0x6c) && ((g_OverworldMapGrid != arg_2 || (g_OverworldPlayerCoordX != arg_1))))
        && (*(int *)(&g_CardSlot_OriginalCardId +
                    g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) ==
            *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20))) &&
       (((&g_CardSlot_Toughness)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] ==
         (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 4) != 0)
        ))) {
      g_ActivePlayer = 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


