/*
 * Decompiled function: Csv_ReadConcise_00492872
 * Entry Point: 00492872
 * Size: 223 bytes
 */
#include "duel.h"


void Csv_ReadConcise_00492872(void)

{
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined4 local_18;
  int local_14;
  int local_10;
  FILE *local_c;
  int local_8;
  
  for (local_14 = 0; local_14 < 0x4e2; local_14 = local_14 + 1) {
    *(undefined4 *)(&DAT_005daf18 + local_14 * 4) = 0xffffffff;
  }
  local_c = _fopen(s_concise_csv_00505410,&DAT_0050540c);
  local_10 = 0;
  for (local_14 = 0; local_14 < DAT_00665ed0; local_14 = local_14 + 1) {
    local_10 = *(int *)(&DAT_004ff590 + local_14 * 0x34);
    local_8 = _fscanf(local_c,s__d__d__ld_0050541c,local_1c,local_20,&local_18);
    (&DAT_004ff5ac)[local_14 * 0x34] = local_20[0];
    *(undefined4 *)(&DAT_005daf18 + local_10 * 4) = local_18;
  }
  _fclose(local_c);
  return;
}


