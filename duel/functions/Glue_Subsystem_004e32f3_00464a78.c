/*
 * Decompiled function: Glue_Subsystem_004e32f3
 * Entry Point: 00464a78
 * Size: 497 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004e32f3(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int local_14;
  int local_c;
  
  if (((((DAT_0068f230 == 0xcb) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 && (arg_1 == DAT_00666458)))) && (DAT_00681ec4 == arg_1)) {
    iVar1 = FUN_004d7d5e(0xab);
    local_14 = 0;
    for (local_c = 499; -1 < local_c; local_c = local_c + -1) {
      if (((*(int *)(&DAT_0068f370 + local_c * 4 + arg_1 * 2000) != -1) &&
          (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_c * 4 + arg_1 * 2000) * 0x34] & 2) != 0))
         && ((local_14 = local_14 + 1, *(int *)(&DAT_0068f370 + local_c * 4 + arg_1 * 2000) == iVar1
             && (3 < local_14)))) {
        if (arg_3 == 0x7d) {
          DAT_0066642c = DAT_0066642c | 1;
        }
        if ((arg_3 != 0x7e) && (arg_3 != 199)) {
          return 0;
        }
        iVar1 = Pic_Subsystem_00451291(arg_1,iVar1);
        if (iVar1 == -1) {
          return 0;
        }
        Pic_Subsystem_0042ac1f(arg_1,iVar1);
        *(uint *)(&DAT_006826cc + iVar1 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + iVar1 * 0x120 + arg_1 * 0x5b20) & 0xfffcffff;
        FUN_0046f116(arg_1,local_c);
        FUN_0046e571(arg_1,arg_2,4);
        FUN_00451482(0,0x30);
        Ai_Subsystem_004cc56d(arg_1,arg_1,iVar1,-1,-1,s_is_returning_from_the_grave__004f8d88,0);
        return 0;
      }
    }
  }
  return 0;
}


