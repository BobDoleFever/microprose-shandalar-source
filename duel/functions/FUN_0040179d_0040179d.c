/*
 * Decompiled function: FUN_0040179d
 * Entry Point: 0040179d
 * Size: 355 bytes
 */
#include "duel.h"


undefined4 FUN_0040179d(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x60;
    }
    if (arg_3 == 0x71) {
      if (DAT_0068f0f8 == -1) {
        bVar1 = false;
        local_c = 0;
        while ((local_c < 2 && (!bVar1))) {
          for (local_8 = 0; local_8 < (int)(&DAT_00666408)[local_c]; local_8 = local_8 + 1) {
            if ((*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) == DAT_00681ec8) &&
               (((&DAT_006826f9)[local_8 * 0x120 + local_c * 0x5b20] & 1) != 0)) {
              bVar1 = true;
            }
          }
          local_c = local_c + 1;
        }
        if (!bVar1) {
          DAT_0068f0f8 = arg_1;
        }
      }
      iVar3 = FUN_004a2b00(arg_1,arg_2,DAT_00681ec8,-1,-1);
      *(uint *)(&DAT_006826f8 + iVar3 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826f8 + iVar3 * 0x120 + arg_1 * 0x5b20) | 0x120;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


