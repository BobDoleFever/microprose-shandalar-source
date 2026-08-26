/*
 * Decompiled function: FUN_0040fa39
 * Entry Point: 0040fa39
 * Size: 420 bytes
 */
#include "magic.h"


undefined4 FUN_0040fa39(char *str_1,char *str_2,int arg_3)

{
  undefined4 uVar1;
  int local_c;
  uint local_8;
  
  if (arg_3 != 0) {
    DAT_00517590 = 0;
    for (local_8 = 0; (int)local_8 < 0x80; local_8 = local_8 + 1) {
      if (((&DAT_0067be00)[local_8 * 100] & 1) != 0) {
        DAT_00517590 = DAT_00517590 + 1;
      }
    }
    if (DAT_00517590 < 2) {
      return 0xffffffff;
    }
    DAT_005384f8 = FUN_0040a1d2(DAT_00517590);
    DAT_005384fc = FUN_0040a1d2(DAT_00517590);
    while (DAT_005384fc == DAT_005384f8) {
      DAT_005384fc = FUN_0040a1d2(DAT_00517590);
    }
  }
  if (DAT_00517590 < 2) {
    uVar1 = 0xffffffff;
  }
  else {
    local_c = 0;
    for (local_8 = 0; (int)local_8 < 0x80; local_8 = local_8 + 1) {
      if (((&DAT_0067be00)[local_8 * 100] & 1) != 0) {
        if (DAT_005384f8 == local_c) {
          g_OverworldWorldState = 0;
          Ai_TownEncounter_004c3b19(local_8);
          strcpy(str_1,&g_OverworldWorldState);
          local_c = local_c + 1;
        }
        else if (DAT_005384fc == local_c) {
          g_OverworldWorldState = 0;
          Ai_TownEncounter_004c3b19(local_8);
          strcpy(str_2,&g_OverworldWorldState);
          local_c = local_c + 1;
        }
        else {
          local_c = local_c + 1;
        }
      }
    }
    uVar1 = 2;
  }
  return uVar1;
}


