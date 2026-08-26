/*
 * Decompiled function: FUN_0046c7d0
 * Entry Point: 0046c7d0
 * Size: 1141 bytes
 */
#include "duel.h"


uint FUN_0046c7d0(int arg_1)

{
  int iVar1;
  uint uVar2;
  uint auStack_68 [20];
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if ((DAT_0068f230 != -1) && (DAT_00676504 == DAT_00681ec4)) {
    for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
      for (local_14 = 0; (int)local_14 < (int)(&DAT_00666408)[local_10]; local_14 = local_14 + 1) {
        if ((((&DAT_006826cc)[local_10 * 0x5b20 + local_14 * 0x120] & 2) != 0) &&
           (iVar1 = FUN_0046e4c9(local_10,local_14,0x7d,arg_1), iVar1 == 2)) {
          DAT_00666758 = 4;
          DAT_0068eef0 = local_10;
          return local_14;
        }
        if ((((arg_1 == local_10) &&
             (*(int *)(&DAT_00682710 + local_10 * 0x5b20 + local_14 * 0x120) == DAT_0068f230)) &&
            (local_10 == DAT_00681ec4)) && (DAT_0068f230 != -1)) {
          DAT_00666758 = DAT_00666758 | 4;
          DAT_00666454 = DAT_00666454 + 1;
          DAT_0068eef0 = local_10;
          return local_14;
        }
      }
    }
  }
  if (((((byte)DAT_00666440 & 2) == 0) || (arg_1 == DAT_00676510)) || (DAT_0068ef98 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    DAT_0068eef0 = arg_1;
    for (local_14 = 0; (int)local_14 < (int)(&DAT_00666408)[arg_1]; local_14 = local_14 + 1) {
      local_c = *(int *)(&DAT_006826c4 + local_14 * 0x120 + arg_1 * 0x5b20);
      if ((local_c != -1) && (local_18 = FUN_0046cc45(arg_1,local_14), local_18 != 0)) {
        auStack_68[local_8] = local_14;
        local_8 = local_8 + 1;
        if (local_18 == 2) {
          return local_14;
        }
      }
    }
    if (DAT_00666744 == 4) {
      for (local_14 = 0; (int)local_14 < (int)(&DAT_00666408)[1 - arg_1]; local_14 = local_14 + 1) {
        local_c = *(int *)(&DAT_006826c4 + local_14 * 0x120 + (1 - arg_1) * 0x5b20);
        if (((local_c != -1) && (local_18 = FUN_0046cc45(1 - arg_1,local_14), local_18 != 0)) &&
           (local_18 == 2)) {
          DAT_0068eef0 = 1 - arg_1;
          return local_14;
        }
      }
    }
    if (DAT_00666744 == 4) {
      uVar2 = 0xffffffff;
    }
    else {
      auStack_68[local_8] = 0xffffffff;
      local_8 = local_8 + 1;
      if (DAT_0066aaf4 == 1) {
        iVar1 = FUN_00439892(2);
        if ((iVar1 == 0) || (iVar1 = Mem_AllocOrFree_004308cf(), iVar1 == 0)) {
          DAT_0068f2c8 = FUN_00439892(local_8);
        }
        else {
          DAT_0068f2c8 = local_8 + -1;
        }
        if ((DAT_0066aadc != 0) && (DAT_0068f2c8 = local_8 + -1, DAT_0066aadc == 1)) {
          DAT_0066aadc = -1;
        }
        DAT_0068f0bc = (-(uint)((*(uint *)(&DAT_006826cc +
                                          arg_1 * 0x5b20 + auStack_68[DAT_0068f2c8] * 0x120) & 2) ==
                               0) & 0xfffff000) + 0x2000 | auStack_68[DAT_0068f2c8] |
                       (arg_1 == 0) - 1 & 0x100;
        DAT_004f3c6c = 4;
        FUN_0043064a();
      }
      else {
        DAT_004f3c6c = 4;
        FUN_004307b2();
        if (local_8 <= DAT_0068f2c8) {
          DAT_0068f2c8 = local_8 + -1;
        }
      }
      if (auStack_68[DAT_0068f2c8] != 0xffffffff) {
        if (0xf < DAT_0066aae4) {
          DAT_0066aae4 = DAT_0066aae4 + -1;
        }
        *(undefined4 *)(&DAT_0068ef00 + DAT_0066aae4 * 4) =
             *(undefined4 *)(&DAT_006826c4 + arg_1 * 0x5b20 + auStack_68[DAT_0068f2c8] * 0x120);
        *(uint *)(&DAT_00666770 + DAT_0066aae4 * 4) = auStack_68[DAT_0068f2c8];
        DAT_0066aae4 = DAT_0066aae4 + 1;
      }
      uVar2 = auStack_68[DAT_0068f2c8];
    }
  }
  return uVar2;
}


