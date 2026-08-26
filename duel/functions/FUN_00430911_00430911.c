/*
 * Decompiled function: FUN_00430911
 * Entry Point: 00430911
 * Size: 2728 bytes
 */
#include "duel.h"


int FUN_00430911(int arg_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *arg2;
  bool bVar5;
  uint local_e4;
  uint local_d4 [2];
  byte local_cc [160];
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  DAT_005ef980 = 1;
  local_c = 0;
  local_28 = 1 - arg_1;
  FUN_00431f41(local_d4,local_d4 + 1);
  _memset(local_cc,0,0xa0);
  local_20 = 0;
  for (local_1c = 1; local_1c <= (int)(&DAT_00681ea8)[arg_1]; local_1c = local_1c + 1) {
    local_20 = local_20 + (int)(0x18 / (longlong)local_1c) + 0xc;
  }
  iVar1 = *(int *)(&DAT_00666710 + arg_1 * 4) * local_20;
  local_20 = 0;
  for (local_1c = 1; local_1c <= (int)(&DAT_00681ea8)[local_28]; local_1c = local_1c + 1) {
    local_20 = local_20 + (int)(0x18 / (longlong)local_1c) + 0xc;
  }
  local_c = ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3) -
            ((int)(*(int *)(&DAT_00666710 + local_28 * 4) * local_20 +
                  (*(int *)(&DAT_00666710 + local_28 * 4) * local_20 >> 0x1f & 7U)) >> 3);
  if ((int)(&DAT_00681ea8)[arg_1] < 1) {
    local_c = local_c + ((&DAT_00681ea8)[arg_1] * 4 + -8) * 0x4b;
  }
  if ((int)(&DAT_00681ea8)[local_28] < 1) {
    local_c = local_c + ((&DAT_00681ea8)[local_28] + -2) * -0x100;
  }
  if (DAT_005ef574 != 0) {
    DAT_005f6810 = 0;
  }
  local_8 = 0;
  do {
    if (1 < local_8) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_1c = 0; local_1c < (int)(&DAT_00666408)[local_8]; local_1c = local_1c + 1) {
          if ((1 << ((byte)arg_1 & 0x1f) & (int)(char)local_cc[local_8 * 0x50 + local_1c]) != 0) {
            local_c = local_c + 2;
          }
          if ((1 << (1 - (byte)arg_1 & 0x1f) & (int)(char)local_cc[local_8 * 0x50 + local_1c]) != 0)
          {
            local_c = local_c + -2;
          }
        }
      }
      if ((DAT_006c121c == 0) && (DAT_00666458 == arg_1)) {
        local_c = FUN_004313b9(arg_1,local_c);
      }
      DAT_005ef980 = 0;
      return local_c;
    }
    local_28 = 1 - local_8;
    local_10 = -(((-(uint)(DAT_00676504 == local_8) & 0x30) + 0x18) *
                *(int *)(&DAT_0068f2fc + local_8 * 0x20));
    for (local_1c = 1; local_1c < 6; local_1c = local_1c + 1) {
      for (local_24 = 1; local_24 <= *(int *)(&DAT_0068ef50 + local_1c * 4 + local_8 * 0x20);
          local_24 = local_24 + 1) {
        local_10 = local_10 + (int)(0x30 / (longlong)local_24);
      }
    }
    for (local_1c = 0; local_1c < (int)(&DAT_00666408)[local_8]; local_1c = local_1c + 1) {
      if (*(int *)(&DAT_006826c4 + local_1c * 0x120 + local_8 * 0x5b20) != -1) {
        local_14 = *(int *)(&DAT_006826c4 + local_1c * 0x120 + local_8 * 0x5b20);
        if (((&DAT_004ff594)[local_14 * 0x34] & 0x80) == 0) {
          local_2c = 1;
          if (((&DAT_004ff594)[local_14 * 0x34] & 2) != 0) {
            uVar2 = FUN_0048b81a(local_8,local_1c,0x34,0xffffffff);
            uVar3 = FUN_0048b81a(local_8,local_1c,0x32,0xffffffff);
            local_18 = (uVar3 & 0xffffbfff) * 2;
            if ((&DAT_004ff595)[local_14 * 0x34] == '\0') {
              local_18 = 0;
            }
            iVar1 = local_18;
            uVar3 = FUN_0048b81a(local_8,local_1c,0x33,0xffffffff);
            uVar3 = uVar3 & 0xffffbfff;
            local_2c = (int)((iVar1 + 3) * (uVar3 + 4)) / 2;
            if ((((&DAT_006826cc)[local_1c * 0x120 + local_8 * 0x5b20] & 0x10) != 0) &&
               (DAT_00666458 == local_8)) {
              local_2c = local_2c + -1;
            }
            if ((uVar2 & 0x80) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((uVar2 & 0x100) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if (((&DAT_004ff5a8)[local_14 * 0x34] & 3) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((uVar2 & 0x40) != 0) {
              local_2c = (int)((uVar3 + 1) * local_2c) / 2;
            }
            if ((uVar2 & 0x200) != 0) {
              local_2c = (int)(local_2c * 3) / 2;
            }
            if ((((DAT_006c121c == 0) && (local_8 != arg_1)) && (DAT_00666458 == arg_1)) &&
               (((&DAT_006826cc)[local_1c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
              local_e4 = 0;
              uVar2 = FUN_0048b81a(local_8,local_1c,0x34,0xffffffff);
              for (local_24 = 0; local_24 < (int)(&DAT_00666408)[local_28]; local_24 = local_24 + 1)
              {
                iVar4 = FUN_0048b2c9(local_28,local_24,local_8,local_1c,uVar2,local_d4[local_8]);
                if (iVar4 != 0) {
                  local_e4 = 1;
                  iVar4 = FUN_0048b81a(local_28,local_24,0x33,local_1c);
                  if ((iVar1 < iVar4) ||
                     (iVar4 = FUN_0048b81a(local_28,local_24,0x32,local_1c), (int)uVar3 <= iVar4)) {
                    local_e4 = 3;
                    break;
                  }
                }
              }
              if ((local_e4 & 2) == 0) {
                iVar4 = *(int *)(&DAT_00666710 + local_28 * 4) * local_18 * 0x18;
                local_10 = local_10 + ((int)(iVar4 + (iVar4 >> 0x1f & 0xfU)) >> 4);
                if ((local_e4 == 0) && ((int)(&DAT_00681ea8)[local_28] <= iVar1)) {
                  local_10 = local_10 + 0x100;
                }
              }
            }
            if (((&DAT_006826cc)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0) {
              if (*(code **)(&DAT_004ff5a0 + local_14 * 0x34) == FUN_00464774) {
                local_2c = 1;
              }
            }
            else {
              local_2c = local_2c * 3;
            }
            local_2c = (int)(*(int *)(&DAT_00666718 + local_8 * 4) * local_2c +
                            ((int)(*(int *)(&DAT_00666718 + local_8 * 4) * local_2c) >> 0x1f & 7U))
                       >> 3;
          }
          if (((&DAT_004ff594)[local_14 * 0x34] & 1) != 0) {
            if (((&DAT_006826cc)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0) {
              local_2c = 2;
            }
            else {
              bVar5 = ((&DAT_006826cc)[local_1c * 0x120 + local_8 * 0x5b20] & 0x10) == 0;
              if (bVar5) {
                local_2c = 1;
              }
              else {
                local_2c = 0;
              }
              local_2c = (uint)bVar5;
            }
          }
          if (((&DAT_004ff594)[local_14 * 0x34] == '@') &&
             (((&DAT_006826cc)[local_1c * 0x120 + local_8 * 0x5b20] & 2) != 0)) {
            local_2c = (((char)(&DAT_004ff598)[local_14 * 0x34] * 3 + 3) * 4) / 2;
          }
          if (((((&DAT_004ff594)[local_14 * 0x34] == '\x04') &&
               (((&DAT_006826cc)[local_1c * 0x120 + local_8 * 0x5b20] & 2) != 0)) &&
              ((&DAT_006826d2)[local_1c * 0x120 + local_8 * 0x5b20] != -1)) &&
             (*(int *)(&DAT_006826e8 + local_1c * 0x120 + local_8 * 0x5b20) != -1)) {
            local_cc[(char)(&DAT_006826d2)[local_1c * 0x120 + local_8 * 0x5b20] * 0x50 +
                     *(int *)(&DAT_006826e8 + local_1c * 0x120 + local_8 * 0x5b20)] =
                 local_cc[(char)(&DAT_006826d2)[local_1c * 0x120 + local_8 * 0x5b20] * 0x50 +
                          *(int *)(&DAT_006826e8 + local_1c * 0x120 + local_8 * 0x5b20)] |
                 (byte)(1 << ((byte)local_8 & 0x1f));
          }
          if ((((&DAT_004ff594)[local_14 * 0x34] & 0x38) != 0) &&
             (((&DAT_006826cc)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0)) {
            iVar1 = Pic_Subsystem_00452551(local_14);
            local_2c = iVar1 * 0xc;
          }
          if ((((&DAT_004ff594)[local_14 * 0x34] & 4) != 0) &&
             (((&DAT_006826cc)[local_1c * 0x120 + local_8 * 0x5b20] & 2) == 0)) {
            local_2c = 3;
          }
          local_10 = local_10 + local_2c;
          if (((DAT_005ef574 & 2) != 0) && (local_8 + 2U == DAT_005ef574)) {
            FUN_0044a5a4(local_8,local_1c);
            FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f3ca0);
            arg2 = (uint *)__itoa(local_2c,&DAT_005126c8,10);
            FUN_004d9640((uint *)&DAT_005f6810,arg2);
            FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f3ca4);
          }
        }
      }
    }
    (&DAT_0068ecb8)[local_8] = local_10;
    if (local_8 == arg_1) {
      local_c = local_c + local_10;
    }
    else {
      local_c = local_c - local_10;
    }
    local_8 = local_8 + 1;
  } while( true );
}


