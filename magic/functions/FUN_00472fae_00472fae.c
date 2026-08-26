/*
 * Decompiled function: FUN_00472fae
 * Entry Point: 00472fae
 * Size: 459 bytes
 */
#include "magic.h"


void FUN_00472fae(void)

{
  short sVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      if ((((&g_CardSlot_Flags)[local_c * 0x120 + local_8 * 0x5b20] & 2) != 0) &&
         (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1)) {
        *(uint *)(&g_CardSlot_Abilities2 + local_c * 0x120 + local_8 * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + local_c * 0x120 + local_8 * 0x5b20) | 0xf000000;
        FUN_00473179(local_8,local_c,0x3c,0xffffffff);
      }
    }
  }
  Ai_Subsystem_004cced8();
  Ai_Subsystem_004ccca3();
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      iVar2 = FUN_00471c32(local_8,local_c);
      if (((iVar2 != 0) &&
          (((&g_MasterCardColorTable)
            [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0))
         && (sVar1 = *(short *)(&g_CardSlot_Power + local_c * 0x120 + local_8 * 0x5b20),
            iVar2 = FUN_00473179(local_8,local_c,0x33,0xffffffff), sVar1 < iVar2)) {
        FUN_00473179(local_8,local_c,0x32,0xffffffff);
      }
    }
  }
  return;
}


