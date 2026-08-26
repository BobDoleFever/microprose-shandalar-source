/*
 * Decompiled function: Csv_LoadInfo_004060e0
 * Entry Point: 004060e0
 * Size: 728 bytes
 */
#include "magic.h"


void Csv_LoadInfo_004060e0(void)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  char local_328 [384];
  int local_1a8;
  undefined1 local_1a4 [11];
  char acStack_199 [385];
  char local_18;
  FILE *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = fopen(s_info_csv_005163c8,&DAT_005163c4);
  bVar1 = false;
  local_18 = '\0';
  local_328[0] = '\0';
  local_10 = 9;
  do {
    local_8 = fscanf(local_14,s______________005163d4,acStack_199 + 1,local_1a4);
    if (local_8 == -1) break;
    if (acStack_199[1] == '0') {
      local_1a8 = atoi(acStack_199 + 1);
      local_328[0] = '\0';
      local_18 = '\0';
    }
    local_18 = local_18 + '\x01';
    if ((local_18 == local_10) && (bVar1)) {
      strcat(local_328,&DAT_005163e4);
    }
    if (acStack_199[1] == '\"') {
      bVar1 = true;
    }
    if (local_18 == local_10) {
      strcat(local_328,acStack_199 + 1);
    }
    sVar2 = strlen(acStack_199 + 1);
    if (acStack_199[sVar2] == '\"') {
      bVar1 = false;
    }
    if (bVar1) {
      local_18 = local_18 + -1;
    }
    if ((local_18 == local_10) && (iVar3 = Pic_Subsystem_0045268f(local_1a8), iVar3 != -1)) {
      if ((*(uint *)(&DAT_0051aed0 + iVar3 * 0x34) & 0x180) != 0) {
        (&DAT_0051aed4)[iVar3 * 0x34] = 4;
      }
      local_c = 1;
      iVar4 = strcmp(local_328,&DAT_005163e8);
      if (iVar4 == 0) {
        local_c = 3;
      }
      iVar4 = strcmp(local_328,s_Uncommon_005163f0);
      if (iVar4 == 0) {
        local_c = 2;
      }
      if ((((&DAT_0051aed1)[iVar3 * 0x34] & 4) != 0) && (local_c < 3)) {
        local_c = local_c + 1;
      }
      (&DAT_0051aed4)[iVar3 * 0x34] = (undefined1)local_c;
      strcpy(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar3 * 0x34);
      strcat(&g_OverworldWorldState,&DAT_005163fc);
      strcat(&g_OverworldWorldState,local_328);
      Surface_FillRect((int *)g_DisplaySurfaceScreen,100,0x80,0x78,8,0);
      FUN_0040c3cc(&g_OverworldWorldState,0xa0,0x81,0xff);
    }
  } while (local_8 != -1);
  fclose(local_14);
  return;
}


