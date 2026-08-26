/*
 * Decompiled function: FUN_004fd5e4
 * Entry Point: 004fd5e4
 * Size: 608 bytes
 */
#include "magic.h"


undefined4 FUN_004fd5e4(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  char local_d8 [200];
  int local_10;
  int local_c;
  uint local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
        if ((&DAT_006b3008)[local_10] == 0) {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_00530728);
          local_8 = 0;
        }
        else if ((&DAT_006b3008)[local_10] == 1) {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_005307a4);
          local_8 = (uint)((int)(&g_PlayerCreatureCount)[local_10] < 5);
        }
        else if ((&DAT_006b3008)[local_10] == 2) {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_00530820);
          if ((int)(&g_PlayerCreatureCount)[local_10] < 5) {
            local_8 = 2;
          }
          else {
            local_8 = 0;
          }
        }
        else {
          strcpy(local_d8,s_Lose_life_or_discard____Lose_3_l_00530898);
          if ((int)(&g_PlayerCreatureCount)[local_10] < 5) {
            local_8 = 3;
          }
          else {
            local_8 = 0;
          }
        }
        local_c = Ai_Subsystem_004cc56d(local_10,arg_1,arg_2,-1,-1,local_d8,local_8);
        if (local_c == 1) {
          Mem_AllocOrFree_0041df33(local_10,2,arg_1,arg_2);
          Prompts_Load_0046fa40(local_10,0,1);
        }
        else if (local_c == 2) {
          Mem_AllocOrFree_0041df33(local_10,1,arg_1,arg_2);
          Prompts_Load_0046fa40(local_10,0,1);
          Prompts_Load_0046fa40(local_10,0,1);
        }
        else if (local_c == 3) {
          Prompts_Load_0046fa40(local_10,0,1);
          Prompts_Load_0046fa40(local_10,0,1);
          Prompts_Load_0046fa40(local_10,0,1);
        }
        else {
          Mem_AllocOrFree_0041df33(local_10,3,arg_1,arg_2);
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


