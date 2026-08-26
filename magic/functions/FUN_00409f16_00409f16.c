/*
 * Decompiled function: FUN_00409f16
 * Entry Point: 00409f16
 * Size: 131 bytes
 */
#include "magic.h"


void FUN_00409f16(int arg1,int arg2)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    if (0x4f < local_8) {
      return;
    }
    if ((0 < *(int *)(&DAT_00516cbc + local_8 * 8 + arg1 * 0x280)) &&
       (iVar1 = Pic_Subsystem_0045268f(*(int *)(&DAT_00516cb8 + local_8 * 8 + arg1 * 0x280)),
       iVar1 == arg2)) break;
    local_8 = local_8 + 1;
  }
  *(int *)(&DAT_00516cbc + local_8 * 8 + arg1 * 0x280) =
       *(int *)(&DAT_00516cbc + local_8 * 8 + arg1 * 0x280) + -1;
  return;
}


