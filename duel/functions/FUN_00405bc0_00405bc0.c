/*
 * Decompiled function: FUN_00405bc0
 * Entry Point: 00405bc0
 * Size: 322 bytes
 */
#include "duel.h"


undefined4 FUN_00405bc0(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 + ((&DAT_00681ea8)[arg_1] - (&DAT_00681ea8)[1 - arg_1]) * 0x18;
    }
    if ((arg_3 == 0x71) && (DAT_0066aaf4 != 1)) {
      do {
        iVar2 = FUN_004491fe(s_Your_flip_004f2258);
        iVar3 = FUN_004491fe(s_Opponent_flip_004f2264);
        if (iVar2 == 1) {
          Mem_AllocOrFree_004afd1c(0,1,arg_1,arg_2);
        }
        if (iVar3 == 1) {
          Mem_AllocOrFree_004afd1c(1,1,arg_1,arg_2);
        }
        if ((iVar2 != 0) || (iVar3 != 0)) {
          Ai_Subsystem_004cc56d
                    (arg_1,arg_1,arg_2,-1,-1,s_Repeating_since_a_tails_came_up__004f2274,0);
        }
      } while ((iVar2 != 0) || (iVar3 != 0));
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


