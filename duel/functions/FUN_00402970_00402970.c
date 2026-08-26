/*
 * Decompiled function: FUN_00402970
 * Entry Point: 00402970
 * Size: 849 bytes
 */
#include "duel.h"


undefined4 FUN_00402970(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (param_3 == 0x74) {
    uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,1);
    uVar2 = FUN_0041bcf0(0,0,param_1,param_1,param_1,0x200,2,0,0,uVar2);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_004f2124,s_ENERGYTAP_004f2118);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,1,
                           &DAT_006679f0,1,&local_c);
      iVar3 = FUN_0041e2a2(param_1,param_1,param_1,0x200,2,0,0,uVar2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) = local_c;
        *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20) = local_8;
        (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 1;
      }
    }
    if (param_3 == 0x71) {
      local_c = *(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20);
      local_8 = *(int *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20);
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,1);
      iVar3 = FUN_0041c0ab(local_c,local_8,0,param_1,param_1,param_1,0x200,2,0,0,uVar2);
      if (iVar3 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        FUN_004a7b83(local_c,local_8);
        cVar1 = (&DAT_004ff597)[*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120) * 0x34]
        ;
        iVar3 = FUN_0049aa14((int)(char)(&DAT_004ff598)
                                        [*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120
                                                 ) * 0x34],0,99);
        *(int *)(&DAT_0068f2e0 + param_1 * 0x20) =
             *(int *)(&DAT_0068f2e0 + param_1 * 0x20) + cVar1 + iVar3;
        cVar1 = (&DAT_004ff597)[*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120) * 0x34]
        ;
        iVar3 = FUN_0049aa14((int)(char)(&DAT_004ff598)
                                        [*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_8 * 0x120
                                                 ) * 0x34],0,99);
        *(int *)(&DAT_0068f2fc + param_1 * 0x20) =
             *(int *)(&DAT_0068f2fc + param_1 * 0x20) + cVar1 + iVar3;
      }
      (&DAT_006827b8)[param_2 * 0x120 + param_1 * 0x5b20] = 0;
      FUN_0046e571(param_1,param_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


