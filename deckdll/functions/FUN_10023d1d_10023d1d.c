/*
 * Decompiled function: FUN_10023d1d
 * Entry Point: 10023d1d
 * Size: 278 bytes
 */
#include "deckdll.h"


int32_t FUN_10023d1d(uint8_t *arg1,int arg2)

{
  uint8_t arg_1;
  int arg_3;
  uint32_t local_10;
  int local_c;
  uint32_t local_8;
  
  local_8 = local_8 & 0xffffff00;
  local_c = 0;
  while (local_c < arg2) {
    arg_1 = *arg1;
    local_8 = CONCAT31(local_8._1_3_,arg_1);
    if ((arg2 - local_c == 1) || (arg1[1] != arg_1)) {
      thunk_FUN_10023e33(arg_1);
      local_c = local_c + 1;
      arg1 = arg1 + 1;
    }
    else {
      arg_3 = arg2 - local_c;
      if (0x3e < arg_3) {
        arg_3 = 0x3f;
      }
      local_10 = thunk_FUN_10023e82(arg_1,(char *)arg1,arg_3);
      local_c = local_c + local_10;
      arg1 = arg1 + local_10;
      local_10 = local_10 | 0xc0;
      fwrite(&local_10,1,1,DAT_1013f728);
      fwrite(&local_8,1,1,DAT_1013f728);
    }
  }
  if (local_c < DAT_10140772) {
    local_8 = (uint32_t)local_8._1_3_ << 8;
    fwrite(&local_8,1,1,DAT_1013f728);
  }
  return 1;
}


