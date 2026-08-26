/*
 * Decompiled function: Palette_Subsystem_004a6d20
 * Entry Point: 004a6d20
 * Size: 408 bytes
 */
#include "magic.h"


int Palette_Subsystem_004a6d20(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  uint uVar2;
  int local_14;
  int local_10;
  int local_8;
  
  local_10 = 0;
  local_8 = 0;
  do {
    if ((1 < local_8) || (local_10 != 0)) {
      return local_10;
    }
    local_14 = 0;
    while ((local_14 < (int)(&g_PlayerActiveCardCount)[local_8] && (local_10 == 0))) {
      if ((*(int *)(&g_CardSlot_CardId + local_14 * 0x120 + local_8 * 0x5b20) != -1) &&
         (((&g_CardSlot_Flags)[local_14 * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        if (*(int *)(&DAT_006b3088 +
                    *(int *)(&g_MasterCardTypeTable +
                            *(int *)(&g_CardSlot_CardId + local_14 * 0x120 + local_8 * 0x5b20) *
                            0x34) * 0x98) != arg_3) {
          iVar1 = Palette_Subsystem_004a6eb8
                            (*(int *)(&DAT_006b3088 +
                                     *(int *)(&g_MasterCardTypeTable +
                                             *(int *)(&g_CardSlot_CardId +
                                                     local_14 * 0x120 + local_8 * 0x5b20) * 0x34) *
                                     0x98));
          if (iVar1 != arg_3) goto LAB_004a6d5f;
        }
        if (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_14 * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)
        {
          uVar2 = SpellChain_ProcessTriggerEvent(arg_1,arg_2);
          if ((*(uint *)(&g_CardSlot_Abilities2 + local_14 * 0x120 + local_8 * 0x5b20) & uVar2) == 0
             ) {
            local_10 = 1;
          }
        }
      }
LAB_004a6d5f:
      local_14 = local_14 + 1;
    }
    local_8 = local_8 + 1;
  } while( true );
}


