/*
 * Decompiled function: Csv_WriteConcise_004064f8
 * Entry Point: 004064f8
 * Size: 167 bytes
 */
#include "magic.h"


void Csv_WriteConcise_004064f8(void)

{
  FILE *_File;
  int local_14;
  
  _File = fopen(s_concise_csv_00516414,&DAT_00516410);
  for (local_14 = 0; local_14 < g_MasterCardCount; local_14 = local_14 + 1) {
    fprintf(_File,s__d__d__ld_00516420,*(int *)(&g_MasterCardTypeTable + local_14 * 0x34),
            (int)(char)(&DAT_0051aed4)[local_14 * 0x34],
            *(undefined4 *)(&DAT_00536e78 + *(int *)(&g_MasterCardTypeTable + local_14 * 0x34) * 4))
    ;
  }
  fclose(_File);
  return;
}


