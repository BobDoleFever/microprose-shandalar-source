/*
 * Decompiled function: FUN_004af82a
 * Entry Point: 004af82a
 * Size: 294 bytes
 */
#include "duel.h"


void FUN_004af82a(int arg1,int arg2)

{
  int arg_2;
  uint local_c;
  
  DAT_00666754 = arg1;
  DAT_0068edd0 = arg2;
  FUN_0048e8a8(DAT_00666458,0xd4,s_Card_leaving_play_00506580,0);
  *(undefined4 *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) = 0xffffffff;
  FUN_0046ed1c(arg1,arg2);
  if (((&DAT_006826f8)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0) {
    local_c = (uint)(((&DAT_006826cd)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0);
    arg_2 = FUN_004d695b(local_c,*(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20));
    if (arg_2 != -1) {
      FUN_00450eb8(local_c,arg_2,8,2);
    }
    (&DAT_0068ee78)[local_c] = (&DAT_0068ee78)[local_c] + 1;
  }
  return;
}


