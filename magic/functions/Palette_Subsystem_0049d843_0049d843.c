/*
 * Decompiled function: Palette_Subsystem_0049d843
 * Entry Point: 0049d843
 * Size: 576 bytes
 */
#include "magic.h"


undefined4
Palette_Subsystem_0049d843(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5,uint arg_6,int arg_7)

{
  byte arg_1;
  undefined4 uVar1;
  char local_2a0 [500];
  int local_ac;
  int local_a8;
  WPARAM local_a4 [4];
  int local_94;
  char *local_30;
  int local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == 0)) {
    uVar1 = 0;
  }
  else {
    local_8 = Ai_Subsystem_004b5cbb(arg_4,arg_5);
    if (local_8 == -1) {
      uVar1 = 0;
    }
    else {
      memcpy(local_a4,&DAT_006b3070 + local_8 * 0x98,0x98);
      local_ac = local_94;
      arg_1 = Ai_Subsystem_004b6356(arg_4,arg_5);
      local_a8 = FUN_00473cc5(arg_1);
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
      strcpy(local_2a0,*(char **)(&DAT_006b30e4 + local_8 * 0x98));
      Ai_Subsystem_004b68b3(arg_4,arg_5,local_2a0);
      Ai_Subsystem_004b69ba(arg_4,arg_5,local_2a0);
      local_30 = local_2a0;
      local_c = FUN_00478aa4(local_8,arg_4,arg_5);
      uVar1 = Palette_Subsystem_0049c7c7(hdc,arg_2,local_a4,local_c,arg_6,arg_7);
    }
  }
  return uVar1;
}


