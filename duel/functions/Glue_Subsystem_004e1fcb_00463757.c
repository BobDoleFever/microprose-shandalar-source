/*
 * Decompiled function: Glue_Subsystem_004e1fcb
 * Entry Point: 00463757
 * Size: 310 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004e1fcb(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x85) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 && (DAT_00681eb4 == arg_1)))) {
    *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    (&DAT_006827db)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&DAT_006827db)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x04';
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Force_of_Nature_deals_8_damage__004f8cbc,0);
    Mem_AllocOrFree_004afd1c(arg_1,8,DAT_00690af0,DAT_0068efa0);
  }
  if ((arg_3 == 199) && (*(int *)(&DAT_0068ef5c + arg_1 * 0x20) < 4)) {
    Mem_AllocOrFree_004afd1c(arg_1,8,arg_1,arg_2);
  }
  return 0;
}


