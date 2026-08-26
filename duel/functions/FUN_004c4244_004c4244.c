/*
 * Decompiled function: FUN_004c4244
 * Entry Point: 004c4244
 * Size: 650 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004c4244(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int local_c;
  
  if (arg_3 == 0x74) {
    if (arg_1 == DAT_00676510) {
      uVar1 = (DAT_0066aad4 | _DAT_0066aad0) & 1;
    }
    else {
      uVar1 = *(uint *)(&DAT_0066aad0 + DAT_00676510 * 4) & 1;
    }
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      iVar2 = FUN_00468550(arg_1,1 - arg_1,arg_2);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else if ((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == arg_1) {
        DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
      }
      else {
        DAT_0068f2d4 = DAT_0068f2d4 +
                       (*(int *)(&DAT_0068ef6c + (1 - arg_1) * 0x20) -
                       *(int *)(&DAT_0068ef6c + arg_1 * 0x20)) * 0xc;
      }
    }
    if (((arg_3 == 0x7c) && (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0)) &&
       ((*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == DAT_00690c48 &&
        (((char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] == DAT_0068ecb0 &&
         (DAT_00690c48 != -1)))))) {
      iVar2 = FUN_00467cce(DAT_0068ecb0,1);
      bVar3 = iVar2 != 0;
      iVar2 = FUN_00467cce(1 - DAT_0068ecb0,1);
      if (iVar2 != 0) {
        bVar3 = bVar3 | 2;
      }
      if (bVar3 == 0) {
        FUN_0046e571(arg_1,arg_2,2);
      }
      else {
        if (DAT_0068ecb0 == DAT_00676510) {
          do {
          } while (local_c == -1);
        }
        else {
          do {
          } while (local_c == -1);
        }
        *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
        (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
      }
      FUN_0046e571(DAT_0068ecb0,DAT_00690c48,2);
    }
    uVar1 = 0;
  }
  return uVar1;
}


