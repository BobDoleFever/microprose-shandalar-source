/*
 * Decompiled function: FUN_004c2ca0
 * Entry Point: 004c2ca0
 * Size: 387 bytes
 */
#include "duel.h"


undefined4 FUN_004c2ca0(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 2) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
       (((&DAT_0066aad0)[arg_1 * 4] & 2) != 0)) {
      DAT_0066642c = DAT_0066642c | 1;
    }
    if (((arg_3 == 4) && (DAT_00690c48 == arg_2)) &&
       ((DAT_0068ecb0 == arg_1 && (((&DAT_0066aad0)[arg_1 * 4] & 2) != 0)))) {
      iVar2 = FUN_0045102d(arg_1,arg_1,arg_2,-1,-1,s_Sacrifice_creature_to_use_gate__N_00508a44,0);
      if (iVar2 != 0) {
        iVar2 = FUN_00468383(arg_1);
        if (iVar2 != -1) {
          FUN_0046e571(arg_1,iVar2,3);
          if ((iVar2 != -1) &&
             (((&DAT_004ff594)
               [*(int *)(&DAT_006826c4 +
                        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) * 0x34] &
              0x40) != 0)) {
            FUN_0046e571(DAT_0068eef0,iVar2,2);
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


