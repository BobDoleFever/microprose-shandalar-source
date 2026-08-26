/*
 * Decompiled function: FUN_0046e571
 * Entry Point: 0046e571
 * Size: 546 bytes
 */
#include "duel.h"


void FUN_0046e571(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_1 != -1) && (arg_2 != -1)) &&
     (((&DAT_006826f8)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x80) == 0)) {
    *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x80;
    iVar1 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + arg_2 * 0x120);
    if (iVar1 != -1) {
      if (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) == 0) {
        arg_3 = 3;
      }
      if (((((&DAT_006826f8)[arg_1 * 0x5b20 + arg_2 * 0x120] & 8) == 0) && (arg_3 != 3)) &&
         ((arg_3 != 4 &&
          ((((&DAT_004ff594)[iVar1 * 0x34] & 3) != 0 && ((&DAT_004ff594)[iVar1 * 0x34] != -0x80)))))
         ) {
        (&DAT_006826e0)[arg_1 * 0x5b20 + arg_2 * 0x120] = (undefined1)arg_3;
        *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 2;
        if (((&DAT_004ff594)[iVar1 * 0x34] & 2) == 0) {
          Pic_Subsystem_0044895f(arg_1,arg_2);
        }
        else {
          *(undefined4 *)(&DAT_00682710 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0xd6;
        }
        DAT_00666760 = Pic_Subsystem_0044895f;
      }
      else {
        (&DAT_006826e0)[arg_1 * 0x5b20 + arg_2 * 0x120] = (undefined1)arg_3;
        Pic_Subsystem_0044895f(arg_1,arg_2);
      }
    }
  }
  return;
}


