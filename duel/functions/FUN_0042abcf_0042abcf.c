/*
 * Decompiled function: FUN_0042abcf
 * Entry Point: 0042abcf
 * Size: 386 bytes
 */
#include "duel.h"


void FUN_0042abcf(int arg_1)

{
  bool bVar1;
  
  if ((DAT_0066ab04 == arg_1) && (DAT_0066aac4 == DAT_00666458)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((DAT_0066aaf4 != 1) &&
     (((*(uint *)(&DAT_006667c0 + arg_1 * 4 + DAT_00666458 * 0x98) & 1) != 0 || (bVar1)))) {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Paused_004f3a84);
    if (arg_1 == 4) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___Upkeep_phase_004f3a8c);
    }
    if (arg_1 == 1) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___Untap_phase_004f3a9c);
    }
    if (arg_1 == 10) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___Draw_phase_004f3aac);
    }
    if (arg_1 == 0x14) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___Main_phase_004f3abc);
    }
    if (arg_1 == 0x1f) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___Discard_phase_004f3acc);
    }
    if (arg_1 == 0x22) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___Cleanup_phase_004f3adc);
    }
    if (arg_1 == 0x19) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___First_strike_damage_resolution_004f3aec);
    }
    if (arg_1 == 0x1a) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s___Combat_damage_resolution_004f3b10);
    }
    FUN_0042ad51(&DAT_005f6810);
  }
  return;
}


