/*
 * Decompiled function: FUN_004c2e23
 * Entry Point: 004c2e23
 * Size: 408 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c2e23(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
       (DAT_00676504 == arg_1)) {
      if (DAT_0068ee88 == 0) {
        DAT_0068f2d4 = DAT_0068f2d4 + -0xf0;
      }
      else {
        iVar2 = FUN_0049b309(DAT_00676504,7,1);
        DAT_0068f2d4 = DAT_0068f2d4 + (iVar2 / 2 + (DAT_0068ee88 - _DAT_0068ee8c)) * 0x18;
      }
    }
    if (((arg_3 == 0x85) &&
        (((&DAT_004ff594)
          [*(int *)(&DAT_006826c4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) * 0x34] & 0x40) !=
         0)) && ((DAT_0068ecb0 == DAT_00681eb4 && (DAT_00666458 == DAT_00681eb4)))) {
      *(uint *)(&DAT_006827d4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) =
           *(uint *)(&DAT_006827d4 + DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120) | 3;
      (&DAT_006827d8)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] =
           (&DAT_006827d8)[DAT_0068ecb0 * 0x5b20 + DAT_00690c48 * 0x120] + '\x02';
    }
    uVar1 = 0;
  }
  return uVar1;
}


