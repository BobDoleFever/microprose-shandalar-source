/*
 * Decompiled function: Glue_Subsystem_004e2c7f
 * Entry Point: 0046440b
 * Size: 873 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Glue_Subsystem_004e2c7f(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       (((*(uint *)(&DAT_0066aad0 + (1 - arg_1) * 4) | _DAT_0066aad0) & 1) != 0)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) &&
       ((*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0)) {
      if (local_c == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
      }
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      FUN_0046e571((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                   *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20),2);
      *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&DAT_006826e8)[arg_2 * 0x120 + arg_1 * 0x5b20];
    }
    if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) {
      bVar1 = false;
      iVar3 = FUN_0049b309(arg_1,1,3);
      if ((iVar3 != 0) &&
         (iVar3 = Ai_Subsystem_004cc56d
                            (arg_1,arg_1,arg_2,-1,-1,s_Pay_mana__Sacrifice_Land__004f8d6c,0),
         iVar3 == 0)) {
        Ai_CalcManaRequirement_004ba890(arg_1,1,3);
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = -1;
        }
        else {
          bVar1 = true;
        }
      }
      if ((arg_3 == 199) && (iVar3 = FUN_0049b309(arg_1,1,3), iVar3 != 0)) {
        bVar1 = true;
      }
      if ((!bVar1) && (iVar3 = FUN_00467cce(arg_1,1), iVar3 != 0)) {
        do {
        } while (local_c == -1);
        FUN_0046e571(DAT_0068eef0,local_c,3);
        *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


