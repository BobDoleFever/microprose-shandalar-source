/*
 * Decompiled function: FUN_00485d15
 * Entry Point: 00485d15
 * Size: 917 bytes
 */
#include "duel.h"


void FUN_00485d15(char *str_1,int arg_2,undefined4 arg_3)

{
  if (str_1 != (char *)0x0) {
    if (arg_2 == 0x1d7) {
      _sprintf(str_1,s_Doom_counters___d_004fa840,arg_3);
    }
    else if (arg_2 == 0x244) {
      _sprintf(str_1,s_Charge_counters___d_004fa854,arg_3);
    }
    else if (arg_2 == 0x248) {
      _sprintf(str_1,s_Charge_counters___d_004fa868,arg_3);
    }
    else if (arg_2 == 0x296) {
      _sprintf(str_1,s_Charge_counters___d_004fa87c,arg_3);
    }
    else if (arg_2 == 0x2fd) {
      _sprintf(str_1,s_Charge_counters___d_004fa890,arg_3);
    }
    else if (arg_2 == 0x354) {
      _sprintf(str_1,s_Charge_counters___d_004fa8a4,arg_3);
    }
    else if (arg_2 == 0x1e4) {
      _sprintf(str_1,s_Clockwork___1__0__counters___d_004fa8b8,arg_3);
    }
    else if (arg_2 == 0x26) {
      _sprintf(str_1,s_Clockwork___1__0__counters___d_004fa8d8,arg_3);
    }
    else if (arg_2 == 0x34) {
      _sprintf(str_1,s_Life_counters___d_004fa8f8,arg_3);
    }
    else if (arg_2 == 0x7b) {
      _sprintf(str_1,s_Life_counters___d_004fa90c,arg_3);
    }
    else if (arg_2 == 0x80) {
      _sprintf(str_1,s_Life_counters___d_004fa920,arg_3);
    }
    else if (arg_2 == 0xf6) {
      _sprintf(str_1,s_Life_counters___d_004fa934,arg_3);
    }
    else if (arg_2 == 0x120) {
      _sprintf(str_1,s_Life_counters___d_004fa948,arg_3);
    }
    else if (arg_2 == 0x5e) {
      _sprintf(str_1,s__1__1_counters___d_004fa95c,arg_3);
    }
    else if (arg_2 == 0x353) {
      _sprintf(str_1,s__1__1_counters___d_004fa970,arg_3);
    }
    else if (arg_2 == 0x92) {
      _sprintf(str_1,s_Vitality_counters___d_004fa984,arg_3);
    }
    else if (arg_2 == 0x2e0) {
      _sprintf(str_1,s_Carrion_counters___d_004fa99c,arg_3);
    }
    else if (arg_2 == 0xd7) {
      _sprintf(str_1,s_Corpse_counters___d_004fa9b4,arg_3);
    }
    else if (arg_2 == 0xdc) {
      _sprintf(str_1,s__1__1_counters___d_004fa9c8,arg_3);
    }
    else if (arg_2 == 0x367) {
      _sprintf(str_1,s_Corpse_counters___d_004fa9dc,arg_3);
    }
    else if (arg_2 == 0x21a) {
      _sprintf(str_1,s__1__1_counters___d_004fa9f0,arg_3);
    }
    else if (arg_2 == 0x216) {
      _sprintf(str_1,s_Drone___1__1__counters___d_004faa04,arg_3);
    }
    else if (arg_2 == 0xf8) {
      _sprintf(str_1,s_Turn_counters___d_004faa20,arg_3);
    }
    else {
      *str_1 = '\0';
    }
  }
  return;
}


