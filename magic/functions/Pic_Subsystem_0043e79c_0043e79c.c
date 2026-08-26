/*
 * Decompiled function: Pic_Subsystem_0043e79c
 * Entry Point: 0043e79c
 * Size: 1054 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043e79c(int arg_1,int arg_2,int arg_3)

{
  short sVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (arg_3 == 0x74) {
    uVar5 = 1;
  }
  else if (arg_3 == 0x73) {
    iVar6 = Card_GetCounters(arg_1,arg_2);
    if ((iVar6 != 0) && (iVar6 = FUN_0040dcca(arg_1,arg_2,7,5), iVar6 != 0)) {
      if ((arg_1 == g_ActivePlayerPriority) && (0 < DAT_006ff550)) {
        DAT_006a4920 = DAT_006a4920 | 3;
      }
      return 1;
    }
    uVar5 = 0;
  }
  else {
    if ((((arg_3 == 0x6d) && (iVar6 = FUN_0040dcca(arg_1,arg_2,7,5), iVar6 != 0)) &&
        (Ai_Subsystem_004be192(arg_1,arg_2,0,5), g_ActivePlayer != 1)) && (0 < DAT_006ff550)) {
      DAT_006ff550 = DAT_006ff550 + -1;
    }
    if (arg_3 == 0x72) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x26);
      }
      iVar6 = Pic_Subsystem_0045268f(900);
      iVar6 = Pic_Subsystem_00451291(arg_1,iVar6);
      if (iVar6 != -1) {
        Pic_Subsystem_0042ac1f(arg_1,iVar6);
        cVar2 = FUN_0041d9d2(arg_1,arg_2,1);
        (&DAT_006a5f4d)[iVar6 * 0x120 + arg_1 * 0x5b20] = (char)(2 << (cVar2 - 1U & 0x1f));
        *(uint *)(&g_CardSlot_Abilities1 + iVar6 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities1 + iVar6 * 0x120 + arg_1 * 0x5b20) | 0x10;
        if (((&g_CardSlot_Abilities1)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) != 0) {
          *(uint *)(&g_CardSlot_Abilities1 + iVar6 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar6 * 0x120 + arg_1 * 0x5b20) | 2;
          (&DAT_006a6030)[iVar6 * 0x120 + arg_1 * 0x5b20] =
               (&DAT_006a6030)[arg_1 * 0x5b20 + arg_2 * 0x120];
        }
        *(undefined4 *)(&DAT_006a5f74 + iVar6 * 0x120 + arg_1 * 0x5b20) =
             *(undefined4 *)
              (&g_MasterCardTypeTable +
              *(int *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120) * 0x34);
        sVar1 = *(short *)(&DAT_006a5f48 + iVar6 * 0x120 + arg_1 * 0x5b20);
        sVar4 = FUN_0040a1d2(3);
        *(short *)(&DAT_006a5f48 + iVar6 * 0x120 + arg_1 * 0x5b20) = sVar1 + sVar4;
        sVar1 = *(short *)(&DAT_006a5f4a + iVar6 * 0x120 + arg_1 * 0x5b20);
        sVar4 = FUN_0040a1d2(3);
        *(short *)(&DAT_006a5f4a + iVar6 * 0x120 + arg_1 * 0x5b20) = sVar1 + sVar4;
        Card_DecrementCounter(g_DialogPromptHwnd,g_DuelArenaHwnd);
      }
    }
    if (((arg_3 == 0x77) &&
        (((&g_MasterCardColorTable)
          [*(int *)(&g_CardSlot_CardId +
                   g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120) * 0x34] & 2) != 0)
        ) && ((((&g_CardSlot_Flags)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] &
               0x20) == 0 &&
              (((&DAT_006a5f50)[g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120] !=
                '\x04' &&
               (cVar2 = (&DAT_006a5f4d)
                        [g_OverworldPlayerCoordX * 0x5b20 + g_OverworldMapGrid * 0x120],
               cVar3 = FUN_0041d9d2(arg_1,arg_2,1), (2 << (cVar3 - 1U & 0x1f) & (int)cVar2) == 0))))
             )) {
      Card_IncrementCounter(arg_1,arg_2);
    }
    uVar5 = 0;
  }
  return uVar5;
}


