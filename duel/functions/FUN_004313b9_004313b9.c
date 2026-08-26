/*
 * Decompiled function: FUN_004313b9
 * Entry Point: 004313b9
 * Size: 2380 bytes
 */
#include "duel.h"


int FUN_004313b9(int arg1,int arg2)

{
  int x;
  int iVar1;
  int iVar2;
  int iVar3;
  int local_1c0;
  int local_1bc;
  uint local_1b8;
  int local_1b4;
  int local_1b0;
  uint local_1a8;
  int local_1a4;
  int local_1a0;
  int local_19c;
  uint local_198;
  int aiStack_194 [16];
  int aiStack_154 [24];
  int local_f4;
  int aiStack_f0 [16];
  int local_b0;
  char acStack_ac [80];
  int local_5c;
  int aiStack_58 [16];
  int local_18;
  int local_14;
  int local_10;
  char acStack_c [8];
  
  x = 1 - arg1;
  FUN_00431f41(&local_1a8,(uint *)0x0);
  for (local_1a0 = 0; local_1a0 < 8; local_1a0 = local_1a0 + 1) {
    acStack_c[local_1a0] = (&DAT_0068ed10)[local_1a0 * 4 + x * 0x20];
    *(undefined4 *)(&DAT_0068ed10 + local_1a0 * 4 + x * 0x20) =
         *(undefined4 *)(&DAT_0068ef50 + local_1a0 * 4 + x * 0x20);
  }
  for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
    aiStack_154[local_14 * 3 + 1] = -1;
  }
  local_10 = 0;
  for (local_1b0 = 0; local_1b0 < (int)(&DAT_00666408)[arg1]; local_1b0 = local_1b0 + 1) {
    if (((*(int *)(&DAT_006826c4 + local_1b0 * 0x120 + arg1 * 0x5b20) != -1) &&
        ((*(uint *)(&DAT_006826cc + local_1b0 * 0x120 + arg1 * 0x5b20) & 0x402) != 0)) &&
       (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_1b0 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) !=
        0)) {
      acStack_ac[local_1b0] = (char)local_10;
      iVar1 = FUN_0048b81a(arg1,local_1b0,0x32,0xffffffff);
      aiStack_f0[local_10] = iVar1;
      iVar1 = FUN_0048b81a(arg1,local_1b0,0x33,0xffffffff);
      aiStack_194[local_10] = iVar1;
      aiStack_58[local_10] = *(int *)(&DAT_00682700 + local_1b0 * 0x120 + arg1 * 0x5b20);
      local_10 = local_10 + 1;
    }
  }
  for (local_1a0 = 0; local_1a0 < (int)(&DAT_00666408)[x]; local_1a0 = local_1a0 + 1) {
    local_19c = *(int *)(&DAT_006826c4 + local_1a0 * 0x120 + x * 0x5b20);
    if (((local_19c != -1) && (((&DAT_004ff594)[local_19c * 0x34] & 2) != 0)) &&
       ((((&DAT_006826cc)[local_1a0 * 0x120 + x * 0x5b20] & 2) != 0 &&
        (((&DAT_004ff595)[local_19c * 0x34] != '\0' ||
         (((&DAT_006826f9)[local_1a0 * 0x120 + x * 0x5b20] & 8) != 0)))))) {
      local_1c0 = FUN_0048b81a(x,local_1a0,0x32,0xffffffff);
      local_1bc = FUN_0048b81a(x,local_1a0,0x33,0xffffffff);
      if (DAT_00676510 == x) {
        if (((&DAT_004ff5a8)[local_19c * 0x34] & 8) != 0) {
          iVar1 = (**(code **)(&DAT_004ff5a0 + local_19c * 0x34))(x,local_1a0,0x39);
          local_1c0 = local_1c0 + iVar1;
        }
        if (((&DAT_004ff5a8)[local_19c * 0x34] & 0x10) != 0) {
          iVar1 = (**(code **)(&DAT_004ff5a0 + local_19c * 0x34))(x,local_1a0,0x3a);
          local_1bc = local_1bc + iVar1;
        }
      }
      local_1b0 = 0;
LAB_004317d2:
      if (local_1b0 < 8) {
        if (local_1c0 <= aiStack_154[local_1b0 * 3 + 1]) goto LAB_004317cc;
        for (local_14 = 7; local_1b0 < local_14; local_14 = local_14 + -1) {
          aiStack_154[local_14 * 3] = aiStack_154[local_14 * 3 + -3];
          aiStack_154[local_14 * 3 + 1] = aiStack_154[local_14 * 3 + -2];
          aiStack_154[local_14 * 3 + 2] = aiStack_154[local_14 * 3 + -1];
        }
        aiStack_154[local_1b0 * 3] = local_1a0;
        aiStack_154[local_1b0 * 3 + 1] = local_1c0;
        aiStack_154[local_1b0 * 3 + 2] = local_1bc;
      }
    }
  }
  local_1a4 = 0;
  local_14 = 0;
  do {
    if ((7 < local_14) || (aiStack_154[local_14 * 3 + 1] == -1)) {
      if (((int)(&DAT_00681ea8)[arg1] <= local_1a4) && (0 < (int)(&DAT_00681ea8)[x])) {
        arg2 = arg2 + -0x100;
      }
      for (local_1a0 = 0; local_1a0 < 8; local_1a0 = local_1a0 + 1) {
        *(int *)(&DAT_0068ed10 + local_1a0 * 4 + x * 0x20) = (int)acStack_c[local_1a0];
      }
      return arg2;
    }
    local_1a0 = aiStack_154[local_14 * 3];
    local_198 = FUN_0048b81a(x,local_1a0,0x34,0xffffffff);
    iVar1 = aiStack_154[local_14 * 3 + 1];
    iVar3 = aiStack_154[local_14 * 3 + 2];
    local_1b4 = 0;
    local_1b8 = 0;
    local_f4 = 0;
    local_5c = 0x7fff;
    for (local_1b0 = 0; local_1b0 < (int)(&DAT_00666408)[arg1]; local_1b0 = local_1b0 + 1) {
      if (((*(int *)(&DAT_006826c4 + local_1b0 * 0x120 + arg1 * 0x5b20) != -1) &&
          (((&DAT_006826cc)[local_1b0 * 0x120 + arg1 * 0x5b20] & 2) != 0)) &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_1b0 * 0x120 + arg1 * 0x5b20) * 0x34] & 2)
          != 0)) {
        local_f4 = (int)acStack_ac[local_1b0];
        local_18 = aiStack_f0[local_f4];
        local_b0 = aiStack_194[local_f4];
        iVar2 = FUN_0048af80(arg1,local_1b0);
        if (((*(uint *)(&DAT_006826cc + local_1b0 * 0x120 + arg1 * 0x5b20) &
             (-(uint)(iVar2 == 0) & 4) + 8) == 0) &&
           (iVar2 = FUN_0048b2c9(arg1,local_1b0,x,local_1a0,local_198,local_1a8), iVar2 != 0)) {
          local_1b8 = 1;
          if ((iVar1 < local_b0) || (iVar3 <= local_18)) {
            local_1b8 = 3;
            *(uint *)(&DAT_006826cc + local_1b0 * 0x120 + arg1 * 0x5b20) =
                 *(uint *)(&DAT_006826cc + local_1b0 * 0x120 + arg1 * 0x5b20) | 8;
            break;
          }
          if (aiStack_58[local_f4] < local_5c) {
            local_5c = aiStack_58[local_f4];
            local_1b4 = local_1b0;
          }
        }
      }
    }
    if ((local_1b8 & 2) == 0) {
      iVar3 = *(int *)(&DAT_00666710 + arg1 * 4) * iVar1 * 0x18;
      iVar3 = iVar3 + (iVar3 >> 0x1f & 3U);
      iVar2 = FUN_0049aa14((&DAT_00681ea8)[arg1] + 1,1,99);
      iVar3 = (int)(CONCAT44(iVar3 >> 0x1f,iVar3 >> 2) / (longlong)iVar2);
      iVar2 = (int)(*(int *)(&DAT_00666718 + arg1 * 4) * local_5c +
                   (*(int *)(&DAT_00666718 + arg1 * 4) * local_5c >> 0x1f & 0xfU)) >> 4;
      if ((local_1b8 == 0) || ((iVar3 < iVar2 && (iVar1 + local_1a4 < (int)(&DAT_00681ea8)[arg1]))))
      {
        local_1a4 = local_1a4 + iVar1;
        arg2 = arg2 - iVar3;
      }
      else {
        arg2 = arg2 - iVar2;
        *(uint *)(&DAT_006826cc + local_1b4 * 0x120 + arg1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + local_1b4 * 0x120 + arg1 * 0x5b20) | 8;
      }
    }
    local_14 = local_14 + 1;
  } while( true );
LAB_004317cc:
  local_1b0 = local_1b0 + 1;
  goto LAB_004317d2;
}


