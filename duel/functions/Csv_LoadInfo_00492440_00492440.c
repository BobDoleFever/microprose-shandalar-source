/*
 * Decompiled function: Csv_LoadInfo_00492440
 * Entry Point: 00492440
 * Size: 595 bytes
 */
#include "duel.h"


/* WARNING: Type propagation algorithm not settling */

void Csv_LoadInfo_00492440(void)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  uint local_328 [96];
  int local_1a8;
  undefined1 local_1a4 [11];
  char acStack_199 [385];
  char local_18;
  FILE *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = _fopen(s_info_csv_005053ac,&DAT_005053a8);
  bVar1 = false;
  local_18 = '\0';
  local_328[0]._0_1_ = '\0';
  local_10 = 9;
  do {
    local_8 = _fscanf(local_14,s______________005053b8,(int)acStack_199 + 1,local_1a4);
    if (local_8 == -1) break;
    if (acStack_199[1] == '0') {
      local_1a8 = _atoi((char *)((int)acStack_199 + 1));
      local_328[0]._0_1_ = '\0';
      local_18 = '\0';
    }
    local_18 = local_18 + '\x01';
    if ((local_18 == local_10) && (bVar1)) {
      FUN_004d9640(local_328,(uint *)&DAT_005053c8);
    }
    if (acStack_199[1] == '\"') {
      bVar1 = true;
    }
    if (local_18 == local_10) {
      FUN_004d9640(local_328,(uint *)((int)acStack_199 + 1));
    }
    sVar2 = _strlen((char *)((int)acStack_199 + 1));
    if (acStack_199[sVar2] == '\"') {
      bVar1 = false;
    }
    if (bVar1) {
      local_18 = local_18 + -1;
    }
    if ((local_18 == local_10) && (iVar3 = FUN_004d7d5e(local_1a8), iVar3 != -1)) {
      if ((*(uint *)(&DAT_004ff5a8 + iVar3 * 0x34) & 0x180) != 0) {
        (&DAT_004ff5ac)[iVar3 * 0x34] = 4;
      }
      local_c = 1;
      iVar4 = _strcmp((char *)local_328,&DAT_005053cc);
      if (iVar4 == 0) {
        local_c = 3;
      }
      iVar4 = _strcmp((char *)local_328,s_Uncommon_005053d4);
      if (iVar4 == 0) {
        local_c = 2;
      }
      if ((((&DAT_004ff5a9)[iVar3 * 0x34] & 4) != 0) && (local_c < 3)) {
        local_c = local_c + 1;
      }
      (&DAT_004ff5ac)[iVar3 * 0x34] = (undefined1)local_c;
    }
  } while (local_8 != -1);
  _fclose(local_14);
  return;
}


