/*
 * Decompiled function: FUN_004cc5eb
 * Entry Point: 004cc5eb
 * Size: 938 bytes
 */
#include "duel.h"


undefined4 FUN_004cc5eb(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6a) {
      *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      for (local_c = 0; local_c < (int)(&DAT_00666408)[DAT_00666458]; local_c = local_c + 1) {
        iVar2 = FUN_0048a33f(DAT_00666458,local_c);
        if (((iVar2 != 0) &&
            (((&DAT_006826cc)[local_c * 0x120 + DAT_00666458 * 0x5b20] & 0x10) == 0)) &&
           (((&DAT_004ff594)
             [*(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00666458 * 0x5b20) * 0x34] & 1) != 0))
        {
          *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) + 1;
        }
      }
    }
    if (arg_3 == 0x73) {
      if (((DAT_0068f2c4 == 4) && (((&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)) &&
         (DAT_00666458 == DAT_00681eb4)) {
        *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x101;
        DAT_00676500 = DAT_00676500 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((arg_3 == 4) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
        *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
        DAT_006664ec = 1;
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (arg_3 == 0x86) {
        Mem_AllocOrFree_004afd1c
                  (DAT_00666458,*(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1,arg_2
                  );
        *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      }
      if (arg_3 == 0x22) {
        *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
      }
      if (arg_3 == 199) {
        local_8 = 0;
        for (local_c = 0; local_c < (int)(&DAT_00666408)[1 - DAT_00666458]; local_c = local_c + 1) {
          iVar2 = FUN_0048a33f(1 - DAT_00666458,local_c);
          if (((iVar2 != 0) &&
              (((&DAT_006826cc)[local_c * 0x120 + (1 - DAT_00666458) * 0x5b20] & 0x10) == 0)) &&
             (((&DAT_004ff594)
               [*(int *)(&DAT_006826c4 + local_c * 0x120 + (1 - DAT_00666458) * 0x5b20) * 0x34] & 1)
              != 0)) {
            local_8 = local_8 + 1;
          }
        }
        Mem_AllocOrFree_004afd1c(1 - DAT_00666458,local_8,arg_1,arg_2);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


