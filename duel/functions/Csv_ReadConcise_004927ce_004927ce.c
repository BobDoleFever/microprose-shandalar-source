/*
 * Decompiled function: Csv_ReadConcise_004927ce
 * Entry Point: 004927ce
 * Size: 164 bytes
 */
#include "duel.h"


void Csv_ReadConcise_004927ce(void)

{
  FILE *fp;
  int local_14;
  
  fp = _fopen(s_concise_csv_005053f4,&DAT_005053f0);
  for (local_14 = 0; local_14 < DAT_00665ed0; local_14 = local_14 + 1) {
    _fprintf(fp,s__d__d__ld_00505400,*(int *)(&DAT_004ff590 + local_14 * 0x34),
             (int)(char)(&DAT_004ff5ac)[local_14 * 0x34],
             *(undefined4 *)(&DAT_005daf18 + *(int *)(&DAT_004ff590 + local_14 * 0x34) * 4));
  }
  _fclose(fp);
  return;
}


