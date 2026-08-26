/*
 * Decompiled function: Palette_Subsystem_004958b1
 * Entry Point: 004958b1
 * Size: 167 bytes
 */
#include "magic.h"


int Palette_Subsystem_004958b1(int arg_1)

{
  char local_7d8 [2000];
  int local_8;
  
  DAT_006fe410 = 1;
  DAT_006a49e8 = arg_1;
  if (arg_1 == -1) {
    strcpy(&DAT_006ff310,s_Opponent_0052b208);
  }
  else {
    strcpy(&DAT_006ff310,&DAT_00522600 + arg_1 * 0x44);
  }
  local_8 = Palette_Subsystem_00495958(local_7d8);
  if (local_8 == -2) {
    MessageBoxA((HWND)0x0,local_7d8,s_Duel_couldn_t_run_0052b214,0x1030);
  }
  return local_8;
}


