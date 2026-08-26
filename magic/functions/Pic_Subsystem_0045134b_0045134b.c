/*
 * Decompiled function: Pic_Subsystem_0045134b
 * Entry Point: 0045134b
 * Size: 1837 bytes
 */
#include "magic.h"


void Pic_Subsystem_0045134b(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int local_8;
  
  *(int *)(&g_ActiveCardsInPlay + arg_3 * 0x120 + arg_1 * 0x5b20) = arg_2;
  *(undefined4 *)(&g_CardSlot_CardId + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined4 *)(&g_ActiveCardsInPlay + arg_3 * 0x120 + arg_1 * 0x5b20);
  *(undefined4 *)(&g_CardSlot_Controller + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  if (arg_1 == 0) {
    *(undefined4 *)(&g_CardSlot_Flags + arg_3 * 0x120) = 0;
  }
  else {
    *(undefined4 *)(&g_CardSlot_Flags + arg_3 * 0x120 + arg_1 * 0x5b20) = 0x1000;
  }
  *(undefined2 *)(&g_CardSlot_Power + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  (&g_CardSlot_Toughness)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0xff;
  *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_3 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
  (&g_CardSlot_DamageReceived)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0xff;
  *(undefined4 *)(&g_CardSlot_TypeFlags + arg_3 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
  *(undefined2 *)(&g_CardSlot_Counters + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined2 *)(&DAT_0051aec2 + arg_2 * 0x34);
  *(undefined2 *)(&DAT_006a5f46 + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined2 *)(&DAT_0051aec4 + arg_2 * 0x34);
  *(undefined2 *)(&DAT_006a5f48 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined2 *)(&DAT_006a5f4a + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  (&DAT_006a5f4d)[arg_3 * 0x120 + arg_1 * 0x5b20] = (&DAT_0051aebe)[arg_2 * 0x34];
  (&DAT_006a5f4c)[arg_3 * 0x120 + arg_1 * 0x5b20] = (&DAT_006a5f4d)[arg_3 * 0x120 + arg_1 * 0x5b20];
  (&g_CardSlot_ColorMask)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0xff;
  (&DAT_006a5f4f)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0;
  (&DAT_006a5f50)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0;
  *(undefined4 *)(&g_CardSlot_TargetSlot + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined4 *)(&g_CardSlot_TargetSlot + arg_3 * 0x120 + arg_1 * 0x5b20);
  *(undefined4 *)(&g_CardSlot_DisplayIndex + arg_3 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
  *(undefined4 *)(&g_CardSlot_Abilities1 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined4 *)(&g_CardSlot_Abilities2 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0x8000000;
  uVar1 = Pic_Subsystem_00451b1c(arg_1,arg_3);
  *(undefined4 *)(&DAT_006a5f70 + arg_3 * 0x120 + arg_1 * 0x5b20) = uVar1;
  *(undefined4 *)(&DAT_006a5f7c + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined4 *)(&DAT_006a5f80 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  (&g_CardSlot_TurnPlayed)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0;
  *(undefined4 *)(&DAT_006a6038 + arg_3 * 0x120 + arg_1 * 0x5b20) = 0;
  *(undefined4 *)(&g_CardSlot_SpecialState + arg_3 * 0x120 + arg_1 * 0x5b20) =
       *(undefined4 *)(&DAT_006a6038 + arg_3 * 0x120 + arg_1 * 0x5b20);
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    (&DAT_006a603c)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120] = 0;
    (&DAT_006a6048)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120] =
         (&DAT_006a603c)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120];
  }
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    (&DAT_006a6029)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120] = 0;
    (&DAT_006a602f)[local_8 + arg_1 * 0x5b20 + arg_3 * 0x120] = 0;
  }
  for (local_8 = 0; local_8 < 0x14; local_8 = local_8 + 1) {
    *(undefined4 *)(&g_CardSlot_CombatTarget + arg_3 * 0x120 + arg_1 * 0x5b20 + local_8 * 8) =
         0xffffffff;
    *(undefined4 *)(&g_CardSlot_AttachedAura + arg_3 * 0x120 + arg_1 * 0x5b20 + local_8 * 8) =
         0xffffffff;
  }
  if (((&DAT_0051aed1)[arg_2 * 0x34] & 0x10) != 0) {
    if (((&g_MasterCardColorTable)[arg_2 * 0x34] == '\x01') ||
       ((&g_MasterCardColorTable)[arg_2 * 0x34] == '@')) {
      (&DAT_006a5f4d)[arg_3 * 0x120 + arg_1 * 0x5b20] = 1;
    }
    if (*(int *)(&g_MasterCardTypeTable + arg_2 * 0x34) == 0xf) {
      (&DAT_006a5f4c)[arg_3 * 0x120 + arg_1 * 0x5b20] = 0x3e;
    }
    else if (*(int *)(&g_MasterCardTypeTable + arg_2 * 0x34) == 300) {
      (&DAT_006a5f4c)[arg_3 * 0x120 + arg_1 * 0x5b20] = 1;
    }
  }
  FUN_00476482(arg_1,arg_3);
  return;
}


