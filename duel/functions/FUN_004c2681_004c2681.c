/*
 * Decompiled function: FUN_004c2681
 * Entry Point: 004c2681
 * Size: 1562 bytes
 */
#include "duel.h"


undefined4 FUN_004c2681(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,4,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_005089f8,s_POWERLEAK_005089ec);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_18);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,4,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_14;
        *(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_18;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,4,0,0,uVar1);
      if (iVar2 == 0) {
        FUN_0046e571(param_1,param_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] =
             (&DAT_00682718)[param_2 * 0x120 + param_1 * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
    }
    if (param_3 == 0x73) {
      if ((((DAT_0068f2c4 == 4) && (DAT_00666458 == DAT_00681eb4)) &&
          ((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00666458)) &&
         (((&DAT_006826e4)[param_2 * 0x120 + param_1 * 0x5b20] & 1) == 0)) {
        *(uint *)(&DAT_006827d4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006827d4 + param_2 * 0x120 + param_1 * 0x5b20) | 0x101;
        DAT_00676500 = DAT_00676500 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((param_3 == 4) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
        *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) | 1;
        DAT_006664ec = 1;
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (param_3 == 0x86) {
        local_c = FUN_0049b309((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],7,1);
        if (2 < local_c) {
          if (((local_c < 8) && (5 < (int)(&DAT_0068ee78)[param_1])) &&
             (7 < (int)(&DAT_00681ea8)[param_1])) {
            local_c = 0;
          }
          else {
            local_c = 2;
          }
        }
        local_8 = FUN_0045102d((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                               param_1,param_2,
                               (int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                               *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20),
                               s_Take_the_2_damage__Pay_1_mana__t_00508a04,local_c);
        if (local_8 == 0) {
          local_10 = 2;
        }
        else if (local_8 == 1) {
          FUN_0048d878(param_1,param_2,0x7e,0,0);
          FUN_0042b6b0((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],0,1);
          FUN_0048e251();
          if (DAT_00681ea4 == 1) {
            local_10 = 2;
          }
          else {
            local_10 = 1;
          }
        }
        else {
          FUN_0042b6b0((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],0,2);
          if (DAT_00681ea4 == 1) {
            local_10 = 2;
          }
          else {
            local_10 = 0;
          }
        }
        FUN_004afd1c((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],local_10,
                     DAT_00690af0,DAT_0068efa0);
        DAT_00681ea4 = -1;
      }
      if (param_3 == 0x22) {
        *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) & 0xfffffffe;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


