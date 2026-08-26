/*
 * Decompiled function: FUN_004252e0
 * Entry Point: 004252e0
 * Size: 1533 bytes
 */
#include "duel.h"


void FUN_004252e0(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5)

{
  byte arg_1;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_f4;
  uint local_e8 [13];
  int local_b4;
  uint local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  uint local_a0;
  undefined *local_9c;
  undefined *local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [10];
  undefined1 auStack_6e [10];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_44;
  undefined4 auStack_40 [4];
  undefined4 local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) {
    local_b0 = FUN_004474ec(&local_ac,arg_4,arg_5);
    local_8 = local_b0 >> 0x10;
    local_a0 = local_b0 & 0xffff;
    if (arg_3 == DAT_00666720) {
      uVar1 = FUN_00446ea2(arg_4,arg_5);
      _sprintf(&DAT_0050abe8,s_Damage___d_004f361c,uVar1);
      arg_1 = FUN_0044781f(arg_4,arg_5);
      local_b4 = FUN_0048c367(arg_1);
      if (local_b4 == 1) {
        FUN_004d9640((uint *)&DAT_0050abe8,(uint *)s__Black__004f3628);
      }
      else if (local_b4 == 2) {
        FUN_004d9640((uint *)&DAT_0050abe8,(uint *)s__Blue__004f3634);
      }
      else if (local_b4 == 4) {
        FUN_004d9640((uint *)&DAT_0050abe8,(uint *)s__Red__004f363c);
      }
      else if (local_b4 == 3) {
        FUN_004d9640((uint *)&DAT_0050abe8,(uint *)s__Green__004f3644);
      }
      else if (local_b4 == 5) {
        FUN_004d9640((uint *)&DAT_0050abe8,(uint *)s__White__004f3650);
      }
    }
    else if (arg_3 == DAT_00666450) {
      iVar2 = FUN_00446ea2(arg_4,arg_5);
      _sprintf(&DAT_0050abe8,s_Hunting___s_004f365c,(&PTR_DAT_004f5500)[iVar2]);
    }
    else if (arg_3 == DAT_00666444) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050abe8,*(uint **)(&DAT_005f7914 + local_a0 * 0x14));
    }
    else if (arg_3 == DAT_0066aae8) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050abe8,*(uint **)(&DAT_005f791c + local_a0 * 0x14));
    }
    else if (arg_3 == DAT_0068f0fc) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050abe8,(uint *)s_Activation_004f3668);
    }
    else {
      DAT_0050abe8 = 0;
    }
    if ((arg_3 == DAT_00666444) && (iVar2 = FUN_00447968(arg_4,arg_5), 0 < iVar2)) {
      Mem_AllocOrFree_004d9630(local_e8,(uint *)&DAT_0050abe8);
      iVar2 = FUN_00447968(arg_4,arg_5);
      FUN_00426b51(&DAT_0050abe8,(char *)local_e8,iVar2);
    }
    iVar2 = FUN_00447184(local_ac,local_a8);
    if ((iVar2 == 0x361) || (iVar2 == 0x360)) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050abe8,*(uint **)(&DAT_005f7914 + iVar2 * 0x14));
    }
    local_98 = &DAT_0050abe8;
    local_9c = &DAT_0050abe8;
    local_94 = 0xffffffff;
    local_90 = 0xffffffff;
    local_8c = 0xffffffff;
    local_88 = 0xffffffff;
    local_84 = 0xffffffff;
    local_80 = 0xffffffff;
    local_7c = 0;
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      auStack_78[local_a4] = 0;
    }
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      auStack_6e[local_a4] = 0;
    }
    local_64 = 0xffffffff;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0xffffffff;
    for (local_a4 = 0; local_a4 < 4; local_a4 = local_a4 + 1) {
      auStack_40[local_a4] = 0;
    }
    local_30 = 0xffffffff;
    if (arg_3 == DAT_00666720) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050ac38,*(uint **)(&DAT_005f7910 + local_a0 * 0x14));
    }
    else if (arg_3 == DAT_00666450) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050ac38,*(uint **)(&DAT_005f7918 + local_a0 * 0x14));
    }
    else if (arg_3 == DAT_00666444) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050ac38,*(uint **)(&DAT_005f7918 + local_a0 * 0x14));
    }
    else if (arg_3 == DAT_0066aae8) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050ac38,*(uint **)(&DAT_005f7920 + local_a0 * 0x14));
    }
    else {
      DAT_0050ac38 = 0;
    }
    local_2c = &DAT_0050ac38;
    local_28 = &DAT_004f3674;
    local_24 = 0;
    local_20 = 0;
    local_44 = 0;
    local_c = 0;
    FUN_00423651(hdc,arg_2,&local_a0,local_8,1);
    FUN_00426181(hdc,arg_2,arg_4,arg_5);
    iVar2 = FUN_00447a88(arg_4,arg_5);
    uVar3 = (uint)(iVar2 == arg_4);
    iVar2 = FUN_00447c07(arg_4,arg_5);
    FUN_00424f7b(hdc,arg_2,(int)local_98,iVar2,uVar3);
    if (arg_3 == DAT_00666720) {
      uVar3 = FUN_00448124(arg_4,arg_5);
      local_f4 = 0;
      if ((uVar3 & 0x100000) != 0) {
        local_f4 = 0x100;
      }
      if ((uVar3 & 0x80000) != 0) {
        local_f4 = local_f4 | 0x80;
      }
      if ((DAT_00663e0c != 0) && (local_f4 != 0)) {
        FUN_00424a81(hdc,arg_2,local_f4);
      }
    }
  }
  return;
}


