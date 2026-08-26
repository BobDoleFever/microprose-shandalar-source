/*
 * Decompiled function: Pic_Draw_00427e36
 * Entry Point: 00427e36
 * Size: 563 bytes
 */
#include "magic.h"


void Pic_Draw_00427e36(int *arg_1,undefined4 *arg_2,char *str_3)

{
  int local_7c;
  char local_74 [100];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  Ai_Subsystem_004b74b1(&local_8,&local_10);
  local_7c = local_8;
  switch(local_10) {
  case 1:
    local_c = 4;
    strcpy(local_74,s_Upkeep_phase_0052101c);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    local_c = 10;
    strcpy(local_74,s_Draw_phase_0052102c);
    break;
  default:
    local_c = 0xffffffff;
    strcpy(local_74,s_next_phase_00521128);
    break;
  case 10:
    local_c = 0x14;
    strcpy(local_74,s_Main_phase__pre_combat__00521038);
    break;
  case 0x14:
    local_c = 0x15;
    strcpy(local_74,s_Main_phase__combat__00521050);
    break;
  case 0x15:
    local_c = 0x16;
    strcpy(local_74,s_Attack_fast_effects_phase_00521064);
    break;
  case 0x16:
    local_c = 0x17;
    strcpy(local_74,s_Choose_defenders_phase_00521080);
    break;
  case 0x17:
    local_c = 0x18;
    strcpy(local_74,s_Block_fast_effects_phase_00521098);
    break;
  case 0x18:
    local_c = 0x19;
    strcpy(local_74,s_Resolve_1st_strike_005210b4);
    break;
  case 0x19:
  case 0x1a:
    local_c = 0x1b;
    strcpy(local_74,s_Resolve_attack_005210c8);
    break;
  case 0x1b:
    local_c = 0x1e;
    strcpy(local_74,s_Main_phase__post_combat__005210d8);
    break;
  case 0x1e:
    local_c = 0x1f;
    strcpy(local_74,s_Discard_phase_005210f4);
    break;
  case 0x1f:
    local_c = 0x20;
    strcpy(local_74,s_Cleanup_phase_00521104);
    break;
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
    local_c = 0;
    local_7c = 1 - local_8;
    strcpy(local_74,s_Start_of_next_turn_00521114);
  }
  if (arg_1 != (int *)0x0) {
    *arg_1 = local_7c;
  }
  if (arg_2 != (undefined4 *)0x0) {
    *arg_2 = local_c;
  }
  if (str_3 != (char *)0x0) {
    strcpy(str_3,local_74);
  }
  return;
}


