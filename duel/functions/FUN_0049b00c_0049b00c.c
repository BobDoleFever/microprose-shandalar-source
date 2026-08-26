/*
 * Decompiled function: FUN_0049b00c
 * Entry Point: 0049b00c
 * Size: 223 bytes
 */
#include "duel.h"


void FUN_0049b00c(int arg_1,uint arg_2,int arg_3)

{
  bool bVar1;
  int local_10;
  int local_c;
  
  bVar1 = false;
  local_c = 0;
  while (((local_c < 0x32 && (*(int *)(&DAT_00666570 + local_c * 4 + arg_1 * 0xcc) != -1)) &&
         (!bVar1))) {
    if (*(uint *)(&DAT_00666570 + local_c * 4 + arg_1 * 0xcc) == (arg_3 << 0x10 | arg_2)) {
      bVar1 = true;
      for (local_10 = local_c; local_10 < 0x31; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00666570 + local_10 * 4 + arg_1 * 0xcc) =
             *(undefined4 *)(&DAT_00666574 + local_10 * 4 + arg_1 * 0xcc);
      }
    }
    local_c = local_c + 1;
  }
  return;
}


