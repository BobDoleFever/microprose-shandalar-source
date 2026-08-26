/*
 * Decompiled function: FUN_004be8ae
 * Entry Point: 004be8ae
 * Size: 64 bytes
 */
#include "duel.h"


undefined4 FUN_004be8ae(int arg_1,int arg_2,int arg_3)

{
  if (DAT_00666750 == arg_3) {
    *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
  }
  return 0;
}


