/*
 * Decompiled function: FUN_00402245
 * Entry Point: 00402245
 * Size: 283 bytes
 */
#include "duel.h"


undefined4 FUN_00402245(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      DAT_0068f2d4 = DAT_0068f2d4 + -0x30;
      while ((&DAT_0068ee78)[arg_1] != 0) {
        Palette_Color_0049ae00(arg_1,1,0);
      }
      for (local_c = 0; ((&DAT_0068ed50)[arg_1 * 0x10 + local_c] != -1 && (local_c < 0x10));
          local_c = local_c + 1) {
      }
      if (local_c < 0x10) {
        iVar2 = FUN_00487ce1(arg_1);
        (&DAT_0068ed50)[arg_1 * 0x10 + local_c] =
             *(undefined4 *)(&DAT_006826c4 + iVar2 * 0x120 + arg_1 * 0x5b20);
        *(undefined4 *)(&DAT_006826c4 + iVar2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      }
      FUN_00402889(arg_1,7);
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


