/*
 * Decompiled function: Palette_Subsystem_0049ebf6
 * Entry Point: 0049ebf6
 * Size: 435 bytes
 */
#include "magic.h"


void Palette_Subsystem_0049ebf6(HDC hdc,RECT *arg_2,int arg_3,int arg_4)

{
  int arg_1;
  int iVar1;
  int local_b0;
  int local_ac;
  uint local_a8;
  WPARAM local_a4 [4];
  undefined4 local_94;
  int local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) {
    local_8 = Ai_Subsystem_004b6d35(arg_3,arg_4);
    arg_1 = Ai_Subsystem_004cbd67(local_8);
    if ((DAT_006ff2dc == arg_1) &&
       (iVar1 = Ai_Subsystem_004b6e3b(arg_3,arg_4), iVar1 == DAT_006a3f74)) {
      Palette_Subsystem_0049c6cb(hdc,arg_2);
    }
    else {
      Ai_Subsystem_004b6da5(&local_b0,arg_3,arg_4);
      local_c = FUN_00478aa4(arg_1,local_b0,local_ac);
      memcpy(local_a4,&DAT_006b3070 + arg_1 * 0x98,0x98);
      local_a8 = Ai_Subsystem_004b6356(arg_3,arg_4);
      if ((local_a8 & 2) == 0) {
        if ((local_a8 & 0x20) == 0) {
          if ((local_a8 & 8) == 0) {
            if ((local_a8 & 0x10) == 0) {
              if ((local_a8 & 4) != 0) {
                local_94 = 2;
              }
            }
            else {
              local_94 = 7;
            }
          }
          else {
            local_94 = 5;
          }
        }
        else {
          local_94 = 8;
        }
      }
      else {
        local_94 = 1;
      }
      Palette_Subsystem_0049c7c7(hdc,&arg_2->left,local_a4,local_c,2,DAT_006fe430);
    }
  }
  return;
}


