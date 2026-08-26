/*
 * Decompiled function: FUN_0049af5c
 * Entry Point: 0049af5c
 * Size: 176 bytes
 */
#include "duel.h"


void FUN_0049af5c(int arg_1,uint arg_2,int arg_3)

{
  bool bVar1;
  int local_c;
  
  if (0 < (int)arg_2) {
    bVar1 = false;
    local_c = 0;
    while ((local_c < 0x32 && (!bVar1))) {
      if (*(int *)(&DAT_00666570 + local_c * 4 + arg_1 * 0xcc) == -1) {
        bVar1 = true;
        *(uint *)(&DAT_00666570 + local_c * 4 + arg_1 * 0xcc) = arg_3 << 0x10 | arg_2;
        *(undefined4 *)(&DAT_00666574 + local_c * 4 + arg_1 * 0xcc) = 0xffffffff;
      }
      local_c = local_c + 1;
    }
  }
  return;
}


