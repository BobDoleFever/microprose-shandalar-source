/*
 * Decompiled function: Ai_ScoreBoardPosition
 * Entry Point: 004ab45f
 * Size: 177 bytes
 */
#include "magic.h"


void Ai_ScoreBoardPosition(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < DAT_0054be44; local_8 = local_8 + 1) {
    (&DAT_005520c8)[local_8] = (&DAT_005524c8)[local_8];
    *(undefined4 *)(&DAT_0054f838 + local_8 * 4) = *(undefined4 *)(&DAT_0054fc38 + local_8 * 4);
    *(undefined4 *)(&DAT_00553440 + local_8 * 4) = *(undefined4 *)(&DAT_00553840 + local_8 * 4);
    *(undefined4 *)(&DAT_005514f8 + local_8 * 4) = *(undefined4 *)(&DAT_00553c40 + local_8 * 4);
  }
  (&DAT_005520c8)[DAT_0054be44] = 99;
  if (DAT_005520c8 == 99) {
    DAT_00556928 = DAT_0054be44;
  }
  DAT_00633434 = 1;
  return;
}


