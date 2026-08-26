/*
 * Decompiled function: Palette_Subsystem_004958b1
 * Entry Point: 00437b8c
 * Size: 167 bytes
 */
#include "duel.h"


int Palette_Subsystem_004958b1(int arg_1)

{
  CHAR local_7d8 [2000];
  int local_8;
  
  DAT_00663dfc = 1;
  DAT_00617434 = arg_1;
  if (arg_1 == -1) {
    Mem_AllocOrFree_004d9630((uint *)&DAT_00664b90,(uint *)s_Opponent_004f6c70);
  }
  else {
    Mem_AllocOrFree_004d9630((uint *)&DAT_00664b90,(uint *)(&DAT_00507370 + arg_1 * 0x44));
  }
  local_8 = Palette_Subsystem_00495958(local_7d8);
  if (local_8 == -2) {
    MessageBoxA((HWND)0x0,local_7d8,s_Duel_couldn_t_run_004f6c7c,0x1030);
  }
  return local_8;
}


