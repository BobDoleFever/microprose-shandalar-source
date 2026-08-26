/*
 * Decompiled function: FUN_004c10d9
 * Entry Point: 004c10d9
 * Size: 1335 bytes
 */
#include "duel.h"


undefined4 FUN_004c10d9(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508978,s_BRAINWASH_0050896c);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_c);
      iVar2 = FUN_0041e2a2(param_1,2,1 - param_1,0x200,2,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        if (local_c == param_1) {
          iVar2 = FUN_0048b81a(local_c,local_8,0x32,0xffffffff);
          DAT_0068f2d4 = DAT_0068f2d4 - (iVar2 * 0xc) / 2;
        }
        else {
          iVar2 = FUN_0048b81a(local_c,local_8,0x32,0xffffffff);
          DAT_0068f2d4 = DAT_0068f2d4 + (iVar2 * 0xc) / 2;
        }
      }
    }
    if (param_3 == 0x71) {
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,2,0,0,uVar1);
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
    if (((((DAT_0068f230 == 0xdc) && (DAT_0068f2c4 == 0x15)) &&
         ((DAT_00690c48 == param_2 && ((DAT_0068ecb0 == param_1 && (DAT_00666458 == DAT_00681ec4))))
         )) && (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0)) &&
       (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00666754 &&
        (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_0068edd0)))) {
      iVar2 = FUN_0049b309(DAT_00666458,7,3);
      if (iVar2 == 0) {
        DAT_00666428 = 1;
      }
      else {
        if (param_3 == 0x7d) {
          DAT_0066642c = DAT_0066642c | 2;
        }
        if (param_3 == 0x7e) {
          FUN_0048d878(param_1,param_2,0x7e,param_1,0);
          FUN_0042b6b0(DAT_00666458,0,3);
          FUN_0048e251();
          if (DAT_00681ea4 == 1) {
            DAT_00666428 = 1;
            DAT_00681ea4 = 0;
          }
          else {
            *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 1;
          }
        }
      }
    }
    if ((param_3 == 0x79) && (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0)) {
      iVar2 = FUN_0049b309(DAT_00666458,7,3);
      if (iVar2 == 0) {
        DAT_0066642c = 1;
      }
      uVar1 = 0;
    }
    else {
      if ((param_3 == 0x22) || (param_3 == 199)) {
        *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = 0;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


