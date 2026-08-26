/*
 * Decompiled function: FUN_004c3059
 * Entry Point: 004c3059
 * Size: 922 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004c3059(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  uint arg_12;
  uint arg_13;
  int iVar2;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  
  if (arg_3 == 0x74) {
    if (DAT_00676510 == arg_1) {
      uVar1 = (DAT_0066aad4 | _DAT_0066aad0) & 1;
    }
    else {
      uVar1 = *(uint *)(&DAT_0066aad0 + DAT_00676504 * 4) & 1;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      FUN_00468550(arg_1,arg_1,arg_2);
      if (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
        DAT_00681ea4 = 1;
      }
    }
    if (arg_3 == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      uVar1 = FUN_004521e2(arg_1,arg_2);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                         *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),(undefined1 *)0x0,
                         arg_1,2,2,0x200,1,0,0,uVar1,arg_12,arg_13,iVar2,arg_15,arg_16,arg_17,arg_18
                         ,arg_19,arg_20);
      if (iVar2 == 0) {
        FUN_0046e571(arg_1,arg_2,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&DAT_00682718)[arg_2 * 0x120 + arg_1 * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20);
        FUN_00467d65(FUN_004c33f8,-1);
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
    }
    if (((arg_3 == 0x77) &&
        (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48)) &&
       (((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0 &&
        (DAT_00690c48 != -1)))) {
      DAT_0066642c = 1;
    }
    if ((((arg_3 == 0x6c) && ((DAT_00690c48 != arg_2 || (DAT_0068ecb0 != arg_1)))) &&
        (*(int *)(&DAT_006826e8 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) ==
         *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20))) &&
       (((&DAT_006826d2)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] ==
         (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] &&
        (((&DAT_004ff594)
          [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 4) != 0)
        ))) {
      DAT_00681ea4 = 1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


