/*
 * Decompiled function: FUN_00409eb0
 * Entry Point: 00409eb0
 * Size: 102 bytes
 */
#include "magic.h"


void FUN_00409eb0(int arg_1)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00516cb8 + local_8 * 8) =
         *(undefined4 *)(&DAT_00516cb8 + local_8 * 8 + arg_1 * 0x280);
    *(undefined4 *)(&DAT_00516cbc + local_8 * 8) =
         *(undefined4 *)(&DAT_00516cbc + local_8 * 8 + arg_1 * 0x280);
  }
  return;
}


