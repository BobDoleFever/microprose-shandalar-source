/*
 * Decompiled function: FUN_004623a9
 * Entry Point: 004623a9
 * Size: 580 bytes
 */
#include "duel.h"


bool FUN_004623a9(int param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  if (((param_3 == 199) && (iVar1 = FUN_0048a33f(param_1,param_2), iVar1 != 0)) &&
     (3 < *(short *)(&DAT_006826d6 + param_2 * 0x120 + param_1 * 0x5b20))) {
    if (param_1 == DAT_00676504) {
      DAT_0068f2d4 = DAT_0068f2d4 + 200;
    }
    else {
      DAT_0068f2d4 = DAT_0068f2d4 + -200;
    }
  }
  if (param_3 == 0x73) {
    bVar2 = (*(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0x20010) == 0;
  }
  else if (param_3 == 0x90) {
    FUN_0043071d(1);
    bVar2 = false;
  }
  else {
    if (param_3 == 0x6d) {
      FUN_00434660(s_prompts_txt_004f8c94,s_PSIONIC_ENTITY_004f8c84);
      FUN_00461047(param_1,param_2,2);
      if (DAT_00681ea4 != 1) {
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
    }
    if (param_3 == 0x72) {
      iVar1 = FUN_004612b0(param_1,param_2,0x72,2);
      if ((iVar1 != 0) &&
         (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) != -1)) {
        FUN_004af950(DAT_00690af0,DAT_0068efa0,3,DAT_00690af0,DAT_0068efa0);
      }
      (&DAT_006827b8)
      [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120] = 0;
    }
    bVar2 = false;
  }
  return bVar2;
}


