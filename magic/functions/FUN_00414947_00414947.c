/*
 * Decompiled function: FUN_00414947
 * Entry Point: 00414947
 * Size: 378 bytes
 */
#include "magic.h"


undefined4 FUN_00414947(int arg_1,undefined4 arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10 [3];
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      iVar2 = Ai_Subsystem_004cc814
                        (arg_1,s_Natural_Selection__0051974c,0,s_See_your_library_00519738,
                         s_See_opponent_s_library_00519720,(char *)0x0);
      if (iVar2 == 0) {
        local_14 = arg_1;
      }
      else {
        local_14 = 1 - arg_1;
      }
      while( true ) {
        for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
          local_10[local_18] = *(int *)(&DAT_0069e730 + local_18 * 4 + local_14 * 2000);
        }
        Pic_Load_004509e8(arg_1,(int)local_10,3,s_Next_3__R_to_L__library_cards_00519768,0);
        iVar2 = Ai_Subsystem_004cc814
                          (arg_1,s_Natural_Selection__005197bc,0,s_No_change_005197b0,
                           s_Rearrange_these_cards_00519798,s_Shuffle_deck_00519788);
        if (iVar2 != 1) break;
        for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
          do {
            iVar2 = FUN_0040a1d2(3);
          } while (local_10[iVar2] == -2);
          *(int *)(&DAT_0069e730 + local_18 * 4 + local_14 * 2000) = local_10[iVar2];
          local_10[iVar2] = -2;
        }
      }
      if (iVar2 == 2) {
        Pic_Subsystem_00452276(local_14);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


