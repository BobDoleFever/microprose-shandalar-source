/*
 * Decompiled function: Magic_CombatPhase
 * Entry Point: 004751d7
 * Size: 1062 bytes
 */
#include "magic.h"


undefined4 Magic_CombatPhase(int arg_1,int arg_2,int arg_3,int arg_4,undefined4 arg_5)

{
  undefined4 uVar1;
  bool bVar2;
  int local_c;
  
  if (DAT_006a3f78 < 0x20) {
    *(undefined4 *)(&DAT_006ff4d0 + DAT_006a3f78 * 4) =
         *(undefined4 *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20);
    *(uint *)(&DAT_006ff4d0 + DAT_006a3f78 * 4) =
         *(uint *)(&DAT_006ff4d0 + DAT_006a3f78 * 4) | arg_3 << 0x10;
    *(uint *)(&DAT_006ff4d0 + DAT_006a3f78 * 4) =
         *(uint *)(&DAT_006ff4d0 + DAT_006a3f78 * 4) | arg_4 << 0x18;
    if (((arg_3 == 0x71) || (arg_3 == 0x7e)) ||
       (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) < 5)) {
      local_c = arg_2;
      bVar2 = true;
    }
    else {
      local_c = Pic_Subsystem_00451291(arg_1,DAT_006fd3f4);
      if (local_c == -1) {
        bVar2 = false;
      }
      else {
        uVar1 = *(undefined4 *)(&g_CardSlot_DisplayIndex + arg_1 * 0x5b20 + local_c * 0x120);
        memcpy(&g_ActiveCardsInPlay + local_c * 0x120 + arg_1 * 0x5b20,
               &g_ActiveCardsInPlay + arg_1 * 0x5b20 + arg_2 * 0x120,0x120);
        *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_c * 0x120) = DAT_006fd3f4;
        *(undefined4 *)(&DAT_006a5f80 + arg_1 * 0x5b20 + local_c * 0x120) = 0;
        (&DAT_006a5f50)[arg_1 * 0x5b20 + local_c * 0x120] = 0;
        if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
          *(undefined4 *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + local_c * 0x120) =
               *(undefined4 *)(&g_ActiveCardsInPlay + arg_2 * 0x120 + arg_1 * 0x5b20);
        }
        else {
          *(undefined4 *)(&g_ActiveCardsInPlay + arg_1 * 0x5b20 + local_c * 0x120) =
               *(undefined4 *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20);
        }
        *(undefined4 *)(&DAT_006a5f74 + arg_1 * 0x5b20 + local_c * 0x120) =
             *(undefined4 *)(&DAT_006a5f74 + arg_2 * 0x120 + arg_1 * 0x5b20);
        *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_c * 0x120) =
             *(uint *)(&g_CardSlot_Flags + arg_1 * 0x5b20 + local_c * 0x120) | 2;
        *(int *)(&g_CardSlot_TapState + arg_1 * 0x5b20 + local_c * 0x120) = arg_1;
        *(int *)(&g_CardSlot_SicknessState + arg_1 * 0x5b20 + local_c * 0x120) = arg_2;
        *(undefined4 *)(&g_CardSlot_DisplayIndex + arg_1 * 0x5b20 + local_c * 0x120) = uVar1;
        bVar2 = true;
      }
    }
    if (bVar2) {
      (&DAT_006fecc0)[DAT_006a3f78 * 2] = arg_1;
      *(int *)(&DAT_006fecc4 + DAT_006a3f78 * 8) = local_c;
      *(int *)(&DAT_006ff390 + DAT_006a3f78 * 8) =
           (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20];
      *(undefined4 *)(&DAT_006ff394 + DAT_006a3f78 * 8) =
           *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20);
      if (g_PlayerManaPool == -1) {
        *(undefined4 *)(&DAT_00696880 + DAT_006a3f78 * 4) = g_ScWillyScore;
      }
      else {
        *(int *)(&DAT_00696880 + DAT_006a3f78 * 4) = g_PlayerManaPool;
      }
      if (g_IsAiThinking != 1) {
        *(undefined4 *)(&DAT_00695d70 + DAT_006a3f78 * 4) = arg_5;
      }
      DAT_006a3f78 = DAT_006a3f78 + 1;
      (&DAT_006fecc0)[DAT_006a3f78 * 2] = 0xffffffff;
    }
  }
  return 0;
}


