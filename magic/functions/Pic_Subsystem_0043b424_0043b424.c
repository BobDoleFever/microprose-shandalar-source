/*
 * Decompiled function: Pic_Subsystem_0043b424
 * Entry Point: 0043b424
 * Size: 711 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0043b424(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *str_2;
  int local_28;
  int local_20;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 2) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      g_ActivePalette = g_ActivePalette | 2;
    }
    if (arg_3 == 0x6c) {
      iVar5 = *(int *)(&DAT_006b2e5c + arg_1 * 0x20);
      iVar3 = FUN_0040a305(*(int *)(&DAT_006b3010 + arg_1 * 4),1,99);
      iVar1 = *(int *)(&DAT_006b2e5c + (1 - arg_1) * 0x20);
      iVar4 = FUN_0040a305(*(int *)(&DAT_006b3000 + (5 - arg_1) * 4),1,99);
      g_SpellStackDepth = g_SpellStackDepth + ((iVar5 * 0xc) / iVar3 - (iVar1 * 0xc) / iVar4);
    }
    if (((arg_3 == 4) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      local_10 = 999;
      local_20 = 0;
      local_14 = 0xffffffff;
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar5 = FUN_00471c32(local_8,local_c);
          if ((iVar5 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 2) != 0)
             ) {
            iVar5 = FUN_00473179(local_8,local_c,0x32,0xffffffff);
            if (iVar5 < local_10) {
              local_14 = local_8 * 0x100 + local_c;
              local_20 = 0;
              local_10 = iVar5;
            }
            if (iVar5 == local_10) {
              local_20 = local_20 + 1;
            }
          }
        }
      }
      if (local_20 == 1) {
        Pic_Subsystem_0044867e((int)local_14 >> 8,local_14 & 0xff,1);
      }
      if (1 < local_20) {
        do {
          strcpy(&g_OverworldWorldState,s_Lowest_power_is_005216e4);
          str_2 = _itoa(local_10,&DAT_00538b80,10);
          strcat(&g_OverworldWorldState,str_2);
          local_18 = -1;
          if (local_28 != -1) {
            local_18 = FUN_00473179(_DAT_0063ee20,local_28,0x32,0xffffffff);
          }
        } while (local_18 != local_10);
        Pic_Subsystem_0044867e(_DAT_0063ee20,local_28,1);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


