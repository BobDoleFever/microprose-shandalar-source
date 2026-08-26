/*
 * Decompiled function: FUN_00409006
 * Entry Point: 00409006
 * Size: 1451 bytes
 */
#include "duel.h"


undefined4 FUN_00409006(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_8;
  
  if (param_3 == 0x74) {
    if ((DAT_00676504 == param_1) && (iVar2 = FUN_0049b309(param_1,7,3), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      if ((DAT_00681eb0._1_1_ & 4) == 0) {
        DAT_00681ea0 = 0;
        FUN_0042b6b0(param_1,1,0xffffffff);
        if (DAT_00681ea4 == 1) {
          return 0;
        }
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00681ea0;
      }
      else {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(undefined4 *)(&DAT_006826e4 + DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20);
      }
      FUN_00434660(s_prompts_txt_004f2670,s_DRAIN_LIFE_004f2664);
      FUN_00461047(param_1,param_2,
                   *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20));
    }
    if (param_3 == 0x71) {
      iVar2 = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      iVar1 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      iVar4 = FUN_004612b0(param_1,param_2,0x71,
                           *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20));
      if ((iVar4 == 0) || (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) < 1)) {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      }
      else {
        if (iVar1 == -1) {
          local_8 = *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
          if ((int)(&DAT_00681ea8)[iVar2] <=
              *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20)) {
            local_8 = (&DAT_00681ea8)[iVar2];
          }
        }
        else {
          iVar4 = FUN_0048b81a(iVar2,iVar1,0x33,0xffffffff);
          if (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) < iVar4) {
            local_8 = *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20);
          }
          else {
            local_8 = FUN_0048b81a(iVar2,iVar1,0x33,0xffffffff);
          }
        }
        if (local_8 < 0) {
          local_8 = 0;
        }
        iVar2 = FUN_004d695b(param_1,DAT_0068eee8);
        if (iVar2 != -1) {
          *(undefined4 *)(&DAT_006826c0 + iVar2 * 0x120 + param_1 * 0x5b20) =
               *(undefined4 *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20);
          *(uint *)(&DAT_006826cc + iVar2 * 0x120 + param_1 * 0x5b20) =
               *(uint *)(&DAT_006826cc + iVar2 * 0x120 + param_1 * 0x5b20) | 2;
          *(undefined4 *)(&DAT_00682704 + iVar2 * 0x120 + param_1 * 0x5b20) = 0x44;
          *(undefined4 *)(&DAT_00682710 + iVar2 * 0x120 + param_1 * 0x5b20) = 0xd7;
          *(int *)(&DAT_006826e4 + iVar2 * 0x120 + param_1 * 0x5b20) = local_8;
          FUN_0048eb25(param_1,iVar2);
          (&DAT_006826d3)[iVar2 * 0x120 + param_1 * 0x5b20] = (undefined1)param_1;
          *(int *)(&DAT_006826ec + iVar2 * 0x120 + param_1 * 0x5b20) = param_2;
        }
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    if (((param_3 == 0x6e) &&
        (*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == DAT_0068f104)) &&
       ((*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == -1 &&
        ((((char)(&DAT_006826d3)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] == param_1 &&
          (*(int *)(&DAT_006826ec + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) == param_2)) &&
         (*(int *)(&DAT_006826e4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) != 0)))))) {
      (&DAT_006826d3)[param_2 * 0x120 + param_1 * 0x5b20] = (undefined1)DAT_0068ecb0;
      *(int *)(&DAT_006826ec + param_2 * 0x120 + param_1 * 0x5b20) = DAT_00690c48;
    }
    uVar3 = 0;
  }
  return uVar3;
}


