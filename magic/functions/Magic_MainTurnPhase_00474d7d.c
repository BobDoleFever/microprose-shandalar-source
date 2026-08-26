/*
 * Decompiled function: Magic_MainTurnPhase
 * Entry Point: 00474d7d
 * Size: 1114 bytes
 */
#include "magic.h"


undefined4 Magic_MainTurnPhase(undefined4 arg_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = DAT_006a3f78 + -1;
  iVar1 = (&DAT_006fecc0)[iVar6 * 2];
  iVar2 = *(int *)(&DAT_006fecc4 + iVar6 * 8);
  if (*(int *)(&g_CardSlot_CardId + iVar2 * 0x120 + iVar1 * 0x5b20) == DAT_006fd3f4) {
    uVar3 = *(undefined4 *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20);
    uVar4 = *(undefined4 *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20);
    uVar5 = *(undefined4 *)(&g_CardSlot_DisplayIndex + iVar2 * 0x120 + iVar1 * 0x5b20);
    memcpy(&g_ActiveCardsInPlay + iVar1 * 0x5b20 + iVar2 * 0x120,
           &g_ActiveCardsInPlay +
           *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120 +
           *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20,0x120);
    *(int *)(&g_CardSlot_CardId + iVar2 * 0x120 + iVar1 * 0x5b20) = DAT_006fd3f4;
    *(undefined4 *)(&DAT_006a5f80 + iVar2 * 0x120 + iVar1 * 0x5b20) = 0;
    (&DAT_006a5f50)[iVar2 * 0x120 + iVar1 * 0x5b20] = 0;
    *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + iVar1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + iVar1 * 0x5b20) | 2;
    *(undefined4 *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) = uVar4;
    *(undefined4 *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) = uVar3;
    *(undefined4 *)(&g_CardSlot_DisplayIndex + iVar2 * 0x120 + iVar1 * 0x5b20) = uVar5;
    if (*(int *)(&g_CardSlot_CardId +
                *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20 +
                *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120) != -1)
    {
      *(undefined4 *)(&g_ActiveCardsInPlay + iVar2 * 0x120 + iVar1 * 0x5b20) =
           *(undefined4 *)
            (&g_CardSlot_CardId +
            *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20 +
            *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120);
    }
    if ((*(int *)(&g_ActiveCardsInPlay + iVar2 * 0x120 + iVar1 * 0x5b20) < DAT_006ff2e0) ||
       (DAT_006ff2e0 + 0x1d <= *(int *)(&g_ActiveCardsInPlay + iVar2 * 0x120 + iVar1 * 0x5b20))) {
      *(undefined4 *)(&DAT_006a5f74 + iVar2 * 0x120 + iVar1 * 0x5b20) =
           *(undefined4 *)
            (&g_MasterCardTypeTable +
            *(int *)(&g_ActiveCardsInPlay +
                    *(int *)(&g_CardSlot_TapState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x5b20 +
                    *(int *)(&g_CardSlot_SicknessState + iVar2 * 0x120 + iVar1 * 0x5b20) * 0x120) *
            0x34);
    }
  }
  if (g_IsAiThinking != 1) {
    *(undefined4 *)(&DAT_00695d70 + iVar6 * 4) = arg_1;
  }
  *(int *)(&DAT_006ff390 + iVar6 * 8) =
       (int)(char)(&g_CardSlot_Toughness)[iVar2 * 0x120 + iVar1 * 0x5b20];
  *(undefined4 *)(&DAT_006ff394 + iVar6 * 8) =
       *(undefined4 *)(&g_CardSlot_OriginalCardId + iVar2 * 0x120 + iVar1 * 0x5b20);
  return 0;
}


