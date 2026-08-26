/*
 * Decompiled function: FUN_0040d64c
 * Entry Point: 0040d64c
 * Size: 223 bytes
 */
#include "magic.h"


void FUN_0040d64c(int arg_1,uint arg_2,int arg_3)

{
  bool bVar1;
  int local_10;
  int local_c;
  
  bVar1 = false;
  local_c = 0;
  while (((local_c < 0x32 && (*(int *)(&DAT_00627870 + local_c * 4 + arg_1 * 0xcc) != -1)) &&
         (!bVar1))) {
    if (*(uint *)(&DAT_00627870 + local_c * 4 + arg_1 * 0xcc) == (arg_3 << 0x10 | arg_2)) {
      bVar1 = true;
      for (local_10 = local_c; local_10 < 0x31; local_10 = local_10 + 1) {
        *(undefined4 *)(&DAT_00627870 + local_10 * 4 + arg_1 * 0xcc) =
             *(undefined4 *)(&DAT_00627874 + local_10 * 4 + arg_1 * 0xcc);
      }
    }
    local_c = local_c + 1;
  }
  return;
}


