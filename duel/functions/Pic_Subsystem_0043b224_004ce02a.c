/*
 * Decompiled function: Pic_Subsystem_0043b224
 * Entry Point: 004ce02a
 * Size: 512 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0043b224(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      DAT_0068f2d4 = DAT_0068f2d4 + ((&DAT_00681ea8)[arg_1] - (&DAT_00681ea8)[1 - arg_1]) * 0xc;
    }
    if (((arg_3 == 2) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (((arg_3 == 4) && (DAT_00690c48 == arg_2)) && (arg_1 == DAT_0068ecb0)) {
      iVar2 = FUN_0049b309(arg_1,3,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1);
      if (iVar2 == 0) {
        FUN_0046e571(arg_1,arg_2,2);
      }
      else {
        iVar2 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,s_Pay_mana__No_Yes_00508d58,1);
        if (iVar2 == 0) {
          FUN_0046e571(arg_1,arg_2,2);
        }
        else {
          Ai_CalcManaRequirement_004ba890
                    (arg_1,3,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1);
          *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
          Mem_AllocOrFree_004afd1c
                    (1 - arg_1,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1,arg_2)
          ;
          Mem_AllocOrFree_004afd1c
                    (arg_1,*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1,arg_2);
          FUN_00467d65(FUN_004cdfdd,-1);
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


