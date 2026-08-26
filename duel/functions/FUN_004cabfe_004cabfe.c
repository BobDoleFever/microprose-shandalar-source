/*
 * Decompiled function: FUN_004cabfe
 * Entry Point: 004cabfe
 * Size: 819 bytes
 */
#include "duel.h"


undefined4 FUN_004cabfe(int param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 == 0x74) {
    uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar3 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar3);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (param_1 == DAT_0068ecb0)) {
      FUN_00434660(s_prompts_txt_00508c68,s_SEEKER_00508c60);
      iVar4 = FUN_00468130(param_1,param_1,param_2);
      if (iVar4 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        DAT_00681ea4 = 0;
      }
    }
    if (param_3 == 0x71) {
      uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar4 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,2,0,0,uVar3);
      if (iVar4 == 0) {
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
    if (((param_3 == 0x78) &&
        (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_0068ecfc)) &&
       (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00690310 &&
        ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0 &&
         (((&DAT_004ff594)
           [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 0x40)
          == 0)))))) {
      cVar1 = (&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120];
      bVar2 = FUN_004af7bb(param_1,param_2,5);
      if ((1 << (bVar2 & 0x1f) & (int)cVar1) == 0) {
        DAT_0066642c = DAT_0066642c + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


