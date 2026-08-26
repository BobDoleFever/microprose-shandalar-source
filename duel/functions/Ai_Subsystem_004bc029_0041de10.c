/*
 * Decompiled function: Ai_Subsystem_004bc029
 * Entry Point: 0041de10
 * Size: 832 bytes
 */
#include "duel.h"


/* WARNING: Removing unreachable block (ram,0x0041df82) */

void Ai_Subsystem_004bc029(uint spell_id,undefined4 target_id,int flags)

{
  uint uVar1;
  char cVar2;
  
  DAT_005f6810 = 0;
  uVar1 = FUN_0048d3eb();
  if ((uVar1 != 0xffffffff) &&
     (((uVar1 = uVar1 >> 0x10 & 0xff, uVar1 == 0x71 || (uVar1 == 0x72)) || (uVar1 == 0x7e)))) {
    if (uVar1 == 0x71) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_CASTING__004f2ee4);
    }
    if (uVar1 == 0x72) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_ACTIVATING__004f2ef0);
    }
    if (uVar1 == 0x7e) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_PROCESSING__004f2f00);
    }
    FUN_0044a5a4(*(int *)(&DAT_0068efa8 + DAT_006764b8 * 8),
                 *(int *)(&DAT_0068efac + DAT_006764b8 * 8));
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2f10);
  }
  if ((flags != 0) &&
     (FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Pick_a_player_004f2f14), spell_id != 0)) {
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2f24);
  }
  if ((spell_id & 1) == 0) {
    if (spell_id != 0) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Pick_target_004f2f38);
      cVar2 = (spell_id & 1) != 0;
      if ((bool)cVar2) {
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2f4c);
      }
      if ((spell_id & 2) != 0) {
        if ((bool)cVar2) {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2f54);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_creature_004f2f58);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 4) != 0) {
        if (cVar2 != '\0') {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2f64);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_enchantment_004f2f68);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x40) != 0) {
        if (cVar2 != '\0') {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2f74);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_artifact_004f2f78);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x80) != 0) {
        if (cVar2 != '\0') {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2f84);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_effect_004f2f88);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 8) != 0) {
        if (cVar2 != '\0') {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2f90);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_sorcery_004f2f94);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x10) != 0) {
        if (cVar2 != '\0') {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2f9c);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_instant_004f2fa0);
        cVar2 = cVar2 + '\x01';
      }
      if ((spell_id & 0x20) != 0) {
        if (cVar2 != '\0') {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f2fa8);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_interrupt_004f2fac);
      }
    }
  }
  else {
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Pick_a_card_004f2f2c);
  }
  return;
}


