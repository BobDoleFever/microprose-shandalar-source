/*
 * Decompiled function: Card_Setup_004590b4
 * Entry Point: 0040be43
 * Size: 506 bytes
 */
#include "duel.h"


undefined4 Card_Setup_004590b4(int arg_1,int arg_2,int arg_3)

{
  if ((((arg_3 == 0x85) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
     ((arg_1 == DAT_00666458 && (DAT_00681eb4 == arg_1)))) {
    *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
  }
  if (((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    if ((int)(&DAT_0068ee78)[arg_1] < 1) {
      DAT_0066642c = DAT_0066642c | 1;
    }
    else {
      Palette_Color_0049ae00(arg_1,0,1);
    }
  }
  if (arg_3 == 0x86) {
    Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Unable_to_discard____Mishra_s_Wa_004f2714,0);
    *(uint *)(&DAT_006826cc +
             *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
             *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
         *(uint *)(&DAT_006826cc +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) | 0x10;
    Mem_AllocOrFree_004afd1c(arg_1,3,DAT_00690af0,DAT_0068efa0);
  }
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  if ((arg_3 == 199) && ((&DAT_0068ee78)[arg_1] != 0)) {
    Mem_AllocOrFree_004afd1c(arg_1,3,arg_1,arg_2);
    DAT_0068f2d4 = DAT_0068f2d4 + 0x60;
  }
  return 0;
}


