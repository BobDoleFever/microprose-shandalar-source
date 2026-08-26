/*
 * Decompiled function: Castle_Process_00491d8f
 * Entry Point: 00491d8f
 * Size: 1320 bytes
 */
#include "magic.h"


undefined4 Castle_Process_00491d8f(undefined4 arg_1,int y,int width,int height)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  int arg_4;
  int iVar4;
  int iVar5;
  char *str_2;
  int local_3c [7];
  undefined4 local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(&DAT_0067bdf0 + y * 100) == 4) {
    strcpy(&g_OverworldWorldState,s_Castle_00528680);
  }
  else {
    g_OverworldWorldState = 0;
    Ai_TownEncounter_004c3b19(y);
  }
  local_18 = 0;
  while (sVar1 = strlen(&g_OverworldWorldState), local_18 < sVar1) {
    if ((&g_OverworldWorldState)[local_18] == ' ') {
      (&g_OverworldWorldState)[local_18] = 10;
    }
    local_18 = local_18 + 1;
  }
  strcat(&g_OverworldWorldState,&DAT_00528688);
  uVar2 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + y * 100),*(int *)(&DAT_0067bdf8 + y * 100));
  local_3c[6] = Adventure_GetLocationEncounterIndex(uVar2);
  if (((&DAT_0067be00)[y * 100] & 1) == 0) {
    local_c = 0xe3;
  }
  else {
    local_c = 0xff;
  }
  if ((&DAT_0067be01)[y * 100] != '\0') {
    local_c = *(int *)(&DAT_00526e48 + ((int)(*(uint *)(&DAT_0067be00 + y * 100) & 0xffffff00) >> 6)
                      );
  }
  iVar5 = height;
  iVar3 = Ai_Util_004c3bc4(width + 0x2a);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,local_c,iVar3,iVar5);
  if (((&DAT_0067be00)[y * 100] & 1) != 0) {
    iVar5 = height;
    iVar3 = Ai_Util_004c3bc4(width + 0x20c);
    FUN_0040d269((int)g_DisplaySurfaceBackBuffer,local_c,iVar3,iVar5);
  }
  uVar2 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + y * 100),*(int *)(&DAT_0067bdf8 + y * 100));
  local_3c[6] = Adventure_GetLocationEncounterIndex(uVar2);
  local_8 = 0;
  for (local_18 = 1; (int)local_18 < 6; local_18 = local_18 + 1) {
    if ((local_3c[6] & 1 << ((byte)local_18 & 0x1f)) != 0) {
      local_8 = local_8 + 1;
    }
  }
  local_10 = (int)*(short *)(DAT_006776a0 + 4);
  local_14 = (int)*(short *)(DAT_006776a0 + 6);
  local_1c = Ai_Util_004c3bc4(((width + 0x80) - (local_10 * local_8) / 2) - (local_8 * 5 + -5));
  for (local_18 = 1; (int)local_18 < 6; local_18 = local_18 + 1) {
    local_3c[1] = 2;
    local_3c[2] = 1;
    local_3c[3] = 4;
    local_3c[4] = 3;
    local_3c[5] = 0;
    if ((local_3c[6] & 1 << ((byte)local_18 & 0x1f)) != 0) {
      iVar5 = (&DAT_006776a0)[local_3c[local_18]];
      iVar3 = Ai_Util_004c3bc4(local_14);
      arg_4 = Ai_Util_004c3bc4(local_10);
      iVar4 = Ai_Util_004c3bc4(local_14 / 2);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,local_1c,height - iVar4,arg_4,iVar3,iVar5)
      ;
      iVar5 = Ai_Util_004c3bc4(local_10 + 5);
      local_1c = local_1c + iVar5;
    }
  }
  local_3c[6] = FUN_00473cc5((byte)*(undefined4 *)(&DAT_0067bdfc + y * 100));
  g_OverworldWorldState = 0;
  if ((&DAT_0067bdfc)[y * 100] == '\0') {
    strcat(&g_OverworldWorldState,&DAT_00528690);
  }
  else {
    str_2 = (char *)Mem_AllocOrFree_00473d7e(local_3c[6]);
    strcat(&g_OverworldWorldState,str_2);
  }
  local_3c[0] = *(int *)(&DAT_0067bdfc + y * 100) >> 8;
  switch(local_3c[0]) {
  case 0:
    strcat(&g_OverworldWorldState,s_Cards_00528694);
    break;
  case 1:
    strcat(&g_OverworldWorldState,s_Land_0052869c);
    break;
  case 2:
    strcat(&g_OverworldWorldState,s_Creatures_005286a4);
    break;
  case 3:
    strcat(&g_OverworldWorldState,s_Enchantments_005286b0);
    break;
  case 4:
    strcat(&g_OverworldWorldState,s_Sorceries_005286c0);
    break;
  case 5:
    strcat(&g_OverworldWorldState,s_Fast_Effects_005286cc);
    break;
  case 7:
    strcat(&g_OverworldWorldState,s_Artifacts_005286dc);
  }
  iVar5 = height;
  iVar3 = Ai_Util_004c3bc4(width + 0xff);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,local_c,iVar3,iVar5);
  g_OverworldWorldState = 0;
  for (local_18 = 0; (int)local_18 < 0xc; local_18 = local_18 + 1) {
    if ((y != 0) && (*(int *)(&DAT_005224e8 + local_18 * 0x10) == y)) {
      local_20 = Bazaar_GetCardBaseValue(local_18);
      strcat(&g_OverworldWorldState,(&PTR_s_Sleight_of_hand_005225d0)[local_18]);
    }
  }
  iVar5 = Ai_Util_004c3bc4(width + 0x19c);
  FUN_0040d269((int)g_DisplaySurfaceBackBuffer,local_c,iVar5,height);
  return 0;
}


