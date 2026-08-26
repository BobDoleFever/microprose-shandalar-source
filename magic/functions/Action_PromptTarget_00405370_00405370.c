/*
 * Decompiled function: Action_PromptTarget_00405370
 * Entry Point: 00405370
 * Size: 832 bytes
 */
#include "magic.h"


/* WARNING: Removing unreachable block (ram,0x004054e2) */

void Action_PromptTarget_00405370(uint spell_id,undefined4 target_id,int flags)

{
  uint uVar1;
  char cVar2;
  
  g_OverworldWorldState = 0;
  uVar1 = FUN_00474d4a();
  if ((uVar1 != 0xffffffff) &&
     (((uVar1 = uVar1 >> 0x10 & 0xff, uVar1 == 0x71 || (uVar1 == 0x72)) || (uVar1 == 0x7e)))) {
    if (uVar1 == 0x71) {
      strcpy(&g_OverworldWorldState,s_CASTING__00516268);
    }
    if (uVar1 == 0x72) {
      strcpy(&g_OverworldWorldState,s_ACTIVATING__00516274);
    }
    if (uVar1 == 0x7e) {
      strcpy(&g_OverworldWorldState,s_PROCESSING__00516284);
    }
    Ai_Subsystem_004b90de
              (*(int *)(&DAT_006fecb8 + DAT_006a3f78 * 8),*(int *)(&DAT_006fecbc + DAT_006a3f78 * 8)
              );
    strcat(&g_OverworldWorldState,&DAT_00516294);
  }
  if ((flags != 0) && (strcat(&g_OverworldWorldState,s_Pick_a_player_00516298), spell_id != 0)) {
    strcat(&g_OverworldWorldState,&DAT_005162a8);
  }
  if ((spell_id & 1) == 0) {
    if (spell_id != 0) {
      strcat(&g_OverworldWorldState,s_Pick_target_005162bc);
      cVar2 = (spell_id & 1) != 0;
      if ((bool)cVar2) {
        strcat(&g_OverworldWorldState,&DAT_005162d0);
      }
      if ((spell_id & 2) != 0) {
        if ((bool)cVar2) {
          strcat(&g_OverworldWorldState,&DAT_005162d8);
        }
        strcat(&g_OverworldWorldState,s_creature_005162dc);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 4) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_005162e8);
        }
        strcat(&g_OverworldWorldState,s_enchantment_005162ec);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x40) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_005162f8);
        }
        strcat(&g_OverworldWorldState,s_artifact_005162fc);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x80) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_00516308);
        }
        strcat(&g_OverworldWorldState,s_effect_0051630c);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 8) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_00516314);
        }
        strcat(&g_OverworldWorldState,s_sorcery_00516318);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x10) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_00516320);
        }
        strcat(&g_OverworldWorldState,s_instant_00516324);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x20) != 0) {
        if (cVar2 != '\0') {
          strcat(&g_OverworldWorldState,&DAT_0051632c);
        }
        strcat(&g_OverworldWorldState,s_interrupt_00516330);
      }
    }
  }
  else {
    strcat(&g_OverworldWorldState,s_Pick_a_card_005162b0);
  }
  return;
}


