/*
 * Decompiled function: FUN_0040f514
 * Entry Point: 0040f514
 * Size: 290 bytes
 */
#include "magic.h"


void FUN_0040f514(byte arg_1)

{
  undefined4 uVar1;
  int aiStack_50 [16];
  int local_10;
  int local_c;
  int local_8;
  
  strcpy(&g_OverworldWorldState,s_Whose_deck_would_you_like_to_see_00519314);
  local_8 = 0;
  for (local_c = 1; local_c < DAT_00523524; local_c = local_c + 1) {
    if ((1 << (arg_1 & 0x1f) & (int)(char)(&DAT_0052262b)[local_c * 0x44]) != 0) {
      aiStack_50[local_8] = local_c;
      local_8 = local_8 + 1;
      Adventure_FormatNewsString(local_c,0,0);
      strcat(&g_OverworldWorldState,&DAT_00519338);
    }
  }
  local_10 = FUN_00489710(&g_OverworldWorldState,100,0x46);
  if (local_10 != -1) {
    local_10 = aiStack_50[local_10];
    FUN_004909d3(local_10,0xffffffff,0,-1);
    for (local_c = 0; local_c < 500; local_c = local_c + 1) {
      uVar1 = FUN_0040a02a(DAT_0052eff8);
      *(undefined4 *)(&DAT_0069ef00 + local_c * 4) = uVar1;
    }
    FUN_0040a16e(DAT_0052eff8);
  }
  return;
}


