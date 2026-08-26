/*
 * Decompiled function: Pic_Subsystem_00447a1a
 * Entry Point: 00447a1a
 * Size: 317 bytes
 */
#include "magic.h"


void Pic_Subsystem_00447a1a(void)

{
  short sVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) &&
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0))
         && (((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
        sVar1 = *(short *)(&g_CardSlot_Power + local_c * 0x120 + local_8 * 0x5b20);
        iVar2 = FUN_00473179(local_8,local_c,0x33,0xffffffff);
        if (iVar2 <= sVar1) {
          if (g_IsAiThinking != 1) {
            Magic_UpkeepPhase(0x19);
          }
          Pic_Subsystem_0044867e(local_8,local_c,2);
        }
      }
    }
  }
  return;
}


