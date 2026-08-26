/*
 * Decompiled function: FUN_0041f17e
 * Entry Point: 0041f17e
 * Size: 149 bytes
 */
#include "magic.h"


undefined4 FUN_0041f17e(int arg_1,int arg_2,int arg_3)

{
  int local_c;
  int local_8;
  
  local_c = *(int *)(&DAT_0067f780 + arg_3 * 4);
  for (local_8 = 0; local_8 < arg_2; local_8 = local_8 + 1) {
    *(int *)(&DAT_0067f7d0 + arg_3 * 200 + local_c * 4) = local_8 * 0x54 + arg_1;
    local_c = local_c + 1;
  }
  *(int *)(&DAT_0067f780 + arg_3 * 4) = *(int *)(&DAT_0067f780 + arg_3 * 4) + arg_2;
  DAT_00680770 = 0;
  return *(undefined4 *)(&DAT_0067f780 + arg_3 * 4);
}


