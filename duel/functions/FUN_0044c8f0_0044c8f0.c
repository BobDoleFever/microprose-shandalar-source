/*
 * Decompiled function: FUN_0044c8f0
 * Entry Point: 0044c8f0
 * Size: 275 bytes
 */
#include "duel.h"


undefined4 FUN_0044c8f0(char *str_1,int arg2)

{
  byte arg_1;
  int arg_3;
  int local_14;
  uint local_c;
  uint local_8;
  
  local_8 = local_8 & 0xffffff00;
  local_14 = 0;
  while (local_14 < arg2) {
    arg_1 = *str_1;
    local_8 = CONCAT31(local_8._1_3_,arg_1);
    if ((arg2 - local_14 == 1) || (str_1[1] != arg_1)) {
      FUN_0044ca03(arg_1);
      local_14 = local_14 + 1;
      str_1 = str_1 + 1;
    }
    else {
      arg_3 = arg2 - local_14;
      if (0x3e < arg_3) {
        arg_3 = 0x3f;
      }
      local_c = FUN_0044ca50(arg_1,str_1,arg_3);
      local_14 = local_14 + local_c;
      str_1 = str_1 + local_c;
      local_c = local_c | 0xc0;
      FID_conflict___fwrite_lk(&local_c,1,1,DAT_00694434);
      FID_conflict___fwrite_lk(&local_8,1,1,DAT_00694434);
    }
  }
  if (local_14 < DAT_00694482) {
    local_8 = (uint)local_8._1_3_ << 8;
    FID_conflict___fwrite_lk(&local_8,1,1,DAT_00694434);
  }
  return 1;
}


