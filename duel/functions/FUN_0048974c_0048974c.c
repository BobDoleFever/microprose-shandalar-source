/*
 * Decompiled function: FUN_0048974c
 * Entry Point: 0048974c
 * Size: 2353 bytes
 */
#include "duel.h"


bool FUN_0048974c(int arg1,int arg2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  bool bVar4;
  uint local_28;
  int local_24;
  int local_20;
  uint local_18;
  uint local_14;
  int local_c;
  
  local_c = arg1;
  if (DAT_0068f2c4 == 4) {
    local_c = DAT_00681eb4;
  }
  if ((local_c != DAT_00676510) && (DAT_0066aaf4 != 1)) {
    FUN_0048c907(arg1,arg2,0x90,1 - arg1,0xffffffff);
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)&DAT_00666500);
    FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_activates____004faff0);
    iVar2 = FUN_0048f067(arg1,arg2);
    if (iVar2 == 0) {
      if (((((&DAT_004ff5a8)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x18)
            != 0) && (DAT_00666458 == arg1)) && (DAT_00666410 != 0)) {
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s__with_004fb00c);
        puVar3 = (uint *)__itoa(DAT_00666410,&DAT_005dadf8,10);
        FUN_004d9640((uint *)&DAT_005f6810,puVar3);
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_mana___004fb014);
      }
    }
    else {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_X_is_004fb000);
      puVar3 = (uint *)__itoa(DAT_00666410,&DAT_005dadf8,10);
      FUN_004d9640((uint *)&DAT_005f6810,puVar3);
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004fb008);
    }
    if ((&DAT_006827b8)[arg2 * 0x120 + arg1 * 0x5b20] == '\0') {
      if (DAT_0068f0bc == 0xffffffff) {
        FUN_00446c16(arg1,arg2,-1,-1,&DAT_005f6810,0);
      }
      else {
        FUN_00446c16(arg1,arg2,(int)DAT_0068f0bc >> 8,DAT_0068f0bc & 0xff,&DAT_005f6810,0);
      }
    }
    else if ((&DAT_006827b8)[arg2 * 0x120 + arg1 * 0x5b20] == '\x01') {
      FUN_00446c16(arg1,arg2,*(int *)(&DAT_00682718 + arg2 * 0x120 + arg1 * 0x5b20),
                   *(int *)(&DAT_0068271c + arg2 * 0x120 + arg1 * 0x5b20),&DAT_005f6810,0);
    }
    else {
      FUN_00446c16(arg1,arg2,-1,-1,&DAT_005f6810,0);
    }
  }
  FUN_0048d878(arg1,arg2,0x72,arg1,0);
  DAT_006664ec = 0;
  if (((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 1) == 0) {
    if ((((&DAT_006827d4)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) &&
       (iVar2 = FUN_0048ed18(arg1,arg2), iVar2 != 0)) {
      for (local_24 = 0; local_24 < 7; local_24 = local_24 + 1) {
        (&DAT_0068ece0)[local_24] =
             (int)(char)(&DAT_006827cc)[local_24 + arg1 * 0x5b20 + arg2 * 0x120];
      }
      Ai_CalcManaRequirement_004ba890(arg1,0,0);
      if ((DAT_00681ea4 == 0) && (FUN_0048c907(arg1,arg2,1,1 - arg1,0xffffffff), DAT_0068edd8 == 0))
      {
        *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) =
             *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) | 0x40;
      }
      if (DAT_00681ea4 != 0) {
        DAT_00681ea4 = 0;
        FUN_0048e251();
        return false;
      }
      *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) =
           *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffffef;
      *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) =
           *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) | 0x80;
      FUN_0048d41e(1);
      return true;
    }
    iVar2 = FUN_0048c50b(arg1,arg2,0x80);
    if (iVar2 == 0) {
      if (((&DAT_004ff5a9)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x10) !=
          0) {
        DAT_0068f0f4 = -1;
      }
      FUN_0042e00f();
      uVar1 = *(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20);
      FUN_0048c907(arg1,arg2,0x6d,1 - arg1,0xffffffff);
      bVar4 = DAT_00681ea4 == 1;
      if (bVar4) {
        FUN_0042e101(arg1);
        FUN_0048e251();
      }
      bVar4 = !bVar4;
      Mem_AllocOrFree_0042e0cd();
      if (bVar4) {
        if (((uVar1 & 0x10) == 0) && (((&DAT_006826cc)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0))
        {
          FUN_0048c50b(arg1,arg2,0x81);
        }
        if (*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) == -1) {
          local_28 = *(uint *)(&DAT_004ff5a8 +
                              *(int *)(&DAT_006826c0 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34);
        }
        else {
          local_28 = *(uint *)(&DAT_004ff5a8 +
                              *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34);
        }
        local_28 = local_28 & 0x1000;
        if ((local_28 == 0) || (DAT_0068f0f4 == -1)) {
          FUN_0048d41e(1);
        }
        else {
          FUN_0048d41e(0);
        }
        if (DAT_0066aaf4 != 1) {
          if ((((&DAT_004ff5a9)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] &
               0x10) == 0) || (DAT_0068f0f4 == -1)) {
            FUN_0048d00c(0x1c);
          }
          else {
            FUN_0048d00c(0x12);
          }
        }
        if (DAT_0066aaf4 != 1) {
          FUN_0048dc9e();
        }
      }
    }
    else {
      FUN_0048e251();
      bVar4 = false;
    }
    if (bVar4 != false) {
      return bVar4;
    }
    DAT_006664ec = 0;
    return false;
  }
  bVar4 = true;
  local_20 = 0;
  for (local_18 = 0; (int)local_18 < 7; local_18 = local_18 + 1) {
    (&DAT_0068ece0)[local_18] = (int)(char)(&DAT_006827d8)[arg2 * 0x120 + arg1 * 0x5b20 + local_18];
    if ((0 < (int)local_18) &&
       (iVar2 = FUN_0049b309(arg1,local_18,(&DAT_0068ece0)[local_18]), iVar2 == 0)) {
      bVar4 = false;
    }
    local_20 = local_20 + (&DAT_0068ece0)[local_18];
  }
  iVar2 = FUN_0049b309(local_c,7,local_20);
  if (iVar2 == 0) {
    bVar4 = false;
  }
  local_14 = (uint)!bVar4;
  if ((((&DAT_006827d5)[arg2 * 0x120 + arg1 * 0x5b20] & 1) != 0) ||
     (iVar2 = Ai_Subsystem_004cc56d
                        (local_c,arg1,arg2,-1,-1,s_Pay_Upkeep_costs__Don_t_pay_Upke_004fb01c,
                         local_14), iVar2 == 0)) {
    if (!bVar4) goto LAB_00489c02;
    Ai_CalcManaRequirement_004ba890(local_c,0,0);
    if ((DAT_00681ea4 == 0) && (FUN_0048c907(arg1,arg2,4,1 - arg1,0xffffffff), DAT_0068edd8 == 0)) {
      *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) =
           *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) | 0x200;
    }
  }
  if (DAT_00681ea4 != 0) {
    DAT_00681ea4 = 0;
    FUN_0048e251();
    return false;
  }
LAB_00489c02:
  for (local_18 = 0; (int)local_18 < 7; local_18 = local_18 + 1) {
    (&DAT_0068ece0)[local_18] = 0;
  }
  *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) =
       *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffffffe;
  *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) =
       *(uint *)(&DAT_006827d4 + arg2 * 0x120 + arg1 * 0x5b20) | 8;
  FUN_0048d41e(1);
  return true;
}


