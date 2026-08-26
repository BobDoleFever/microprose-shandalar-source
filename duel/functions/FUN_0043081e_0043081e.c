/*
 * Decompiled function: FUN_0043081e
 * Entry Point: 0043081e
 * Size: 177 bytes
 */
#include "duel.h"


void FUN_0043081e(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_0050b37c; local_8 = local_8 + 1) {
    (&DAT_00511600)[local_8] = (&DAT_00511a00)[local_8];
    *(undefined4 *)(&DAT_0050ed70 + local_8 * 4) = *(undefined4 *)(&DAT_0050f170 + local_8 * 4);
    *(undefined4 *)(&DAT_00512978 + local_8 * 4) = *(undefined4 *)(&DAT_00512d78 + local_8 * 4);
    *(undefined4 *)(&DAT_00510a30 + local_8 * 4) = *(undefined4 *)(&DAT_00513178 + local_8 * 4);
  }
  (&DAT_00511600)[DAT_0050b37c] = 99;
  if (DAT_00511600 == 99) {
    DAT_00515e60 = DAT_0050b37c;
  }
  DAT_0067650c = 1;
  return;
}


