/*
 * Decompiled function: FUN_004215c2
 * Entry Point: 004215c2
 * Size: 576 bytes
 */
#include "duel.h"


undefined4 FUN_004215c2(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5,uint arg_6,int arg_7)

{
  byte arg_1;
  undefined4 uVar1;
  uint local_2a0 [125];
  int local_ac;
  int local_a8;
  undefined4 local_a4 [4];
  int local_94;
  uint *local_30;
  undefined4 local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == 0)) {
    uVar1 = 0;
  }
  else {
    local_8 = FUN_00447184(arg_4,arg_5);
    if (local_8 == -1) {
      uVar1 = 0;
    }
    else {
      FID_conflict__memcpy(local_a4,&DAT_00618ac0 + local_8 * 0x98,0x98);
      local_ac = local_94;
      arg_1 = FUN_0044781f(arg_4,arg_5);
      local_a8 = FUN_0048c367(arg_1);
      if (((((local_ac == 1) || (local_ac == 8)) ||
           ((local_ac == 7 || ((local_ac == 5 || (local_ac == 2)))))) ||
          ((local_ac == 6 && (local_a8 != 0)))) || ((local_ac == 3 && (local_a8 != 0)))) {
        if (local_a8 == 1) {
          local_94 = 1;
        }
        else if (local_a8 == 5) {
          local_94 = 8;
        }
        else if (local_a8 == 3) {
          local_94 = 5;
        }
        else if (local_a8 == 4) {
          local_94 = 7;
        }
        else if (local_a8 == 2) {
          local_94 = 2;
        }
      }
      Mem_AllocOrFree_004d9630(local_2a0,*(uint **)(&DAT_00618b34 + local_8 * 0x98));
      FUN_00447d7c(arg_4,arg_5,local_2a0);
      Ai_Subsystem_004b69ba(arg_4,arg_5,local_2a0);
      local_30 = local_2a0;
      local_c = FUN_00486c12(local_8,arg_4,arg_5);
      uVar1 = Palette_Subsystem_0049c7c7(hdc,arg_2,local_a4,local_c,arg_6,arg_7);
    }
  }
  return uVar1;
}


