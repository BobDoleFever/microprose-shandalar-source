/*
 * Decompiled function: FUN_00407c33
 * Entry Point: 00407c33
 * Size: 608 bytes
 */
#include "duel.h"


undefined4 FUN_00407c33(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  uint local_d8 [50];
  int local_10;
  int local_c;
  uint local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
        if ((&DAT_0068ee78)[local_10] == 0) {
          Mem_AllocOrFree_004d9630(local_d8,(uint *)s_Lose_life_or_discard____Lose_3_l_004f2430);
          local_8 = 0;
        }
        else if ((&DAT_0068ee78)[local_10] == 1) {
          Mem_AllocOrFree_004d9630(local_d8,(uint *)s_Lose_life_or_discard____Lose_3_l_004f24ac);
          local_8 = (uint)((int)(&DAT_00681ea8)[local_10] < 5);
        }
        else if ((&DAT_0068ee78)[local_10] == 2) {
          Mem_AllocOrFree_004d9630(local_d8,(uint *)s_Lose_life_or_discard____Lose_3_l_004f2528);
          if ((int)(&DAT_00681ea8)[local_10] < 5) {
            local_8 = 2;
          }
          else {
            local_8 = 0;
          }
        }
        else {
          Mem_AllocOrFree_004d9630(local_d8,(uint *)s_Lose_life_or_discard____Lose_3_l_004f25a0);
          if ((int)(&DAT_00681ea8)[local_10] < 5) {
            local_8 = 3;
          }
          else {
            local_8 = 0;
          }
        }
        local_c = Ai_Subsystem_004cc56d(local_10,arg_1,arg_2,-1,-1,local_d8,local_8);
        if (local_c == 1) {
          Mem_AllocOrFree_004afd1c(local_10,2,arg_1,arg_2);
          Palette_Color_0049ae00(local_10,0,1);
        }
        else if (local_c == 2) {
          Mem_AllocOrFree_004afd1c(local_10,1,arg_1,arg_2);
          Palette_Color_0049ae00(local_10,0,1);
          Palette_Color_0049ae00(local_10,0,1);
        }
        else if (local_c == 3) {
          Palette_Color_0049ae00(local_10,0,1);
          Palette_Color_0049ae00(local_10,0,1);
          Palette_Color_0049ae00(local_10,0,1);
        }
        else {
          Mem_AllocOrFree_004afd1c(local_10,3,arg_1,arg_2);
        }
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


