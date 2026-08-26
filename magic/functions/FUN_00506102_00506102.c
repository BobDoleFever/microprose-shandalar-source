/*
 * Decompiled function: FUN_00506102
 * Entry Point: 00506102
 * Size: 431 bytes
 */
#include "magic.h"


void FUN_00506102(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  while (*(int *)(&DAT_0063eeac + g_ActivePlayerPriority * 0x20) != 0) {
    local_c = 0;
    while( true ) {
      if ((int)(&g_PlayerActiveCardCount)[g_ActivePlayerPriority] <= local_c) goto LAB_005061ff;
      if (((*(int *)(&g_CardSlot_CardId + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) != -1)
          && (((byte)*(undefined4 *)
                      (&g_CardSlot_Flags + local_c * 0x120 + g_ActivePlayerPriority * 0x5b20) & 0x22
              ) == 2)) &&
         (Magic_TriggerCardEvent
                    (g_ActivePlayerPriority,local_c,0x8f,1 - g_ActivePlayerPriority,0xffffffff),
         DAT_006b2e38 != 0)) break;
      local_c = local_c + 1;
    }
    iVar1 = FUN_0047103b(g_ActivePlayerPriority,local_c);
    if (iVar1 != 0) {
      FUN_00471971(g_ActivePlayerPriority,local_c);
    }
  }
LAB_005061ff:
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if (0 < *(int *)(&DAT_0063eeac + local_8 * 0x20)) {
      if (g_IsAiThinking != 1) {
        Magic_UpkeepPhase(0x20);
        Ai_Subsystem_004b784d(local_8,*(undefined4 *)(&DAT_0063eeac + local_8 * 0x20));
      }
      (&g_PlayerCreatureCount)[local_8] =
           (&g_PlayerCreatureCount)[local_8] - *(int *)(&DAT_0063eeac + local_8 * 0x20);
      for (local_c = 0; local_c < 8; local_c = local_c + 1) {
        *(undefined4 *)(&DAT_0063ee90 + local_c * 4 + local_8 * 0x20) = 0;
      }
    }
  }
  return;
}


