/*
 * Decompiled function: FUN_0042e217
 * Entry Point: 0042e217
 * Size: 2683 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0042e217(int arg_1,uint arg_2,int arg_3)

{
  int iVar1;
  uint uVar2;
  uint *arg2;
  int local_34;
  uint local_30;
  int local_24;
  uint local_20;
  int local_10;
  byte local_8;
  
  DAT_00666748 = arg_2;
LAB_0042e228:
  while( true ) {
    if (0 < *(int *)(&DAT_0068f2e0 + arg_2 * 4 + arg_1 * 0x20)) {
      FUN_0049b277(arg_1,arg_2,1);
      DAT_00666748 = 0xffffffff;
      return 1;
    }
    local_24 = 0;
    while ((local_24 < 10 && (*(int *)(&DAT_00666900 + local_24 * 4 + arg_1 * 0x2c) != -1))) {
      if ((0 < *(int *)(&DAT_0068f2e0 +
                       (uint)*(ushort *)(&DAT_00666900 + local_24 * 4 + arg_1 * 0x2c) * 4 +
                       arg_1 * 0x20)) &&
         (arg_2 == *(uint *)(&DAT_00666900 + local_24 * 4 + arg_1 * 0x2c) >> 0x10)) {
        FUN_0049b277(arg_1,(uint)*(ushort *)(&DAT_00666900 + local_24 * 4 + arg_1 * 0x2c),1);
        DAT_00666748 = 0xffffffff;
        return 1;
      }
      local_24 = local_24 + 1;
    }
    if (arg_2 == 6) {
      for (local_20 = 0; (int)local_20 < 7; local_20 = local_20 + 1) {
        if (*(int *)(&DAT_0068f2e0 + local_20 * 4 + arg_1 * 0x20) != 0) {
          FUN_0049b277(arg_1,local_10,1);
          DAT_00666748 = 0xffffffff;
          return 1;
        }
      }
    }
    if (arg_2 == 0) {
      for (local_20 = 0; (int)local_20 < 7; local_20 = local_20 + 1) {
        if ((local_20 != 6) && (*(int *)(&DAT_0068f2e0 + local_20 * 4 + arg_1 * 0x20) != 0)) {
          FUN_0049b277(arg_1,local_10,1);
          DAT_00666748 = 0xffffffff;
          return 1;
        }
      }
    }
    if ((((arg_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0066643c == 0)) &&
       (DAT_0068f0b0 == 0)) break;
    if (arg_2 == 0) {
      local_10 = -1;
      for (local_20 = 1; (int)local_20 < 7; local_20 = local_20 + 1) {
        iVar1 = FUN_0049b309(arg_1,local_20,1);
        if (iVar1 != 0) {
          iVar1 = FUN_0049b309(arg_1,local_20,1);
          iVar1 = (iVar1 << 5) / (*(int *)(&DAT_0068f320 + local_20 * 4 + arg_1 * 0x20) * 2 + 1);
          if (local_10 < iVar1) {
            arg_2 = local_20;
            DAT_00666748 = local_20;
            local_10 = iVar1;
          }
        }
      }
    }
    local_30 = 0;
    local_24 = 0;
    while ((local_24 < 10 && (*(int *)(&DAT_00666900 + local_24 * 4 + arg_1 * 0x2c) != -1))) {
      if (arg_2 == *(uint *)(&DAT_00666900 + local_24 * 4 + arg_1 * 0x2c) >> 0x10) {
        local_8 = (byte)*(undefined2 *)(&DAT_00666900 + local_24 * 4 + arg_1 * 0x2c);
        local_30 = local_30 | 1 << (local_8 & 0x1f);
      }
      local_24 = local_24 + 1;
    }
    local_20 = 0;
    while( true ) {
      if ((int)(&DAT_00666408)[arg_1] <= (int)local_20) {
        DAT_00666748 = 0xffffffff;
        return 0;
      }
      if (((((((&DAT_006826cc)[arg_1 * 0x5b20 + local_20 * 0x120] & 2) != 0) &&
            (((&DAT_006826cc)[arg_1 * 0x5b20 + local_20 * 0x120] & 0x10) == 0)) &&
           (iVar1 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_20 * 0x120), iVar1 != -1)) &&
          ((((&DAT_004ff594)[iVar1 * 0x34] & 1) != 0 &&
           (uVar2 = (uint)(char)(&DAT_006826dc)[arg_1 * 0x5b20 + local_20 * 0x120], uVar2 != 0))))
         && ((((uVar2 & 1 << ((byte)arg_2 & 0x1f)) != 0 ||
              (((local_30 & uVar2) != 0 || (arg_2 == 0)))) || (arg_2 == 6)))) break;
      local_20 = local_20 + 1;
    }
    FUN_0048d878(arg_1,local_20,0x72,arg_1,0);
    DAT_0068f220 = 1;
    DAT_0068f0f4 = 0xffffffff;
    uVar2 = *(uint *)(&DAT_006826cc + local_34 * 0x120 + arg_1 * 0x5b20);
    _DAT_0068ecc8 = iVar1;
    FUN_0048c907(arg_1,local_20,0x6d,1 - arg_1,0xffffffff);
    DAT_0068f220 = 0;
    if (DAT_00681ea4 == 1) {
      DAT_00681ea4 = 0;
      FUN_0048e251();
    }
    else {
      if (((uVar2 & 0x10) == 0) &&
         (((&DAT_006826cc)[local_34 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
        FUN_0048c50b(arg_1,local_20,0x81);
      }
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x12);
      }
      FUN_0048dd43();
    }
    _DAT_0068ecc8 = 0xffffffff;
  }
  do {
    switch(arg_2) {
    case 0:
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Tap_any_land__004f3c48);
      break;
    case 1:
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Tap_a_swamp__004f3bf8);
      break;
    case 2:
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Tap_an_island__004f3c08);
      break;
    case 3:
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Tap_a_forest__004f3c18);
      break;
    case 4:
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Tap_a_mountain__004f3c28);
      break;
    case 5:
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Tap_a_plains__004f3c38);
    }
    if (arg_3 == 0) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s__or_none__X_is_004f3c58);
      arg2 = (uint *)__itoa(DAT_00681ea0,&DAT_0050b368,10);
      FUN_004d9640((uint *)&DAT_005f6810,arg2);
    }
    local_34 = Action_PromptTarget_004b2bd0(arg_1,arg_1,arg_1,0,0,0x5f6810,1);
    if (((local_34 != -1) && (((&DAT_006826cc)[local_34 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) &&
       (((&DAT_006826cc)[local_34 * 0x120 + arg_1 * 0x5b20] & 0x14) == 0)) {
      if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_34 * 0x120 + arg_1 * 0x5b20) * 0x34] & 1)
          == 0) {
        if ((((&DAT_004ff5a9)[*(int *)(&DAT_006826c4 + local_34 * 0x120 + arg_1 * 0x5b20) * 0x34] &
             0x10) != 0) &&
           (iVar1 = FUN_0048c907(arg_1,local_34,0x73,1 - arg_1,0xffffffff), iVar1 != 0)) break;
      }
      else if (((int)(char)(&DAT_006826dc)[local_34 * 0x120 + arg_1 * 0x5b20] != 0) &&
              ((((int)(char)(&DAT_006826dc)[local_34 * 0x120 + arg_1 * 0x5b20] &
                1 << ((byte)arg_2 & 0x1f)) != 0 || (arg_2 == 0)))) {
        FUN_0048d878(arg_1,local_20,0x72,arg_1,0);
        _DAT_0068ecc8 = *(int *)(&DAT_006826c4 + local_34 * 0x120 + arg_1 * 0x5b20);
        DAT_0068f220 = 1;
        DAT_0068f0f4 = 0xffffffff;
        uVar2 = *(uint *)(&DAT_006826cc + local_34 * 0x120 + arg_1 * 0x5b20);
        FUN_0048c907(arg_1,local_34,0x6d,1 - arg_1,0xffffffff);
        DAT_0068f220 = 0;
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = 0;
          FUN_0048e251();
        }
        else {
          if (((uVar2 & 0x10) == 0) &&
             (((&DAT_006826cc)[local_34 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
            FUN_0048c50b(arg_1,local_34,0x81);
          }
          if (DAT_0066aaf4 != 1) {
            FUN_0048d00c(0x12);
          }
          FUN_0048dd43();
          FUN_00451482(0,0xff);
        }
        _DAT_0068ecc8 = 0xffffffff;
        goto LAB_0042e228;
      }
    }
    if (arg_3 == 0) {
      FUN_00451482(0,0xff);
      DAT_00666748 = 0xffffffff;
      return 0;
    }
  } while( true );
  FUN_0048d878(arg_1,local_20,0x72,arg_1,0);
  _DAT_0068ecc8 = *(int *)(&DAT_006826c4 + local_34 * 0x120 + arg_1 * 0x5b20);
  DAT_0068f220 = 1;
  DAT_0068f0f4 = 0xffffffff;
  uVar2 = *(uint *)(&DAT_006826cc + local_34 * 0x120 + arg_1 * 0x5b20);
  FUN_0048c907(arg_1,local_34,0x6d,1 - arg_1,0xffffffff);
  DAT_0068f220 = 0;
  if (DAT_00681ea4 == 1) {
    DAT_00681ea4 = 0;
    FUN_0048e251();
  }
  else {
    if (((uVar2 & 0x10) == 0) && (((&DAT_006826cc)[local_34 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0))
    {
      FUN_0048c50b(arg_1,local_34,0x81);
    }
    if (DAT_0066aaf4 != 1) {
      FUN_0048d00c(0x12);
    }
    FUN_0048dd43();
    FUN_00451482(0,0xff);
  }
  _DAT_0068ecc8 = 0xffffffff;
  goto LAB_0042e228;
}


