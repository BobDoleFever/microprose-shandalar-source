/*
 * Decompiled function: FUN_004500a1
 * Entry Point: 004500a1
 * Size: 563 bytes
 */
#include "duel.h"


void FUN_004500a1(int *arg_1,undefined4 *arg_2,int arg_3)

{
  int local_7c;
  uint local_74 [25];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_0044897a(&local_8,&local_10);
  local_7c = local_8;
  switch(local_10) {
  case 1:
    local_c = 4;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Upkeep_phase_004f84e0);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    local_c = 10;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Draw_phase_004f84f0);
    break;
  default:
    local_c = 0xffffffff;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_next_phase_004f85ec);
    break;
  case 10:
    local_c = 0x14;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Main_phase__pre_combat__004f84fc);
    break;
  case 0x14:
    local_c = 0x15;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Main_phase__combat__004f8514);
    break;
  case 0x15:
    local_c = 0x16;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Attack_fast_effects_phase_004f8528);
    break;
  case 0x16:
    local_c = 0x17;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Choose_defenders_phase_004f8544);
    break;
  case 0x17:
    local_c = 0x18;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Block_fast_effects_phase_004f855c);
    break;
  case 0x18:
    local_c = 0x19;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Resolve_1st_strike_004f8578);
    break;
  case 0x19:
  case 0x1a:
    local_c = 0x1b;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Resolve_attack_004f858c);
    break;
  case 0x1b:
    local_c = 0x1e;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Main_phase__post_combat__004f859c);
    break;
  case 0x1e:
    local_c = 0x1f;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Discard_phase_004f85b8);
    break;
  case 0x1f:
    local_c = 0x20;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Cleanup_phase_004f85c8);
    break;
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
    local_c = 0;
    local_7c = 1 - local_8;
    Mem_AllocOrFree_004d9630(local_74,(uint *)s_Start_of_next_turn_004f85d8);
  }
  if (arg_1 != (int *)0x0) {
    *arg_1 = local_7c;
  }
  if (arg_2 != (undefined4 *)0x0) {
    *arg_2 = local_c;
  }
  if (arg_3 != 0) {
    Mem_AllocOrFree_004d9630((uint *)arg_3,local_74);
  }
  return;
}


