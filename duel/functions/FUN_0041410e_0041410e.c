/*
 * Decompiled function: FUN_0041410e
 * Entry Point: 0041410e
 * Size: 1053 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041410e(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if ((((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
     (iVar1 = FUN_00404b06(arg_1,*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20),-1),
     iVar1 != 0)) {
    DAT_0068f2d4 = DAT_0068f2d4 + -0xf0;
  }
  if (((arg_3 == 0x82) &&
      (iVar1 = FUN_0048b81a(DAT_0068ecb0,DAT_00690c48,0x32,0xffffffff), 2 < iVar1)) &&
     ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 &&
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0))
     )) {
    *(uint *)(&DAT_006827c8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) =
         *(uint *)(&DAT_006827c8 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) & 0xfffffffd;
    _DAT_0068f0cc = _DAT_0068f0cc | 1;
  }
  if (arg_3 == 199) {
    iVar1 = (&DAT_00666408)[DAT_00676504];
    if ((int)(&DAT_00666408)[DAT_00676504] <= (int)(&DAT_00666408)[DAT_00676510]) {
      iVar1 = (&DAT_00666408)[DAT_00676510];
    }
    local_c = 0;
    for (local_8 = 0; local_8 < iVar1; local_8 = local_8 + 1) {
      if (((*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676510 * 0x5b20) != -1) &&
          (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0)) &&
         (2 < *(short *)(&DAT_006826d4 + local_8 * 0x120 + DAT_00676510 * 0x5b20))) {
        if (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676510 * 0x5b20] & 0x10) == 0) {
          iVar2 = FUN_0048af80(DAT_00676510,local_8);
          if (iVar2 == 0) {
            local_c = local_c + *(short *)(&DAT_006826d4 + local_8 * 0x120 + DAT_00676510 * 0x5b20);
          }
        }
        else if ((&DAT_006827cc)[local_8 * 0x120 + DAT_00676510 * 0x5b20] == '\0') {
          local_c = local_c + *(short *)(&DAT_006826d4 + local_8 * 0x120 + DAT_00676510 * 0x5b20) *
                              2;
        }
      }
      if (((*(int *)(&DAT_006826c4 + local_8 * 0x120 + DAT_00676504 * 0x5b20) != -1) &&
          (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676504 * 0x5b20] & 2) != 0)) &&
         (2 < *(short *)(&DAT_006826d4 + local_8 * 0x120 + DAT_00676504 * 0x5b20))) {
        if (((&DAT_006826cc)[local_8 * 0x120 + DAT_00676504 * 0x5b20] & 0x10) == 0) {
          iVar2 = FUN_0048af80(DAT_00676504,local_8);
          if (iVar2 == 0) {
            local_c = local_c - *(short *)(&DAT_006826d4 + local_8 * 0x120 + DAT_00676504 * 0x5b20);
          }
        }
        else if ((&DAT_006827cc)[local_8 * 0x120 + DAT_00676504 * 0x5b20] == '\0') {
          local_c = local_c + *(short *)(&DAT_006826d4 + local_8 * 0x120 + DAT_00676504 * 0x5b20) *
                              -2;
        }
      }
    }
    DAT_0068f2d4 = DAT_0068f2d4 + local_c * 0xc;
  }
  return 0;
}


