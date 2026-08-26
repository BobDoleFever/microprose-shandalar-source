/*
 * Decompiled function: FUN_004a775b
 * Entry Point: 004a775b
 * Size: 1064 bytes
 */
#include "duel.h"


undefined4 FUN_004a775b(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,0x43,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      FUN_00434660(s_prompts_txt_005061c8,s_TWIDDLE_005061c0);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0,
                           &DAT_006679f0,1,&local_c);
      iVar2 = FUN_0041e2a2(param_1,2,2,0x200,0x43,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
        if ((DAT_00681eb0._1_1_ & 4) == 0) {
          uVar1 = FUN_0045102d(param_1,param_1,param_2,local_c,local_8,s_Tap__Untap__005061d4,
                               (*(uint *)(&DAT_006826cc + local_8 * 0x120 + local_c * 0x5b20) & 0x10
                               ) >> 4);
          *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) = uVar1;
        }
        else {
          *(undefined4 *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
               *(undefined4 *)(&DAT_006826e4 + DAT_0068eccc * 0x120 + DAT_0068ecd0 * 0x5b20);
        }
        if (DAT_00676504 == param_1) {
          if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) * 0x34]
              & 1) != 0) {
            DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
          }
          if (((*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0) &&
              (local_c == DAT_00676504)) ||
             ((*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 1 &&
              (local_c == DAT_00676510)))) {
            DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
          }
        }
      }
    }
    if (param_3 == 0x71) {
      local_c = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar2 = FUN_0041c0ab(local_c,local_8,0,param_1,2,2,0x200,0x43,0,0,uVar1);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else if (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0) {
        FUN_004a7b83(local_c,local_8);
      }
      else {
        *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) =
             *(uint *)(&DAT_006826cc + local_c * 0x5b20 + local_8 * 0x120) & 0xffffffef;
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


