/*
 * Decompiled function: FUN_004cc99a
 * Entry Point: 004cc99a
 * Size: 500 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004cc99a(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 == 0x74) {
    if (param_1 == DAT_00676510) {
      uVar1 = (DAT_0066aad4 | _DAT_0066aad0) & 2;
    }
    else {
      uVar1 = *(uint *)(&DAT_0066aad0 + DAT_00676510 * 4) & 2;
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508cec,s_COCOON_00508ce4);
      iVar2 = FUN_00468130(param_1,1 - param_1,param_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
      }
    }
    if (((*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48) &&
        ((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0)) &&
       ((DAT_00690c48 != -1 && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0)))
       ) {
      if (param_3 == 4) {
        *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) + 1;
      }
      if (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) < 4) {
        *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x10;
      }
      else {
        if (param_3 == 0x33) {
          DAT_0066642c = DAT_0066642c + 1;
        }
        if (param_3 == 0x32) {
          DAT_0066642c = DAT_0066642c + 1;
        }
        if (param_3 == 0x34) {
          DAT_0066642c = DAT_0066642c | 0x20;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


