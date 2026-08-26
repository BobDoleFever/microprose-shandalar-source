/*
 * Decompiled function: FUN_0041649d
 * Entry Point: 0041649d
 * Size: 1261 bytes
 */
#include "duel.h"


undefined4 FUN_0041649d(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    iVar1 = FUN_00404b06(arg_1,*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20),-1);
    if (iVar1 == 0) {
      DAT_0068f2d4 = DAT_0068f2d4 +
                     (*(int *)(&DAT_0068edfc + (1 - arg_1) * 0x20) -
                     *(int *)(&DAT_0068edfc + arg_1 * 0x20)) * 0xc;
    }
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
  }
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,1);
    if ((iVar1 == 0) ||
       (((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) !=
          0)) || (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)))) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,1), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,1);
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      local_c = 0;
      while( true ) {
        iVar1 = (&DAT_00666408)[DAT_00676504];
        if ((int)(&DAT_00666408)[DAT_00676504] <= (int)(&DAT_00666408)[DAT_00676510]) {
          iVar1 = (&DAT_00666408)[DAT_00676510];
        }
        if (iVar1 <= local_c) break;
        if (((*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676510 * 0x5b20) != -1) &&
            (((&DAT_006826cc)[local_c * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0)) &&
           (((&DAT_004ff594)
             [*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676510 * 0x5b20) * 0x34] & 2) != 0))
        {
          FUN_0046e571(DAT_00676510,local_c,2);
        }
        if (((*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676504 * 0x5b20) != -1) &&
            (((&DAT_006826cc)[local_c * 0x120 + DAT_00676504 * 0x5b20] & 2) != 0)) &&
           (((&DAT_004ff594)
             [*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676504 * 0x5b20) * 0x34] & 2) != 0))
        {
          FUN_0046e571(DAT_00676504,local_c,2);
        }
        local_c = local_c + 1;
      }
      Pic_Subsystem_004488a0();
      local_c = 0;
      while( true ) {
        iVar1 = (&DAT_00666408)[DAT_00676504];
        if ((int)(&DAT_00666408)[DAT_00676504] <= (int)(&DAT_00666408)[DAT_00676510]) {
          iVar1 = (&DAT_00666408)[DAT_00676510];
        }
        if (iVar1 <= local_c) break;
        if (((*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676510 * 0x5b20) != -1) &&
            (((&DAT_006826cc)[local_c * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0)) &&
           ((((&DAT_004ff594)
              [*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676510 * 0x5b20) * 0x34] & 0x44) !=
             0 && (((&DAT_004ff594)
                    [*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676510 * 0x5b20) * 0x34] & 2)
                   == 0)))) {
          FUN_0046e571(DAT_00676510,local_c,2);
        }
        if ((((*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676504 * 0x5b20) != -1) &&
             (((&DAT_006826cc)[local_c * 0x120 + DAT_00676504 * 0x5b20] & 2) != 0)) &&
            (((&DAT_004ff594)
              [*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676504 * 0x5b20) * 0x34] & 0x44) !=
             0)) && (((&DAT_004ff594)
                      [*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676504 * 0x5b20) * 0x34] & 2
                     ) == 0)) {
          FUN_0046e571(DAT_00676504,local_c,2);
        }
        local_c = local_c + 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


