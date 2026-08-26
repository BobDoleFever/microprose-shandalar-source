/*
 * Decompiled function: FUN_004a3dd6
 * Entry Point: 004a3dd6
 * Size: 435 bytes
 */
#include "duel.h"


undefined4 FUN_004a3dd6(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x73) {
    uVar1 = FUN_0049b309(arg_1,7,1);
  }
  else {
    if (((arg_3 == 0x6d) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      iVar2 = FUN_0049b309(arg_1,7,1);
      if (iVar2 != 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      }
    }
    if (arg_3 == 0x72) {
      FUN_0046e571(DAT_00690af0,DAT_0068efa0,4);
    }
    if ((((DAT_0068f230 == 0xce) || (arg_3 == 199)) &&
        ((DAT_00690c48 == arg_2 && ((DAT_0068ecb0 == arg_1 && (DAT_00666458 == arg_1)))))) &&
       (arg_1 == DAT_00681ec4)) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Naf_s_Asp_takes_1_life__00506020,0);
        Mem_AllocOrFree_004afd1c(arg_1,1,arg_1,arg_2);
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      if (DAT_0066aaf4 == 1) {
        Mem_AllocOrFree_004afd1c(arg_1,1,arg_1,arg_2);
      }
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


