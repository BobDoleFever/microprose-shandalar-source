/*
 * Decompiled function: FUN_00401900
 * Entry Point: 00401900
 * Size: 936 bytes
 */
#include "duel.h"


undefined4 FUN_00401900(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_110;
  int local_108;
  undefined1 local_104 [252];
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (param_3 == 0x71) {
      FUN_00434660(s_prompts_txt_004f2040,s_BALANCE_004f2038);
      FUN_004d9630(local_104,&DAT_006679f0);
      do {
        FUN_004d9630(&DAT_006679f0,local_104);
        local_110 = 0;
        local_108 = 0;
        local_8 = 0;
        while( true ) {
          iVar2 = DAT_00666408;
          if (DAT_00666408 <= DAT_0066640c) {
            iVar2 = DAT_0066640c;
          }
          if (iVar2 <= local_8) break;
          iVar2 = FUN_0048a33f(0,local_8);
          if ((iVar2 != 0) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x120) * 0x34] & 1) != 0)) {
            local_108 = local_108 + 1;
          }
          iVar2 = FUN_0048a33f(1,local_8);
          if ((iVar2 != 0) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006881e4 + local_8 * 0x120) * 0x34] & 1) != 0)) {
            local_110 = local_110 + 1;
          }
          local_8 = local_8 + 1;
        }
        if (local_110 < local_108) {
          FUN_004687a3(0);
        }
        else if (local_108 < local_110) {
          FUN_004687a3(1);
        }
        FUN_00451482(0,0xff);
      } while (local_110 != local_108);
      do {
        if (DAT_0068ee7c < DAT_0068ee78) {
          FUN_00488150(0,0,0);
        }
        if (DAT_0068ee78 < DAT_0068ee7c) {
          FUN_00488150(1,0,0);
        }
      } while (DAT_0068ee78 != DAT_0068ee7c);
      do {
        local_110 = 0;
        local_108 = 0;
        local_8 = 0;
        while( true ) {
          iVar2 = DAT_00666408;
          if (DAT_00666408 <= DAT_0066640c) {
            iVar2 = DAT_0066640c;
          }
          if (iVar2 <= local_8) break;
          iVar2 = FUN_0048a33f(0,local_8);
          if (((iVar2 != 0) &&
              (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x120) * 0x34] & 2) != 0)) &&
             ((&DAT_006826e0)[local_8 * 0x120] != '\x03')) {
            local_108 = local_108 + 1;
          }
          iVar2 = FUN_0048a33f(1,local_8);
          if (((iVar2 != 0) &&
              (((&DAT_004ff594)[*(int *)(&DAT_006881e4 + local_8 * 0x120) * 0x34] & 2) != 0)) &&
             ((&DAT_006826e0)[local_8 * 0x120] != '\x03')) {
            local_110 = local_110 + 1;
          }
          local_8 = local_8 + 1;
        }
        FUN_004d9630(&DAT_006679f0,&DAT_00667aea);
        if (local_110 < local_108) {
          uVar1 = FUN_00468383(0);
          FUN_0046e571(0,uVar1,3);
        }
        if (local_108 < local_110) {
          uVar1 = FUN_00468383(1);
          FUN_0046e571(1,uVar1,3);
        }
        FUN_00451482(0,0xff);
      } while (local_110 != local_108);
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


