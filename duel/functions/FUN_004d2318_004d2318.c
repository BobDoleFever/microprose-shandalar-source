/*
 * Decompiled function: FUN_004d2318
 * Entry Point: 004d2318
 * Size: 1498 bytes
 */
#include "duel.h"


undefined4 FUN_004d2318(int param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_3 == 1) {
    *(int *)(&DAT_0068f330 + param_1 * 0x20) = *(int *)(&DAT_0068f330 + param_1 * 0x20) + 2;
  }
  if (param_3 == 0x74) {
    FUN_0043071d(0);
    uVar3 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar3 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar3);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508f94,s_THE_BRUTE_00508f88);
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
    if (((param_3 == 0x73) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
       (*(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) == 0)) {
      bVar1 = (&DAT_006826cc)
              [*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20];
      cVar2 = (&DAT_006826e0)
              [*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120 +
               (char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] * 0x5b20];
      iVar4 = FUN_0049b68d(param_1,param_2,4,3);
      if (iVar4 == 0 || (cVar2 != '\x02' || (bVar1 & 2) == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 99;
      }
    }
    else if (param_3 == 0x90) {
      FUN_0043071d(0);
      uVar3 = 0;
    }
    else {
      if (((param_3 == 0x6d) && ((DAT_00681eb0._1_1_ & 2) != 0)) &&
         (FUN_0042ecaf(param_1,param_2,4,3), DAT_00681ea4 != 1)) {
        DAT_006664ec = 1;
        *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(int *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) + 1;
      }
      if ((param_3 == 0x72) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
        *(undefined4 *)
         (&DAT_006826e4 +
         *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120) = 0;
        FUN_0045962d((int)(char)(&DAT_006826d2)
                                [*(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) *
                                 0x5b20 + *(int *)(&DAT_006827b4 +
                                                  param_2 * 0x120 + param_1 * 0x5b20) * 0x120],
                     *(undefined4 *)
                      (&DAT_006826e8 +
                      *(int *)(&DAT_006827b0 + param_2 * 0x120 + param_1 * 0x5b20) * 0x5b20 +
                      *(int *)(&DAT_006827b4 + param_2 * 0x120 + param_1 * 0x5b20) * 0x120));
      }
      if ((((*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48) &&
           ((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0)) &&
          (DAT_00690c48 != -1)) &&
         ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0 && (param_3 == 0x32))))
      {
        DAT_0066642c = DAT_0066642c + 1;
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}


