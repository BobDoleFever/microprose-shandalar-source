/*
 * Decompiled function: FUN_00484c45
 * Entry Point: 00484c45
 * Size: 263 bytes
 */
#include "magic.h"


void FUN_00484c45(undefined4 arg_1)

{
  switch(arg_1) {
  case 1:
    strcat(&g_OverworldWorldState,&DAT_00527020);
    break;
  case 2:
    strcat(&g_OverworldWorldState,s_Creature_00527028);
    break;
  case 4:
    strcat(&g_OverworldWorldState,s_Enchantment_00527034);
    break;
  case 8:
    strcat(&g_OverworldWorldState,s_Sorcery_00527040);
    break;
  case 0x10:
    strcat(&g_OverworldWorldState,s_Instant_00527048);
    break;
  case 0x20:
    strcat(&g_OverworldWorldState,s_Interrupt_00527050);
    break;
  case 0x40:
    strcat(&g_OverworldWorldState,s_Artifact_0052705c);
    break;
  case 0x42:
    strcat(&g_OverworldWorldState,s_A_creature_00527068);
    break;
  case 0x80:
    strcat(&g_OverworldWorldState,s_Game_effect_00527074);
  }
  return;
}


