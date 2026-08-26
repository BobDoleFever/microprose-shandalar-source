/*
 * Decompiled function: Card_PradeshGypsies_ResetRestriction
 * Entry Point: 004dd33b
 * Size: 754 bytes
 */
#include "magic.h"


undefined4 Card_PradeshGypsies_ResetRestriction(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (g_CurrentTurnPhase == arg_1) {
      if (((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
         (((DAT_006a282c | DAT_006a2828) & 2) != 0)) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else if (((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
            ((*(byte *)(&DAT_006a2828 + g_ActivePlayerPriority) & 2) != 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      if (local_c == -1) {
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
      }
      *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      iVar2 = FUN_00410cc0(arg_1,arg_2,DAT_006a2854,
                           (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                           *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
      if (iVar2 != -1) {
        *(undefined2 *)(&DAT_006a5f48 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
        *(undefined2 *)(&DAT_006a5f4a + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
      }
      *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if ((arg_3 == 0x3b) &&
       ((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20014) == 0)) {
      *(int *)(&DAT_00695eb0 + arg_1 * 4) = *(int *)(&DAT_00695eb0 + arg_1 * 4) + 1;
      *(int *)(&DAT_00695eb8 + arg_1 * 4) = *(int *)(&DAT_00695eb8 + arg_1 * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


