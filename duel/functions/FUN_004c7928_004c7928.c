/*
 * Decompiled function: FUN_004c7928
 * Entry Point: 004c7928
 * Size: 1043 bytes
 */
#include "duel.h"


undefined4 FUN_004c7928(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0x74) {
    uVar1 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar1 = FUN_0041bcf0(0,0,param_1,2,2,0x200,2,0,0,uVar1);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508ba8,s_CREATUREBOND_00508b98);
      iVar2 = FUN_00468130(param_1,1 - param_1,param_2);
      DAT_00681ea4 = (uint)(iVar2 == 0);
      if (DAT_00681ea4 != 1) {
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
        }
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
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
    if (((param_3 == 0x77) &&
        (*(int *)(&DAT_006826e8 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00690c48)) &&
       (((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_0068ecb0 &&
        ((DAT_00690c48 != -1 && (iVar2 = FUN_004d695b(param_1,DAT_0068f2d0), iVar2 != -1)))))) {
      *(undefined4 *)(&DAT_006826c0 + iVar2 * 0x120 + param_1 * 0x5b20) =
           *(undefined4 *)(&DAT_006826c4 + param_2 * 0x120 + param_1 * 0x5b20);
      *(uint *)(&DAT_006826cc + iVar2 * 0x120 + param_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar2 * 0x120 + param_1 * 0x5b20) | 2;
      *(undefined4 *)(&DAT_00682704 + iVar2 * 0x120 + param_1 * 0x5b20) = 0x32;
      uVar1 = FUN_0048b81a(DAT_0068ecb0,DAT_00690c48,0x33,0xffffffff);
      *(undefined4 *)(&DAT_006826e4 + iVar2 * 0x120 + param_1 * 0x5b20) = uVar1;
      (&DAT_006826d2)[iVar2 * 0x120 + param_1 * 0x5b20] = (undefined1)DAT_0068ecb0;
      FUN_0048eb25(param_1,iVar2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


