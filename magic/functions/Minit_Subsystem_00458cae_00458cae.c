/*
 * Decompiled function: Minit_Subsystem_00458cae
 * Entry Point: 00458cae
 * Size: 1030 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00458cae(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    if ((((DAT_006a282c | DAT_006a2828) & 2) == 0) ||
       (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    Ai_GetOpponentPlayerScore(0);
    uVar1 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20,
       ((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId +
                 *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 0x34] &
       0x40) != 0)) {
      g_ActivePlayer = 1;
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      if (((&g_MasterCardColorTable)
           [*(int *)(&g_CardSlot_CardId +
                    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                    (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) * 0x34]
          & 0x40) == 0) {
        iVar2 = FUN_00410cc0(arg_1,arg_2,DAT_006a2854,
                             (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                             *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
        if (iVar2 != -1) {
          *(undefined2 *)(&DAT_006a5f48 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
          *(undefined2 *)(&DAT_006a5f4a + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
          *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x20;
        }
        iVar2 = FUN_0041d8a6(*(int *)(&g_CardSlot_CardId +
                                     *(int *)(&g_CardSlot_OriginalCardId +
                                             arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                                     (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] *
                                     0x5b20));
        if (iVar2 != -1) {
          (&g_MasterCardColorTable)[iVar2 * 0x34] = 0x42;
          *(int *)(&g_CardSlot_CardId +
                  *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  (char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x5b20) = iVar2;
        }
        (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
        *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) =
             (int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20];
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    if (arg_3 == 0x3b) {
      *(int *)(&DAT_00695eb0 + arg_1 * 4) = *(int *)(&DAT_00695eb0 + arg_1 * 4) + 1;
      *(int *)(&DAT_00695eb8 + arg_1 * 4) = *(int *)(&DAT_00695eb8 + arg_1 * 4) + 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


