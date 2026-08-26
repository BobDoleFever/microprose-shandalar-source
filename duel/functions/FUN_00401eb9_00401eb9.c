/*
 * Decompiled function: FUN_00401eb9
 * Entry Point: 00401eb9
 * Size: 529 bytes
 */
#include "duel.h"


undefined4 FUN_00401eb9(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
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
      local_1c = 0;
      local_14 = DAT_00666458;
      while (local_1c < 2) {
        local_20 = 0;
        for (local_8 = 0; local_8 < (int)(&DAT_00666408)[local_14]; local_8 = local_8 + 1) {
          iVar2 = FUN_0048a2cd(local_14,local_8);
          if (iVar2 != 0) {
            local_20 = local_20 + 1;
          }
        }
        for (local_18 = 0; local_18 < local_20; local_18 = local_18 + 1) {
          Palette_Color_0049ae00(local_14,1,0);
        }
        local_1c = local_1c + 1;
        if (DAT_00666458 == 0) {
          local_14 = local_14 + 1;
        }
        else {
          local_14 = local_14 + -1;
        }
      }
      FUN_00451482(0,0x30);
      local_10 = 0;
      local_c = 0;
      for (local_18 = 0; local_18 < 500; local_18 = local_18 + 1) {
        if (*(int *)(&DAT_006669f0 + local_18 * 4) != -1) {
          local_c = local_c + 1;
        }
        if (*(int *)(&DAT_006671c0 + local_18 * 4) != -1) {
          local_10 = local_10 + 1;
        }
      }
      if ((local_c < 7) && (local_10 < 7)) {
        if (DAT_0066aaf4 == 1) {
          DAT_00681ea8 = 0;
          DAT_00681eac = 0;
        }
        else {
          Mem_AllocOrFree_00450eed(s_Neither_player_has_enough_librar_004f2064);
          Sleep(0x9c4);
          Mem_AllocOrFree_00450eed(&DAT_004f20a8);
          FUN_004d65c6(2);
        }
      }
      else {
        FUN_00402889(0,7);
        FUN_00402889(1,7);
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


