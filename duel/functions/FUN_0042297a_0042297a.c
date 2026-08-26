/*
 * Decompiled function: FUN_0042297a
 * Entry Point: 0042297a
 * Size: 435 bytes
 */
#include "duel.h"


void FUN_0042297a(HDC hdc,RECT *arg_2,int arg_3,int arg_4)

{
  int arg_1;
  int iVar1;
  int local_b0;
  int local_ac;
  uint local_a8;
  undefined4 local_a4 [4];
  undefined4 local_94;
  undefined4 local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) {
    local_8 = FUN_004481fe(arg_3,arg_4);
    arg_1 = CardIDFromType(local_8);
    if ((DAT_0068f0fc == arg_1) && (iVar1 = FUN_00448304(arg_3,arg_4), iVar1 == DAT_006764b4)) {
      FUN_0042043e(hdc,arg_2);
    }
    else {
      FUN_0044826e(&local_b0,arg_3,arg_4);
      local_c = FUN_00486c12(arg_1,local_b0,local_ac);
      FID_conflict__memcpy(local_a4,&DAT_00618ac0 + arg_1 * 0x98,0x98);
      local_a8 = FUN_0044781f(arg_3,arg_4);
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
      Palette_Subsystem_0049c7c7(hdc,&arg_2->left,local_a4,local_c,2,DAT_00663e10);
    }
  }
  return;
}


