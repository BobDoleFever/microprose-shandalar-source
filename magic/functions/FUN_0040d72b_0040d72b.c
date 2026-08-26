/*
 * Decompiled function: FUN_0040d72b
 * Entry Point: 0040d72b
 * Size: 190 bytes
 */
#include "magic.h"


void FUN_0040d72b(int arg_1,uint arg_2,int arg_3)

{
  bool bVar1;
  int local_c;
  
  if ((0 < (int)arg_2) && (0 < arg_3)) {
    bVar1 = false;
    local_c = 0;
    while ((local_c < 10 && (!bVar1))) {
      if (*(int *)(&DAT_00627a20 + local_c * 4 + arg_1 * 0x2c) == -1) {
        bVar1 = true;
        *(uint *)(&DAT_00627a20 + local_c * 4 + arg_1 * 0x2c) = arg_3 << 0x10 | arg_2 & 0xffff;
        *(undefined4 *)(&DAT_00627a24 + local_c * 4 + arg_1 * 0x2c) = 0xffffffff;
      }
      local_c = local_c + 1;
    }
  }
  return;
}


