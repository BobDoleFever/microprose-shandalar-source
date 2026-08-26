/*
 * Decompiled function: Ai_Subsystem_004bc029
 * Entry Point: 004bc029
 * Size: 1018 bytes
 */
#include "magic.h"


undefined4 Ai_Subsystem_004bc029(undefined4 spell_id,int *target_id,int flags,int height)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int local_8c;
  char local_88 [100];
  int local_24;
  size_t local_20;
  uint local_1c;
  int local_18;
  int local_14;
  char local_10;
  uint local_c;
  int local_8;
  
  g_OverworldWorldState = 0;
  local_1c = FUN_00474d4a();
  if (local_1c == 0xffffffff) {
    strcpy(&g_OverworldWorldState,&DAT_0052d640);
  }
  else {
    local_8 = *(int *)(&DAT_006fecb8 + DAT_006a3f78 * 8);
    local_24 = *(int *)(&DAT_006fecbc + DAT_006a3f78 * 8);
    local_c = local_1c >> 0x10 & 0xff;
    if (local_c == 0x71) {
      strcpy(&g_OverworldWorldState,s_CASTING__0052d5f4);
      Ai_Subsystem_004b90de(local_8,local_24);
      strcat(&g_OverworldWorldState,s___tap_0052d600);
    }
    else if (local_c == 0x72) {
      strcpy(&g_OverworldWorldState,s_ACTIVATING__0052d608);
      Ai_Subsystem_004b90de(local_8,local_24);
      strcat(&g_OverworldWorldState,s___tap_0052d618);
    }
    else if (local_c == 0x7e) {
      strcpy(&g_OverworldWorldState,s_PROCESSING__0052d620);
      Ai_Subsystem_004b90de(local_8,local_24);
      strcat(&g_OverworldWorldState,s___tap_0052d630);
    }
    else {
      strcpy(&g_OverworldWorldState,&DAT_0052d638);
    }
  }
  local_88[0] = '\0';
  if ((*target_id == -1) || (target_id[6] == -1)) {
    if (height == -1) {
      uVar5 = 0xfffffff0;
      pcVar4 = s__c__d_so_far__0052d648;
      iVar6 = flags;
      sVar1 = strlen(local_88);
      sprintf(local_88 + sVar1,pcVar4,uVar5,iVar6);
    }
    else if (flags < height) {
      uVar5 = 0xfffffff0;
      pcVar4 = s__c__d_so_far__max__d__0052d658;
      iVar6 = flags;
      iVar2 = height;
      sVar1 = strlen(local_88);
      sprintf(local_88 + sVar1,pcVar4,uVar5,iVar6,iVar2);
    }
  }
  else if ((*target_id != 0) || (target_id[6] != 0)) {
    local_8c = target_id[6];
    iVar6 = *target_id;
    local_20 = strlen(local_88);
    for (local_8c = local_8c + iVar6; 9 < local_8c; local_8c = local_8c + -10) {
      local_88[local_20] = -0x11;
      iVar6 = local_20 + 1;
      local_20 = local_20 + 1;
      local_88[iVar6] = '\0';
    }
    if (local_8c != 0) {
      local_88[local_20] = (char)local_8c + -0xf;
      iVar6 = local_20 + 1;
      local_20 = local_20 + 1;
      local_88[iVar6] = '\0';
    }
  }
  for (local_14 = 1; local_14 < 6; local_14 = local_14 + 1) {
    if (local_14 == 1) {
      local_10 = -2;
    }
    else if (local_14 == 2) {
      local_10 = -3;
    }
    else if (local_14 == 3) {
      local_10 = -1;
    }
    else if (local_14 == 4) {
      local_10 = -4;
    }
    else {
      local_10 = -5;
    }
    if (target_id[local_14] == -1) {
      if (height == -1) {
        iVar2 = (int)local_10;
        pcVar4 = s__c__d_so_far__0052d670;
        iVar6 = flags;
        sVar1 = strlen(local_88);
        sprintf(local_88 + sVar1,pcVar4,iVar2,iVar6);
      }
      else if (flags < height) {
        iVar3 = (int)local_10;
        pcVar4 = s__c__d_so_far__max__d__0052d680;
        iVar6 = flags;
        iVar2 = height;
        sVar1 = strlen(local_88);
        sprintf(local_88 + sVar1,pcVar4,iVar3,iVar6,iVar2);
      }
    }
    else if (target_id[local_14] != 0) {
      local_20 = strlen(local_88);
      for (local_18 = 0; local_18 < target_id[local_14]; local_18 = local_18 + 1) {
        local_88[local_20] = local_10;
        local_20 = local_20 + 1;
      }
      local_88[local_20] = '\0';
    }
  }
  strcat(&g_OverworldWorldState,local_88);
  return 0;
}


