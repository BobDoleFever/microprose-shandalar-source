/*
 * Decompiled function: FUN_004ca742
 * Entry Point: 004ca742
 * Size: 387 bytes
 */
#include "duel.h"


void FUN_004ca742(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0x74) {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508c40,s_INVISIBILITY_00508c30);
      iVar1 = FUN_00468130(param_1,param_1,param_2);
      if (iVar1 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
      }
    }
    if (((param_3 == 0x78) &&
        (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_0068ecfc)) &&
       (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00690310 &&
        ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0 &&
         ((&DAT_004ff595)
          [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] != '\0')))
        ))) {
      DAT_0066642c = DAT_0066642c + 1;
    }
  }
  return;
}


