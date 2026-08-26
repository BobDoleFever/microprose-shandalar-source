/*
 * Decompiled function: Glue_Subsystem_004e268e
 * Entry Point: 00463e1a
 * Size: 435 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004e268e(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x85) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 && (DAT_00681eb4 == arg_1)))) {
    *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    (&DAT_006827d9)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827d9)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x03';
    (&DAT_006827d8)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827d8)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x03';
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Cosmic_Horror_deals_7_damage__004f8d10,0);
    Mem_AllocOrFree_004afd1c(arg_1,7,DAT_00690af0,DAT_0068efa0);
    FUN_0046e571(DAT_00690af0,DAT_0068efa0,1);
  }
  if ((arg_3 == 199) &&
     (((int)(&DAT_0068ef54)[arg_1 * 8] < 3 || (*(int *)(&DAT_0068ef6c + arg_1 * 0x20) < 6)))) {
    Mem_AllocOrFree_004afd1c(arg_1,7,arg_1,arg_2);
    FUN_0046e571(arg_1,arg_2,1);
  }
  return 0;
}


