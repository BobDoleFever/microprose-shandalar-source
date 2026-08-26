/*
 * Decompiled function: FUN_0041698a
 * Entry Point: 0041698a
 * Size: 193 bytes
 */
#include "duel.h"


undefined4 FUN_0041698a(int arg_1,int arg_2,int arg_3)

{
  if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) &&
     (((&DAT_004ff594)[arg_3 * 0x34] & 2) != 0)) {
    FUN_0046e571(arg_1,arg_2,2);
  }
  Pic_Subsystem_004488a0();
  if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) &&
     (((&DAT_004ff594)[arg_3 * 0x34] & 0x44) != 0)) {
    FUN_0046e571(arg_1,arg_2,2);
  }
  return 0;
}


