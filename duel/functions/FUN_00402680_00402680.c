/*
 * Decompiled function: FUN_00402680
 * Entry Point: 00402680
 * Size: 521 bytes
 */
#include "duel.h"


undefined4 FUN_00402680(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      DAT_0068f2d4 = DAT_0068f2d4 - ((&DAT_0068ee78)[arg_1] * -0x18 + 0x30);
    }
    if (arg_3 == 0x71) {
      local_10 = 0;
      local_8 = DAT_00666458;
      while (local_10 < 2) {
        for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
          iVar2 = FUN_0048a2cd(local_8,local_c);
          if (iVar2 != 0) {
            FUN_004d7b2d(local_8,*(undefined4 *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20)
                        );
            *(undefined4 *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) = 0xffffffff;
          }
        }
        local_c = 0;
        while ((local_c < 500 && (*(int *)(&DAT_0068f370 + local_c * 4 + local_8 * 2000) != -1))) {
          FUN_004d7b2d(local_8,*(undefined4 *)(&DAT_0068f370 + local_c * 4 + local_8 * 2000));
          local_c = local_c + 1;
        }
        for (local_c = 0; local_c < 500; local_c = local_c + 1) {
          *(undefined4 *)(&DAT_0068f370 + local_c * 4 + local_8 * 2000) = 0xffffffff;
        }
        FUN_00451482(0,0x30);
        FUN_004d7946(local_8);
        FUN_00402889(local_8,7);
        local_10 = local_10 + 1;
        if (DAT_00666458 == 0) {
          local_8 = local_8 + 1;
        }
        else {
          local_8 = local_8 + -1;
        }
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


