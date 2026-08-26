/*
 * Decompiled function: FUN_00463fcd
 * Entry Point: 00463fcd
 * Size: 856 bytes
 */
#include "duel.h"


undefined4 FUN_00463fcd(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) &&
     (*(int *)(&DAT_0068ee80 + param_1 * 4) < 2)) {
    DAT_0068f2d4 = DAT_0068f2d4 + -0xa8;
  }
  if (param_3 == 0x87) {
    iVar1 = FUN_00464325(param_1,param_2);
    if (iVar1 == 0) {
      DAT_0066642c = DAT_0066642c | 1;
    }
  }
  if ((((param_3 == 0x85) && (param_2 == DAT_00690c48)) &&
      ((param_1 == DAT_0068ecb0 &&
       ((*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0 &&
        (param_1 == DAT_00666458)))))) && (DAT_00681eb4 == param_1)) {
    *(uint *)(&DAT_006827d4 + param_2 * 0x120 + param_1 * 0x5b20) =
         *(uint *)(&DAT_006827d4 + param_2 * 0x120 + param_1 * 0x5b20) | 0x101;
    iVar1 = FUN_00464325(param_1,param_2);
    if (iVar1 == 0) {
      DAT_0068f2c0 = DAT_0068f2c0 + 1;
    }
  }
  if (((param_3 == 4) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
         *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) + 1;
    iVar1 = FUN_00464325(param_1,param_2);
    if (iVar1 == 0) {
      DAT_0066642c = DAT_0066642c | 1;
    }
    else {
      *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) | 0x100000;
      FUN_00451482(0,0x20);
      FUN_00434660(s_prompts_txt_004f8d40,s_LORD_OF_THE_PIT_004f8d30);
      uVar2 = FUN_00468383(param_1);
      *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + param_2 * 0x120 + param_1 * 0x5b20) & 0xffefffff;
      FUN_0046e571(param_1,uVar2,3);
    }
  }
  if (param_3 == 0x86) {
    FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,
                 s_Lord_of_the_Pit_deals_7_damage__004f8d4c,0);
    FUN_004afd1c(param_1,7,DAT_00690af0,DAT_0068efa0);
  }
  if (param_3 == 199) {
    iVar1 = FUN_00464325(param_1,param_2);
    if (iVar1 == 0) {
      FUN_004afd1c(param_1,7,DAT_00690af0,DAT_0068efa0);
    }
  }
  if (((param_3 == 0x22) || (param_3 == 199)) &&
     ((param_2 == DAT_00690c48 && (param_1 == DAT_0068ecb0)))) {
    *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
  }
  if (((param_3 == 0x8a) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + -0x30;
  }
  if (((param_3 == 0x8b) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    DAT_0069340c = DAT_0069340c + 0x30;
  }
  return 0;
}


