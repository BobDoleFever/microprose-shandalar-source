/*
 * Decompiled function: FUN_004c3d11
 * Entry Point: 004c3d11
 * Size: 1326 bytes
 */
#include "duel.h"


undefined4 FUN_004c3d11(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_3 == 199) && (((&DAT_006826cc)[param_2 * 0x120 + param_1 * 0x5b20] & 2) != 0)) &&
     ((&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] != -1)) {
    if ((char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20] == DAT_00676510) {
      iVar1 = 0x18 - (&DAT_00681ea8)[(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * 0x18;
    }
    else {
      iVar1 = 0x18 - (&DAT_00681ea8)[(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20]];
      if (iVar1 < 2) {
        iVar1 = 1;
      }
      DAT_0068f2d4 = DAT_0068f2d4 + iVar1 * -0x18;
    }
  }
  if (param_3 == 0x74) {
    uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
    uVar2 = FUN_0041bcf0(0,0,param_1,2,2,0x200,1,0,0,uVar2);
  }
  else {
    if (((param_3 == 0x6c) && (DAT_00690c48 == param_2)) && (DAT_0068ecb0 == param_1)) {
      FUN_00434660(s_prompts_txt_00508ad0,s_CURSED_LAND_00508ac4);
      iVar1 = FUN_00468550(param_1,1 - param_1,param_2);
      DAT_00681ea4 = (uint)(iVar1 == 0);
      if (DAT_00681ea4 != 1) {
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676510) {
          DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
        }
        if (*(int *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20) == DAT_00676504) {
          DAT_0068f2d4 = DAT_0068f2d4 + -0x60;
        }
      }
    }
    if (param_3 == 0x71) {
      uVar2 = FUN_004521e2(param_1,param_2,0,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0,0,0);
      iVar1 = FUN_0041c0ab(*(undefined4 *)(&DAT_00682718 + param_2 * 0x120 + param_1 * 0x5b20),
                           *(undefined4 *)(&DAT_0068271c + param_2 * 0x120 + param_1 * 0x5b20),0,
                           param_1,2,2,0x200,1,0,0,uVar2);
      if (iVar1 == 0) {
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
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
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
        FUN_004afd1c((int)(char)(&DAT_006826d2)[param_2 * 0x120 + param_1 * 0x5b20],1,param_1,
                     param_2);
      }
      if (param_3 == 0x22) {
        *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + param_2 * 0x120 + param_1 * 0x5b20) & 0xfffffffe;
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


