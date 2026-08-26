/*
 * Decompiled function: FUN_0050b00c
 * Entry Point: 0050b00c
 * Size: 240 bytes
 */
#include "magic.h"


int FUN_0050b00c(void)

{
  int arg_1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0x7fff;
  local_c = -1;
  for (local_14 = 0; local_14 < 0xf; local_14 = local_14 + 1) {
    if ((*(int *)(&DAT_0067eff0 + local_14 * 0x30) != -1) &&
       (*(int *)(&DAT_0067f010 + local_14 * 0x30) != 7)) {
      arg_1 = FUN_0040a36f(DAT_00641010 - *(int *)(&DAT_0067f000 + local_14 * 0x30),
                           DAT_00641014 - *(int *)(&DAT_0067f004 + local_14 * 0x30));
      local_8 = FUN_0040a1d2(arg_1);
      local_8 = local_8 + arg_1 / 2;
      if (((&DAT_0067f015)[local_14 * 0x30] & 2) != 0) {
        local_8 = local_8 * 3;
      }
      if (local_8 < local_10) {
        local_c = local_14;
        local_10 = local_8;
      }
    }
  }
  return local_c;
}


