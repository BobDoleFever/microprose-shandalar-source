/*
 * Decompiled function: FUN_004cf08b
 * Entry Point: 004cf08b
 * Size: 1644 bytes
 */
#include "duel.h"


undefined4 FUN_004cf08b(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar2);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508e64,s_ANY_WARD_00508e58);
      iVar3 = FUN_00468130(param_1,param_1,param_2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        if ((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00676504) {
          iVar3 = *(int *)(&DAT_0068ede0 + param_4 * 4 + DAT_00676510 * 0x20);
          iVar4 = FUN_0048b81a((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],
                               *(undefined4 *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20),
                               0x32,0xffffffff);
          DAT_0068f2d4 = DAT_0068f2d4 + (iVar3 + 1) * iVar4 * 3;
        }
        if ((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
        }
      }
    }
    if (param_3 == 0x71) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar3 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,2,0,0,uVar2);
      if (iVar3 == 0) {
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
    uVar1 = DAT_0066642c;
    if (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) != -1) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_8]; local_10 = local_10 + 1) {
          if (((((((&DAT_006826cc)[local_10 * 0x120 + local_8 * 0x5b20] & 2) != 0) &&
                (*(int *)(&DAT_006826e8 + local_10 * 0x120 + local_8 * 0x5b20) ==
                 *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20))) &&
               (((&DAT_006826d2)[local_10 * 0x120 + local_8 * 0x5b20] ==
                 (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] &&
                ((int)(char)(&DAT_006826dd)[local_10 * 0x120 + local_8 * 0x5b20] ==
                 1 << ((byte)param_4 & 0x1f))))) && ((local_8 != param_1 || (param_2 != local_10))))
             && (((&DAT_004ff594)
                  [*(int *)(&DAT_006826c4 + local_10 * 0x120 + local_8 * 0x5b20) * 0x34] & 4) != 0))
          {
            DAT_0066642c = uVar1;
            FUN_0046e571(local_8,local_10,1);
          }
        }
      }
    }
    DAT_0066642c = uVar1;
    if ((((*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48) &&
         ((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0)) &&
        (DAT_00690c48 != -1)) &&
       ((((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0 &&
        (param_4 = FUN_004af7bb(param_1,param_2,param_4), param_3 == 0x34)))) {
      DAT_0066642c = DAT_0066642c | 0x800 << ((char)param_4 - 1U & 0x1f);
    }
    if (((param_3 == 0x6c) &&
        ((&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
         (&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20])) &&
       ((*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
         *(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) &&
        (((1 << ((byte)param_4 & 0x1f) &
          (int)(char)(&DAT_006826dd)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120]) != 0 &&
         (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 0x20) == 0)))))) {
      DAT_0066642c = 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}


