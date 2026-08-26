/*
 * Decompiled function: Csv_ReadConcise_0040659f
 * Entry Point: 0040659f
 * Size: 226 bytes
 */
#include "magic.h"


void Csv_ReadConcise_0040659f(void)

{
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined4 local_18;
  int local_14;
  int local_10;
  FILE *local_c;
  int local_8;
  
  for (local_14 = 0; local_14 < 0x4e2; local_14 = local_14 + 1) {
    *(undefined4 *)(&DAT_00536e78 + local_14 * 4) = 0xffffffff;
  }
  local_c = fopen(s_concise_csv_00516430,&DAT_0051642c);
  local_10 = 0;
  for (local_14 = 0; local_14 < g_MasterCardCount; local_14 = local_14 + 1) {
    local_10 = *(int *)(&g_MasterCardTypeTable + local_14 * 0x34);
    local_8 = fscanf(local_c,s__d__d__ld_0051643c,local_1c,local_20,&local_18);
    (&DAT_0051aed4)[local_14 * 0x34] = local_20[0];
    *(undefined4 *)(&DAT_00536e78 + local_10 * 4) = local_18;
  }
  fclose(local_c);
  return;
}


