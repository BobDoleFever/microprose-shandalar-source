/*
 * Decompiled function: FUN_00422b2d
 * Entry Point: 00422b2d
 * Size: 2852 bytes
 */
#include "duel.h"


void FUN_00422b2d(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5)

{
  byte arg_1;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_354 [100];
  int local_1c4;
  int local_1c0;
  undefined4 local_1bc;
  char local_158;
  char local_157;
  undefined1 local_156;
  int local_f4;
  uint local_f0;
  int local_ec;
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
  undefined1 *local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) {
    local_b0 = FUN_004474ec(&local_ac,arg_4,arg_5);
    local_8 = local_b0 >> 0x10;
    local_a0 = local_b0 & 0xffff;
    if (DAT_00666720 == arg_3) {
      uVar1 = FUN_00446ea2(arg_4,arg_5);
      _sprintf(&DAT_0050b180,s_Damage___d_004f3470,uVar1);
      arg_1 = FUN_0044781f(arg_4,arg_5);
      local_b4 = FUN_0048c367(arg_1);
      if (local_b4 == 1) {
        FUN_004d9640((uint *)&DAT_0050b180,(uint *)s__Black__004f347c);
      }
      else if (local_b4 == 2) {
        FUN_004d9640((uint *)&DAT_0050b180,(uint *)s__Blue__004f3488);
      }
      else if (local_b4 == 4) {
        FUN_004d9640((uint *)&DAT_0050b180,(uint *)s__Red__004f3490);
      }
      else if (local_b4 == 3) {
        FUN_004d9640((uint *)&DAT_0050b180,(uint *)s__Green__004f3498);
      }
      else if (local_b4 == 5) {
        FUN_004d9640((uint *)&DAT_0050b180,(uint *)s__White__004f34a4);
      }
    }
    else if (DAT_00666450 == arg_3) {
      iVar2 = FUN_00446ea2(arg_4,arg_5);
      _sprintf(&DAT_0050b180,s_Hunting___s_004f34b0,(&PTR_DAT_004f5500)[iVar2]);
    }
    else if (DAT_00666444 == arg_3) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050b180,*(uint **)(&DAT_005f7914 + local_a0 * 0x14));
    }
    else if (DAT_0066aae8 == arg_3) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050b180,*(uint **)(&DAT_005f791c + local_a0 * 0x14));
    }
    else {
      DAT_0050b180 = 0;
    }
    if ((DAT_00666444 == arg_3) && (iVar2 = FUN_00447968(arg_4,arg_5), 0 < iVar2)) {
      Mem_AllocOrFree_004d9630(local_e8,(uint *)&DAT_0050b180);
      iVar2 = FUN_00447968(arg_4,arg_5);
      FUN_00426b51(&DAT_0050b180,(char *)local_e8,iVar2);
    }
    local_ec = FUN_00447184(local_ac,local_a8);
    if ((local_ec == 0x361) || (local_ec == 0x360)) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050b180,*(uint **)(&DAT_005f7914 + local_ec * 0x14));
    }
    local_98 = &DAT_0050b180;
    local_9c = &DAT_0050b180;
    local_94 = 0xffffffff;
    local_90 = 0xffffffff;
    local_8c = 0;
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
    if (DAT_00666720 == arg_3) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050adf8,*(uint **)(&DAT_005f7910 + local_a0 * 0x14));
    }
    else if (DAT_00666450 == arg_3) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050adf8,*(uint **)(&DAT_005f7918 + local_a0 * 0x14));
    }
    else if (DAT_00666444 == arg_3) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050adf8,*(uint **)(&DAT_005f7918 + local_a0 * 0x14));
    }
    else if (DAT_0066aae8 == arg_3) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_0050adf8,*(uint **)(&DAT_005f7920 + local_a0 * 0x14));
    }
    else {
      DAT_0050adf8 = '\0';
    }
    FUN_00447d7c(arg_4,arg_5,&DAT_0050adf8);
    FUN_00447e83(arg_4,arg_5,&DAT_0050adf8);
    local_1bc._1_1_ = 0;
    local_1bc._0_1_ = -0x12;
    FUN_004718de(&DAT_0050adf8,&DAT_004f34bc,0,(char *)&local_1bc);
    local_1bc._0_1_ = -2;
    FUN_004718de(&DAT_0050adf8,&DAT_004f34c0,0,(char *)&local_1bc);
    local_1bc._0_1_ = -3;
    FUN_004718de(&DAT_0050adf8,&DAT_004f34c4,0,(char *)&local_1bc);
    local_1bc._0_1_ = -5;
    FUN_004718de(&DAT_0050adf8,&DAT_004f34c8,0,(char *)&local_1bc);
    local_1bc._0_1_ = -4;
    FUN_004718de(&DAT_0050adf8,&DAT_004f34cc,0,(char *)&local_1bc);
    local_1bc._0_1_ = -1;
    FUN_004718de(&DAT_0050adf8,&DAT_004f34d0,0,(char *)&local_1bc);
    local_158 = '|';
    local_156 = 0;
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      local_1bc._0_1_ = (char)local_a4 + -0xf;
      local_157 = (char)local_a4 + '0';
      FUN_004718de(&DAT_0050adf8,&local_158,0,(char *)&local_1bc);
    }
    FUN_004479d5(arg_4,arg_5,&local_1c0,&local_f4);
    _sprintf((char *)&local_1bc,s___d___d_004f34d4,local_1c0,local_f4);
    FUN_004718de(&DAT_0050adf8,s___X___X_004f34dc,0,(char *)&local_1bc);
    _sprintf((char *)&local_1bc,s__0___d_004f34e4,local_f4);
    FUN_004718de(&DAT_0050adf8,s__0___X_004f34ec,0,(char *)&local_1bc);
    _sprintf((char *)&local_1bc,s___d__0_004f34f4,local_1c0);
    FUN_004718de(&DAT_0050adf8,s___X__0_004f34fc,0,(char *)&local_1bc);
    if (local_a0 == 0x132) {
      local_f0 = FUN_00446ea2(arg_4,arg_5);
      if (local_f0 == 1) {
        Mem_AllocOrFree_004d9630(&local_1bc,(uint *)s_swampwalk_004f3504);
      }
      else if (local_f0 == 0x10) {
        Mem_AllocOrFree_004d9630(&local_1bc,(uint *)s_plainswalk_004f3510);
      }
      else if (local_f0 == 4) {
        Mem_AllocOrFree_004d9630(&local_1bc,(uint *)s_forestwalk_004f351c);
      }
      else if (local_f0 == 8) {
        Mem_AllocOrFree_004d9630(&local_1bc,(uint *)s_mountainwalk_004f3528);
      }
      else if (local_f0 == 2) {
        Mem_AllocOrFree_004d9630(&local_1bc,(uint *)s_islandwalk_004f3538);
      }
      else {
        Mem_AllocOrFree_004d9630(&local_1bc,(uint *)&DAT_004f3544);
      }
      FUN_004718de(&DAT_0050adf8,&DAT_004f3548,0,(char *)&local_1bc);
    }
    if (local_a0 == 0x21b) {
      local_f0 = FUN_00446ea2(arg_4,arg_5);
      local_1c4 = 0;
      Mem_AllocOrFree_004d9630(&local_1bc,(uint *)&DAT_004f354c);
      if ((local_f0 & 0x20) != 0) {
        if (local_1c4 != 0) {
          FUN_004d9640(&local_1bc,(uint *)s_and_004f3550);
        }
        FUN_004d9640(&local_1bc,(uint *)s_flying_004f3558);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x100) != 0) {
        if (local_1c4 != 0) {
          FUN_004d9640(&local_1bc,(uint *)s_and_004f3560);
        }
        FUN_004d9640(&local_1bc,(uint *)s_first_strike_004f3568);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x40) != 0) {
        if (local_1c4 != 0) {
          FUN_004d9640(&local_1bc,(uint *)s_and_004f3578);
        }
        FUN_004d9640(&local_1bc,(uint *)s_banding_004f3580);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x80) != 0) {
        if (local_1c4 != 0) {
          FUN_004d9640(&local_1bc,(uint *)s_and_004f3588);
        }
        FUN_004d9640(&local_1bc,(uint *)s_trample_004f3590);
        local_1c4 = 1;
      }
      FUN_004718de(&DAT_0050adf8,&DAT_004f3598,0,(char *)&local_1bc);
      FUN_004479d5(arg_4,arg_5,&local_1c0,&local_f4);
      _sprintf((char *)&local_1bc,s___d___d_004f359c,local_1c0,local_f4);
      FUN_004718de(&DAT_0050adf8,s___X___X_004f35a4,0,(char *)&local_1bc);
    }
    if ((DAT_00666444 == arg_3) && (iVar2 = FUN_00447968(arg_4,arg_5), 0 < iVar2)) {
      Mem_AllocOrFree_004d9630(local_354,(uint *)&DAT_0050adf8);
      iVar2 = FUN_00447968(arg_4,arg_5);
      FUN_00426b51(&DAT_0050adf8,(char *)local_354,iVar2);
    }
    if (DAT_00666720 == arg_3) {
      uVar3 = FUN_00448124(arg_4,arg_5);
      if ((DAT_0050adf8 != '\0') && (DAT_0050adf8 != '\n')) {
        FUN_004d9640((uint *)&DAT_0050adf8,(uint *)&DAT_004f35ac);
      }
      if ((uVar3 & 0x100000) != 0) {
        FUN_004d9640((uint *)&DAT_0050adf8,(uint *)s_First_strike_004f35b0);
      }
      if ((uVar3 & 0x80000) != 0) {
        FUN_004d9640((uint *)&DAT_0050adf8,(uint *)s_Trample_004f35c0);
      }
    }
    local_2c = &DAT_0050adf8;
    local_28 = &DAT_004f35c8;
    local_24 = 0;
    local_20 = 0;
    local_44 = 0;
    local_c = 0;
    FUN_0042053a(hdc,arg_2,&local_a0,local_8,2,DAT_00663e10);
  }
  return;
}


