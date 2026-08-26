/*
 * Decompiled function: Adventure_TriggerDuelFromEncounter
 * Entry Point: 004ead33
 * Size: 99 bytes
 */
#include "magic.h"


void Adventure_TriggerDuelFromEncounter(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0xc; local_8 = local_8 + 1) {
    if ((0 < *(int *)(&DAT_005224ec + local_8 * 0x10)) &&
       (*(int *)(&DAT_005224ec + local_8 * 0x10) = *(int *)(&DAT_005224ec + local_8 * 0x10) + -1,
       *(int *)(&DAT_005224ec + local_8 * 0x10) == 0)) {
      Ai_Subsystem_004c05ba();
    }
  }
  return;
}


